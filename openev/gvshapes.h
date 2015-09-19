/******************************************************************************
 * $Id: gvshapes.h,v 1.26 2005/01/14 16:51:51 gmwalter Exp $
 *
 * Project:  OpenEV
 * Purpose:  Definitions of GvShape (single object) and GvShapes (data
 *           container).
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
 * $Log: gvshapes.h,v $
 * Revision 1.26  2005/01/14 16:51:51  gmwalter
 * Checked in Aude's gv_shapes_add_shape_last function
 * (allows shapes to be added without repeating
 * indices if others have been deleted).
 *
 * Revision 1.25  2005/01/04 18:50:31  gmwalter
 * Checked in Aude's new gvshape function changes.
 *
 * Revision 1.24  2003/08/29 20:52:43  warmerda
 * added to/from xml translation for GvShape
 *
 * Revision 1.23  2003/06/25 17:06:06  warmerda
 * added gv_shape_rotate(), gv_shape_scale() and related stuff
 *
 * Revision 1.22  2003/01/06 21:20:03  warmerda
 * added gv_shapes_from_ogr_layer
 *
 * Revision 1.21  2002/11/04 21:42:07  sduclos
 * change geometric data type name to gvgeocoord
 *
 * Revision 1.20  2002/07/18 19:33:57  pgs
 * added gv_shapes_to_dbf
 *
 * Revision 1.19  2002/05/07 02:51:15  warmerda
 * preliminary support for GVSHAPE_COLLECTION
 *
 * Revision 1.18  2002/03/07 18:31:56  warmerda
 * added preliminary gv_shape_clip_to_rect() implementation
 *
 * Revision 1.17  2002/03/07 02:31:56  warmerda
 * added default_height to add_height functions
 *
 * Revision 1.16  2001/12/08 04:49:38  warmerda
 * added point in polygon test
 *
 * Revision 1.15  2001/08/08 17:45:48  warmerda
 * GvShape now referenced counted
 *
 * Revision 1.14  2001/01/18 16:48:14  warmerda
 * added gv_shapes_add_height() and wrappers
 *
 * Revision 1.13  2000/08/04 14:14:12  warmerda
 * GvShapes shape ids now persistent
 *
 * Revision 1.12  2000/07/14 14:51:01  warmerda
 * fixed insert, and delete node support
 *
 * Revision 1.11  2000/07/13 19:08:37  warmerda
 * added coping optional for gv_shapes_replace_shapes
 *
 * Revision 1.10  2000/06/28 13:10:42  warmerda
 * added preliminary OGR support
 *
 * Revision 1.9  2000/06/20 13:27:08  warmerda
 * added standard headers
 *
 */

#ifndef __GV_SHAPES_H__
#define __GV_SHAPES_H__

#include "gvdata.h"
#include "cpl_minixml.h"

#define GV_TYPE_SHAPES           (gv_shapes_get_type ())
#define GV_SHAPES(obj)           (GTK_CHECK_CAST ((obj), GV_TYPE_SHAPES,\
                                                  GvShapes))
#define GV_SHAPES_CLASS(klass)   (GTK_CHECK_CLASS_CAST((klass),GV_TYPE_SHAPES,\
                                                       GvShapesClass))
#define GV_IS_SHAPES(obj)        (GTK_CHECK_TYPE ((obj), GV_TYPE_SHAPES))
#define GV_IS_SHAPES_CLASS(klass) (GTK_CHECK_CLASS_TYPE ((klass), GV_TYPE_SHAPES))

#define GVSHAPE_POINT      1
#define GVSHAPE_LINE       2
#define GVSHAPE_AREA       3
#define GVSHAPE_COLLECTION 4

#define GVSF_TYPE_MASK      0x07
#define GVSF_CUSTOM_RENDER  0x08

typedef struct
{
    guint     flags;
    guint     ref_count;
    GvProperties properties;
} GvShape;

typedef struct
{
    guint     flags;
    guint     ref_count;
    GvProperties properties;
    gvgeocoord     x;
    gvgeocoord     y;
    gvgeocoord     z;
} GvPointShape;

typedef struct
{
    guint     flags;
    guint     ref_count;
    GvProperties properties;
    int       num_nodes;
    gvgeocoord     *xyz_nodes;
} GvLineShape;

typedef struct
{
    guint     flags;
    guint     ref_count;
    GvProperties properties;
    int       num_rings;
    int       *num_ring_nodes;
    gvgeocoord     **xyz_ring_nodes;

    /* tesselation information */
    gint      fill_objects; /* -1 is untesselated, -2 is `do not tesselate' */
    GArray    *mode_offset;
    GArray    *fill;
} GvAreaShape;

typedef struct
{
    guint     flags;
    guint     ref_count;
    GvProperties properties;
    int       geom_count;
    GvShape   **geom_list;
} GvCollectionShape;

