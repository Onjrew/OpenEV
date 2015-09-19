/******************************************************************************
 * $Id: gvtool.c,v 1.11 2005/01/17 18:37:43 gmwalter Exp $
 *
 * Project:  OpenEV
 * Purpose:  Base class for editing mode tools.
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
 * $Log: gvtool.c,v $
 * Revision 1.11  2005/01/17 18:37:43  gmwalter
 * Add ability to reset tool cursor type.
 *
 * Revision 1.10  2002/11/04 21:42:07  sduclos
 * change geometric data type name to gvgeocoord
 *
 * Revision 1.9  2000/07/27 20:06:23  warmerda
 * added boundary constraints
 *
 * Revision 1.8  2000/06/20 13:26:55  warmerda
 * added standard headers
 *
 */

#include "gvtool.h"
#include <gtk/gtksignal.h>

enum
{
    ACTIVATE,
    DEACTIVATE,
    DRAW,
    BUTTON_PRESS,
    BUTTON_RELEASE,
    MOTION_NOTIFY,
    KEY_PRESS,
    ENTER_NOTIFY,
    LEAVE_NOTIFY,
    LAST_SIGNAL
};

static void gv_tool_class_init(GvToolClass *klass);
static void gv_tool_init(GvTool *tool);
static void gv_tool_real_activate(GvTool *tool, GvViewArea *area);
static void gv_tool_real_deactivate(GvTool *tool, GvViewArea *area);

static guint tool_signals[LAST_SIGNAL] = { 0 };

GtkType
gv_tool_get_type(void)
{
    static GtkType tool_type = 0;

    if (!tool_type)
    {
	static const GtkTypeInfo tool_info =
	{
	    "GvTool",
	    sizeof(GvTool),
	    sizeof(GvToolClass),
	    (GtkClassInitFunc) gv_tool_class_init,
	    (GtkObjectInitFunc) gv_tool_init,
	    /* reserved_1 */ NULL,
	    /* reserved_2 */ NULL,
	    (GtkClassInitFunc) NULL,
	};

	tool_type = gtk_type_unique(gtk_object_get_type(),
				    &tool_info);
    }
    return tool_type;
}

static void
gv_tool_class_init(GvToolClass *klass)
{
    GtkObjectClass *object_class;

    object_class = (GtkObjectClass*) klass;

    tool_signals[ACTIVATE] =
	gtk_signal_new ("activate",
			GTK_RUN_FIRST,
			object_class->type,
			GTK_SIGNAL_OFFSET (GvToolClass, activate),
			gtk_marshal_NONE__POINTER,
			GTK_TYPE_NONE, 1,
			GTK_TYPE_POINTER);

    tool_signals[DEACTIVATE] =
	gtk_signal_new ("deactivate",
			GTK_RUN_FIRST,
			object_class->type,
			GTK_SIGNAL_OFFSET (GvToolClass, deactivate),
			gtk_marshal_NONE__POINTER,
			GTK_TYPE_NONE, 1,
			GTK_TYPE_POINTER);    

    tool_signals[DRAW] =
	gtk_signal_new ("draw",
			GTK_RUN_FIRST,
			object_class->type,
			GTK_SIGNAL_OFFSET (GvToolClass, draw),
			gtk_marshal_NONE__NONE,
			GTK_TYPE_NONE, 0);    
	
    tool_signals[BUTTON_PRESS] =
	gtk_signal_new ("button-press",
			GTK_RUN_FIRST,
			object_class->type,
			GTK_SIGNAL_OFFSET (GvToolClass, button_press),
			gtk_marshal_NONE__POINTER,
			GTK_TYPE_NONE, 1,
			GTK_TYPE_POINTER);

    tool_signals[BUTTON_RELEASE] =
	gtk_signal_new ("button-release",
			GTK_RUN_FIRST,
			object_class->type,
			GTK_SIGNAL_OFFSET (GvToolClass, button_release),
			gtk_marshal_NONE__POINTER,
			GTK_TYPE_NONE, 1,
			GTK_TYPE_POINTER);

    tool_signals[MOTION_NOTIFY] =
	gtk_signal_new ("motion-notify",
			GTK_RUN_FIRST,
			object_class->type,
			GTK_SIGNAL_OFFSET (GvToolClass, motion_notify),
			gtk_marshal_NONE__POINTER,
			GTK_TYPE_NONE, 1,
			GTK_TYPE_POINTER);

    tool_signals[KEY_PRESS] =
	gtk_signal_new ("key-press",
			GTK_RUN_FIRST,
			object_class->type,
			GTK_SIGNAL_OFFSET (GvToolClass, key_press),
			gtk_marshal_NONE__POINTER,
			GTK_TYPE_NONE, 1,
			GTK_TYPE_POINTER);    

    tool_signals[ENTER_NOTIFY] =
	gtk_signal_new ("enter-notify",
			GTK_RUN_FIRST,
			object_class->type,
			GTK_SIGNAL_OFFSET (GvToolClass, enter_notify),
			gtk_marshal_NONE__POINTER,
			GTK_TYPE_NONE, 1,
			GTK_TYPE_POINTER);    

    tool_signals[LEAVE_NOTIFY] =
	gtk_signal_new ("leave-notify",
			GTK_RUN_FIRST,
			object_class->type,
			GTK_SIGNAL_OFFSET (GvToolClass, leave_notify),
			gtk_marshal_NONE__POINTER,
			GTK_TYPE_NONE, 1,
			GTK_TYPE_POINTER);    

    gtk_object_class_add_signals(object_class, tool_signals, LAST_SIGNAL);
    
    klass->activate = gv_tool_real_activate;
    klass->deactivate = gv_tool_real_deactivate;
    klass->draw = NULL;
    klass->button_press = NULL;
    klass->button_release = NULL;
    klass->motion_notify = NULL;
    klass->key_press = NULL;
    klass->enter_notify = NULL;
    klass->leave_notify = NULL;
}

