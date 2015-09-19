static PyObject *_wrap_gv_view_area_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gv_view_area_get_type"))
        return NULL;
    return PyInt_FromLong(gv_view_area_get_type());
}

static PyObject *_wrap_gv_view_area_new(PyObject *self, PyObject *args) {
    GtkObject *retval;

    if (!PyArg_ParseTuple(args, ":gv_view_area_new"))
        return NULL;
    retval = (GtkObject *)gv_view_area_new();
    if (retval) return PyGtk_New(retval);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gv_view_area_get_width(PyObject *self, PyObject *args) {
    PyObject *view;

    if (!PyArg_ParseTuple(args, "O!:gv_view_area_get_width", &PyGtk_Type, &view))
        return NULL;
    return PyInt_FromLong(gv_view_area_get_width(GV_VIEW_AREA(PyGtk_Get(view))));
}

static PyObject *_wrap_gv_view_area_get_height(PyObject *self, PyObject *args) {
    PyObject *view;

    if (!PyArg_ParseTuple(args, "O!:gv_view_area_get_height", &PyGtk_Type, &view))
        return NULL;
    return PyInt_FromLong(gv_view_area_get_height(GV_VIEW_AREA(PyGtk_Get(view))));
}

static PyObject *_wrap_gv_view_area_add_layer(PyObject *self, PyObject *args) {
    PyObject *view, *layer;

    if (!PyArg_ParseTuple(args, "O!O!:gv_view_area_add_layer", &PyGtk_Type, &view, &PyGtk_Type, &layer))
        return NULL;
    gv_view_area_add_layer(GV_VIEW_AREA(PyGtk_Get(view)), GTK_OBJECT(PyGtk_Get(layer)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gv_view_area_remove_layer(PyObject *self, PyObject *args) {
    PyObject *view, *layer;

    if (!PyArg_ParseTuple(args, "O!O!:gv_view_area_remove_layer", &PyGtk_Type, &view, &PyGtk_Type, &layer))
        return NULL;
    gv_view_area_remove_layer(GV_VIEW_AREA(PyGtk_Get(view)), GTK_OBJECT(PyGtk_Get(layer)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gv_view_area_get_named_layer(PyObject *self, PyObject *args) {
    PyObject *view;
    const char *layer_name;
    GtkObject *retval;

    if (!PyArg_ParseTuple(args, "O!s:gv_view_area_get_named_layer", &PyGtk_Type, &view, &layer_name))
        return NULL;
    retval = (GtkObject *)gv_view_area_get_named_layer(GV_VIEW_AREA(PyGtk_Get(view)), layer_name);
    if (retval) return PyGtk_New(retval);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gv_view_area_active_layer(PyObject *self, PyObject *args) {
    PyObject *view;
    GtkObject *retval;

    if (!PyArg_ParseTuple(args, "O!:gv_view_area_active_layer", &PyGtk_Type, &view))
        return NULL;
    retval = (GtkObject *)gv_view_area_active_layer(GV_VIEW_AREA(PyGtk_Get(view)));
    if (retval) return PyGtk_New(retval);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gv_view_area_set_active_layer(PyObject *self, PyObject *args) {
    PyObject *area, *layer;

    if (!PyArg_ParseTuple(args, "O!O!:gv_view_area_set_active_layer", &PyGtk_Type, &area, &PyGtk_Type, &layer))
        return NULL;
    gv_view_area_set_active_layer(GV_VIEW_AREA(PyGtk_Get(area)), GTK_OBJECT(PyGtk_Get(layer)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gv_view_area_swap_layers(PyObject *self, PyObject *args) {
    PyObject *area;
    int layer_a, layer_b;

    if (!PyArg_ParseTuple(args, "O!ii:gv_view_area_swap_layers", &PyGtk_Type, &area, &layer_a, &layer_b))
        return NULL;
    gv_view_area_swap_layers(GV_VIEW_AREA(PyGtk_Get(area)), layer_a, layer_b);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gv_view_area_zoom(PyObject *self, PyObject *args) {
    PyObject *area;
    double zoom;

    if (!PyArg_ParseTuple(args, "O!d:gv_view_area_zoom", &PyGtk_Type, &area, &zoom))
        return NULL;
    gv_view_area_zoom(GV_VIEW_AREA(PyGtk_Get(area)), zoom);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gv_view_area_get_zoom(PyObject *self, PyObject *args) {
    PyObject *view;

    if (!PyArg_ParseTuple(args, "O!:gv_view_area_get_zoom", &PyGtk_Type, &view))
        return NULL;
    return PyFloat_FromDouble(gv_view_area_get_zoom(GV_VIEW_AREA(PyGtk_Get(view))));
}

static PyObject *_wrap_gv_view_area_get_flip_x(PyObject *self, PyObject *args) {
    PyObject *area;

    if (!PyArg_ParseTuple(args, "O!:gv_view_area_get_flip_x", &PyGtk_Type, &area))
        return NULL;
    return PyInt_FromLong(gv_view_area_get_flip_x(GV_VIEW_AREA(PyGtk_Get(area))));
}

static PyObject *_wrap_gv_view_area_get_flip_y(PyObject *self, PyObject *args) {
    PyObject *area;

    if (!PyArg_ParseTuple(args, "O!:gv_view_area_get_flip_y", &PyGtk_Type, &area))
        return NULL;
    return PyInt_FromLong(gv_view_area_get_flip_y(GV_VIEW_AREA(PyGtk_Get(area))));
}

static PyObject *_wrap_gv_view_area_set_flip_xy(PyObject *self, PyObject *args) {
    PyObject *area;
    int flip_x, flip_y;

    if (!PyArg_ParseTuple(args, "O!ii:gv_view_area_set_flip_xy", &PyGtk_Type, &area, &flip_x, &flip_y))
        return NULL;
    gv_view_area_set_flip_xy(GV_VIEW_AREA(PyGtk_Get(area)), flip_x, flip_y);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gv_view_area_rotate(PyObject *self, PyObject *args) {
    PyObject *area;
    double angle;

    if (!PyArg_ParseTuple(args, "O!d:gv_view_area_rotate", &PyGtk_Type, &area, &angle))
        return NULL;
    gv_view_area_rotate(GV_VIEW_AREA(PyGtk_Get(area)), angle);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gv_view_area_translate(PyObject *self, PyObject *args) {
    PyObject *area;
    double dx, dy;

    if (!PyArg_ParseTuple(args, "O!dd:gv_view_area_translate", &PyGtk_Type, &area, &dx, &dy))
        return NULL;
    gv_view_area_translate(GV_VIEW_AREA(PyGtk_Get(area)), dx, dy);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gv_view_area_set_translation(PyObject *self, PyObject *args) {
    PyObject *area;
    double x, y;

    if (!PyArg_ParseTuple(args, "O!dd:gv_view_area_set_translation", &PyGtk_Type, &area, &x, &y))
        return NULL;
    gv_view_area_set_translation(GV_VIEW_AREA(PyGtk_Get(area)), x, y);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gv_view_area_fit_extents(PyObject *self, PyObject *args) {
    PyObject *area;
    double llx, llyy, width, height;

    if (!PyArg_ParseTuple(args, "O!dddd:gv_view_area_fit_extents", &PyGtk_Type, &area, &llx, &llyy, &width, &height))
        return NULL;
    gv_view_area_fit_extents(GV_VIEW_AREA(PyGtk_Get(area)), llx, llyy, width, height);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gv_view_area_fit_all_layers(PyObject *self, PyObject *args) {
    PyObject *area;

    if (!PyArg_ParseTuple(args, "O!:gv_view_area_fit_all_layers", &PyGtk_Type, &area))
        return NULL;
    gv_view_area_fit_all_layers(GV_VIEW_AREA(PyGtk_Get(area)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gv_view_area_set_projection(PyObject *self, PyObject *args) {
    PyObject *area;
    const char *proj_name;

    if (!PyArg_ParseTuple(args, "O!s:gv_view_area_set_projection", &PyGtk_Type, &area, &proj_name))
        return NULL;
    gv_view_area_set_projection(GV_VIEW_AREA(PyGtk_Get(area)), proj_name);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gv_view_area_get_projection(PyObject *self, PyObject *args) {
    PyObject *area;
    const char *ret;

    if (!PyArg_ParseTuple(args, "O!:gv_view_area_get_projection", &PyGtk_Type, &area))
        return NULL;
    ret = gv_view_area_get_projection(GV_VIEW_AREA(PyGtk_Get(area)));
    if( ret != NULL)
        return PyString_FromString(ret);
    else
    {
        Py_INCREF(Py_None);
        return Py_None;
    }
}

static PyObject *_wrap_gv_view_area_copy_state(PyObject *self, PyObject *args) {
    PyObject *area, *source;

    if (!PyArg_ParseTuple(args, "O!O!:gv_view_area_copy_state", &PyGtk_Type, &area, &PyGtk_Type, &source))
        return NULL;
    gv_view_area_copy_state(GV_VIEW_AREA(PyGtk_Get(area)), GV_VIEW_AREA(PyGtk_Get(source)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gv_view_area_print_to_file(PyObject *self, PyObject *args) {
    PyObject *area;
    int width, height, is_rgb;
    char *filename, *format;

    if (!PyArg_ParseTuple(args, "O!iissi:gv_view_area_print_to_file", &PyGtk_Type, &area, &width, &height, &filename, &format, &is_rgb))
        return NULL;
    return PyInt_FromLong(gv_view_area_print_to_file(GV_VIEW_AREA(PyGtk_Get(area)), width, height, filename, format, is_rgb));
}

static PyObject *_wrap_gv_view_area_print_postscript_to_file(PyObject *self, PyObject *args) {
    PyObject *area;
    int width, height, is_rgb;
    char *filename;
    double ulx, uly, lrx, lry;

    if (!PyArg_ParseTuple(args, "O!iiddddis:gv_view_area_print_postscript_to_file", &PyGtk_Type, &area, &width, &height, &ulx, &uly, &lrx, &lry, &is_rgb, &filename))
        return NULL;
    return PyInt_FromLong(gv_view_area_print_postscript_to_file(GV_VIEW_AREA(PyGtk_Get(area)), width, height, ulx, uly, lrx, lry, is_rgb, filename));
}

static PyObject *_wrap_gv_view_area_page_setup(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gv_view_area_page_setup"))
        return NULL;
    gv_view_area_page_setup();
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gv_view_area_print_to_windriver(PyObject *self, PyObject *args) {
    PyObject *area;
    int width, height, is_rgb;
    double ulx, uly, lrx, lry;

    if (!PyArg_ParseTuple(args, "O!iiddddi:gv_view_area_print_to_windriver", &PyGtk_Type, &area, &width, &height, &ulx, &uly, &lrx, &lry, &is_rgb))
        return NULL;
    return PyInt_FromLong(gv_view_area_print_to_windriver(GV_VIEW_AREA(PyGtk_Get(area)), width, height, ulx, uly, lrx, lry, is_rgb));
}

static PyObject *_wrap_gv_view_area_set_mode(PyObject *self, PyObject *args) {
    PyObject *area;
    int flag_3d;

    if (!PyArg_ParseTuple(args, "O!i:gv_view_area_set_mode", &PyGtk_Type, &area, &flag_3d))
        return NULL;
    gv_view_area_set_mode(GV_VIEW_AREA(PyGtk_Get(area)), flag_3d);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gv_view_area_get_mode(PyObject *self, PyObject *args) {
    PyObject *area;

    if (!PyArg_ParseTuple(args, "O!:gv_view_area_get_mode", &PyGtk_Type, &area))
        return NULL;
    return PyInt_FromLong(gv_view_area_get_mode(GV_VIEW_AREA(PyGtk_Get(area))));
}

static PyObject *_wrap_gv_view_area_height_scale(PyObject *self, PyObject *args) {
    PyObject *area;
    double scale;

    if (!PyArg_ParseTuple(args, "O!d:gv_view_area_height_scale", &PyGtk_Type, &area, &scale))
        return NULL;
    gv_view_area_height_scale(GV_VIEW_AREA(PyGtk_Get(area)), scale);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gv_view_area_get_height_scale(PyObject *self, PyObject *args) {
    PyObject *area;

    if (!PyArg_ParseTuple(args, "O!:gv_view_area_get_height_scale", &PyGtk_Type, &area))
        return NULL;
    return PyFloat_FromDouble(gv_view_area_get_height_scale(GV_VIEW_AREA(PyGtk_Get(area))));
}

static PyObject *_wrap_gv_view_area_queue_draw(PyObject *self, PyObject *args) {
    PyObject *area;

    if (!PyArg_ParseTuple(args, "O!:gv_view_area_queue_draw", &PyGtk_Type, &area))
        return NULL;
    gv_view_area_queue_draw(GV_VIEW_AREA(PyGtk_Get(area)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gv_view_area_get_raw(PyObject *self, PyObject *args) {
    PyObject *area, *ref_layer;

    if (!PyArg_ParseTuple(args, "O!O!:gv_view_area_get_raw", &PyGtk_Type, &area, &PyGtk_Type, &ref_layer))
        return NULL;
    return PyInt_FromLong(gv_view_area_get_raw(GV_VIEW_AREA(PyGtk_Get(area)), GTK_OBJECT(PyGtk_Get(ref_layer))));
}

static PyObject *_wrap_gv_view_area_set_raw(PyObject *self, PyObject *args) {
    PyObject *area, *ref_layer;
    int raw_enable;

    if (!PyArg_ParseTuple(args, "O!O!i:gv_view_area_set_raw", &PyGtk_Type, &area, &PyGtk_Type, &ref_layer, &raw_enable))
        return NULL;
    return PyInt_FromLong(gv_view_area_set_raw(GV_VIEW_AREA(PyGtk_Get(area)), GTK_OBJECT(PyGtk_Get(ref_layer)), raw_enable));
}

static PyObject *_wrap_gv_view_area_get_property(PyObject *self, PyObject *args) {
    PyObject *area;
    const char *ret;
    char *name;

    if (!PyArg_ParseTuple(args, "O!s:gv_view_area_get_property", &PyGtk_Type, &area, &name))
        return NULL;
    ret = gv_view_area_get_property(GV_VIEW_AREA(PyGtk_Get(area)), name);
    if( ret != NULL)
        return PyString_FromString(ret);
    else
    {
        Py_INCREF(Py_None);
        return Py_None;
    }
}

static PyObject *_wrap_gv_view_area_set_property(PyObject *self, PyObject *args) {
    PyObject *area;
    const char *name, *value;

    if (!PyArg_ParseTuple(args, "O!ss:gv_view_area_set_property", &PyGtk_Type, &area, &name, &value))
        return NULL;
    gv_view_area_set_property(GV_VIEW_AREA(PyGtk_Get(area)), name, value);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gv_data_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gv_data_get_type"))
        return NULL;
    return PyInt_FromLong(gv_data_get_type());
}

static PyObject *_wrap_gv_data_is_read_only(PyObject *self, PyObject *args) {
    PyObject *data;

    if (!PyArg_ParseTuple(args, "O!:gv_data_is_read_only", &PyGtk_Type, &data))
        return NULL;
    return PyInt_FromLong(gv_data_is_read_only(GV_DATA(PyGtk_Get(data))));
}

static PyObject *_wrap_gv_data_set_read_only(PyObject *self, PyObject *args) {
    PyObject *data;
    int read_only;

    if (!PyArg_ParseTuple(args, "O!i:gv_data_set_read_only", &PyGtk_Type, &data, &read_only))
        return NULL;
    gv_data_set_read_only(GV_DATA(PyGtk_Get(data)), read_only);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gv_data_get_name(PyObject *self, PyObject *args) {
    PyObject *data;
    const char *ret;

    if (!PyArg_ParseTuple(args, "O!:gv_data_get_name", &PyGtk_Type, &data))
        return NULL;
    ret = gv_data_get_name(GV_DATA(PyGtk_Get(data)));
    if( ret != NULL)
        return PyString_FromString(ret);
    else
    {
        Py_INCREF(Py_None);
        return Py_None;
    }
}

static PyObject *_wrap_gv_data_set_name(PyObject *self, PyObject *args) {
    PyObject *data;
    char *name;

    if (!PyArg_ParseTuple(args, "O!s:gv_data_set_name", &PyGtk_Type, &data, &name))
        return NULL;
    gv_data_set_name(GV_DATA(PyGtk_Get(data)), name);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gv_data_get_projection(PyObject *self, PyObject *args) {
    PyObject *data;
    const char *ret;

    if (!PyArg_ParseTuple(args, "O!:gv_data_get_projection", &PyGtk_Type, &data))
        return NULL;
    ret = gv_data_get_projection(GV_DATA(PyGtk_Get(data)));
    if( ret != NULL)
        return PyString_FromString(ret);
    else
    {
        Py_INCREF(Py_None);
        return Py_None;
    }
}

static PyObject *_wrap_gv_data_set_projection(PyObject *self, PyObject *args) {
    PyObject *data;
    char *projection;

    if (!PyArg_ParseTuple(args, "O!s:gv_data_set_projection", &PyGtk_Type, &data, &projection))
        return NULL;
    gv_data_set_projection(GV_DATA(PyGtk_Get(data)), projection);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gv_data_get_property(PyObject *self, PyObject *args) {
    PyObject *data;
    const char *ret;
    char *name;

    if (!PyArg_ParseTuple(args, "O!s:gv_data_get_property", &PyGtk_Type, &data, &name))
        return NULL;
    ret = gv_data_get_property(GV_DATA(PyGtk_Get(data)), name);
    if( ret != NULL)
        return PyString_FromString(ret);
    else
    {
        Py_INCREF(Py_None);
        return Py_None;
    }
}

static PyObject *_wrap_gv_data_set_property(PyObject *self, PyObject *args) {
    PyObject *data;
    const char *name, *value;

    if (!PyArg_ParseTuple(args, "O!ss:gv_data_set_property", &PyGtk_Type, &data, &name, &value))
        return NULL;
    gv_data_set_property(GV_DATA(PyGtk_Get(data)), name, value);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gv_data_freeze(PyObject *self, PyObject *args) {
    PyObject *data;

    if (!PyArg_ParseTuple(args, "O!:gv_data_freeze", &PyGtk_Type, &data))
        return NULL;
    gv_data_freeze(GV_DATA(PyGtk_Get(data)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gv_data_thaw(PyObject *self, PyObject *args) {
    PyObject *data;

    if (!PyArg_ParseTuple(args, "O!:gv_data_thaw", &PyGtk_Type, &data))
        return NULL;
    gv_data_thaw(GV_DATA(PyGtk_Get(data)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gv_data_get_parent(PyObject *self, PyObject *args) {
    PyObject *data;
    GtkObject *retval;

    if (!PyArg_ParseTuple(args, "O!:gv_data_get_parent", &PyGtk_Type, &data))
        return NULL;
    retval = (GtkObject *)gv_data_get_parent(GV_DATA(PyGtk_Get(data)));
    if (retval) return PyGtk_New(retval);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gv_data_registry_dump(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gv_data_registry_dump"))
        return NULL;
    gv_data_registry_dump();
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gv_records_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gv_records_get_type"))
        return NULL;
    return PyInt_FromLong(gv_records_get_type());
}

static PyObject *_wrap_gv_records_new(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gv_records_new"))
        return NULL;
    return PyGtk_New((GtkObject *)gv_records_new());
}

static PyObject *_wrap_gv_records_from_dbf(PyObject *self, PyObject *args) {
    char *filename;
    PyProgressData sProgressInfo = {NULL,NULL,-1};
    GtkObject *retval;

    if (!PyArg_ParseTuple(args, "sOO:gv_records_from_dbf", &filename, &(sProgressInfo.psPyCallback), &(sProgressInfo.psPyCallbackData)))
        return NULL;
    retval = (GtkObject *)gv_records_from_dbf(filename, PyProgressProxy, &sProgressInfo);
    if (retval) return PyGtk_New(retval);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gv_records_from_rec(PyObject *self, PyObject *args) {
    char *filename;
    PyProgressData sProgressInfo = {NULL,NULL,-1};
    GtkObject *retval;

    if (!PyArg_ParseTuple(args, "sOO:gv_records_from_rec", &filename, &(sProgressInfo.psPyCallback), &(sProgressInfo.psPyCallbackData)))
        return NULL;
    retval = (GtkObject *)gv_records_from_rec(filename, PyProgressProxy, &sProgressInfo);
    if (retval) return PyGtk_New(retval);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gv_records_create_records(PyObject *self, PyObject *args) {
    PyObject *records;
    int new_records;

    if (!PyArg_ParseTuple(args, "O!i:gv_records_create_records", &PyGtk_Type, &records, &new_records))
        return NULL;
    return PyInt_FromLong(gv_records_create_records(GV_RECORDS(PyGtk_Get(records)), new_records));
}

static PyObject *_wrap_gv_records_num_records(PyObject *self, PyObject *args) {
    PyObject *records;

    if (!PyArg_ParseTuple(args, "O!:gv_records_num_records", &PyGtk_Type, &records))
        return NULL;
    return PyInt_FromLong(gv_records_num_records(GV_RECORDS(PyGtk_Get(records))));
}

static PyObject *_wrap_gv_records_add_field(PyObject *self, PyObject *args) {
    PyObject *records;
    const char *name;
    int rft, width, precision;

    if (!PyArg_ParseTuple(args, "O!siii:gv_records_add_field", &PyGtk_Type, &records, &name, &rft, &width, &precision))
        return NULL;
    return PyInt_FromLong(gv_records_add_field(GV_RECORDS(PyGtk_Get(records)), name, rft, width, precision));
}

static PyObject *_wrap_gv_records_set_raw_field_data(PyObject *self, PyObject *args) {
    PyObject *records;
    int record_index, field_index;
    const char *value = NULL;

    if (!PyArg_ParseTuple(args, "O!ii|z:gv_records_set_raw_field_data", &PyGtk_Type, &records, &record_index, &field_index, &value))
        return NULL;
    gv_records_set_raw_field_data(GV_RECORDS(PyGtk_Get(records)), record_index, field_index, value);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gv_records_get_raw_field_data(PyObject *self, PyObject *args) {
    PyObject *records;
    const char *ret;
    int record_index, field_index;

    if (!PyArg_ParseTuple(args, "O!ii:gv_records_get_raw_field_data", &PyGtk_Type, &records, &record_index, &field_index))
        return NULL;
    ret = gv_records_get_raw_field_data(GV_RECORDS(PyGtk_Get(records)), record_index, field_index);
    if( ret != NULL)
        return PyString_FromString(ret);
    else
    {
        Py_INCREF(Py_None);
        return Py_None;
    }
}

static PyObject *_wrap_gv_shapes_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gv_shapes_get_type"))
        return NULL;
    return PyInt_FromLong(gv_shapes_get_type());
}

static PyObject *_wrap_gv_shapes_new(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gv_shapes_new"))
        return NULL;
    return PyGtk_New((GtkObject *)gv_shapes_new());
}

static PyObject *_wrap_gv_shapes_from_shapefile(PyObject *self, PyObject *args) {
    char *filename;
    GtkObject *retval;

    if (!PyArg_ParseTuple(args, "s:gv_shapes_from_shapefile", &filename))
        return NULL;
    retval = (GtkObject *)gv_shapes_from_shapefile(filename);
    if (retval) return PyGtk_New(retval);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gv_shapes_to_shapefile(PyObject *self, PyObject *args) {
    char *filename;
    PyObject *data;
    int shp_type;

    if (!PyArg_ParseTuple(args, "sO!i:gv_shapes_to_shapefile", &filename, &PyGtk_Type, &data, &shp_type))
        return NULL;
    return PyInt_FromLong(gv_shapes_to_shapefile(filename, GV_DATA(PyGtk_Get(data)), shp_type));
}

static PyObject *_wrap_gv_shapes_from_ogr(PyObject *self, PyObject *args) {
    char *filename;
    int layer;
    GtkObject *retval;

    if (!PyArg_ParseTuple(args, "si:gv_shapes_from_ogr", &filename, &layer))
        return NULL;
    retval = (GtkObject *)gv_shapes_from_ogr(filename, layer);
    if (retval) return PyGtk_New(retval);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gv_have_ogr_support(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gv_have_ogr_support"))
        return NULL;
    return PyInt_FromLong(gv_have_ogr_support());
}

static PyObject *_wrap_gv_shapes_num_shapes(PyObject *self, PyObject *args) {
    PyObject *shapes;

    if (!PyArg_ParseTuple(args, "O!:gv_shapes_num_shapes", &PyGtk_Type, &shapes))
        return NULL;
    return PyInt_FromLong(gv_shapes_num_shapes(GV_SHAPES(PyGtk_Get(shapes))));
}

static PyObject *_wrap_gv_shapes_add_height(PyObject *self, PyObject *args) {
    PyObject *shapes, *raster;
    double offset, default_height;

    if (!PyArg_ParseTuple(args, "O!O!dd:gv_shapes_add_height", &PyGtk_Type, &shapes, &PyGtk_Type, &raster, &offset, &default_height))
        return NULL;
    gv_shapes_add_height(GV_SHAPES(PyGtk_Get(shapes)), GV_DATA(PyGtk_Get(raster)), offset, default_height);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gv_shape_get_count(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gv_shape_get_count"))
        return NULL;
    return PyInt_FromLong(gv_shape_get_count());
}

static PyObject *_wrap_gv_points_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gv_points_get_type"))
        return NULL;
    return PyInt_FromLong(gv_points_get_type());
}

static PyObject *_wrap_gv_points_new(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gv_points_new"))
        return NULL;
    return PyGtk_New((GtkObject *)gv_points_new());
}

static PyObject *_wrap_gv_points_num_points(PyObject *self, PyObject *args) {
    PyObject *points;

    if (!PyArg_ParseTuple(args, "O!:gv_points_num_points", &PyGtk_Type, &points))
        return NULL;
    return PyInt_FromLong(gv_points_num_points(GV_POINTS(PyGtk_Get(points))));
}

static PyObject *_wrap_gv_polylines_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gv_polylines_get_type"))
        return NULL;
    return PyInt_FromLong(gv_polylines_get_type());
}

static PyObject *_wrap_gv_polylines_new(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gv_polylines_new"))
        return NULL;
    return PyGtk_New((GtkObject *)gv_polylines_new());
}

static PyObject *_wrap_gv_polylines_num_lines(PyObject *self, PyObject *args) {
    PyObject *lines;

    if (!PyArg_ParseTuple(args, "O!:gv_polylines_num_lines", &PyGtk_Type, &lines))
        return NULL;
    return PyInt_FromLong(gv_polylines_num_lines(GV_POLYLINES(PyGtk_Get(lines))));
}

static PyObject *_wrap_gv_areas_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gv_areas_get_type"))
        return NULL;
    return PyInt_FromLong(gv_areas_get_type());
}

static PyObject *_wrap_gv_areas_new(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gv_areas_new"))
        return NULL;
    return PyGtk_New((GtkObject *)gv_areas_new());
}

static PyObject *_wrap_gv_areas_num_areas(PyObject *self, PyObject *args) {
    PyObject *areas;

    if (!PyArg_ParseTuple(args, "O!:gv_areas_num_areas", &PyGtk_Type, &areas))
        return NULL;
    return PyInt_FromLong(gv_areas_num_areas(GV_AREAS(PyGtk_Get(areas))));
}

static PyObject *_wrap_gv_layer_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gv_layer_get_type"))
        return NULL;
    return PyInt_FromLong(gv_layer_get_type());
}

static PyObject *_wrap_gv_layer_is_visible(PyObject *self, PyObject *args) {
    PyObject *layer;

    if (!PyArg_ParseTuple(args, "O!:gv_layer_is_visible", &PyGtk_Type, &layer))
        return NULL;
    return PyInt_FromLong(gv_layer_is_visible(GV_LAYER(PyGtk_Get(layer))));
}

static PyObject *_wrap_gv_layer_set_visible(PyObject *self, PyObject *args) {
    PyObject *layer;
    int visible;

    if (!PyArg_ParseTuple(args, "O!i:gv_layer_set_visible", &PyGtk_Type, &layer, &visible))
        return NULL;
    gv_layer_set_visible(GV_LAYER(PyGtk_Get(layer)), visible);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gv_layer_reproject(PyObject *self, PyObject *args) {
    PyObject *layer;
    char *projection;

    if (!PyArg_ParseTuple(args, "O!s:gv_layer_reproject", &PyGtk_Type, &layer, &projection))
        return NULL;
    return PyInt_FromLong(gv_layer_reproject(GV_LAYER(PyGtk_Get(layer)), projection));
}

static PyObject *_wrap_gv_layer_get_view(PyObject *self, PyObject *args) {
    PyObject *layer;

    if (!PyArg_ParseTuple(args, "O!:gv_layer_get_view", &PyGtk_Type, &layer))
        return NULL;
    return PyGtk_New((GtkObject *)gv_layer_get_view(GV_LAYER(PyGtk_Get(layer))));
}

static PyObject *_wrap_gv_shape_layer_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gv_shape_layer_get_type"))
        return NULL;
    return PyInt_FromLong(gv_shape_layer_get_type());
}

static PyObject *_wrap_gv_shape_layer_clear_selection(PyObject *self, PyObject *args) {
    PyObject *layer;

    if (!PyArg_ParseTuple(args, "O!:gv_shape_layer_clear_selection", &PyGtk_Type, &layer))
        return NULL;
    gv_shape_layer_clear_selection(GV_SHAPE_LAYER(PyGtk_Get(layer)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gv_shape_layer_select_all(PyObject *self, PyObject *args) {
    PyObject *layer;

    if (!PyArg_ParseTuple(args, "O!:gv_shape_layer_select_all", &PyGtk_Type, &layer))
        return NULL;
    gv_shape_layer_select_all(GV_SHAPE_LAYER(PyGtk_Get(layer)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gv_shape_layer_select_shape(PyObject *self, PyObject *args) {
    PyObject *layer;
    int shape_id;

    if (!PyArg_ParseTuple(args, "O!i:gv_shape_layer_select_shape", &PyGtk_Type, &layer, &shape_id))
        return NULL;
    gv_shape_layer_select_shape(GV_SHAPE_LAYER(PyGtk_Get(layer)), shape_id);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gv_shape_layer_deselect_shape(PyObject *self, PyObject *args) {
    PyObject *layer;
    int shape_id;

    if (!PyArg_ParseTuple(args, "O!i:gv_shape_layer_deselect_shape", &PyGtk_Type, &layer, &shape_id))
        return NULL;
    gv_shape_layer_deselect_shape(GV_SHAPE_LAYER(PyGtk_Get(layer)), shape_id);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gv_shape_layer_subselect_shape(PyObject *self, PyObject *args) {
    PyObject *layer;
    int shape_id;

    if (!PyArg_ParseTuple(args, "O!i:gv_shape_layer_subselect_shape", &PyGtk_Type, &layer, &shape_id))
        return NULL;
    gv_shape_layer_subselect_shape(GV_SHAPE_LAYER(PyGtk_Get(layer)), shape_id);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gv_shape_layer_get_subselection(PyObject *self, PyObject *args) {
    PyObject *layer;

    if (!PyArg_ParseTuple(args, "O!:gv_shape_layer_get_subselection", &PyGtk_Type, &layer))
        return NULL;
    return PyInt_FromLong(gv_shape_layer_get_subselection(GV_SHAPE_LAYER(PyGtk_Get(layer))));
}

static PyObject *_wrap_gv_shapes_layer_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gv_shapes_layer_get_type"))
        return NULL;
    return PyInt_FromLong(gv_shapes_layer_get_type());
}

static PyObject *_wrap_gv_shapes_layer_new(PyObject *self, PyObject *args) {
    PyObject *py_shapes = Py_None;
    GvShapes *shapes = NULL;

    if (!PyArg_ParseTuple(args, "|O:gv_shapes_layer_new", &py_shapes))
        return NULL;
    if (PyGtk_Check(py_shapes))
        shapes = GV_SHAPES(PyGtk_Get(py_shapes));
    else if (py_shapes != Py_None) {
        PyErr_SetString(PyExc_TypeError, "shapes argument must be a GvShapes or None");
        return NULL;
    }
    return PyGtk_New((GtkObject *)gv_shapes_layer_new(shapes));
}

static PyObject *_wrap_gv_shapes_layer_get_symbol_manager(PyObject *self, PyObject *args) {
    PyObject *layer;
    int ok_to_create;
    GtkObject *retval;

    if (!PyArg_ParseTuple(args, "O!i:gv_shapes_layer_get_symbol_manager", &PyGtk_Type, &layer, &ok_to_create))
        return NULL;
    retval = (GtkObject *)gv_shapes_layer_get_symbol_manager(GV_SHAPES_LAYER(PyGtk_Get(layer)), ok_to_create);
    if (retval) return PyGtk_New(retval);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gv_point_layer_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gv_point_layer_get_type"))
        return NULL;
    return PyInt_FromLong(gv_point_layer_get_type());
}

static PyObject *_wrap_gv_point_layer_new(PyObject *self, PyObject *args) {
    PyObject *py_points = Py_None;
    GvPoints *points = NULL;

    if (!PyArg_ParseTuple(args, "|O:gv_point_layer_new", &py_points))
        return NULL;
    if (PyGtk_Check(py_points))
        points = GV_POINTS(PyGtk_Get(py_points));
    else if (py_points != Py_None) {
        PyErr_SetString(PyExc_TypeError, "points argument must be a GvPoints or None");
        return NULL;
    }
    return PyGtk_New((GtkObject *)gv_point_layer_new(points));
}

static PyObject *_wrap_gv_line_layer_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gv_line_layer_get_type"))
        return NULL;
    return PyInt_FromLong(gv_line_layer_get_type());
}

static PyObject *_wrap_gv_line_layer_new(PyObject *self, PyObject *args) {
    PyObject *py_lines = Py_None;
    GvPolylines *lines = NULL;

    if (!PyArg_ParseTuple(args, "|O:gv_line_layer_new", &py_lines))
        return NULL;
    if (PyGtk_Check(py_lines))
        lines = GV_POLYLINES(PyGtk_Get(py_lines));
    else if (py_lines != Py_None) {
        PyErr_SetString(PyExc_TypeError, "lines argument must be a GvPolylines or None");
        return NULL;
    }
    return PyGtk_New((GtkObject *)gv_line_layer_new(lines));
}

static PyObject *_wrap_gv_area_layer_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gv_area_layer_get_type"))
        return NULL;
    return PyInt_FromLong(gv_area_layer_get_type());
}

static PyObject *_wrap_gv_area_layer_new(PyObject *self, PyObject *args) {
    PyObject *py_areas = Py_None;
    GvAreas *areas = NULL;

    if (!PyArg_ParseTuple(args, "|O:gv_area_layer_new", &py_areas))
        return NULL;
    if (PyGtk_Check(py_areas))
        areas = GV_AREAS(PyGtk_Get(py_areas));
    else if (py_areas != Py_None) {
        PyErr_SetString(PyExc_TypeError, "areas argument must be a GvAreas or None");
        return NULL;
    }
    return PyGtk_New((GtkObject *)gv_area_layer_new(areas));
}

static PyObject *_wrap_gv_pquery_layer_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gv_pquery_layer_get_type"))
        return NULL;
    return PyInt_FromLong(gv_pquery_layer_get_type());
}

static PyObject *_wrap_gv_pquery_layer_new(PyObject *self, PyObject *args) {
    PyObject *py_shapes = Py_None;
    GvShapes *shapes = NULL;

    if (!PyArg_ParseTuple(args, "|O:gv_pquery_layer_new", &py_shapes))
        return NULL;
    if (PyGtk_Check(py_shapes))
        shapes = GV_SHAPES(PyGtk_Get(py_shapes));
    else if (py_shapes != Py_None) {
        PyErr_SetString(PyExc_TypeError, "shapes argument must be a GvShapes or None");
        return NULL;
    }
    return PyGtk_New((GtkObject *)gv_pquery_layer_new(shapes));
}

static PyObject *_wrap_ip_gcp_layer_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":ip_gcp_layer_get_type"))
        return NULL;
    return PyInt_FromLong(ip_gcp_layer_get_type());
}

static PyObject *_wrap_ip_gcp_layer_new(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":ip_gcp_layer_new"))
        return NULL;
    return PyGtk_New((GtkObject *)ip_gcp_layer_new());
}

static PyObject *_wrap_app_cur_layer_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":app_cur_layer_get_type"))
        return NULL;
    return PyInt_FromLong(app_cur_layer_get_type());
}

static PyObject *_wrap_app_cur_layer_new(PyObject *self, PyObject *args) {
    PyObject *py_shapes = Py_None;
    GvShapes *shapes = NULL;

    if (!PyArg_ParseTuple(args, "O:app_cur_layer_new", &py_shapes))
        return NULL;
    if (PyGtk_Check(py_shapes))
        shapes = GV_SHAPES(PyGtk_Get(py_shapes));
    else if (py_shapes != Py_None) {
        PyErr_SetString(PyExc_TypeError, "shapes argument must be a GvShapes or None");
        return NULL;
    }
    return PyGtk_New((GtkObject *)app_cur_layer_new(shapes));
}

static PyObject *_wrap_gv_symbol_manager_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gv_symbol_manager_get_type"))
        return NULL;
    return PyInt_FromLong(gv_symbol_manager_get_type());
}

static PyObject *_wrap_gv_get_symbol_manager(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gv_get_symbol_manager"))
        return NULL;
    return PyGtk_New((GtkObject *)gv_get_symbol_manager());
}

static PyObject *_wrap_gv_symbol_manager_eject_symbol(PyObject *self, PyObject *args) {
    PyObject *manager;
    const char *name;

    if (!PyArg_ParseTuple(args, "O!s:gv_symbol_manager_eject_symbol", &PyGtk_Type, &manager, &name))
        return NULL;
    gv_symbol_manager_eject_symbol(GV_SYMBOL_MANAGER(PyGtk_Get(manager)), name);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gv_symbol_manager_has_symbol(PyObject *self, PyObject *args) {
    PyObject *manager;
    const char *name;

    if (!PyArg_ParseTuple(args, "O!s:gv_symbol_manager_has_symbol", &PyGtk_Type, &manager, &name))
        return NULL;
    return PyInt_FromLong(gv_symbol_manager_has_symbol(GV_SYMBOL_MANAGER(PyGtk_Get(manager)), name));
}

static PyObject *_wrap_gv_manager_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gv_manager_get_type"))
        return NULL;
    return PyInt_FromLong(gv_manager_get_type());
}

static PyObject *_wrap_gv_get_manager(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gv_get_manager"))
        return NULL;
    return PyGtk_New((GtkObject *)gv_get_manager());
}

static PyObject *_wrap_gv_manager_get_preference(PyObject *self, PyObject *args) {
    PyObject *manager;
    const char *ret, *name;

    if (!PyArg_ParseTuple(args, "O!s:gv_manager_get_preference", &PyGtk_Type, &manager, &name))
        return NULL;
    ret = gv_manager_get_preference(GV_MANAGER(PyGtk_Get(manager)), name);
    if( ret != NULL)
        return PyString_FromString(ret);
    else
    {
        Py_INCREF(Py_None);
        return Py_None;
    }
}

static PyObject *_wrap_gv_manager_set_preference(PyObject *self, PyObject *args) {
    PyObject *manager;
    const char *name, *value;

    if (!PyArg_ParseTuple(args, "O!ss:gv_manager_set_preference", &PyGtk_Type, &manager, &name, &value))
        return NULL;
    gv_manager_set_preference(GV_MANAGER(PyGtk_Get(manager)), name, value);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gv_manager_get_busy(PyObject *self, PyObject *args) {
    PyObject *manager;

    if (!PyArg_ParseTuple(args, "O!:gv_manager_get_busy", &PyGtk_Type, &manager))
        return NULL;
    return PyInt_FromLong(gv_manager_get_busy(GV_MANAGER(PyGtk_Get(manager))));
}

static PyObject *_wrap_gv_manager_set_busy(PyObject *self, PyObject *args) {
    PyObject *manager;
    int busy;

    if (!PyArg_ParseTuple(args, "O!i:gv_manager_set_busy", &PyGtk_Type, &manager, &busy))
        return NULL;
    gv_manager_set_busy(GV_MANAGER(PyGtk_Get(manager)), busy);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gv_manager_dump(PyObject *self, PyObject *args) {
    PyObject *manager;

    if (!PyArg_ParseTuple(args, "O!:gv_manager_dump", &PyGtk_Type, &manager))
        return NULL;
    gv_manager_dump(GV_MANAGER(PyGtk_Get(manager)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gv_tool_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gv_tool_get_type"))
        return NULL;
    return PyInt_FromLong(gv_tool_get_type());
}

static PyObject *_wrap_gv_tool_activate(PyObject *self, PyObject *args) {
    PyObject *tool, *view;

    if (!PyArg_ParseTuple(args, "O!O!:gv_tool_activate", &PyGtk_Type, &tool, &PyGtk_Type, &view))
        return NULL;
    gv_tool_activate(GV_TOOL(PyGtk_Get(tool)), GV_VIEW_AREA(PyGtk_Get(view)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gv_tool_deactivate(PyObject *self, PyObject *args) {
    PyObject *tool, *view;

    if (!PyArg_ParseTuple(args, "O!O!:gv_tool_deactivate", &PyGtk_Type, &tool, &PyGtk_Type, &view))
        return NULL;
    gv_tool_deactivate(GV_TOOL(PyGtk_Get(tool)), GV_VIEW_AREA(PyGtk_Get(view)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gv_tool_get_view(PyObject *self, PyObject *args) {
    PyObject *tool;
    GtkObject *retval;

    if (!PyArg_ParseTuple(args, "O!:gv_tool_get_view", &PyGtk_Type, &tool))
        return NULL;
    retval = (GtkObject *)gv_tool_get_view(GV_TOOL(PyGtk_Get(tool)));
    if (retval) return PyGtk_New(retval);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gv_tool_set_cursor(PyObject *self, PyObject *args) {
    PyObject *tool;
    int cursor_type;

    if (!PyArg_ParseTuple(args, "O!i:gv_tool_set_cursor", &PyGtk_Type, &tool, &cursor_type))
        return NULL;
    gv_tool_set_cursor(GV_TOOL(PyGtk_Get(tool)), cursor_type);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gv_selection_tool_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gv_selection_tool_get_type"))
        return NULL;
    return PyInt_FromLong(gv_selection_tool_get_type());
}

static PyObject *_wrap_gv_selection_tool_new(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gv_selection_tool_new"))
        return NULL;
    return PyGtk_New((GtkObject *)gv_selection_tool_new());
}

static PyObject *_wrap_gv_selection_tool_set_layer(PyObject *self, PyObject *args) {
    PyObject *tool, *layer;

    if (!PyArg_ParseTuple(args, "O!O!:gv_selection_tool_set_layer", &PyGtk_Type, &tool, &PyGtk_Type, &layer))
        return NULL;
    gv_selection_tool_set_layer(GV_SELECTION_TOOL(PyGtk_Get(tool)), GV_SHAPE_LAYER(PyGtk_Get(layer)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gv_zoompan_tool_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gv_zoompan_tool_get_type"))
        return NULL;
    return PyInt_FromLong(gv_zoompan_tool_get_type());
}

static PyObject *_wrap_gv_zoompan_tool_new(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gv_zoompan_tool_new"))
        return NULL;
    return PyGtk_New((GtkObject *)gv_zoompan_tool_new());
}

static PyObject *_wrap_gv_point_tool_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gv_point_tool_get_type"))
        return NULL;
    return PyInt_FromLong(gv_point_tool_get_type());
}

static PyObject *_wrap_gv_point_tool_new(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gv_point_tool_new"))
        return NULL;
    return PyGtk_New((GtkObject *)gv_point_tool_new());
}

static PyObject *_wrap_gv_point_tool_set_layer(PyObject *self, PyObject *args) {
    PyObject *tool, *layer;

    if (!PyArg_ParseTuple(args, "O!O!:gv_point_tool_set_layer", &PyGtk_Type, &tool, &PyGtk_Type, &layer))
        return NULL;
    gv_point_tool_set_layer(GV_POINT_TOOL(PyGtk_Get(tool)), GV_SHAPE_LAYER(PyGtk_Get(layer)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gv_point_tool_set_named_layer(PyObject *self, PyObject *args) {
    PyObject *tool;
    char *name;

    if (!PyArg_ParseTuple(args, "O!s:gv_point_tool_set_named_layer", &PyGtk_Type, &tool, &name))
        return NULL;
    gv_point_tool_set_named_layer(GV_POINT_TOOL(PyGtk_Get(tool)), name);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gv_line_tool_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gv_line_tool_get_type"))
        return NULL;
    return PyInt_FromLong(gv_line_tool_get_type());
}

static PyObject *_wrap_gv_line_tool_new(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gv_line_tool_new"))
        return NULL;
    return PyGtk_New((GtkObject *)gv_line_tool_new());
}

static PyObject *_wrap_gv_line_tool_set_layer(PyObject *self, PyObject *args) {
    PyObject *tool, *layer;

    if (!PyArg_ParseTuple(args, "O!O!:gv_line_tool_set_layer", &PyGtk_Type, &tool, &PyGtk_Type, &layer))
        return NULL;
    gv_line_tool_set_layer(GV_LINE_TOOL(PyGtk_Get(tool)), GV_SHAPE_LAYER(PyGtk_Get(layer)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gv_line_tool_set_named_layer(PyObject *self, PyObject *args) {
    PyObject *tool;
    char *name;

    if (!PyArg_ParseTuple(args, "O!s:gv_line_tool_set_named_layer", &PyGtk_Type, &tool, &name))
        return NULL;
    gv_line_tool_set_named_layer(GV_LINE_TOOL(PyGtk_Get(tool)), name);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gv_rect_tool_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gv_rect_tool_get_type"))
        return NULL;
    return PyInt_FromLong(gv_rect_tool_get_type());
}

static PyObject *_wrap_gv_rect_tool_new(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gv_rect_tool_new"))
        return NULL;
    return PyGtk_New((GtkObject *)gv_rect_tool_new());
}

static PyObject *_wrap_gv_rect_tool_set_layer(PyObject *self, PyObject *args) {
    PyObject *tool, *layer;

    if (!PyArg_ParseTuple(args, "O!O!:gv_rect_tool_set_layer", &PyGtk_Type, &tool, &PyGtk_Type, &layer))
        return NULL;
    gv_rect_tool_set_layer(GV_RECT_TOOL(PyGtk_Get(tool)), GV_SHAPE_LAYER(PyGtk_Get(layer)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gv_rect_tool_set_named_layer(PyObject *self, PyObject *args) {
    PyObject *tool;
    char *name;

    if (!PyArg_ParseTuple(args, "O!s:gv_rect_tool_set_named_layer", &PyGtk_Type, &tool, &name))
        return NULL;
    gv_rect_tool_set_named_layer(GV_RECT_TOOL(PyGtk_Get(tool)), name);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gv_rotate_tool_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gv_rotate_tool_get_type"))
        return NULL;
    return PyInt_FromLong(gv_rotate_tool_get_type());
}

static PyObject *_wrap_gv_rotate_tool_new(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gv_rotate_tool_new"))
        return NULL;
    return PyGtk_New((GtkObject *)gv_rotate_tool_new());
}

static PyObject *_wrap_gv_rotate_tool_set_layer(PyObject *self, PyObject *args) {
    PyObject *tool, *layer;

    if (!PyArg_ParseTuple(args, "O!O!:gv_rotate_tool_set_layer", &PyGtk_Type, &tool, &PyGtk_Type, &layer))
        return NULL;
    gv_rotate_tool_set_layer(GV_ROTATE_TOOL(PyGtk_Get(tool)), GV_SHAPE_LAYER(PyGtk_Get(layer)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gv_rotate_tool_set_named_layer(PyObject *self, PyObject *args) {
    PyObject *tool;
    char *name;

    if (!PyArg_ParseTuple(args, "O!s:gv_rotate_tool_set_named_layer", &PyGtk_Type, &tool, &name))
        return NULL;
    gv_rotate_tool_set_named_layer(GV_ROTATE_TOOL(PyGtk_Get(tool)), name);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gv_area_tool_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gv_area_tool_get_type"))
        return NULL;
    return PyInt_FromLong(gv_area_tool_get_type());
}

static PyObject *_wrap_gv_area_tool_new(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gv_area_tool_new"))
        return NULL;
    return PyGtk_New((GtkObject *)gv_area_tool_new());
}

static PyObject *_wrap_gv_area_tool_set_layer(PyObject *self, PyObject *args) {
    PyObject *tool, *layer;

    if (!PyArg_ParseTuple(args, "O!O!:gv_area_tool_set_layer", &PyGtk_Type, &tool, &PyGtk_Type, &layer))
        return NULL;
    gv_area_tool_set_layer(GV_AREA_TOOL(PyGtk_Get(tool)), GV_SHAPE_LAYER(PyGtk_Get(layer)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gv_area_tool_set_named_layer(PyObject *self, PyObject *args) {
    PyObject *tool;
    char *name;

    if (!PyArg_ParseTuple(args, "O!s:gv_area_tool_set_named_layer", &PyGtk_Type, &tool, &name))
        return NULL;
    gv_area_tool_set_named_layer(GV_AREA_TOOL(PyGtk_Get(tool)), name);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gv_node_tool_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gv_node_tool_get_type"))
        return NULL;
    return PyInt_FromLong(gv_node_tool_get_type());
}

static PyObject *_wrap_gv_node_tool_new(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gv_node_tool_new"))
        return NULL;
    return PyGtk_New((GtkObject *)gv_node_tool_new());
}

static PyObject *_wrap_gv_node_tool_set_layer(PyObject *self, PyObject *args) {
    PyObject *tool, *layer;

    if (!PyArg_ParseTuple(args, "O!O!:gv_node_tool_set_layer", &PyGtk_Type, &tool, &PyGtk_Type, &layer))
        return NULL;
    gv_node_tool_set_layer(GV_NODE_TOOL(PyGtk_Get(tool)), GV_SHAPE_LAYER(PyGtk_Get(layer)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gv_roi_tool_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gv_roi_tool_get_type"))
        return NULL;
    return PyInt_FromLong(gv_roi_tool_get_type());
}

static PyObject *_wrap_gv_roi_tool_new(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gv_roi_tool_new"))
        return NULL;
    return PyGtk_New((GtkObject *)gv_roi_tool_new());
}

static PyObject *_wrap_gv_poi_tool_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gv_poi_tool_get_type"))
        return NULL;
    return PyInt_FromLong(gv_poi_tool_get_type());
}

static PyObject *_wrap_gv_poi_tool_new(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gv_poi_tool_new"))
        return NULL;
    return PyGtk_New((GtkObject *)gv_poi_tool_new());
}

static PyObject *_wrap_gv_track_tool_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gv_track_tool_get_type"))
        return NULL;
    return PyInt_FromLong(gv_track_tool_get_type());
}

static PyObject *_wrap_gv_track_tool_new(PyObject *self, PyObject *args) {
    PyObject *label;

    if (!PyArg_ParseTuple(args, "O!:gv_track_tool_new", &PyGtk_Type, &label))
        return NULL;
    return PyGtk_New((GtkObject *)gv_track_tool_new(GTK_OBJECT(PyGtk_Get(label))));
}

static PyObject *_wrap_gv_toolbox_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gv_toolbox_get_type"))
        return NULL;
    return PyInt_FromLong(gv_toolbox_get_type());
}

static PyObject *_wrap_gv_toolbox_new(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gv_toolbox_new"))
        return NULL;
    return PyGtk_New((GtkObject *)gv_toolbox_new());
}

static PyObject *_wrap_gv_toolbox_add_tool(PyObject *self, PyObject *args) {
    PyObject *toolbox, *tool;
    char *name;

    if (!PyArg_ParseTuple(args, "O!sO!:gv_toolbox_add_tool", &PyGtk_Type, &toolbox, &name, &PyGtk_Type, &tool))
        return NULL;
    gv_toolbox_add_tool(GV_TOOLBOX(PyGtk_Get(toolbox)), name, GV_TOOL(PyGtk_Get(tool)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gv_toolbox_activate_tool(PyObject *self, PyObject *args) {
    PyObject *toolbox;
    char *name;

    if (!PyArg_ParseTuple(args, "O!s:gv_toolbox_activate_tool", &PyGtk_Type, &toolbox, &name))
        return NULL;
    gv_toolbox_activate_tool(GV_TOOLBOX(PyGtk_Get(toolbox)), name);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gv_undo_register_data(PyObject *self, PyObject *args) {
    PyObject *data;

    if (!PyArg_ParseTuple(args, "O!:gv_undo_register_data", &PyGtk_Type, &data))
        return NULL;
    gv_undo_register_data(GV_DATA(PyGtk_Get(data)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gv_undo_pop(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gv_undo_pop"))
        return NULL;
    gv_undo_pop();
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gv_undo_clear(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gv_undo_clear"))
        return NULL;
    gv_undo_clear();
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gv_undo_can_undo(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gv_undo_can_undo"))
        return NULL;
    return PyInt_FromLong(gv_undo_can_undo());
}

static PyObject *_wrap_gv_undo_close(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gv_undo_close"))
        return NULL;
    gv_undo_close();
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gv_undo_open(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gv_undo_open"))
        return NULL;
    gv_undo_open();
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gv_undo_start_group(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gv_undo_start_group"))
        return NULL;
    return PyInt_FromLong(gv_undo_start_group());
}

static PyObject *_wrap_gv_undo_end_group(PyObject *self, PyObject *args) {
    int group;

    if (!PyArg_ParseTuple(args, "i:gv_undo_end_group", &group))
        return NULL;
    gv_undo_end_group(group);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gv_view_link_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gv_view_link_get_type"))
        return NULL;
    return PyInt_FromLong(gv_view_link_get_type());
}

static PyObject *_wrap_gv_view_link_new(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gv_view_link_new"))
        return NULL;
    return PyGtk_New((GtkObject *)gv_view_link_new());
}

static PyObject *_wrap_gv_view_link_register_view(PyObject *self, PyObject *args) {
    PyObject *link, *view;

    if (!PyArg_ParseTuple(args, "O!O!:gv_view_link_register_view", &PyGtk_Type, &link, &PyGtk_Type, &view))
        return NULL;
    gv_view_link_register_view(GV_VIEW_LINK(PyGtk_Get(link)), GV_VIEW_AREA(PyGtk_Get(view)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gv_view_link_remove_view(PyObject *self, PyObject *args) {
    PyObject *link, *view;

    if (!PyArg_ParseTuple(args, "O!O!:gv_view_link_remove_view", &PyGtk_Type, &link, &PyGtk_Type, &view))
        return NULL;
    gv_view_link_remove_view(GV_VIEW_LINK(PyGtk_Get(link)), GV_VIEW_AREA(PyGtk_Get(view)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gv_view_link_enable(PyObject *self, PyObject *args) {
    PyObject *link;

    if (!PyArg_ParseTuple(args, "O!:gv_view_link_enable", &PyGtk_Type, &link))
        return NULL;
    gv_view_link_enable(GV_VIEW_LINK(PyGtk_Get(link)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gv_view_link_disable(PyObject *self, PyObject *args) {
    PyObject *link;

    if (!PyArg_ParseTuple(args, "O!:gv_view_link_disable", &PyGtk_Type, &link))
        return NULL;
    gv_view_link_disable(GV_VIEW_LINK(PyGtk_Get(link)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gv_view_link_set_cursor_mode(PyObject *self, PyObject *args) {
    PyObject *link;
    int cursor_mode;

    if (!PyArg_ParseTuple(args, "O!i:gv_view_link_set_cursor_mode", &PyGtk_Type, &link, &cursor_mode))
        return NULL;
    gv_view_link_set_cursor_mode(GV_VIEW_LINK(PyGtk_Get(link)), cursor_mode);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gv_raster_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gv_raster_get_type"))
        return NULL;
    return PyInt_FromLong(gv_raster_get_type());
}

static PyObject *_wrap_gv_raster_flush_cache(PyObject *self, PyObject *args) {
    PyObject *raster;
    int x_off, y_off, width, height;

    if (!PyArg_ParseTuple(args, "O!iiii:gv_raster_flush_cache", &PyGtk_Type, &raster, &x_off, &y_off, &width, &height))
        return NULL;
    gv_raster_flush_cache(GV_RASTER(PyGtk_Get(raster)), x_off, y_off, width, height);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gv_raster_get_min(PyObject *self, PyObject *args) {
    PyObject *raster;

    if (!PyArg_ParseTuple(args, "O!:gv_raster_get_min", &PyGtk_Type, &raster))
        return NULL;
    return PyFloat_FromDouble(gv_raster_get_min(GV_RASTER(PyGtk_Get(raster))));
}

static PyObject *_wrap_gv_raster_get_max(PyObject *self, PyObject *args) {
    PyObject *raster;

    if (!PyArg_ParseTuple(args, "O!:gv_raster_get_max", &PyGtk_Type, &raster))
        return NULL;
    return PyFloat_FromDouble(gv_raster_get_max(GV_RASTER(PyGtk_Get(raster))));
}

static PyObject *_wrap_gv_raster_cache_get_max(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gv_raster_cache_get_max"))
        return NULL;
    return PyInt_FromLong(gv_raster_cache_get_max());
}

static PyObject *_wrap_gv_raster_cache_get_used(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gv_raster_cache_get_used"))
        return NULL;
    return PyInt_FromLong(gv_raster_cache_get_used());
}

static PyObject *_wrap_gv_raster_cache_set_max(PyObject *self, PyObject *args) {
    int new_max;

    if (!PyArg_ParseTuple(args, "i:gv_raster_cache_set_max", &new_max))
        return NULL;
    gv_raster_cache_set_max(new_max);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gv_raster_set_poly_order_preference(PyObject *self, PyObject *args) {
    PyObject *raster;
    int poly_order;

    if (!PyArg_ParseTuple(args, "O!i:gv_raster_set_poly_order_preference", &PyGtk_Type, &raster, &poly_order))
        return NULL;
    gv_raster_set_poly_order_preference(GV_RASTER(PyGtk_Get(raster)), poly_order);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gv_raster_layer_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gv_raster_layer_get_type"))
        return NULL;
    return PyInt_FromLong(gv_raster_layer_get_type());
}

static PyObject *_wrap_gv_raster_layer_lut_color_wheel_new(PyObject *self, PyObject *args) {
    PyObject *layer;
    int h_type, s_type, v_type;
    double h_param, s_param, v_param;

    if (!PyArg_ParseTuple(args, "O!ididid:gv_raster_layer_lut_color_wheel_new", &PyGtk_Type, &layer, &h_type, &h_param, &s_type, &s_param, &v_type, &v_param))
        return NULL;
    return PyInt_FromLong(gv_raster_layer_lut_color_wheel_new(GV_RASTER_LAYER(PyGtk_Get(layer)), h_type, h_param, s_type, s_param, v_type, v_param));
}

static PyObject *_wrap_gv_raster_layer_lut_color_wheel_new_ev(PyObject *self, PyObject *args) {
    PyObject *layer;
    int set_phase, set_magnitude;

    if (!PyArg_ParseTuple(args, "O!ii:gv_raster_layer_lut_color_wheel_new_ev", &PyGtk_Type, &layer, &set_phase, &set_magnitude))
        return NULL;
    return PyInt_FromLong(gv_raster_layer_lut_color_wheel_new_ev(GV_RASTER_LAYER(PyGtk_Get(layer)), set_phase, set_magnitude));
}

static PyObject *_wrap_gv_raster_layer_lut_color_wheel_1d_new(PyObject *self, PyObject *args) {
    PyObject *layer;
    double s, v, offset;

    if (!PyArg_ParseTuple(args, "O!ddd:gv_raster_layer_lut_color_wheel_1d_new", &PyGtk_Type, &layer, &s, &v, &offset))
        return NULL;
    return PyInt_FromLong(gv_raster_layer_lut_color_wheel_1d_new(GV_RASTER_LAYER(PyGtk_Get(layer)), s, v, offset));
}

static PyObject *_wrap_gv_raster_layer_alpha_set(PyObject *self, PyObject *args) {
    PyObject *layer;
    int alpha_mode;
    double alpha_check_val;

    if (!PyArg_ParseTuple(args, "O!id:gv_raster_layer_alpha_set", &PyGtk_Type, &layer, &alpha_mode, &alpha_check_val))
        return NULL;
    return PyInt_FromLong(gv_raster_layer_alpha_set(GV_RASTER_LAYER(PyGtk_Get(layer)), alpha_mode, alpha_check_val));
}

static PyObject *_wrap_gv_raster_layer_min_set(PyObject *self, PyObject *args) {
    PyObject *layer;
    int isource;
    double min;

    if (!PyArg_ParseTuple(args, "O!id:gv_raster_layer_min_set", &PyGtk_Type, &layer, &isource, &min))
        return NULL;
    return PyInt_FromLong(gv_raster_layer_min_set(GV_RASTER_LAYER(PyGtk_Get(layer)), isource, min));
}

static PyObject *_wrap_gv_raster_layer_min_get(PyObject *self, PyObject *args) {
    PyObject *layer;
    int isource;

    if (!PyArg_ParseTuple(args, "O!i:gv_raster_layer_min_get", &PyGtk_Type, &layer, &isource))
        return NULL;
    return PyFloat_FromDouble(gv_raster_layer_min_get(GV_RASTER_LAYER(PyGtk_Get(layer)), isource));
}

static PyObject *_wrap_gv_raster_layer_max_set(PyObject *self, PyObject *args) {
    PyObject *layer;
    int isource;
    double max;

    if (!PyArg_ParseTuple(args, "O!id:gv_raster_layer_max_set", &PyGtk_Type, &layer, &isource, &max))
        return NULL;
    return PyInt_FromLong(gv_raster_layer_max_set(GV_RASTER_LAYER(PyGtk_Get(layer)), isource, max));
}

static PyObject *_wrap_gv_raster_layer_max_get(PyObject *self, PyObject *args) {
    PyObject *layer;
    int isource;

    if (!PyArg_ParseTuple(args, "O!i:gv_raster_layer_max_get", &PyGtk_Type, &layer, &isource))
        return NULL;
    return PyFloat_FromDouble(gv_raster_layer_max_get(GV_RASTER_LAYER(PyGtk_Get(layer)), isource));
}

static PyObject *_wrap_gv_raster_layer_nodata_set(PyObject *self, PyObject *args) {
    PyObject *layer;
    int isource;
    double nodata_real, nodata_imaginary;

    if (!PyArg_ParseTuple(args, "O!idd:gv_raster_layer_nodata_set", &PyGtk_Type, &layer, &isource, &nodata_real, &nodata_imaginary))
        return NULL;
    return PyInt_FromLong(gv_raster_layer_nodata_set(GV_RASTER_LAYER(PyGtk_Get(layer)), isource, nodata_real, nodata_imaginary));
}

static PyObject *_wrap_gv_raster_layer_type_get(PyObject *self, PyObject *args) {
    PyObject *layer;
    int isource;

    if (!PyArg_ParseTuple(args, "O!i:gv_raster_layer_type_get", &PyGtk_Type, &layer, &isource))
        return NULL;
    return PyFloat_FromDouble(gv_raster_layer_type_get(GV_RASTER_LAYER(PyGtk_Get(layer)), isource));
}

static PyObject *_wrap_gv_raster_layer_get_const_value(PyObject *self, PyObject *args) {
    PyObject *layer;
    int isource;

    if (!PyArg_ParseTuple(args, "O!i:gv_raster_layer_get_const_value", &PyGtk_Type, &layer, &isource))
        return NULL;
    return PyInt_FromLong(gv_raster_layer_get_const_value(GV_RASTER_LAYER(PyGtk_Get(layer)), isource));
}

static PyObject *_wrap_gv_raster_layer_get_data(PyObject *self, PyObject *args) {
    PyObject *layer;
    int isource;
    GtkObject *retval;

    if (!PyArg_ParseTuple(args, "O!i:gv_raster_layer_get_data", &PyGtk_Type, &layer, &isource))
        return NULL;
    retval = (GtkObject *)gv_raster_layer_get_data(GV_RASTER_LAYER(PyGtk_Get(layer)), isource);
    if (retval) return PyGtk_New(retval);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gv_raster_layer_get_mode(PyObject *self, PyObject *args) {
    PyObject *layer;

    if (!PyArg_ParseTuple(args, "O!:gv_raster_layer_get_mode", &PyGtk_Type, &layer))
        return NULL;
    return PyInt_FromLong(gv_raster_layer_get_mode(GV_RASTER_LAYER(PyGtk_Get(layer))));
}

static PyObject *_wrap_gv_raster_layer_texture_clamp_set(PyObject *self, PyObject *args) {
    PyObject *layer;
    int s_clamp, t_clamp;

    if (!PyArg_ParseTuple(args, "O!ii:gv_raster_layer_texture_clamp_set", &PyGtk_Type, &layer, &s_clamp, &t_clamp))
        return NULL;
    return PyInt_FromLong(gv_raster_layer_texture_clamp_set(GV_RASTER_LAYER(PyGtk_Get(layer)), s_clamp, t_clamp));
}

static PyObject *_wrap_gv_raster_layer_zoom_set(PyObject *self, PyObject *args) {
    PyObject *layer;
    int max_mode, min_mode;

    if (!PyArg_ParseTuple(args, "O!ii:gv_raster_layer_zoom_set", &PyGtk_Type, &layer, &max_mode, &min_mode))
        return NULL;
    return PyInt_FromLong(gv_raster_layer_zoom_set(GV_RASTER_LAYER(PyGtk_Get(layer)), max_mode, min_mode));
}

static PyObject *_wrap_gv_raster_layer_blend_mode_set(PyObject *self, PyObject *args) {
    PyObject *layer;
    int mode, sfactor, dfactor;

    if (!PyArg_ParseTuple(args, "O!iii:gv_raster_layer_blend_mode_set", &PyGtk_Type, &layer, &mode, &sfactor, &dfactor))
        return NULL;
    return PyInt_FromLong(gv_raster_layer_blend_mode_set(GV_RASTER_LAYER(PyGtk_Get(layer)), mode, sfactor, dfactor));
}

static PyObject *_wrap_gv_raster_layer_lut_type_get(PyObject *self, PyObject *args) {
    PyObject *layer;

    if (!PyArg_ParseTuple(args, "O!:gv_raster_layer_lut_type_get", &PyGtk_Type, &layer))
        return NULL;
    return PyInt_FromLong(gv_raster_layer_lut_type_get(GV_RASTER_LAYER(PyGtk_Get(layer))));
}

static PyObject *_wrap_gv_raster_layer_add_height(PyObject *self, PyObject *args) {
    PyObject *layer, *height_raster;
    double default_height;

    if (!PyArg_ParseTuple(args, "O!O!d:gv_raster_layer_add_height", &PyGtk_Type, &layer, &PyGtk_Type, &height_raster, &default_height))
        return NULL;
    gv_raster_layer_add_height(GV_RASTER_LAYER(PyGtk_Get(layer)), GV_RASTER(PyGtk_Get(height_raster)), default_height);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gv_raster_layer_clamp_height(PyObject *self, PyObject *args) {
    PyObject *layer;
    int bclamp_min, bclamp_max;
    double min_height, max_height;

    if (!PyArg_ParseTuple(args, "O!iidd:gv_raster_layer_clamp_height", &PyGtk_Type, &layer, &bclamp_min, &bclamp_max, &min_height, &max_height))
        return NULL;
    gv_raster_layer_clamp_height(GV_RASTER_LAYER(PyGtk_Get(layer)), bclamp_min, bclamp_max, min_height, max_height);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gv_texture_cache_dump(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gv_texture_cache_dump"))
        return NULL;
    gv_texture_cache_dump();
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gv_texture_cache_get_max(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gv_texture_cache_get_max"))
        return NULL;
    return PyInt_FromLong(gv_texture_cache_get_max());
}

static PyObject *_wrap_gv_texture_cache_get_used(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gv_texture_cache_get_used"))
        return NULL;
    return PyInt_FromLong(gv_texture_cache_get_used());
}

static PyObject *_wrap_gv_texture_cache_set_max(PyObject *self, PyObject *args) {
    int new_max;

    if (!PyArg_ParseTuple(args, "i:gv_texture_cache_set_max", &new_max))
        return NULL;
    gv_texture_cache_set_max(new_max);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gv_build_skirt(PyObject *self, PyObject *args) {
    PyObject *raster;
    double base_z;

    if (!PyArg_ParseTuple(args, "O!d:gv_build_skirt", &PyGtk_Type, &raster, &base_z))
        return NULL;
    return PyGtk_New((GtkObject *)gv_build_skirt(GV_RASTER_LAYER(PyGtk_Get(raster)), base_z));
}

static PyObject *_wrap_gtk_color_well_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gtk_color_well_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_color_well_get_type());
}

static PyObject *_wrap_gtk_color_well_new(PyObject *self, PyObject *args) {
    char *title;

    if (!PyArg_ParseTuple(args, "s:gtk_color_well_new", &title))
        return NULL;
    return PyGtk_New((GtkObject *)gtk_color_well_new(title));
}

static PyObject *_wrap_gtk_color_well_set_d(PyObject *self, PyObject *args) {
    PyObject *cwell;
    double r, g, b, a;

    if (!PyArg_ParseTuple(args, "O!dddd:gtk_color_well_set_d", &PyGtk_Type, &cwell, &r, &g, &b, &a))
        return NULL;
    gtk_color_well_set_d(GTK_COLOR_WELL(PyGtk_Get(cwell)), r, g, b, a);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_color_well_set_i8(PyObject *self, PyObject *args) {
    PyObject *cwell;
    int r, g, b, a;

    if (!PyArg_ParseTuple(args, "O!iiii:gtk_color_well_set_i8", &PyGtk_Type, &cwell, &r, &g, &b, &a))
        return NULL;
    gtk_color_well_set_i8(GTK_COLOR_WELL(PyGtk_Get(cwell)), r, g, b, a);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_color_well_set_i16(PyObject *self, PyObject *args) {
    PyObject *cwell;
    int r, g, b, a;

    if (!PyArg_ParseTuple(args, "O!iiii:gtk_color_well_set_i16", &PyGtk_Type, &cwell, &r, &g, &b, &a))
        return NULL;
    gtk_color_well_set_i16(GTK_COLOR_WELL(PyGtk_Get(cwell)), r, g, b, a);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_color_well_set_use_alpha(PyObject *self, PyObject *args) {
    PyObject *cwell;
    int use_alpha;

    if (!PyArg_ParseTuple(args, "O!i:gtk_color_well_set_use_alpha", &PyGtk_Type, &cwell, &use_alpha))
        return NULL;
    gtk_color_well_set_use_alpha(GTK_COLOR_WELL(PyGtk_Get(cwell)), use_alpha);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_color_well_set_continuous(PyObject *self, PyObject *args) {
    PyObject *cwell;
    int update_continuous;

    if (!PyArg_ParseTuple(args, "O!i:gtk_color_well_set_continuous", &PyGtk_Type, &cwell, &update_continuous))
        return NULL;
    gtk_color_well_set_continuous(GTK_COLOR_WELL(PyGtk_Get(cwell)), update_continuous);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gtk_color_well_set_title(PyObject *self, PyObject *args) {
    PyObject *cwell;
    char *title;

    if (!PyArg_ParseTuple(args, "O!s:gtk_color_well_set_title", &PyGtk_Type, &cwell, &title))
        return NULL;
    gtk_color_well_set_title(GTK_COLOR_WELL(PyGtk_Get(cwell)), title);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gv_autopan_tool_get_type(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gv_autopan_tool_get_type"))
        return NULL;
    return PyInt_FromLong(gv_autopan_tool_get_type());
}

static PyObject *_wrap_gv_autopan_tool_new(PyObject *self, PyObject *args) {
    if (!PyArg_ParseTuple(args, ":gv_autopan_tool_new"))
        return NULL;
    return PyGtk_New((GtkObject *)gv_autopan_tool_new());
}

static PyObject *_wrap_gv_autopan_tool_play(PyObject *self, PyObject *args) {
    PyObject *tool;

    if (!PyArg_ParseTuple(args, "O!:gv_autopan_tool_play", &PyGtk_Type, &tool))
        return NULL;
    return PyInt_FromLong(gv_autopan_tool_play(GV_AUTOPAN_TOOL(PyGtk_Get(tool))));
}

static PyObject *_wrap_gv_autopan_tool_pause(PyObject *self, PyObject *args) {
    PyObject *tool;

    if (!PyArg_ParseTuple(args, "O!:gv_autopan_tool_pause", &PyGtk_Type, &tool))
        return NULL;
    return PyInt_FromLong(gv_autopan_tool_pause(GV_AUTOPAN_TOOL(PyGtk_Get(tool))));
}

static PyObject *_wrap_gv_autopan_tool_stop(PyObject *self, PyObject *args) {
    PyObject *tool;

    if (!PyArg_ParseTuple(args, "O!:gv_autopan_tool_stop", &PyGtk_Type, &tool))
        return NULL;
    return PyInt_FromLong(gv_autopan_tool_stop(GV_AUTOPAN_TOOL(PyGtk_Get(tool))));
}

static PyObject *_wrap_gv_autopan_tool_set_speed(PyObject *self, PyObject *args) {
    PyObject *tool;
    double speed;

    if (!PyArg_ParseTuple(args, "O!d:gv_autopan_tool_set_speed", &PyGtk_Type, &tool, &speed))
        return NULL;
    return PyFloat_FromDouble(gv_autopan_tool_set_speed(GV_AUTOPAN_TOOL(PyGtk_Get(tool)), speed));
}

static PyObject *_wrap_gv_autopan_tool_get_speed(PyObject *self, PyObject *args) {
    PyObject *tool;

    if (!PyArg_ParseTuple(args, "O!:gv_autopan_tool_get_speed", &PyGtk_Type, &tool))
        return NULL;
    return PyFloat_FromDouble(gv_autopan_tool_get_speed(GV_AUTOPAN_TOOL(PyGtk_Get(tool))));
}

static PyObject *_wrap_gv_autopan_tool_set_location(PyObject *self, PyObject *args) {
    PyObject *tool;
    double x, y, z;

    if (!PyArg_ParseTuple(args, "O!ddd:gv_autopan_tool_set_location", &PyGtk_Type, &tool, &x, &y, &z))
        return NULL;
    return PyInt_FromLong(gv_autopan_tool_set_location(GV_AUTOPAN_TOOL(PyGtk_Get(tool)), x, y, z));
}

static PyObject *_wrap_gv_autopan_tool_set_overlap(PyObject *self, PyObject *args) {
    PyObject *tool;
    double overlap;

    if (!PyArg_ParseTuple(args, "O!d:gv_autopan_tool_set_overlap", &PyGtk_Type, &tool, &overlap))
        return NULL;
    return PyInt_FromLong(gv_autopan_tool_set_overlap(GV_AUTOPAN_TOOL(PyGtk_Get(tool)), overlap));
}

static PyObject *_wrap_gv_autopan_tool_get_overlap(PyObject *self, PyObject *args) {
    PyObject *tool;

    if (!PyArg_ParseTuple(args, "O!:gv_autopan_tool_get_overlap", &PyGtk_Type, &tool))
        return NULL;
    return PyFloat_FromDouble(gv_autopan_tool_get_overlap(GV_AUTOPAN_TOOL(PyGtk_Get(tool))));
}

static PyObject *_wrap_gv_autopan_tool_set_block_x_size(PyObject *self, PyObject *args) {
    PyObject *tool;
    double block_x_size;
    int mode;

    if (!PyArg_ParseTuple(args, "O!di:gv_autopan_tool_set_block_x_size", &PyGtk_Type, &tool, &block_x_size, &mode))
        return NULL;
    return PyInt_FromLong(gv_autopan_tool_set_block_x_size(GV_AUTOPAN_TOOL(PyGtk_Get(tool)), block_x_size, mode));
}

static PyObject *_wrap_gv_autopan_tool_set_x_resolution(PyObject *self, PyObject *args) {
    PyObject *tool;
    double resolution;

    if (!PyArg_ParseTuple(args, "O!d:gv_autopan_tool_set_x_resolution", &PyGtk_Type, &tool, &resolution))
        return NULL;
    return PyInt_FromLong(gv_autopan_tool_set_x_resolution(GV_AUTOPAN_TOOL(PyGtk_Get(tool)), resolution));
}

static PyObject *_wrap_gv_autopan_tool_set_standard_path(PyObject *self, PyObject *args) {
    PyObject *tool;
    int path_type;

    if (!PyArg_ParseTuple(args, "O!i:gv_autopan_tool_set_standard_path", &PyGtk_Type, &tool, &path_type))
        return NULL;
    return PyInt_FromLong(gv_autopan_tool_set_standard_path(GV_AUTOPAN_TOOL(PyGtk_Get(tool)), path_type));
}

static PyObject *_wrap_gv_autopan_tool_set_lines_path(PyObject *self, PyObject *args) {
    PyObject *tool, *lines;

    if (!PyArg_ParseTuple(args, "O!O!:gv_autopan_tool_set_lines_path", &PyGtk_Type, &tool, &PyGtk_Type, &lines))
        return NULL;
    return PyInt_FromLong(gv_autopan_tool_set_lines_path(GV_AUTOPAN_TOOL(PyGtk_Get(tool)), GV_SHAPES(PyGtk_Get(lines))));
}

static PyObject *_wrap_gv_autopan_tool_clear_trail(PyObject *self, PyObject *args) {
    PyObject *tool;

    if (!PyArg_ParseTuple(args, "O!:gv_autopan_tool_clear_trail", &PyGtk_Type, &tool))
        return NULL;
    gv_autopan_tool_clear_trail(GV_AUTOPAN_TOOL(PyGtk_Get(tool)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_gv_autopan_tool_set_trail_color(PyObject *self, PyObject *args) {
    PyObject *tool, *view;
    double red, green, blue, alpha;

    if (!PyArg_ParseTuple(args, "O!O!dddd:gv_autopan_tool_set_trail_color", &PyGtk_Type, &tool, &PyGtk_Type, &view, &red, &green, &blue, &alpha))
        return NULL;
    return PyInt_FromLong(gv_autopan_tool_set_trail_color(GV_AUTOPAN_TOOL(PyGtk_Get(tool)), GV_VIEW_AREA(PyGtk_Get(view)), red, green, blue, alpha));
}

static PyObject *_wrap_gv_autopan_tool_set_trail_mode(PyObject *self, PyObject *args) {
    PyObject *tool, *view;
    int trail_mode;

    if (!PyArg_ParseTuple(args, "O!O!i:gv_autopan_tool_set_trail_mode", &PyGtk_Type, &tool, &PyGtk_Type, &view, &trail_mode))
        return NULL;
    return PyInt_FromLong(gv_autopan_tool_set_trail_mode(GV_AUTOPAN_TOOL(PyGtk_Get(tool)), GV_VIEW_AREA(PyGtk_Get(view)), trail_mode));
}

static PyObject *_wrap_gv_autopan_tool_save_trail_tiles(PyObject *self, PyObject *args) {
    PyObject *tool;
    const char *basename;

    if (!PyArg_ParseTuple(args, "O!s:gv_autopan_tool_save_trail_tiles", &PyGtk_Type, &tool, &basename))
        return NULL;
    return PyInt_FromLong(gv_autopan_tool_save_trail_tiles(GV_AUTOPAN_TOOL(PyGtk_Get(tool)), basename));
}

static PyObject *_wrap_gv_autopan_tool_load_trail_tiles(PyObject *self, PyObject *args) {
    PyObject *tool;
    const char *basename;
    int num_trail_tiles;

    if (!PyArg_ParseTuple(args, "O!si:gv_autopan_tool_load_trail_tiles", &PyGtk_Type, &tool, &basename, &num_trail_tiles))
        return NULL;
    return PyInt_FromLong(gv_autopan_tool_load_trail_tiles(GV_AUTOPAN_TOOL(PyGtk_Get(tool)), basename, num_trail_tiles));
}

static PyObject *_wrap_gv_autopan_tool_register_view(PyObject *self, PyObject *args) {
    PyObject *tool, *view;
    int can_resize, can_reposition, trail_mode;

    if (!PyArg_ParseTuple(args, "O!O!iii:gv_autopan_tool_register_view", &PyGtk_Type, &tool, &PyGtk_Type, &view, &can_resize, &can_reposition, &trail_mode))
        return NULL;
    return PyInt_FromLong(gv_autopan_tool_register_view(GV_AUTOPAN_TOOL(PyGtk_Get(tool)), GV_VIEW_AREA(PyGtk_Get(view)), can_resize, can_reposition, trail_mode));
}

static PyObject *_wrap_gv_autopan_tool_remove_view(PyObject *self, PyObject *args) {
    PyObject *tool, *view;

    if (!PyArg_ParseTuple(args, "O!O!:gv_autopan_tool_remove_view", &PyGtk_Type, &tool, &PyGtk_Type, &view))
        return NULL;
    return PyInt_FromLong(gv_autopan_tool_remove_view(GV_AUTOPAN_TOOL(PyGtk_Get(tool)), GV_VIEW_AREA(PyGtk_Get(view))));
}

