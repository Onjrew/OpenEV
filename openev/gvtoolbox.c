/******************************************************************************
 * $Id: gvtoolbox.c,v 1.8 2000/08/03 18:39:49 warmerda Exp $
 *
 * Project:  OpenEV
 * Purpose:  Container for available editing tools, manages which is active.
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
 * $Log: gvtoolbox.c,v $
 * Revision 1.8  2000/08/03 18:39:49  warmerda
 * activate a tool on key-press, or button-press but not focus-enter
 *
 * Revision 1.7  2000/07/27 20:06:23  warmerda
 * added boundary constraints
 *
 * Revision 1.6  2000/06/20 13:26:55  warmerda
 * added standard headers
 *
 */

#include "gvtoolbox.h"
#include <gtk/gtksignal.h>

static void gv_toolbox_class_init(GvToolboxClass *klass);
static void gv_toolbox_init(GvToolbox *toolbox);
static void gv_toolbox_activate(GvTool *toolbox, GvViewArea *view);
static void gv_toolbox_deactivate(GvTool *toolbox, GvViewArea *view);
static void gv_toolbox_view_event(GvViewArea *view, GdkEvent *event, GvToolbox *toolbox);
static void gv_toolbox_switch_to_view(GvToolbox *toolbox, GvViewArea *view);
static void gv_toolbox_destroy(GtkObject *object);
static void gv_toolbox_finalize(GtkObject *object);

GtkType
gv_toolbox_get_type(void)
{
    static GtkType toolbox_type = 0;

    if (!toolbox_type)
    {
	static const GtkTypeInfo toolbox_info =
	{
	    "GvToolbox",
	    sizeof(GvToolbox),
	    sizeof(GvToolboxClass),
	    (GtkClassInitFunc) gv_toolbox_class_init,
	    (GtkObjectInitFunc) gv_toolbox_init,
	    /* reserved_1 */ NULL,
	    /* reserved_2 */ NULL,
	    (GtkClassInitFunc) NULL,
	};

	toolbox_type = gtk_type_unique(gv_tool_get_type(),
				       &toolbox_info);
    }
    return toolbox_type;
}

static void
gv_toolbox_class_init(GvToolboxClass *klass)
{
    GtkObjectClass *object_class;
    GvToolClass *tool_class;

    object_class = (GtkObjectClass*)klass;    
    tool_class = (GvToolClass*)klass;

    object_class->destroy = gv_toolbox_destroy;
    object_class->finalize = gv_toolbox_finalize;
    
    tool_class->activate = gv_toolbox_activate;
    tool_class->deactivate = gv_toolbox_deactivate;
}

static void
gv_toolbox_init(GvToolbox *toolbox)
{
    toolbox->tools = g_hash_table_new(g_str_hash, g_str_equal);
    toolbox->active_tool = NULL;
    toolbox->views = NULL;
}

GvTool *
gv_toolbox_new(void)
{
    return GV_TOOL(gtk_type_new(GV_TYPE_TOOLBOX));
}

void
gv_toolbox_add_tool(GvToolbox *toolbox, gchar *name, GvTool *tool)
{
    if (g_hash_table_lookup(toolbox->tools, name))
    {
	g_warning("gv_toolbox_add_tool(): tool %s already exists", name);
	return;
    }

    gtk_object_ref(GTK_OBJECT(tool));
    gtk_object_sink(GTK_OBJECT(tool));
    g_hash_table_insert(toolbox->tools, g_strdup(name), (gpointer)tool);

    if( GV_TOOL(toolbox)->bounded ) 
        gv_tool_set_boundary( tool, &(GV_TOOL(toolbox)->boundary) );
}

void
gv_toolbox_activate_tool(GvToolbox *toolbox, gchar *tool_name)
{
    GvTool *tool;

    if (tool_name)
    {
	tool = (GvTool*)g_hash_table_lookup(toolbox->tools, tool_name);
	if (!tool)
	{
	    g_warning("gv_toolbox_activate_tool(): no tool %s in toolbox",
		      tool_name);
	    return;
	}
    }
    else
    {
	tool = NULL;
    }

    /* Check if tool is already active */
    if (tool == toolbox->active_tool) return;

    /* Deactivate currently active tool */
    if (toolbox->active_tool && GV_TOOL(toolbox)->view)
    {
	gv_tool_deactivate(toolbox->active_tool, GV_TOOL(toolbox)->view);
    }

    /* Activate new tool */
    toolbox->active_tool = tool;
    if (toolbox->active_tool && GV_TOOL(toolbox)->view)
    {
	gv_tool_activate(toolbox->active_tool, GV_TOOL(toolbox)->view);
    }
}

