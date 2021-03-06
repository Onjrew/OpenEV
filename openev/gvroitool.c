/******************************************************************************
 * $Id: gvroitool.c,v 1.11 2002/11/04 21:42:06 sduclos Exp $
 *
 * Project:  OpenEV
 * Purpose:  Region of interest (box in raster coordinates) editing mode.
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
 * $Log: gvroitool.c,v $
 * Revision 1.11  2002/11/04 21:42:06  sduclos
 * change geometric data type name to gvgeocoord
 *
 * Revision 1.10  2000/07/27 20:06:23  warmerda
 * added boundary constraints
 *
 * Revision 1.9  2000/06/30 18:04:55  srawlin
 * added ability to set ROI constraints
 *
 * Revision 1.8  2000/06/30 14:05:36  srawlin
 * fixed bug where ROI selected then zoom in
 *
 * Revision 1.7  2000/06/29 21:18:10  srawlin
 * Added CHANGED and CHANGING Signals
 *
 * Revision 1.6  2000/06/29 16:15:55  srawlin
 * added function to create new ROI
 *
 * Revision 1.5  2000/06/20 13:26:55  warmerda
 * added standard headers
 *
 */

#include "gvroitool.h"
#include <gtk/gtksignal.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>

#define PICK_SIZE 6.0

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

/* Signals */
enum
{
    ROI_CHANGED,
    ROI_CHANGING,
    LAST_SIGNAL
};

static void gv_roi_tool_class_init(GvRoiToolClass *klass);
static void gv_roi_tool_init(GvRoiTool *tool);
static void gv_roi_tool_draw(GvTool *tool);
static void gv_roi_tool_button_press(GvTool *tool, GdkEventButton *event);
static void gv_roi_tool_button_release(GvTool *tool, GdkEventButton *event);
static void gv_roi_tool_motion_notify(GvTool *tool, GdkEventMotion *event);
static void gv_roi_tool_deactivate(GvTool *tool, GvViewArea *view);
static void gv_roi_tool_start_resize(GvRoiTool *tool, gint pick, gvgeocoord pointer_x, gvgeocoord pointer_y);
static gint gv_roi_tool_pick_border(GvRoiTool *tool, gvgeocoord x, gvgeocoord y);

static guint roitool_signals[LAST_SIGNAL] = { 0 };

GtkType
gv_roi_tool_get_type(void)
{
    static GtkType roi_tool_type = 0;

    if (!roi_tool_type)
    {
	static const GtkTypeInfo roi_tool_info =
	{
	    "GvRoiTool",
	    sizeof(GvRoiTool),
	    sizeof(GvRoiToolClass),
	    (GtkClassInitFunc) gv_roi_tool_class_init,
	    (GtkObjectInitFunc) gv_roi_tool_init,
	    /* reserved_1 */ NULL,
	    /* reserved_2 */ NULL,
	    (GtkClassInitFunc) NULL,
	};

	roi_tool_type = gtk_type_unique(gv_tool_get_type(),
					&roi_tool_info);
    }
    return roi_tool_type;
}

static void
gv_roi_tool_class_init(GvRoiToolClass *klass)
{
    GvToolClass *tool_class;
    GtkObjectClass *object_class;

    object_class = (GtkObjectClass*) klass;
    tool_class = (GvToolClass*)klass;

    roitool_signals[ROI_CHANGED] =
	gtk_signal_new ("roi_changed",
			GTK_RUN_FIRST,
			object_class->type,
			GTK_SIGNAL_OFFSET (GvRoiToolClass,roi_changed),
			gtk_marshal_NONE__POINTER,
			GTK_TYPE_NONE, 0 );

    roitool_signals[ROI_CHANGING] =
	gtk_signal_new ("roi_changing",
			GTK_RUN_FIRST,
			object_class->type,
			GTK_SIGNAL_OFFSET (GvRoiToolClass,roi_changed),
			gtk_marshal_NONE__POINTER,
			GTK_TYPE_NONE, 0 );

    gtk_object_class_add_signals(object_class, roitool_signals, LAST_SIGNAL);
    
    klass->roi_changed = NULL;
    klass->roi_changing = NULL;

    tool_class->deactivate = gv_roi_tool_deactivate;
    tool_class->draw = gv_roi_tool_draw;
    tool_class->button_press = gv_roi_tool_button_press;
    tool_class->button_release = gv_roi_tool_button_release;
    tool_class->motion_notify = gv_roi_tool_motion_notify;
}
static void
gv_roi_tool_init(GvRoiTool *tool)
{
    tool->pick = PICK_NONE;
    
    tool->roi_marked = FALSE;
    tool->banding = FALSE;
}

GvTool *
gv_roi_tool_new(void)
{
    GvTool *tool;

    tool = GV_TOOL(gtk_type_new(GV_TYPE_ROI_TOOL));

    

    return tool;
    
}

