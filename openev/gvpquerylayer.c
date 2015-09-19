/******************************************************************************
 * $Id: gvpquerylayer.c,v 1.11 2004/08/20 13:53:47 warmerda Exp $
 *
 * Project:  OpenEV
 * Purpose:  Point query layer.
 * Author:   OpenEV Team
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
 * $Log: gvpquerylayer.c,v $
 * Revision 1.11  2004/08/20 13:53:47  warmerda
 * allow GvShapes to be passed into constructor
 *
 * Revision 1.10  2003/08/27 19:58:43  warmerda
 * added force_simple flag for gv_view_area_bmfont_draw
 *
 * Revision 1.9  2003/02/27 03:59:21  warmerda
 * added view to gv_shapes_layer_get_draw_info
 *
 * Revision 1.8  2002/11/04 21:42:06  sduclos
 * change geometric data type name to gvgeocoord
 *
 * Revision 1.7  2000/08/04 14:14:12  warmerda
 * GvShapes shape ids now persistent
 *
 * Revision 1.6  2000/06/20 13:26:55  warmerda
 * added standard headers
 *
 */

#include "gvpquerylayer.h"
#include "gvutils.h"
#include <GL/gl.h>

static void gv_pquery_layer_class_init(GvPqueryLayerClass *klass);
static void gv_pquery_layer_init(GvPqueryLayer *layer);
static void gv_pquery_layer_setup(GvLayer *layer, GvViewArea *view);
static void gv_pquery_layer_draw(GvLayer *layer, GvViewArea *view);
static void gv_pquery_layer_draw_selected(GvShapeLayer *layer, 
                                          GvViewArea *view);

GtkType
gv_pquery_layer_get_type(void)
{
    static GtkType pquery_layer_type = 0;

    if (!pquery_layer_type)
    {
	static const GtkTypeInfo pquery_layer_info =
	{
	    "GvPqueryLayer",
	    sizeof(GvPqueryLayer),
	    sizeof(GvPqueryLayerClass),
	    (GtkClassInitFunc) gv_pquery_layer_class_init,
	    (GtkObjectInitFunc) gv_pquery_layer_init,
	    /* reserved_1 */ NULL,
	    /* reserved_2 */ NULL,
	    (GtkClassInitFunc) NULL,
	};

	pquery_layer_type = gtk_type_unique(gv_shapes_layer_get_type(),
					    &pquery_layer_info);
    }
    return pquery_layer_type;
}

static void
gv_pquery_layer_class_init(GvPqueryLayerClass *klass)
{
    GvLayerClass *layer_class;
    GvShapeLayerClass *shape_layer_class;

    layer_class = (GvLayerClass*) klass;
    shape_layer_class = (GvShapeLayerClass*) klass;

    layer_class->setup = gv_pquery_layer_setup;
    layer_class->draw = gv_pquery_layer_draw;
    shape_layer_class->draw_selected = gv_pquery_layer_draw_selected;
}

static void
gv_pquery_layer_init(GvPqueryLayer *layer)
{
    layer->font = 0;
}

GtkObject *
gv_pquery_layer_new( GvShapes *data )
{
    GvPqueryLayer *layer = GV_PQUERY_LAYER(gtk_type_new(
	gv_pquery_layer_get_type()));

    if( data == NULL )
    {
        data = GV_SHAPES(gv_shapes_new());
        gv_data_set_name( GV_DATA(data), "Query Points" );
    }

    gv_shapes_layer_set_data( GV_SHAPES_LAYER(layer), data );

    return GTK_OBJECT(layer);
}

/*******************************************************/

static void
gv_pquery_layer_setup(GvLayer *rlayer, GvViewArea *view)
{
    GvPqueryLayer *layer = GV_PQUERY_LAYER(rlayer);

    layer->font = gv_view_area_bmfont_load(view, "fixed");
}

static void gv_pquery_layer_draw_text(GvViewArea * view, 
                                      GvPqueryLayer *layer, GvShape *shape,
                                      gvgeocoord dx, gvgeocoord dy )

{
    const char *text;
    gvgeocoord    x, y;

    x = gv_shape_get_x( shape, 0, 0 );
    y = gv_shape_get_y( shape, 0, 0 );

    /* FIXME: the label should be cached in the point structure */
    text = gv_format_point_query( view, gv_data_get_properties(GV_DATA(layer)),
                                  x, y );
                                  
    gv_view_area_bmfont_draw(view, layer->font, x+dx, y+dy, 
                             (char *) text, 0);
}

static void
gv_pquery_layer_draw(GvLayer *rlayer, GvViewArea *view)
{
    GvPqueryLayer *layer = GV_PQUERY_LAYER(rlayer);
    gint i, points;
    gint *selected, presentation;
    gvgeocoord dx, dy;
    gint hit_selected = FALSE;
    GvShapeDrawInfo    drawinfo;
    GvShape           *shape;
    
    presentation = GV_LAYER(layer)->presentation;
    selected = GV_SHAPE_LAYER_SELBUF(layer);

    gv_shapes_layer_get_draw_info( view, GV_SHAPES_LAYER(rlayer), &drawinfo );
    points = gv_shapes_num_shapes(GV_SHAPES_LAYER(layer)->data);
    
    /* Call the parent class draw func to make crosshairs */
    (*((GvLayerClass*)gtk_type_class(GV_TYPE_SHAPES_LAYER))->draw)
	(GV_LAYER(layer), view);

    /* Get offset for text */
    dx = dy = drawinfo.point_size;
    gv_view_area_correct_for_transform(view, dx, dy, &dx, &dy);    

    glColor4fv(drawinfo.point_color);
    for (i=0; i < points; ++i)
    {
	if (selected[i] && !presentation)
	{
	    hit_selected = 1;
	    continue;
	}

        shape = gv_shapes_get_shape(GV_SHAPES_LAYER(layer)->data, i);
        if( shape != NULL )
            gv_pquery_layer_draw_text( view, layer, shape, dx, dy );
    }

    if (hit_selected && ! GV_SHAPE_LAYER(layer)->flags & GV_DELAY_SELECTED)
    {
	gv_pquery_layer_draw_selected(GV_SHAPE_LAYER(layer), view);
    }     
}

static void
gv_pquery_layer_draw_selected(GvShapeLayer *rlayer, GvViewArea *view)
{
    gint i, points;
    gint *selected;
    gvgeocoord dx, dy;
    GvPqueryLayer *layer = GV_PQUERY_LAYER(rlayer);
    GvShapeDrawInfo    drawinfo;
    GvShape           *shape;

    selected = GV_SHAPE_LAYER_SELBUF(layer);

    gv_shapes_layer_get_draw_info( view, GV_SHAPES_LAYER(rlayer), &drawinfo );
    points = gv_shapes_num_shapes(GV_SHAPES_LAYER(layer)->data);
    
    /* Call the parent class draw func to make crosshairs */
    (*((GvShapeLayerClass*)gtk_type_class(GV_TYPE_SHAPES_LAYER))->
     draw_selected)(GV_SHAPE_LAYER(layer), view);

    /* Get offset for text */
    dx = dy = drawinfo.point_size;
    gv_view_area_correct_for_transform(view, dx, dy, &dx, &dy);    

    glColor4fv(drawinfo.point_color);
    for (i=0; i < points; ++i)
    {
	if (!selected[i])
	{
	    continue;
	}

        shape = gv_shapes_get_shape(GV_SHAPES_LAYER(layer)->data, i);
        if( shape != NULL )
            gv_pquery_layer_draw_text( view, layer, shape, dx, dy );
    }
}


