/******************************************************************************
 * $Id: gvtessshape.c,v 1.11 2003/02/25 19:41:23 warmerda Exp $
 *
 * Project:  OpenEV
 * Purpose:  Tesselation for GvAreaShape.
 * Author:   Frank Warmerdam, warmerda@home.com
 *
 ******************************************************************************
 * Copyright (c) 2000, Atlantis Scientific Inc. (www.atlsci.com)
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 ******************************************************************************
 *
 * $Log: gvtessshape.c,v $
 * Revision 1.11  2003/02/25 19:41:23  warmerda
 * avoid warning
 *
 * Revision 1.10  2002/12/10 02:57:34  sduclos
 * update tess callback cast for WIN_CALLBACK
 *
 * Revision 1.9  2002/11/05 18:56:26  sduclos
 * fix gcc warning
 *
 * Revision 1.8  2002/11/04 21:42:07  sduclos
 * change geometric data type name to gvgeocoord
 *
 * Revision 1.7  2001/05/01 21:48:01  warmerda
 * fixed Mesa3.3 compatibility fixes
 *
 * Revision 1.6  2001/04/24 16:22:12  warmerda
 * fixed mesa3.3 incompatibility
 *
 * Revision 1.5  2000/07/13 22:25:43  warmerda
 * detect tesselations w/1 fill_object and no vertices, and reset to 0 objects
 *
 * Revision 1.4  2000/06/20 13:26:55  warmerda
 * added standard headers
 *
 */

#include "gvshapes.h"

/* gtkgl.h is to satisfy some Windows definition requirements */
#include <gtkgl/gdkgl.h>
#include <GL/glu.h>
#include <string.h>

/* Backward compatibility with glu ver. 1.1 */
#if !defined(GLU_VERSION_1_2)

#if !defined(GLU_TESS_BEGIN)
#define GLU_TESS_BEGIN  GLU_BEGIN
#define GLU_TESS_END    GLU_END
#define GLU_TESS_VERTEX GLU_VERTEX
#define GLU_TESS_ERROR  GLU_ERROR
#endif

#define gluTessBeginPolygon(tess,data) gluBeginPolygon(tess)
#define gluTessBeginContour(tess)      gluNextContour(tess, GLU_UNKNOWN)
#define gluTessEndContour(tess)
#define gluTessEndPolygon(tess)        gluEndPolygon(tess)

typedef GLUtriangulatorObj GLUtesselator;
#endif /* GLU_VERSION_1_2 */

enum { GV_CCW, GV_CW };

static GvAreaShape *area;

#ifdef WIN32
#  define WIN_CALLBACK FAR PASCAL
#else
#  define WIN_CALLBACK
#endif

static void WIN_CALLBACK tess_begin(GLenum type);
static void WIN_CALLBACK tess_end(void);
static void WIN_CALLBACK tess_vertex(void *data);
static void WIN_CALLBACK tess_error(GLenum err);
static gint check_ring_lengths(void);
static void check_winding(void);
static gint find_winding(gvgeocoord *, int);
static void reverse_array(gvgeocoord *, int);

gint
gv_area_shape_tessellate(GvAreaShape *in_area)
{
    typedef void (*f);
    static GLUtesselator *tess = NULL;
    int i, j;
    GLdouble coords[3];

    /* A fill_objects value of -2 is a special flag meaning don't tesselate
       or fill because we are in the midst of editing. */
    if( in_area->fill_objects == -2 )
        return FALSE;
    
    if (!tess)
    {
	tess = gluNewTess();
	g_return_val_if_fail(tess, FALSE);

	gluTessCallback(tess, GLU_TESS_BEGIN, (f) tess_begin);
	gluTessCallback(tess, GLU_TESS_END,   (f) tess_end);
	gluTessCallback(tess, GLU_TESS_VERTEX,(f) tess_vertex);
	gluTessCallback(tess, GLU_TESS_ERROR, (f) tess_error);
    }

    /* Global is available to all tess callbacks */
    area = in_area;

    /* Check for short ring lengths, or unclosed rings */
    if (!check_ring_lengths()) return FALSE;
    
    /* Fix ring winding before tesselation */
    check_winding();
    
    area->fill_objects = 0;
    if (area->fill)
    {
	g_array_set_size(area->fill, 0);
	g_array_set_size(area->mode_offset, 0);
    }
    else
    {
	area->fill = g_array_new(FALSE, FALSE, sizeof(GvVertex3d));
	area->mode_offset = 
	  g_array_new(FALSE, FALSE, sizeof(gint));
    }

    gluTessBeginPolygon(tess, NULL);
    for (i=0; i < gv_shape_get_rings((GvShape *) area); ++i)
    {
        int     node_count;
        gvgeocoord   *xyz_nodes;

	node_count = area->num_ring_nodes[i];
        xyz_nodes = area->xyz_ring_nodes[i];
	
	gluTessBeginContour(tess);
	for (j=0; j < node_count; ++j)
	{
            coords[0] = xyz_nodes[j*3+0];
            coords[1] = xyz_nodes[j*3+1];
            coords[2] = xyz_nodes[j*3+2];
	    
	    gluTessVertex(tess, coords, xyz_nodes + j*3);
	}
	gluTessEndContour(tess);
    }
    gluTessEndPolygon(tess);

    if( area->fill->len == 0 )
        area->fill_objects = 0;

    return (area->fill_objects > 0 
	    && g_array_index(area->mode_offset,gint,0) != GV_TESS_NONE);
}

