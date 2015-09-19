/******************************************************************************
 * $Id: gtkmissing.c,v 1.8 2004/09/30 21:12:07 warmerda Exp $
 *
 * Project:  OpenEV
 * Purpose:  Hand generated python bindings for some Gtk functionality
 *           not addressed by pygtk.
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
 * $Log: gtkmissing.c,v $
 * Revision 1.8  2004/09/30 21:12:07  warmerda
 * added explicit ref() and unref() though we shouldn't generally need them
 *
 * Revision 1.7  2002/07/09 03:34:10  warmerda
 * added window get/set position calls
 *
 * Revision 1.6  2001/07/03 23:25:51  warmerda
 * added gtk_object_sink
 *
 * Revision 1.5  2000/06/23 13:00:41  warmerda
 * added a few ref count related debugging functions
 *
 * Revision 1.4  2000/06/20 13:39:06  warmerda
 * added standard headers
 *
 */

#if defined(WIN32) || defined(_WIN32)
#  include <pygtk.h>
#else
#  include <pygtk/pygtk.h>
#endif

/*
 * Functions missing in the python gtk bindings (as of pygtk-0.6.3)
 */

static PyObject *
_wrap_gtk_toolbar_append_element(PyObject *self, PyObject *args)
{
    PyGtk_Object *t;
    GtkWidget *widget = NULL, *icon = NULL;
    char *text, *tooltip, *tip_private;
    GtkWidget *ret;
    PyObject *callback, *py_widget, *py_icon, *extra = NULL, *data;
    int type;
    
    if (!PyArg_ParseTuple(args, "O!iOzzzOO|O!:gtk_toolbar_append_item",
			  &PyGtk_Type, &t, &type, &py_widget,
			  &text, &tooltip, &tip_private,
			  &py_icon, &callback, &PyTuple_Type, &extra))
	return NULL;
    if (!PyCallable_Check(callback) && callback != Py_None) {
	PyErr_SetString(PyExc_TypeError,"eighth argument not callable");
	return NULL;
    }
    Py_INCREF(callback);
    if (PyGtk_Check(py_widget))
	widget = GTK_WIDGET(PyGtk_Get(py_widget));
    else if (py_widget != Py_None)
    {
	PyErr_SetString(PyExc_TypeError, "arg 3 must be a widget or None");
	return NULL;
    }
    if (PyGtk_Check(py_icon))
	widget = GTK_WIDGET(PyGtk_Get(py_icon));
    else if (py_icon != Py_None)
    {
	PyErr_SetString(PyExc_TypeError, "arg 7 must be a widget or None");
	return NULL;
    }
    /* if you set sigfunc to NULL, no signal is connected, rather than
       the default signal handler being used */
    ret = gtk_toolbar_append_element(GTK_TOOLBAR(PyGtk_Get(t)), type,
				     widget, text, tooltip, tip_private,
				     icon, NULL, NULL);
    if (callback != Py_None) {
	if (extra)
	    Py_INCREF(extra);
	else
	    extra = PyTuple_New(0);
	data = Py_BuildValue("(OO)", callback, extra);
	gtk_signal_connect_full(GTK_OBJECT(ret), "clicked", NULL,
				PyGtk_CallbackMarshal, data,
				PyGtk_DestroyNotify, FALSE, FALSE);
    }
    return PyGtk_New((GtkObject *)ret);
}

static PyObject *
_wrap_gtk_object_deref_and_destroy(PyObject *self, PyObject *args)
{
    PyGtk_Object *t;
    GtkObject    *object;
    
    if (!PyArg_ParseTuple(args, "O!:gtk_object_deref_and_destroy",
			  &PyGtk_Type, &t))
	return NULL;

    object = GTK_OBJECT(PyGtk_Get(t));
    while( object->ref_count > 1 )
        gtk_object_unref(object);

    gtk_object_unref(object);

    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_object_unref(PyObject *self, PyObject *args)
{
    PyGtk_Object *t;
    GtkObject    *object;
    
    if (!PyArg_ParseTuple(args, "O!:gtk_object_unref",
			  &PyGtk_Type, &t))
	return NULL;

    object = GTK_OBJECT(PyGtk_Get(t));

    gtk_object_unref(object);

    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_object_ref(PyObject *self, PyObject *args)
{
    PyGtk_Object *t;
    GtkObject    *object;
    
    if (!PyArg_ParseTuple(args, "O!:gtk_object_ref",
			  &PyGtk_Type, &t))
	return NULL;

    object = GTK_OBJECT(PyGtk_Get(t));

    gtk_object_ref(object);

    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_object_get_ref_count(PyObject *self, PyObject *args)
{
    PyGtk_Object *t;
    GtkObject    *object;
    
    if (!PyArg_ParseTuple(args, "O!:gtk_object_get_ref_count",
			  &PyGtk_Type, &t))
	return NULL;

    object = GTK_OBJECT(PyGtk_Get(t));

    return Py_BuildValue("i", object->ref_count );
}

static PyObject *
_wrap_gtk_object_sink(PyObject *self, PyObject *args)
{
    PyGtk_Object *t;
    GtkObject    *object;
    
    if (!PyArg_ParseTuple(args, "O!:gtk_object_get_ref_count",
			  &PyGtk_Type, &t))
	return NULL;

    object = GTK_OBJECT(PyGtk_Get(t));
    gtk_object_sink( object );

    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_py_object_get_ref_count(PyObject *self, PyObject *args)
{
    PyGtk_Object *t;
    
    if (!PyArg_ParseTuple(args, "O:py_object_get_ref_count",
			  &t))
	return NULL;

    return Py_BuildValue("i", t->ob_refcnt );
}

static PyObject *
_wrap_gtk_window_move(PyObject *self, PyObject *args)
{
    PyGtk_Object *t;
    int x, y;
    GdkWindow *window;
    
    if (!PyArg_ParseTuple(args, "O!ii:gtk_window_move",
			  &PyGtk_Type, &t, &x, &y))
	return NULL;

    window = GTK_WIDGET(PyGtk_Get(t))->window;

    gdk_window_move( window, x, y );

    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_window_get_position(PyObject *self, PyObject *args)
{
    PyGtk_Object *t;
    int x, y;
    GdkWindow *window;
    
    if (!PyArg_ParseTuple(args, "O!:gtk_window_get_position",
			  &PyGtk_Type, &t))
	return NULL;

    window = GTK_WIDGET(PyGtk_Get(t))->window;

    gdk_window_get_position( window, &x, &y );

    return Py_BuildValue("(ii)", x, y );
}

static PyMethodDef gtkmissing_methods[] =
{
    {"gtk_toolbar_append_element", _wrap_gtk_toolbar_append_element, 1},
    {"gtk_object_deref_and_destroy", _wrap_gtk_object_deref_and_destroy, 1},
    {"gtk_object_unref", _wrap_gtk_object_unref, 1},
    {"gtk_object_ref", _wrap_gtk_object_ref, 1},
    {"gtk_object_get_ref_count", _wrap_gtk_object_get_ref_count, 1},
    {"gtk_object_sink", _wrap_gtk_object_sink, 1},
    {"py_object_get_ref_count", _wrap_py_object_get_ref_count, 1},
    {"gtk_window_move", _wrap_gtk_window_move, 1},
    {"gtk_window_get_position", _wrap_gtk_window_get_position, 1},
    {NULL, NULL, 0}
};

void
init_gtkmissing(void)
{
    init_pygtk();
    
    Py_InitModule("_gtkmissing", gtkmissing_methods);
    
    if (PyErr_Occurred())
	Py_FatalError("can't initialize module _gtkmissing");
}
