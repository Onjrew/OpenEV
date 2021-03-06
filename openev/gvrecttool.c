/******************************************************************************
 * $Id: gvrecttool.c,v 1.7 2002/11/04 21:42:06 sduclos Exp $
 *
 * Project:  OpenEV
 * Purpose:  Rectangle editing mode in GvShapesLayer.
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
 * $Log: gvrecttool.c,v $
 * Revision 1.7  2002/11/04 21:42:06  sduclos
 * change geometric data type name to gvgeocoord
 *
 * Revision 1.6  2001/08/08 17:44:12  warmerda
 * use gv_shape_type() macro
 *
 * Revision 1.5  2000/08/08 20:58:47  warmerda
 * recover from layer destruction
 *
 * Revision 1.4  2000/08/03 18:11:51  warmerda
 * don't create zero sized rectangles
 *
 * Revision 1.3  2000/07/27 20:06:23  warmerda
 * added boundary constraints
 *
 * Revision 1.2  2000/07/27 17:52:09  warmerda
 * allow edit of existing rectangles
 *
 * Revision 1.1  2000/07/25 23:34:03  warmerda
 * New
 *
 */

#include <stdio.h>
#include <gtk/gtksignal.h>
#include <gdk/gdkkeysyms.h>
#include "gvrecttool.h"
#include "gvundo.h"
#include <GL/gl.h>

static void gv_rect_tool_class_init(GvRectToolClass *klass);
static void gv_rect_tool_init(GvRectTool *tool);
static void gv_rect_tool_draw(GvRectTool *tool);
static void gv_rect_tool_button_press(GvTool *tool, GdkEventButton *event);
static void gv_rect_tool_button_release(GvTool *tool, GdkEventButton *event);
static void gv_rect_tool_motion_notify(GvTool *tool, GdkEventMotion *event);
static void gv_rect_tool_key_press(GvTool *tool, GdkEventKey *event);
static void gv_rect_tool_deactivate(GvTool *tool, GvViewArea *view);
static gint gv_rect_tool_configure(GvRectTool *tool);

/* Return values for gv_roi_tool_pick_border() */
enum
{
    PICK_NONE = 0,
    PICK_CORNER_TOPLEFT,
    PICK_CORNER_BOTTOMLEFT,
    PICK_CORNER_BOTTOMRIGHT,
    PICK_CORNER_TOPRIGHT,
    PICK_SIDE_TOP,
    PICK_SIDE_RIGHT,
    PICK_SIDE_BOTTOM,
    PICK_SIDE_LEFT
};

GtkType
gv_rect_tool_get_type(void)
{
    static GtkType rect_tool_type = 0;

    if (!rect_tool_type)
    {
	static const GtkTypeInfo rect_tool_info =
	{
	    "GvRectTool",
	    sizeof(GvRectTool),
	    sizeof(GvRectToolClass),
	    (GtkClassInitFunc) gv_rect_tool_class_init,
	    (GtkObjectInitFunc) gv_rect_tool_init,
	    /* reserved_1 */ NULL,
	    /* reserved_2 */ NULL,
	    (GtkClassInitFunc) NULL,
	};

	rect_tool_type = gtk_type_unique(gv_tool_get_type(),
					 &rect_tool_info);
    }
    return rect_tool_type;
}

static void
gv_rect_tool_class_init(GvRectToolClass *klass)
{
    GvToolClass *tool_class;

    tool_class = (GvToolClass*)klass;
    tool_class->deactivate = gv_rect_tool_deactivate;
    tool_class->button_press = gv_rect_tool_button_press;
    tool_class->button_release = gv_rect_tool_button_release;
    tool_class->motion_notify = gv_rect_tool_motion_notify;
    tool_class->key_press = gv_rect_tool_key_press;
}

static void
gv_rect_tool_init(GvRectTool *tool)
{
    GV_TOOL(tool)->cursor = gdk_cursor_new(GDK_TCROSS);
    tool->layer = NULL;
    tool->named_layer = NULL;
    tool->drawing = FALSE;
}

GvTool *
gv_rect_tool_new(void)
{
    return GV_TOOL(gtk_type_new(GV_TYPE_RECT_TOOL));
}

static gint gv_rect_tool_layer_destroy( GtkObject *layer, gpointer data )

{
    GvRectTool *tool = (GvRectTool *) data;

    if( tool->layer == GV_SHAPES_LAYER(layer) )
        gv_rect_tool_set_layer( tool, NULL );
    
    return 0;
}