gint
gv_roi_tool_get_rect(GvRoiTool *tool, GvRect *rect)
{
    if (!tool->roi_marked)
    {
	return FALSE;
    }

    rect->x = MIN(tool->v_head.x, tool->v_tail.x);
    rect->y = MIN(tool->v_head.y, tool->v_tail.y);
    rect->width = tool->v_tail.x - tool->v_head.x;
    rect->height = tool->v_tail.y - tool->v_head.y;
    rect->width = ABS(rect->width);
    rect->height = ABS(rect->height);

    return TRUE;
}

gint
gv_roi_tool_new_rect(GvRoiTool *tool, GvRect *rect)
{
    /* Create new ROI */
    tool->roi_marked = TRUE;
    
    tool->v_head.x = rect->x;
    tool->v_head.y = rect->y;
    tool->v_tail.x = rect->x + ABS(rect->width);
    tool->v_tail.y = rect->y + ABS(rect->height);

    gv_tool_clamp_to_bounds( GV_TOOL(tool), 
                             &(tool->v_head.x), &(tool->v_head.y) );
    gv_tool_clamp_to_bounds( GV_TOOL(tool), 
                             &(tool->v_tail.x), &(tool->v_tail.y) );

    /* Check input parameters */
    if (rect->width <=0 || rect->height <= 0)
    {
        tool->roi_marked = FALSE;
        return FALSE;
    }

    gtk_signal_emit(GTK_OBJECT(tool), 
                    roitool_signals[ROI_CHANGED]);

    gv_view_area_queue_draw(GV_TOOL(tool)->view);	

    return TRUE;
}

/**************************************************************/

static void
gv_roi_tool_button_press(GvTool *rtool, GdkEventButton *event)
{
    GvRoiTool *tool = GV_ROI_TOOL(rtool);

    if ((event->button == 1)  && !(event->state & GDK_CONTROL_MASK)
                              && !(event->state & GDK_SHIFT_MASK) )
    {
	if (tool->roi_marked)
	{
	    /* Check for contact with ROI border */
	    gint pick;
	    gvgeocoord pointer_x, pointer_y;

	    pick = gv_roi_tool_pick_border(tool, event->x, event->y);

	    if (pick != PICK_NONE)		
	    {
		/* Start ROI resize dragging operation */
		gv_view_area_map_pointer(GV_TOOL(tool)->view,
					 event->x, event->y,
					 &pointer_x, &pointer_y);
		gv_roi_tool_start_resize(tool, pick, pointer_x, pointer_y);
		return;
	    }
	}

	/* Set head and tail vertex to pointer position */
	/* Map pointer position */
	gv_view_area_map_pointer(GV_TOOL(tool)->view, event->x, event->y,
				 &tool->v_tail.x, &tool->v_tail.y);
	tool->v_head = tool->v_tail;

        if( gv_tool_check_bounds( GV_TOOL(tool), 
                                  tool->v_tail.x, tool->v_tail.y ) )
        {
            /* Begin rubber band */
            tool->banding = TRUE;
            tool->roi_marked = TRUE;

            /* No drag offset for initial rubber banding */
            tool->v_drag_offset.x = tool->v_drag_offset.y = 0.0;
            tool->drag_right = tool->drag_bottom = TRUE;
        }
    }
}

static void
gv_roi_tool_button_release(GvTool *rtool, GdkEventButton *event)
{
    GvRoiTool *tool = GV_ROI_TOOL(rtool);

    if (event->button == 1 && tool->banding)
    {
	gvgeocoord pointer_x, pointer_y;
	
	/* End rubber band */
	tool->banding = FALSE;

	/* Map pointer position */
	gv_view_area_map_pointer(GV_TOOL(tool)->view, event->x, event->y,
				 &pointer_x, &pointer_y);

	/* Reposition tail vertex */
	if (tool->drag_right)
	{
	    tool->v_tail.x = pointer_x + tool->v_drag_offset.x;
	}
	if (tool->drag_bottom)
	{
	    tool->v_tail.y = pointer_y + tool->v_drag_offset.y;
	}

        gv_tool_clamp_to_bounds( rtool, 
                                 &(tool->v_tail.x), &(tool->v_tail.y) );

	/* Reject empty regions */
	if (tool->v_tail.x == tool->v_head.x ||
	    tool->v_tail.y == tool->v_head.y)
	{
	    tool->roi_marked = FALSE;
	}
	
	gv_view_area_queue_draw(GV_TOOL(tool)->view);	

        gtk_signal_emit(GTK_OBJECT(tool), 
                        roitool_signals[ROI_CHANGED]);
    }
}