static void WIN_CALLBACK
tess_begin(GLenum type)
{
    area->fill_objects++;
    g_array_append_val(area->mode_offset, type );
    g_array_append_val(area->mode_offset, area->fill->len );
}

static void WIN_CALLBACK
tess_end(void)
{
}

static void WIN_CALLBACK
tess_vertex(void *data)
{
  /* for some unknown reason, we somes get called with a NULL 
     if the object doesn't tesselate properly (with libMesa). */

  if( data != NULL )
    g_array_append_vals(area->fill, data, 1);
  else
    tess_error( 0 );
}

static void WIN_CALLBACK
tess_error(GLenum err)
{
  GLenum bad_fill_mode = GV_TESS_NONE;
  gint   offset = 0;

  g_array_set_size(area->fill, 0);
  g_array_set_size(area->mode_offset, 0);

  area->fill_objects = 1;
  g_array_append_val(area->mode_offset, bad_fill_mode );
  g_array_append_val(area->mode_offset, offset );
}

static gint
check_ring_lengths(void)
{
    int r;

    for (r=0; r < area->num_rings; ++r)
    {
        int nodes = area->num_ring_nodes[r];

	if ( nodes < 3) 
            return FALSE;
    }

    return TRUE;
}

static void
check_winding(void)
{
    int r, winding;

    for (r=0; r < area->num_rings; ++r)
    {
	winding = find_winding(area->xyz_ring_nodes[r], 
                               area->num_ring_nodes[r]);

	if ((r == 0 && winding == GV_CW) || (r > 0 && winding == GV_CCW))
	{
	    reverse_array(area->xyz_ring_nodes[r], 
                          area->num_ring_nodes[r]);
	}
    }
}

/* According to the comp.graphics.algorthms FAQ, item 2.07, the
 * orientation (winding) of a simple polygon can be determined by
 * looking at the sign of the following series:
 *    sum_{i=0}^{n-1} (x_i y_{i+1} - y_i x_{i+1})
 * A positive result means a counter clockwise winding.
 */ 
static gint
find_winding(gvgeocoord *xyz_nodes, int node_count)
{
    gvgeocoord *a, *b;
    gvgeocoord sum;
    int i;

    sum = 0.0;
    a = xyz_nodes + 0;
    b = xyz_nodes + 3;
    for (i=1; i < node_count; ++i, a += 3, b += 3)
    {
	sum += a[0] * b[1] - a[1] * b[0];
    }
    b = xyz_nodes;
    sum += a[0] * b[1] - a[1] * b[0];

    return (sum < 0.0 ? GV_CW : GV_CCW);
}

static void
reverse_array(gvgeocoord *xyz_nodes, int node_count)
{
    int i;
    gvgeocoord   xyz_temp[3];

    for (i=0; i < node_count/2; ++i)
    { 
        memcpy( xyz_temp, xyz_nodes+i*3, 
                sizeof(gvgeocoord)*3 );
        memcpy( xyz_nodes+i*3, xyz_nodes+(node_count-i-1)*3, 
                sizeof(gvgeocoord)*3);
        memcpy( xyz_nodes+(node_count-i-1)*3, xyz_temp, 
                sizeof(gvgeocoord)*3);
    }
}