void
gv_rect_tool_set_layer(GvRectTool *tool, GvShapeLayer *layer)
{
    if (GV_TOOL(tool)->view == NULL)
    {
	g_warning("gv_rect_tool_set_layer(): inactive tool");
	return;
    }

    if( layer != NULL && gv_data_is_read_only( GV_DATA(layer) ) )
    {
        g_warning( "gv_rect_tool_set_layer(): layer is read-only" );
        return;
    }

    /* Disconnect from the previous layer (for draw) */
    if (tool->layer)
    {
	if (tool->drawing)
	{
            tool->drawing = FALSE;
	}
	gv_shape_layer_clear_selection(GV_SHAPE_LAYER(tool->layer));
	gtk_signal_disconnect_by_data(GTK_OBJECT(tool->layer), (gpointer)tool);
	gv_view_area_queue_draw(GV_TOOL(tool)->view);
    }
 
    if( layer == NULL )
        tool->layer = NULL;
    else
        tool->layer = GV_SHAPES_LAYER(layer);

    if (layer)
    {
	gv_view_area_set_active_layer(GV_TOOL(tool)->view, GTK_OBJECT(layer));
	
        /* Redraw when the layer draws */
	gtk_signal_connect_object_after(GTK_OBJECT(layer), "draw",
					GTK_SIGNAL_FUNC(gv_rect_tool_draw),
					GTK_OBJECT(tool));
        /* Recover if layer destroyed */
        gtk_signal_connect(
            GTK_OBJECT(layer), "destroy", 
            GTK_SIGNAL_FUNC(gv_rect_tool_layer_destroy),
            GTK_OBJECT(tool));
    }
}

void
gv_rect_tool_set_named_layer(GvRectTool *tool, gchar *name)
{
    if (tool->named_layer)
    {
	g_free(tool->named_layer);
	tool->named_layer = NULL;
    }
    if (name)
    {
	tool->named_layer = g_strdup(name);	
    }
    /* Tool layer will be updated next time it is configured */
}

/********************************************************/

static void
gv_rect_tool_draw(GvRectTool *tool)
{
    if (tool->drawing)
    {
	/* Color is set when the layer is drawn,
	   so we don't need to repeat it here */

	glBegin(GL_LINE_LOOP);
	glVertex2(tool->v_head.x, tool->v_head.y);
	glVertex2(tool->v_head.x, tool->v_tail.y);
	glVertex2(tool->v_tail.x, tool->v_tail.y);
	glVertex2(tool->v_tail.x, tool->v_head.y);
	glVertex2(tool->v_head.x, tool->v_head.y);
	glEnd();
    }
}

static void 
gv_rect_tool_reshape( GvRectTool *r_tool, gvgeocoord x, gvgeocoord y )

{
    GvShape *shape;
    gvgeocoord   x1, y1, x2, y2;

    gv_tool_clamp_to_bounds( GV_TOOL(r_tool), &x, &y );

    shape = gv_shapes_get_shape( r_tool->layer->data, r_tool->shape_id );
    if( shape == NULL || gv_shape_get_nodes( shape, 0 ) != 5 )
        return;

    shape = gv_shape_copy( shape );
    
    x1 = gv_shape_get_x(shape,0,0);
    y1 = gv_shape_get_y(shape,0,0);
    x2 = gv_shape_get_x(shape,0,2);
    y2 = gv_shape_get_y(shape,0,2);

    if( r_tool->picked == PICK_SIDE_TOP )
        y1 = y;
    else if( r_tool->picked == PICK_SIDE_RIGHT )
        x2 = x;
    else if( r_tool->picked == PICK_SIDE_BOTTOM )
        y2 = y;
    else if( r_tool->picked == PICK_SIDE_LEFT )
        x1 = x;
    else if( r_tool->picked == PICK_CORNER_TOPLEFT )
    {
        x1 = x;
        y1 = y;
    }
    else if( r_tool->picked == PICK_CORNER_TOPRIGHT )
    {
        x2 = x;
        y1 = y;
    }
    else if( r_tool->picked == PICK_CORNER_BOTTOMRIGHT )
    {
        x2 = x;
        y2 = y;
    }
    else if( r_tool->picked == PICK_CORNER_BOTTOMLEFT )
    {
        x1 = x;
        y2 = y;
    }

    gv_shape_set_xyz( shape, 0, 0, x1, y1, 0 );
    gv_shape_set_xyz( shape, 0, 1, x1, y2, 0 );
    gv_shape_set_xyz( shape, 0, 2, x2, y2, 0 );
    gv_shape_set_xyz( shape, 0, 3, x2, y1, 0 );
    gv_shape_set_xyz( shape, 0, 4, x1, y1, 0 );

    gv_shapes_replace_shapes( r_tool->layer->data, 1, &(r_tool->shape_id),
                              &shape, FALSE );
}