typedef struct
{
    GvData data;

    GPtrArray *shapes;
    int    actual_num_shapes;  /* not including NULLs in GPtrArray */

    GvRect extents;
    guint extents_valid : 1;
} GvShapes;

typedef struct
{
    GvDataClass parent_class;
} GvShapesClass;

GvShape* gv_shape_new( gint type );
GvShape* gv_shape_from_xml_tree( CPLXMLNode * );
CPLXMLNode *gv_shape_to_xml_tree( GvShape *psShape );

#define gv_shape_get_properties( shape ) (&(shape)->properties)
#define gv_shape_type( shape ) ((shape)->flags & GVSF_TYPE_MASK)

void     gv_shape_unref( GvShape *shape );
void     gv_shape_ref( GvShape *shape );
int      gv_shape_get_ref( GvShape *shape );
void     gv_shape_delete( GvShape *shape );
GvShape* gv_shape_copy( GvShape *shape );
gint     gv_shape_get_rings( GvShape *shape );
gint     gv_shape_get_nodes( GvShape *shape, gint ring );
gvgeocoord  gv_shape_get_xyz( GvShape *shape, gint ring, gint node, gint off );
void     gv_shape_get_extents( GvShape *shape, GvRect *rect );

#define gv_shape_get_x(shape,ring,node) gv_shape_get_xyz(shape,ring,node,0)
#define gv_shape_get_y(shape,ring,node) gv_shape_get_xyz(shape,ring,node,1)
#define gv_shape_get_z(shape,ring,node) gv_shape_get_xyz(shape,ring,node,2)

gint     gv_shape_set_xyz( GvShape *shape, gint ring, gint node,
                           gvgeocoord x, gvgeocoord y, gvgeocoord z );
gint     gv_shape_add_node( GvShape *shape, gint ring,
                             gvgeocoord x, gvgeocoord y, gvgeocoord z );
gint     gv_shape_insert_node( GvShape *shape, gint ring, int node,
                               gvgeocoord x, gvgeocoord y, gvgeocoord z );
gint     gv_shape_delete_node( GvShape *shape, gint ring, gint node );
gint     gv_shape_delete_ring( GvShape *shape, gint ring );
gint     gv_shape_point_in_polygon( GvShape *shape_poly, double x, double y );
gdouble gv_shape_distance_from_polygon( GvShape *shape_poly, double x, double y );
GvShape *gv_shape_clip_to_rect( GvShape *shape, GvRect *rect );

void     gv_shape_collection_add_shape( GvShape *collection, GvShape *shape );
GvShape *gv_shape_collection_get_shape( GvShape *collection, int shp_index );
int      gv_shape_collection_get_count( GvShape *collection );

GtkType  gv_shapes_get_type (void);

gint     gv_area_shape_tessellate(GvAreaShape *area);

int      gv_shape_get_count(void);
gint     gv_shape_update_attribute( GvShape *shape, const char *tool, 
                                    const char *attribute, 
                                    const char *update_value );
gint gv_shape_get_center( GvShape *shape, GvVertex3d *xyz );
gint gv_shape_rotate( GvShape *shape, double angle_in_degrees );
gint gv_shape_scale( GvShape *shape, double new_scale );

GvData* gv_shapes_new(void);
GvData* gv_shapes_from_shapefile(const char *);
GvData* gv_shapes_from_ogr(const char *,int);
GvData* gv_shapes_from_ogr_layer(void *);

void    gv_shapes_add_height(GvShapes *shapes, GvData *raster, double offset,
                             double default_height );
int gv_shapes_to_shapefile(const char *,GvData *, int);
int gv_shapes_to_dbf(const char *,GvData * );
void gv_shapes_get_extents(GvShapes *shapes, GvRect *rect);
gint gv_shapes_add_shape(GvShapes *shapes, GvShape *shape);
gint gv_shapes_add_shape_last(GvShapes *shapes, GvShape *shape);
void gv_shapes_replace_shapes(GvShapes *shapes, gint num_shapes,
                              gint *shape_id, GvShape **shps, int make_copy);
void gv_shapes_delete_shapes(GvShapes *shapes, gint num_shapes, gint*shapeids);
void gv_shapes_translate_shapes(GvShapes *shapes, gint num_shapes,
                                gint *shapeids, gvgeocoord dx, gvgeocoord dy );

#define gv_shapes_num_shapes(adata) \
     (adata->shapes->len)

#define gv_shapes_get_shape(adata,id) \
     ((GvShape*)g_ptr_array_index(adata->shapes, id))

#ifdef HAVE_OGR
#define gv_have_ogr_support() 1
#else
#define gv_have_ogr_support() 0
#endif

#endif /*__GV_SHAPES_H__ */