static void
gv_roi_tool_motion_notify(GvTool *rtool, GdkEventMotion *event)
{
    GvRoiTool *tool = GV_ROI_TOOL(rtool);

    if (tool->banding)
    {
	gvgeocoord pointer_x, pointer_y;
	
	/* Resize rubber band */
	/* Map pointer position */
	gv_view_area_map_pointer(GV_TOOL(tool)->view, event->x, event->y,
				 &pointer_x, &pointer_y);

	/* Reposition tail vertex */
	if (tool->drag_right)
	{
	    tool->v_tail.x = pointer_x + tool->v_drag_offset.x;
	}
	if (tool->drag_bottom)
	{
	    tool->v_tail.y = pointer_y + tool->v_drag_offset.y;
	}

        gv_tool_clamp_to_bounds( rtool, 
                                 &(tool->v_tail.x), &(tool->v_tail.y) );

        gtk_signal_emit(GTK_OBJECT(tool), 
                        roitool_signals[ROI_CHANGING]);	

	gv_view_area_queue_draw(GV_TOOL(tool)->view);	
    }
    else if (tool->roi_marked)
    {
	/* Highlight roi sides to indicate the effect of a click & drag */
	gint pick;

	pick = gv_roi_tool_pick_border(tool, event->x, event->y);
	if (pick != tool->pick)
	{
	    tool->pick = pick;
	    gv_view_area_queue_draw(GV_TOOL(tool)->view);
	}
    }
}

static void
gv_roi_tool_draw(GvTool *rtool)
{
    GvRoiTool *tool = GV_ROI_TOOL(rtool);

    if (tool->roi_marked)
    {
	glColor3f(1.0, 0.5, 0.0);
	glBegin(GL_LINE_LOOP);
	glVertex2(tool->v_head.x, tool->v_head.y);
	glVertex2(tool->v_head.x, tool->v_tail.y);
	glVertex2(tool->v_tail.x, tool->v_tail.y);
	glVertex2(tool->v_tail.x, tool->v_head.y);
	glEnd();

	if (tool->pick != PICK_NONE)
	{
	    glColor3f(1.0, 0.0, 0.0);
	    glBegin(GL_LINES);
	    switch (tool->pick)
	    {
		case PICK_CORNER_TOPLEFT:
		    glVertex2(tool->v_tail.x, tool->v_head.y);
		    glVertex2(tool->v_head.x, tool->v_head.y);
		    glVertex2(tool->v_head.x, tool->v_head.y);
		    glVertex2(tool->v_head.x, tool->v_tail.y);
		    break;

		case PICK_CORNER_BOTTOMLEFT:
		    glVertex2(tool->v_head.x, tool->v_tail.y);
		    glVertex2(tool->v_tail.x, tool->v_tail.y);
		    glVertex2(tool->v_head.x, tool->v_head.y);
		    glVertex2(tool->v_head.x, tool->v_tail.y);
		    break;

		case PICK_CORNER_BOTTOMRIGHT:
		    glVertex2(tool->v_head.x, tool->v_tail.y);
		    glVertex2(tool->v_tail.x, tool->v_tail.y);
		    glVertex2(tool->v_tail.x, tool->v_tail.y);
		    glVertex2(tool->v_tail.x, tool->v_head.y);
		    break;

		case PICK_CORNER_TOPRIGHT:
		    glVertex2(tool->v_tail.x, tool->v_head.y);
		    glVertex2(tool->v_head.x, tool->v_head.y);
		    glVertex2(tool->v_tail.x, tool->v_tail.y);
		    glVertex2(tool->v_tail.x, tool->v_head.y);
		    break;		    
		
		case PICK_SIDE_TOP:
		    glVertex2(tool->v_tail.x, tool->v_head.y);
		    glVertex2(tool->v_head.x, tool->v_head.y);
		    break;

		case PICK_SIDE_RIGHT:
		    glVertex2(tool->v_tail.x, tool->v_tail.y);
		    glVertex2(tool->v_tail.x, tool->v_head.y);
		    break;

		case PICK_SIDE_BOTTOM:
		    glVertex2(tool->v_head.x, tool->v_tail.y);
		    glVertex2(tool->v_tail.x, tool->v_tail.y);
		    break;

		case PICK_SIDE_LEFT:
		    glVertex2(tool->v_head.x, tool->v_head.y);
		    glVertex2(tool->v_head.x, tool->v_tail.y);
		    break;
	    }
	    glEnd();
	}
    }
}

static void
gv_roi_tool_deactivate(GvTool *rtool, GvViewArea *view)
{
    GvRoiTool *tool = GV_ROI_TOOL(rtool);

    /* Call the parent class func */
    GV_TOOL_DEACTIVATE(tool, view);

    tool->roi_marked = FALSE;
    tool->banding = FALSE;

    gv_view_area_queue_draw(view);
}

