static PyObject *_wrap_glade_xml_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":glade_xml_get_type"))
        return NULL;
    return PyInt_FromLong(glade_xml_get_type());
}

static PyObject *_wrap_glade_xml_new(PyObject *self, PyObject *args) {
    char *filename, *rooot;

    if (!PyArg_ParseTuple(args, "sz:glade_xml_new", &filename, &rooot))
        return NULL;
    return PyGtk_New((GtkObject *)glade_xml_new(filename, rooot));
}

static PyObject *_wrap_glade_xml_new_with_domain(PyObject *self, PyObject *args) {
    char *filename, *root, *domain;

    if (!PyArg_ParseTuple(args, "szz:glade_xml_new_with_domain", &filename, &root, &domain))
        return NULL;
    return PyGtk_New((GtkObject *)glade_xml_new_with_domain(filename, root, domain));
}