static void
gv_tool_init(GvTool *tool)
{
    tool->view = NULL;
    tool->cursor = NULL;
    tool->bounded = 0;
}

void
gv_tool_activate(GvTool *tool, GvViewArea *view)
{
    gtk_signal_emit(GTK_OBJECT(tool), tool_signals[ACTIVATE], view);
}

void
gv_tool_deactivate(GvTool *tool, GvViewArea *view)
{
    gtk_signal_emit(GTK_OBJECT(tool), tool_signals[DEACTIVATE], view);
}

/**************************************************************/

static void
gv_tool_real_activate(GvTool *tool, GvViewArea *view)
{
    GvToolClass *klass;
    
    if (tool->view)
    {
	g_warning("gv_tool_activate(): tool %s is already active on a view",
		  gtk_type_name(GTK_OBJECT_TYPE(tool)));
	return;
    }

    tool->view = view;
    gtk_object_ref(GTK_OBJECT(view));
    klass = (GvToolClass*)gtk_type_class(GTK_OBJECT_TYPE(tool));

    /* This could be done through an indirect function call which
       emits a tool signal.  Probably better but more overhead... */

    if (klass->draw)
    {
	gtk_signal_connect_object(GTK_OBJECT(view), "gldraw",
				  GTK_SIGNAL_FUNC(klass->draw),
				  GTK_OBJECT(tool));	
    }
    if (klass->button_press)
    {
	gtk_signal_connect_object(GTK_OBJECT(view), "button-press-event",
				  GTK_SIGNAL_FUNC(klass->button_press),
				  GTK_OBJECT(tool));
    }
    if (klass->button_release)
    {
	gtk_signal_connect_object(GTK_OBJECT(view), "button-release-event",
				  GTK_SIGNAL_FUNC(klass->button_release),
				  GTK_OBJECT(tool));
    }
    if (klass->motion_notify)
    {
	gtk_signal_connect_object(GTK_OBJECT(view), "motion-notify-event",
				  GTK_SIGNAL_FUNC(klass->motion_notify),
				  GTK_OBJECT(tool));
    }
    if (klass->key_press)
    {
	gtk_signal_connect_object(GTK_OBJECT(view), "key-press-event",
				  GTK_SIGNAL_FUNC(klass->key_press),
				  GTK_OBJECT(tool));
    }
    if (klass->enter_notify)
    {
	gtk_signal_connect_object(GTK_OBJECT(view), "enter-notify-event",
				  GTK_SIGNAL_FUNC(klass->enter_notify),
				  GTK_OBJECT(tool));
    }
    if (klass->leave_notify)
    {
	gtk_signal_connect_object(GTK_OBJECT(view), "leave-notify-event",
				  GTK_SIGNAL_FUNC(klass->leave_notify),
				  GTK_OBJECT(tool));
    }

    /* Install cursor for this tool */
    if (GTK_WIDGET_REALIZED(GTK_WIDGET(view)))
    {
	gdk_window_set_cursor(GTK_WIDGET(view)->window, tool->cursor);
    }
}

static void
gv_tool_real_deactivate(GvTool *tool, GvViewArea *view)
{
    g_return_if_fail(tool->view == view);

    gtk_signal_disconnect_by_data(GTK_OBJECT(tool->view), (gpointer)tool);
    tool->view = NULL;
    gtk_object_unref(GTK_OBJECT(view));
}

GvViewArea *gv_tool_get_view(GvTool *tool)

{
    return tool->view;
}

gint
gv_tool_set_boundary(GvTool *tool, GvRect *rect)
{
    if( rect == NULL )
    {
        tool->bounded = FALSE;
        return TRUE;
    }

    /* check rect is valid */
    if (rect->width <= 0 || rect->height <= 0)
    {
        return FALSE;
    }

    tool->bounded = TRUE;
    tool->boundary = *rect;

    return TRUE;
}

void gv_tool_clamp_to_bounds( GvTool *tool, gvgeocoord *x, gvgeocoord *y )

{
    if( tool->bounded )
    {
        *x = MAX(MIN(*x,tool->boundary.x+tool->boundary.width),
                tool->boundary.x);
        *y = MAX(MIN(*y,tool->boundary.y+tool->boundary.height),
                tool->boundary.y);
    }
}

gint gv_tool_check_bounds( GvTool *tool, gvgeocoord x, gvgeocoord y )

{
    if( !tool->bounded )
        return TRUE;

    if( x < tool->boundary.x || x > tool->boundary.x + tool->boundary.width )
        return FALSE;

    if( y < tool->boundary.y || y > tool->boundary.y + tool->boundary.height )
        return FALSE;

    return TRUE;
}

void
gv_tool_set_cursor(GvTool *tool, gint cursor_type)
{
    if (tool->cursor != NULL)
        gdk_cursor_destroy(tool->cursor);

    tool->cursor = gdk_cursor_new(cursor_type);

    if ((tool->view != NULL) && (GTK_WIDGET_REALIZED(GTK_WIDGET(tool->view))))
    {
	gdk_window_set_cursor(GTK_WIDGET(tool->view)->window, tool->cursor);
    }

}
