static PyObject *_wrap_gdk_draw_point(PyObject *self, PyObject *args) {
    int x, y;
    PyObject *drawable, *gc;

    if (!PyArg_ParseTuple(args, "O!O!ii:gdk_draw_point", &PyGdkWindow_Type, &drawable, &PyGdkGC_Type, &gc, &x, &y))
        return NULL;
    gdk_draw_point(PyGdkWindow_Get(drawable), PyGdkGC_Get(gc), x, y);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gdk_draw_line(PyObject *self, PyObject *args) {
    int x1, y1, x2, y2;
    PyObject *drawable, *gc;

    if (!PyArg_ParseTuple(args, "O!O!iiii:gdk_draw_line", &PyGdkWindow_Type, &drawable, &PyGdkGC_Type, &gc, &x1, &y1, &x2, &y2))
        return NULL;
    gdk_draw_line(PyGdkWindow_Get(drawable), PyGdkGC_Get(gc), x1, y1, x2, y2);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gdk_draw_rectangle(PyObject *self, PyObject *args) {
    int filled, x, y, width, height;
    PyObject *drawable, *gc;

    if (!PyArg_ParseTuple(args, "O!O!iiiii:gdk_draw_rectangle", &PyGdkWindow_Type, &drawable, &PyGdkGC_Type, &gc, &filled, &x, &y, &width, &height))
        return NULL;
    gdk_draw_rectangle(PyGdkWindow_Get(drawable), PyGdkGC_Get(gc), filled, x, y, width, height);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gdk_draw_arc(PyObject *self, PyObject *args) {
    int filled, x, y, width, height, angle1, angle2;
    PyObject *drawable, *gc;

    if (!PyArg_ParseTuple(args, "O!O!iiiiiii:gdk_draw_arc", &PyGdkWindow_Type, &drawable, &PyGdkGC_Type, &gc, &filled, &x, &y, &width, &height, &angle1, &angle2))
        return NULL;
    gdk_draw_arc(PyGdkWindow_Get(drawable), PyGdkGC_Get(gc), filled, x, y, width, height, angle1, angle2);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gdk_draw_string(PyObject *self, PyObject *args) {
    int x, y;
    char *str;
    PyObject *drawable, *font, *gc;

    if (!PyArg_ParseTuple(args, "O!O!O!iis:gdk_draw_string", &PyGdkWindow_Type, &drawable, &PyGdkFont_Type, &font, &PyGdkGC_Type, &gc, &x, &y, &str))
        return NULL;
    gdk_draw_string(PyGdkWindow_Get(drawable), PyGdkFont_Get(font), PyGdkGC_Get(gc), x, y, str);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gdk_draw_pixmap(PyObject *self, PyObject *args) {
    int xsrc, ysrc, xdest, ydest, width, height;
    PyObject *drawable, *gc, *src;

    if (!PyArg_ParseTuple(args, "O!O!O!iiiiii:gdk_draw_pixmap", &PyGdkWindow_Type, &drawable, &PyGdkGC_Type, &gc, &PyGdkWindow_Type, &src, &xsrc, &ysrc, &xdest, &ydest, &width, &height))
        return NULL;
    gdk_draw_pixmap(PyGdkWindow_Get(drawable), PyGdkGC_Get(gc), PyGdkWindow_Get(src), xsrc, ysrc, xdest, ydest, width, height);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gdk_cursor_new(PyObject *self, PyObject *args) {
    GdkCursorType cursor_type;
    PyObject *py_cursor_type;

    if (!PyArg_ParseTuple(args, "O:gdk_cursor_new", &py_cursor_type))
        return NULL;
    if (PyGtkEnum_get_value(GTK_TYPE_GDK_CURSOR_TYPE, py_cursor_type, (gint *)&cursor_type))
        return NULL;
    return PyGdkCursor_New(gdk_cursor_new(cursor_type));
}

static PyObject *_wrap_gdk_cursor_new_from_pixmap(PyObject *self, PyObject *args) {
    int x, y;
    PyObject *source, *mask, *fg, *bg;

    if (!PyArg_ParseTuple(args, "O!O!O!O!ii:gdk_cursor_new_from_pixmap", &PyGdkWindow_Type, &source, &PyGdkWindow_Type, &mask, &PyGdkColor_Type, &fg, &PyGdkColor_Type, &bg, &x, &y))
        return NULL;
    return PyGdkCursor_New(gdk_cursor_new_from_pixmap(PyGdkWindow_Get(source), PyGdkWindow_Get(mask), PyGdkColor_Get(fg), PyGdkColor_Get(bg), x, y));
}

static PyObject *_wrap_gdk_screen_width(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gdk_screen_width"))
        return NULL;
    return PyInt_FromLong(gdk_screen_width());
}

static PyObject *_wrap_gdk_screen_height(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gdk_screen_height"))
        return NULL;
    return PyInt_FromLong(gdk_screen_height());
}

static PyObject *_wrap_gdk_screen_width_mm(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gdk_screen_width_mm"))
        return NULL;
    return PyInt_FromLong(gdk_screen_width_mm());
}

static PyObject *_wrap_gdk_screen_height_mm(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gdk_screen_height_mm"))
        return NULL;
    return PyInt_FromLong(gdk_screen_height_mm());
}

static PyObject *_wrap_gtk_object_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_object_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_object_get_type());
}

static PyObject *_wrap_gtk_widget_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_widget_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_widget_get_type());
}

static PyObject *_wrap_gtk_type_from_name(PyObject *self, PyObject *args) {
    char *name;

    if (!PyArg_ParseTuple(args, "s:gtk_type_from_name", &name))
        return NULL;
    return PyInt_FromLong(gtk_type_from_name(name));
}

static PyObject *_wrap_gtk_type_name(PyObject *self, PyObject *args) {
    int type;

    if (!PyArg_ParseTuple(args, "i:gtk_type_name", &type))
        return NULL;
    return PyString_FromString(gtk_type_name(type));
}

static PyObject *_wrap_gtk_exit(PyObject *self, PyObject *args) {
    int code = 0;

    if (!PyArg_ParseTuple(args, "|i:gtk_exit", &code))
        return NULL;
    gtk_exit(code);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_main_quit(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_main_quit"))
        return NULL;
    gtk_main_quit();
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_set_locale(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_set_locale"))
        return NULL;
    return PyString_FromString(gtk_set_locale());
}

static PyObject *_wrap_gtk_quit_add_destroy(PyObject *self, PyObject *args) {
    PyObject *object;
    int main_level;

    if (!PyArg_ParseTuple(args, "iO!:gtk_quit_add_destroy", &main_level, &PyGtk_Type, &object))
        return NULL;
    gtk_quit_add_destroy(main_level, GTK_OBJECT(PyGtk_Get(object)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_quit_remove(PyObject *self, PyObject *args) {
    int quit_id;

    if (!PyArg_ParseTuple(args, "i:gtk_quit_remove", &quit_id))
        return NULL;
    gtk_quit_remove(quit_id);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_timeout_remove(PyObject *self, PyObject *args) {
    int tag;

    if (!PyArg_ParseTuple(args, "i:gtk_timeout_remove", &tag))
        return NULL;
    gtk_timeout_remove(tag);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_idle_remove(PyObject *self, PyObject *args) {
    int tag;

    if (!PyArg_ParseTuple(args, "i:gtk_idle_remove", &tag))
        return NULL;
    gtk_idle_remove(tag);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_input_remove(PyObject *self, PyObject *args) {
    int tag;

    if (!PyArg_ParseTuple(args, "i:gtk_input_remove", &tag))
        return NULL;
    gtk_input_remove(tag);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_rc_parse(PyObject *self, PyObject *args) {
    char *file;

    if (!PyArg_ParseTuple(args, "s:gtk_rc_parse", &file))
        return NULL;
    gtk_rc_parse(file);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_rc_parse_string(PyObject *self, PyObject *args) {
    char *rc_string;

    if (!PyArg_ParseTuple(args, "s:gtk_rc_parse_string", &rc_string))
        return NULL;
    gtk_rc_parse_string(rc_string);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_rc_reparse_all(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_rc_reparse_all"))
        return NULL;
    gtk_rc_reparse_all();
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_rc_get_style(PyObject *self, PyObject *args) {
    PyObject *widget;

    if (!PyArg_ParseTuple(args, "O!:gtk_rc_get_style", &PyGtk_Type, &widget))
        return NULL;
    return PyGtkStyle_New(gtk_rc_get_style(GTK_WIDGET(PyGtk_Get(widget))));
}

static PyObject *_wrap_gtk_accel_group_new(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_accel_group_new"))
        return NULL;
    return PyGtkAccelGroup_New(gtk_accel_group_new());
}

static PyObject *_wrap_gtk_accel_group_get_default(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_accel_group_get_default"))
        return NULL;
    return PyGtkAccelGroup_New(gtk_accel_group_get_default());
}

static PyObject *_wrap_gtk_accel_group_activate(PyObject *self, PyObject *args) {
    PyObject *group, *py_modifiers;
    GdkModifierType modifiers;
    int key;

    if (!PyArg_ParseTuple(args, "O!iO:gtk_accel_group_activate", &PyGtkAccelGroup_Type, &group, &key, &py_modifiers))
        return NULL;
    if (PyGtkFlag_get_value(GTK_TYPE_GDK_MODIFIER_TYPE, py_modifiers, (gint *)&modifiers))
        return NULL;
    return PyInt_FromLong(gtk_accel_group_activate(PyGtkAccelGroup_Get(group), key, modifiers));
}

static PyObject *_wrap_gtk_accel_groups_activate(PyObject *self, PyObject *args) {
    PyObject *object, *py_modifiers;
    GdkModifierType modifiers;
    int key;

    if (!PyArg_ParseTuple(args, "O!iO:gtk_accel_groups_activate", &PyGtk_Type, &object, &key, &py_modifiers))
        return NULL;
    if (PyGtkFlag_get_value(GTK_TYPE_GDK_MODIFIER_TYPE, py_modifiers, (gint *)&modifiers))
        return NULL;
    return PyInt_FromLong(gtk_accel_groups_activate(GTK_OBJECT(PyGtk_Get(object)), key, modifiers));
}

static PyObject *_wrap_gtk_accel_group_attach(PyObject *self, PyObject *args) {
    PyObject *group, *object;

    if (!PyArg_ParseTuple(args, "O!O!:gtk_accel_group_attach", &PyGtkAccelGroup_Type, &group, &PyGtk_Type, &object))
        return NULL;
    gtk_accel_group_attach(PyGtkAccelGroup_Get(group), GTK_OBJECT(PyGtk_Get(object)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_accel_group_detach(PyObject *self, PyObject *args) {
    PyObject *group, *object;

    if (!PyArg_ParseTuple(args, "O!O!:gtk_accel_group_detach", &PyGtkAccelGroup_Type, &group, &PyGtk_Type, &object))
        return NULL;
    gtk_accel_group_detach(PyGtkAccelGroup_Get(group), GTK_OBJECT(PyGtk_Get(object)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_accel_group_lock(PyObject *self, PyObject *args) {
    PyObject *group;

    if (!PyArg_ParseTuple(args, "O!:gtk_accel_group_lock", &PyGtkAccelGroup_Type, &group))
        return NULL;
    gtk_accel_group_lock(PyGtkAccelGroup_Get(group));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_accel_group_unlock(PyObject *self, PyObject *args) {
    PyObject *group;

    if (!PyArg_ParseTuple(args, "O!:gtk_accel_group_unlock", &PyGtkAccelGroup_Type, &group))
        return NULL;
    gtk_accel_group_unlock(PyGtkAccelGroup_Get(group));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_accel_group_lock_entry(PyObject *self, PyObject *args) {
    PyObject *group, *py_modifiers;
    GdkModifierType modifiers;
    int key;

    if (!PyArg_ParseTuple(args, "O!iO:gtk_accel_group_lock_entry", &PyGtkAccelGroup_Type, &group, &key, &py_modifiers))
        return NULL;
    if (PyGtkFlag_get_value(GTK_TYPE_GDK_MODIFIER_TYPE, py_modifiers, (gint *)&modifiers))
        return NULL;
    gtk_accel_group_lock_entry(PyGtkAccelGroup_Get(group), key, modifiers);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_accel_group_unlock_entry(PyObject *self, PyObject *args) {
    PyObject *group, *py_modifiers;
    GdkModifierType modifiers;
    int key;

    if (!PyArg_ParseTuple(args, "O!iO:gtk_accel_group_unlock_entry", &PyGtkAccelGroup_Type, &group, &key, &py_modifiers))
        return NULL;
    if (PyGtkFlag_get_value(GTK_TYPE_GDK_MODIFIER_TYPE, py_modifiers, (gint *)&modifiers))
        return NULL;
    gtk_accel_group_unlock_entry(PyGtkAccelGroup_Get(group), key, modifiers);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_accel_group_add(PyObject *self, PyObject *args) {
    PyObject *group, *py_modifiers, *py_flags, *object;
    char *signal;
    GdkModifierType modifiers;
    GtkAccelFlags flags;
    int key;

    if (!PyArg_ParseTuple(args, "O!iOOO!s:gtk_accel_group_add", &PyGtkAccelGroup_Type, &group, &key, &py_modifiers, &py_flags, &PyGtk_Type, &object, &signal))
        return NULL;
    if (PyGtkFlag_get_value(GTK_TYPE_GDK_MODIFIER_TYPE, py_modifiers, (gint *)&modifiers))
        return NULL;
    if (PyGtkFlag_get_value(GTK_TYPE_ACCEL_FLAGS, py_flags, (gint *)&flags))
        return NULL;
    gtk_accel_group_add(PyGtkAccelGroup_Get(group), key, modifiers, flags, GTK_OBJECT(PyGtk_Get(object)), signal);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_accel_group_remove(PyObject *self, PyObject *args) {
    PyObject *group, *py_modifiers, *object;
    GdkModifierType modifiers;
    int key;

    if (!PyArg_ParseTuple(args, "O!iOO!:gtk_accel_group_remove", &PyGtkAccelGroup_Type, &group, &key, &py_modifiers, &PyGtk_Type, &object))
        return NULL;
    if (PyGtkFlag_get_value(GTK_TYPE_GDK_MODIFIER_TYPE, py_modifiers, (gint *)&modifiers))
        return NULL;
    gtk_accel_group_remove(PyGtkAccelGroup_Get(group), key, modifiers, GTK_OBJECT(PyGtk_Get(object)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_GTK_OBJECT_FLAGS(PyObject *self, PyObject *args) {
    PyObject *object;

    if (!PyArg_ParseTuple(args, "O!:GTK_OBJECT_FLAGS", &PyGtk_Type, &object))
        return NULL;
    return PyInt_FromLong(GTK_OBJECT_FLAGS(GTK_OBJECT(PyGtk_Get(object))));
}

static PyObject *_wrap_GTK_OBJECT_SET_FLAGS(PyObject *self, PyObject *args) {
    GtkWidgetFlags flags;
    PyObject *object, *py_flags;

    if (!PyArg_ParseTuple(args, "O!O:GTK_OBJECT_SET_FLAGS", &PyGtk_Type, &object, &py_flags))
        return NULL;
    if (PyGtkFlag_get_value(GTK_TYPE_WIDGET_FLAGS, py_flags, (gint *)&flags))
        return NULL;
    GTK_OBJECT_SET_FLAGS(GTK_OBJECT(PyGtk_Get(object)), flags);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_GTK_OBJECT_UNSET_FLAGS(PyObject *self, PyObject *args) {
    GtkWidgetFlags flags;
    PyObject *object, *py_flags;

    if (!PyArg_ParseTuple(args, "O!O:GTK_OBJECT_UNSET_FLAGS", &PyGtk_Type, &object, &py_flags))
        return NULL;
    if (PyGtkFlag_get_value(GTK_TYPE_WIDGET_FLAGS, py_flags, (gint *)&flags))
        return NULL;
    GTK_OBJECT_UNSET_FLAGS(GTK_OBJECT(PyGtk_Get(object)), flags);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_GTK_OBJECT_TYPE(PyObject *self, PyObject *args) {
    PyObject *object;

    if (!PyArg_ParseTuple(args, "O!:GTK_OBJECT_TYPE", &PyGtk_Type, &object))
        return NULL;
    return PyInt_FromLong(GTK_OBJECT_TYPE(GTK_OBJECT(PyGtk_Get(object))));
}

static PyObject *_wrap_gtk_object_destroy(PyObject *self, PyObject *args) {
    PyObject *object;

    if (!PyArg_ParseTuple(args, "O!:gtk_object_destroy", &PyGtk_Type, &object))
        return NULL;
    gtk_object_destroy(GTK_OBJECT(PyGtk_Get(object)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_GTK_CHECK_TYPE(PyObject *self, PyObject *args) {
    int type;
    PyObject *object;

    if (!PyArg_ParseTuple(args, "O!i:GTK_CHECK_TYPE", &PyGtk_Type, &object, &type))
        return NULL;
    return PyInt_FromLong(GTK_CHECK_TYPE(GTK_OBJECT(PyGtk_Get(object)), type));
}

static PyObject *_wrap_gtk_signal_disconnect(PyObject *self, PyObject *args) {
    int handler_id;
    PyObject *object;

    if (!PyArg_ParseTuple(args, "O!i:gtk_signal_disconnect", &PyGtk_Type, &object, &handler_id))
        return NULL;
    gtk_signal_disconnect(GTK_OBJECT(PyGtk_Get(object)), handler_id);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_signal_emit_stop_by_name(PyObject *self, PyObject *args) {
    char *name;
    PyObject *object;

    if (!PyArg_ParseTuple(args, "O!s:gtk_signal_emit_stop_by_name", &PyGtk_Type, &object, &name))
        return NULL;
    gtk_signal_emit_stop_by_name(GTK_OBJECT(PyGtk_Get(object)), name);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_signal_handler_block(PyObject *self, PyObject *args) {
    int id;
    PyObject *object;

    if (!PyArg_ParseTuple(args, "O!i:gtk_signal_handler_block", &PyGtk_Type, &object, &id))
        return NULL;
    gtk_signal_handler_block(GTK_OBJECT(PyGtk_Get(object)), id);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_signal_handler_unblock(PyObject *self, PyObject *args) {
    int id;
    PyObject *object;

    if (!PyArg_ParseTuple(args, "O!i:gtk_signal_handler_unblock", &PyGtk_Type, &object, &id))
        return NULL;
    gtk_signal_handler_unblock(GTK_OBJECT(PyGtk_Get(object)), id);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_signal_handlers_destroy(PyObject *self, PyObject *args) {
    PyObject *object;

    if (!PyArg_ParseTuple(args, "O!:gtk_signal_handlers_destroy", &PyGtk_Type, &object))
        return NULL;
    gtk_signal_handlers_destroy(GTK_OBJECT(PyGtk_Get(object)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_data_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_data_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_data_get_type());
}

static PyObject *_wrap_gtk_adjustment_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_adjustment_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_adjustment_get_type());
}

static PyObject *_wrap_gtk_adjustment_get_value(PyObject *self, PyObject *args) {
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_adjustment_get_value", &PyGtk_Type, &obj))
        return NULL;
    return PyFloat_FromDouble(GTK_ADJUSTMENT(PyGtk_Get(obj))->value);
}

static PyObject *_wrap_gtk_adjustment_get_lower(PyObject *self, PyObject *args) {
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_adjustment_get_lower", &PyGtk_Type, &obj))
        return NULL;
    return PyFloat_FromDouble(GTK_ADJUSTMENT(PyGtk_Get(obj))->lower);
}

static PyObject *_wrap_gtk_adjustment_get_upper(PyObject *self, PyObject *args) {
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_adjustment_get_upper", &PyGtk_Type, &obj))
        return NULL;
    return PyFloat_FromDouble(GTK_ADJUSTMENT(PyGtk_Get(obj))->upper);
}

static PyObject *_wrap_gtk_adjustment_get_step_increment(PyObject *self, PyObject *args) {
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_adjustment_get_step_increment", &PyGtk_Type, &obj))
        return NULL;
    return PyFloat_FromDouble(GTK_ADJUSTMENT(PyGtk_Get(obj))->step_increment);
}

static PyObject *_wrap_gtk_adjustment_get_page_increment(PyObject *self, PyObject *args) {
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_adjustment_get_page_increment", &PyGtk_Type, &obj))
        return NULL;
    return PyFloat_FromDouble(GTK_ADJUSTMENT(PyGtk_Get(obj))->page_increment);
}

static PyObject *_wrap_gtk_adjustment_get_page_size(PyObject *self, PyObject *args) {
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_adjustment_get_page_size", &PyGtk_Type, &obj))
        return NULL;
    return PyFloat_FromDouble(GTK_ADJUSTMENT(PyGtk_Get(obj))->page_size);
}

static PyObject *_wrap_gtk_adjustment_new(PyObject *self, PyObject *args) {
    double value, lower, upper, step_increment, page_increment, page_size;

    if (!PyArg_ParseTuple(args, "dddddd:gtk_adjustment_new", &value, &lower, &upper, &step_increment, &page_increment, &page_size))
        return NULL;
    return PyGtk_New((GtkObject *)gtk_adjustment_new(value, lower, upper, step_increment, page_increment, page_size));
}

static PyObject *_wrap_gtk_adjustment_changed(PyObject *self, PyObject *args) {
    PyObject *adjustment;

    if (!PyArg_ParseTuple(args, "O!:gtk_adjustment_changed", &PyGtk_Type, &adjustment))
        return NULL;
    gtk_adjustment_changed(GTK_ADJUSTMENT(PyGtk_Get(adjustment)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_adjustment_value_changed(PyObject *self, PyObject *args) {
    PyObject *adjustment;

    if (!PyArg_ParseTuple(args, "O!:gtk_adjustment_value_changed", &PyGtk_Type, &adjustment))
        return NULL;
    gtk_adjustment_value_changed(GTK_ADJUSTMENT(PyGtk_Get(adjustment)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_adjustment_clamp_page(PyObject *self, PyObject *args) {
    double lower, upper;
    PyObject *adjustment;

    if (!PyArg_ParseTuple(args, "O!dd:gtk_adjustment_clamp_page", &PyGtk_Type, &adjustment, &lower, &upper))
        return NULL;
    gtk_adjustment_clamp_page(GTK_ADJUSTMENT(PyGtk_Get(adjustment)), lower, upper);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_adjustment_set_value(PyObject *self, PyObject *args) {
    double value;
    PyObject *adjustment;

    if (!PyArg_ParseTuple(args, "O!d:gtk_adjustment_set_value", &PyGtk_Type, &adjustment, &value))
        return NULL;
    gtk_adjustment_set_value(GTK_ADJUSTMENT(PyGtk_Get(adjustment)), value);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_widget_destroy(PyObject *self, PyObject *args) {
    PyObject *widget;

    if (!PyArg_ParseTuple(args, "O!:gtk_widget_destroy", &PyGtk_Type, &widget))
        return NULL;
    gtk_widget_destroy(GTK_WIDGET(PyGtk_Get(widget)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_widget_unparent(PyObject *self, PyObject *args) {
    PyObject *widget;

    if (!PyArg_ParseTuple(args, "O!:gtk_widget_unparent", &PyGtk_Type, &widget))
        return NULL;
    gtk_widget_unparent(GTK_WIDGET(PyGtk_Get(widget)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_widget_show(PyObject *self, PyObject *args) {
    PyObject *widget;

    if (!PyArg_ParseTuple(args, "O!:gtk_widget_show", &PyGtk_Type, &widget))
        return NULL;
    gtk_widget_show(GTK_WIDGET(PyGtk_Get(widget)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_widget_show_now(PyObject *self, PyObject *args) {
    PyObject *widget;

    if (!PyArg_ParseTuple(args, "O!:gtk_widget_show_now", &PyGtk_Type, &widget))
        return NULL;
    gtk_widget_show_now(GTK_WIDGET(PyGtk_Get(widget)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_widget_hide(PyObject *self, PyObject *args) {
    PyObject *widget;

    if (!PyArg_ParseTuple(args, "O!:gtk_widget_hide", &PyGtk_Type, &widget))
        return NULL;
    gtk_widget_hide(GTK_WIDGET(PyGtk_Get(widget)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_widget_show_all(PyObject *self, PyObject *args) {
    PyObject *widget;

    if (!PyArg_ParseTuple(args, "O!:gtk_widget_show_all", &PyGtk_Type, &widget))
        return NULL;
    gtk_widget_show_all(GTK_WIDGET(PyGtk_Get(widget)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_widget_hide_all(PyObject *self, PyObject *args) {
    PyObject *widget;

    if (!PyArg_ParseTuple(args, "O!:gtk_widget_hide_all", &PyGtk_Type, &widget))
        return NULL;
    gtk_widget_hide_all(GTK_WIDGET(PyGtk_Get(widget)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_widget_map(PyObject *self, PyObject *args) {
    PyObject *widget;

    if (!PyArg_ParseTuple(args, "O!:gtk_widget_map", &PyGtk_Type, &widget))
        return NULL;
    gtk_widget_map(GTK_WIDGET(PyGtk_Get(widget)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_widget_unmap(PyObject *self, PyObject *args) {
    PyObject *widget;

    if (!PyArg_ParseTuple(args, "O!:gtk_widget_unmap", &PyGtk_Type, &widget))
        return NULL;
    gtk_widget_unmap(GTK_WIDGET(PyGtk_Get(widget)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_widget_realize(PyObject *self, PyObject *args) {
    PyObject *widget;

    if (!PyArg_ParseTuple(args, "O!:gtk_widget_realize", &PyGtk_Type, &widget))
        return NULL;
    gtk_widget_realize(GTK_WIDGET(PyGtk_Get(widget)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_widget_unrealize(PyObject *self, PyObject *args) {
    PyObject *widget;

    if (!PyArg_ParseTuple(args, "O!:gtk_widget_unrealize", &PyGtk_Type, &widget))
        return NULL;
    gtk_widget_unrealize(GTK_WIDGET(PyGtk_Get(widget)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_widget_queue_draw(PyObject *self, PyObject *args) {
    PyObject *widget;

    if (!PyArg_ParseTuple(args, "O!:gtk_widget_queue_draw", &PyGtk_Type, &widget))
        return NULL;
    gtk_widget_queue_draw(GTK_WIDGET(PyGtk_Get(widget)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_widget_queue_resize(PyObject *self, PyObject *args) {
    PyObject *widget;

    if (!PyArg_ParseTuple(args, "O!:gtk_widget_queue_resize", &PyGtk_Type, &widget))
        return NULL;
    gtk_widget_queue_resize(GTK_WIDGET(PyGtk_Get(widget)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_widget_draw_focus(PyObject *self, PyObject *args) {
    PyObject *widget;

    if (!PyArg_ParseTuple(args, "O!:gtk_widget_draw_focus", &PyGtk_Type, &widget))
        return NULL;
    gtk_widget_draw_focus(GTK_WIDGET(PyGtk_Get(widget)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_widget_draw_default(PyObject *self, PyObject *args) {
    PyObject *widget;

    if (!PyArg_ParseTuple(args, "O!:gtk_widget_draw_default", &PyGtk_Type, &widget))
        return NULL;
    gtk_widget_draw_default(GTK_WIDGET(PyGtk_Get(widget)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_widget_add_accelerator(PyObject *self, PyObject *args) {
    PyObject *widget, *group, *py_modifiers, *py_flags;
    char *signal_name;
    GdkModifierType modifiers;
    GtkAccelFlags flags;
    int key;

    if (!PyArg_ParseTuple(args, "O!sO!iOO:gtk_widget_add_accelerator", &PyGtk_Type, &widget, &signal_name, &PyGtkAccelGroup_Type, &group, &key, &py_modifiers, &py_flags))
        return NULL;
    if (PyGtkFlag_get_value(GTK_TYPE_GDK_MODIFIER_TYPE, py_modifiers, (gint *)&modifiers))
        return NULL;
    if (PyGtkFlag_get_value(GTK_TYPE_ACCEL_FLAGS, py_flags, (gint *)&flags))
        return NULL;
    gtk_widget_add_accelerator(GTK_WIDGET(PyGtk_Get(widget)), signal_name, PyGtkAccelGroup_Get(group), key, modifiers, flags);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_widget_remove_accelerator(PyObject *self, PyObject *args) {
    PyObject *widget, *group, *py_modifiers;
    GdkModifierType modifiers;
    int key;

    if (!PyArg_ParseTuple(args, "O!O!iO:gtk_widget_remove_accelerator", &PyGtk_Type, &widget, &PyGtkAccelGroup_Type, &group, &key, &py_modifiers))
        return NULL;
    if (PyGtkFlag_get_value(GTK_TYPE_GDK_MODIFIER_TYPE, py_modifiers, (gint *)&modifiers))
        return NULL;
    gtk_widget_remove_accelerator(GTK_WIDGET(PyGtk_Get(widget)), PyGtkAccelGroup_Get(group), key, modifiers);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_widget_remove_accelerators(PyObject *self, PyObject *args) {
    int visible_only;
    char *signal_name;
    PyObject *widget;

    if (!PyArg_ParseTuple(args, "O!si:gtk_widget_remove_accelerators", &PyGtk_Type, &widget, &signal_name, &visible_only))
        return NULL;
    gtk_widget_remove_accelerators(GTK_WIDGET(PyGtk_Get(widget)), signal_name, visible_only);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_widget_accelerator_signal(PyObject *self, PyObject *args) {
    PyObject *widget, *group, *py_modifiers;
    GdkModifierType modifiers;
    int key;

    if (!PyArg_ParseTuple(args, "O!O!iO:gtk_widget_accelerator_signal", &PyGtk_Type, &widget, &PyGtkAccelGroup_Type, &group, &key, &py_modifiers))
        return NULL;
    if (PyGtkFlag_get_value(GTK_TYPE_GDK_MODIFIER_TYPE, py_modifiers, (gint *)&modifiers))
        return NULL;
    return PyInt_FromLong(gtk_widget_accelerator_signal(GTK_WIDGET(PyGtk_Get(widget)), PyGtkAccelGroup_Get(group), key, modifiers));
}

static PyObject *_wrap_gtk_widget_lock_accelerators(PyObject *self, PyObject *args) {
    PyObject *widget;

    if (!PyArg_ParseTuple(args, "O!:gtk_widget_lock_accelerators", &PyGtk_Type, &widget))
        return NULL;
    gtk_widget_lock_accelerators(GTK_WIDGET(PyGtk_Get(widget)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_widget_unlock_accelerators(PyObject *self, PyObject *args) {
    PyObject *widget;

    if (!PyArg_ParseTuple(args, "O!:gtk_widget_unlock_accelerators", &PyGtk_Type, &widget))
        return NULL;
    gtk_widget_unlock_accelerators(GTK_WIDGET(PyGtk_Get(widget)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_widget_accelerators_locked(PyObject *self, PyObject *args) {
    PyObject *widget;

    if (!PyArg_ParseTuple(args, "O!:gtk_widget_accelerators_locked", &PyGtk_Type, &widget))
        return NULL;
    return PyInt_FromLong(gtk_widget_accelerators_locked(GTK_WIDGET(PyGtk_Get(widget))));
}

static PyObject *_wrap_gtk_widget_event(PyObject *self, PyObject *args) {
    PyObject *widget, *event;

    if (!PyArg_ParseTuple(args, "O!O!:gtk_widget_event", &PyGtk_Type, &widget, &PyGdkEvent_Type, &event))
        return NULL;
    return PyInt_FromLong(gtk_widget_event(GTK_WIDGET(PyGtk_Get(widget)), PyGdkEvent_Get(event)));
}

static PyObject *_wrap_gtk_widget_activate(PyObject *self, PyObject *args) {
    PyObject *widget;

    if (!PyArg_ParseTuple(args, "O!:gtk_widget_activate", &PyGtk_Type, &widget))
        return NULL;
    return PyInt_FromLong(gtk_widget_activate(GTK_WIDGET(PyGtk_Get(widget))));
}

static PyObject *_wrap_gtk_widget_set_scroll_adjustments(PyObject *self, PyObject *args) {
    PyObject *widget, *hadjustment, *vadjustment;

    if (!PyArg_ParseTuple(args, "O!O!O!:gtk_widget_set_scroll_adjustments", &PyGtk_Type, &widget, &PyGtk_Type, &hadjustment, &PyGtk_Type, &vadjustment))
        return NULL;
    return PyInt_FromLong(gtk_widget_set_scroll_adjustments(GTK_WIDGET(PyGtk_Get(widget)), GTK_ADJUSTMENT(PyGtk_Get(hadjustment)), GTK_ADJUSTMENT(PyGtk_Get(vadjustment))));
}

static PyObject *_wrap_gtk_widget_reparent(PyObject *self, PyObject *args) {
    PyObject *widget, *new_parent;

    if (!PyArg_ParseTuple(args, "O!O!:gtk_widget_reparent", &PyGtk_Type, &widget, &PyGtk_Type, &new_parent))
        return NULL;
    gtk_widget_reparent(GTK_WIDGET(PyGtk_Get(widget)), GTK_WIDGET(PyGtk_Get(new_parent)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_widget_popup(PyObject *self, PyObject *args) {
    int x, y;
    PyObject *widget;

    if (!PyArg_ParseTuple(args, "O!ii:gtk_widget_popup", &PyGtk_Type, &widget, &x, &y))
        return NULL;
    gtk_widget_popup(GTK_WIDGET(PyGtk_Get(widget)), x, y);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_widget_grab_focus(PyObject *self, PyObject *args) {
    PyObject *widget;

    if (!PyArg_ParseTuple(args, "O!:gtk_widget_grab_focus", &PyGtk_Type, &widget))
        return NULL;
    gtk_widget_grab_focus(GTK_WIDGET(PyGtk_Get(widget)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_widget_grab_default(PyObject *self, PyObject *args) {
    PyObject *widget;

    if (!PyArg_ParseTuple(args, "O!:gtk_widget_grab_default", &PyGtk_Type, &widget))
        return NULL;
    gtk_widget_grab_default(GTK_WIDGET(PyGtk_Get(widget)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_widget_set_name(PyObject *self, PyObject *args) {
    char *name;
    PyObject *widget;

    if (!PyArg_ParseTuple(args, "O!s:gtk_widget_set_name", &PyGtk_Type, &widget, &name))
        return NULL;
    gtk_widget_set_name(GTK_WIDGET(PyGtk_Get(widget)), name);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_widget_get_name(PyObject *self, PyObject *args) {
    PyObject *widget;

    if (!PyArg_ParseTuple(args, "O!:gtk_widget_get_name", &PyGtk_Type, &widget))
        return NULL;
    return PyString_FromString(gtk_widget_get_name(GTK_WIDGET(PyGtk_Get(widget))));
}

static PyObject *_wrap_gtk_widget_set_state(PyObject *self, PyObject *args) {
    GtkStateType state;
    PyObject *widget, *py_state;

    if (!PyArg_ParseTuple(args, "O!O:gtk_widget_set_state", &PyGtk_Type, &widget, &py_state))
        return NULL;
    if (PyGtkEnum_get_value(GTK_TYPE_STATE_TYPE, py_state, (gint *)&state))
        return NULL;
    gtk_widget_set_state(GTK_WIDGET(PyGtk_Get(widget)), state);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_widget_set_sensitive(PyObject *self, PyObject *args) {
    int sensitive;
    PyObject *widget;

    if (!PyArg_ParseTuple(args, "O!i:gtk_widget_set_sensitive", &PyGtk_Type, &widget, &sensitive))
        return NULL;
    gtk_widget_set_sensitive(GTK_WIDGET(PyGtk_Get(widget)), sensitive);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_widget_set_app_paintable(PyObject *self, PyObject *args) {
    int app_paintable;
    PyObject *widget;

    if (!PyArg_ParseTuple(args, "O!i:gtk_widget_set_app_paintable", &PyGtk_Type, &widget, &app_paintable))
        return NULL;
    gtk_widget_set_app_paintable(GTK_WIDGET(PyGtk_Get(widget)), app_paintable);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_widget_set_parent(PyObject *self, PyObject *args) {
    PyObject *widget, *parent;

    if (!PyArg_ParseTuple(args, "O!O!:gtk_widget_set_parent", &PyGtk_Type, &widget, &PyGtk_Type, &parent))
        return NULL;
    gtk_widget_set_parent(GTK_WIDGET(PyGtk_Get(widget)), GTK_WIDGET(PyGtk_Get(parent)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_widget_set_parent_window(PyObject *self, PyObject *args) {
    PyObject *widget, *parent_window;

    if (!PyArg_ParseTuple(args, "O!O!:gtk_widget_set_parent_window", &PyGtk_Type, &widget, &PyGdkWindow_Type, &parent_window))
        return NULL;
    gtk_widget_set_parent_window(GTK_WIDGET(PyGtk_Get(widget)), PyGdkWindow_Get(parent_window));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_widget_get_parent_window(PyObject *self, PyObject *args) {
    PyObject *widget;

    if (!PyArg_ParseTuple(args, "O!:gtk_widget_get_parent_window", &PyGtk_Type, &widget))
        return NULL;
    return PyGdkWindow_New(gtk_widget_get_parent_window(GTK_WIDGET(PyGtk_Get(widget))));
}

static PyObject *_wrap_gtk_widget_set_uposition(PyObject *self, PyObject *args) {
    int x, y;
    PyObject *widget;

    if (!PyArg_ParseTuple(args, "O!ii:gtk_widget_set_uposition", &PyGtk_Type, &widget, &x, &y))
        return NULL;
    gtk_widget_set_uposition(GTK_WIDGET(PyGtk_Get(widget)), x, y);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_widget_set_usize(PyObject *self, PyObject *args) {
    int height, width;
    PyObject *widget;

    if (!PyArg_ParseTuple(args, "O!ii:gtk_widget_set_usize", &PyGtk_Type, &widget, &height, &width))
        return NULL;
    gtk_widget_set_usize(GTK_WIDGET(PyGtk_Get(widget)), height, width);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_widget_set_events(PyObject *self, PyObject *args) {
    GdkEventMask events;
    PyObject *widget, *py_events;

    if (!PyArg_ParseTuple(args, "O!O:gtk_widget_set_events", &PyGtk_Type, &widget, &py_events))
        return NULL;
    if (PyGtkFlag_get_value(GTK_TYPE_GDK_EVENT_MASK, py_events, (gint *)&events))
        return NULL;
    gtk_widget_set_events(GTK_WIDGET(PyGtk_Get(widget)), events);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_widget_add_events(PyObject *self, PyObject *args) {
    GdkEventMask events;
    PyObject *widget, *py_events;

    if (!PyArg_ParseTuple(args, "O!O:gtk_widget_add_events", &PyGtk_Type, &widget, &py_events))
        return NULL;
    if (PyGtkFlag_get_value(GTK_TYPE_GDK_EVENT_MASK, py_events, (gint *)&events))
        return NULL;
    gtk_widget_add_events(GTK_WIDGET(PyGtk_Get(widget)), events);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_widget_set_extension_events(PyObject *self, PyObject *args) {
    GdkEventMask events;
    PyObject *widget, *py_events;

    if (!PyArg_ParseTuple(args, "O!O:gtk_widget_set_extension_events", &PyGtk_Type, &widget, &py_events))
        return NULL;
    if (PyGtkFlag_get_value(GTK_TYPE_GDK_EVENT_MASK, py_events, (gint *)&events))
        return NULL;
    gtk_widget_set_extension_events(GTK_WIDGET(PyGtk_Get(widget)), events);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_widget_get_extension_events(PyObject *self, PyObject *args) {
    PyObject *widget;

    if (!PyArg_ParseTuple(args, "O!:gtk_widget_get_extension_events", &PyGtk_Type, &widget))
        return NULL;
    return PyInt_FromLong(gtk_widget_get_extension_events(GTK_WIDGET(PyGtk_Get(widget))));
}

static PyObject *_wrap_gtk_widget_get_toplevel(PyObject *self, PyObject *args) {
    PyObject *widget;

    if (!PyArg_ParseTuple(args, "O!:gtk_widget_get_toplevel", &PyGtk_Type, &widget))
        return NULL;
    return PyGtk_New((GtkObject *)gtk_widget_get_toplevel(GTK_WIDGET(PyGtk_Get(widget))));
}

static PyObject *_wrap_gtk_widget_get_ancestor(PyObject *self, PyObject *args) {
    int type;
    PyObject *widget;

    if (!PyArg_ParseTuple(args, "O!i:gtk_widget_get_ancestor", &PyGtk_Type, &widget, &type))
        return NULL;
    return PyGtk_New((GtkObject *)gtk_widget_get_ancestor(GTK_WIDGET(PyGtk_Get(widget)), type));
}

static PyObject *_wrap_gtk_widget_get_colormap(PyObject *self, PyObject *args) {
    PyObject *widget;

    if (!PyArg_ParseTuple(args, "O!:gtk_widget_get_colormap", &PyGtk_Type, &widget))
        return NULL;
    return PyGdkColormap_New(gtk_widget_get_colormap(GTK_WIDGET(PyGtk_Get(widget))));
}

static PyObject *_wrap_gtk_widget_get_events(PyObject *self, PyObject *args) {
    PyObject *widget;

    if (!PyArg_ParseTuple(args, "O!:gtk_widget_get_events", &PyGtk_Type, &widget))
        return NULL;
    return PyInt_FromLong(gtk_widget_get_events(GTK_WIDGET(PyGtk_Get(widget))));
}

static PyObject *_wrap_gtk_widget_is_ancestor(PyObject *self, PyObject *args) {
    PyObject *widget, *ancestor;

    if (!PyArg_ParseTuple(args, "O!O!:gtk_widget_is_ancestor", &PyGtk_Type, &widget, &PyGtk_Type, &ancestor))
        return NULL;
    return PyInt_FromLong(gtk_widget_is_ancestor(GTK_WIDGET(PyGtk_Get(widget)), GTK_WIDGET(PyGtk_Get(ancestor))));
}

static PyObject *_wrap_gtk_widget_hide_on_delete(PyObject *self, PyObject *args) {
    PyObject *widget;

    if (!PyArg_ParseTuple(args, "O!:gtk_widget_hide_on_delete", &PyGtk_Type, &widget))
        return NULL;
    return PyInt_FromLong(gtk_widget_hide_on_delete(GTK_WIDGET(PyGtk_Get(widget))));
}

static PyObject *_wrap_gtk_widget_set_style(PyObject *self, PyObject *args) {
    PyObject *widget, *style;

    if (!PyArg_ParseTuple(args, "O!O!:gtk_widget_set_style", &PyGtk_Type, &widget, &PyGtkStyle_Type, &style))
        return NULL;
    gtk_widget_set_style(GTK_WIDGET(PyGtk_Get(widget)), PyGtkStyle_Get(style));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_widget_set_rc_style(PyObject *self, PyObject *args) {
    PyObject *widget;

    if (!PyArg_ParseTuple(args, "O!:gtk_widget_set_rc_style", &PyGtk_Type, &widget))
        return NULL;
    gtk_widget_set_rc_style(GTK_WIDGET(PyGtk_Get(widget)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_widget_ensure_style(PyObject *self, PyObject *args) {
    PyObject *widget;

    if (!PyArg_ParseTuple(args, "O!:gtk_widget_ensure_style", &PyGtk_Type, &widget))
        return NULL;
    gtk_widget_ensure_style(GTK_WIDGET(PyGtk_Get(widget)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_widget_get_style(PyObject *self, PyObject *args) {
    PyObject *widget;

    if (!PyArg_ParseTuple(args, "O!:gtk_widget_get_style", &PyGtk_Type, &widget))
        return NULL;
    return PyGtkStyle_New(gtk_widget_get_style(GTK_WIDGET(PyGtk_Get(widget))));
}

static PyObject *_wrap_gtk_widget_restore_default_style(PyObject *self, PyObject *args) {
    PyObject *widget;

    if (!PyArg_ParseTuple(args, "O!:gtk_widget_restore_default_style", &PyGtk_Type, &widget))
        return NULL;
    gtk_widget_restore_default_style(GTK_WIDGET(PyGtk_Get(widget)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_widget_set_composite_name(PyObject *self, PyObject *args) {
    char *name;
    PyObject *widget;

    if (!PyArg_ParseTuple(args, "O!s:gtk_widget_set_composite_name", &PyGtk_Type, &widget, &name))
        return NULL;
    gtk_widget_set_composite_name(GTK_WIDGET(PyGtk_Get(widget)), name);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_widget_get_composite_name(PyObject *self, PyObject *args) {
    PyObject *py_ret, *widget;
    char *ret;

    if (!PyArg_ParseTuple(args, "O!:gtk_widget_get_composite_name", &PyGtk_Type, &widget))
        return NULL;
    ret = gtk_widget_get_composite_name(GTK_WIDGET(PyGtk_Get(widget)));
    py_ret = PyString_FromString(ret);
    g_free(ret);
    return py_ret;
}

static PyObject *_wrap_gtk_widget_reset_rc_styles(PyObject *self, PyObject *args) {
    PyObject *widget;

    if (!PyArg_ParseTuple(args, "O!:gtk_widget_reset_rc_styles", &PyGtk_Type, &widget))
        return NULL;
    gtk_widget_reset_rc_styles(GTK_WIDGET(PyGtk_Get(widget)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_widget_push_style(PyObject *self, PyObject *args) {
    PyObject *style;

    if (!PyArg_ParseTuple(args, "O!:gtk_widget_push_style", &PyGtkStyle_Type, &style))
        return NULL;
    gtk_widget_push_style(PyGtkStyle_Get(style));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_widget_push_colormap(PyObject *self, PyObject *args) {
    PyObject *cmap;

    if (!PyArg_ParseTuple(args, "O!:gtk_widget_push_colormap", &PyGdkColormap_Type, &cmap))
        return NULL;
    gtk_widget_push_colormap(PyGdkColormap_Get(cmap));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_widget_pop_style(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_widget_pop_style"))
        return NULL;
    gtk_widget_pop_style();
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_widget_pop_colormap(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_widget_pop_colormap"))
        return NULL;
    gtk_widget_pop_colormap();
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_widget_set_default_style(PyObject *self, PyObject *args) {
    PyObject *style;

    if (!PyArg_ParseTuple(args, "O!:gtk_widget_set_default_style", &PyGtkStyle_Type, &style))
        return NULL;
    gtk_widget_set_default_style(PyGtkStyle_Get(style));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_widget_set_default_colormap(PyObject *self, PyObject *args) {
    PyObject *cmap;

    if (!PyArg_ParseTuple(args, "O!:gtk_widget_set_default_colormap", &PyGdkColormap_Type, &cmap))
        return NULL;
    gtk_widget_set_default_colormap(PyGdkColormap_Get(cmap));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_widget_get_default_style(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_widget_get_default_style"))
        return NULL;
    return PyGtkStyle_New(gtk_widget_get_default_style());
}

static PyObject *_wrap_gtk_widget_get_default_colormap(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_widget_get_default_colormap"))
        return NULL;
    return PyGdkColormap_New(gtk_widget_get_default_colormap());
}

static PyObject *_wrap_gtk_widget_shape_combine_mask(PyObject *self, PyObject *args) {
    int ofs_x, ofs_y;
    PyObject *widget, *mask;

    if (!PyArg_ParseTuple(args, "O!O!ii:gtk_widget_shape_combine_mask", &PyGtk_Type, &widget, &PyGdkWindow_Type, &mask, &ofs_x, &ofs_y))
        return NULL;
    gtk_widget_shape_combine_mask(GTK_WIDGET(PyGtk_Get(widget)), PyGdkWindow_Get(mask), ofs_x, ofs_y);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_grab_add(PyObject *self, PyObject *args) {
    PyObject *widget;

    if (!PyArg_ParseTuple(args, "O!:gtk_grab_add", &PyGtk_Type, &widget))
        return NULL;
    gtk_grab_add(GTK_WIDGET(PyGtk_Get(widget)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_grab_get_current(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_grab_get_current"))
        return NULL;
    return PyGtk_New((GtkObject *)gtk_grab_get_current());
}

static PyObject *_wrap_gtk_grab_remove(PyObject *self, PyObject *args) {
    PyObject *widget;

    if (!PyArg_ParseTuple(args, "O!:gtk_grab_remove", &PyGtk_Type, &widget))
        return NULL;
    gtk_grab_remove(GTK_WIDGET(PyGtk_Get(widget)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_drag_get_data(PyObject *self, PyObject *args) {
    int target, time;
    PyObject *widget, *context;

    if (!PyArg_ParseTuple(args, "O!O!ii:gtk_drag_get_data", &PyGtk_Type, &widget, &PyGdkDragContext_Type, &context, &target, &time))
        return NULL;
    gtk_drag_get_data(GTK_WIDGET(PyGtk_Get(widget)), PyGdkDragContext_Get(context), target, time);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_drag_finish(PyObject *self, PyObject *args) {
    int success, del, time;
    PyObject *context;

    if (!PyArg_ParseTuple(args, "O!iii:gtk_drag_finish", &PyGdkDragContext_Type, &context, &success, &del, &time))
        return NULL;
    gtk_drag_finish(PyGdkDragContext_Get(context), success, del, time);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_drag_get_source_widget(PyObject *self, PyObject *args) {
    PyObject *context;

    if (!PyArg_ParseTuple(args, "O!:gtk_drag_get_source_widget", &PyGdkDragContext_Type, &context))
        return NULL;
    return PyGtk_New((GtkObject *)gtk_drag_get_source_widget(PyGdkDragContext_Get(context)));
}

static PyObject *_wrap_gtk_drag_highlight(PyObject *self, PyObject *args) {
    PyObject *widget;

    if (!PyArg_ParseTuple(args, "O!:gtk_drag_highlight", &PyGtk_Type, &widget))
        return NULL;
    gtk_drag_highlight(GTK_WIDGET(PyGtk_Get(widget)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_drag_unhighlight(PyObject *self, PyObject *args) {
    PyObject *widget;

    if (!PyArg_ParseTuple(args, "O!:gtk_drag_unhighlight", &PyGtk_Type, &widget))
        return NULL;
    gtk_drag_unhighlight(GTK_WIDGET(PyGtk_Get(widget)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_drag_dest_set_proxy(PyObject *self, PyObject *args) {
    int use_coordinates;
    GdkDragProtocol protocol;
    PyObject *widget, *proxy_window, *py_protocol;

    if (!PyArg_ParseTuple(args, "O!O!Oi:gtk_drag_dest_set_proxy", &PyGtk_Type, &widget, &PyGdkWindow_Type, &proxy_window, &py_protocol, &use_coordinates))
        return NULL;
    if (PyGtkEnum_get_value(GTK_TYPE_GDK_DRAG_PROTOCOL, py_protocol, (gint *)&protocol))
        return NULL;
    gtk_drag_dest_set_proxy(GTK_WIDGET(PyGtk_Get(widget)), PyGdkWindow_Get(proxy_window), protocol, use_coordinates);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_drag_dest_unset(PyObject *self, PyObject *args) {
    PyObject *widget;

    if (!PyArg_ParseTuple(args, "O!:gtk_drag_dest_unset", &PyGtk_Type, &widget))
        return NULL;
    gtk_drag_dest_unset(GTK_WIDGET(PyGtk_Get(widget)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_drag_source_unset(PyObject *self, PyObject *args) {
    PyObject *widget;

    if (!PyArg_ParseTuple(args, "O!:gtk_drag_source_unset", &PyGtk_Type, &widget))
        return NULL;
    gtk_drag_source_unset(GTK_WIDGET(PyGtk_Get(widget)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_drag_source_set_icon(PyObject *self, PyObject *args) {
    PyObject *widget, *colormap, *pixmap, *mask;

    if (!PyArg_ParseTuple(args, "O!O!O!O!:gtk_drag_source_set_icon", &PyGtk_Type, &widget, &PyGdkColormap_Type, &colormap, &PyGdkWindow_Type, &pixmap, &PyGdkWindow_Type, &mask))
        return NULL;
    gtk_drag_source_set_icon(GTK_WIDGET(PyGtk_Get(widget)), PyGdkColormap_Get(colormap), PyGdkWindow_Get(pixmap), PyGdkWindow_Get(mask));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_drag_set_icon_widget(PyObject *self, PyObject *args) {
    int hot_x, hot_y;
    PyObject *context, *widget;

    if (!PyArg_ParseTuple(args, "O!O!ii:gtk_drag_set_icon_widget", &PyGdkDragContext_Type, &context, &PyGtk_Type, &widget, &hot_x, &hot_y))
        return NULL;
    gtk_drag_set_icon_widget(PyGdkDragContext_Get(context), GTK_WIDGET(PyGtk_Get(widget)), hot_x, hot_y);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_drag_set_icon_pixmap(PyObject *self, PyObject *args) {
    int hot_x, hot_y;
    PyObject *context, *colormap, *pixmap, *mask;

    if (!PyArg_ParseTuple(args, "O!O!O!O!ii:gtk_drag_set_icon_pixmap", &PyGdkDragContext_Type, &context, &PyGdkColormap_Type, &colormap, &PyGdkWindow_Type, &pixmap, &PyGdkWindow_Type, &mask, &hot_x, &hot_y))
        return NULL;
    gtk_drag_set_icon_pixmap(PyGdkDragContext_Get(context), PyGdkColormap_Get(colormap), PyGdkWindow_Get(pixmap), PyGdkWindow_Get(mask), hot_x, hot_y);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_drag_set_icon_default(PyObject *self, PyObject *args) {
    PyObject *context;

    if (!PyArg_ParseTuple(args, "O!:gtk_drag_set_icon_default", &PyGdkDragContext_Type, &context))
        return NULL;
    gtk_drag_set_icon_default(PyGdkDragContext_Get(context));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_drag_set_default_icon(PyObject *self, PyObject *args) {
    int hot_x, hot_y;
    PyObject *colormap, *pixmap, *mask;

    if (!PyArg_ParseTuple(args, "O!O!O!ii:gtk_drag_set_default_icon", &PyGdkColormap_Type, &colormap, &PyGdkWindow_Type, &pixmap, &PyGdkWindow_Type, &mask, &hot_x, &hot_y))
        return NULL;
    gtk_drag_set_default_icon(PyGdkColormap_Get(colormap), PyGdkWindow_Get(pixmap), PyGdkWindow_Get(mask), hot_x, hot_y);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gdk_drag_status(PyObject *self, PyObject *args) {
    int time;
    GdkDragAction action;
    PyObject *context, *py_action;

    if (!PyArg_ParseTuple(args, "O!Oi:gdk_drag_status", &PyGdkDragContext_Type, &context, &py_action, &time))
        return NULL;
    if (PyGtkFlag_get_value(GTK_TYPE_GDK_DRAG_ACTION, py_action, (gint *)&action))
        return NULL;
    gdk_drag_status(PyGdkDragContext_Get(context), action, time);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gdk_atom_intern(PyObject *self, PyObject *args) {
    int only_if_exists = FALSE;
    char *atom_name;

    if (!PyArg_ParseTuple(args, "s|i:gdk_atom_intern", &atom_name, &only_if_exists))
        return NULL;
    return PyGdkAtom_New(gdk_atom_intern(atom_name, only_if_exists));
}

static PyObject *_wrap_gdk_atom_name(PyObject *self, PyObject *args) {
    PyObject *py_ret;
    int atom;
    char *ret;

    if (!PyArg_ParseTuple(args, "i:gdk_atom_name", &atom))
        return NULL;
    ret = gdk_atom_name(atom);
    py_ret = PyString_FromString(ret);
    g_free(ret);
    return py_ret;
}

static PyObject *_wrap_gtk_selection_owner_set(PyObject *self, PyObject *args) {
    int selection, time;
    PyObject *widget;

    if (!PyArg_ParseTuple(args, "O!ii:gtk_selection_owner_set", &PyGtk_Type, &widget, &selection, &time))
        return NULL;
    return PyInt_FromLong(gtk_selection_owner_set(GTK_WIDGET(PyGtk_Get(widget)), selection, time));
}

static PyObject *_wrap_gtk_selection_add_target(PyObject *self, PyObject *args) {
    int selection, target, info;
    PyObject *widget;

    if (!PyArg_ParseTuple(args, "O!iii:gtk_selection_add_target", &PyGtk_Type, &widget, &selection, &target, &info))
        return NULL;
    gtk_selection_add_target(GTK_WIDGET(PyGtk_Get(widget)), selection, target, info);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_selection_convert(PyObject *self, PyObject *args) {
    int selection, target, time;
    PyObject *widget;

    if (!PyArg_ParseTuple(args, "O!iii:gtk_selection_convert", &PyGtk_Type, &widget, &selection, &target, &time))
        return NULL;
    return PyInt_FromLong(gtk_selection_convert(GTK_WIDGET(PyGtk_Get(widget)), selection, target, time));
}

static PyObject *_wrap_gtk_selection_remove_all(PyObject *self, PyObject *args) {
    PyObject *widget;

    if (!PyArg_ParseTuple(args, "O!:gtk_selection_remove_all", &PyGtk_Type, &widget))
        return NULL;
    gtk_selection_remove_all(GTK_WIDGET(PyGtk_Get(widget)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_tooltips_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_tooltips_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_tooltips_get_type());
}

static PyObject *_wrap_gtk_tooltips_new(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_tooltips_new"))
        return NULL;
    return PyGtk_New((GtkObject *)gtk_tooltips_new());
}

static PyObject *_wrap_gtk_tooltips_enable(PyObject *self, PyObject *args) {
    PyObject *tooltips;

    if (!PyArg_ParseTuple(args, "O!:gtk_tooltips_enable", &PyGtk_Type, &tooltips))
        return NULL;
    gtk_tooltips_enable(GTK_TOOLTIPS(PyGtk_Get(tooltips)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_tooltips_disable(PyObject *self, PyObject *args) {
    PyObject *tooltips;

    if (!PyArg_ParseTuple(args, "O!:gtk_tooltips_disable", &PyGtk_Type, &tooltips))
        return NULL;
    gtk_tooltips_disable(GTK_TOOLTIPS(PyGtk_Get(tooltips)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_tooltips_set_delay(PyObject *self, PyObject *args) {
    int delay;
    PyObject *tooltips;

    if (!PyArg_ParseTuple(args, "O!i:gtk_tooltips_set_delay", &PyGtk_Type, &tooltips, &delay))
        return NULL;
    gtk_tooltips_set_delay(GTK_TOOLTIPS(PyGtk_Get(tooltips)), delay);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_tooltips_set_tip(PyObject *self, PyObject *args) {
    char *tip_text, *tip_private;
    PyObject *tooltips, *widget;

    if (!PyArg_ParseTuple(args, "O!O!zz:gtk_tooltips_set_tip", &PyGtk_Type, &tooltips, &PyGtk_Type, &widget, &tip_text, &tip_private))
        return NULL;
    gtk_tooltips_set_tip(GTK_TOOLTIPS(PyGtk_Get(tooltips)), GTK_WIDGET(PyGtk_Get(widget)), tip_text, tip_private);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_tooltips_set_colors(PyObject *self, PyObject *args) {
    PyObject *tooltips, *background, *foreground;

    if (!PyArg_ParseTuple(args, "O!O!O!:gtk_tooltips_set_colors", &PyGtk_Type, &tooltips, &PyGdkColor_Type, &background, &PyGdkColor_Type, &foreground))
        return NULL;
    gtk_tooltips_set_colors(GTK_TOOLTIPS(PyGtk_Get(tooltips)), PyGdkColor_Get(background), PyGdkColor_Get(foreground));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_tooltips_force_window(PyObject *self, PyObject *args) {
    PyObject *tooltips;

    if (!PyArg_ParseTuple(args, "O!:gtk_tooltips_force_window", &PyGtk_Type, &tooltips))
        return NULL;
    gtk_tooltips_force_window(GTK_TOOLTIPS(PyGtk_Get(tooltips)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_container_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_container_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_container_get_type());
}

static PyObject *_wrap_gtk_container_set_border_width(PyObject *self, PyObject *args) {
    int border_width;
    PyObject *container;

    if (!PyArg_ParseTuple(args, "O!i:gtk_container_set_border_width", &PyGtk_Type, &container, &border_width))
        return NULL;
    gtk_container_set_border_width(GTK_CONTAINER(PyGtk_Get(container)), border_width);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_container_remove(PyObject *self, PyObject *args) {
    PyObject *container, *widget;

    if (!PyArg_ParseTuple(args, "O!O!:gtk_container_remove", &PyGtk_Type, &container, &PyGtk_Type, &widget))
        return NULL;
    gtk_container_remove(GTK_CONTAINER(PyGtk_Get(container)), GTK_WIDGET(PyGtk_Get(widget)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_container_set_resize_mode(PyObject *self, PyObject *args) {
    GtkResizeMode resize_mode;
    PyObject *container, *py_resize_mode;

    if (!PyArg_ParseTuple(args, "O!O:gtk_container_set_resize_mode", &PyGtk_Type, &container, &py_resize_mode))
        return NULL;
    if (PyGtkEnum_get_value(GTK_TYPE_RESIZE_MODE, py_resize_mode, (gint *)&resize_mode))
        return NULL;
    gtk_container_set_resize_mode(GTK_CONTAINER(PyGtk_Get(container)), resize_mode);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_container_check_resize(PyObject *self, PyObject *args) {
    PyObject *container;

    if (!PyArg_ParseTuple(args, "O!:gtk_container_check_resize", &PyGtk_Type, &container))
        return NULL;
    gtk_container_check_resize(GTK_CONTAINER(PyGtk_Get(container)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_container_child_composite_name(PyObject *self, PyObject *args) {
    PyObject *py_ret, *container, *child;
    char *ret;

    if (!PyArg_ParseTuple(args, "O!O!:gtk_container_child_composite_name", &PyGtk_Type, &container, &PyGtk_Type, &child))
        return NULL;
    ret = gtk_container_child_composite_name(GTK_CONTAINER(PyGtk_Get(container)), GTK_WIDGET(PyGtk_Get(child)));
    py_ret = PyString_FromString(ret);
    g_free(ret);
    return py_ret;
}

static PyObject *_wrap_gtk_container_focus(PyObject *self, PyObject *args) {
    GtkDirectionType direction;
    PyObject *container, *py_direction;

    if (!PyArg_ParseTuple(args, "O!O:gtk_container_focus", &PyGtk_Type, &container, &py_direction))
        return NULL;
    if (PyGtkEnum_get_value(GTK_TYPE_DIRECTION_TYPE, py_direction, (gint *)&direction))
        return NULL;
    return PyInt_FromLong(gtk_container_focus(GTK_CONTAINER(PyGtk_Get(container)), direction));
}

static PyObject *_wrap_gtk_container_set_focus_child(PyObject *self, PyObject *args) {
    GtkWidget *child = NULL;
    PyObject *container, *py_child = Py_None;

    if (!PyArg_ParseTuple(args, "O!O:gtk_container_set_focus_child", &PyGtk_Type, &container, &py_child))
        return NULL;
    if (PyGtk_Check(py_child))
        child = GTK_WIDGET(PyGtk_Get(py_child));
    else if (py_child != Py_None) {
        PyErr_SetString(PyExc_TypeError, "child argument must be a GtkWidget or None");
	return NULL;
    }
    gtk_container_set_focus_child(GTK_CONTAINER(PyGtk_Get(container)), child);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_container_set_focus_vadjustment(PyObject *self, PyObject *args) {
    PyObject *container, *adjustment;

    if (!PyArg_ParseTuple(args, "O!O!:gtk_container_set_focus_vadjustment", &PyGtk_Type, &container, &PyGtk_Type, &adjustment))
        return NULL;
    gtk_container_set_focus_vadjustment(GTK_CONTAINER(PyGtk_Get(container)), GTK_ADJUSTMENT(PyGtk_Get(adjustment)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_container_set_focus_hadjustment(PyObject *self, PyObject *args) {
    PyObject *container, *adjustment;

    if (!PyArg_ParseTuple(args, "O!O!:gtk_container_set_focus_hadjustment", &PyGtk_Type, &container, &PyGtk_Type, &adjustment))
        return NULL;
    gtk_container_set_focus_hadjustment(GTK_CONTAINER(PyGtk_Get(container)), GTK_ADJUSTMENT(PyGtk_Get(adjustment)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_container_register_toplevel(PyObject *self, PyObject *args) {
    PyObject *container;

    if (!PyArg_ParseTuple(args, "O!:gtk_container_register_toplevel", &PyGtk_Type, &container))
        return NULL;
    gtk_container_register_toplevel(GTK_CONTAINER(PyGtk_Get(container)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_container_unregister_toplevel(PyObject *self, PyObject *args) {
    PyObject *container;

    if (!PyArg_ParseTuple(args, "O!:gtk_container_unregister_toplevel", &PyGtk_Type, &container))
        return NULL;
    gtk_container_unregister_toplevel(GTK_CONTAINER(PyGtk_Get(container)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_container_resize_children(PyObject *self, PyObject *args) {
    PyObject *container;

    if (!PyArg_ParseTuple(args, "O!:gtk_container_resize_children", &PyGtk_Type, &container))
        return NULL;
    gtk_container_resize_children(GTK_CONTAINER(PyGtk_Get(container)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_container_child_type(PyObject *self, PyObject *args) {
    PyObject *container;

    if (!PyArg_ParseTuple(args, "O!:gtk_container_child_type", &PyGtk_Type, &container))
        return NULL;
    return PyInt_FromLong(gtk_container_child_type(GTK_CONTAINER(PyGtk_Get(container))));
}

static PyObject *_wrap_gtk_fixed_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_fixed_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_fixed_get_type());
}

static PyObject *_wrap_gtk_fixed_new(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_fixed_new"))
        return NULL;
    return PyGtk_New((GtkObject *)gtk_fixed_new());
}

static PyObject *_wrap_gtk_fixed_put(PyObject *self, PyObject *args) {
    int x, y;
    PyObject *fixed, *widget;

    if (!PyArg_ParseTuple(args, "O!O!ii:gtk_fixed_put", &PyGtk_Type, &fixed, &PyGtk_Type, &widget, &x, &y))
        return NULL;
    gtk_fixed_put(GTK_FIXED(PyGtk_Get(fixed)), GTK_WIDGET(PyGtk_Get(widget)), x, y);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_fixed_move(PyObject *self, PyObject *args) {
    int x, y;
    PyObject *fixed, *widget;

    if (!PyArg_ParseTuple(args, "O!O!ii:gtk_fixed_move", &PyGtk_Type, &fixed, &PyGtk_Type, &widget, &x, &y))
        return NULL;
    gtk_fixed_move(GTK_FIXED(PyGtk_Get(fixed)), GTK_WIDGET(PyGtk_Get(widget)), x, y);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_bin_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_bin_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_bin_get_type());
}

static PyObject *_wrap_gtk_event_box_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_event_box_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_event_box_get_type());
}

static PyObject *_wrap_gtk_event_box_new(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_event_box_new"))
        return NULL;
    return PyGtk_New((GtkObject *)gtk_event_box_new());
}

static PyObject *_wrap_gtk_window_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_window_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_window_get_type());
}

static PyObject *_wrap_gtk_window_new(PyObject *self, PyObject *args) {
    GtkWindowType type;
    PyObject *py_type;

    if (!PyArg_ParseTuple(args, "O:gtk_window_new", &py_type))
        return NULL;
    if (PyGtkEnum_get_value(GTK_TYPE_WINDOW_TYPE, py_type, (gint *)&type))
        return NULL;
    return PyGtk_New((GtkObject *)gtk_window_new(type));
}

static PyObject *_wrap_gtk_window_set_title(PyObject *self, PyObject *args) {
    char *title;
    PyObject *window;

    if (!PyArg_ParseTuple(args, "O!s:gtk_window_set_title", &PyGtk_Type, &window, &title))
        return NULL;
    gtk_window_set_title(GTK_WINDOW(PyGtk_Get(window)), title);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_window_set_wmclass(PyObject *self, PyObject *args) {
    char *wmclass_class, *wmclass_name;
    PyObject *window;

    if (!PyArg_ParseTuple(args, "O!ss:gtk_window_set_wmclass", &PyGtk_Type, &window, &wmclass_class, &wmclass_name))
        return NULL;
    gtk_window_set_wmclass(GTK_WINDOW(PyGtk_Get(window)), wmclass_class, wmclass_name);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_window_set_policy(PyObject *self, PyObject *args) {
    int allow_shrink, allow_grow, auto_shrink;
    PyObject *window;

    if (!PyArg_ParseTuple(args, "O!iii:gtk_window_set_policy", &PyGtk_Type, &window, &allow_shrink, &allow_grow, &auto_shrink))
        return NULL;
    gtk_window_set_policy(GTK_WINDOW(PyGtk_Get(window)), allow_shrink, allow_grow, auto_shrink);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_window_add_accel_group(PyObject *self, PyObject *args) {
    PyObject *window, *group;

    if (!PyArg_ParseTuple(args, "O!O!:gtk_window_add_accel_group", &PyGtk_Type, &window, &PyGtkAccelGroup_Type, &group))
        return NULL;
    gtk_window_add_accel_group(GTK_WINDOW(PyGtk_Get(window)), PyGtkAccelGroup_Get(group));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_window_remove_accel_group(PyObject *self, PyObject *args) {
    PyObject *window, *group;

    if (!PyArg_ParseTuple(args, "O!O!:gtk_window_remove_accel_group", &PyGtk_Type, &window, &PyGtkAccelGroup_Type, &group))
        return NULL;
    gtk_window_remove_accel_group(GTK_WINDOW(PyGtk_Get(window)), PyGtkAccelGroup_Get(group));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_window_set_position(PyObject *self, PyObject *args) {
    GtkWindowPosition position;
    PyObject *window, *py_position;

    if (!PyArg_ParseTuple(args, "O!O:gtk_window_set_position", &PyGtk_Type, &window, &py_position))
        return NULL;
    if (PyGtkEnum_get_value(GTK_TYPE_WINDOW_POSITION, py_position, (gint *)&position))
        return NULL;
    gtk_window_set_position(GTK_WINDOW(PyGtk_Get(window)), position);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_window_activate_focus(PyObject *self, PyObject *args) {
    PyObject *window;

    if (!PyArg_ParseTuple(args, "O!:gtk_window_activate_focus", &PyGtk_Type, &window))
        return NULL;
    return PyInt_FromLong(gtk_window_activate_focus(GTK_WINDOW(PyGtk_Get(window))));
}

static PyObject *_wrap_gtk_window_activate_default(PyObject *self, PyObject *args) {
    PyObject *window;

    if (!PyArg_ParseTuple(args, "O!:gtk_window_activate_default", &PyGtk_Type, &window))
        return NULL;
    return PyInt_FromLong(gtk_window_activate_default(GTK_WINDOW(PyGtk_Get(window))));
}

static PyObject *_wrap_gtk_window_set_transient_for(PyObject *self, PyObject *args) {
    PyObject *window, *parent;

    if (!PyArg_ParseTuple(args, "O!O!:gtk_window_set_transient_for", &PyGtk_Type, &window, &PyGtk_Type, &parent))
        return NULL;
    gtk_window_set_transient_for(GTK_WINDOW(PyGtk_Get(window)), GTK_WINDOW(PyGtk_Get(parent)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_window_set_default_size(PyObject *self, PyObject *args) {
    int width, height;
    PyObject *window;

    if (!PyArg_ParseTuple(args, "O!ii:gtk_window_set_default_size", &PyGtk_Type, &window, &width, &height))
        return NULL;
    gtk_window_set_default_size(GTK_WINDOW(PyGtk_Get(window)), width, height);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_window_set_modal(PyObject *self, PyObject *args) {
    int modal;
    PyObject *window;

    if (!PyArg_ParseTuple(args, "O!i:gtk_window_set_modal", &PyGtk_Type, &window, &modal))
        return NULL;
    gtk_window_set_modal(GTK_WINDOW(PyGtk_Get(window)), modal);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_dialog_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_dialog_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_dialog_get_type());
}

static PyObject *_wrap_gtk_dialog_get_vbox(PyObject *self, PyObject *args) {
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_dialog_get_vbox", &PyGtk_Type, &obj))
        return NULL;
    return PyGtk_New((GtkObject *)GTK_DIALOG(PyGtk_Get(obj))->vbox);
}

static PyObject *_wrap_gtk_dialog_get_action_area(PyObject *self, PyObject *args) {
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_dialog_get_action_area", &PyGtk_Type, &obj))
        return NULL;
    return PyGtk_New((GtkObject *)GTK_DIALOG(PyGtk_Get(obj))->action_area);
}

static PyObject *_wrap_gtk_dialog_new(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_dialog_new"))
        return NULL;
    return PyGtk_New((GtkObject *)gtk_dialog_new());
}

static PyObject *_wrap_gtk_handle_box_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_handle_box_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_handle_box_get_type());
}

static PyObject *_wrap_gtk_handle_box_new(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_handle_box_new"))
        return NULL;
    return PyGtk_New((GtkObject *)gtk_handle_box_new());
}

static PyObject *_wrap_gtk_handle_box_set_shadow_type(PyObject *self, PyObject *args) {
    GtkShadowType type;
    PyObject *handle_box, *py_type;

    if (!PyArg_ParseTuple(args, "O!O:gtk_handle_box_set_shadow_type", &PyGtk_Type, &handle_box, &py_type))
        return NULL;
    if (PyGtkEnum_get_value(GTK_TYPE_SHADOW_TYPE, py_type, (gint *)&type))
        return NULL;
    gtk_handle_box_set_shadow_type(GTK_HANDLE_BOX(PyGtk_Get(handle_box)), type);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_handle_box_set_handle_position(PyObject *self, PyObject *args) {
    GtkPositionType position;
    PyObject *handle_box, *py_position;

    if (!PyArg_ParseTuple(args, "O!O:gtk_handle_box_set_handle_position", &PyGtk_Type, &handle_box, &py_position))
        return NULL;
    if (PyGtkEnum_get_value(GTK_TYPE_POSITION_TYPE, py_position, (gint *)&position))
        return NULL;
    gtk_handle_box_set_handle_position(GTK_HANDLE_BOX(PyGtk_Get(handle_box)), position);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_handle_box_set_snap_edge(PyObject *self, PyObject *args) {
    GtkPositionType position;
    PyObject *handle_box, *py_position;

    if (!PyArg_ParseTuple(args, "O!O:gtk_handle_box_set_snap_edge", &PyGtk_Type, &handle_box, &py_position))
        return NULL;
    if (PyGtkEnum_get_value(GTK_TYPE_POSITION_TYPE, py_position, (gint *)&position))
        return NULL;
    gtk_handle_box_set_snap_edge(GTK_HANDLE_BOX(PyGtk_Get(handle_box)), position);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_box_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_box_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_box_get_type());
}

static PyObject *_wrap_gtk_box_pack_start(PyObject *self, PyObject *args) {
    int expand = TRUE, fill = TRUE, padding = 0;
    PyObject *box, *child;

    if (!PyArg_ParseTuple(args, "O!O!|iii:gtk_box_pack_start", &PyGtk_Type, &box, &PyGtk_Type, &child, &expand, &fill, &padding))
        return NULL;
    gtk_box_pack_start(GTK_BOX(PyGtk_Get(box)), GTK_WIDGET(PyGtk_Get(child)), expand, fill, padding);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_box_pack_end(PyObject *self, PyObject *args) {
    int expand = TRUE, fill = TRUE, padding = 0;
    PyObject *box, *child;

    if (!PyArg_ParseTuple(args, "O!O!|iii:gtk_box_pack_end", &PyGtk_Type, &box, &PyGtk_Type, &child, &expand, &fill, &padding))
        return NULL;
    gtk_box_pack_end(GTK_BOX(PyGtk_Get(box)), GTK_WIDGET(PyGtk_Get(child)), expand, fill, padding);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_box_pack_start_defaults(PyObject *self, PyObject *args) {
    PyObject *box, *child;

    if (!PyArg_ParseTuple(args, "O!O!:gtk_box_pack_start_defaults", &PyGtk_Type, &box, &PyGtk_Type, &child))
        return NULL;
    gtk_box_pack_start_defaults(GTK_BOX(PyGtk_Get(box)), GTK_WIDGET(PyGtk_Get(child)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_box_pack_end_defaults(PyObject *self, PyObject *args) {
    PyObject *box, *child;

    if (!PyArg_ParseTuple(args, "O!O!:gtk_box_pack_end_defaults", &PyGtk_Type, &box, &PyGtk_Type, &child))
        return NULL;
    gtk_box_pack_end_defaults(GTK_BOX(PyGtk_Get(box)), GTK_WIDGET(PyGtk_Get(child)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_box_set_homogeneous(PyObject *self, PyObject *args) {
    int homogenous;
    PyObject *box;

    if (!PyArg_ParseTuple(args, "O!i:gtk_box_set_homogeneous", &PyGtk_Type, &box, &homogenous))
        return NULL;
    gtk_box_set_homogeneous(GTK_BOX(PyGtk_Get(box)), homogenous);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_box_set_spacing(PyObject *self, PyObject *args) {
    int spacing;
    PyObject *box;

    if (!PyArg_ParseTuple(args, "O!i:gtk_box_set_spacing", &PyGtk_Type, &box, &spacing))
        return NULL;
    gtk_box_set_spacing(GTK_BOX(PyGtk_Get(box)), spacing);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_box_reorder_child(PyObject *self, PyObject *args) {
    int pos;
    PyObject *box, *child;

    if (!PyArg_ParseTuple(args, "O!O!i:gtk_box_reorder_child", &PyGtk_Type, &box, &PyGtk_Type, &child, &pos))
        return NULL;
    gtk_box_reorder_child(GTK_BOX(PyGtk_Get(box)), GTK_WIDGET(PyGtk_Get(child)), pos);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_box_set_child_packing(PyObject *self, PyObject *args) {
    PyObject *box, *child, *py_pack_type;
    GtkPackType pack_type;
    int expand, fill, padding;

    if (!PyArg_ParseTuple(args, "O!O!iiiO:gtk_box_set_child_packing", &PyGtk_Type, &box, &PyGtk_Type, &child, &expand, &fill, &padding, &py_pack_type))
        return NULL;
    if (PyGtkEnum_get_value(GTK_TYPE_PACK_TYPE, py_pack_type, (gint *)&pack_type))
        return NULL;
    gtk_box_set_child_packing(GTK_BOX(PyGtk_Get(box)), GTK_WIDGET(PyGtk_Get(child)), expand, fill, padding, pack_type);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_hbox_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_hbox_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_hbox_get_type());
}

static PyObject *_wrap_gtk_hbox_new(PyObject *self, PyObject *args) {
    int homogeneous, spacing;

    if (!PyArg_ParseTuple(args, "ii:gtk_hbox_new", &homogeneous, &spacing))
        return NULL;
    return PyGtk_New((GtkObject *)gtk_hbox_new(homogeneous, spacing));
}

static PyObject *_wrap_gtk_vbox_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_vbox_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_vbox_get_type());
}

static PyObject *_wrap_gtk_vbox_new(PyObject *self, PyObject *args) {
    int homogeneous, spacing;

    if (!PyArg_ParseTuple(args, "ii:gtk_vbox_new", &homogeneous, &spacing))
        return NULL;
    return PyGtk_New((GtkObject *)gtk_vbox_new(homogeneous, spacing));
}

static PyObject *_wrap_gtk_button_box_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_button_box_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_button_box_get_type());
}

static PyObject *_wrap_gtk_button_box_set_child_size_default(PyObject *self, PyObject *args) {
    int min_width, min_height;

    if (!PyArg_ParseTuple(args, "ii:gtk_button_box_set_child_size_default", &min_width, &min_height))
        return NULL;
    gtk_button_box_set_child_size_default(min_width, min_height);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_button_box_set_child_ipadding_default(PyObject *self, PyObject *args) {
    int ipad_x, ipad_y;

    if (!PyArg_ParseTuple(args, "ii:gtk_button_box_set_child_ipadding_default", &ipad_x, &ipad_y))
        return NULL;
    gtk_button_box_set_child_ipadding_default(ipad_x, ipad_y);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_button_box_get_spacing(PyObject *self, PyObject *args) {
    PyObject *widget;

    if (!PyArg_ParseTuple(args, "O!:gtk_button_box_get_spacing", &PyGtk_Type, &widget))
        return NULL;
    return PyInt_FromLong(gtk_button_box_get_spacing(GTK_BUTTON_BOX(PyGtk_Get(widget))));
}

static PyObject *_wrap_gtk_button_box_get_layout(PyObject *self, PyObject *args) {
    PyObject *widget;

    if (!PyArg_ParseTuple(args, "O!:gtk_button_box_get_layout", &PyGtk_Type, &widget))
        return NULL;
    return PyInt_FromLong(gtk_button_box_get_layout(GTK_BUTTON_BOX(PyGtk_Get(widget))));
}

static PyObject *_wrap_gtk_button_box_set_spacing(PyObject *self, PyObject *args) {
    int spacing;
    PyObject *widget;

    if (!PyArg_ParseTuple(args, "O!i:gtk_button_box_set_spacing", &PyGtk_Type, &widget, &spacing))
        return NULL;
    gtk_button_box_set_spacing(GTK_BUTTON_BOX(PyGtk_Get(widget)), spacing);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_button_box_set_layout(PyObject *self, PyObject *args) {
    GtkButtonBoxStyle layout_style;
    PyObject *widget, *py_layout_style;

    if (!PyArg_ParseTuple(args, "O!O:gtk_button_box_set_layout", &PyGtk_Type, &widget, &py_layout_style))
        return NULL;
    if (PyGtkEnum_get_value(GTK_TYPE_BUTTON_BOX_STYLE, py_layout_style, (gint *)&layout_style))
        return NULL;
    gtk_button_box_set_layout(GTK_BUTTON_BOX(PyGtk_Get(widget)), layout_style);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_button_box_set_child_size(PyObject *self, PyObject *args) {
    int min_width, min_height;
    PyObject *widget;

    if (!PyArg_ParseTuple(args, "O!ii:gtk_button_box_set_child_size", &PyGtk_Type, &widget, &min_width, &min_height))
        return NULL;
    gtk_button_box_set_child_size(GTK_BUTTON_BOX(PyGtk_Get(widget)), min_width, min_height);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_button_box_set_child_ipadding(PyObject *self, PyObject *args) {
    int ipad_x, ipad_y;
    PyObject *widget;

    if (!PyArg_ParseTuple(args, "O!ii:gtk_button_box_set_child_ipadding", &PyGtk_Type, &widget, &ipad_x, &ipad_y))
        return NULL;
    gtk_button_box_set_child_ipadding(GTK_BUTTON_BOX(PyGtk_Get(widget)), ipad_x, ipad_y);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_hbutton_box_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_hbutton_box_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_hbutton_box_get_type());
}

static PyObject *_wrap_gtk_hbutton_box_new(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_hbutton_box_new"))
        return NULL;
    return PyGtk_New((GtkObject *)gtk_hbutton_box_new());
}

static PyObject *_wrap_gtk_hbutton_box_get_spacing_default(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_hbutton_box_get_spacing_default"))
        return NULL;
    return PyInt_FromLong(gtk_hbutton_box_get_spacing_default());
}

static PyObject *_wrap_gtk_hbutton_box_get_layout_default(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_hbutton_box_get_layout_default"))
        return NULL;
    return PyInt_FromLong(gtk_hbutton_box_get_layout_default());
}

static PyObject *_wrap_gtk_hbutton_box_set_spacing_default(PyObject *self, PyObject *args) {
    int spacing;

    if (!PyArg_ParseTuple(args, "i:gtk_hbutton_box_set_spacing_default", &spacing))
        return NULL;
    gtk_hbutton_box_set_spacing_default(spacing);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_hbutton_box_set_layout_default(PyObject *self, PyObject *args) {
    GtkButtonBoxStyle layout;
    PyObject *py_layout;

    if (!PyArg_ParseTuple(args, "O:gtk_hbutton_box_set_layout_default", &py_layout))
        return NULL;
    if (PyGtkEnum_get_value(GTK_TYPE_BUTTON_BOX_STYLE, py_layout, (gint *)&layout))
        return NULL;
    gtk_hbutton_box_set_layout_default(layout);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_vbutton_box_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_vbutton_box_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_vbutton_box_get_type());
}

static PyObject *_wrap_gtk_vbutton_box_new(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_vbutton_box_new"))
        return NULL;
    return PyGtk_New((GtkObject *)gtk_vbutton_box_new());
}

static PyObject *_wrap_gtk_vbutton_box_get_spacing_default(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_vbutton_box_get_spacing_default"))
        return NULL;
    return PyInt_FromLong(gtk_vbutton_box_get_spacing_default());
}

static PyObject *_wrap_gtk_vbutton_box_get_layout_default(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_vbutton_box_get_layout_default"))
        return NULL;
    return PyInt_FromLong(gtk_vbutton_box_get_layout_default());
}

static PyObject *_wrap_gtk_vbutton_box_set_spacing_default(PyObject *self, PyObject *args) {
    int spacing;

    if (!PyArg_ParseTuple(args, "i:gtk_vbutton_box_set_spacing_default", &spacing))
        return NULL;
    gtk_vbutton_box_set_spacing_default(spacing);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_vbutton_box_set_layout_default(PyObject *self, PyObject *args) {
    GtkButtonBoxStyle layout;
    PyObject *py_layout;

    if (!PyArg_ParseTuple(args, "O:gtk_vbutton_box_set_layout_default", &py_layout))
        return NULL;
    if (PyGtkEnum_get_value(GTK_TYPE_BUTTON_BOX_STYLE, py_layout, (gint *)&layout))
        return NULL;
    gtk_vbutton_box_set_layout_default(layout);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_table_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_table_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_table_get_type());
}

static PyObject *_wrap_gtk_table_new(PyObject *self, PyObject *args) {
    int rows, columns, homogenous;

    if (!PyArg_ParseTuple(args, "iii:gtk_table_new", &rows, &columns, &homogenous))
        return NULL;
    return PyGtk_New((GtkObject *)gtk_table_new(rows, columns, homogenous));
}

static PyObject *_wrap_gtk_table_attach(PyObject *self, PyObject *args) {
    GtkAttachOptions xoptions = GTK_EXPAND|GTK_FILL, yoptions = GTK_EXPAND|GTK_FILL;
    PyObject *table, *child, *py_xoptions = NULL, *py_yoptions = NULL;
    int left_attach, right_attach, top_attach, bottom_attach, xpadding = 0, ypadding = 0;

    if (!PyArg_ParseTuple(args, "O!O!iiii|OOii:gtk_table_attach", &PyGtk_Type, &table, &PyGtk_Type, &child, &left_attach, &right_attach, &top_attach, &bottom_attach, &py_xoptions, &py_yoptions, &xpadding, &ypadding))
        return NULL;
    if (PyGtkFlag_get_value(GTK_TYPE_ATTACH_OPTIONS, py_xoptions, (gint *)&xoptions))
        return NULL;
    if (PyGtkFlag_get_value(GTK_TYPE_ATTACH_OPTIONS, py_yoptions, (gint *)&yoptions))
        return NULL;
    gtk_table_attach(GTK_TABLE(PyGtk_Get(table)), GTK_WIDGET(PyGtk_Get(child)), left_attach, right_attach, top_attach, bottom_attach, xoptions, yoptions, xpadding, ypadding);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_table_attach_defaults(PyObject *self, PyObject *args) {
    int left_attach, right_attach, top_attach, bottom_attach;
    PyObject *table, *child;

    if (!PyArg_ParseTuple(args, "O!O!iiii:gtk_table_attach_defaults", &PyGtk_Type, &table, &PyGtk_Type, &child, &left_attach, &right_attach, &top_attach, &bottom_attach))
        return NULL;
    gtk_table_attach_defaults(GTK_TABLE(PyGtk_Get(table)), GTK_WIDGET(PyGtk_Get(child)), left_attach, right_attach, top_attach, bottom_attach);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_table_set_row_spacing(PyObject *self, PyObject *args) {
    int row, spacing;
    PyObject *table;

    if (!PyArg_ParseTuple(args, "O!ii:gtk_table_set_row_spacing", &PyGtk_Type, &table, &row, &spacing))
        return NULL;
    gtk_table_set_row_spacing(GTK_TABLE(PyGtk_Get(table)), row, spacing);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_table_set_col_spacing(PyObject *self, PyObject *args) {
    int column, spacing;
    PyObject *table;

    if (!PyArg_ParseTuple(args, "O!ii:gtk_table_set_col_spacing", &PyGtk_Type, &table, &column, &spacing))
        return NULL;
    gtk_table_set_col_spacing(GTK_TABLE(PyGtk_Get(table)), column, spacing);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_table_set_row_spacings(PyObject *self, PyObject *args) {
    int spacing;
    PyObject *table;

    if (!PyArg_ParseTuple(args, "O!i:gtk_table_set_row_spacings", &PyGtk_Type, &table, &spacing))
        return NULL;
    gtk_table_set_row_spacings(GTK_TABLE(PyGtk_Get(table)), spacing);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_table_set_col_spacings(PyObject *self, PyObject *args) {
    int spacing;
    PyObject *table;

    if (!PyArg_ParseTuple(args, "O!i:gtk_table_set_col_spacings", &PyGtk_Type, &table, &spacing))
        return NULL;
    gtk_table_set_col_spacings(GTK_TABLE(PyGtk_Get(table)), spacing);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_table_set_homogeneous(PyObject *self, PyObject *args) {
    int homogeneous;
    PyObject *table;

    if (!PyArg_ParseTuple(args, "O!i:gtk_table_set_homogeneous", &PyGtk_Type, &table, &homogeneous))
        return NULL;
    gtk_table_set_homogeneous(GTK_TABLE(PyGtk_Get(table)), homogeneous);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_table_resize(PyObject *self, PyObject *args) {
    int rows, cols;
    PyObject *table;

    if (!PyArg_ParseTuple(args, "O!ii:gtk_table_resize", &PyGtk_Type, &table, &rows, &cols))
        return NULL;
    gtk_table_resize(GTK_TABLE(PyGtk_Get(table)), rows, cols);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_packer_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_packer_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_packer_get_type());
}

static PyObject *_wrap_gtk_packer_new(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_packer_new"))
        return NULL;
    return PyGtk_New((GtkObject *)gtk_packer_new());
}

static PyObject *_wrap_gtk_packer_add_defaults(PyObject *self, PyObject *args) {
    GtkAnchorType anchor;
    GtkPackerOptions options;
    GtkSideType side;
    PyObject *packer, *child, *py_side, *py_anchor, *py_options;

    if (!PyArg_ParseTuple(args, "O!O!OOO:gtk_packer_add_defaults", &PyGtk_Type, &packer, &PyGtk_Type, &child, &py_side, &py_anchor, &py_options))
        return NULL;
    if (PyGtkEnum_get_value(GTK_TYPE_SIDE_TYPE, py_side, (gint *)&side))
        return NULL;
    if (PyGtkEnum_get_value(GTK_TYPE_ANCHOR_TYPE, py_anchor, (gint *)&anchor))
        return NULL;
    if (PyGtkFlag_get_value(GTK_TYPE_PACKER_OPTIONS, py_options, (gint *)&options))
        return NULL;
    gtk_packer_add_defaults(GTK_PACKER(PyGtk_Get(packer)), GTK_WIDGET(PyGtk_Get(child)), side, anchor, options);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_packer_add(PyObject *self, PyObject *args) {
    int border_width = 0, pad_x = 0, pad_y = 0, ipad_x = 0, ipad_y = 0;
    GtkAnchorType anchor;
    GtkPackerOptions options;
    GtkSideType side;
    PyObject *packer, *child, *py_side, *py_anchor, *py_options;

    if (!PyArg_ParseTuple(args, "O!O!OOO|iiiii:gtk_packer_add", &PyGtk_Type, &packer, &PyGtk_Type, &child, &py_side, &py_anchor, &py_options, &border_width, &pad_x, &pad_y, &ipad_x, &ipad_y))
        return NULL;
    if (PyGtkEnum_get_value(GTK_TYPE_SIDE_TYPE, py_side, (gint *)&side))
        return NULL;
    if (PyGtkEnum_get_value(GTK_TYPE_ANCHOR_TYPE, py_anchor, (gint *)&anchor))
        return NULL;
    if (PyGtkFlag_get_value(GTK_TYPE_PACKER_OPTIONS, py_options, (gint *)&options))
        return NULL;
    gtk_packer_add(GTK_PACKER(PyGtk_Get(packer)), GTK_WIDGET(PyGtk_Get(child)), side, anchor, options, border_width, pad_x, pad_y, ipad_x, ipad_y);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_packer_set_child_packing(PyObject *self, PyObject *args) {
    int border_width = 0, pad_x = 0, pad_y = 0, ipad_x = 0, ipad_y = 0;
    GtkAnchorType anchor;
    GtkPackerOptions options;
    GtkSideType size;
    PyObject *packer, *child, *py_size, *py_anchor, *py_options;

    if (!PyArg_ParseTuple(args, "O!O!OOO|iiiii:gtk_packer_set_child_packing", &PyGtk_Type, &packer, &PyGtk_Type, &child, &py_size, &py_anchor, &py_options, &border_width, &pad_x, &pad_y, &ipad_x, &ipad_y))
        return NULL;
    if (PyGtkEnum_get_value(GTK_TYPE_SIDE_TYPE, py_size, (gint *)&size))
        return NULL;
    if (PyGtkEnum_get_value(GTK_TYPE_ANCHOR_TYPE, py_anchor, (gint *)&anchor))
        return NULL;
    if (PyGtkFlag_get_value(GTK_TYPE_PACKER_OPTIONS, py_options, (gint *)&options))
        return NULL;
    gtk_packer_set_child_packing(GTK_PACKER(PyGtk_Get(packer)), GTK_WIDGET(PyGtk_Get(child)), size, anchor, options, border_width, pad_x, pad_y, ipad_x, ipad_y);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_packer_reorder_child(PyObject *self, PyObject *args) {
    int position;
    PyObject *packer, *widget;

    if (!PyArg_ParseTuple(args, "O!O!i:gtk_packer_reorder_child", &PyGtk_Type, &packer, &PyGtk_Type, &widget, &position))
        return NULL;
    gtk_packer_reorder_child(GTK_PACKER(PyGtk_Get(packer)), GTK_WIDGET(PyGtk_Get(widget)), position);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_packer_set_spacing(PyObject *self, PyObject *args) {
    int spacing;
    PyObject *packer;

    if (!PyArg_ParseTuple(args, "O!i:gtk_packer_set_spacing", &PyGtk_Type, &packer, &spacing))
        return NULL;
    gtk_packer_set_spacing(GTK_PACKER(PyGtk_Get(packer)), spacing);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_packer_set_default_border_width(PyObject *self, PyObject *args) {
    int border;
    PyObject *packer;

    if (!PyArg_ParseTuple(args, "O!i:gtk_packer_set_default_border_width", &PyGtk_Type, &packer, &border))
        return NULL;
    gtk_packer_set_default_border_width(GTK_PACKER(PyGtk_Get(packer)), border);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_packer_set_default_pad(PyObject *self, PyObject *args) {
    int pad_x, pad_y;
    PyObject *packer;

    if (!PyArg_ParseTuple(args, "O!ii:gtk_packer_set_default_pad", &PyGtk_Type, &packer, &pad_x, &pad_y))
        return NULL;
    gtk_packer_set_default_pad(GTK_PACKER(PyGtk_Get(packer)), pad_x, pad_y);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_packer_set_default_ipad(PyObject *self, PyObject *args) {
    int ipad_x, ipad_y;
    PyObject *packer;

    if (!PyArg_ParseTuple(args, "O!ii:gtk_packer_set_default_ipad", &PyGtk_Type, &packer, &ipad_x, &ipad_y))
        return NULL;
    gtk_packer_set_default_ipad(GTK_PACKER(PyGtk_Get(packer)), ipad_x, ipad_y);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_paned_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_paned_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_paned_get_type());
}

static PyObject *_wrap_gtk_paned_add1(PyObject *self, PyObject *args) {
    PyObject *paned, *child;

    if (!PyArg_ParseTuple(args, "O!O!:gtk_paned_add1", &PyGtk_Type, &paned, &PyGtk_Type, &child))
        return NULL;
    gtk_paned_add1(GTK_PANED(PyGtk_Get(paned)), GTK_WIDGET(PyGtk_Get(child)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_paned_add2(PyObject *self, PyObject *args) {
    PyObject *paned, *child;

    if (!PyArg_ParseTuple(args, "O!O!:gtk_paned_add2", &PyGtk_Type, &paned, &PyGtk_Type, &child))
        return NULL;
    gtk_paned_add2(GTK_PANED(PyGtk_Get(paned)), GTK_WIDGET(PyGtk_Get(child)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_paned_pack1(PyObject *self, PyObject *args) {
    int resize, shrink;
    PyObject *paned, *child;

    if (!PyArg_ParseTuple(args, "O!O!ii:gtk_paned_pack1", &PyGtk_Type, &paned, &PyGtk_Type, &child, &resize, &shrink))
        return NULL;
    gtk_paned_pack1(GTK_PANED(PyGtk_Get(paned)), GTK_WIDGET(PyGtk_Get(child)), resize, shrink);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_paned_pack2(PyObject *self, PyObject *args) {
    int resize, shrink;
    PyObject *paned, *child;

    if (!PyArg_ParseTuple(args, "O!O!ii:gtk_paned_pack2", &PyGtk_Type, &paned, &PyGtk_Type, &child, &resize, &shrink))
        return NULL;
    gtk_paned_pack2(GTK_PANED(PyGtk_Get(paned)), GTK_WIDGET(PyGtk_Get(child)), resize, shrink);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_paned_set_position(PyObject *self, PyObject *args) {
    int position;
    PyObject *paned;

    if (!PyArg_ParseTuple(args, "O!i:gtk_paned_set_position", &PyGtk_Type, &paned, &position))
        return NULL;
    gtk_paned_set_position(GTK_PANED(PyGtk_Get(paned)), position);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_paned_set_handle_size(PyObject *self, PyObject *args) {
    int size;
    PyObject *paned;

    if (!PyArg_ParseTuple(args, "O!i:gtk_paned_set_handle_size", &PyGtk_Type, &paned, &size))
        return NULL;
    gtk_paned_set_handle_size(GTK_PANED(PyGtk_Get(paned)), size);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_paned_set_gutter_size(PyObject *self, PyObject *args) {
    int size;
    PyObject *paned;

    if (!PyArg_ParseTuple(args, "O!i:gtk_paned_set_gutter_size", &PyGtk_Type, &paned, &size))
        return NULL;
    gtk_paned_set_gutter_size(GTK_PANED(PyGtk_Get(paned)), size);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_hpaned_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_hpaned_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_hpaned_get_type());
}

static PyObject *_wrap_gtk_hpaned_new(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_hpaned_new"))
        return NULL;
    return PyGtk_New((GtkObject *)gtk_hpaned_new());
}

static PyObject *_wrap_gtk_vpaned_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_vpaned_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_vpaned_get_type());
}

static PyObject *_wrap_gtk_vpaned_new(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_vpaned_new"))
        return NULL;
    return PyGtk_New((GtkObject *)gtk_vpaned_new());
}

static PyObject *_wrap_gtk_frame_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_frame_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_frame_get_type());
}

static PyObject *_wrap_gtk_frame_new(PyObject *self, PyObject *args) {
    char *label;

    if (!PyArg_ParseTuple(args, "z:gtk_frame_new", &label))
        return NULL;
    return PyGtk_New((GtkObject *)gtk_frame_new(label));
}

static PyObject *_wrap_gtk_frame_set_label(PyObject *self, PyObject *args) {
    char *label;
    PyObject *frame;

    if (!PyArg_ParseTuple(args, "O!s:gtk_frame_set_label", &PyGtk_Type, &frame, &label))
        return NULL;
    gtk_frame_set_label(GTK_FRAME(PyGtk_Get(frame)), label);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_frame_set_label_align(PyObject *self, PyObject *args) {
    double xalign, yalign;
    PyObject *frame;

    if (!PyArg_ParseTuple(args, "O!dd:gtk_frame_set_label_align", &PyGtk_Type, &frame, &xalign, &yalign))
        return NULL;
    gtk_frame_set_label_align(GTK_FRAME(PyGtk_Get(frame)), xalign, yalign);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_frame_set_shadow_type(PyObject *self, PyObject *args) {
    GtkShadowType type;
    PyObject *frame, *py_type;

    if (!PyArg_ParseTuple(args, "O!O:gtk_frame_set_shadow_type", &PyGtk_Type, &frame, &py_type))
        return NULL;
    if (PyGtkEnum_get_value(GTK_TYPE_SHADOW_TYPE, py_type, (gint *)&type))
        return NULL;
    gtk_frame_set_shadow_type(GTK_FRAME(PyGtk_Get(frame)), type);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_aspect_frame_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_aspect_frame_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_aspect_frame_get_type());
}

static PyObject *_wrap_gtk_aspect_frame_new(PyObject *self, PyObject *args) {
    int obey_child;
    double xalign, yalign, ratio;
    char *label;

    if (!PyArg_ParseTuple(args, "sdddi:gtk_aspect_frame_new", &label, &xalign, &yalign, &ratio, &obey_child))
        return NULL;
    return PyGtk_New((GtkObject *)gtk_aspect_frame_new(label, xalign, yalign, ratio, obey_child));
}

static PyObject *_wrap_gtk_aspect_frame_set(PyObject *self, PyObject *args) {
    int obey_child;
    double xalign, yalign, ratio;
    PyObject *aspect_frame;

    if (!PyArg_ParseTuple(args, "O!dddi:gtk_aspect_frame_set", &PyGtk_Type, &aspect_frame, &xalign, &yalign, &ratio, &obey_child))
        return NULL;
    gtk_aspect_frame_set(GTK_ASPECT_FRAME(PyGtk_Get(aspect_frame)), xalign, yalign, ratio, obey_child);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_viewport_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_viewport_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_viewport_get_type());
}

static PyObject *_wrap_gtk_viewport_new(PyObject *self, PyObject *args) {
    GtkAdjustment *hadjustment = NULL, *vadjustment = NULL;
    PyObject *py_hadjustment = Py_None, *py_vadjustment = Py_None;

    if (!PyArg_ParseTuple(args, "|OO:gtk_viewport_new", &py_hadjustment, &py_vadjustment))
        return NULL;
    if (PyGtk_Check(py_hadjustment))
        hadjustment = GTK_ADJUSTMENT(PyGtk_Get(py_hadjustment));
    else if (py_hadjustment != Py_None) {
        PyErr_SetString(PyExc_TypeError, "hadjustment argument must be a GtkAdjustment or None");
	return NULL;
    }
    if (PyGtk_Check(py_vadjustment))
        vadjustment = GTK_ADJUSTMENT(PyGtk_Get(py_vadjustment));
    else if (py_vadjustment != Py_None) {
        PyErr_SetString(PyExc_TypeError, "vadjustment argument must be a GtkAdjustment or None");
	return NULL;
    }
    return PyGtk_New((GtkObject *)gtk_viewport_new(hadjustment, vadjustment));
}

static PyObject *_wrap_gtk_viewport_get_hadjustment(PyObject *self, PyObject *args) {
    PyObject *viewport;

    if (!PyArg_ParseTuple(args, "O!:gtk_viewport_get_hadjustment", &PyGtk_Type, &viewport))
        return NULL;
    return PyGtk_New((GtkObject *)gtk_viewport_get_hadjustment(GTK_VIEWPORT(PyGtk_Get(viewport))));
}

static PyObject *_wrap_gtk_viewport_get_vadjustment(PyObject *self, PyObject *args) {
    PyObject *viewport;

    if (!PyArg_ParseTuple(args, "O!:gtk_viewport_get_vadjustment", &PyGtk_Type, &viewport))
        return NULL;
    return PyGtk_New((GtkObject *)gtk_viewport_get_vadjustment(GTK_VIEWPORT(PyGtk_Get(viewport))));
}

static PyObject *_wrap_gtk_viewport_set_hadjustment(PyObject *self, PyObject *args) {
    PyObject *viewport, *adjustment;

    if (!PyArg_ParseTuple(args, "O!O!:gtk_viewport_set_hadjustment", &PyGtk_Type, &viewport, &PyGtk_Type, &adjustment))
        return NULL;
    gtk_viewport_set_hadjustment(GTK_VIEWPORT(PyGtk_Get(viewport)), GTK_ADJUSTMENT(PyGtk_Get(adjustment)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_viewport_set_vadjustment(PyObject *self, PyObject *args) {
    PyObject *viewport, *adjustment;

    if (!PyArg_ParseTuple(args, "O!O!:gtk_viewport_set_vadjustment", &PyGtk_Type, &viewport, &PyGtk_Type, &adjustment))
        return NULL;
    gtk_viewport_set_vadjustment(GTK_VIEWPORT(PyGtk_Get(viewport)), GTK_ADJUSTMENT(PyGtk_Get(adjustment)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_viewport_set_shadow_type(PyObject *self, PyObject *args) {
    GtkShadowType type;
    PyObject *viewport, *py_type;

    if (!PyArg_ParseTuple(args, "O!O:gtk_viewport_set_shadow_type", &PyGtk_Type, &viewport, &py_type))
        return NULL;
    if (PyGtkEnum_get_value(GTK_TYPE_SHADOW_TYPE, py_type, (gint *)&type))
        return NULL;
    gtk_viewport_set_shadow_type(GTK_VIEWPORT(PyGtk_Get(viewport)), type);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_scrolled_window_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_scrolled_window_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_scrolled_window_get_type());
}

static PyObject *_wrap_gtk_scrolled_window_new(PyObject *self, PyObject *args) {
    GtkAdjustment *hadjustment = NULL, *vadjustment = NULL;
    PyObject *py_hadjustment = Py_None, *py_vadjustment = Py_None;

    if (!PyArg_ParseTuple(args, "|OO:gtk_scrolled_window_new", &py_hadjustment, &py_vadjustment))
        return NULL;
    if (PyGtk_Check(py_hadjustment))
        hadjustment = GTK_ADJUSTMENT(PyGtk_Get(py_hadjustment));
    else if (py_hadjustment != Py_None) {
        PyErr_SetString(PyExc_TypeError, "hadjustment argument must be a GtkAdjustment or None");
	return NULL;
    }
    if (PyGtk_Check(py_vadjustment))
        vadjustment = GTK_ADJUSTMENT(PyGtk_Get(py_vadjustment));
    else if (py_vadjustment != Py_None) {
        PyErr_SetString(PyExc_TypeError, "vadjustment argument must be a GtkAdjustment or None");
	return NULL;
    }
    return PyGtk_New((GtkObject *)gtk_scrolled_window_new(hadjustment, vadjustment));
}

static PyObject *_wrap_gtk_scrolled_window_set_hadjustment(PyObject *self, PyObject *args) {
    PyObject *scrolled_window, *adjustment;

    if (!PyArg_ParseTuple(args, "O!O!:gtk_scrolled_window_set_hadjustment", &PyGtk_Type, &scrolled_window, &PyGtk_Type, &adjustment))
        return NULL;
    gtk_scrolled_window_set_hadjustment(GTK_SCROLLED_WINDOW(PyGtk_Get(scrolled_window)), GTK_ADJUSTMENT(PyGtk_Get(adjustment)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_scrolled_window_set_vadjustment(PyObject *self, PyObject *args) {
    PyObject *scrolled_window, *adjustment;

    if (!PyArg_ParseTuple(args, "O!O!:gtk_scrolled_window_set_vadjustment", &PyGtk_Type, &scrolled_window, &PyGtk_Type, &adjustment))
        return NULL;
    gtk_scrolled_window_set_vadjustment(GTK_SCROLLED_WINDOW(PyGtk_Get(scrolled_window)), GTK_ADJUSTMENT(PyGtk_Get(adjustment)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_scrolled_window_get_hadjustment(PyObject *self, PyObject *args) {
    PyObject *scrolled_window;

    if (!PyArg_ParseTuple(args, "O!:gtk_scrolled_window_get_hadjustment", &PyGtk_Type, &scrolled_window))
        return NULL;
    return PyGtk_New((GtkObject *)gtk_scrolled_window_get_hadjustment(GTK_SCROLLED_WINDOW(PyGtk_Get(scrolled_window))));
}

static PyObject *_wrap_gtk_scrolled_window_get_vadjustment(PyObject *self, PyObject *args) {
    PyObject *scrolled_window;

    if (!PyArg_ParseTuple(args, "O!:gtk_scrolled_window_get_vadjustment", &PyGtk_Type, &scrolled_window))
        return NULL;
    return PyGtk_New((GtkObject *)gtk_scrolled_window_get_vadjustment(GTK_SCROLLED_WINDOW(PyGtk_Get(scrolled_window))));
}

static PyObject *_wrap_gtk_scrolled_window_set_policy(PyObject *self, PyObject *args) {
    GtkPolicyType hscrollbar_policy, vscrollbar_policy;
    PyObject *scrolled_window, *py_hscrollbar_policy, *py_vscrollbar_policy;

    if (!PyArg_ParseTuple(args, "O!OO:gtk_scrolled_window_set_policy", &PyGtk_Type, &scrolled_window, &py_hscrollbar_policy, &py_vscrollbar_policy))
        return NULL;
    if (PyGtkEnum_get_value(GTK_TYPE_POLICY_TYPE, py_hscrollbar_policy, (gint *)&hscrollbar_policy))
        return NULL;
    if (PyGtkEnum_get_value(GTK_TYPE_POLICY_TYPE, py_vscrollbar_policy, (gint *)&vscrollbar_policy))
        return NULL;
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(PyGtk_Get(scrolled_window)), hscrollbar_policy, vscrollbar_policy);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_scrolled_window_set_placement(PyObject *self, PyObject *args) {
    GtkCornerType window_placement;
    PyObject *scrolled_window, *py_window_placement;

    if (!PyArg_ParseTuple(args, "O!O:gtk_scrolled_window_set_placement", &PyGtk_Type, &scrolled_window, &py_window_placement))
        return NULL;
    if (PyGtkEnum_get_value(GTK_TYPE_CORNER_TYPE, py_window_placement, (gint *)&window_placement))
        return NULL;
    gtk_scrolled_window_set_placement(GTK_SCROLLED_WINDOW(PyGtk_Get(scrolled_window)), window_placement);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_scrolled_window_add_with_viewport(PyObject *self, PyObject *args) {
    PyObject *scrolled_window, *child;

    if (!PyArg_ParseTuple(args, "O!O!:gtk_scrolled_window_add_with_viewport", &PyGtk_Type, &scrolled_window, &PyGtk_Type, &child))
        return NULL;
    gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(PyGtk_Get(scrolled_window)), GTK_WIDGET(PyGtk_Get(child)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_notebook_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_notebook_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_notebook_get_type());
}

static PyObject *_wrap_gtk_notebook_get_tab_pos(PyObject *self, PyObject *args) {
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_notebook_get_tab_pos", &PyGtk_Type, &obj))
        return NULL;
    return PyInt_FromLong(GTK_NOTEBOOK(PyGtk_Get(obj))->tab_pos);
}

static PyObject *_wrap_gtk_notebook_new(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_notebook_new"))
        return NULL;
    return PyGtk_New((GtkObject *)gtk_notebook_new());
}

static PyObject *_wrap_gtk_notebook_append_page(PyObject *self, PyObject *args) {
    PyObject *notebook, *child, *tab_label;

    if (!PyArg_ParseTuple(args, "O!O!O!:gtk_notebook_append_page", &PyGtk_Type, &notebook, &PyGtk_Type, &child, &PyGtk_Type, &tab_label))
        return NULL;
    gtk_notebook_append_page(GTK_NOTEBOOK(PyGtk_Get(notebook)), GTK_WIDGET(PyGtk_Get(child)), GTK_WIDGET(PyGtk_Get(tab_label)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_notebook_append_page_menu(PyObject *self, PyObject *args) {
    PyObject *notebook, *child, *tab_label, *menu_label;

    if (!PyArg_ParseTuple(args, "O!O!O!O!:gtk_notebook_append_page_menu", &PyGtk_Type, &notebook, &PyGtk_Type, &child, &PyGtk_Type, &tab_label, &PyGtk_Type, &menu_label))
        return NULL;
    gtk_notebook_append_page_menu(GTK_NOTEBOOK(PyGtk_Get(notebook)), GTK_WIDGET(PyGtk_Get(child)), GTK_WIDGET(PyGtk_Get(tab_label)), GTK_WIDGET(PyGtk_Get(menu_label)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_notebook_prepend_page(PyObject *self, PyObject *args) {
    PyObject *notebook, *child, *tab_label;

    if (!PyArg_ParseTuple(args, "O!O!O!:gtk_notebook_prepend_page", &PyGtk_Type, &notebook, &PyGtk_Type, &child, &PyGtk_Type, &tab_label))
        return NULL;
    gtk_notebook_prepend_page(GTK_NOTEBOOK(PyGtk_Get(notebook)), GTK_WIDGET(PyGtk_Get(child)), GTK_WIDGET(PyGtk_Get(tab_label)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_notebook_prepend_page_menu(PyObject *self, PyObject *args) {
    PyObject *notebook, *child, *tab_label, *menu_label;

    if (!PyArg_ParseTuple(args, "O!O!O!O!:gtk_notebook_prepend_page_menu", &PyGtk_Type, &notebook, &PyGtk_Type, &child, &PyGtk_Type, &tab_label, &PyGtk_Type, &menu_label))
        return NULL;
    gtk_notebook_prepend_page_menu(GTK_NOTEBOOK(PyGtk_Get(notebook)), GTK_WIDGET(PyGtk_Get(child)), GTK_WIDGET(PyGtk_Get(tab_label)), GTK_WIDGET(PyGtk_Get(menu_label)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_notebook_insert_page(PyObject *self, PyObject *args) {
    int position;
    PyObject *notebook, *child, *tab_label;

    if (!PyArg_ParseTuple(args, "O!O!O!i:gtk_notebook_insert_page", &PyGtk_Type, &notebook, &PyGtk_Type, &child, &PyGtk_Type, &tab_label, &position))
        return NULL;
    gtk_notebook_insert_page(GTK_NOTEBOOK(PyGtk_Get(notebook)), GTK_WIDGET(PyGtk_Get(child)), GTK_WIDGET(PyGtk_Get(tab_label)), position);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_notebook_insert_page_menu(PyObject *self, PyObject *args) {
    int position;
    PyObject *notebook, *child, *tab_label, *menu_label;

    if (!PyArg_ParseTuple(args, "O!O!O!O!i:gtk_notebook_insert_page_menu", &PyGtk_Type, &notebook, &PyGtk_Type, &child, &PyGtk_Type, &tab_label, &PyGtk_Type, &menu_label, &position))
        return NULL;
    gtk_notebook_insert_page_menu(GTK_NOTEBOOK(PyGtk_Get(notebook)), GTK_WIDGET(PyGtk_Get(child)), GTK_WIDGET(PyGtk_Get(tab_label)), GTK_WIDGET(PyGtk_Get(menu_label)), position);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_notebook_remove_page(PyObject *self, PyObject *args) {
    int page_num;
    PyObject *notebook;

    if (!PyArg_ParseTuple(args, "O!i:gtk_notebook_remove_page", &PyGtk_Type, &notebook, &page_num))
        return NULL;
    gtk_notebook_remove_page(GTK_NOTEBOOK(PyGtk_Get(notebook)), page_num);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_notebook_get_current_page(PyObject *self, PyObject *args) {
    PyObject *notebook;

    if (!PyArg_ParseTuple(args, "O!:gtk_notebook_get_current_page", &PyGtk_Type, &notebook))
        return NULL;
    return PyInt_FromLong(gtk_notebook_get_current_page(GTK_NOTEBOOK(PyGtk_Get(notebook))));
}

static PyObject *_wrap_gtk_notebook_get_nth_page(PyObject *self, PyObject *args) {
    int page_num;
    PyObject *notebook;

    if (!PyArg_ParseTuple(args, "O!i:gtk_notebook_get_nth_page", &PyGtk_Type, &notebook, &page_num))
        return NULL;
    return PyGtk_New((GtkObject *)gtk_notebook_get_nth_page(GTK_NOTEBOOK(PyGtk_Get(notebook)), page_num));
}

static PyObject *_wrap_gtk_notebook_page_num(PyObject *self, PyObject *args) {
    PyObject *notebook, *page;

    if (!PyArg_ParseTuple(args, "O!O!:gtk_notebook_page_num", &PyGtk_Type, &notebook, &PyGtk_Type, &page))
        return NULL;
    return PyInt_FromLong(gtk_notebook_page_num(GTK_NOTEBOOK(PyGtk_Get(notebook)), GTK_WIDGET(PyGtk_Get(page))));
}

static PyObject *_wrap_gtk_notebook_set_page(PyObject *self, PyObject *args) {
    int page_num;
    PyObject *notebook;

    if (!PyArg_ParseTuple(args, "O!i:gtk_notebook_set_page", &PyGtk_Type, &notebook, &page_num))
        return NULL;
    gtk_notebook_set_page(GTK_NOTEBOOK(PyGtk_Get(notebook)), page_num);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_notebook_next_page(PyObject *self, PyObject *args) {
    PyObject *notebook;

    if (!PyArg_ParseTuple(args, "O!:gtk_notebook_next_page", &PyGtk_Type, &notebook))
        return NULL;
    gtk_notebook_next_page(GTK_NOTEBOOK(PyGtk_Get(notebook)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_notebook_prev_page(PyObject *self, PyObject *args) {
    PyObject *notebook;

    if (!PyArg_ParseTuple(args, "O!:gtk_notebook_prev_page", &PyGtk_Type, &notebook))
        return NULL;
    gtk_notebook_prev_page(GTK_NOTEBOOK(PyGtk_Get(notebook)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_notebook_reorder_child(PyObject *self, PyObject *args) {
    int position;
    PyObject *notebook, *child;

    if (!PyArg_ParseTuple(args, "O!O!i:gtk_notebook_reorder_child", &PyGtk_Type, &notebook, &PyGtk_Type, &child, &position))
        return NULL;
    gtk_notebook_reorder_child(GTK_NOTEBOOK(PyGtk_Get(notebook)), GTK_WIDGET(PyGtk_Get(child)), position);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_notebook_set_tab_pos(PyObject *self, PyObject *args) {
    GtkPositionType pos;
    PyObject *notebook, *py_pos;

    if (!PyArg_ParseTuple(args, "O!O:gtk_notebook_set_tab_pos", &PyGtk_Type, &notebook, &py_pos))
        return NULL;
    if (PyGtkEnum_get_value(GTK_TYPE_POSITION_TYPE, py_pos, (gint *)&pos))
        return NULL;
    gtk_notebook_set_tab_pos(GTK_NOTEBOOK(PyGtk_Get(notebook)), pos);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_notebook_set_show_tabs(PyObject *self, PyObject *args) {
    int show_tabs;
    PyObject *notebook;

    if (!PyArg_ParseTuple(args, "O!i:gtk_notebook_set_show_tabs", &PyGtk_Type, &notebook, &show_tabs))
        return NULL;
    gtk_notebook_set_show_tabs(GTK_NOTEBOOK(PyGtk_Get(notebook)), show_tabs);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_notebook_set_show_border(PyObject *self, PyObject *args) {
    int show_border;
    PyObject *notebook;

    if (!PyArg_ParseTuple(args, "O!i:gtk_notebook_set_show_border", &PyGtk_Type, &notebook, &show_border))
        return NULL;
    gtk_notebook_set_show_border(GTK_NOTEBOOK(PyGtk_Get(notebook)), show_border);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_notebook_set_scrollable(PyObject *self, PyObject *args) {
    int scrollable;
    PyObject *notebook;

    if (!PyArg_ParseTuple(args, "O!i:gtk_notebook_set_scrollable", &PyGtk_Type, &notebook, &scrollable))
        return NULL;
    gtk_notebook_set_scrollable(GTK_NOTEBOOK(PyGtk_Get(notebook)), scrollable);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_notebook_set_homogeneous_tabs(PyObject *self, PyObject *args) {
    int homogeneous;
    PyObject *notebook;

    if (!PyArg_ParseTuple(args, "O!i:gtk_notebook_set_homogeneous_tabs", &PyGtk_Type, &notebook, &homogeneous))
        return NULL;
    gtk_notebook_set_homogeneous_tabs(GTK_NOTEBOOK(PyGtk_Get(notebook)), homogeneous);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_notebook_set_tab_border(PyObject *self, PyObject *args) {
    int border_width;
    PyObject *notebook;

    if (!PyArg_ParseTuple(args, "O!i:gtk_notebook_set_tab_border", &PyGtk_Type, &notebook, &border_width))
        return NULL;
    gtk_notebook_set_tab_border(GTK_NOTEBOOK(PyGtk_Get(notebook)), border_width);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_notebook_set_tab_hborder(PyObject *self, PyObject *args) {
    int tab_hborder;
    PyObject *notebook;

    if (!PyArg_ParseTuple(args, "O!i:gtk_notebook_set_tab_hborder", &PyGtk_Type, &notebook, &tab_hborder))
        return NULL;
    gtk_notebook_set_tab_hborder(GTK_NOTEBOOK(PyGtk_Get(notebook)), tab_hborder);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_notebook_set_tab_vborder(PyObject *self, PyObject *args) {
    int tab_vborder;
    PyObject *notebook;

    if (!PyArg_ParseTuple(args, "O!i:gtk_notebook_set_tab_vborder", &PyGtk_Type, &notebook, &tab_vborder))
        return NULL;
    gtk_notebook_set_tab_vborder(GTK_NOTEBOOK(PyGtk_Get(notebook)), tab_vborder);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_notebook_popup_enable(PyObject *self, PyObject *args) {
    PyObject *notebook;

    if (!PyArg_ParseTuple(args, "O!:gtk_notebook_popup_enable", &PyGtk_Type, &notebook))
        return NULL;
    gtk_notebook_popup_enable(GTK_NOTEBOOK(PyGtk_Get(notebook)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_notebook_popup_disable(PyObject *self, PyObject *args) {
    PyObject *notebook;

    if (!PyArg_ParseTuple(args, "O!:gtk_notebook_popup_disable", &PyGtk_Type, &notebook))
        return NULL;
    gtk_notebook_popup_disable(GTK_NOTEBOOK(PyGtk_Get(notebook)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_notebook_get_tab_label(PyObject *self, PyObject *args) {
    PyObject *notebook, *child;

    if (!PyArg_ParseTuple(args, "O!O!:gtk_notebook_get_tab_label", &PyGtk_Type, &notebook, &PyGtk_Type, &child))
        return NULL;
    return PyGtk_New((GtkObject *)gtk_notebook_get_tab_label(GTK_NOTEBOOK(PyGtk_Get(notebook)), GTK_WIDGET(PyGtk_Get(child))));
}

static PyObject *_wrap_gtk_notebook_set_tab_label(PyObject *self, PyObject *args) {
    PyObject *notebook, *child, *tab_label;

    if (!PyArg_ParseTuple(args, "O!O!O!:gtk_notebook_set_tab_label", &PyGtk_Type, &notebook, &PyGtk_Type, &child, &PyGtk_Type, &tab_label))
        return NULL;
    gtk_notebook_set_tab_label(GTK_NOTEBOOK(PyGtk_Get(notebook)), GTK_WIDGET(PyGtk_Get(child)), GTK_WIDGET(PyGtk_Get(tab_label)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_notebook_set_tab_label_text(PyObject *self, PyObject *args) {
    char *tab_text;
    PyObject *notebook, *child;

    if (!PyArg_ParseTuple(args, "O!O!s:gtk_notebook_set_tab_label_text", &PyGtk_Type, &notebook, &PyGtk_Type, &child, &tab_text))
        return NULL;
    gtk_notebook_set_tab_label_text(GTK_NOTEBOOK(PyGtk_Get(notebook)), GTK_WIDGET(PyGtk_Get(child)), tab_text);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_notebook_get_menu_label(PyObject *self, PyObject *args) {
    PyObject *notebook, *child;

    if (!PyArg_ParseTuple(args, "O!O!:gtk_notebook_get_menu_label", &PyGtk_Type, &notebook, &PyGtk_Type, &child))
        return NULL;
    return PyGtk_New((GtkObject *)gtk_notebook_get_menu_label(GTK_NOTEBOOK(PyGtk_Get(notebook)), GTK_WIDGET(PyGtk_Get(child))));
}

static PyObject *_wrap_gtk_notebook_set_menu_label(PyObject *self, PyObject *args) {
    PyObject *notebook, *child, *menu_label;

    if (!PyArg_ParseTuple(args, "O!O!O!:gtk_notebook_set_menu_label", &PyGtk_Type, &notebook, &PyGtk_Type, &child, &PyGtk_Type, &menu_label))
        return NULL;
    gtk_notebook_set_menu_label(GTK_NOTEBOOK(PyGtk_Get(notebook)), GTK_WIDGET(PyGtk_Get(child)), GTK_WIDGET(PyGtk_Get(menu_label)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_notebook_set_menu_label_text(PyObject *self, PyObject *args) {
    char *menu_text;
    PyObject *notebook, *child;

    if (!PyArg_ParseTuple(args, "O!O!s:gtk_notebook_set_menu_label_text", &PyGtk_Type, &notebook, &PyGtk_Type, &child, &menu_text))
        return NULL;
    gtk_notebook_set_menu_label_text(GTK_NOTEBOOK(PyGtk_Get(notebook)), GTK_WIDGET(PyGtk_Get(child)), menu_text);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_notebook_set_tab_label_packing(PyObject *self, PyObject *args) {
    PyObject *notebook, *child, *py_pack_type;
    GtkPackType pack_type;
    int expand, fill;

    if (!PyArg_ParseTuple(args, "O!O!iiO:gtk_notebook_set_tab_label_packing", &PyGtk_Type, &notebook, &PyGtk_Type, &child, &expand, &fill, &py_pack_type))
        return NULL;
    if (PyGtkEnum_get_value(GTK_TYPE_PACK_TYPE, py_pack_type, (gint *)&pack_type))
        return NULL;
    gtk_notebook_set_tab_label_packing(GTK_NOTEBOOK(PyGtk_Get(notebook)), GTK_WIDGET(PyGtk_Get(child)), expand, fill, pack_type);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_alignment_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_alignment_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_alignment_get_type());
}

static PyObject *_wrap_gtk_alignment_new(PyObject *self, PyObject *args) {
    double xalign, yalign, xscale, yscale;

    if (!PyArg_ParseTuple(args, "dddd:gtk_alignment_new", &xalign, &yalign, &xscale, &yscale))
        return NULL;
    return PyGtk_New((GtkObject *)gtk_alignment_new(xalign, yalign, xscale, yscale));
}

static PyObject *_wrap_gtk_alignment_set(PyObject *self, PyObject *args) {
    double xalign, yalign, xscale, yscale;
    PyObject *alignment;

    if (!PyArg_ParseTuple(args, "O!dddd:gtk_alignment_set", &PyGtk_Type, &alignment, &xalign, &yalign, &xscale, &yscale))
        return NULL;
    gtk_alignment_set(GTK_ALIGNMENT(PyGtk_Get(alignment)), xalign, yalign, xscale, yscale);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_layout_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_layout_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_layout_get_type());
}

static PyObject *_wrap_gtk_layout_new(PyObject *self, PyObject *args) {
    GtkAdjustment *hadjustment = NULL, *vadjustment = NULL;
    PyObject *py_hadjustment = Py_None, *py_vadjustment = Py_None;

    if (!PyArg_ParseTuple(args, "|OO:gtk_layout_new", &py_hadjustment, &py_vadjustment))
        return NULL;
    if (PyGtk_Check(py_hadjustment))
        hadjustment = GTK_ADJUSTMENT(PyGtk_Get(py_hadjustment));
    else if (py_hadjustment != Py_None) {
        PyErr_SetString(PyExc_TypeError, "hadjustment argument must be a GtkAdjustment or None");
	return NULL;
    }
    if (PyGtk_Check(py_vadjustment))
        vadjustment = GTK_ADJUSTMENT(PyGtk_Get(py_vadjustment));
    else if (py_vadjustment != Py_None) {
        PyErr_SetString(PyExc_TypeError, "vadjustment argument must be a GtkAdjustment or None");
	return NULL;
    }
    return PyGtk_New((GtkObject *)gtk_layout_new(hadjustment, vadjustment));
}

static PyObject *_wrap_gtk_layout_put(PyObject *self, PyObject *args) {
    int x, y;
    PyObject *layout, *child;

    if (!PyArg_ParseTuple(args, "O!O!ii:gtk_layout_put", &PyGtk_Type, &layout, &PyGtk_Type, &child, &x, &y))
        return NULL;
    gtk_layout_put(GTK_LAYOUT(PyGtk_Get(layout)), GTK_WIDGET(PyGtk_Get(child)), x, y);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_layout_move(PyObject *self, PyObject *args) {
    int x, y;
    PyObject *layout, *child;

    if (!PyArg_ParseTuple(args, "O!O!ii:gtk_layout_move", &PyGtk_Type, &layout, &PyGtk_Type, &child, &x, &y))
        return NULL;
    gtk_layout_move(GTK_LAYOUT(PyGtk_Get(layout)), GTK_WIDGET(PyGtk_Get(child)), x, y);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_layout_set_size(PyObject *self, PyObject *args) {
    int width, height;
    PyObject *layout;

    if (!PyArg_ParseTuple(args, "O!ii:gtk_layout_set_size", &PyGtk_Type, &layout, &width, &height))
        return NULL;
    gtk_layout_set_size(GTK_LAYOUT(PyGtk_Get(layout)), width, height);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_layout_freeze(PyObject *self, PyObject *args) {
    PyObject *layout;

    if (!PyArg_ParseTuple(args, "O!:gtk_layout_freeze", &PyGtk_Type, &layout))
        return NULL;
    gtk_layout_freeze(GTK_LAYOUT(PyGtk_Get(layout)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_layout_thaw(PyObject *self, PyObject *args) {
    PyObject *layout;

    if (!PyArg_ParseTuple(args, "O!:gtk_layout_thaw", &PyGtk_Type, &layout))
        return NULL;
    gtk_layout_thaw(GTK_LAYOUT(PyGtk_Get(layout)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_layout_get_hadjustment(PyObject *self, PyObject *args) {
    PyObject *layout;

    if (!PyArg_ParseTuple(args, "O!:gtk_layout_get_hadjustment", &PyGtk_Type, &layout))
        return NULL;
    return PyGtk_New((GtkObject *)gtk_layout_get_hadjustment(GTK_LAYOUT(PyGtk_Get(layout))));
}

static PyObject *_wrap_gtk_layout_get_vadjustment(PyObject *self, PyObject *args) {
    PyObject *layout;

    if (!PyArg_ParseTuple(args, "O!:gtk_layout_get_vadjustment", &PyGtk_Type, &layout))
        return NULL;
    return PyGtk_New((GtkObject *)gtk_layout_get_vadjustment(GTK_LAYOUT(PyGtk_Get(layout))));
}

static PyObject *_wrap_gtk_layout_set_hadjustment(PyObject *self, PyObject *args) {
    PyObject *layout, *adjustment;

    if (!PyArg_ParseTuple(args, "O!O!:gtk_layout_set_hadjustment", &PyGtk_Type, &layout, &PyGtk_Type, &adjustment))
        return NULL;
    gtk_layout_set_hadjustment(GTK_LAYOUT(PyGtk_Get(layout)), GTK_ADJUSTMENT(PyGtk_Get(adjustment)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_layout_set_vadjustment(PyObject *self, PyObject *args) {
    PyObject *layout, *adjustment;

    if (!PyArg_ParseTuple(args, "O!O!:gtk_layout_set_vadjustment", &PyGtk_Type, &layout, &PyGtk_Type, &adjustment))
        return NULL;
    gtk_layout_set_vadjustment(GTK_LAYOUT(PyGtk_Get(layout)), GTK_ADJUSTMENT(PyGtk_Get(adjustment)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_plug_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_plug_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_plug_get_type());
}

static PyObject *_wrap_gtk_plug_new(PyObject *self, PyObject *args) {
    int socket_id;

    if (!PyArg_ParseTuple(args, "i:gtk_plug_new", &socket_id))
        return NULL;
    return PyGtk_New((GtkObject *)gtk_plug_new(socket_id));
}

static PyObject *_wrap_gtk_socket_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_socket_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_socket_get_type());
}

static PyObject *_wrap_gtk_socket_new(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_socket_new"))
        return NULL;
    return PyGtk_New((GtkObject *)gtk_socket_new());
}

static PyObject *_wrap_gtk_socket_steal(PyObject *self, PyObject *args) {
    int window_id;
    PyObject *socket;

    if (!PyArg_ParseTuple(args, "O!i:gtk_socket_steal", &PyGtk_Type, &socket, &window_id))
        return NULL;
    gtk_socket_steal(GTK_SOCKET(PyGtk_Get(socket)), window_id);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_toolbar_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_toolbar_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_toolbar_get_type());
}

static PyObject *_wrap_gtk_toolbar_new(PyObject *self, PyObject *args) {
    GtkOrientation orientation;
    GtkToolbarStyle style;
    PyObject *py_orientation, *py_style;

    if (!PyArg_ParseTuple(args, "OO:gtk_toolbar_new", &py_orientation, &py_style))
        return NULL;
    if (PyGtkEnum_get_value(GTK_TYPE_ORIENTATION, py_orientation, (gint *)&orientation))
        return NULL;
    if (PyGtkEnum_get_value(GTK_TYPE_TOOLBAR_STYLE, py_style, (gint *)&style))
        return NULL;
    return PyGtk_New((GtkObject *)gtk_toolbar_new(orientation, style));
}

static PyObject *_wrap_gtk_toolbar_append_space(PyObject *self, PyObject *args) {
    PyObject *toolbar;

    if (!PyArg_ParseTuple(args, "O!:gtk_toolbar_append_space", &PyGtk_Type, &toolbar))
        return NULL;
    gtk_toolbar_append_space(GTK_TOOLBAR(PyGtk_Get(toolbar)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_toolbar_prepend_space(PyObject *self, PyObject *args) {
    PyObject *toolbar;

    if (!PyArg_ParseTuple(args, "O!:gtk_toolbar_prepend_space", &PyGtk_Type, &toolbar))
        return NULL;
    gtk_toolbar_prepend_space(GTK_TOOLBAR(PyGtk_Get(toolbar)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_toolbar_insert_space(PyObject *self, PyObject *args) {
    int position;
    PyObject *toolbar;

    if (!PyArg_ParseTuple(args, "O!i:gtk_toolbar_insert_space", &PyGtk_Type, &toolbar, &position))
        return NULL;
    gtk_toolbar_insert_space(GTK_TOOLBAR(PyGtk_Get(toolbar)), position);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_toolbar_append_widget(PyObject *self, PyObject *args) {
    char *tooltip_text, *tooltip_private_text;
    PyObject *Toolbar, *Widget;

    if (!PyArg_ParseTuple(args, "O!O!ss:gtk_toolbar_append_widget", &PyGtk_Type, &Toolbar, &PyGtk_Type, &Widget, &tooltip_text, &tooltip_private_text))
        return NULL;
    gtk_toolbar_append_widget(GTK_TOOLBAR(PyGtk_Get(Toolbar)), GTK_WIDGET(PyGtk_Get(Widget)), tooltip_text, tooltip_private_text);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_toolbar_prepend_widget(PyObject *self, PyObject *args) {
    char *tooltip_text, *tooltip_private_text;
    PyObject *Toolbar, *Widget;

    if (!PyArg_ParseTuple(args, "O!O!ss:gtk_toolbar_prepend_widget", &PyGtk_Type, &Toolbar, &PyGtk_Type, &Widget, &tooltip_text, &tooltip_private_text))
        return NULL;
    gtk_toolbar_prepend_widget(GTK_TOOLBAR(PyGtk_Get(Toolbar)), GTK_WIDGET(PyGtk_Get(Widget)), tooltip_text, tooltip_private_text);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_toolbar_insert_widget(PyObject *self, PyObject *args) {
    int position;
    char *tooltip_text, *tooltip_private_text;
    PyObject *toolbar, *widget;

    if (!PyArg_ParseTuple(args, "O!O!ssi:gtk_toolbar_insert_widget", &PyGtk_Type, &toolbar, &PyGtk_Type, &widget, &tooltip_text, &tooltip_private_text, &position))
        return NULL;
    gtk_toolbar_insert_widget(GTK_TOOLBAR(PyGtk_Get(toolbar)), GTK_WIDGET(PyGtk_Get(widget)), tooltip_text, tooltip_private_text, position);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_toolbar_set_orientation(PyObject *self, PyObject *args) {
    GtkOrientation orientation;
    PyObject *toolbar, *py_orientation;

    if (!PyArg_ParseTuple(args, "O!O:gtk_toolbar_set_orientation", &PyGtk_Type, &toolbar, &py_orientation))
        return NULL;
    if (PyGtkEnum_get_value(GTK_TYPE_ORIENTATION, py_orientation, (gint *)&orientation))
        return NULL;
    gtk_toolbar_set_orientation(GTK_TOOLBAR(PyGtk_Get(toolbar)), orientation);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_toolbar_set_style(PyObject *self, PyObject *args) {
    GtkToolbarStyle style;
    PyObject *toolbar, *py_style;

    if (!PyArg_ParseTuple(args, "O!O:gtk_toolbar_set_style", &PyGtk_Type, &toolbar, &py_style))
        return NULL;
    if (PyGtkEnum_get_value(GTK_TYPE_TOOLBAR_STYLE, py_style, (gint *)&style))
        return NULL;
    gtk_toolbar_set_style(GTK_TOOLBAR(PyGtk_Get(toolbar)), style);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_toolbar_set_space_size(PyObject *self, PyObject *args) {
    int space_size;
    PyObject *toolbar;

    if (!PyArg_ParseTuple(args, "O!i:gtk_toolbar_set_space_size", &PyGtk_Type, &toolbar, &space_size))
        return NULL;
    gtk_toolbar_set_space_size(GTK_TOOLBAR(PyGtk_Get(toolbar)), space_size);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_toolbar_set_space_style(PyObject *self, PyObject *args) {
    GtkToolbarSpaceStyle space_style;
    PyObject *toolbar, *py_space_style;

    if (!PyArg_ParseTuple(args, "O!O:gtk_toolbar_set_space_style", &PyGtk_Type, &toolbar, &py_space_style))
        return NULL;
    if (PyGtkEnum_get_value(GTK_TYPE_TOOLBAR_SPACE_STYLE, py_space_style, (gint *)&space_style))
        return NULL;
    gtk_toolbar_set_space_style(GTK_TOOLBAR(PyGtk_Get(toolbar)), space_style);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_toolbar_set_tooltips(PyObject *self, PyObject *args) {
    int enable;
    PyObject *toolbar;

    if (!PyArg_ParseTuple(args, "O!i:gtk_toolbar_set_tooltips", &PyGtk_Type, &toolbar, &enable))
        return NULL;
    gtk_toolbar_set_tooltips(GTK_TOOLBAR(PyGtk_Get(toolbar)), enable);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_toolbar_set_button_relief(PyObject *self, PyObject *args) {
    GtkReliefStyle relief;
    PyObject *toolbar, *py_relief;

    if (!PyArg_ParseTuple(args, "O!O:gtk_toolbar_set_button_relief", &PyGtk_Type, &toolbar, &py_relief))
        return NULL;
    if (PyGtkEnum_get_value(GTK_TYPE_RELIEF_STYLE, py_relief, (gint *)&relief))
        return NULL;
    gtk_toolbar_set_button_relief(GTK_TOOLBAR(PyGtk_Get(toolbar)), relief);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_toolbar_get_button_relief(PyObject *self, PyObject *args) {
    PyObject *toolbar;

    if (!PyArg_ParseTuple(args, "O!:gtk_toolbar_get_button_relief", &PyGtk_Type, &toolbar))
        return NULL;
    return PyInt_FromLong(gtk_toolbar_get_button_relief(GTK_TOOLBAR(PyGtk_Get(toolbar))));
}

static PyObject *_wrap_gtk_button_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_button_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_button_get_type());
}

static PyObject *_wrap_gtk_button_new(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_button_new"))
        return NULL;
    return PyGtk_New((GtkObject *)gtk_button_new());
}

static PyObject *_wrap_gtk_button_new_with_label(PyObject *self, PyObject *args) {
    char *label;

    if (!PyArg_ParseTuple(args, "s:gtk_button_new_with_label", &label))
        return NULL;
    return PyGtk_New((GtkObject *)gtk_button_new_with_label(label));
}

static PyObject *_wrap_gtk_button_pressed(PyObject *self, PyObject *args) {
    PyObject *button;

    if (!PyArg_ParseTuple(args, "O!:gtk_button_pressed", &PyGtk_Type, &button))
        return NULL;
    gtk_button_pressed(GTK_BUTTON(PyGtk_Get(button)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_button_released(PyObject *self, PyObject *args) {
    PyObject *button;

    if (!PyArg_ParseTuple(args, "O!:gtk_button_released", &PyGtk_Type, &button))
        return NULL;
    gtk_button_released(GTK_BUTTON(PyGtk_Get(button)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_button_clicked(PyObject *self, PyObject *args) {
    PyObject *button;

    if (!PyArg_ParseTuple(args, "O!:gtk_button_clicked", &PyGtk_Type, &button))
        return NULL;
    gtk_button_clicked(GTK_BUTTON(PyGtk_Get(button)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_button_enter(PyObject *self, PyObject *args) {
    PyObject *button;

    if (!PyArg_ParseTuple(args, "O!:gtk_button_enter", &PyGtk_Type, &button))
        return NULL;
    gtk_button_enter(GTK_BUTTON(PyGtk_Get(button)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_button_leave(PyObject *self, PyObject *args) {
    PyObject *button;

    if (!PyArg_ParseTuple(args, "O!:gtk_button_leave", &PyGtk_Type, &button))
        return NULL;
    gtk_button_leave(GTK_BUTTON(PyGtk_Get(button)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_button_set_relief(PyObject *self, PyObject *args) {
    GtkReliefStyle newstyle;
    PyObject *button, *py_newstyle;

    if (!PyArg_ParseTuple(args, "O!O:gtk_button_set_relief", &PyGtk_Type, &button, &py_newstyle))
        return NULL;
    if (PyGtkEnum_get_value(GTK_TYPE_RELIEF_STYLE, py_newstyle, (gint *)&newstyle))
        return NULL;
    gtk_button_set_relief(GTK_BUTTON(PyGtk_Get(button)), newstyle);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_button_get_relief(PyObject *self, PyObject *args) {
    PyObject *button;

    if (!PyArg_ParseTuple(args, "O!:gtk_button_get_relief", &PyGtk_Type, &button))
        return NULL;
    return PyInt_FromLong(gtk_button_get_relief(GTK_BUTTON(PyGtk_Get(button))));
}

static PyObject *_wrap_gtk_toggle_button_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_toggle_button_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_toggle_button_get_type());
}

static PyObject *_wrap_gtk_toggle_button_get_draw_indicator(PyObject *self, PyObject *args) {
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_toggle_button_get_draw_indicator", &PyGtk_Type, &obj))
        return NULL;
    return PyInt_FromLong(GTK_TOGGLE_BUTTON(PyGtk_Get(obj))->draw_indicator);
}

static PyObject *_wrap_gtk_toggle_button_new(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_toggle_button_new"))
        return NULL;
    return PyGtk_New((GtkObject *)gtk_toggle_button_new());
}

static PyObject *_wrap_gtk_toggle_button_new_with_label(PyObject *self, PyObject *args) {
    char *label;

    if (!PyArg_ParseTuple(args, "s:gtk_toggle_button_new_with_label", &label))
        return NULL;
    return PyGtk_New((GtkObject *)gtk_toggle_button_new_with_label(label));
}

static PyObject *_wrap_gtk_toggle_button_set_mode(PyObject *self, PyObject *args) {
    int draw_indicator;
    PyObject *toggle_button;

    if (!PyArg_ParseTuple(args, "O!i:gtk_toggle_button_set_mode", &PyGtk_Type, &toggle_button, &draw_indicator))
        return NULL;
    gtk_toggle_button_set_mode(GTK_TOGGLE_BUTTON(PyGtk_Get(toggle_button)), draw_indicator);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_toggle_button_set_active(PyObject *self, PyObject *args) {
    int state;
    PyObject *toggle_button;

    if (!PyArg_ParseTuple(args, "O!i:gtk_toggle_button_set_active", &PyGtk_Type, &toggle_button, &state))
        return NULL;
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(PyGtk_Get(toggle_button)), state);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_toggle_button_get_active(PyObject *self, PyObject *args) {
    PyObject *toggle_button;

    if (!PyArg_ParseTuple(args, "O!:gtk_toggle_button_get_active", &PyGtk_Type, &toggle_button))
        return NULL;
    return PyInt_FromLong(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(PyGtk_Get(toggle_button))));
}

static PyObject *_wrap_gtk_toggle_button_toggled(PyObject *self, PyObject *args) {
    PyObject *toggle_button;

    if (!PyArg_ParseTuple(args, "O!:gtk_toggle_button_toggled", &PyGtk_Type, &toggle_button))
        return NULL;
    gtk_toggle_button_toggled(GTK_TOGGLE_BUTTON(PyGtk_Get(toggle_button)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_check_button_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_check_button_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_check_button_get_type());
}

static PyObject *_wrap_gtk_check_button_new(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_check_button_new"))
        return NULL;
    return PyGtk_New((GtkObject *)gtk_check_button_new());
}

static PyObject *_wrap_gtk_check_button_new_with_label(PyObject *self, PyObject *args) {
    char *label;

    if (!PyArg_ParseTuple(args, "s:gtk_check_button_new_with_label", &label))
        return NULL;
    return PyGtk_New((GtkObject *)gtk_check_button_new_with_label(label));
}

static PyObject *_wrap_gtk_radio_button_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_radio_button_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_radio_button_get_type());
}

static PyObject *_wrap_gtk_radio_button_new_from_widget(PyObject *self, PyObject *args) {
    PyObject *group;

    if (!PyArg_ParseTuple(args, "O!:gtk_radio_button_new_from_widget", &PyGtk_Type, &group))
        return NULL;
    return PyGtk_New((GtkObject *)gtk_radio_button_new_from_widget(GTK_RADIO_BUTTON(PyGtk_Get(group))));
}

static PyObject *_wrap_gtk_radio_button_new_with_label_from_widget(PyObject *self, PyObject *args) {
    GtkRadioButton *group = NULL;
    char *label;
    PyObject *py_group = Py_None;

    if (!PyArg_ParseTuple(args, "Os:gtk_radio_button_new_with_label_from_widget", &py_group, &label))
        return NULL;
    if (PyGtk_Check(py_group))
        group = GTK_RADIO_BUTTON(PyGtk_Get(py_group));
    else if (py_group != Py_None) {
        PyErr_SetString(PyExc_TypeError, "group argument must be a GtkRadioButton or None");
	return NULL;
    }
    return PyGtk_New((GtkObject *)gtk_radio_button_new_with_label_from_widget(group, label));
}

static PyObject *_wrap_gtk_misc_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_misc_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_misc_get_type());
}

static PyObject *_wrap_gtk_misc_set_alignment(PyObject *self, PyObject *args) {
    double xalign, yalign;
    PyObject *misc;

    if (!PyArg_ParseTuple(args, "O!dd:gtk_misc_set_alignment", &PyGtk_Type, &misc, &xalign, &yalign))
        return NULL;
    gtk_misc_set_alignment(GTK_MISC(PyGtk_Get(misc)), xalign, yalign);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_misc_set_padding(PyObject *self, PyObject *args) {
    int xpad, ypad;
    PyObject *misc;

    if (!PyArg_ParseTuple(args, "O!ii:gtk_misc_set_padding", &PyGtk_Type, &misc, &xpad, &ypad))
        return NULL;
    gtk_misc_set_padding(GTK_MISC(PyGtk_Get(misc)), xpad, ypad);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_arrow_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_arrow_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_arrow_get_type());
}

static PyObject *_wrap_gtk_arrow_new(PyObject *self, PyObject *args) {
    GtkArrowType arrow_type;
    GtkShadowType shadow_type;
    PyObject *py_arrow_type, *py_shadow_type;

    if (!PyArg_ParseTuple(args, "OO:gtk_arrow_new", &py_arrow_type, &py_shadow_type))
        return NULL;
    if (PyGtkEnum_get_value(GTK_TYPE_ARROW_TYPE, py_arrow_type, (gint *)&arrow_type))
        return NULL;
    if (PyGtkEnum_get_value(GTK_TYPE_SHADOW_TYPE, py_shadow_type, (gint *)&shadow_type))
        return NULL;
    return PyGtk_New((GtkObject *)gtk_arrow_new(arrow_type, shadow_type));
}

static PyObject *_wrap_gtk_arrow_set(PyObject *self, PyObject *args) {
    GtkArrowType arrow_type;
    GtkShadowType shadow_type;
    PyObject *arrow, *py_arrow_type, *py_shadow_type;

    if (!PyArg_ParseTuple(args, "O!OO:gtk_arrow_set", &PyGtk_Type, &arrow, &py_arrow_type, &py_shadow_type))
        return NULL;
    if (PyGtkEnum_get_value(GTK_TYPE_ARROW_TYPE, py_arrow_type, (gint *)&arrow_type))
        return NULL;
    if (PyGtkEnum_get_value(GTK_TYPE_SHADOW_TYPE, py_shadow_type, (gint *)&shadow_type))
        return NULL;
    gtk_arrow_set(GTK_ARROW(PyGtk_Get(arrow)), arrow_type, shadow_type);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_label_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_label_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_label_get_type());
}

static PyObject *_wrap_gtk_label_new(PyObject *self, PyObject *args) {
    char *str;

    if (!PyArg_ParseTuple(args, "s:gtk_label_new", &str))
        return NULL;
    return PyGtk_New((GtkObject *)gtk_label_new(str));
}

static PyObject *_wrap_gtk_label_set_text(PyObject *self, PyObject *args) {
    char *str;
    PyObject *label;

    if (!PyArg_ParseTuple(args, "O!s:gtk_label_set_text", &PyGtk_Type, &label, &str))
        return NULL;
    gtk_label_set_text(GTK_LABEL(PyGtk_Get(label)), str);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_label_set_pattern(PyObject *self, PyObject *args) {
    char *pattern;
    PyObject *label;

    if (!PyArg_ParseTuple(args, "O!s:gtk_label_set_pattern", &PyGtk_Type, &label, &pattern))
        return NULL;
    gtk_label_set_pattern(GTK_LABEL(PyGtk_Get(label)), pattern);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_label_set_justify(PyObject *self, PyObject *args) {
    GtkJustification jtype;
    PyObject *label, *py_jtype;

    if (!PyArg_ParseTuple(args, "O!O:gtk_label_set_justify", &PyGtk_Type, &label, &py_jtype))
        return NULL;
    if (PyGtkEnum_get_value(GTK_TYPE_JUSTIFICATION, py_jtype, (gint *)&jtype))
        return NULL;
    gtk_label_set_justify(GTK_LABEL(PyGtk_Get(label)), jtype);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_label_set_line_wrap(PyObject *self, PyObject *args) {
    int wrap;
    PyObject *label;

    if (!PyArg_ParseTuple(args, "O!i:gtk_label_set_line_wrap", &PyGtk_Type, &label, &wrap))
        return NULL;
    gtk_label_set_line_wrap(GTK_LABEL(PyGtk_Get(label)), wrap);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_label_parse_uline(PyObject *self, PyObject *args) {
    char *string;
    PyObject *label;

    if (!PyArg_ParseTuple(args, "O!s:gtk_label_parse_uline", &PyGtk_Type, &label, &string))
        return NULL;
    return PyInt_FromLong(gtk_label_parse_uline(GTK_LABEL(PyGtk_Get(label)), string));
}

static PyObject *_wrap_gtk_accel_label_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_accel_label_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_accel_label_get_type());
}

static PyObject *_wrap_gtk_accel_label_new(PyObject *self, PyObject *args) {
    char *string;

    if (!PyArg_ParseTuple(args, "s:gtk_accel_label_new", &string))
        return NULL;
    return PyGtk_New((GtkObject *)gtk_accel_label_new(string));
}

static PyObject *_wrap_gtk_accel_label_get_accel_width(PyObject *self, PyObject *args) {
    PyObject *accel_label;

    if (!PyArg_ParseTuple(args, "O!:gtk_accel_label_get_accel_width", &PyGtk_Type, &accel_label))
        return NULL;
    return PyInt_FromLong(gtk_accel_label_get_accel_width(GTK_ACCEL_LABEL(PyGtk_Get(accel_label))));
}

static PyObject *_wrap_gtk_accel_label_set_accel_widget(PyObject *self, PyObject *args) {
    PyObject *accel_label, *accel_widget;

    if (!PyArg_ParseTuple(args, "O!O!:gtk_accel_label_set_accel_widget", &PyGtk_Type, &accel_label, &PyGtk_Type, &accel_widget))
        return NULL;
    gtk_accel_label_set_accel_widget(GTK_ACCEL_LABEL(PyGtk_Get(accel_label)), GTK_WIDGET(PyGtk_Get(accel_widget)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_accel_label_refetch(PyObject *self, PyObject *args) {
    PyObject *accel_label;

    if (!PyArg_ParseTuple(args, "O!:gtk_accel_label_refetch", &PyGtk_Type, &accel_label))
        return NULL;
    return PyInt_FromLong(gtk_accel_label_refetch(GTK_ACCEL_LABEL(PyGtk_Get(accel_label))));
}

static PyObject *_wrap_gtk_tips_query_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_tips_query_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_tips_query_get_type());
}

static PyObject *_wrap_gtk_tips_query_new(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_tips_query_new"))
        return NULL;
    return PyGtk_New((GtkObject *)gtk_tips_query_new());
}

static PyObject *_wrap_gtk_tips_query_start_query(PyObject *self, PyObject *args) {
    PyObject *tips_query;

    if (!PyArg_ParseTuple(args, "O!:gtk_tips_query_start_query", &PyGtk_Type, &tips_query))
        return NULL;
    gtk_tips_query_start_query(GTK_TIPS_QUERY(PyGtk_Get(tips_query)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_tips_query_stop_query(PyObject *self, PyObject *args) {
    PyObject *tips_query;

    if (!PyArg_ParseTuple(args, "O!:gtk_tips_query_stop_query", &PyGtk_Type, &tips_query))
        return NULL;
    gtk_tips_query_stop_query(GTK_TIPS_QUERY(PyGtk_Get(tips_query)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_tips_query_set_caller(PyObject *self, PyObject *args) {
    PyObject *tips_query, *caller;

    if (!PyArg_ParseTuple(args, "O!O!:gtk_tips_query_set_caller", &PyGtk_Type, &tips_query, &PyGtk_Type, &caller))
        return NULL;
    gtk_tips_query_set_caller(GTK_TIPS_QUERY(PyGtk_Get(tips_query)), GTK_WIDGET(PyGtk_Get(caller)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_tips_query_set_labels(PyObject *self, PyObject *args) {
    char *label_inactive, *label_no_tip;
    PyObject *tips_query;

    if (!PyArg_ParseTuple(args, "O!ss:gtk_tips_query_set_labels", &PyGtk_Type, &tips_query, &label_inactive, &label_no_tip))
        return NULL;
    gtk_tips_query_set_labels(GTK_TIPS_QUERY(PyGtk_Get(tips_query)), label_inactive, label_no_tip);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_item_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_item_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_item_get_type());
}

static PyObject *_wrap_gtk_item_select(PyObject *self, PyObject *args) {
    PyObject *item;

    if (!PyArg_ParseTuple(args, "O!:gtk_item_select", &PyGtk_Type, &item))
        return NULL;
    gtk_item_select(GTK_ITEM(PyGtk_Get(item)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_item_deselect(PyObject *self, PyObject *args) {
    PyObject *item;

    if (!PyArg_ParseTuple(args, "O!:gtk_item_deselect", &PyGtk_Type, &item))
        return NULL;
    gtk_item_deselect(GTK_ITEM(PyGtk_Get(item)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_item_toggle(PyObject *self, PyObject *args) {
    PyObject *item;

    if (!PyArg_ParseTuple(args, "O!:gtk_item_toggle", &PyGtk_Type, &item))
        return NULL;
    gtk_item_toggle(GTK_ITEM(PyGtk_Get(item)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_statusbar_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_statusbar_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_statusbar_get_type());
}

static PyObject *_wrap_gtk_statusbar_new(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_statusbar_new"))
        return NULL;
    return PyGtk_New((GtkObject *)gtk_statusbar_new());
}

static PyObject *_wrap_gtk_statusbar_push(PyObject *self, PyObject *args) {
    int context_id;
    char *text;
    PyObject *statusbar;

    if (!PyArg_ParseTuple(args, "O!is:gtk_statusbar_push", &PyGtk_Type, &statusbar, &context_id, &text))
        return NULL;
    return PyInt_FromLong(gtk_statusbar_push(GTK_STATUSBAR(PyGtk_Get(statusbar)), context_id, text));
}

static PyObject *_wrap_gtk_statusbar_pop(PyObject *self, PyObject *args) {
    int context_id;
    PyObject *statusbar;

    if (!PyArg_ParseTuple(args, "O!i:gtk_statusbar_pop", &PyGtk_Type, &statusbar, &context_id))
        return NULL;
    gtk_statusbar_pop(GTK_STATUSBAR(PyGtk_Get(statusbar)), context_id);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_statusbar_get_context_id(PyObject *self, PyObject *args) {
    char *context_description;
    PyObject *statusbar;

    if (!PyArg_ParseTuple(args, "O!s:gtk_statusbar_get_context_id", &PyGtk_Type, &statusbar, &context_description))
        return NULL;
    return PyInt_FromLong(gtk_statusbar_get_context_id(GTK_STATUSBAR(PyGtk_Get(statusbar)), context_description));
}

static PyObject *_wrap_gtk_statusbar_remove(PyObject *self, PyObject *args) {
    int context_id, message_id;
    PyObject *statusbar;

    if (!PyArg_ParseTuple(args, "O!ii:gtk_statusbar_remove", &PyGtk_Type, &statusbar, &context_id, &message_id))
        return NULL;
    gtk_statusbar_remove(GTK_STATUSBAR(PyGtk_Get(statusbar)), context_id, message_id);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_separator_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_separator_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_separator_get_type());
}

static PyObject *_wrap_gtk_hseparator_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_hseparator_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_hseparator_get_type());
}

static PyObject *_wrap_gtk_hseparator_new(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_hseparator_new"))
        return NULL;
    return PyGtk_New((GtkObject *)gtk_hseparator_new());
}

static PyObject *_wrap_gtk_vseparator_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_vseparator_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_vseparator_get_type());
}

static PyObject *_wrap_gtk_vseparator_new(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_vseparator_new"))
        return NULL;
    return PyGtk_New((GtkObject *)gtk_vseparator_new());
}

static PyObject *_wrap_gtk_progress_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_progress_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_progress_get_type());
}

static PyObject *_wrap_gtk_progress_set_show_text(PyObject *self, PyObject *args) {
    int show_text;
    PyObject *progress;

    if (!PyArg_ParseTuple(args, "O!i:gtk_progress_set_show_text", &PyGtk_Type, &progress, &show_text))
        return NULL;
    gtk_progress_set_show_text(GTK_PROGRESS(PyGtk_Get(progress)), show_text);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_progress_set_text_alignment(PyObject *self, PyObject *args) {
    double x_align, y_align;
    PyObject *progress;

    if (!PyArg_ParseTuple(args, "O!dd:gtk_progress_set_text_alignment", &PyGtk_Type, &progress, &x_align, &y_align))
        return NULL;
    gtk_progress_set_text_alignment(GTK_PROGRESS(PyGtk_Get(progress)), x_align, y_align);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_progress_set_format_string(PyObject *self, PyObject *args) {
    char *format;
    PyObject *progress;

    if (!PyArg_ParseTuple(args, "O!s:gtk_progress_set_format_string", &PyGtk_Type, &progress, &format))
        return NULL;
    gtk_progress_set_format_string(GTK_PROGRESS(PyGtk_Get(progress)), format);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_progress_set_adjustment(PyObject *self, PyObject *args) {
    PyObject *progress, *adjustment;

    if (!PyArg_ParseTuple(args, "O!O!:gtk_progress_set_adjustment", &PyGtk_Type, &progress, &PyGtk_Type, &adjustment))
        return NULL;
    gtk_progress_set_adjustment(GTK_PROGRESS(PyGtk_Get(progress)), GTK_ADJUSTMENT(PyGtk_Get(adjustment)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_progress_configure(PyObject *self, PyObject *args) {
    double value, min, max;
    PyObject *progress;

    if (!PyArg_ParseTuple(args, "O!ddd:gtk_progress_configure", &PyGtk_Type, &progress, &value, &min, &max))
        return NULL;
    gtk_progress_configure(GTK_PROGRESS(PyGtk_Get(progress)), value, min, max);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_progress_set_percentage(PyObject *self, PyObject *args) {
    double percentage;
    PyObject *progress;

    if (!PyArg_ParseTuple(args, "O!d:gtk_progress_set_percentage", &PyGtk_Type, &progress, &percentage))
        return NULL;
    gtk_progress_set_percentage(GTK_PROGRESS(PyGtk_Get(progress)), percentage);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_progress_set_value(PyObject *self, PyObject *args) {
    double value;
    PyObject *progress;

    if (!PyArg_ParseTuple(args, "O!d:gtk_progress_set_value", &PyGtk_Type, &progress, &value))
        return NULL;
    gtk_progress_set_value(GTK_PROGRESS(PyGtk_Get(progress)), value);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_progress_get_value(PyObject *self, PyObject *args) {
    PyObject *progress;

    if (!PyArg_ParseTuple(args, "O!:gtk_progress_get_value", &PyGtk_Type, &progress))
        return NULL;
    return PyFloat_FromDouble(gtk_progress_get_value(GTK_PROGRESS(PyGtk_Get(progress))));
}

static PyObject *_wrap_gtk_progress_set_activity_mode(PyObject *self, PyObject *args) {
    int activity_mode;
    PyObject *progress;

    if (!PyArg_ParseTuple(args, "O!i:gtk_progress_set_activity_mode", &PyGtk_Type, &progress, &activity_mode))
        return NULL;
    gtk_progress_set_activity_mode(GTK_PROGRESS(PyGtk_Get(progress)), activity_mode);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_progress_get_current_text(PyObject *self, PyObject *args) {
    PyObject *py_ret, *progress;
    char *ret;

    if (!PyArg_ParseTuple(args, "O!:gtk_progress_get_current_text", &PyGtk_Type, &progress))
        return NULL;
    ret = gtk_progress_get_current_text(GTK_PROGRESS(PyGtk_Get(progress)));
    py_ret = PyString_FromString(ret);
    g_free(ret);
    return py_ret;
}

static PyObject *_wrap_gtk_progress_get_text_from_value(PyObject *self, PyObject *args) {
    PyObject *py_ret, *progress;
    double value;
    char *ret;

    if (!PyArg_ParseTuple(args, "O!d:gtk_progress_get_text_from_value", &PyGtk_Type, &progress, &value))
        return NULL;
    ret = gtk_progress_get_text_from_value(GTK_PROGRESS(PyGtk_Get(progress)), value);
    py_ret = PyString_FromString(ret);
    g_free(ret);
    return py_ret;
}

static PyObject *_wrap_gtk_progress_get_current_percentage(PyObject *self, PyObject *args) {
    PyObject *progress;

    if (!PyArg_ParseTuple(args, "O!:gtk_progress_get_current_percentage", &PyGtk_Type, &progress))
        return NULL;
    return PyFloat_FromDouble(gtk_progress_get_current_percentage(GTK_PROGRESS(PyGtk_Get(progress))));
}

static PyObject *_wrap_gtk_progress_get_percentage_from_value(PyObject *self, PyObject *args) {
    double value;
    PyObject *progress;

    if (!PyArg_ParseTuple(args, "O!d:gtk_progress_get_percentage_from_value", &PyGtk_Type, &progress, &value))
        return NULL;
    return PyFloat_FromDouble(gtk_progress_get_percentage_from_value(GTK_PROGRESS(PyGtk_Get(progress)), value));
}

static PyObject *_wrap_gtk_progress_bar_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_progress_bar_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_progress_bar_get_type());
}

static PyObject *_wrap_gtk_progress_bar_new(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_progress_bar_new"))
        return NULL;
    return PyGtk_New((GtkObject *)gtk_progress_bar_new());
}

static PyObject *_wrap_gtk_progress_bar_new_with_adjustment(PyObject *self, PyObject *args) {
    PyObject *adjustment;

    if (!PyArg_ParseTuple(args, "O!:gtk_progress_bar_new_with_adjustment", &PyGtk_Type, &adjustment))
        return NULL;
    return PyGtk_New((GtkObject *)gtk_progress_bar_new_with_adjustment(GTK_ADJUSTMENT(PyGtk_Get(adjustment))));
}

static PyObject *_wrap_gtk_progress_bar_set_bar_style(PyObject *self, PyObject *args) {
    GtkProgressBarStyle style;
    PyObject *pbar, *py_style;

    if (!PyArg_ParseTuple(args, "O!O:gtk_progress_bar_set_bar_style", &PyGtk_Type, &pbar, &py_style))
        return NULL;
    if (PyGtkEnum_get_value(GTK_TYPE_PROGRESS_BAR_STYLE, py_style, (gint *)&style))
        return NULL;
    gtk_progress_bar_set_bar_style(GTK_PROGRESS_BAR(PyGtk_Get(pbar)), style);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_progress_bar_set_discrete_blocks(PyObject *self, PyObject *args) {
    int blocks;
    PyObject *pbar;

    if (!PyArg_ParseTuple(args, "O!i:gtk_progress_bar_set_discrete_blocks", &PyGtk_Type, &pbar, &blocks))
        return NULL;
    gtk_progress_bar_set_discrete_blocks(GTK_PROGRESS_BAR(PyGtk_Get(pbar)), blocks);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_progress_bar_set_activity_step(PyObject *self, PyObject *args) {
    int step;
    PyObject *pbar;

    if (!PyArg_ParseTuple(args, "O!i:gtk_progress_bar_set_activity_step", &PyGtk_Type, &pbar, &step))
        return NULL;
    gtk_progress_bar_set_activity_step(GTK_PROGRESS_BAR(PyGtk_Get(pbar)), step);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_progress_bar_set_activity_blocks(PyObject *self, PyObject *args) {
    int blocks;
    PyObject *pbar;

    if (!PyArg_ParseTuple(args, "O!i:gtk_progress_bar_set_activity_blocks", &PyGtk_Type, &pbar, &blocks))
        return NULL;
    gtk_progress_bar_set_activity_blocks(GTK_PROGRESS_BAR(PyGtk_Get(pbar)), blocks);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_progress_bar_set_orientation(PyObject *self, PyObject *args) {
    GtkProgressBarOrientation orientation;
    PyObject *pbar, *py_orientation;

    if (!PyArg_ParseTuple(args, "O!O:gtk_progress_bar_set_orientation", &PyGtk_Type, &pbar, &py_orientation))
        return NULL;
    if (PyGtkEnum_get_value(GTK_TYPE_PROGRESS_BAR_ORIENTATION, py_orientation, (gint *)&orientation))
        return NULL;
    gtk_progress_bar_set_orientation(GTK_PROGRESS_BAR(PyGtk_Get(pbar)), orientation);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_progress_bar_update(PyObject *self, PyObject *args) {
    double percentage;
    PyObject *progress_bar;

    if (!PyArg_ParseTuple(args, "O!d:gtk_progress_bar_update", &PyGtk_Type, &progress_bar, &percentage))
        return NULL;
    gtk_progress_bar_update(GTK_PROGRESS_BAR(PyGtk_Get(progress_bar)), percentage);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_pixmap_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_pixmap_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_pixmap_get_type());
}

static PyObject *_wrap_gtk_pixmap_new(PyObject *self, PyObject *args) {
    GdkBitmap *mask = NULL;
    PyObject *pixmap, *py_mask = Py_None;

    if (!PyArg_ParseTuple(args, "O!O:gtk_pixmap_new", &PyGdkWindow_Type, &pixmap, &py_mask))
        return NULL;
    if (PyGdkBitmap_Check(py_mask))
        mask = PyGdkWindow_Get(py_mask);
    else if (py_mask != Py_None) {
        PyErr_SetString(PyExc_TypeError, "mask argument must be a GdkBitmap or None");
	return NULL;
    }
    return PyGtk_New((GtkObject *)gtk_pixmap_new(PyGdkWindow_Get(pixmap), mask));
}

static PyObject *_wrap_gtk_pixmap_set(PyObject *self, PyObject *args) {
    PyObject *pixmap, *val, *mask;

    if (!PyArg_ParseTuple(args, "O!O!O!:gtk_pixmap_set", &PyGtk_Type, &pixmap, &PyGdkWindow_Type, &val, &PyGdkWindow_Type, &mask))
        return NULL;
    gtk_pixmap_set(GTK_PIXMAP(PyGtk_Get(pixmap)), PyGdkWindow_Get(val), PyGdkWindow_Get(mask));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_pixmap_set_build_insensitive(PyObject *self, PyObject *args) {
    int build;
    PyObject *pixmap;

    if (!PyArg_ParseTuple(args, "O!i:gtk_pixmap_set_build_insensitive", &PyGtk_Type, &pixmap, &build))
        return NULL;
    gtk_pixmap_set_build_insensitive(GTK_PIXMAP(PyGtk_Get(pixmap)), build);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_color_selection_dialog_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_color_selection_dialog_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_color_selection_dialog_get_type());
}

static PyObject *_wrap_gtk_color_selection_dialog_get_colorsel(PyObject *self, PyObject *args) {
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_color_selection_dialog_get_colorsel", &PyGtk_Type, &obj))
        return NULL;
    return PyGtk_New((GtkObject *)GTK_COLOR_SELECTION_DIALOG(PyGtk_Get(obj))->colorsel);
}

static PyObject *_wrap_gtk_color_selection_dialog_get_main_vbox(PyObject *self, PyObject *args) {
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_color_selection_dialog_get_main_vbox", &PyGtk_Type, &obj))
        return NULL;
    return PyGtk_New((GtkObject *)GTK_COLOR_SELECTION_DIALOG(PyGtk_Get(obj))->main_vbox);
}

static PyObject *_wrap_gtk_color_selection_dialog_get_ok_button(PyObject *self, PyObject *args) {
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_color_selection_dialog_get_ok_button", &PyGtk_Type, &obj))
        return NULL;
    return PyGtk_New((GtkObject *)GTK_COLOR_SELECTION_DIALOG(PyGtk_Get(obj))->ok_button);
}

static PyObject *_wrap_gtk_color_selection_dialog_get_reset_button(PyObject *self, PyObject *args) {
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_color_selection_dialog_get_reset_button", &PyGtk_Type, &obj))
        return NULL;
    return PyGtk_New((GtkObject *)GTK_COLOR_SELECTION_DIALOG(PyGtk_Get(obj))->reset_button);
}

static PyObject *_wrap_gtk_color_selection_dialog_get_cancel_button(PyObject *self, PyObject *args) {
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_color_selection_dialog_get_cancel_button", &PyGtk_Type, &obj))
        return NULL;
    return PyGtk_New((GtkObject *)GTK_COLOR_SELECTION_DIALOG(PyGtk_Get(obj))->cancel_button);
}

static PyObject *_wrap_gtk_color_selection_dialog_get_help_button(PyObject *self, PyObject *args) {
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_color_selection_dialog_get_help_button", &PyGtk_Type, &obj))
        return NULL;
    return PyGtk_New((GtkObject *)GTK_COLOR_SELECTION_DIALOG(PyGtk_Get(obj))->help_button);
}

static PyObject *_wrap_gtk_color_selection_dialog_new(PyObject *self, PyObject *args) {
    char *title;

    if (!PyArg_ParseTuple(args, "s:gtk_color_selection_dialog_new", &title))
        return NULL;
    return PyGtk_New((GtkObject *)gtk_color_selection_dialog_new(title));
}

static PyObject *_wrap_gtk_color_selection_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_color_selection_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_color_selection_get_type());
}

static PyObject *_wrap_gtk_color_selection_new(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_color_selection_new"))
        return NULL;
    return PyGtk_New((GtkObject *)gtk_color_selection_new());
}

static PyObject *_wrap_gtk_color_selection_set_update_policy(PyObject *self, PyObject *args) {
    GtkUpdateType policy;
    PyObject *colorsel, *py_policy;

    if (!PyArg_ParseTuple(args, "O!O:gtk_color_selection_set_update_policy", &PyGtk_Type, &colorsel, &py_policy))
        return NULL;
    if (PyGtkEnum_get_value(GTK_TYPE_UPDATE_TYPE, py_policy, (gint *)&policy))
        return NULL;
    gtk_color_selection_set_update_policy(GTK_COLOR_SELECTION(PyGtk_Get(colorsel)), policy);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_color_selection_set_opacity(PyObject *self, PyObject *args) {
    int use_opacity;
    PyObject *colorsel;

    if (!PyArg_ParseTuple(args, "O!i:gtk_color_selection_set_opacity", &PyGtk_Type, &colorsel, &use_opacity))
        return NULL;
    gtk_color_selection_set_opacity(GTK_COLOR_SELECTION(PyGtk_Get(colorsel)), use_opacity);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_curve_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_curve_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_curve_get_type());
}

static PyObject *_wrap_gtk_curve_new(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_curve_new"))
        return NULL;
    return PyGtk_New((GtkObject *)gtk_curve_new());
}

static PyObject *_wrap_gtk_curve_reset(PyObject *self, PyObject *args) {
    PyObject *curve;

    if (!PyArg_ParseTuple(args, "O!:gtk_curve_reset", &PyGtk_Type, &curve))
        return NULL;
    gtk_curve_reset(GTK_CURVE(PyGtk_Get(curve)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_curve_set_gamma(PyObject *self, PyObject *args) {
    double gamma;
    PyObject *curve;

    if (!PyArg_ParseTuple(args, "O!d:gtk_curve_set_gamma", &PyGtk_Type, &curve, &gamma))
        return NULL;
    gtk_curve_set_gamma(GTK_CURVE(PyGtk_Get(curve)), gamma);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_curve_set_range(PyObject *self, PyObject *args) {
    double min_x, max_x, min_y, max_y;
    PyObject *curve;

    if (!PyArg_ParseTuple(args, "O!dddd:gtk_curve_set_range", &PyGtk_Type, &curve, &min_x, &max_x, &min_y, &max_y))
        return NULL;
    gtk_curve_set_range(GTK_CURVE(PyGtk_Get(curve)), min_x, max_x, min_y, max_y);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_curve_set_curve_type(PyObject *self, PyObject *args) {
    GtkCurveType type;
    PyObject *curve, *py_type;

    if (!PyArg_ParseTuple(args, "O!O:gtk_curve_set_curve_type", &PyGtk_Type, &curve, &py_type))
        return NULL;
    if (PyGtkEnum_get_value(GTK_TYPE_CURVE_TYPE, py_type, (gint *)&type))
        return NULL;
    gtk_curve_set_curve_type(GTK_CURVE(PyGtk_Get(curve)), type);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_gamma_curve_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_gamma_curve_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_gamma_curve_get_type());
}

static PyObject *_wrap_gtk_gamma_curve_get_table(PyObject *self, PyObject *args) {
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_gamma_curve_get_table", &PyGtk_Type, &obj))
        return NULL;
    return PyGtk_New((GtkObject *)GTK_GAMMA_CURVE(PyGtk_Get(obj))->table);
}

static PyObject *_wrap_gtk_gamma_curve_get_curve(PyObject *self, PyObject *args) {
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_gamma_curve_get_curve", &PyGtk_Type, &obj))
        return NULL;
    return PyGtk_New((GtkObject *)GTK_GAMMA_CURVE(PyGtk_Get(obj))->curve);
}

static PyObject *_wrap_gtk_gamma_curve_get_gamma(PyObject *self, PyObject *args) {
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_gamma_curve_get_gamma", &PyGtk_Type, &obj))
        return NULL;
    return PyFloat_FromDouble(GTK_GAMMA_CURVE(PyGtk_Get(obj))->gamma);
}

static PyObject *_wrap_gtk_gamma_curve_get_gamma_dialog(PyObject *self, PyObject *args) {
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_gamma_curve_get_gamma_dialog", &PyGtk_Type, &obj))
        return NULL;
    return PyGtk_New((GtkObject *)GTK_GAMMA_CURVE(PyGtk_Get(obj))->gamma_dialog);
}

static PyObject *_wrap_gtk_gamma_curve_get_gamma_text(PyObject *self, PyObject *args) {
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_gamma_curve_get_gamma_text", &PyGtk_Type, &obj))
        return NULL;
    return PyGtk_New((GtkObject *)GTK_GAMMA_CURVE(PyGtk_Get(obj))->gamma_text);
}

static PyObject *_wrap_gtk_gamma_curve_new(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_gamma_curve_new"))
        return NULL;
    return PyGtk_New((GtkObject *)gtk_gamma_curve_new());
}

static PyObject *_wrap_gtk_input_dialog_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_input_dialog_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_input_dialog_get_type());
}

static PyObject *_wrap_gtk_input_dialog_get_close_button(PyObject *self, PyObject *args) {
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_input_dialog_get_close_button", &PyGtk_Type, &obj))
        return NULL;
    return PyGtk_New((GtkObject *)GTK_INPUT_DIALOG(PyGtk_Get(obj))->close_button);
}

static PyObject *_wrap_gtk_input_dialog_get_save_button(PyObject *self, PyObject *args) {
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_input_dialog_get_save_button", &PyGtk_Type, &obj))
        return NULL;
    return PyGtk_New((GtkObject *)GTK_INPUT_DIALOG(PyGtk_Get(obj))->save_button);
}

static PyObject *_wrap_gtk_input_dialog_new(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_input_dialog_new"))
        return NULL;
    return PyGtk_New((GtkObject *)gtk_input_dialog_new());
}

static PyObject *_wrap_gtk_drawing_area_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_drawing_area_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_drawing_area_get_type());
}

static PyObject *_wrap_gtk_drawing_area_new(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_drawing_area_new"))
        return NULL;
    return PyGtk_New((GtkObject *)gtk_drawing_area_new());
}

static PyObject *_wrap_gtk_drawing_area_size(PyObject *self, PyObject *args) {
    int width, height;
    PyObject *darea;

    if (!PyArg_ParseTuple(args, "O!ii:gtk_drawing_area_size", &PyGtk_Type, &darea, &width, &height))
        return NULL;
    gtk_drawing_area_size(GTK_DRAWING_AREA(PyGtk_Get(darea)), width, height);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_file_selection_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_file_selection_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_file_selection_get_type());
}

static PyObject *_wrap_gtk_file_selection_get_dir_list(PyObject *self, PyObject *args) {
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_file_selection_get_dir_list", &PyGtk_Type, &obj))
        return NULL;
    return PyGtk_New((GtkObject *)GTK_FILE_SELECTION(PyGtk_Get(obj))->dir_list);
}

static PyObject *_wrap_gtk_file_selection_get_file_list(PyObject *self, PyObject *args) {
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_file_selection_get_file_list", &PyGtk_Type, &obj))
        return NULL;
    return PyGtk_New((GtkObject *)GTK_FILE_SELECTION(PyGtk_Get(obj))->file_list);
}

static PyObject *_wrap_gtk_file_selection_get_selection_entry(PyObject *self, PyObject *args) {
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_file_selection_get_selection_entry", &PyGtk_Type, &obj))
        return NULL;
    return PyGtk_New((GtkObject *)GTK_FILE_SELECTION(PyGtk_Get(obj))->selection_entry);
}

static PyObject *_wrap_gtk_file_selection_get_selection_text(PyObject *self, PyObject *args) {
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_file_selection_get_selection_text", &PyGtk_Type, &obj))
        return NULL;
    return PyGtk_New((GtkObject *)GTK_FILE_SELECTION(PyGtk_Get(obj))->selection_text);
}

static PyObject *_wrap_gtk_file_selection_get_main_vbox(PyObject *self, PyObject *args) {
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_file_selection_get_main_vbox", &PyGtk_Type, &obj))
        return NULL;
    return PyGtk_New((GtkObject *)GTK_FILE_SELECTION(PyGtk_Get(obj))->main_vbox);
}

static PyObject *_wrap_gtk_file_selection_get_ok_button(PyObject *self, PyObject *args) {
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_file_selection_get_ok_button", &PyGtk_Type, &obj))
        return NULL;
    return PyGtk_New((GtkObject *)GTK_FILE_SELECTION(PyGtk_Get(obj))->ok_button);
}

static PyObject *_wrap_gtk_file_selection_get_cancel_button(PyObject *self, PyObject *args) {
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_file_selection_get_cancel_button", &PyGtk_Type, &obj))
        return NULL;
    return PyGtk_New((GtkObject *)GTK_FILE_SELECTION(PyGtk_Get(obj))->cancel_button);
}

static PyObject *_wrap_gtk_file_selection_get_help_button(PyObject *self, PyObject *args) {
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_file_selection_get_help_button", &PyGtk_Type, &obj))
        return NULL;
    return PyGtk_New((GtkObject *)GTK_FILE_SELECTION(PyGtk_Get(obj))->help_button);
}

static PyObject *_wrap_gtk_file_selection_new(PyObject *self, PyObject *args) {
    char *title;

    if (!PyArg_ParseTuple(args, "s:gtk_file_selection_new", &title))
        return NULL;
    return PyGtk_New((GtkObject *)gtk_file_selection_new(title));
}

static PyObject *_wrap_gtk_file_selection_set_filename(PyObject *self, PyObject *args) {
    char *filename;
    PyObject *filesel;

    if (!PyArg_ParseTuple(args, "O!s:gtk_file_selection_set_filename", &PyGtk_Type, &filesel, &filename))
        return NULL;
    gtk_file_selection_set_filename(GTK_FILE_SELECTION(PyGtk_Get(filesel)), filename);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_file_selection_get_filename(PyObject *self, PyObject *args) {
    PyObject *filesel;

    if (!PyArg_ParseTuple(args, "O!:gtk_file_selection_get_filename", &PyGtk_Type, &filesel))
        return NULL;
    return PyString_FromString(gtk_file_selection_get_filename(GTK_FILE_SELECTION(PyGtk_Get(filesel))));
}

static PyObject *_wrap_gtk_file_selection_complete(PyObject *self, PyObject *args) {
    char *pattern;
    PyObject *filesel;

    if (!PyArg_ParseTuple(args, "O!s:gtk_file_selection_complete", &PyGtk_Type, &filesel, &pattern))
        return NULL;
    gtk_file_selection_complete(GTK_FILE_SELECTION(PyGtk_Get(filesel)), pattern);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_file_selection_show_fileop_buttons(PyObject *self, PyObject *args) {
    PyObject *filesel;

    if (!PyArg_ParseTuple(args, "O!:gtk_file_selection_show_fileop_buttons", &PyGtk_Type, &filesel))
        return NULL;
    gtk_file_selection_show_fileop_buttons(GTK_FILE_SELECTION(PyGtk_Get(filesel)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_file_selection_hide_fileop_buttons(PyObject *self, PyObject *args) {
    PyObject *filesel;

    if (!PyArg_ParseTuple(args, "O!:gtk_file_selection_hide_fileop_buttons", &PyGtk_Type, &filesel))
        return NULL;
    gtk_file_selection_hide_fileop_buttons(GTK_FILE_SELECTION(PyGtk_Get(filesel)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_font_selection_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_font_selection_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_font_selection_get_type());
}

static PyObject *_wrap_gtk_font_selection_new(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_font_selection_new"))
        return NULL;
    return PyGtk_New((GtkObject *)gtk_font_selection_new());
}

static PyObject *_wrap_gtk_font_selection_get_font_name(PyObject *self, PyObject *args) {
    PyObject *py_ret, *fontsel;
    char *ret;

    if (!PyArg_ParseTuple(args, "O!:gtk_font_selection_get_font_name", &PyGtk_Type, &fontsel))
        return NULL;
    ret = gtk_font_selection_get_font_name(GTK_FONT_SELECTION(PyGtk_Get(fontsel)));
    py_ret = PyString_FromString(ret);
    g_free(ret);
    return py_ret;
}

static PyObject *_wrap_gtk_font_selection_get_font(PyObject *self, PyObject *args) {
    PyObject *fontsel;

    if (!PyArg_ParseTuple(args, "O!:gtk_font_selection_get_font", &PyGtk_Type, &fontsel))
        return NULL;
    return PyGdkFont_New(gtk_font_selection_get_font(GTK_FONT_SELECTION(PyGtk_Get(fontsel))));
}

static PyObject *_wrap_gtk_font_selection_set_font_name(PyObject *self, PyObject *args) {
    char *fontname;
    PyObject *fontsel;

    if (!PyArg_ParseTuple(args, "O!s:gtk_font_selection_set_font_name", &PyGtk_Type, &fontsel, &fontname))
        return NULL;
    return PyInt_FromLong(gtk_font_selection_set_font_name(GTK_FONT_SELECTION(PyGtk_Get(fontsel)), fontname));
}

static PyObject *_wrap_gtk_font_selection_get_preview_text(PyObject *self, PyObject *args) {
    PyObject *fontsel;

    if (!PyArg_ParseTuple(args, "O!:gtk_font_selection_get_preview_text", &PyGtk_Type, &fontsel))
        return NULL;
    return PyString_FromString(gtk_font_selection_get_preview_text(GTK_FONT_SELECTION(PyGtk_Get(fontsel))));
}

static PyObject *_wrap_gtk_font_selection_set_preview_text(PyObject *self, PyObject *args) {
    char *text;
    PyObject *fontsel;

    if (!PyArg_ParseTuple(args, "O!s:gtk_font_selection_set_preview_text", &PyGtk_Type, &fontsel, &text))
        return NULL;
    gtk_font_selection_set_preview_text(GTK_FONT_SELECTION(PyGtk_Get(fontsel)), text);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_font_selection_dialog_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_font_selection_dialog_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_font_selection_dialog_get_type());
}

static PyObject *_wrap_gtk_font_selection_dialog_get_fontsel(PyObject *self, PyObject *args) {
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_font_selection_dialog_get_fontsel", &PyGtk_Type, &obj))
        return NULL;
    return PyGtk_New((GtkObject *)GTK_FONT_SELECTION_DIALOG(PyGtk_Get(obj))->fontsel);
}

static PyObject *_wrap_gtk_font_selection_dialog_get_main_vbox(PyObject *self, PyObject *args) {
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_font_selection_dialog_get_main_vbox", &PyGtk_Type, &obj))
        return NULL;
    return PyGtk_New((GtkObject *)GTK_FONT_SELECTION_DIALOG(PyGtk_Get(obj))->main_vbox);
}

static PyObject *_wrap_gtk_font_selection_dialog_get_action_area(PyObject *self, PyObject *args) {
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_font_selection_dialog_get_action_area", &PyGtk_Type, &obj))
        return NULL;
    return PyGtk_New((GtkObject *)GTK_FONT_SELECTION_DIALOG(PyGtk_Get(obj))->action_area);
}

static PyObject *_wrap_gtk_font_selection_dialog_get_ok_button(PyObject *self, PyObject *args) {
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_font_selection_dialog_get_ok_button", &PyGtk_Type, &obj))
        return NULL;
    return PyGtk_New((GtkObject *)GTK_FONT_SELECTION_DIALOG(PyGtk_Get(obj))->ok_button);
}

static PyObject *_wrap_gtk_font_selection_dialog_get_apply_button(PyObject *self, PyObject *args) {
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_font_selection_dialog_get_apply_button", &PyGtk_Type, &obj))
        return NULL;
    return PyGtk_New((GtkObject *)GTK_FONT_SELECTION_DIALOG(PyGtk_Get(obj))->apply_button);
}

static PyObject *_wrap_gtk_font_selection_dialog_get_cancel_button(PyObject *self, PyObject *args) {
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_font_selection_dialog_get_cancel_button", &PyGtk_Type, &obj))
        return NULL;
    return PyGtk_New((GtkObject *)GTK_FONT_SELECTION_DIALOG(PyGtk_Get(obj))->cancel_button);
}

static PyObject *_wrap_gtk_font_selection_dialog_new(PyObject *self, PyObject *args) {
    char *title;

    if (!PyArg_ParseTuple(args, "s:gtk_font_selection_dialog_new", &title))
        return NULL;
    return PyGtk_New((GtkObject *)gtk_font_selection_dialog_new(title));
}

static PyObject *_wrap_gtk_font_selection_dialog_get_font_name(PyObject *self, PyObject *args) {
    PyObject *py_ret, *fsd;
    char *ret;

    if (!PyArg_ParseTuple(args, "O!:gtk_font_selection_dialog_get_font_name", &PyGtk_Type, &fsd))
        return NULL;
    ret = gtk_font_selection_dialog_get_font_name(GTK_FONT_SELECTION_DIALOG(PyGtk_Get(fsd)));
    py_ret = PyString_FromString(ret);
    g_free(ret);
    return py_ret;
}

static PyObject *_wrap_gtk_font_selection_dialog_get_font(PyObject *self, PyObject *args) {
    PyObject *fsd;

    if (!PyArg_ParseTuple(args, "O!:gtk_font_selection_dialog_get_font", &PyGtk_Type, &fsd))
        return NULL;
    return PyGdkFont_New(gtk_font_selection_dialog_get_font(GTK_FONT_SELECTION_DIALOG(PyGtk_Get(fsd))));
}

static PyObject *_wrap_gtk_font_selection_dialog_set_font_name(PyObject *self, PyObject *args) {
    char *fontname;
    PyObject *fsd;

    if (!PyArg_ParseTuple(args, "O!s:gtk_font_selection_dialog_set_font_name", &PyGtk_Type, &fsd, &fontname))
        return NULL;
    return PyInt_FromLong(gtk_font_selection_dialog_set_font_name(GTK_FONT_SELECTION_DIALOG(PyGtk_Get(fsd)), fontname));
}

static PyObject *_wrap_gtk_font_selection_dialog_get_preview_text(PyObject *self, PyObject *args) {
    PyObject *fsd;

    if (!PyArg_ParseTuple(args, "O!:gtk_font_selection_dialog_get_preview_text", &PyGtk_Type, &fsd))
        return NULL;
    return PyString_FromString(gtk_font_selection_dialog_get_preview_text(GTK_FONT_SELECTION_DIALOG(PyGtk_Get(fsd))));
}

static PyObject *_wrap_gtk_font_selection_dialog_set_preview_text(PyObject *self, PyObject *args) {
    char *text;
    PyObject *fsd;

    if (!PyArg_ParseTuple(args, "O!s:gtk_font_selection_dialog_set_preview_text", &PyGtk_Type, &fsd, &text))
        return NULL;
    gtk_font_selection_dialog_set_preview_text(GTK_FONT_SELECTION_DIALOG(PyGtk_Get(fsd)), text);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_preview_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_preview_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_preview_get_type());
}

static PyObject *_wrap_gtk_preview_new(PyObject *self, PyObject *args) {
    GtkPreviewType type;
    PyObject *py_type;

    if (!PyArg_ParseTuple(args, "O:gtk_preview_new", &py_type))
        return NULL;
    if (PyGtkEnum_get_value(GTK_TYPE_PREVIEW_TYPE, py_type, (gint *)&type))
        return NULL;
    return PyGtk_New((GtkObject *)gtk_preview_new(type));
}

static PyObject *_wrap_gtk_preview_size(PyObject *self, PyObject *args) {
    int width, height;
    PyObject *preview;

    if (!PyArg_ParseTuple(args, "O!ii:gtk_preview_size", &PyGtk_Type, &preview, &width, &height))
        return NULL;
    gtk_preview_size(GTK_PREVIEW(PyGtk_Get(preview)), width, height);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_preview_put(PyObject *self, PyObject *args) {
    int srcx, srcy, destx, desty, width, height;
    PyObject *preview, *window, *gc;

    if (!PyArg_ParseTuple(args, "O!O!O!iiiiii:gtk_preview_put", &PyGtk_Type, &preview, &PyGdkWindow_Type, &window, &PyGdkGC_Type, &gc, &srcx, &srcy, &destx, &desty, &width, &height))
        return NULL;
    gtk_preview_put(GTK_PREVIEW(PyGtk_Get(preview)), PyGdkWindow_Get(window), PyGdkGC_Get(gc), srcx, srcy, destx, desty, width, height);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_preview_set_expand(PyObject *self, PyObject *args) {
    int expand;
    PyObject *preview;

    if (!PyArg_ParseTuple(args, "O!i:gtk_preview_set_expand", &PyGtk_Type, &preview, &expand))
        return NULL;
    gtk_preview_set_expand(GTK_PREVIEW(PyGtk_Get(preview)), expand);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_preview_set_gamma(PyObject *self, PyObject *args) {
    double gamma;

    if (!PyArg_ParseTuple(args, "d:gtk_preview_set_gamma", &gamma))
        return NULL;
    gtk_preview_set_gamma(gamma);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_preview_set_color_cube(PyObject *self, PyObject *args) {
    int nred_shades, ngreen_shades, nblue_shades, ngray_shades;

    if (!PyArg_ParseTuple(args, "iiii:gtk_preview_set_color_cube", &nred_shades, &ngreen_shades, &nblue_shades, &ngray_shades))
        return NULL;
    gtk_preview_set_color_cube(nred_shades, ngreen_shades, nblue_shades, ngray_shades);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_preview_set_install_cmap(PyObject *self, PyObject *args) {
    int install_cmap;

    if (!PyArg_ParseTuple(args, "i:gtk_preview_set_install_cmap", &install_cmap))
        return NULL;
    gtk_preview_set_install_cmap(install_cmap);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_preview_set_reserved(PyObject *self, PyObject *args) {
    int nreserved;

    if (!PyArg_ParseTuple(args, "i:gtk_preview_set_reserved", &nreserved))
        return NULL;
    gtk_preview_set_reserved(nreserved);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_preview_set_dither(PyObject *self, PyObject *args) {
    GdkRgbDither dither;
    PyObject *preview, *py_dither;

    if (!PyArg_ParseTuple(args, "O!O:gtk_preview_set_dither", &PyGtk_Type, &preview, &py_dither))
        return NULL;
    if (PyGtkEnum_get_value(GTK_TYPE_GDK_RGB_DITHER, py_dither, (gint *)&dither))
        return NULL;
    gtk_preview_set_dither(GTK_PREVIEW(PyGtk_Get(preview)), dither);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_calendar_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_calendar_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_calendar_get_type());
}

static PyObject *_wrap_gtk_calendar_new(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_calendar_new"))
        return NULL;
    return PyGtk_New((GtkObject *)gtk_calendar_new());
}

static PyObject *_wrap_gtk_calendar_select_month(PyObject *self, PyObject *args) {
    int month, year;
    PyObject *calendar;

    if (!PyArg_ParseTuple(args, "O!ii:gtk_calendar_select_month", &PyGtk_Type, &calendar, &month, &year))
        return NULL;
    return PyInt_FromLong(gtk_calendar_select_month(GTK_CALENDAR(PyGtk_Get(calendar)), month, year));
}

static PyObject *_wrap_gtk_calendar_select_day(PyObject *self, PyObject *args) {
    int day;
    PyObject *calendar;

    if (!PyArg_ParseTuple(args, "O!i:gtk_calendar_select_day", &PyGtk_Type, &calendar, &day))
        return NULL;
    gtk_calendar_select_day(GTK_CALENDAR(PyGtk_Get(calendar)), day);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_calendar_mark_day(PyObject *self, PyObject *args) {
    int day;
    PyObject *calendar;

    if (!PyArg_ParseTuple(args, "O!i:gtk_calendar_mark_day", &PyGtk_Type, &calendar, &day))
        return NULL;
    return PyInt_FromLong(gtk_calendar_mark_day(GTK_CALENDAR(PyGtk_Get(calendar)), day));
}

static PyObject *_wrap_gtk_calendar_unmark_day(PyObject *self, PyObject *args) {
    int day;
    PyObject *calendar;

    if (!PyArg_ParseTuple(args, "O!i:gtk_calendar_unmark_day", &PyGtk_Type, &calendar, &day))
        return NULL;
    return PyInt_FromLong(gtk_calendar_unmark_day(GTK_CALENDAR(PyGtk_Get(calendar)), day));
}

static PyObject *_wrap_gtk_calendar_clear_marks(PyObject *self, PyObject *args) {
    PyObject *calendar;

    if (!PyArg_ParseTuple(args, "O!:gtk_calendar_clear_marks", &PyGtk_Type, &calendar))
        return NULL;
    gtk_calendar_clear_marks(GTK_CALENDAR(PyGtk_Get(calendar)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_calendar_display_options(PyObject *self, PyObject *args) {
    GtkCalendarDisplayOptions flags;
    PyObject *calendar, *py_flags;

    if (!PyArg_ParseTuple(args, "O!O:gtk_calendar_display_options", &PyGtk_Type, &calendar, &py_flags))
        return NULL;
    if (PyGtkFlag_get_value(GTK_TYPE_CALENDAR_DISPLAY_OPTIONS, py_flags, (gint *)&flags))
        return NULL;
    gtk_calendar_display_options(GTK_CALENDAR(PyGtk_Get(calendar)), flags);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_calendar_freeze(PyObject *self, PyObject *args) {
    PyObject *calendar;

    if (!PyArg_ParseTuple(args, "O!:gtk_calendar_freeze", &PyGtk_Type, &calendar))
        return NULL;
    gtk_calendar_freeze(GTK_CALENDAR(PyGtk_Get(calendar)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_calendar_thaw(PyObject *self, PyObject *args) {
    PyObject *calendar;

    if (!PyArg_ParseTuple(args, "O!:gtk_calendar_thaw", &PyGtk_Type, &calendar))
        return NULL;
    gtk_calendar_thaw(GTK_CALENDAR(PyGtk_Get(calendar)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_tree_item_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_tree_item_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_tree_item_get_type());
}

static PyObject *_wrap_gtk_tree_item_get_subtree(PyObject *self, PyObject *args) {
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_tree_item_get_subtree", &PyGtk_Type, &obj))
        return NULL;
    return PyGtk_New((GtkObject *)GTK_TREE_ITEM(PyGtk_Get(obj))->subtree);
}

static PyObject *_wrap_gtk_tree_item_new(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_tree_item_new"))
        return NULL;
    return PyGtk_New((GtkObject *)gtk_tree_item_new());
}

static PyObject *_wrap_gtk_tree_item_new_with_label(PyObject *self, PyObject *args) {
    char *label;

    if (!PyArg_ParseTuple(args, "s:gtk_tree_item_new_with_label", &label))
        return NULL;
    return PyGtk_New((GtkObject *)gtk_tree_item_new_with_label(label));
}

static PyObject *_wrap_gtk_tree_item_set_subtree(PyObject *self, PyObject *args) {
    PyObject *tree_item, *subtree;

    if (!PyArg_ParseTuple(args, "O!O!:gtk_tree_item_set_subtree", &PyGtk_Type, &tree_item, &PyGtk_Type, &subtree))
        return NULL;
    gtk_tree_item_set_subtree(GTK_TREE_ITEM(PyGtk_Get(tree_item)), GTK_WIDGET(PyGtk_Get(subtree)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_tree_item_remove_subtree(PyObject *self, PyObject *args) {
    PyObject *tree_item;

    if (!PyArg_ParseTuple(args, "O!:gtk_tree_item_remove_subtree", &PyGtk_Type, &tree_item))
        return NULL;
    gtk_tree_item_remove_subtree(GTK_TREE_ITEM(PyGtk_Get(tree_item)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_tree_item_select(PyObject *self, PyObject *args) {
    PyObject *tree_item;

    if (!PyArg_ParseTuple(args, "O!:gtk_tree_item_select", &PyGtk_Type, &tree_item))
        return NULL;
    gtk_tree_item_select(GTK_TREE_ITEM(PyGtk_Get(tree_item)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_tree_item_deselect(PyObject *self, PyObject *args) {
    PyObject *tree_item;

    if (!PyArg_ParseTuple(args, "O!:gtk_tree_item_deselect", &PyGtk_Type, &tree_item))
        return NULL;
    gtk_tree_item_deselect(GTK_TREE_ITEM(PyGtk_Get(tree_item)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_tree_item_expand(PyObject *self, PyObject *args) {
    PyObject *tree_item;

    if (!PyArg_ParseTuple(args, "O!:gtk_tree_item_expand", &PyGtk_Type, &tree_item))
        return NULL;
    gtk_tree_item_expand(GTK_TREE_ITEM(PyGtk_Get(tree_item)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_tree_item_collapse(PyObject *self, PyObject *args) {
    PyObject *tree_item;

    if (!PyArg_ParseTuple(args, "O!:gtk_tree_item_collapse", &PyGtk_Type, &tree_item))
        return NULL;
    gtk_tree_item_collapse(GTK_TREE_ITEM(PyGtk_Get(tree_item)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_tree_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_tree_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_tree_get_type());
}

static PyObject *_wrap_gtk_tree_new(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_tree_new"))
        return NULL;
    return PyGtk_New((GtkObject *)gtk_tree_new());
}

static PyObject *_wrap_gtk_tree_append(PyObject *self, PyObject *args) {
    PyObject *tree, *child;

    if (!PyArg_ParseTuple(args, "O!O!:gtk_tree_append", &PyGtk_Type, &tree, &PyGtk_Type, &child))
        return NULL;
    gtk_tree_append(GTK_TREE(PyGtk_Get(tree)), GTK_WIDGET(PyGtk_Get(child)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_tree_prepend(PyObject *self, PyObject *args) {
    PyObject *tree, *child;

    if (!PyArg_ParseTuple(args, "O!O!:gtk_tree_prepend", &PyGtk_Type, &tree, &PyGtk_Type, &child))
        return NULL;
    gtk_tree_prepend(GTK_TREE(PyGtk_Get(tree)), GTK_WIDGET(PyGtk_Get(child)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_tree_insert(PyObject *self, PyObject *args) {
    int position;
    PyObject *tree, *child;

    if (!PyArg_ParseTuple(args, "O!O!i:gtk_tree_insert", &PyGtk_Type, &tree, &PyGtk_Type, &child, &position))
        return NULL;
    gtk_tree_insert(GTK_TREE(PyGtk_Get(tree)), GTK_WIDGET(PyGtk_Get(child)), position);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_tree_clear_items(PyObject *self, PyObject *args) {
    int start, end;
    PyObject *tree;

    if (!PyArg_ParseTuple(args, "O!ii:gtk_tree_clear_items", &PyGtk_Type, &tree, &start, &end))
        return NULL;
    gtk_tree_clear_items(GTK_TREE(PyGtk_Get(tree)), start, end);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_tree_select_item(PyObject *self, PyObject *args) {
    int item;
    PyObject *tree;

    if (!PyArg_ParseTuple(args, "O!i:gtk_tree_select_item", &PyGtk_Type, &tree, &item))
        return NULL;
    gtk_tree_select_item(GTK_TREE(PyGtk_Get(tree)), item);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_tree_unselect_item(PyObject *self, PyObject *args) {
    int item;
    PyObject *tree;

    if (!PyArg_ParseTuple(args, "O!i:gtk_tree_unselect_item", &PyGtk_Type, &tree, &item))
        return NULL;
    gtk_tree_unselect_item(GTK_TREE(PyGtk_Get(tree)), item);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_tree_select_child(PyObject *self, PyObject *args) {
    PyObject *tree, *child;

    if (!PyArg_ParseTuple(args, "O!O!:gtk_tree_select_child", &PyGtk_Type, &tree, &PyGtk_Type, &child))
        return NULL;
    gtk_tree_select_child(GTK_TREE(PyGtk_Get(tree)), GTK_WIDGET(PyGtk_Get(child)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_tree_unselect_child(PyObject *self, PyObject *args) {
    PyObject *tree, *child;

    if (!PyArg_ParseTuple(args, "O!O!:gtk_tree_unselect_child", &PyGtk_Type, &tree, &PyGtk_Type, &child))
        return NULL;
    gtk_tree_unselect_child(GTK_TREE(PyGtk_Get(tree)), GTK_WIDGET(PyGtk_Get(child)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_tree_child_position(PyObject *self, PyObject *args) {
    PyObject *tree, *child;

    if (!PyArg_ParseTuple(args, "O!O!:gtk_tree_child_position", &PyGtk_Type, &tree, &PyGtk_Type, &child))
        return NULL;
    return PyInt_FromLong(gtk_tree_child_position(GTK_TREE(PyGtk_Get(tree)), GTK_WIDGET(PyGtk_Get(child))));
}

static PyObject *_wrap_gtk_tree_set_selection_mode(PyObject *self, PyObject *args) {
    GtkSelectionMode mode;
    PyObject *tree, *py_mode;

    if (!PyArg_ParseTuple(args, "O!O:gtk_tree_set_selection_mode", &PyGtk_Type, &tree, &py_mode))
        return NULL;
    if (PyGtkEnum_get_value(GTK_TYPE_SELECTION_MODE, py_mode, (gint *)&mode))
        return NULL;
    gtk_tree_set_selection_mode(GTK_TREE(PyGtk_Get(tree)), mode);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_tree_set_view_mode(PyObject *self, PyObject *args) {
    GtkTreeViewMode mode;
    PyObject *tree, *py_mode;

    if (!PyArg_ParseTuple(args, "O!O:gtk_tree_set_view_mode", &PyGtk_Type, &tree, &py_mode))
        return NULL;
    if (PyGtkEnum_get_value(GTK_TYPE_TREE_VIEW_MODE, py_mode, (gint *)&mode))
        return NULL;
    gtk_tree_set_view_mode(GTK_TREE(PyGtk_Get(tree)), mode);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_tree_set_view_lines(PyObject *self, PyObject *args) {
    int flag;
    PyObject *tree;

    if (!PyArg_ParseTuple(args, "O!i:gtk_tree_set_view_lines", &PyGtk_Type, &tree, &flag))
        return NULL;
    gtk_tree_set_view_lines(GTK_TREE(PyGtk_Get(tree)), flag);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_clist_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_clist_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_clist_get_type());
}

static PyObject *_wrap_gtk_clist_get_focus_row(PyObject *self, PyObject *args) {
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_clist_get_focus_row", &PyGtk_Type, &obj))
        return NULL;
    return PyInt_FromLong(GTK_CLIST(PyGtk_Get(obj))->focus_row);
}

static PyObject *_wrap_gtk_clist_get_rows(PyObject *self, PyObject *args) {
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_clist_get_rows", &PyGtk_Type, &obj))
        return NULL;
    return PyInt_FromLong(GTK_CLIST(PyGtk_Get(obj))->rows);
}

static PyObject *_wrap_gtk_clist_new(PyObject *self, PyObject *args) {
    int columns;

    if (!PyArg_ParseTuple(args, "i:gtk_clist_new", &columns))
        return NULL;
    return PyGtk_New((GtkObject *)gtk_clist_new(columns));
}

static PyObject *_wrap_gtk_clist_set_shadow_type(PyObject *self, PyObject *args) {
    GtkShadowType border;
    PyObject *clist, *py_border;

    if (!PyArg_ParseTuple(args, "O!O:gtk_clist_set_shadow_type", &PyGtk_Type, &clist, &py_border))
        return NULL;
    if (PyGtkEnum_get_value(GTK_TYPE_SHADOW_TYPE, py_border, (gint *)&border))
        return NULL;
    gtk_clist_set_shadow_type(GTK_CLIST(PyGtk_Get(clist)), border);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_clist_set_selection_mode(PyObject *self, PyObject *args) {
    GtkSelectionMode mode;
    PyObject *clist, *py_mode;

    if (!PyArg_ParseTuple(args, "O!O:gtk_clist_set_selection_mode", &PyGtk_Type, &clist, &py_mode))
        return NULL;
    if (PyGtkEnum_get_value(GTK_TYPE_SELECTION_MODE, py_mode, (gint *)&mode))
        return NULL;
    gtk_clist_set_selection_mode(GTK_CLIST(PyGtk_Get(clist)), mode);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_clist_set_reorderable(PyObject *self, PyObject *args) {
    int reorderable;
    PyObject *clist;

    if (!PyArg_ParseTuple(args, "O!i:gtk_clist_set_reorderable", &PyGtk_Type, &clist, &reorderable))
        return NULL;
    gtk_clist_set_reorderable(GTK_CLIST(PyGtk_Get(clist)), reorderable);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_clist_set_use_drag_icons(PyObject *self, PyObject *args) {
    int use_icons;
    PyObject *clist;

    if (!PyArg_ParseTuple(args, "O!i:gtk_clist_set_use_drag_icons", &PyGtk_Type, &clist, &use_icons))
        return NULL;
    gtk_clist_set_use_drag_icons(GTK_CLIST(PyGtk_Get(clist)), use_icons);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_clist_set_button_actions(PyObject *self, PyObject *args) {
    int button, button_actions;
    PyObject *clist;

    if (!PyArg_ParseTuple(args, "O!ii:gtk_clist_set_button_actions", &PyGtk_Type, &clist, &button, &button_actions))
        return NULL;
    gtk_clist_set_button_actions(GTK_CLIST(PyGtk_Get(clist)), button, button_actions);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_clist_set_hadjustment(PyObject *self, PyObject *args) {
    PyObject *clist, *adjustment;

    if (!PyArg_ParseTuple(args, "O!O!:gtk_clist_set_hadjustment", &PyGtk_Type, &clist, &PyGtk_Type, &adjustment))
        return NULL;
    gtk_clist_set_hadjustment(GTK_CLIST(PyGtk_Get(clist)), GTK_ADJUSTMENT(PyGtk_Get(adjustment)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_clist_set_vadjustment(PyObject *self, PyObject *args) {
    PyObject *clist, *adjustment;

    if (!PyArg_ParseTuple(args, "O!O!:gtk_clist_set_vadjustment", &PyGtk_Type, &clist, &PyGtk_Type, &adjustment))
        return NULL;
    gtk_clist_set_vadjustment(GTK_CLIST(PyGtk_Get(clist)), GTK_ADJUSTMENT(PyGtk_Get(adjustment)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_clist_get_hadjustment(PyObject *self, PyObject *args) {
    PyObject *clist;

    if (!PyArg_ParseTuple(args, "O!:gtk_clist_get_hadjustment", &PyGtk_Type, &clist))
        return NULL;
    return PyGtk_New((GtkObject *)gtk_clist_get_hadjustment(GTK_CLIST(PyGtk_Get(clist))));
}

static PyObject *_wrap_gtk_clist_get_vadjustment(PyObject *self, PyObject *args) {
    PyObject *clist;

    if (!PyArg_ParseTuple(args, "O!:gtk_clist_get_vadjustment", &PyGtk_Type, &clist))
        return NULL;
    return PyGtk_New((GtkObject *)gtk_clist_get_vadjustment(GTK_CLIST(PyGtk_Get(clist))));
}

static PyObject *_wrap_gtk_clist_freeze(PyObject *self, PyObject *args) {
    PyObject *clist;

    if (!PyArg_ParseTuple(args, "O!:gtk_clist_freeze", &PyGtk_Type, &clist))
        return NULL;
    gtk_clist_freeze(GTK_CLIST(PyGtk_Get(clist)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_clist_thaw(PyObject *self, PyObject *args) {
    PyObject *clist;

    if (!PyArg_ParseTuple(args, "O!:gtk_clist_thaw", &PyGtk_Type, &clist))
        return NULL;
    gtk_clist_thaw(GTK_CLIST(PyGtk_Get(clist)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_clist_column_titles_show(PyObject *self, PyObject *args) {
    PyObject *clist;

    if (!PyArg_ParseTuple(args, "O!:gtk_clist_column_titles_show", &PyGtk_Type, &clist))
        return NULL;
    gtk_clist_column_titles_show(GTK_CLIST(PyGtk_Get(clist)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_clist_column_titles_hide(PyObject *self, PyObject *args) {
    PyObject *clist;

    if (!PyArg_ParseTuple(args, "O!:gtk_clist_column_titles_hide", &PyGtk_Type, &clist))
        return NULL;
    gtk_clist_column_titles_hide(GTK_CLIST(PyGtk_Get(clist)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_clist_column_title_active(PyObject *self, PyObject *args) {
    int column;
    PyObject *clist;

    if (!PyArg_ParseTuple(args, "O!i:gtk_clist_column_title_active", &PyGtk_Type, &clist, &column))
        return NULL;
    gtk_clist_column_title_active(GTK_CLIST(PyGtk_Get(clist)), column);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_clist_column_title_passive(PyObject *self, PyObject *args) {
    int column;
    PyObject *clist;

    if (!PyArg_ParseTuple(args, "O!i:gtk_clist_column_title_passive", &PyGtk_Type, &clist, &column))
        return NULL;
    gtk_clist_column_title_passive(GTK_CLIST(PyGtk_Get(clist)), column);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_clist_column_titles_active(PyObject *self, PyObject *args) {
    PyObject *clist;

    if (!PyArg_ParseTuple(args, "O!:gtk_clist_column_titles_active", &PyGtk_Type, &clist))
        return NULL;
    gtk_clist_column_titles_active(GTK_CLIST(PyGtk_Get(clist)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_clist_column_titles_passive(PyObject *self, PyObject *args) {
    PyObject *clist;

    if (!PyArg_ParseTuple(args, "O!:gtk_clist_column_titles_passive", &PyGtk_Type, &clist))
        return NULL;
    gtk_clist_column_titles_passive(GTK_CLIST(PyGtk_Get(clist)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_clist_set_column_title(PyObject *self, PyObject *args) {
    int column;
    char *title;
    PyObject *clist;

    if (!PyArg_ParseTuple(args, "O!is:gtk_clist_set_column_title", &PyGtk_Type, &clist, &column, &title))
        return NULL;
    gtk_clist_set_column_title(GTK_CLIST(PyGtk_Get(clist)), column, title);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_clist_get_column_title(PyObject *self, PyObject *args) {
    int column;
    PyObject *clist;

    if (!PyArg_ParseTuple(args, "O!i:gtk_clist_get_column_title", &PyGtk_Type, &clist, &column))
        return NULL;
    return PyString_FromString(gtk_clist_get_column_title(GTK_CLIST(PyGtk_Get(clist)), column));
}

static PyObject *_wrap_gtk_clist_set_column_widget(PyObject *self, PyObject *args) {
    int column;
    PyObject *clist, *widget;

    if (!PyArg_ParseTuple(args, "O!iO!:gtk_clist_set_column_widget", &PyGtk_Type, &clist, &column, &PyGtk_Type, &widget))
        return NULL;
    gtk_clist_set_column_widget(GTK_CLIST(PyGtk_Get(clist)), column, GTK_WIDGET(PyGtk_Get(widget)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_clist_get_column_widget(PyObject *self, PyObject *args) {
    int column;
    PyObject *clist;

    if (!PyArg_ParseTuple(args, "O!i:gtk_clist_get_column_widget", &PyGtk_Type, &clist, &column))
        return NULL;
    return PyGtk_New((GtkObject *)gtk_clist_get_column_widget(GTK_CLIST(PyGtk_Get(clist)), column));
}

static PyObject *_wrap_gtk_clist_set_column_justification(PyObject *self, PyObject *args) {
    PyObject *clist, *py_justification;
    GtkJustification justification;
    int column;

    if (!PyArg_ParseTuple(args, "O!iO:gtk_clist_set_column_justification", &PyGtk_Type, &clist, &column, &py_justification))
        return NULL;
    if (PyGtkEnum_get_value(GTK_TYPE_JUSTIFICATION, py_justification, (gint *)&justification))
        return NULL;
    gtk_clist_set_column_justification(GTK_CLIST(PyGtk_Get(clist)), column, justification);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_clist_set_column_visibility(PyObject *self, PyObject *args) {
    int column, visible;
    PyObject *clist;

    if (!PyArg_ParseTuple(args, "O!ii:gtk_clist_set_column_visibility", &PyGtk_Type, &clist, &column, &visible))
        return NULL;
    gtk_clist_set_column_visibility(GTK_CLIST(PyGtk_Get(clist)), column, visible);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_clist_set_column_resizeable(PyObject *self, PyObject *args) {
    int column, resizeable;
    PyObject *clist;

    if (!PyArg_ParseTuple(args, "O!ii:gtk_clist_set_column_resizeable", &PyGtk_Type, &clist, &column, &resizeable))
        return NULL;
    gtk_clist_set_column_resizeable(GTK_CLIST(PyGtk_Get(clist)), column, resizeable);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_clist_set_column_auto_resize(PyObject *self, PyObject *args) {
    int column, auto_resize;
    PyObject *clist;

    if (!PyArg_ParseTuple(args, "O!ii:gtk_clist_set_column_auto_resize", &PyGtk_Type, &clist, &column, &auto_resize))
        return NULL;
    gtk_clist_set_column_auto_resize(GTK_CLIST(PyGtk_Get(clist)), column, auto_resize);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_clist_columns_autosize(PyObject *self, PyObject *args) {
    PyObject *clist;

    if (!PyArg_ParseTuple(args, "O!:gtk_clist_columns_autosize", &PyGtk_Type, &clist))
        return NULL;
    return PyInt_FromLong(gtk_clist_columns_autosize(GTK_CLIST(PyGtk_Get(clist))));
}

static PyObject *_wrap_gtk_clist_optimal_column_width(PyObject *self, PyObject *args) {
    int column;
    PyObject *clist;

    if (!PyArg_ParseTuple(args, "O!i:gtk_clist_optimal_column_width", &PyGtk_Type, &clist, &column))
        return NULL;
    return PyInt_FromLong(gtk_clist_optimal_column_width(GTK_CLIST(PyGtk_Get(clist)), column));
}

static PyObject *_wrap_gtk_clist_set_column_width(PyObject *self, PyObject *args) {
    int column, width;
    PyObject *clist;

    if (!PyArg_ParseTuple(args, "O!ii:gtk_clist_set_column_width", &PyGtk_Type, &clist, &column, &width))
        return NULL;
    gtk_clist_set_column_width(GTK_CLIST(PyGtk_Get(clist)), column, width);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_clist_set_column_min_width(PyObject *self, PyObject *args) {
    int column, min_width;
    PyObject *clist;

    if (!PyArg_ParseTuple(args, "O!ii:gtk_clist_set_column_min_width", &PyGtk_Type, &clist, &column, &min_width))
        return NULL;
    gtk_clist_set_column_min_width(GTK_CLIST(PyGtk_Get(clist)), column, min_width);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_clist_set_column_max_width(PyObject *self, PyObject *args) {
    int column, max_width;
    PyObject *clist;

    if (!PyArg_ParseTuple(args, "O!ii:gtk_clist_set_column_max_width", &PyGtk_Type, &clist, &column, &max_width))
        return NULL;
    gtk_clist_set_column_max_width(GTK_CLIST(PyGtk_Get(clist)), column, max_width);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_clist_set_row_height(PyObject *self, PyObject *args) {
    int height;
    PyObject *clist;

    if (!PyArg_ParseTuple(args, "O!i:gtk_clist_set_row_height", &PyGtk_Type, &clist, &height))
        return NULL;
    gtk_clist_set_row_height(GTK_CLIST(PyGtk_Get(clist)), height);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_clist_moveto(PyObject *self, PyObject *args) {
    PyObject *clist;
    double row_align, column_align;
    int row, column;

    if (!PyArg_ParseTuple(args, "O!iidd:gtk_clist_moveto", &PyGtk_Type, &clist, &row, &column, &row_align, &column_align))
        return NULL;
    gtk_clist_moveto(GTK_CLIST(PyGtk_Get(clist)), row, column, row_align, column_align);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_clist_row_is_visible(PyObject *self, PyObject *args) {
    int row;
    PyObject *clist;

    if (!PyArg_ParseTuple(args, "O!i:gtk_clist_row_is_visible", &PyGtk_Type, &clist, &row))
        return NULL;
    return PyInt_FromLong(gtk_clist_row_is_visible(GTK_CLIST(PyGtk_Get(clist)), row));
}

static PyObject *_wrap_gtk_clist_get_cell_type(PyObject *self, PyObject *args) {
    int row, column;
    PyObject *clist;

    if (!PyArg_ParseTuple(args, "O!ii:gtk_clist_get_cell_type", &PyGtk_Type, &clist, &row, &column))
        return NULL;
    return PyInt_FromLong(gtk_clist_get_cell_type(GTK_CLIST(PyGtk_Get(clist)), row, column));
}

static PyObject *_wrap_gtk_clist_set_text(PyObject *self, PyObject *args) {
    int row, column;
    char *text;
    PyObject *clist;

    if (!PyArg_ParseTuple(args, "O!iis:gtk_clist_set_text", &PyGtk_Type, &clist, &row, &column, &text))
        return NULL;
    gtk_clist_set_text(GTK_CLIST(PyGtk_Get(clist)), row, column, text);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_clist_set_pixmap(PyObject *self, PyObject *args) {
    int row, col;
    GdkBitmap *mask = NULL;
    PyObject *clist, *pixmap, *py_mask = Py_None;

    if (!PyArg_ParseTuple(args, "O!iiO!O:gtk_clist_set_pixmap", &PyGtk_Type, &clist, &row, &col, &PyGdkWindow_Type, &pixmap, &py_mask))
        return NULL;
    if (PyGdkBitmap_Check(py_mask))
        mask = PyGdkWindow_Get(py_mask);
    else if (py_mask != Py_None) {
        PyErr_SetString(PyExc_TypeError, "mask argument must be a GdkBitmap or None");
	return NULL;
    }
    gtk_clist_set_pixmap(GTK_CLIST(PyGtk_Get(clist)), row, col, PyGdkWindow_Get(pixmap), mask);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_clist_set_pixtext(PyObject *self, PyObject *args) {
    PyObject *clist, *pixmap, *mask;
    char *text;
    int row, col, spacing;

    if (!PyArg_ParseTuple(args, "O!iisiO!O!:gtk_clist_set_pixtext", &PyGtk_Type, &clist, &row, &col, &text, &spacing, &PyGdkWindow_Type, &pixmap, &PyGdkWindow_Type, &mask))
        return NULL;
    gtk_clist_set_pixtext(GTK_CLIST(PyGtk_Get(clist)), row, col, text, spacing, PyGdkWindow_Get(pixmap), PyGdkWindow_Get(mask));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_clist_set_foreground(PyObject *self, PyObject *args) {
    int row;
    PyObject *clist, *color;

    if (!PyArg_ParseTuple(args, "O!iO!:gtk_clist_set_foreground", &PyGtk_Type, &clist, &row, &PyGdkColor_Type, &color))
        return NULL;
    gtk_clist_set_foreground(GTK_CLIST(PyGtk_Get(clist)), row, PyGdkColor_Get(color));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_clist_set_background(PyObject *self, PyObject *args) {
    int row;
    PyObject *clist, *color;

    if (!PyArg_ParseTuple(args, "O!iO!:gtk_clist_set_background", &PyGtk_Type, &clist, &row, &PyGdkColor_Type, &color))
        return NULL;
    gtk_clist_set_background(GTK_CLIST(PyGtk_Get(clist)), row, PyGdkColor_Get(color));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_clist_set_cell_style(PyObject *self, PyObject *args) {
    int row, column;
    PyObject *clist, *style;

    if (!PyArg_ParseTuple(args, "O!iiO!:gtk_clist_set_cell_style", &PyGtk_Type, &clist, &row, &column, &PyGtkStyle_Type, &style))
        return NULL;
    gtk_clist_set_cell_style(GTK_CLIST(PyGtk_Get(clist)), row, column, PyGtkStyle_Get(style));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_clist_get_cell_style(PyObject *self, PyObject *args) {
    int row, column;
    PyObject *clist;

    if (!PyArg_ParseTuple(args, "O!ii:gtk_clist_get_cell_style", &PyGtk_Type, &clist, &row, &column))
        return NULL;
    return PyGtkStyle_New(gtk_clist_get_cell_style(GTK_CLIST(PyGtk_Get(clist)), row, column));
}

static PyObject *_wrap_gtk_clist_set_row_style(PyObject *self, PyObject *args) {
    int row;
    PyObject *clist, *style;

    if (!PyArg_ParseTuple(args, "O!iO!:gtk_clist_set_row_style", &PyGtk_Type, &clist, &row, &PyGtkStyle_Type, &style))
        return NULL;
    gtk_clist_set_row_style(GTK_CLIST(PyGtk_Get(clist)), row, PyGtkStyle_Get(style));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_clist_get_row_style(PyObject *self, PyObject *args) {
    int row;
    PyObject *clist;

    if (!PyArg_ParseTuple(args, "O!i:gtk_clist_get_row_style", &PyGtk_Type, &clist, &row))
        return NULL;
    return PyGtkStyle_New(gtk_clist_get_row_style(GTK_CLIST(PyGtk_Get(clist)), row));
}

static PyObject *_wrap_gtk_clist_set_shift(PyObject *self, PyObject *args) {
    int row, column, vertical, horizontal;
    PyObject *clist;

    if (!PyArg_ParseTuple(args, "O!iiii:gtk_clist_set_shift", &PyGtk_Type, &clist, &row, &column, &vertical, &horizontal))
        return NULL;
    gtk_clist_set_shift(GTK_CLIST(PyGtk_Get(clist)), row, column, vertical, horizontal);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_clist_set_selectable(PyObject *self, PyObject *args) {
    int row, selectable;
    PyObject *clist;

    if (!PyArg_ParseTuple(args, "O!ii:gtk_clist_set_selectable", &PyGtk_Type, &clist, &row, &selectable))
        return NULL;
    gtk_clist_set_selectable(GTK_CLIST(PyGtk_Get(clist)), row, selectable);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_clist_get_selectable(PyObject *self, PyObject *args) {
    int row;
    PyObject *clist;

    if (!PyArg_ParseTuple(args, "O!i:gtk_clist_get_selectable", &PyGtk_Type, &clist, &row))
        return NULL;
    return PyInt_FromLong(gtk_clist_get_selectable(GTK_CLIST(PyGtk_Get(clist)), row));
}

static PyObject *_wrap_gtk_clist_remove(PyObject *self, PyObject *args) {
    int row;
    PyObject *clist;

    if (!PyArg_ParseTuple(args, "O!i:gtk_clist_remove", &PyGtk_Type, &clist, &row))
        return NULL;
    gtk_clist_remove(GTK_CLIST(PyGtk_Get(clist)), row);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_clist_select_row(PyObject *self, PyObject *args) {
    int row, column;
    PyObject *clist;

    if (!PyArg_ParseTuple(args, "O!ii:gtk_clist_select_row", &PyGtk_Type, &clist, &row, &column))
        return NULL;
    gtk_clist_select_row(GTK_CLIST(PyGtk_Get(clist)), row, column);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_clist_unselect_row(PyObject *self, PyObject *args) {
    int row, column;
    PyObject *clist;

    if (!PyArg_ParseTuple(args, "O!ii:gtk_clist_unselect_row", &PyGtk_Type, &clist, &row, &column))
        return NULL;
    gtk_clist_unselect_row(GTK_CLIST(PyGtk_Get(clist)), row, column);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_clist_undo_selection(PyObject *self, PyObject *args) {
    PyObject *clist;

    if (!PyArg_ParseTuple(args, "O!:gtk_clist_undo_selection", &PyGtk_Type, &clist))
        return NULL;
    gtk_clist_undo_selection(GTK_CLIST(PyGtk_Get(clist)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_clist_clear(PyObject *self, PyObject *args) {
    PyObject *clist;

    if (!PyArg_ParseTuple(args, "O!:gtk_clist_clear", &PyGtk_Type, &clist))
        return NULL;
    gtk_clist_clear(GTK_CLIST(PyGtk_Get(clist)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_clist_select_all(PyObject *self, PyObject *args) {
    PyObject *clist;

    if (!PyArg_ParseTuple(args, "O!:gtk_clist_select_all", &PyGtk_Type, &clist))
        return NULL;
    gtk_clist_select_all(GTK_CLIST(PyGtk_Get(clist)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_clist_unselect_all(PyObject *self, PyObject *args) {
    PyObject *clist;

    if (!PyArg_ParseTuple(args, "O!:gtk_clist_unselect_all", &PyGtk_Type, &clist))
        return NULL;
    gtk_clist_unselect_all(GTK_CLIST(PyGtk_Get(clist)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_clist_swap_rows(PyObject *self, PyObject *args) {
    int row1, row2;
    PyObject *clist;

    if (!PyArg_ParseTuple(args, "O!ii:gtk_clist_swap_rows", &PyGtk_Type, &clist, &row1, &row2))
        return NULL;
    gtk_clist_swap_rows(GTK_CLIST(PyGtk_Get(clist)), row1, row2);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_clist_row_move(PyObject *self, PyObject *args) {
    int source_row, dest_row;
    PyObject *clist;

    if (!PyArg_ParseTuple(args, "O!ii:gtk_clist_row_move", &PyGtk_Type, &clist, &source_row, &dest_row))
        return NULL;
    gtk_clist_row_move(GTK_CLIST(PyGtk_Get(clist)), source_row, dest_row);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_clist_set_sort_column(PyObject *self, PyObject *args) {
    int column;
    PyObject *clist;

    if (!PyArg_ParseTuple(args, "O!i:gtk_clist_set_sort_column", &PyGtk_Type, &clist, &column))
        return NULL;
    gtk_clist_set_sort_column(GTK_CLIST(PyGtk_Get(clist)), column);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_clist_set_sort_type(PyObject *self, PyObject *args) {
    GtkSortType sort_type;
    PyObject *clist, *py_sort_type;

    if (!PyArg_ParseTuple(args, "O!O:gtk_clist_set_sort_type", &PyGtk_Type, &clist, &py_sort_type))
        return NULL;
    if (PyGtkEnum_get_value(GTK_TYPE_SORT_TYPE, py_sort_type, (gint *)&sort_type))
        return NULL;
    gtk_clist_set_sort_type(GTK_CLIST(PyGtk_Get(clist)), sort_type);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_clist_sort(PyObject *self, PyObject *args) {
    PyObject *clist;

    if (!PyArg_ParseTuple(args, "O!:gtk_clist_sort", &PyGtk_Type, &clist))
        return NULL;
    gtk_clist_sort(GTK_CLIST(PyGtk_Get(clist)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_clist_set_auto_sort(PyObject *self, PyObject *args) {
    int auto_sort;
    PyObject *clist;

    if (!PyArg_ParseTuple(args, "O!i:gtk_clist_set_auto_sort", &PyGtk_Type, &clist, &auto_sort))
        return NULL;
    gtk_clist_set_auto_sort(GTK_CLIST(PyGtk_Get(clist)), auto_sort);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_combo_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_combo_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_combo_get_type());
}

static PyObject *_wrap_gtk_combo_get_entry(PyObject *self, PyObject *args) {
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_combo_get_entry", &PyGtk_Type, &obj))
        return NULL;
    return PyGtk_New((GtkObject *)GTK_COMBO(PyGtk_Get(obj))->entry);
}

static PyObject *_wrap_gtk_combo_get_list(PyObject *self, PyObject *args) {
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_combo_get_list", &PyGtk_Type, &obj))
        return NULL;
    return PyGtk_New((GtkObject *)GTK_COMBO(PyGtk_Get(obj))->list);
}

static PyObject *_wrap_gtk_combo_new(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_combo_new"))
        return NULL;
    return PyGtk_New((GtkObject *)gtk_combo_new());
}

static PyObject *_wrap_gtk_combo_set_value_in_list(PyObject *self, PyObject *args) {
    int val, ok_if_empty;
    PyObject *combo;

    if (!PyArg_ParseTuple(args, "O!ii:gtk_combo_set_value_in_list", &PyGtk_Type, &combo, &val, &ok_if_empty))
        return NULL;
    gtk_combo_set_value_in_list(GTK_COMBO(PyGtk_Get(combo)), val, ok_if_empty);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_combo_set_use_arrows(PyObject *self, PyObject *args) {
    int val;
    PyObject *combo;

    if (!PyArg_ParseTuple(args, "O!i:gtk_combo_set_use_arrows", &PyGtk_Type, &combo, &val))
        return NULL;
    gtk_combo_set_use_arrows(GTK_COMBO(PyGtk_Get(combo)), val);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_combo_set_use_arrows_always(PyObject *self, PyObject *args) {
    int val;
    PyObject *combo;

    if (!PyArg_ParseTuple(args, "O!i:gtk_combo_set_use_arrows_always", &PyGtk_Type, &combo, &val))
        return NULL;
    gtk_combo_set_use_arrows_always(GTK_COMBO(PyGtk_Get(combo)), val);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_combo_set_case_sensitive(PyObject *self, PyObject *args) {
    int val;
    PyObject *combo;

    if (!PyArg_ParseTuple(args, "O!i:gtk_combo_set_case_sensitive", &PyGtk_Type, &combo, &val))
        return NULL;
    gtk_combo_set_case_sensitive(GTK_COMBO(PyGtk_Get(combo)), val);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_combo_set_item_string(PyObject *self, PyObject *args) {
    char *item_value;
    PyObject *combo, *item;

    if (!PyArg_ParseTuple(args, "O!O!s:gtk_combo_set_item_string", &PyGtk_Type, &combo, &PyGtk_Type, &item, &item_value))
        return NULL;
    gtk_combo_set_item_string(GTK_COMBO(PyGtk_Get(combo)), GTK_ITEM(PyGtk_Get(item)), item_value);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_combo_disable_activate(PyObject *self, PyObject *args) {
    PyObject *combo;

    if (!PyArg_ParseTuple(args, "O!:gtk_combo_disable_activate", &PyGtk_Type, &combo))
        return NULL;
    gtk_combo_disable_activate(GTK_COMBO(PyGtk_Get(combo)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_list_item_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_list_item_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_list_item_get_type());
}

static PyObject *_wrap_gtk_list_item_new(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_list_item_new"))
        return NULL;
    return PyGtk_New((GtkObject *)gtk_list_item_new());
}

static PyObject *_wrap_gtk_list_item_new_with_label(PyObject *self, PyObject *args) {
    char *label;

    if (!PyArg_ParseTuple(args, "s:gtk_list_item_new_with_label", &label))
        return NULL;
    return PyGtk_New((GtkObject *)gtk_list_item_new_with_label(label));
}

static PyObject *_wrap_gtk_list_item_select(PyObject *self, PyObject *args) {
    PyObject *list_item;

    if (!PyArg_ParseTuple(args, "O!:gtk_list_item_select", &PyGtk_Type, &list_item))
        return NULL;
    gtk_list_item_select(GTK_LIST_ITEM(PyGtk_Get(list_item)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_list_item_deselect(PyObject *self, PyObject *args) {
    PyObject *list_item;

    if (!PyArg_ParseTuple(args, "O!:gtk_list_item_deselect", &PyGtk_Type, &list_item))
        return NULL;
    gtk_list_item_deselect(GTK_LIST_ITEM(PyGtk_Get(list_item)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_list_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_list_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_list_get_type());
}

static PyObject *_wrap_gtk_list_new(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_list_new"))
        return NULL;
    return PyGtk_New((GtkObject *)gtk_list_new());
}

static PyObject *_wrap_gtk_list_clear_items(PyObject *self, PyObject *args) {
    int start, end;
    PyObject *list;

    if (!PyArg_ParseTuple(args, "O!ii:gtk_list_clear_items", &PyGtk_Type, &list, &start, &end))
        return NULL;
    gtk_list_clear_items(GTK_LIST(PyGtk_Get(list)), start, end);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_list_select_item(PyObject *self, PyObject *args) {
    int item;
    PyObject *list;

    if (!PyArg_ParseTuple(args, "O!i:gtk_list_select_item", &PyGtk_Type, &list, &item))
        return NULL;
    gtk_list_select_item(GTK_LIST(PyGtk_Get(list)), item);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_list_unselect_item(PyObject *self, PyObject *args) {
    int item;
    PyObject *list;

    if (!PyArg_ParseTuple(args, "O!i:gtk_list_unselect_item", &PyGtk_Type, &list, &item))
        return NULL;
    gtk_list_unselect_item(GTK_LIST(PyGtk_Get(list)), item);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_list_select_child(PyObject *self, PyObject *args) {
    PyObject *list, *child;

    if (!PyArg_ParseTuple(args, "O!O!:gtk_list_select_child", &PyGtk_Type, &list, &PyGtk_Type, &child))
        return NULL;
    gtk_list_select_child(GTK_LIST(PyGtk_Get(list)), GTK_WIDGET(PyGtk_Get(child)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_list_unselect_child(PyObject *self, PyObject *args) {
    PyObject *list, *child;

    if (!PyArg_ParseTuple(args, "O!O!:gtk_list_unselect_child", &PyGtk_Type, &list, &PyGtk_Type, &child))
        return NULL;
    gtk_list_unselect_child(GTK_LIST(PyGtk_Get(list)), GTK_WIDGET(PyGtk_Get(child)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_list_child_position(PyObject *self, PyObject *args) {
    PyObject *list, *child;

    if (!PyArg_ParseTuple(args, "O!O!:gtk_list_child_position", &PyGtk_Type, &list, &PyGtk_Type, &child))
        return NULL;
    return PyInt_FromLong(gtk_list_child_position(GTK_LIST(PyGtk_Get(list)), GTK_WIDGET(PyGtk_Get(child))));
}

static PyObject *_wrap_gtk_list_set_selection_mode(PyObject *self, PyObject *args) {
    GtkSelectionMode mode;
    PyObject *list, *py_mode;

    if (!PyArg_ParseTuple(args, "O!O:gtk_list_set_selection_mode", &PyGtk_Type, &list, &py_mode))
        return NULL;
    if (PyGtkEnum_get_value(GTK_TYPE_SELECTION_MODE, py_mode, (gint *)&mode))
        return NULL;
    gtk_list_set_selection_mode(GTK_LIST(PyGtk_Get(list)), mode);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_list_extend_selection(PyObject *self, PyObject *args) {
    int auto_start;
    GtkScrollType scroll_type;
    double position;
    PyObject *list, *py_scroll_type;

    if (!PyArg_ParseTuple(args, "O!Odi:gtk_list_extend_selection", &PyGtk_Type, &list, &py_scroll_type, &position, &auto_start))
        return NULL;
    if (PyGtkEnum_get_value(GTK_TYPE_SCROLL_TYPE, py_scroll_type, (gint *)&scroll_type))
        return NULL;
    gtk_list_extend_selection(GTK_LIST(PyGtk_Get(list)), scroll_type, position, auto_start);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_list_start_selection(PyObject *self, PyObject *args) {
    PyObject *list;

    if (!PyArg_ParseTuple(args, "O!:gtk_list_start_selection", &PyGtk_Type, &list))
        return NULL;
    gtk_list_start_selection(GTK_LIST(PyGtk_Get(list)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_list_end_selection(PyObject *self, PyObject *args) {
    PyObject *list;

    if (!PyArg_ParseTuple(args, "O!:gtk_list_end_selection", &PyGtk_Type, &list))
        return NULL;
    gtk_list_end_selection(GTK_LIST(PyGtk_Get(list)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_list_select_all(PyObject *self, PyObject *args) {
    PyObject *list;

    if (!PyArg_ParseTuple(args, "O!:gtk_list_select_all", &PyGtk_Type, &list))
        return NULL;
    gtk_list_select_all(GTK_LIST(PyGtk_Get(list)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_list_unselect_all(PyObject *self, PyObject *args) {
    PyObject *list;

    if (!PyArg_ParseTuple(args, "O!:gtk_list_unselect_all", &PyGtk_Type, &list))
        return NULL;
    gtk_list_unselect_all(GTK_LIST(PyGtk_Get(list)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_list_scroll_horizontal(PyObject *self, PyObject *args) {
    GtkScrollType scroll_type;
    double pos;
    PyObject *list, *py_scroll_type;

    if (!PyArg_ParseTuple(args, "O!Od:gtk_list_scroll_horizontal", &PyGtk_Type, &list, &py_scroll_type, &pos))
        return NULL;
    if (PyGtkEnum_get_value(GTK_TYPE_SCROLL_TYPE, py_scroll_type, (gint *)&scroll_type))
        return NULL;
    gtk_list_scroll_horizontal(GTK_LIST(PyGtk_Get(list)), scroll_type, pos);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_list_scroll_vertical(PyObject *self, PyObject *args) {
    GtkScrollType scroll_type;
    double pos;
    PyObject *list, *py_scroll_type;

    if (!PyArg_ParseTuple(args, "O!Od:gtk_list_scroll_vertical", &PyGtk_Type, &list, &py_scroll_type, &pos))
        return NULL;
    if (PyGtkEnum_get_value(GTK_TYPE_SCROLL_TYPE, py_scroll_type, (gint *)&scroll_type))
        return NULL;
    gtk_list_scroll_vertical(GTK_LIST(PyGtk_Get(list)), scroll_type, pos);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_list_toggle_add_mode(PyObject *self, PyObject *args) {
    PyObject *list;

    if (!PyArg_ParseTuple(args, "O!:gtk_list_toggle_add_mode", &PyGtk_Type, &list))
        return NULL;
    gtk_list_toggle_add_mode(GTK_LIST(PyGtk_Get(list)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_list_toggle_focus_row(PyObject *self, PyObject *args) {
    PyObject *list;

    if (!PyArg_ParseTuple(args, "O!:gtk_list_toggle_focus_row", &PyGtk_Type, &list))
        return NULL;
    gtk_list_toggle_focus_row(GTK_LIST(PyGtk_Get(list)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_list_toggle_row(PyObject *self, PyObject *args) {
    PyObject *list, *item;

    if (!PyArg_ParseTuple(args, "O!O!:gtk_list_toggle_row", &PyGtk_Type, &list, &PyGtk_Type, &item))
        return NULL;
    gtk_list_toggle_row(GTK_LIST(PyGtk_Get(list)), GTK_WIDGET(PyGtk_Get(item)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_list_undo_selection(PyObject *self, PyObject *args) {
    PyObject *list;

    if (!PyArg_ParseTuple(args, "O!:gtk_list_undo_selection", &PyGtk_Type, &list))
        return NULL;
    gtk_list_undo_selection(GTK_LIST(PyGtk_Get(list)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_list_end_drag_selection(PyObject *self, PyObject *args) {
    PyObject *list;

    if (!PyArg_ParseTuple(args, "O!:gtk_list_end_drag_selection", &PyGtk_Type, &list))
        return NULL;
    gtk_list_end_drag_selection(GTK_LIST(PyGtk_Get(list)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_ctree_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_ctree_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_ctree_get_type());
}

static PyObject *_wrap_gtk_ctree_new(PyObject *self, PyObject *args) {
    int columns, tree_column;

    if (!PyArg_ParseTuple(args, "ii:gtk_ctree_new", &columns, &tree_column))
        return NULL;
    return PyGtk_New((GtkObject *)gtk_ctree_new(columns, tree_column));
}

static PyObject *_wrap_gtk_ctree_remove_node(PyObject *self, PyObject *args) {
    PyObject *ctree, *node;

    if (!PyArg_ParseTuple(args, "O!O!:gtk_ctree_remove_node", &PyGtk_Type, &ctree, &PyGtkCTreeNode_Type, &node))
        return NULL;
    gtk_ctree_remove_node(GTK_CTREE(PyGtk_Get(ctree)), PyGtkCTreeNode_Get(node));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_ctree_is_viewable(PyObject *self, PyObject *args) {
    PyObject *ctree, *node;

    if (!PyArg_ParseTuple(args, "O!O!:gtk_ctree_is_viewable", &PyGtk_Type, &ctree, &PyGtkCTreeNode_Type, &node))
        return NULL;
    return PyInt_FromLong(gtk_ctree_is_viewable(GTK_CTREE(PyGtk_Get(ctree)), PyGtkCTreeNode_Get(node)));
}

static PyObject *_wrap_gtk_ctree_last(PyObject *self, PyObject *args) {
    PyObject *ctree, *node;

    if (!PyArg_ParseTuple(args, "O!O!:gtk_ctree_last", &PyGtk_Type, &ctree, &PyGtkCTreeNode_Type, &node))
        return NULL;
    return PyGtkCTreeNode_New(gtk_ctree_last(GTK_CTREE(PyGtk_Get(ctree)), PyGtkCTreeNode_Get(node)));
}

static PyObject *_wrap_gtk_ctree_node_nth(PyObject *self, PyObject *args) {
    int row;
    PyObject *ctree;

    if (!PyArg_ParseTuple(args, "O!i:gtk_ctree_node_nth", &PyGtk_Type, &ctree, &row))
        return NULL;
    {
        GtkCTreeNode *p = gtk_ctree_node_nth(GTK_CTREE(PyGtk_Get(ctree)), row);
        if (p)
            return PyGtkCTreeNode_New(p);
        Py_INCREF(Py_None);
        return Py_None;
    }
}

static PyObject *_wrap_gtk_ctree_find(PyObject *self, PyObject *args) {
    PyObject *ctree, *node, *child;

    if (!PyArg_ParseTuple(args, "O!O!O!:gtk_ctree_find", &PyGtk_Type, &ctree, &PyGtkCTreeNode_Type, &node, &PyGtkCTreeNode_Type, &child))
        return NULL;
    return PyInt_FromLong(gtk_ctree_find(GTK_CTREE(PyGtk_Get(ctree)), PyGtkCTreeNode_Get(node), PyGtkCTreeNode_Get(child)));
}

static PyObject *_wrap_gtk_ctree_is_ancestor(PyObject *self, PyObject *args) {
    PyObject *ctree, *node, *child;

    if (!PyArg_ParseTuple(args, "O!O!O!:gtk_ctree_is_ancestor", &PyGtk_Type, &ctree, &PyGtkCTreeNode_Type, &node, &PyGtkCTreeNode_Type, &child))
        return NULL;
    return PyInt_FromLong(gtk_ctree_is_ancestor(GTK_CTREE(PyGtk_Get(ctree)), PyGtkCTreeNode_Get(node), PyGtkCTreeNode_Get(child)));
}

static PyObject *_wrap_gtk_ctree_is_hot_spot(PyObject *self, PyObject *args) {
    int x, y;
    PyObject *ctree;

    if (!PyArg_ParseTuple(args, "O!ii:gtk_ctree_is_hot_spot", &PyGtk_Type, &ctree, &x, &y))
        return NULL;
    return PyInt_FromLong(gtk_ctree_is_hot_spot(GTK_CTREE(PyGtk_Get(ctree)), x, y));
}

static PyObject *_wrap_gtk_ctree_expand(PyObject *self, PyObject *args) {
    PyObject *ctree, *node;

    if (!PyArg_ParseTuple(args, "O!O!:gtk_ctree_expand", &PyGtk_Type, &ctree, &PyGtkCTreeNode_Type, &node))
        return NULL;
    gtk_ctree_expand(GTK_CTREE(PyGtk_Get(ctree)), PyGtkCTreeNode_Get(node));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_ctree_expand_recursive(PyObject *self, PyObject *args) {
    PyObject *ctree, *node;

    if (!PyArg_ParseTuple(args, "O!O!:gtk_ctree_expand_recursive", &PyGtk_Type, &ctree, &PyGtkCTreeNode_Type, &node))
        return NULL;
    gtk_ctree_expand_recursive(GTK_CTREE(PyGtk_Get(ctree)), PyGtkCTreeNode_Get(node));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_ctree_expand_to_depth(PyObject *self, PyObject *args) {
    int depth;
    PyObject *ctree, *node;

    if (!PyArg_ParseTuple(args, "O!O!i:gtk_ctree_expand_to_depth", &PyGtk_Type, &ctree, &PyGtkCTreeNode_Type, &node, &depth))
        return NULL;
    gtk_ctree_expand_to_depth(GTK_CTREE(PyGtk_Get(ctree)), PyGtkCTreeNode_Get(node), depth);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_ctree_collapse(PyObject *self, PyObject *args) {
    PyObject *ctree, *node;

    if (!PyArg_ParseTuple(args, "O!O!:gtk_ctree_collapse", &PyGtk_Type, &ctree, &PyGtkCTreeNode_Type, &node))
        return NULL;
    gtk_ctree_collapse(GTK_CTREE(PyGtk_Get(ctree)), PyGtkCTreeNode_Get(node));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_ctree_collapse_recursive(PyObject *self, PyObject *args) {
    PyObject *ctree, *node;

    if (!PyArg_ParseTuple(args, "O!O!:gtk_ctree_collapse_recursive", &PyGtk_Type, &ctree, &PyGtkCTreeNode_Type, &node))
        return NULL;
    gtk_ctree_collapse_recursive(GTK_CTREE(PyGtk_Get(ctree)), PyGtkCTreeNode_Get(node));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_ctree_collapse_to_depth(PyObject *self, PyObject *args) {
    int depth;
    PyObject *ctree, *node;

    if (!PyArg_ParseTuple(args, "O!O!i:gtk_ctree_collapse_to_depth", &PyGtk_Type, &ctree, &PyGtkCTreeNode_Type, &node, &depth))
        return NULL;
    gtk_ctree_collapse_to_depth(GTK_CTREE(PyGtk_Get(ctree)), PyGtkCTreeNode_Get(node), depth);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_ctree_toggle_expansion(PyObject *self, PyObject *args) {
    PyObject *ctree, *node;

    if (!PyArg_ParseTuple(args, "O!O!:gtk_ctree_toggle_expansion", &PyGtk_Type, &ctree, &PyGtkCTreeNode_Type, &node))
        return NULL;
    gtk_ctree_toggle_expansion(GTK_CTREE(PyGtk_Get(ctree)), PyGtkCTreeNode_Get(node));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_ctree_toggle_expansion_recursive(PyObject *self, PyObject *args) {
    PyObject *ctree, *node;

    if (!PyArg_ParseTuple(args, "O!O!:gtk_ctree_toggle_expansion_recursive", &PyGtk_Type, &ctree, &PyGtkCTreeNode_Type, &node))
        return NULL;
    gtk_ctree_toggle_expansion_recursive(GTK_CTREE(PyGtk_Get(ctree)), PyGtkCTreeNode_Get(node));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_ctree_select(PyObject *self, PyObject *args) {
    PyObject *ctree, *node;

    if (!PyArg_ParseTuple(args, "O!O!:gtk_ctree_select", &PyGtk_Type, &ctree, &PyGtkCTreeNode_Type, &node))
        return NULL;
    gtk_ctree_select(GTK_CTREE(PyGtk_Get(ctree)), PyGtkCTreeNode_Get(node));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_ctree_select_recursive(PyObject *self, PyObject *args) {
    PyObject *ctree, *node;

    if (!PyArg_ParseTuple(args, "O!O!:gtk_ctree_select_recursive", &PyGtk_Type, &ctree, &PyGtkCTreeNode_Type, &node))
        return NULL;
    gtk_ctree_select_recursive(GTK_CTREE(PyGtk_Get(ctree)), PyGtkCTreeNode_Get(node));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_ctree_unselect(PyObject *self, PyObject *args) {
    PyObject *ctree, *node;

    if (!PyArg_ParseTuple(args, "O!O!:gtk_ctree_unselect", &PyGtk_Type, &ctree, &PyGtkCTreeNode_Type, &node))
        return NULL;
    gtk_ctree_unselect(GTK_CTREE(PyGtk_Get(ctree)), PyGtkCTreeNode_Get(node));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_ctree_unselect_recursive(PyObject *self, PyObject *args) {
    PyObject *ctree, *node;

    if (!PyArg_ParseTuple(args, "O!O!:gtk_ctree_unselect_recursive", &PyGtk_Type, &ctree, &PyGtkCTreeNode_Type, &node))
        return NULL;
    gtk_ctree_unselect_recursive(GTK_CTREE(PyGtk_Get(ctree)), PyGtkCTreeNode_Get(node));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_ctree_real_select_recursive(PyObject *self, PyObject *args) {
    int state;
    PyObject *ctree, *node;

    if (!PyArg_ParseTuple(args, "O!O!i:gtk_ctree_real_select_recursive", &PyGtk_Type, &ctree, &PyGtkCTreeNode_Type, &node, &state))
        return NULL;
    gtk_ctree_real_select_recursive(GTK_CTREE(PyGtk_Get(ctree)), PyGtkCTreeNode_Get(node), state);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_ctree_node_set_text(PyObject *self, PyObject *args) {
    int column;
    char *text;
    PyObject *ctree, *node;

    if (!PyArg_ParseTuple(args, "O!O!is:gtk_ctree_node_set_text", &PyGtk_Type, &ctree, &PyGtkCTreeNode_Type, &node, &column, &text))
        return NULL;
    gtk_ctree_node_set_text(GTK_CTREE(PyGtk_Get(ctree)), PyGtkCTreeNode_Get(node), column, text);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_ctree_node_set_pixmap(PyObject *self, PyObject *args) {
    int column;
    PyObject *ctree, *node, *pixmap, *mask;

    if (!PyArg_ParseTuple(args, "O!O!iO!O!:gtk_ctree_node_set_pixmap", &PyGtk_Type, &ctree, &PyGtkCTreeNode_Type, &node, &column, &PyGdkWindow_Type, &pixmap, &PyGdkWindow_Type, &mask))
        return NULL;
    gtk_ctree_node_set_pixmap(GTK_CTREE(PyGtk_Get(ctree)), PyGtkCTreeNode_Get(node), column, PyGdkWindow_Get(pixmap), PyGdkWindow_Get(mask));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_ctree_node_set_pixtext(PyObject *self, PyObject *args) {
    PyObject *ctree, *node, *pixmap, *mask;
    char *text;
    int column, spacing;

    if (!PyArg_ParseTuple(args, "O!O!isiO!O!:gtk_ctree_node_set_pixtext", &PyGtk_Type, &ctree, &PyGtkCTreeNode_Type, &node, &column, &text, &spacing, &PyGdkWindow_Type, &pixmap, &PyGdkWindow_Type, &mask))
        return NULL;
    gtk_ctree_node_set_pixtext(GTK_CTREE(PyGtk_Get(ctree)), PyGtkCTreeNode_Get(node), column, text, spacing, PyGdkWindow_Get(pixmap), PyGdkWindow_Get(mask));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_ctree_set_node_info(PyObject *self, PyObject *args) {
    PyObject *ctree, *node, *pixmap_closed, *mask_closed, *pixmap_opened, *mask_opened;
    char *text;
    int spacing, is_leaf, expanded;

    if (!PyArg_ParseTuple(args, "O!O!siO!O!O!O!ii:gtk_ctree_set_node_info", &PyGtk_Type, &ctree, &PyGtkCTreeNode_Type, &node, &text, &spacing, &PyGdkWindow_Type, &pixmap_closed, &PyGdkWindow_Type, &mask_closed, &PyGdkWindow_Type, &pixmap_opened, &PyGdkWindow_Type, &mask_opened, &is_leaf, &expanded))
        return NULL;
    gtk_ctree_set_node_info(GTK_CTREE(PyGtk_Get(ctree)), PyGtkCTreeNode_Get(node), text, spacing, PyGdkWindow_Get(pixmap_closed), PyGdkWindow_Get(mask_closed), PyGdkWindow_Get(pixmap_opened), PyGdkWindow_Get(mask_opened), is_leaf, expanded);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_ctree_node_set_shift(PyObject *self, PyObject *args) {
    int column, vertical, horizontal;
    PyObject *ctree, *node;

    if (!PyArg_ParseTuple(args, "O!O!iii:gtk_ctree_node_set_shift", &PyGtk_Type, &ctree, &PyGtkCTreeNode_Type, &node, &column, &vertical, &horizontal))
        return NULL;
    gtk_ctree_node_set_shift(GTK_CTREE(PyGtk_Get(ctree)), PyGtkCTreeNode_Get(node), column, vertical, horizontal);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_ctree_node_set_selectable(PyObject *self, PyObject *args) {
    int selectable;
    PyObject *ctree, *node;

    if (!PyArg_ParseTuple(args, "O!O!i:gtk_ctree_node_set_selectable", &PyGtk_Type, &ctree, &PyGtkCTreeNode_Type, &node, &selectable))
        return NULL;
    gtk_ctree_node_set_selectable(GTK_CTREE(PyGtk_Get(ctree)), PyGtkCTreeNode_Get(node), selectable);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_ctree_node_get_selectable(PyObject *self, PyObject *args) {
    PyObject *ctree, *node;

    if (!PyArg_ParseTuple(args, "O!O!:gtk_ctree_node_get_selectable", &PyGtk_Type, &ctree, &PyGtkCTreeNode_Type, &node))
        return NULL;
    return PyInt_FromLong(gtk_ctree_node_get_selectable(GTK_CTREE(PyGtk_Get(ctree)), PyGtkCTreeNode_Get(node)));
}

static PyObject *_wrap_gtk_ctree_node_get_cell_type(PyObject *self, PyObject *args) {
    int column;
    PyObject *ctree, *node;

    if (!PyArg_ParseTuple(args, "O!O!i:gtk_ctree_node_get_cell_type", &PyGtk_Type, &ctree, &PyGtkCTreeNode_Type, &node, &column))
        return NULL;
    return PyInt_FromLong(gtk_ctree_node_get_cell_type(GTK_CTREE(PyGtk_Get(ctree)), PyGtkCTreeNode_Get(node), column));
}

static PyObject *_wrap_gtk_ctree_node_set_row_style(PyObject *self, PyObject *args) {
    PyObject *ctree, *node, *style;

    if (!PyArg_ParseTuple(args, "O!O!O!:gtk_ctree_node_set_row_style", &PyGtk_Type, &ctree, &PyGtkCTreeNode_Type, &node, &PyGtkStyle_Type, &style))
        return NULL;
    gtk_ctree_node_set_row_style(GTK_CTREE(PyGtk_Get(ctree)), PyGtkCTreeNode_Get(node), PyGtkStyle_Get(style));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_ctree_node_get_row_style(PyObject *self, PyObject *args) {
    PyObject *ctree, *node;

    if (!PyArg_ParseTuple(args, "O!O!:gtk_ctree_node_get_row_style", &PyGtk_Type, &ctree, &PyGtkCTreeNode_Type, &node))
        return NULL;
    return PyGtkStyle_New(gtk_ctree_node_get_row_style(GTK_CTREE(PyGtk_Get(ctree)), PyGtkCTreeNode_Get(node)));
}

static PyObject *_wrap_gtk_ctree_node_set_cell_style(PyObject *self, PyObject *args) {
    int column;
    PyObject *ctree, *node, *style;

    if (!PyArg_ParseTuple(args, "O!O!iO!:gtk_ctree_node_set_cell_style", &PyGtk_Type, &ctree, &PyGtkCTreeNode_Type, &node, &column, &PyGtkStyle_Type, &style))
        return NULL;
    gtk_ctree_node_set_cell_style(GTK_CTREE(PyGtk_Get(ctree)), PyGtkCTreeNode_Get(node), column, PyGtkStyle_Get(style));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_ctree_node_get_cell_style(PyObject *self, PyObject *args) {
    int column;
    PyObject *ctree, *node;

    if (!PyArg_ParseTuple(args, "O!O!i:gtk_ctree_node_get_cell_style", &PyGtk_Type, &ctree, &PyGtkCTreeNode_Type, &node, &column))
        return NULL;
    return PyGtkStyle_New(gtk_ctree_node_get_cell_style(GTK_CTREE(PyGtk_Get(ctree)), PyGtkCTreeNode_Get(node), column));
}

static PyObject *_wrap_gtk_ctree_node_set_foreground(PyObject *self, PyObject *args) {
    PyObject *ctree, *node, *color;

    if (!PyArg_ParseTuple(args, "O!O!O!:gtk_ctree_node_set_foreground", &PyGtk_Type, &ctree, &PyGtkCTreeNode_Type, &node, &PyGdkColor_Type, &color))
        return NULL;
    gtk_ctree_node_set_foreground(GTK_CTREE(PyGtk_Get(ctree)), PyGtkCTreeNode_Get(node), PyGdkColor_Get(color));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_ctree_node_set_background(PyObject *self, PyObject *args) {
    PyObject *ctree, *node, *color;

    if (!PyArg_ParseTuple(args, "O!O!O!:gtk_ctree_node_set_background", &PyGtk_Type, &ctree, &PyGtkCTreeNode_Type, &node, &PyGdkColor_Type, &color))
        return NULL;
    gtk_ctree_node_set_background(GTK_CTREE(PyGtk_Get(ctree)), PyGtkCTreeNode_Get(node), PyGdkColor_Get(color));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_ctree_node_moveto(PyObject *self, PyObject *args) {
    PyObject *ctree, *node;
    double row_align, col_align;
    int column;

    if (!PyArg_ParseTuple(args, "O!O!idd:gtk_ctree_node_moveto", &PyGtk_Type, &ctree, &PyGtkCTreeNode_Type, &node, &column, &row_align, &col_align))
        return NULL;
    gtk_ctree_node_moveto(GTK_CTREE(PyGtk_Get(ctree)), PyGtkCTreeNode_Get(node), column, row_align, col_align);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_ctree_node_is_visible(PyObject *self, PyObject *args) {
    PyObject *ctree, *node;

    if (!PyArg_ParseTuple(args, "O!O!:gtk_ctree_node_is_visible", &PyGtk_Type, &ctree, &PyGtkCTreeNode_Type, &node))
        return NULL;
    return PyInt_FromLong(gtk_ctree_node_is_visible(GTK_CTREE(PyGtk_Get(ctree)), PyGtkCTreeNode_Get(node)));
}

static PyObject *_wrap_gtk_ctree_set_indent(PyObject *self, PyObject *args) {
    int indent;
    PyObject *ctree;

    if (!PyArg_ParseTuple(args, "O!i:gtk_ctree_set_indent", &PyGtk_Type, &ctree, &indent))
        return NULL;
    gtk_ctree_set_indent(GTK_CTREE(PyGtk_Get(ctree)), indent);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_ctree_set_spacing(PyObject *self, PyObject *args) {
    int spacing;
    PyObject *ctree;

    if (!PyArg_ParseTuple(args, "O!i:gtk_ctree_set_spacing", &PyGtk_Type, &ctree, &spacing))
        return NULL;
    gtk_ctree_set_spacing(GTK_CTREE(PyGtk_Get(ctree)), spacing);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_ctree_set_show_stub(PyObject *self, PyObject *args) {
    int show_stub;
    PyObject *ctree;

    if (!PyArg_ParseTuple(args, "O!i:gtk_ctree_set_show_stub", &PyGtk_Type, &ctree, &show_stub))
        return NULL;
    gtk_ctree_set_show_stub(GTK_CTREE(PyGtk_Get(ctree)), show_stub);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_ctree_set_line_style(PyObject *self, PyObject *args) {
    GtkCTreeLineStyle style;
    PyObject *ctree, *py_style;

    if (!PyArg_ParseTuple(args, "O!O:gtk_ctree_set_line_style", &PyGtk_Type, &ctree, &py_style))
        return NULL;
    if (PyGtkEnum_get_value(GTK_TYPE_CTREE_LINE_STYLE, py_style, (gint *)&style))
        return NULL;
    gtk_ctree_set_line_style(GTK_CTREE(PyGtk_Get(ctree)), style);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_ctree_set_expander_style(PyObject *self, PyObject *args) {
    GtkCTreeExpanderStyle style;
    PyObject *ctree, *py_style;

    if (!PyArg_ParseTuple(args, "O!O:gtk_ctree_set_expander_style", &PyGtk_Type, &ctree, &py_style))
        return NULL;
    if (PyGtkEnum_get_value(GTK_TYPE_CTREE_EXPANDER_STYLE, py_style, (gint *)&style))
        return NULL;
    gtk_ctree_set_expander_style(GTK_CTREE(PyGtk_Get(ctree)), style);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_ctree_sort_node(PyObject *self, PyObject *args) {
    PyObject *ctree, *node;

    if (!PyArg_ParseTuple(args, "O!O!:gtk_ctree_sort_node", &PyGtk_Type, &ctree, &PyGtkCTreeNode_Type, &node))
        return NULL;
    gtk_ctree_sort_node(GTK_CTREE(PyGtk_Get(ctree)), PyGtkCTreeNode_Get(node));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_ctree_sort_recursive(PyObject *self, PyObject *args) {
    PyObject *ctree, *node;

    if (!PyArg_ParseTuple(args, "O!O!:gtk_ctree_sort_recursive", &PyGtk_Type, &ctree, &PyGtkCTreeNode_Type, &node))
        return NULL;
    gtk_ctree_sort_recursive(GTK_CTREE(PyGtk_Get(ctree)), PyGtkCTreeNode_Get(node));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_menu_shell_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_menu_shell_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_menu_shell_get_type());
}

static PyObject *_wrap_gtk_menu_shell_append(PyObject *self, PyObject *args) {
    PyObject *menu_shell, *child;

    if (!PyArg_ParseTuple(args, "O!O!:gtk_menu_shell_append", &PyGtk_Type, &menu_shell, &PyGtk_Type, &child))
        return NULL;
    gtk_menu_shell_append(GTK_MENU_SHELL(PyGtk_Get(menu_shell)), GTK_WIDGET(PyGtk_Get(child)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_menu_shell_prepend(PyObject *self, PyObject *args) {
    PyObject *menu_shell, *child;

    if (!PyArg_ParseTuple(args, "O!O!:gtk_menu_shell_prepend", &PyGtk_Type, &menu_shell, &PyGtk_Type, &child))
        return NULL;
    gtk_menu_shell_prepend(GTK_MENU_SHELL(PyGtk_Get(menu_shell)), GTK_WIDGET(PyGtk_Get(child)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_menu_shell_insert(PyObject *self, PyObject *args) {
    int position;
    PyObject *menu_shell, *child;

    if (!PyArg_ParseTuple(args, "O!O!i:gtk_menu_shell_insert", &PyGtk_Type, &menu_shell, &PyGtk_Type, &child, &position))
        return NULL;
    gtk_menu_shell_insert(GTK_MENU_SHELL(PyGtk_Get(menu_shell)), GTK_WIDGET(PyGtk_Get(child)), position);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_menu_shell_deactivate(PyObject *self, PyObject *args) {
    PyObject *menu_shell;

    if (!PyArg_ParseTuple(args, "O!:gtk_menu_shell_deactivate", &PyGtk_Type, &menu_shell))
        return NULL;
    gtk_menu_shell_deactivate(GTK_MENU_SHELL(PyGtk_Get(menu_shell)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_menu_shell_select_item(PyObject *self, PyObject *args) {
    PyObject *menu_shell, *menu_item;

    if (!PyArg_ParseTuple(args, "O!O!:gtk_menu_shell_select_item", &PyGtk_Type, &menu_shell, &PyGtk_Type, &menu_item))
        return NULL;
    gtk_menu_shell_select_item(GTK_MENU_SHELL(PyGtk_Get(menu_shell)), GTK_WIDGET(PyGtk_Get(menu_item)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_menu_shell_deselect(PyObject *self, PyObject *args) {
    PyObject *menu_shell;

    if (!PyArg_ParseTuple(args, "O!:gtk_menu_shell_deselect", &PyGtk_Type, &menu_shell))
        return NULL;
    gtk_menu_shell_deselect(GTK_MENU_SHELL(PyGtk_Get(menu_shell)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_menu_shell_activate_item(PyObject *self, PyObject *args) {
    int force_deactivate;
    PyObject *menu_shell, *menu_item;

    if (!PyArg_ParseTuple(args, "O!O!i:gtk_menu_shell_activate_item", &PyGtk_Type, &menu_shell, &PyGtk_Type, &menu_item, &force_deactivate))
        return NULL;
    gtk_menu_shell_activate_item(GTK_MENU_SHELL(PyGtk_Get(menu_shell)), GTK_WIDGET(PyGtk_Get(menu_item)), force_deactivate);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_menu_bar_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_menu_bar_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_menu_bar_get_type());
}

static PyObject *_wrap_gtk_menu_bar_new(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_menu_bar_new"))
        return NULL;
    return PyGtk_New((GtkObject *)gtk_menu_bar_new());
}

static PyObject *_wrap_gtk_menu_bar_append(PyObject *self, PyObject *args) {
    PyObject *menu_bar, *child;

    if (!PyArg_ParseTuple(args, "O!O!:gtk_menu_bar_append", &PyGtk_Type, &menu_bar, &PyGtk_Type, &child))
        return NULL;
    gtk_menu_bar_append(GTK_MENU_BAR(PyGtk_Get(menu_bar)), GTK_WIDGET(PyGtk_Get(child)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_menu_bar_prepend(PyObject *self, PyObject *args) {
    PyObject *menu_bar, *child;

    if (!PyArg_ParseTuple(args, "O!O!:gtk_menu_bar_prepend", &PyGtk_Type, &menu_bar, &PyGtk_Type, &child))
        return NULL;
    gtk_menu_bar_prepend(GTK_MENU_BAR(PyGtk_Get(menu_bar)), GTK_WIDGET(PyGtk_Get(child)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_menu_bar_insert(PyObject *self, PyObject *args) {
    int position;
    PyObject *menu_bar, *child;

    if (!PyArg_ParseTuple(args, "O!O!i:gtk_menu_bar_insert", &PyGtk_Type, &menu_bar, &PyGtk_Type, &child, &position))
        return NULL;
    gtk_menu_bar_insert(GTK_MENU_BAR(PyGtk_Get(menu_bar)), GTK_WIDGET(PyGtk_Get(child)), position);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_menu_bar_set_shadow_type(PyObject *self, PyObject *args) {
    GtkShadowType type;
    PyObject *menu_bar, *py_type;

    if (!PyArg_ParseTuple(args, "O!O:gtk_menu_bar_set_shadow_type", &PyGtk_Type, &menu_bar, &py_type))
        return NULL;
    if (PyGtkEnum_get_value(GTK_TYPE_SHADOW_TYPE, py_type, (gint *)&type))
        return NULL;
    gtk_menu_bar_set_shadow_type(GTK_MENU_BAR(PyGtk_Get(menu_bar)), type);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_menu_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_menu_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_menu_get_type());
}

static PyObject *_wrap_gtk_menu_new(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_menu_new"))
        return NULL;
    return PyGtk_New((GtkObject *)gtk_menu_new());
}

static PyObject *_wrap_gtk_menu_append(PyObject *self, PyObject *args) {
    PyObject *menu, *child;

    if (!PyArg_ParseTuple(args, "O!O!:gtk_menu_append", &PyGtk_Type, &menu, &PyGtk_Type, &child))
        return NULL;
    gtk_menu_append(GTK_MENU(PyGtk_Get(menu)), GTK_WIDGET(PyGtk_Get(child)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_menu_prepend(PyObject *self, PyObject *args) {
    PyObject *menu, *child;

    if (!PyArg_ParseTuple(args, "O!O!:gtk_menu_prepend", &PyGtk_Type, &menu, &PyGtk_Type, &child))
        return NULL;
    gtk_menu_prepend(GTK_MENU(PyGtk_Get(menu)), GTK_WIDGET(PyGtk_Get(child)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_menu_insert(PyObject *self, PyObject *args) {
    int position;
    PyObject *menu, *child;

    if (!PyArg_ParseTuple(args, "O!O!i:gtk_menu_insert", &PyGtk_Type, &menu, &PyGtk_Type, &child, &position))
        return NULL;
    gtk_menu_insert(GTK_MENU(PyGtk_Get(menu)), GTK_WIDGET(PyGtk_Get(child)), position);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_menu_reposition(PyObject *self, PyObject *args) {
    PyObject *menu;

    if (!PyArg_ParseTuple(args, "O!:gtk_menu_reposition", &PyGtk_Type, &menu))
        return NULL;
    gtk_menu_reposition(GTK_MENU(PyGtk_Get(menu)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_menu_popdown(PyObject *self, PyObject *args) {
    PyObject *menu;

    if (!PyArg_ParseTuple(args, "O!:gtk_menu_popdown", &PyGtk_Type, &menu))
        return NULL;
    gtk_menu_popdown(GTK_MENU(PyGtk_Get(menu)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_menu_get_active(PyObject *self, PyObject *args) {
    PyObject *menu;

    if (!PyArg_ParseTuple(args, "O!:gtk_menu_get_active", &PyGtk_Type, &menu))
        return NULL;
    return PyGtk_New((GtkObject *)gtk_menu_get_active(GTK_MENU(PyGtk_Get(menu))));
}

static PyObject *_wrap_gtk_menu_set_active(PyObject *self, PyObject *args) {
    int index;
    PyObject *menu;

    if (!PyArg_ParseTuple(args, "O!i:gtk_menu_set_active", &PyGtk_Type, &menu, &index))
        return NULL;
    gtk_menu_set_active(GTK_MENU(PyGtk_Get(menu)), index);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_menu_set_accel_group(PyObject *self, PyObject *args) {
    PyObject *menu, *group;

    if (!PyArg_ParseTuple(args, "O!O!:gtk_menu_set_accel_group", &PyGtk_Type, &menu, &PyGtkAccelGroup_Type, &group))
        return NULL;
    gtk_menu_set_accel_group(GTK_MENU(PyGtk_Get(menu)), PyGtkAccelGroup_Get(group));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_menu_get_accel_group(PyObject *self, PyObject *args) {
    PyObject *menu;

    if (!PyArg_ParseTuple(args, "O!:gtk_menu_get_accel_group", &PyGtk_Type, &menu))
        return NULL;
    return PyGtkAccelGroup_New(gtk_menu_get_accel_group(GTK_MENU(PyGtk_Get(menu))));
}

static PyObject *_wrap_gtk_menu_get_attach_widget(PyObject *self, PyObject *args) {
    PyObject *menu;

    if (!PyArg_ParseTuple(args, "O!:gtk_menu_get_attach_widget", &PyGtk_Type, &menu))
        return NULL;
    return PyGtk_New((GtkObject *)gtk_menu_get_attach_widget(GTK_MENU(PyGtk_Get(menu))));
}

static PyObject *_wrap_gtk_menu_detach(PyObject *self, PyObject *args) {
    PyObject *menu;

    if (!PyArg_ParseTuple(args, "O!:gtk_menu_detach", &PyGtk_Type, &menu))
        return NULL;
    gtk_menu_detach(GTK_MENU(PyGtk_Get(menu)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_menu_set_tearoff_state(PyObject *self, PyObject *args) {
    int torn_off;
    PyObject *menu;

    if (!PyArg_ParseTuple(args, "O!i:gtk_menu_set_tearoff_state", &PyGtk_Type, &menu, &torn_off))
        return NULL;
    gtk_menu_set_tearoff_state(GTK_MENU(PyGtk_Get(menu)), torn_off);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_menu_set_title(PyObject *self, PyObject *args) {
    char *title;
    PyObject *menu;

    if (!PyArg_ParseTuple(args, "O!s:gtk_menu_set_title", &PyGtk_Type, &menu, &title))
        return NULL;
    gtk_menu_set_title(GTK_MENU(PyGtk_Get(menu)), title);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_menu_reorder_child(PyObject *self, PyObject *args) {
    int position;
    PyObject *menu, *child;

    if (!PyArg_ParseTuple(args, "O!O!i:gtk_menu_reorder_child", &PyGtk_Type, &menu, &PyGtk_Type, &child, &position))
        return NULL;
    gtk_menu_reorder_child(GTK_MENU(PyGtk_Get(menu)), GTK_WIDGET(PyGtk_Get(child)), position);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_menu_item_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_menu_item_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_menu_item_get_type());
}

static PyObject *_wrap_gtk_menu_item_new(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_menu_item_new"))
        return NULL;
    return PyGtk_New((GtkObject *)gtk_menu_item_new());
}

static PyObject *_wrap_gtk_menu_item_new_with_label(PyObject *self, PyObject *args) {
    char *label;

    if (!PyArg_ParseTuple(args, "s:gtk_menu_item_new_with_label", &label))
        return NULL;
    return PyGtk_New((GtkObject *)gtk_menu_item_new_with_label(label));
}

static PyObject *_wrap_gtk_menu_item_set_submenu(PyObject *self, PyObject *args) {
    PyObject *menu_item, *submenu;

    if (!PyArg_ParseTuple(args, "O!O!:gtk_menu_item_set_submenu", &PyGtk_Type, &menu_item, &PyGtk_Type, &submenu))
        return NULL;
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(PyGtk_Get(menu_item)), GTK_WIDGET(PyGtk_Get(submenu)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_menu_item_remove_submenu(PyObject *self, PyObject *args) {
    PyObject *menu_item;

    if (!PyArg_ParseTuple(args, "O!:gtk_menu_item_remove_submenu", &PyGtk_Type, &menu_item))
        return NULL;
    gtk_menu_item_remove_submenu(GTK_MENU_ITEM(PyGtk_Get(menu_item)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_menu_item_set_placement(PyObject *self, PyObject *args) {
    GtkSubmenuPlacement placement;
    PyObject *menu_item, *py_placement;

    if (!PyArg_ParseTuple(args, "O!O:gtk_menu_item_set_placement", &PyGtk_Type, &menu_item, &py_placement))
        return NULL;
    if (PyGtkEnum_get_value(GTK_TYPE_SUBMENU_PLACEMENT, py_placement, (gint *)&placement))
        return NULL;
    gtk_menu_item_set_placement(GTK_MENU_ITEM(PyGtk_Get(menu_item)), placement);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_menu_item_configure(PyObject *self, PyObject *args) {
    int show_toggle_indicator, show_submenu_indicator;
    PyObject *menu_item;

    if (!PyArg_ParseTuple(args, "O!ii:gtk_menu_item_configure", &PyGtk_Type, &menu_item, &show_toggle_indicator, &show_submenu_indicator))
        return NULL;
    gtk_menu_item_configure(GTK_MENU_ITEM(PyGtk_Get(menu_item)), show_toggle_indicator, show_submenu_indicator);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_menu_item_select(PyObject *self, PyObject *args) {
    PyObject *menu_item;

    if (!PyArg_ParseTuple(args, "O!:gtk_menu_item_select", &PyGtk_Type, &menu_item))
        return NULL;
    gtk_menu_item_select(GTK_MENU_ITEM(PyGtk_Get(menu_item)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_menu_item_deselect(PyObject *self, PyObject *args) {
    PyObject *menu_item;

    if (!PyArg_ParseTuple(args, "O!:gtk_menu_item_deselect", &PyGtk_Type, &menu_item))
        return NULL;
    gtk_menu_item_deselect(GTK_MENU_ITEM(PyGtk_Get(menu_item)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_menu_item_activate(PyObject *self, PyObject *args) {
    PyObject *menu_item;

    if (!PyArg_ParseTuple(args, "O!:gtk_menu_item_activate", &PyGtk_Type, &menu_item))
        return NULL;
    gtk_menu_item_activate(GTK_MENU_ITEM(PyGtk_Get(menu_item)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_menu_item_right_justify(PyObject *self, PyObject *args) {
    PyObject *menu_item;

    if (!PyArg_ParseTuple(args, "O!:gtk_menu_item_right_justify", &PyGtk_Type, &menu_item))
        return NULL;
    gtk_menu_item_right_justify(GTK_MENU_ITEM(PyGtk_Get(menu_item)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_check_menu_item_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_check_menu_item_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_check_menu_item_get_type());
}

static PyObject *_wrap_gtk_check_menu_item_get_active(PyObject *self, PyObject *args) {
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_check_menu_item_get_active", &PyGtk_Type, &obj))
        return NULL;
    return PyInt_FromLong(GTK_CHECK_MENU_ITEM(PyGtk_Get(obj))->active);
}

static PyObject *_wrap_gtk_check_menu_item_new(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_check_menu_item_new"))
        return NULL;
    return PyGtk_New((GtkObject *)gtk_check_menu_item_new());
}

static PyObject *_wrap_gtk_check_menu_item_new_with_label(PyObject *self, PyObject *args) {
    char *label;

    if (!PyArg_ParseTuple(args, "s:gtk_check_menu_item_new_with_label", &label))
        return NULL;
    return PyGtk_New((GtkObject *)gtk_check_menu_item_new_with_label(label));
}

static PyObject *_wrap_gtk_check_menu_item_set_active(PyObject *self, PyObject *args) {
    int state;
    PyObject *check_menu_item;

    if (!PyArg_ParseTuple(args, "O!i:gtk_check_menu_item_set_active", &PyGtk_Type, &check_menu_item, &state))
        return NULL;
    gtk_check_menu_item_set_active(GTK_CHECK_MENU_ITEM(PyGtk_Get(check_menu_item)), state);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_check_menu_item_set_show_toggle(PyObject *self, PyObject *args) {
    int always;
    PyObject *menu_item;

    if (!PyArg_ParseTuple(args, "O!i:gtk_check_menu_item_set_show_toggle", &PyGtk_Type, &menu_item, &always))
        return NULL;
    gtk_check_menu_item_set_show_toggle(GTK_CHECK_MENU_ITEM(PyGtk_Get(menu_item)), always);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_check_menu_item_toggled(PyObject *self, PyObject *args) {
    PyObject *check_menu_item;

    if (!PyArg_ParseTuple(args, "O!:gtk_check_menu_item_toggled", &PyGtk_Type, &check_menu_item))
        return NULL;
    gtk_check_menu_item_toggled(GTK_CHECK_MENU_ITEM(PyGtk_Get(check_menu_item)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_radio_menu_item_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_radio_menu_item_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_radio_menu_item_get_type());
}

static PyObject *_wrap_gtk_option_menu_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_option_menu_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_option_menu_get_type());
}

static PyObject *_wrap_gtk_option_menu_new(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_option_menu_new"))
        return NULL;
    return PyGtk_New((GtkObject *)gtk_option_menu_new());
}

static PyObject *_wrap_gtk_option_menu_get_menu(PyObject *self, PyObject *args) {
    PyObject *option_menu;

    if (!PyArg_ParseTuple(args, "O!:gtk_option_menu_get_menu", &PyGtk_Type, &option_menu))
        return NULL;
    return PyGtk_New((GtkObject *)gtk_option_menu_get_menu(GTK_OPTION_MENU(PyGtk_Get(option_menu))));
}

static PyObject *_wrap_gtk_option_menu_set_menu(PyObject *self, PyObject *args) {
    PyObject *option_menu, *menu;

    if (!PyArg_ParseTuple(args, "O!O!:gtk_option_menu_set_menu", &PyGtk_Type, &option_menu, &PyGtk_Type, &menu))
        return NULL;
    gtk_option_menu_set_menu(GTK_OPTION_MENU(PyGtk_Get(option_menu)), GTK_WIDGET(PyGtk_Get(menu)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_option_menu_remove_menu(PyObject *self, PyObject *args) {
    PyObject *option_menu;

    if (!PyArg_ParseTuple(args, "O!:gtk_option_menu_remove_menu", &PyGtk_Type, &option_menu))
        return NULL;
    gtk_option_menu_remove_menu(GTK_OPTION_MENU(PyGtk_Get(option_menu)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_option_menu_set_history(PyObject *self, PyObject *args) {
    int index;
    PyObject *option_menu;

    if (!PyArg_ParseTuple(args, "O!i:gtk_option_menu_set_history", &PyGtk_Type, &option_menu, &index))
        return NULL;
    gtk_option_menu_set_history(GTK_OPTION_MENU(PyGtk_Get(option_menu)), index);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_tearoff_menu_item_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_tearoff_menu_item_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_tearoff_menu_item_get_type());
}

static PyObject *_wrap_gtk_tearoff_menu_item_new(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_tearoff_menu_item_new"))
        return NULL;
    return PyGtk_New((GtkObject *)gtk_tearoff_menu_item_new());
}

static PyObject *_wrap_gtk_item_factory_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_item_factory_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_item_factory_get_type());
}

static PyObject *_wrap_gtk_item_factory_new(PyObject *self, PyObject *args) {
    PyObject *group;
    char *path;
    int container_type;

    if (!PyArg_ParseTuple(args, "isO!:gtk_item_factory_new", &container_type, &path, &PyGtkAccelGroup_Type, &group))
        return NULL;
    return PyGtk_New((GtkObject *)gtk_item_factory_new(container_type, path, PyGtkAccelGroup_Get(group)));
}

static PyObject *_wrap_gtk_item_factory_parse_rc(PyObject *self, PyObject *args) {
    char *file_name;

    if (!PyArg_ParseTuple(args, "s:gtk_item_factory_parse_rc", &file_name))
        return NULL;
    gtk_item_factory_parse_rc(file_name);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_item_factory_parse_rc_string(PyObject *self, PyObject *args) {
    char *rc_string;

    if (!PyArg_ParseTuple(args, "s:gtk_item_factory_parse_rc_string", &rc_string))
        return NULL;
    gtk_item_factory_parse_rc_string(rc_string);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_item_factory_add_foreign(PyObject *self, PyObject *args) {
    PyObject *accel_widget, *accel_group, *py_modifiers;
    char *full_path;
    GdkModifierType modifiers;
    int keyval;

    if (!PyArg_ParseTuple(args, "O!sO!iO:gtk_item_factory_add_foreign", &PyGtk_Type, &accel_widget, &full_path, &PyGtkAccelGroup_Type, &accel_group, &keyval, &py_modifiers))
        return NULL;
    if (PyGtkFlag_get_value(GTK_TYPE_GDK_MODIFIER_TYPE, py_modifiers, (gint *)&modifiers))
        return NULL;
    gtk_item_factory_add_foreign(GTK_WIDGET(PyGtk_Get(accel_widget)), full_path, PyGtkAccelGroup_Get(accel_group), keyval, modifiers);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_item_factory_from_widget(PyObject *self, PyObject *args) {
    PyObject *widget;

    if (!PyArg_ParseTuple(args, "O!:gtk_item_factory_from_widget", &PyGtk_Type, &widget))
        return NULL;
    return PyGtk_New((GtkObject *)gtk_item_factory_from_widget(GTK_WIDGET(PyGtk_Get(widget))));
}

static PyObject *_wrap_gtk_item_factory_path_from_widget(PyObject *self, PyObject *args) {
    PyObject *widget;

    if (!PyArg_ParseTuple(args, "O!:gtk_item_factory_path_from_widget", &PyGtk_Type, &widget))
        return NULL;
    return PyString_FromString(gtk_item_factory_path_from_widget(GTK_WIDGET(PyGtk_Get(widget))));
}

static PyObject *_wrap_gtk_item_factory_delete_item(PyObject *self, PyObject *args) {
    char *path;
    PyObject *ifactory;

    if (!PyArg_ParseTuple(args, "O!s:gtk_item_factory_delete_item", &PyGtk_Type, &ifactory, &path))
        return NULL;
    gtk_item_factory_delete_item(GTK_ITEM_FACTORY(PyGtk_Get(ifactory)), path);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_item_factory_popup(PyObject *self, PyObject *args) {
    int x, y, mouse_button, time;
    PyObject *ifactory;

    if (!PyArg_ParseTuple(args, "O!iiii:gtk_item_factory_popup", &PyGtk_Type, &ifactory, &x, &y, &mouse_button, &time))
        return NULL;
    gtk_item_factory_popup(GTK_ITEM_FACTORY(PyGtk_Get(ifactory)), x, y, mouse_button, time);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_range_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_range_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_range_get_type());
}

static PyObject *_wrap_gtk_range_get_adjustment(PyObject *self, PyObject *args) {
    PyObject *range;

    if (!PyArg_ParseTuple(args, "O!:gtk_range_get_adjustment", &PyGtk_Type, &range))
        return NULL;
    return PyGtk_New((GtkObject *)gtk_range_get_adjustment(GTK_RANGE(PyGtk_Get(range))));
}

static PyObject *_wrap_gtk_range_set_update_policy(PyObject *self, PyObject *args) {
    GtkUpdateType policy;
    PyObject *range, *py_policy;

    if (!PyArg_ParseTuple(args, "O!O:gtk_range_set_update_policy", &PyGtk_Type, &range, &py_policy))
        return NULL;
    if (PyGtkEnum_get_value(GTK_TYPE_UPDATE_TYPE, py_policy, (gint *)&policy))
        return NULL;
    gtk_range_set_update_policy(GTK_RANGE(PyGtk_Get(range)), policy);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_range_set_adjustment(PyObject *self, PyObject *args) {
    PyObject *range, *adjustment;

    if (!PyArg_ParseTuple(args, "O!O!:gtk_range_set_adjustment", &PyGtk_Type, &range, &PyGtk_Type, &adjustment))
        return NULL;
    gtk_range_set_adjustment(GTK_RANGE(PyGtk_Get(range)), GTK_ADJUSTMENT(PyGtk_Get(adjustment)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_range_draw_background(PyObject *self, PyObject *args) {
    PyObject *range;

    if (!PyArg_ParseTuple(args, "O!:gtk_range_draw_background", &PyGtk_Type, &range))
        return NULL;
    gtk_range_draw_background(GTK_RANGE(PyGtk_Get(range)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_range_clear_background(PyObject *self, PyObject *args) {
    PyObject *range;

    if (!PyArg_ParseTuple(args, "O!:gtk_range_clear_background", &PyGtk_Type, &range))
        return NULL;
    gtk_range_clear_background(GTK_RANGE(PyGtk_Get(range)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_range_draw_trough(PyObject *self, PyObject *args) {
    PyObject *range;

    if (!PyArg_ParseTuple(args, "O!:gtk_range_draw_trough", &PyGtk_Type, &range))
        return NULL;
    gtk_range_draw_trough(GTK_RANGE(PyGtk_Get(range)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_range_draw_slider(PyObject *self, PyObject *args) {
    PyObject *range;

    if (!PyArg_ParseTuple(args, "O!:gtk_range_draw_slider", &PyGtk_Type, &range))
        return NULL;
    gtk_range_draw_slider(GTK_RANGE(PyGtk_Get(range)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_range_draw_step_forw(PyObject *self, PyObject *args) {
    PyObject *range;

    if (!PyArg_ParseTuple(args, "O!:gtk_range_draw_step_forw", &PyGtk_Type, &range))
        return NULL;
    gtk_range_draw_step_forw(GTK_RANGE(PyGtk_Get(range)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_range_draw_step_back(PyObject *self, PyObject *args) {
    PyObject *range;

    if (!PyArg_ParseTuple(args, "O!:gtk_range_draw_step_back", &PyGtk_Type, &range))
        return NULL;
    gtk_range_draw_step_back(GTK_RANGE(PyGtk_Get(range)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_range_slider_update(PyObject *self, PyObject *args) {
    PyObject *range;

    if (!PyArg_ParseTuple(args, "O!:gtk_range_slider_update", &PyGtk_Type, &range))
        return NULL;
    gtk_range_slider_update(GTK_RANGE(PyGtk_Get(range)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_scale_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_scale_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_scale_get_type());
}

static PyObject *_wrap_gtk_scale_set_digits(PyObject *self, PyObject *args) {
    int digits;
    PyObject *scale;

    if (!PyArg_ParseTuple(args, "O!i:gtk_scale_set_digits", &PyGtk_Type, &scale, &digits))
        return NULL;
    gtk_scale_set_digits(GTK_SCALE(PyGtk_Get(scale)), digits);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_scale_set_draw_value(PyObject *self, PyObject *args) {
    int draw_value;
    PyObject *scale;

    if (!PyArg_ParseTuple(args, "O!i:gtk_scale_set_draw_value", &PyGtk_Type, &scale, &draw_value))
        return NULL;
    gtk_scale_set_draw_value(GTK_SCALE(PyGtk_Get(scale)), draw_value);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_scale_set_value_pos(PyObject *self, PyObject *args) {
    GtkPositionType pos;
    PyObject *scale, *py_pos;

    if (!PyArg_ParseTuple(args, "O!O:gtk_scale_set_value_pos", &PyGtk_Type, &scale, &py_pos))
        return NULL;
    if (PyGtkEnum_get_value(GTK_TYPE_POSITION_TYPE, py_pos, (gint *)&pos))
        return NULL;
    gtk_scale_set_value_pos(GTK_SCALE(PyGtk_Get(scale)), pos);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_scale_get_value_width(PyObject *self, PyObject *args) {
    PyObject *scale;

    if (!PyArg_ParseTuple(args, "O!:gtk_scale_get_value_width", &PyGtk_Type, &scale))
        return NULL;
    return PyInt_FromLong(gtk_scale_get_value_width(GTK_SCALE(PyGtk_Get(scale))));
}

static PyObject *_wrap_gtk_scale_draw_value(PyObject *self, PyObject *args) {
    PyObject *scale;

    if (!PyArg_ParseTuple(args, "O!:gtk_scale_draw_value", &PyGtk_Type, &scale))
        return NULL;
    gtk_scale_draw_value(GTK_SCALE(PyGtk_Get(scale)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_hscale_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_hscale_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_hscale_get_type());
}

static PyObject *_wrap_gtk_hscale_new(PyObject *self, PyObject *args) {
    GtkAdjustment *adjustment = NULL;
    PyObject *py_adjustment = Py_None;

    if (!PyArg_ParseTuple(args, "O:gtk_hscale_new", &py_adjustment))
        return NULL;
    if (PyGtk_Check(py_adjustment))
        adjustment = GTK_ADJUSTMENT(PyGtk_Get(py_adjustment));
    else if (py_adjustment != Py_None) {
        PyErr_SetString(PyExc_TypeError, "adjustment argument must be a GtkAdjustment or None");
	return NULL;
    }
    return PyGtk_New((GtkObject *)gtk_hscale_new(adjustment));
}

static PyObject *_wrap_gtk_vscale_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_vscale_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_vscale_get_type());
}

static PyObject *_wrap_gtk_vscale_new(PyObject *self, PyObject *args) {
    GtkAdjustment *adjustment = NULL;
    PyObject *py_adjustment = Py_None;

    if (!PyArg_ParseTuple(args, "O:gtk_vscale_new", &py_adjustment))
        return NULL;
    if (PyGtk_Check(py_adjustment))
        adjustment = GTK_ADJUSTMENT(PyGtk_Get(py_adjustment));
    else if (py_adjustment != Py_None) {
        PyErr_SetString(PyExc_TypeError, "adjustment argument must be a GtkAdjustment or None");
	return NULL;
    }
    return PyGtk_New((GtkObject *)gtk_vscale_new(adjustment));
}

static PyObject *_wrap_gtk_scrollbar_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_scrollbar_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_scrollbar_get_type());
}

static PyObject *_wrap_gtk_hscrollbar_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_hscrollbar_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_hscrollbar_get_type());
}

static PyObject *_wrap_gtk_hscrollbar_new(PyObject *self, PyObject *args) {
    GtkAdjustment *adjustment = NULL;
    PyObject *py_adjustment = Py_None;

    if (!PyArg_ParseTuple(args, "O:gtk_hscrollbar_new", &py_adjustment))
        return NULL;
    if (PyGtk_Check(py_adjustment))
        adjustment = GTK_ADJUSTMENT(PyGtk_Get(py_adjustment));
    else if (py_adjustment != Py_None) {
        PyErr_SetString(PyExc_TypeError, "adjustment argument must be a GtkAdjustment or None");
	return NULL;
    }
    return PyGtk_New((GtkObject *)gtk_hscrollbar_new(adjustment));
}

static PyObject *_wrap_gtk_vscrollbar_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_vscrollbar_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_vscrollbar_get_type());
}

static PyObject *_wrap_gtk_vscrollbar_new(PyObject *self, PyObject *args) {
    GtkAdjustment *adjustment = NULL;
    PyObject *py_adjustment = Py_None;

    if (!PyArg_ParseTuple(args, "O:gtk_vscrollbar_new", &py_adjustment))
        return NULL;
    if (PyGtk_Check(py_adjustment))
        adjustment = GTK_ADJUSTMENT(PyGtk_Get(py_adjustment));
    else if (py_adjustment != Py_None) {
        PyErr_SetString(PyExc_TypeError, "adjustment argument must be a GtkAdjustment or None");
	return NULL;
    }
    return PyGtk_New((GtkObject *)gtk_vscrollbar_new(adjustment));
}

static PyObject *_wrap_gtk_ruler_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_ruler_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_ruler_get_type());
}

static PyObject *_wrap_gtk_ruler_set_metric(PyObject *self, PyObject *args) {
    GtkMetricType metric;
    PyObject *ruler, *py_metric;

    if (!PyArg_ParseTuple(args, "O!O:gtk_ruler_set_metric", &PyGtk_Type, &ruler, &py_metric))
        return NULL;
    if (PyGtkEnum_get_value(GTK_TYPE_METRIC_TYPE, py_metric, (gint *)&metric))
        return NULL;
    gtk_ruler_set_metric(GTK_RULER(PyGtk_Get(ruler)), metric);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_ruler_set_range(PyObject *self, PyObject *args) {
    double lower, upper, position, max_size;
    PyObject *ruler;

    if (!PyArg_ParseTuple(args, "O!dddd:gtk_ruler_set_range", &PyGtk_Type, &ruler, &lower, &upper, &position, &max_size))
        return NULL;
    gtk_ruler_set_range(GTK_RULER(PyGtk_Get(ruler)), lower, upper, position, max_size);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_ruler_draw_ticks(PyObject *self, PyObject *args) {
    PyObject *ruler;

    if (!PyArg_ParseTuple(args, "O!:gtk_ruler_draw_ticks", &PyGtk_Type, &ruler))
        return NULL;
    gtk_ruler_draw_ticks(GTK_RULER(PyGtk_Get(ruler)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_ruler_draw_pos(PyObject *self, PyObject *args) {
    PyObject *ruler;

    if (!PyArg_ParseTuple(args, "O!:gtk_ruler_draw_pos", &PyGtk_Type, &ruler))
        return NULL;
    gtk_ruler_draw_pos(GTK_RULER(PyGtk_Get(ruler)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_hruler_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_hruler_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_hruler_get_type());
}

static PyObject *_wrap_gtk_hruler_new(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_hruler_new"))
        return NULL;
    return PyGtk_New((GtkObject *)gtk_hruler_new());
}

static PyObject *_wrap_gtk_vruler_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_vruler_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_vruler_get_type());
}

static PyObject *_wrap_gtk_vruler_new(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_vruler_new"))
        return NULL;
    return PyGtk_New((GtkObject *)gtk_vruler_new());
}

static PyObject *_wrap_gtk_editable_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_editable_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_editable_get_type());
}

static PyObject *_wrap_gtk_editable_get_selection_start_pos(PyObject *self, PyObject *args) {
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_editable_get_selection_start_pos", &PyGtk_Type, &obj))
        return NULL;
    return PyInt_FromLong(GTK_EDITABLE(PyGtk_Get(obj))->selection_start_pos);
}

static PyObject *_wrap_gtk_editable_get_selection_end_pos(PyObject *self, PyObject *args) {
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_editable_get_selection_end_pos", &PyGtk_Type, &obj))
        return NULL;
    return PyInt_FromLong(GTK_EDITABLE(PyGtk_Get(obj))->selection_end_pos);
}

static PyObject *_wrap_gtk_editable_select_region(PyObject *self, PyObject *args) {
    int start, end;
    PyObject *editable;

    if (!PyArg_ParseTuple(args, "O!ii:gtk_editable_select_region", &PyGtk_Type, &editable, &start, &end))
        return NULL;
    gtk_editable_select_region(GTK_EDITABLE(PyGtk_Get(editable)), start, end);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_editable_delete_text(PyObject *self, PyObject *args) {
    int start, end;
    PyObject *editable;

    if (!PyArg_ParseTuple(args, "O!ii:gtk_editable_delete_text", &PyGtk_Type, &editable, &start, &end))
        return NULL;
    gtk_editable_delete_text(GTK_EDITABLE(PyGtk_Get(editable)), start, end);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_editable_get_chars(PyObject *self, PyObject *args) {
    int start, end;
    char *ret;
    PyObject *py_ret, *editable;

    if (!PyArg_ParseTuple(args, "O!ii:gtk_editable_get_chars", &PyGtk_Type, &editable, &start, &end))
        return NULL;
    ret = gtk_editable_get_chars(GTK_EDITABLE(PyGtk_Get(editable)), start, end);
    py_ret = PyString_FromString(ret);
    g_free(ret);
    return py_ret;
}

static PyObject *_wrap_gtk_editable_cut_clipboard(PyObject *self, PyObject *args) {
    PyObject *edtiable;

    if (!PyArg_ParseTuple(args, "O!:gtk_editable_cut_clipboard", &PyGtk_Type, &edtiable))
        return NULL;
    gtk_editable_cut_clipboard(GTK_EDITABLE(PyGtk_Get(edtiable)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_editable_copy_clipboard(PyObject *self, PyObject *args) {
    PyObject *editable;

    if (!PyArg_ParseTuple(args, "O!:gtk_editable_copy_clipboard", &PyGtk_Type, &editable))
        return NULL;
    gtk_editable_copy_clipboard(GTK_EDITABLE(PyGtk_Get(editable)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_editable_paste_clipboard(PyObject *self, PyObject *args) {
    PyObject *editable;

    if (!PyArg_ParseTuple(args, "O!:gtk_editable_paste_clipboard", &PyGtk_Type, &editable))
        return NULL;
    gtk_editable_paste_clipboard(GTK_EDITABLE(PyGtk_Get(editable)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_editable_claim_selection(PyObject *self, PyObject *args) {
    int claim, time;
    PyObject *editable;

    if (!PyArg_ParseTuple(args, "O!ii:gtk_editable_claim_selection", &PyGtk_Type, &editable, &claim, &time))
        return NULL;
    gtk_editable_claim_selection(GTK_EDITABLE(PyGtk_Get(editable)), claim, time);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_editable_delete_selection(PyObject *self, PyObject *args) {
    PyObject *editable;

    if (!PyArg_ParseTuple(args, "O!:gtk_editable_delete_selection", &PyGtk_Type, &editable))
        return NULL;
    gtk_editable_delete_selection(GTK_EDITABLE(PyGtk_Get(editable)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_editable_changed(PyObject *self, PyObject *args) {
    PyObject *editable;

    if (!PyArg_ParseTuple(args, "O!:gtk_editable_changed", &PyGtk_Type, &editable))
        return NULL;
    gtk_editable_changed(GTK_EDITABLE(PyGtk_Get(editable)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_editable_set_position(PyObject *self, PyObject *args) {
    int position;
    PyObject *editable;

    if (!PyArg_ParseTuple(args, "O!i:gtk_editable_set_position", &PyGtk_Type, &editable, &position))
        return NULL;
    gtk_editable_set_position(GTK_EDITABLE(PyGtk_Get(editable)), position);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_editable_get_position(PyObject *self, PyObject *args) {
    PyObject *editable;

    if (!PyArg_ParseTuple(args, "O!:gtk_editable_get_position", &PyGtk_Type, &editable))
        return NULL;
    return PyInt_FromLong(gtk_editable_get_position(GTK_EDITABLE(PyGtk_Get(editable))));
}

static PyObject *_wrap_gtk_editable_set_editable(PyObject *self, PyObject *args) {
    int is_editable;
    PyObject *editable;

    if (!PyArg_ParseTuple(args, "O!i:gtk_editable_set_editable", &PyGtk_Type, &editable, &is_editable))
        return NULL;
    gtk_editable_set_editable(GTK_EDITABLE(PyGtk_Get(editable)), is_editable);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_entry_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_entry_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_entry_get_type());
}

static PyObject *_wrap_gtk_entry_new(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_entry_new"))
        return NULL;
    return PyGtk_New((GtkObject *)gtk_entry_new());
}

static PyObject *_wrap_gtk_entry_new_with_max_length(PyObject *self, PyObject *args) {
    int max;

    if (!PyArg_ParseTuple(args, "i:gtk_entry_new_with_max_length", &max))
        return NULL;
    return PyGtk_New((GtkObject *)gtk_entry_new_with_max_length(max));
}

static PyObject *_wrap_gtk_entry_set_text(PyObject *self, PyObject *args) {
    char *text;
    PyObject *entry;

    if (!PyArg_ParseTuple(args, "O!s:gtk_entry_set_text", &PyGtk_Type, &entry, &text))
        return NULL;
    gtk_entry_set_text(GTK_ENTRY(PyGtk_Get(entry)), text);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_entry_append_text(PyObject *self, PyObject *args) {
    char *text;
    PyObject *entry;

    if (!PyArg_ParseTuple(args, "O!s:gtk_entry_append_text", &PyGtk_Type, &entry, &text))
        return NULL;
    gtk_entry_append_text(GTK_ENTRY(PyGtk_Get(entry)), text);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_entry_prepend_text(PyObject *self, PyObject *args) {
    char *text;
    PyObject *entry;

    if (!PyArg_ParseTuple(args, "O!s:gtk_entry_prepend_text", &PyGtk_Type, &entry, &text))
        return NULL;
    gtk_entry_prepend_text(GTK_ENTRY(PyGtk_Get(entry)), text);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_entry_set_position(PyObject *self, PyObject *args) {
    int position;
    PyObject *entry;

    if (!PyArg_ParseTuple(args, "O!i:gtk_entry_set_position", &PyGtk_Type, &entry, &position))
        return NULL;
    gtk_entry_set_position(GTK_ENTRY(PyGtk_Get(entry)), position);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_entry_get_text(PyObject *self, PyObject *args) {
    PyObject *entry;

    if (!PyArg_ParseTuple(args, "O!:gtk_entry_get_text", &PyGtk_Type, &entry))
        return NULL;
    return PyString_FromString(gtk_entry_get_text(GTK_ENTRY(PyGtk_Get(entry))));
}

static PyObject *_wrap_gtk_entry_select_region(PyObject *self, PyObject *args) {
    int start, end;
    PyObject *entry;

    if (!PyArg_ParseTuple(args, "O!ii:gtk_entry_select_region", &PyGtk_Type, &entry, &start, &end))
        return NULL;
    gtk_entry_select_region(GTK_ENTRY(PyGtk_Get(entry)), start, end);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_entry_set_visibility(PyObject *self, PyObject *args) {
    int visible;
    PyObject *entry;

    if (!PyArg_ParseTuple(args, "O!i:gtk_entry_set_visibility", &PyGtk_Type, &entry, &visible))
        return NULL;
    gtk_entry_set_visibility(GTK_ENTRY(PyGtk_Get(entry)), visible);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_entry_set_editable(PyObject *self, PyObject *args) {
    int editable;
    PyObject *entry;

    if (!PyArg_ParseTuple(args, "O!i:gtk_entry_set_editable", &PyGtk_Type, &entry, &editable))
        return NULL;
    gtk_entry_set_editable(GTK_ENTRY(PyGtk_Get(entry)), editable);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_entry_set_max_length(PyObject *self, PyObject *args) {
    int max;
    PyObject *entry;

    if (!PyArg_ParseTuple(args, "O!i:gtk_entry_set_max_length", &PyGtk_Type, &entry, &max))
        return NULL;
    gtk_entry_set_max_length(GTK_ENTRY(PyGtk_Get(entry)), max);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_spin_button_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_spin_button_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_spin_button_get_type());
}

static PyObject *_wrap_gtk_spin_button_new(PyObject *self, PyObject *args) {
    int digits;
    GtkAdjustment *adjustment = NULL;
    double climb_rate;
    PyObject *py_adjustment = Py_None;

    if (!PyArg_ParseTuple(args, "Odi:gtk_spin_button_new", &py_adjustment, &climb_rate, &digits))
        return NULL;
    if (PyGtk_Check(py_adjustment))
        adjustment = GTK_ADJUSTMENT(PyGtk_Get(py_adjustment));
    else if (py_adjustment != Py_None) {
        PyErr_SetString(PyExc_TypeError, "adjustment argument must be a GtkAdjustment or None");
	return NULL;
    }
    return PyGtk_New((GtkObject *)gtk_spin_button_new(adjustment, climb_rate, digits));
}

static PyObject *_wrap_gtk_spin_button_set_adjustment(PyObject *self, PyObject *args) {
    PyObject *spin_button, *adjustment;

    if (!PyArg_ParseTuple(args, "O!O!:gtk_spin_button_set_adjustment", &PyGtk_Type, &spin_button, &PyGtk_Type, &adjustment))
        return NULL;
    gtk_spin_button_set_adjustment(GTK_SPIN_BUTTON(PyGtk_Get(spin_button)), GTK_ADJUSTMENT(PyGtk_Get(adjustment)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_spin_button_get_adjustment(PyObject *self, PyObject *args) {
    PyObject *spin_button;

    if (!PyArg_ParseTuple(args, "O!:gtk_spin_button_get_adjustment", &PyGtk_Type, &spin_button))
        return NULL;
    return PyGtk_New((GtkObject *)gtk_spin_button_get_adjustment(GTK_SPIN_BUTTON(PyGtk_Get(spin_button))));
}

static PyObject *_wrap_gtk_spin_button_set_digits(PyObject *self, PyObject *args) {
    int digits;
    PyObject *spin_button;

    if (!PyArg_ParseTuple(args, "O!i:gtk_spin_button_set_digits", &PyGtk_Type, &spin_button, &digits))
        return NULL;
    gtk_spin_button_set_digits(GTK_SPIN_BUTTON(PyGtk_Get(spin_button)), digits);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_spin_button_get_value_as_float(PyObject *self, PyObject *args) {
    PyObject *spin_button;

    if (!PyArg_ParseTuple(args, "O!:gtk_spin_button_get_value_as_float", &PyGtk_Type, &spin_button))
        return NULL;
    return PyFloat_FromDouble(gtk_spin_button_get_value_as_float(GTK_SPIN_BUTTON(PyGtk_Get(spin_button))));
}

static PyObject *_wrap_gtk_spin_button_get_value_as_int(PyObject *self, PyObject *args) {
    PyObject *spin_button;

    if (!PyArg_ParseTuple(args, "O!:gtk_spin_button_get_value_as_int", &PyGtk_Type, &spin_button))
        return NULL;
    return PyInt_FromLong(gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(PyGtk_Get(spin_button))));
}

static PyObject *_wrap_gtk_spin_button_set_value(PyObject *self, PyObject *args) {
    double value;
    PyObject *spin_button;

    if (!PyArg_ParseTuple(args, "O!d:gtk_spin_button_set_value", &PyGtk_Type, &spin_button, &value))
        return NULL;
    gtk_spin_button_set_value(GTK_SPIN_BUTTON(PyGtk_Get(spin_button)), value);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_spin_button_set_update_policy(PyObject *self, PyObject *args) {
    GtkSpinButtonUpdatePolicy policy;
    PyObject *spin_button, *py_policy;

    if (!PyArg_ParseTuple(args, "O!O:gtk_spin_button_set_update_policy", &PyGtk_Type, &spin_button, &py_policy))
        return NULL;
    if (PyGtkEnum_get_value(GTK_TYPE_SPIN_BUTTON_UPDATE_POLICY, py_policy, (gint *)&policy))
        return NULL;
    gtk_spin_button_set_update_policy(GTK_SPIN_BUTTON(PyGtk_Get(spin_button)), policy);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_spin_button_set_numeric(PyObject *self, PyObject *args) {
    int numeric;
    PyObject *spin_button;

    if (!PyArg_ParseTuple(args, "O!i:gtk_spin_button_set_numeric", &PyGtk_Type, &spin_button, &numeric))
        return NULL;
    gtk_spin_button_set_numeric(GTK_SPIN_BUTTON(PyGtk_Get(spin_button)), numeric);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_spin_button_spin(PyObject *self, PyObject *args) {
    GtkSpinType direction;
    double increment;
    PyObject *spin_button, *py_direction;

    if (!PyArg_ParseTuple(args, "O!Od:gtk_spin_button_spin", &PyGtk_Type, &spin_button, &py_direction, &increment))
        return NULL;
    if (PyGtkEnum_get_value(GTK_TYPE_SPIN_TYPE, py_direction, (gint *)&direction))
        return NULL;
    gtk_spin_button_spin(GTK_SPIN_BUTTON(PyGtk_Get(spin_button)), direction, increment);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_spin_button_set_wrap(PyObject *self, PyObject *args) {
    int wrap;
    PyObject *spin_button;

    if (!PyArg_ParseTuple(args, "O!i:gtk_spin_button_set_wrap", &PyGtk_Type, &spin_button, &wrap))
        return NULL;
    gtk_spin_button_set_wrap(GTK_SPIN_BUTTON(PyGtk_Get(spin_button)), wrap);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_spin_button_set_shadow_type(PyObject *self, PyObject *args) {
    GtkShadowType shadow_type;
    PyObject *spin_button, *py_shadow_type;

    if (!PyArg_ParseTuple(args, "O!O:gtk_spin_button_set_shadow_type", &PyGtk_Type, &spin_button, &py_shadow_type))
        return NULL;
    if (PyGtkEnum_get_value(GTK_TYPE_SHADOW_TYPE, py_shadow_type, (gint *)&shadow_type))
        return NULL;
    gtk_spin_button_set_shadow_type(GTK_SPIN_BUTTON(PyGtk_Get(spin_button)), shadow_type);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_spin_button_set_snap_to_ticks(PyObject *self, PyObject *args) {
    int snap_to_ticks;
    PyObject *spin_button;

    if (!PyArg_ParseTuple(args, "O!i:gtk_spin_button_set_snap_to_ticks", &PyGtk_Type, &spin_button, &snap_to_ticks))
        return NULL;
    gtk_spin_button_set_snap_to_ticks(GTK_SPIN_BUTTON(PyGtk_Get(spin_button)), snap_to_ticks);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_spin_button_update(PyObject *self, PyObject *args) {
    PyObject *spin_button;

    if (!PyArg_ParseTuple(args, "O!:gtk_spin_button_update", &PyGtk_Type, &spin_button))
        return NULL;
    gtk_spin_button_update(GTK_SPIN_BUTTON(PyGtk_Get(spin_button)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_text_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_text_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_text_get_type());
}

static PyObject *_wrap_gtk_text_get_hadj(PyObject *self, PyObject *args) {
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_text_get_hadj", &PyGtk_Type, &obj))
        return NULL;
    return PyGtk_New((GtkObject *)GTK_TEXT(PyGtk_Get(obj))->hadj);
}

static PyObject *_wrap_gtk_text_get_vadj(PyObject *self, PyObject *args) {
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_text_get_vadj", &PyGtk_Type, &obj))
        return NULL;
    return PyGtk_New((GtkObject *)GTK_TEXT(PyGtk_Get(obj))->vadj);
}

static PyObject *_wrap_gtk_text_new(PyObject *self, PyObject *args) {
    GtkAdjustment *hadj = NULL, *vadj = NULL;
    PyObject *py_hadj = Py_None, *py_vadj = Py_None;

    if (!PyArg_ParseTuple(args, "|OO:gtk_text_new", &py_hadj, &py_vadj))
        return NULL;
    if (PyGtk_Check(py_hadj))
        hadj = GTK_ADJUSTMENT(PyGtk_Get(py_hadj));
    else if (py_hadj != Py_None) {
        PyErr_SetString(PyExc_TypeError, "hadj argument must be a GtkAdjustment or None");
	return NULL;
    }
    if (PyGtk_Check(py_vadj))
        vadj = GTK_ADJUSTMENT(PyGtk_Get(py_vadj));
    else if (py_vadj != Py_None) {
        PyErr_SetString(PyExc_TypeError, "vadj argument must be a GtkAdjustment or None");
	return NULL;
    }
    return PyGtk_New((GtkObject *)gtk_text_new(hadj, vadj));
}

static PyObject *_wrap_gtk_text_set_editable(PyObject *self, PyObject *args) {
    int editable;
    PyObject *text;

    if (!PyArg_ParseTuple(args, "O!i:gtk_text_set_editable", &PyGtk_Type, &text, &editable))
        return NULL;
    gtk_text_set_editable(GTK_TEXT(PyGtk_Get(text)), editable);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_text_set_word_wrap(PyObject *self, PyObject *args) {
    int word_wrap;
    PyObject *text;

    if (!PyArg_ParseTuple(args, "O!i:gtk_text_set_word_wrap", &PyGtk_Type, &text, &word_wrap))
        return NULL;
    gtk_text_set_word_wrap(GTK_TEXT(PyGtk_Get(text)), word_wrap);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_text_set_line_wrap(PyObject *self, PyObject *args) {
    int line_wrap;
    PyObject *text;

    if (!PyArg_ParseTuple(args, "O!i:gtk_text_set_line_wrap", &PyGtk_Type, &text, &line_wrap))
        return NULL;
    gtk_text_set_line_wrap(GTK_TEXT(PyGtk_Get(text)), line_wrap);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_text_set_adjustments(PyObject *self, PyObject *args) {
    GtkAdjustment *hadj = NULL, *vadj = NULL;
    PyObject *text, *py_hadj = Py_None, *py_vadj = Py_None;

    if (!PyArg_ParseTuple(args, "O!OO:gtk_text_set_adjustments", &PyGtk_Type, &text, &py_hadj, &py_vadj))
        return NULL;
    if (PyGtk_Check(py_hadj))
        hadj = GTK_ADJUSTMENT(PyGtk_Get(py_hadj));
    else if (py_hadj != Py_None) {
        PyErr_SetString(PyExc_TypeError, "hadj argument must be a GtkAdjustment or None");
	return NULL;
    }
    if (PyGtk_Check(py_vadj))
        vadj = GTK_ADJUSTMENT(PyGtk_Get(py_vadj));
    else if (py_vadj != Py_None) {
        PyErr_SetString(PyExc_TypeError, "vadj argument must be a GtkAdjustment or None");
	return NULL;
    }
    gtk_text_set_adjustments(GTK_TEXT(PyGtk_Get(text)), hadj, vadj);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_text_set_point(PyObject *self, PyObject *args) {
    int index;
    PyObject *text;

    if (!PyArg_ParseTuple(args, "O!i:gtk_text_set_point", &PyGtk_Type, &text, &index))
        return NULL;
    gtk_text_set_point(GTK_TEXT(PyGtk_Get(text)), index);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_text_get_point(PyObject *self, PyObject *args) {
    PyObject *text;

    if (!PyArg_ParseTuple(args, "O!:gtk_text_get_point", &PyGtk_Type, &text))
        return NULL;
    return PyInt_FromLong(gtk_text_get_point(GTK_TEXT(PyGtk_Get(text))));
}

static PyObject *_wrap_gtk_text_get_length(PyObject *self, PyObject *args) {
    PyObject *text;

    if (!PyArg_ParseTuple(args, "O!:gtk_text_get_length", &PyGtk_Type, &text))
        return NULL;
    return PyInt_FromLong(gtk_text_get_length(GTK_TEXT(PyGtk_Get(text))));
}

static PyObject *_wrap_gtk_text_freeze(PyObject *self, PyObject *args) {
    PyObject *text;

    if (!PyArg_ParseTuple(args, "O!:gtk_text_freeze", &PyGtk_Type, &text))
        return NULL;
    gtk_text_freeze(GTK_TEXT(PyGtk_Get(text)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_text_thaw(PyObject *self, PyObject *args) {
    PyObject *text;

    if (!PyArg_ParseTuple(args, "O!:gtk_text_thaw", &PyGtk_Type, &text))
        return NULL;
    gtk_text_thaw(GTK_TEXT(PyGtk_Get(text)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_text_insert(PyObject *self, PyObject *args) {
    PyObject *text, *py_font = Py_None, *py_fore = Py_None, *py_back = Py_None;
    char *chars;
    GdkColor *fore = NULL, *back = NULL;
    int length;
    GdkFont *font = NULL;

    if (!PyArg_ParseTuple(args, "O!OOOsi:gtk_text_insert", &PyGtk_Type, &text, &py_font, &py_fore, &py_back, &chars, &length))
        return NULL;
    if (PyGdkFont_Check(py_font))
        font = PyGdkFont_Get(py_font);
    else if (py_font != Py_None) {
        PyErr_SetString(PyExc_TypeError, "font argument must be a GdkFont or None");
	return NULL;
    }
    if (PyGdkColor_Check(py_fore))
        fore = PyGdkColor_Get(py_fore);
    else if (py_fore != Py_None) {
        PyErr_SetString(PyExc_TypeError, "fore argument must be a GdkColor or None");
	return NULL;
    }
    if (PyGdkColor_Check(py_back))
        back = PyGdkColor_Get(py_back);
    else if (py_back != Py_None) {
        PyErr_SetString(PyExc_TypeError, "back argument must be a GdkColor or None");
	return NULL;
    }
    gtk_text_insert(GTK_TEXT(PyGtk_Get(text)), font, fore, back, chars, length);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_text_backward_delete(PyObject *self, PyObject *args) {
    int nchars;
    PyObject *text;

    if (!PyArg_ParseTuple(args, "O!i:gtk_text_backward_delete", &PyGtk_Type, &text, &nchars))
        return NULL;
    gtk_text_backward_delete(GTK_TEXT(PyGtk_Get(text)), nchars);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_text_forward_delete(PyObject *self, PyObject *args) {
    int nchars;
    PyObject *text;

    if (!PyArg_ParseTuple(args, "O!i:gtk_text_forward_delete", &PyGtk_Type, &text, &nchars))
        return NULL;
    gtk_text_forward_delete(GTK_TEXT(PyGtk_Get(text)), nchars);
    Py_INCREF(Py_None);
    return Py_None;
}

