static PyObject *_wrap_gdk_gl_query(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gdk_gl_query"))
        return NULL;
    return PyInt_FromLong(gdk_gl_query());
}

static PyObject *_wrap_gdk_gl_use_gdk_font(PyObject *self, PyObject *args) {
    int first, count, list_base;
    PyObject *font;

    if (!PyArg_ParseTuple(args, "O!iii:gdk_gl_use_gdk_font", &PyGdkFont_Type, &font, &first, &count, &list_base))
        return NULL;
    gdk_gl_use_gdk_font(PyGdkFont_Get(font), first, count, list_base);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_gl_area_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_gl_area_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_gl_area_get_type());
}

static PyObject *_wrap_gtk_gl_area_make_current(PyObject *self, PyObject *args) {
    PyObject *glarea;

    if (!PyArg_ParseTuple(args, "O!:gtk_gl_area_make_current", &PyGtk_Type, &glarea))
        return NULL;
    return PyInt_FromLong(gtk_gl_area_make_current(GTK_GL_AREA(PyGtk_Get(glarea))));
}

static PyObject *_wrap_gtk_gl_area_swap_buffers(PyObject *self, PyObject *args) {
    PyObject *glarea;

    if (!PyArg_ParseTuple(args, "O!:gtk_gl_area_swap_buffers", &PyGtk_Type, &glarea))
        return NULL;
    gtk_gl_area_swap_buffers(GTK_GL_AREA(PyGtk_Get(glarea)));
    Py_INCREF(Py_None);
    return Py_None;
}