/*******************************************************/

static void
gv_toolbox_activate(GvTool *tool, GvViewArea *view)
{
    GvToolbox *toolbox = GV_TOOLBOX( tool );

    if (!g_list_find(toolbox->views, view))
    {
        gtk_object_ref(GTK_OBJECT(view));
        toolbox->views = g_list_append(toolbox->views, (gpointer)view);

        gtk_signal_connect(GTK_OBJECT(view), "button-press-event",
                           GTK_SIGNAL_FUNC(gv_toolbox_view_event),
                           (gpointer)toolbox);
        gtk_signal_connect(GTK_OBJECT(view), "key-press-event",
                           GTK_SIGNAL_FUNC(gv_toolbox_view_event),
                           (gpointer)toolbox);
    }

    gv_toolbox_switch_to_view( toolbox, view );
}

static void
gv_toolbox_deactivate(GvTool *tool, GvViewArea *view)
{
    GvToolbox *toolbox = GV_TOOLBOX( tool );

    if (!g_list_find(toolbox->views, view))
    {
	g_warning("gv_toolbox_activate(): view not active");
	return;
    }

    if (view == GV_TOOL(toolbox)->view)
    {
	if (toolbox->active_tool)
	{
	    gv_tool_deactivate(toolbox->active_tool, view);
	}
	GV_TOOL(toolbox)->view = NULL;
    }

    gtk_signal_disconnect_by_data(GTK_OBJECT(view), (gpointer)toolbox);
    toolbox->views = g_list_remove(toolbox->views, view);
    gtk_object_unref(GTK_OBJECT(view));    
}

static void
gv_toolbox_view_event(GvViewArea *view, GdkEvent *event, GvToolbox *toolbox)
{
    /* Check whether this view is the active view */
    if (view != GV_TOOL(toolbox)->view)
    {
        gv_tool_activate( GV_TOOL(toolbox), view );
    }
}

static void
gv_toolbox_switch_to_view(GvToolbox *toolbox, GvViewArea *view)
{
    /* Deactivate the active tool */
    if (toolbox->active_tool && GV_TOOL(toolbox)->view)
    {
	gv_tool_deactivate(toolbox->active_tool, GV_TOOL(toolbox)->view);
    }

    /* Switch views */
    GV_TOOL(toolbox)->view = view;

    /* Reactivate the active tool */
    if (toolbox->active_tool && view)
    {
	gv_tool_activate(toolbox->active_tool, view);
    }
}

static gboolean
unref_object_foreach(gpointer key, gpointer value, gpointer data)
{
    gtk_object_unref((GtkObject*)value);
    return TRUE;
}

static void
gv_toolbox_destroy(GtkObject *object)
{
    GvToolClass *parent_class;
    GvToolbox *toolbox;    

    toolbox = GV_TOOLBOX(object);

    /* Remove all views */
    while (toolbox->views)
    {
	GvViewArea *view = (GvViewArea*)toolbox->views->data;
	gv_tool_deactivate(GV_TOOL(toolbox), view);
    }

    /* Remove all tools */
    g_hash_table_foreach_remove(toolbox->tools, unref_object_foreach, NULL);

    /* Call parent class function */
    parent_class = gtk_type_class(gv_tool_get_type());
    GTK_OBJECT_CLASS(parent_class)->destroy(object);         
}

static void
gv_toolbox_finalize(GtkObject *object)
{
    GvToolClass *parent_class;
    GvToolbox *toolbox;    

    toolbox = GV_TOOLBOX(object);

    g_hash_table_destroy(toolbox->tools);
    
    /* Call parent class function */
    parent_class = gtk_type_class(gv_tool_get_type());
    GTK_OBJECT_CLASS(parent_class)->finalize(object);         
}