static void
gv_rect_tool_button_press(GvTool *r_tool, GdkEventButton *event)
{
    GvRectTool *tool = GV_RECT_TOOL(r_tool);

    if (event->button == 1 && !tool->drawing )
    {
        GvNodeInfo edit_node;
        int        before, shape_id, is_rectangle = FALSE;

	if (!gv_rect_tool_configure(tool)) return;

	if (gv_shape_layer_pick_shape(GV_SHAPE_LAYER(tool->layer), 
                                      GV_TOOL(tool)->view,
				      event->x, event->y, &shape_id))
        {
            GvShape *shape;

            /* Is the shape a rectangle? */
            shape = gv_shapes_get_shape( tool->layer->data, shape_id );
            if( shape != NULL 
                && gv_shape_type(shape) == GVSHAPE_AREA
                && gv_shape_get_rings( shape ) == 1 
                && gv_shape_get_nodes( shape, 0 ) == 5 )
            {
                gvgeocoord   x1, y1, x2, y2;

                x1 = gv_shape_get_x(shape,0,0);
                y1 = gv_shape_get_y(shape,0,0);
                x2 = gv_shape_get_x(shape,0,2);
                y2 = gv_shape_get_y(shape,0,2);

                tool->winding = 1;
                is_rectangle = gv_shape_get_x(shape,0,1) == x1
                    && gv_shape_get_y(shape,0,1) == y2
                    && gv_shape_get_x(shape,0,3) == x2
                    && gv_shape_get_y(shape,0,3) == y1
                    && gv_shape_get_x(shape,0,4) == x1
                    && gv_shape_get_y(shape,0,4) == y1;

                if( !is_rectangle )
                {
                    tool->winding = 0;
                    is_rectangle = gv_shape_get_x(shape,0,1) == x2
                        && gv_shape_get_y(shape,0,1) == y1
                        && gv_shape_get_x(shape,0,3) == x1
                        && gv_shape_get_y(shape,0,3) == y2
                        && gv_shape_get_x(shape,0,4) == x1
                        && gv_shape_get_y(shape,0,4) == y1;
                }

                if( is_rectangle )
                {
                    gv_shape_layer_clear_selection(
                        GV_SHAPE_LAYER(tool->layer));
		    gv_shape_layer_select_shape(
                        GV_SHAPE_LAYER(tool->layer), shape_id);
                }
            }
        }

        /* Is the user selecting an existing rectangles edge/corner? */
	if (is_rectangle 
            && gv_shape_layer_pick_node(GV_SHAPE_LAYER(tool->layer), 
                                        GV_TOOL(tool)->view,
                                        event->x, event->y, &before,
                                        &edit_node) )
	{
            if( tool->winding == 0 )
            {
                if( before )
                    edit_node.node_id = 5 - edit_node.node_id;
                else
                    edit_node.node_id = 4 - edit_node.node_id;
            }

            if( before && edit_node.node_id == 1 )
                tool->picked = PICK_SIDE_LEFT;
            else if( before && edit_node.node_id == 2 )
                tool->picked = PICK_SIDE_BOTTOM;
            else if( before && edit_node.node_id == 3 )
                tool->picked = PICK_SIDE_RIGHT;
            else if( before && edit_node.node_id == 4 )
                tool->picked = PICK_SIDE_TOP;
            else if( edit_node.node_id == 0 )
                tool->picked = PICK_CORNER_TOPLEFT;
            else if( edit_node.node_id == 1 )
                tool->picked = PICK_CORNER_BOTTOMLEFT;
            else if( edit_node.node_id == 2 )
                tool->picked = PICK_CORNER_BOTTOMRIGHT;
            else if( edit_node.node_id == 3 )
                tool->picked = PICK_CORNER_TOPRIGHT;
            else if( edit_node.node_id == 4 )
                tool->picked = PICK_CORNER_TOPLEFT;
            else
            {
                g_warning( "Yikes!  What node is this?" );
                return;
            }

            tool->reshaping = TRUE;
            tool->shape_id = edit_node.shape_id;
            
            /* Close down undo.  A single operation describing the new
               ring will be pushed to undo when drawing stops. */
            gv_undo_close();
            gv_undo_disable();

            return;
        }

	/* Map pointer position to tail vertex */
	gv_view_area_map_pointer(GV_TOOL(tool)->view, event->x, event->y,
				 &tool->v_tail.x, &tool->v_tail.y);

	if( gv_tool_check_bounds( GV_TOOL(tool),
                                  tool->v_tail.x, tool->v_tail.y ) )
        {
            /* Start a new rect */
            tool->drawing = TRUE;
            tool->v_head = tool->v_tail;
        }
    }
}