static void
gv_roi_tool_start_resize(GvRoiTool *tool, gint pick, gvgeocoord pointer_x,
			 gvgeocoord pointer_y)
{
    gvgeocoord temp;
#define SWAP(a,b) {temp=a; a=b; b=temp;}
    
    /* Reposition the head and tail vertexes so we are always dragging
       the bottom right corner */
    switch (pick)
    {
	case PICK_CORNER_TOPLEFT:
	case PICK_SIDE_TOP:
	case PICK_SIDE_LEFT:
	    /* Swap head and tail */
	    SWAP(tool->v_head.x, tool->v_tail.x);
	    SWAP(tool->v_head.y, tool->v_tail.y);
	    break;

	case PICK_CORNER_TOPRIGHT:
	    /* Swap y coords only */
	    SWAP(tool->v_head.y, tool->v_tail.y);
	    break;

	case PICK_CORNER_BOTTOMLEFT:
	    /* Swap x coords only */
	    SWAP(tool->v_head.x, tool->v_tail.x);
	    break;
    }

    /* Set the drag flags for side or corner dragging */
    switch (pick)
    {
	case PICK_SIDE_TOP:
	case PICK_SIDE_BOTTOM:
	    tool->drag_right = FALSE;
	    tool->drag_bottom = TRUE;
	    tool->pick = PICK_SIDE_BOTTOM;
	    break;

	case PICK_SIDE_LEFT:
	case PICK_SIDE_RIGHT:
	    tool->drag_right = TRUE;
	    tool->drag_bottom = FALSE;
	    tool->pick = PICK_SIDE_RIGHT;
	    break;

	default:
	    tool->drag_right = TRUE;
	    tool->drag_bottom = TRUE;
	    tool->pick = PICK_CORNER_BOTTOMRIGHT;
	    break;
    }

    /* Set the drag offset vector */
    tool->v_drag_offset.x = tool->v_tail.x - pointer_x;
    tool->v_drag_offset.y = tool->v_tail.y - pointer_y;

    /* Enable dragging */
    tool->banding = TRUE;

#undef SWAP    
}

static gint
gv_roi_tool_pick_border(GvRoiTool *tool, gvgeocoord x, gvgeocoord y)
{
    GvViewArea *view;
    GLuint buf[16];
    GLint hits;
    GLint vp[4];

    /* FIXME: need to make the view area current GL context */

    view = GV_TOOL(tool)->view;
    vp[0] = vp[1]  = 0;
    vp[2] = (GLint)view->state.shape_x;
    vp[3] = (GLint)view->state.shape_y;
    
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluPickMatrix(x, vp[3]-y, PICK_SIZE, PICK_SIZE, vp);
    gluOrtho2D(-vp[2]/2.0, vp[2]/2.0, -vp[3]/2.0, vp[3]/2.0);

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    glRotate(view->state.rot, 0.0, 0.0, 1.0);
    glScale(view->state.linear_zoom * view->state.flip_x,
	     view->state.linear_zoom * view->state.flip_y, 1.0);
    glTranslate(view->state.tx, view->state.ty, 0.0);

    glSelectBuffer(16, buf);
    glRenderMode(GL_SELECT);

    glInitNames();
    glPushName(-1);

    /* Top */
    glLoadName(0);
    glBegin(GL_LINES);
    glVertex2(tool->v_head.x, tool->v_head.y);
    glVertex2(tool->v_tail.x, tool->v_head.y);
    glEnd();

    /* Right */
    glLoadName(1);
    glBegin(GL_LINES);
    glVertex2(tool->v_tail.x, tool->v_head.y);
    glVertex2(tool->v_tail.x, tool->v_tail.y);
    glEnd();

    /* Bottom */
    glLoadName(2);
    glBegin(GL_LINES);
    glVertex2(tool->v_tail.x, tool->v_tail.y);
    glVertex2(tool->v_head.x, tool->v_tail.y);
    glEnd();

    /* Left */
    glLoadName(3);
    glBegin(GL_LINES);
    glVertex2(tool->v_head.x, tool->v_tail.y);
    glVertex2(tool->v_head.x, tool->v_head.y);
    glEnd();

    hits = glRenderMode(GL_RENDER);
    
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();

    if (hits > 1)
    {
	/* We've picked a corner */
	if (buf[3] == 0 && buf[7] == 1)
	    return PICK_CORNER_TOPRIGHT;
	if (buf[3] == 1)
	    return PICK_CORNER_BOTTOMRIGHT;
	if (buf[3] == 2)
	    return PICK_CORNER_BOTTOMLEFT;
	if (buf[3] == 0 && buf[7] == 3)
	    return PICK_CORNER_TOPLEFT;
    }
    else if (hits == 1)
    {
	/* We've picked a side */
	return PICK_SIDE_TOP + buf[3];
    }

    /* No hits */
    return PICK_NONE;
}