static void
gv_rect_tool_button_release(GvTool *r_tool, GdkEventButton *event)
{
    GvRectTool *tool = GV_RECT_TOOL(r_tool);

    if (event->button == 1 && tool->drawing )
    {
        GvShape *shape;
	
	if (!gv_rect_tool_configure(tool)) return;

        /* Map pointer position to tail vertex */
        gv_view_area_map_pointer(GV_TOOL(tool)->view, event->x, event->y,
                                 &tool->v_tail.x, &tool->v_tail.y);
	
        gv_tool_clamp_to_bounds( GV_TOOL(tool),
				 &tool->v_tail.x, &tool->v_tail.y );


        if( tool->v_tail.x != tool->v_head.x 
            && tool->v_tail.y != tool->v_head.y )
        {
            /* create the new rectangle */
            shape = gv_shape_new( GVSHAPE_AREA );
            
            gv_shape_add_node( shape, 0, tool->v_tail.x, tool->v_tail.y, 0 );
            gv_shape_add_node( shape, 0, tool->v_tail.x, tool->v_head.y, 0 );
            gv_shape_add_node( shape, 0, tool->v_head.x, tool->v_head.y, 0 );
            gv_shape_add_node( shape, 0, tool->v_head.x, tool->v_tail.y, 0 );
            gv_shape_add_node( shape, 0, tool->v_tail.x, tool->v_tail.y, 0 ); 
            
            gv_shapes_layer_select_new_shape( GV_SHAPES_LAYER(tool->layer), 
                                              shape );
        }

        tool->drawing = FALSE;
        return;
    }

    if (event->button == 1 && tool->reshaping )
    {
	if (!gv_rect_tool_configure(tool)) return;

        /* Reopen undo.  Push a memento describing the ring addition */
        gv_undo_enable();
        gv_undo_open();

	/* Map pointer position to tail vertex */
	gv_view_area_map_pointer(GV_TOOL(tool)->view, event->x, event->y,
				 &tool->v_tail.x, &tool->v_tail.y);
        gv_rect_tool_reshape( tool, tool->v_tail.x, tool->v_tail.y );

        tool->reshaping = FALSE;
    }
}

static void
gv_rect_tool_motion_notify(GvTool *r_tool, GdkEventMotion *event)
{
    GvRectTool *tool = GV_RECT_TOOL(r_tool);

    if (tool->drawing)
    {
	/* Map pointer position to tail vertex */
	gv_view_area_map_pointer(GV_TOOL(tool)->view, event->x, event->y,
				 &tool->v_tail.x, &tool->v_tail.y);

        gv_tool_clamp_to_bounds( GV_TOOL(tool),
				 &tool->v_tail.x, &tool->v_tail.y );

	gv_view_area_queue_draw(GV_TOOL(tool)->view);
    }

    if (tool->reshaping)
    {
	/* Map pointer position to tail vertex */
	gv_view_area_map_pointer(GV_TOOL(tool)->view, event->x, event->y,
				 &tool->v_tail.x, &tool->v_tail.y);
        gv_rect_tool_reshape( tool, tool->v_tail.x, tool->v_tail.y );
    }
}

static void
gv_rect_tool_key_press(GvTool *rtool, GdkEventKey *event)
{
    GvRectTool *tool = GV_RECT_TOOL(rtool);

    if (!gv_rect_tool_configure(tool)) return;
    
    switch (event->keyval)
    {
	case GDK_Delete:
	case GDK_BackSpace:
	case GDK_Escape:
          if( tool->drawing )
          {
              tool->drawing = FALSE;
              gv_view_area_queue_draw(GV_TOOL(tool)->view);
          }
          if( tool->reshaping )
          {
              /* Reopen undo.  Push a memento describing the ring addition */
              gv_undo_enable();
              gv_undo_open();

              tool->reshaping = FALSE;
              gv_view_area_queue_draw(GV_TOOL(tool)->view);
          }
          break;
    }
}

static void
gv_rect_tool_deactivate(GvTool *r_tool, GvViewArea *view)
{
    GvRectTool *tool = GV_RECT_TOOL(r_tool);

    /* Disconnect from layer */
    if (tool->layer)
    {
	gv_rect_tool_set_layer(tool, NULL);
    }

    /* Call the parent class func */
    GV_TOOL_DEACTIVATE(tool, view);
}

static gint
gv_rect_tool_configure(GvRectTool *tool)
{
    /* Check that we still are working on the active layer */
    if (!tool->layer ||	GTK_OBJECT(tool->layer) !=
	gv_view_area_active_layer(GV_TOOL(tool)->view))
    {
	GtkObject *layer;

	if (tool->named_layer)
	{
	    /* Look for named layer if given */
	    layer = gv_view_area_get_named_layer(GV_TOOL(tool)->view,
						 tool->named_layer);
	}
	else
	{
            layer = gv_view_area_get_layer_of_type(GV_TOOL(tool)->view,
                                                   GV_TYPE_SHAPES_LAYER,
                                                   FALSE);
	}

	if (!layer)
	{
	    g_warning("gv_rect_tool_configure(): no shapes layer in view");
	    return FALSE;
	}

	gv_rect_tool_set_layer(tool, GV_SHAPE_LAYER(layer));
    }
    return tool->layer != NULL;
}
