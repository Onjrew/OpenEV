static PyObject *
_wrap_gtk_sheet_get_type(PyObject *self, PyObject *args)
{
    if (!PyArg_ParseTuple(args, ":gtk_sheet_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_sheet_get_type());
}

static PyObject *
_wrap_gtk_plot_data_get_type(PyObject *self, PyObject *args)
{
    if (!PyArg_ParseTuple(args, ":gtk_plot_data_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_plot_data_get_type());
}

static PyObject *
_wrap_gtk_plot_bar_get_type(PyObject *self, PyObject *args)
{
    if (!PyArg_ParseTuple(args, ":gtk_plot_bar_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_plot_bar_get_type());
}

static PyObject *
_wrap_gtk_plot_box_get_type(PyObject *self, PyObject *args)
{
    if (!PyArg_ParseTuple(args, ":gtk_plot_box_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_plot_box_get_type());
}

static PyObject *
_wrap_gtk_plot_flux_get_type(PyObject *self, PyObject *args)
{
    if (!PyArg_ParseTuple(args, ":gtk_plot_flux_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_plot_flux_get_type());
}

static PyObject *
_wrap_gtk_plot_surface_get_type(PyObject *self, PyObject *args)
{
    if (!PyArg_ParseTuple(args, ":gtk_plot_surface_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_plot_surface_get_type());
}

static PyObject *
_wrap_gtk_plot_csurface_get_type(PyObject *self, PyObject *args)
{
    if (!PyArg_ParseTuple(args, ":gtk_plot_csurface_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_plot_csurface_get_type());
}

static PyObject *
_wrap_gtk_plot_pixmap_get_type(PyObject *self, PyObject *args)
{
    if (!PyArg_ParseTuple(args, ":gtk_plot_pixmap_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_plot_pixmap_get_type());
}

static PyObject *
_wrap_gtk_plot_axis_get_type(PyObject *self, PyObject *args)
{
    if (!PyArg_ParseTuple(args, ":gtk_plot_axis_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_plot_axis_get_type());
}

static PyObject *
_wrap_gtk_plot_get_type(PyObject *self, PyObject *args)
{
    if (!PyArg_ParseTuple(args, ":gtk_plot_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_plot_get_type());
}

static PyObject *
_wrap_gtk_plot_polar_get_type(PyObject *self, PyObject *args)
{
    if (!PyArg_ParseTuple(args, ":gtk_plot_polar_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_plot_polar_get_type());
}

static PyObject *
_wrap_gtk_plot3d_get_type(PyObject *self, PyObject *args)
{
    if (!PyArg_ParseTuple(args, ":gtk_plot3d_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_plot3d_get_type());
}

static PyObject *
_wrap_gtk_plot_canvas_get_type(PyObject *self, PyObject *args)
{
    if (!PyArg_ParseTuple(args, ":gtk_plot_canvas_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_plot_canvas_get_type());
}

static PyObject *
_wrap_gtk_plot_canvas_get_pixmap(PyObject *self, PyObject *args)
{
    GdkPixmap *ret;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_plot_canvas_get_pixmap", &PyGtk_Type, &obj))
        return NULL;
    ret = GTK_PLOT_CANVAS(PyGtk_Get(obj))->pixmap;
    if (ret)
        return PyGdkWindow_New(ret);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_icon_list_get_type(PyObject *self, PyObject *args)
{
    if (!PyArg_ParseTuple(args, ":gtk_icon_list_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_icon_list_get_type());
}

static PyObject *
_wrap_gtk_icon_list_get_num_icons(PyObject *self, PyObject *args)
{
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_icon_list_get_num_icons", &PyGtk_Type, &obj))
        return NULL;
    return PyInt_FromLong(GTK_ICON_LIST(PyGtk_Get(obj))->num_icons);
}

static PyObject *
_wrap_gtk_dir_tree_get_type(PyObject *self, PyObject *args)
{
    if (!PyArg_ParseTuple(args, ":gtk_dir_tree_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_dir_tree_get_type());
}

static PyObject *
_wrap_gtk_file_list_get_type(PyObject *self, PyObject *args)
{
    if (!PyArg_ParseTuple(args, ":gtk_file_list_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_file_list_get_type());
}

static PyObject *
_wrap_gtk_icon_file_selection_get_type(PyObject *self, PyObject *args)
{
    if (!PyArg_ParseTuple(args, ":gtk_icon_file_selection_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_icon_file_selection_get_type());
}

static PyObject *
_wrap_gtk_icon_file_selection_get_path_label(PyObject *self, PyObject *args)
{
    GtkObject *ret;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_icon_file_selection_get_path_label", &PyGtk_Type, &obj))
        return NULL;
    ret = (GtkObject *) GTK_ICON_FILE_SELECTION(PyGtk_Get(obj))->path_label;
    if (ret)
        return PyGtk_New(ret);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_icon_file_selection_get_dir_tree(PyObject *self, PyObject *args)
{
    GtkObject *ret;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_icon_file_selection_get_dir_tree", &PyGtk_Type, &obj))
        return NULL;
    ret = (GtkObject *) GTK_ICON_FILE_SELECTION(PyGtk_Get(obj))->dir_tree;
    if (ret)
        return PyGtk_New(ret);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_icon_file_selection_get_file_list(PyObject *self, PyObject *args)
{
    GtkObject *ret;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_icon_file_selection_get_file_list", &PyGtk_Type, &obj))
        return NULL;
    ret = (GtkObject *) GTK_ICON_FILE_SELECTION(PyGtk_Get(obj))->file_list;
    if (ret)
        return PyGtk_New(ret);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_icon_file_selection_get_history_combo(PyObject *self, PyObject *args)
{
    GtkObject *ret;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_icon_file_selection_get_history_combo", &PyGtk_Type, &obj))
        return NULL;
    ret = (GtkObject *) GTK_ICON_FILE_SELECTION(PyGtk_Get(obj))->history_combo;
    if (ret)
        return PyGtk_New(ret);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_icon_file_selection_get_file_entry(PyObject *self, PyObject *args)
{
    GtkObject *ret;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_icon_file_selection_get_file_entry", &PyGtk_Type, &obj))
        return NULL;
    ret = (GtkObject *) GTK_ICON_FILE_SELECTION(PyGtk_Get(obj))->file_entry;
    if (ret)
        return PyGtk_New(ret);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_icon_file_selection_get_filter_entry(PyObject *self, PyObject *args)
{
    GtkObject *ret;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_icon_file_selection_get_filter_entry", &PyGtk_Type, &obj))
        return NULL;
    ret = (GtkObject *) GTK_ICON_FILE_SELECTION(PyGtk_Get(obj))->filter_entry;
    if (ret)
        return PyGtk_New(ret);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_icon_file_selection_get_ok_button(PyObject *self, PyObject *args)
{
    GtkObject *ret;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_icon_file_selection_get_ok_button", &PyGtk_Type, &obj))
        return NULL;
    ret = (GtkObject *) GTK_ICON_FILE_SELECTION(PyGtk_Get(obj))->ok_button;
    if (ret)
        return PyGtk_New(ret);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_icon_file_selection_get_cancel_button(PyObject *self, PyObject *args)
{
    GtkObject *ret;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_icon_file_selection_get_cancel_button", &PyGtk_Type, &obj))
        return NULL;
    ret = (GtkObject *) GTK_ICON_FILE_SELECTION(PyGtk_Get(obj))->cancel_button;
    if (ret)
        return PyGtk_New(ret);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_icon_file_selection_get_action_area(PyObject *self, PyObject *args)
{
    GtkObject *ret;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_icon_file_selection_get_action_area", &PyGtk_Type, &obj))
        return NULL;
    ret = (GtkObject *) GTK_ICON_FILE_SELECTION(PyGtk_Get(obj))->action_area;
    if (ret)
        return PyGtk_New(ret);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_item_entry_get_type(PyObject *self, PyObject *args)
{
    if (!PyArg_ParseTuple(args, ":gtk_item_entry_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_item_entry_get_type());
}

static PyObject *
_wrap_gtk_font_combo_get_type(PyObject *self, PyObject *args)
{
    if (!PyArg_ParseTuple(args, ":gtk_font_combo_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_font_combo_get_type());
}

static PyObject *
_wrap_gtk_font_combo_get_name_combo(PyObject *self, PyObject *args)
{
    GtkObject *ret;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_font_combo_get_name_combo", &PyGtk_Type, &obj))
        return NULL;
    ret = (GtkObject *) GTK_FONT_COMBO(PyGtk_Get(obj))->name_combo;
    if (ret)
        return PyGtk_New(ret);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_font_combo_get_size_combo(PyObject *self, PyObject *args)
{
    GtkObject *ret;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_font_combo_get_size_combo", &PyGtk_Type, &obj))
        return NULL;
    ret = (GtkObject *) GTK_FONT_COMBO(PyGtk_Get(obj))->size_combo;
    if (ret)
        return PyGtk_New(ret);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_font_combo_get_bold_button(PyObject *self, PyObject *args)
{
    GtkObject *ret;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_font_combo_get_bold_button", &PyGtk_Type, &obj))
        return NULL;
    ret = (GtkObject *) GTK_FONT_COMBO(PyGtk_Get(obj))->bold_button;
    if (ret)
        return PyGtk_New(ret);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_font_combo_get_italic_button(PyObject *self, PyObject *args)
{
    GtkObject *ret;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_font_combo_get_italic_button", &PyGtk_Type, &obj))
        return NULL;
    ret = (GtkObject *) GTK_FONT_COMBO(PyGtk_Get(obj))->italic_button;
    if (ret)
        return PyGtk_New(ret);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_font_combo_get_font(PyObject *self, PyObject *args)
{
    GdkFont *ret;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_font_combo_get_font", &PyGtk_Type, &obj))
        return NULL;
    ret = GTK_FONT_COMBO(PyGtk_Get(obj))->font;
    if (ret)
        return PyGdkFont_New(ret);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_font_combo_get_height(PyObject *self, PyObject *args)
{
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_font_combo_get_height", &PyGtk_Type, &obj))
        return NULL;
    return PyInt_FromLong(GTK_FONT_COMBO(PyGtk_Get(obj))->height);
}

static PyObject *
_wrap_gtk_font_combo_get_italic(PyObject *self, PyObject *args)
{
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_font_combo_get_italic", &PyGtk_Type, &obj))
        return NULL;
    return PyInt_FromLong(GTK_FONT_COMBO(PyGtk_Get(obj))->italic);
}

static PyObject *
_wrap_gtk_font_combo_get_bold(PyObject *self, PyObject *args)
{
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_font_combo_get_bold", &PyGtk_Type, &obj))
        return NULL;
    return PyInt_FromLong(GTK_FONT_COMBO(PyGtk_Get(obj))->bold);
}

static PyObject *
_wrap_gtk_combo_box_get_type(PyObject *self, PyObject *args)
{
    if (!PyArg_ParseTuple(args, ":gtk_combo_box_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_combo_box_get_type());
}

static PyObject *
_wrap_gtk_combo_box_get_button(PyObject *self, PyObject *args)
{
    GtkObject *ret;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_combo_box_get_button", &PyGtk_Type, &obj))
        return NULL;
    ret = (GtkObject *) GTK_COMBO_BOX(PyGtk_Get(obj))->button;
    if (ret)
        return PyGtk_New(ret);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_combo_box_get_arrow(PyObject *self, PyObject *args)
{
    GtkObject *ret;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_combo_box_get_arrow", &PyGtk_Type, &obj))
        return NULL;
    ret = (GtkObject *) GTK_COMBO_BOX(PyGtk_Get(obj))->arrow;
    if (ret)
        return PyGtk_New(ret);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_combo_box_get_popup(PyObject *self, PyObject *args)
{
    GtkObject *ret;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_combo_box_get_popup", &PyGtk_Type, &obj))
        return NULL;
    ret = (GtkObject *) GTK_COMBO_BOX(PyGtk_Get(obj))->popup;
    if (ret)
        return PyGtk_New(ret);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_combo_box_get_popwin(PyObject *self, PyObject *args)
{
    GtkObject *ret;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_combo_box_get_popwin", &PyGtk_Type, &obj))
        return NULL;
    ret = (GtkObject *) GTK_COMBO_BOX(PyGtk_Get(obj))->popwin;
    if (ret)
        return PyGtk_New(ret);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_combo_box_get_frame(PyObject *self, PyObject *args)
{
    GtkObject *ret;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_combo_box_get_frame", &PyGtk_Type, &obj))
        return NULL;
    ret = (GtkObject *) GTK_COMBO_BOX(PyGtk_Get(obj))->frame;
    if (ret)
        return PyGtk_New(ret);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_border_combo_get_type(PyObject *self, PyObject *args)
{
    if (!PyArg_ParseTuple(args, ":gtk_border_combo_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_border_combo_get_type());
}

static PyObject *
_wrap_gtk_color_combo_get_type(PyObject *self, PyObject *args)
{
    if (!PyArg_ParseTuple(args, ":gtk_color_combo_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_color_combo_get_type());
}

static PyObject *
_wrap_gtk_toggle_combo_get_type(PyObject *self, PyObject *args)
{
    if (!PyArg_ParseTuple(args, ":gtk_toggle_combo_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_toggle_combo_get_type());
}

static PyObject *
_wrap_gtk_char_selection_get_type(PyObject *self, PyObject *args)
{
    if (!PyArg_ParseTuple(args, ":gtk_char_selection_get_type"))
        return NULL;
    return PyInt_FromLong(gtk_char_selection_get_type());
}

static PyObject *
_wrap_gtk_char_selection_get_font_combo(PyObject *self, PyObject *args)
{
    GtkObject *ret;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_char_selection_get_font_combo", &PyGtk_Type, &obj))
        return NULL;
    ret = (GtkObject *) GTK_CHAR_SELECTION(PyGtk_Get(obj))->font_combo;
    if (ret)
        return PyGtk_New(ret);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_char_selection_get_ok_button(PyObject *self, PyObject *args)
{
    GtkObject *ret;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_char_selection_get_ok_button", &PyGtk_Type, &obj))
        return NULL;
    ret = (GtkObject *) GTK_CHAR_SELECTION(PyGtk_Get(obj))->ok_button;
    if (ret)
        return PyGtk_New(ret);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_char_selection_get_cancel_button(PyObject *self, PyObject *args)
{
    GtkObject *ret;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_char_selection_get_cancel_button", &PyGtk_Type, &obj))
        return NULL;
    ret = (GtkObject *) GTK_CHAR_SELECTION(PyGtk_Get(obj))->cancel_button;
    if (ret)
        return PyGtk_New(ret);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_GTK_SHEET_SET_FLAGS(PyObject *self, PyObject *args)
{
    int flags;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!i:GTK_SHEET_SET_FLAGS", &PyGtk_Type, &obj, &flags))
        return NULL;
    GTK_SHEET_SET_FLAGS(GTK_SHEET(PyGtk_Get(obj)), flags);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_GTK_SHEET_UNSET_FLAGS(PyObject *self, PyObject *args)
{
    int flags;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!i:GTK_SHEET_UNSET_FLAGS", &PyGtk_Type, &obj, &flags))
        return NULL;
    GTK_SHEET_UNSET_FLAGS(GTK_SHEET(PyGtk_Get(obj)), flags);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_GTK_PLOT_CANVAS_SET_FLAGS(PyObject *self, PyObject *args)
{
    int flags;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!i:GTK_PLOT_CANVAS_SET_FLAGS", &PyGtk_Type, &obj, &flags))
        return NULL;
    GTK_PLOT_CANVAS_SET_FLAGS(GTK_PLOT_CANVAS(PyGtk_Get(obj)), flags);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_GTK_PLOT_CANVAS_UNSET_FLAGS(PyObject *self, PyObject *args)
{
    int flags;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!i:GTK_PLOT_CANVAS_UNSET_FLAGS", &PyGtk_Type, &obj, &flags))
        return NULL;
    GTK_PLOT_CANVAS_UNSET_FLAGS(GTK_PLOT_CANVAS(PyGtk_Get(obj)), flags);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_sheet_set_hadjustment(PyObject *self, PyObject *args)
{
    PyObject *obj, *adjustment;

    if (!PyArg_ParseTuple(args, "O!O!:gtk_sheet_set_hadjustment", &PyGtk_Type, &obj, &PyGtk_Type, &adjustment))
        return NULL;
    gtk_sheet_set_hadjustment(GTK_SHEET(PyGtk_Get(obj)), GTK_ADJUSTMENT(PyGtk_Get(adjustment)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_sheet_set_vadjustment(PyObject *self, PyObject *args)
{
    PyObject *obj, *adjustment;

    if (!PyArg_ParseTuple(args, "O!O!:gtk_sheet_set_vadjustment", &PyGtk_Type, &obj, &PyGtk_Type, &adjustment))
        return NULL;
    gtk_sheet_set_vadjustment(GTK_SHEET(PyGtk_Get(obj)), GTK_ADJUSTMENT(PyGtk_Get(adjustment)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_sheet_change_entry(PyObject *self, PyObject *args)
{
    int entry_type;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!i:gtk_sheet_change_entry", &PyGtk_Type, &obj, &entry_type))
        return NULL;
    gtk_sheet_change_entry(GTK_SHEET(PyGtk_Get(obj)), entry_type);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_sheet_get_entry(PyObject *self, PyObject *args)
{
    PyObject *obj;
    GtkObject *ret;

    if (!PyArg_ParseTuple(args, "O!:gtk_sheet_get_entry", &PyGtk_Type, &obj))
        return NULL;
    ret = (GtkObject *) gtk_sheet_get_entry(GTK_SHEET(PyGtk_Get(obj)));
    if (ret)
        return PyGtk_New(ret);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_sheet_get_entry_widget(PyObject *self, PyObject *args)
{
    PyObject *obj;
    GtkObject *ret;

    if (!PyArg_ParseTuple(args, "O!:gtk_sheet_get_entry_widget", &PyGtk_Type, &obj))
        return NULL;
    ret = (GtkObject *) gtk_sheet_get_entry_widget(GTK_SHEET(PyGtk_Get(obj)));
    if (ret)
        return PyGtk_New(ret);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_sheet_get_state(PyObject *self, PyObject *args)
{
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_sheet_get_state", &PyGtk_Type, &obj))
        return NULL;
    return PyInt_FromLong(gtk_sheet_get_state(GTK_SHEET(PyGtk_Get(obj))));
}

static PyObject *
_wrap_gtk_sheet_get_columns_count(PyObject *self, PyObject *args)
{
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_sheet_get_columns_count", &PyGtk_Type, &obj))
        return NULL;
    return PyInt_FromLong(gtk_sheet_get_columns_count(GTK_SHEET(PyGtk_Get(obj))));
}

static PyObject *
_wrap_gtk_sheet_get_rows_count(PyObject *self, PyObject *args)
{
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_sheet_get_rows_count", &PyGtk_Type, &obj))
        return NULL;
    return PyInt_FromLong(gtk_sheet_get_rows_count(GTK_SHEET(PyGtk_Get(obj))));
}

static PyObject *
_wrap_gtk_sheet_set_selection_mode(PyObject *self, PyObject *args)
{
    int mode;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!i:gtk_sheet_set_selection_mode", &PyGtk_Type, &obj, &mode))
        return NULL;
    gtk_sheet_set_selection_mode(GTK_SHEET(PyGtk_Get(obj)), mode);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_sheet_set_title(PyObject *self, PyObject *args)
{
    char *title;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!s:gtk_sheet_set_title", &PyGtk_Type, &obj, &title))
        return NULL;
    gtk_sheet_set_title(GTK_SHEET(PyGtk_Get(obj)), title);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_sheet_freeze(PyObject *self, PyObject *args)
{
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_sheet_freeze", &PyGtk_Type, &obj))
        return NULL;
    gtk_sheet_freeze(GTK_SHEET(PyGtk_Get(obj)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_sheet_thaw(PyObject *self, PyObject *args)
{
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_sheet_thaw", &PyGtk_Type, &obj))
        return NULL;
    gtk_sheet_thaw(GTK_SHEET(PyGtk_Get(obj)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_sheet_set_background(PyObject *self, PyObject *args)
{
    PyObject *obj, *color;

    if (!PyArg_ParseTuple(args, "O!O!:gtk_sheet_set_background", &PyGtk_Type, &obj, &PyGdkColor_Type, &color))
        return NULL;
    gtk_sheet_set_background(GTK_SHEET(PyGtk_Get(obj)), PyGdkColor_Get(color));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_sheet_set_grid(PyObject *self, PyObject *args)
{
    PyObject *obj, *color;

    if (!PyArg_ParseTuple(args, "O!O!:gtk_sheet_set_grid", &PyGtk_Type, &obj, &PyGdkColor_Type, &color))
        return NULL;
    gtk_sheet_set_grid(GTK_SHEET(PyGtk_Get(obj)), PyGdkColor_Get(color));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_sheet_show_grid(PyObject *self, PyObject *args)
{
    int visible;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!i:gtk_sheet_show_grid", &PyGtk_Type, &obj, &visible))
        return NULL;
    gtk_sheet_show_grid(GTK_SHEET(PyGtk_Get(obj)), visible);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_sheet_grid_visible(PyObject *self, PyObject *args)
{
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_sheet_grid_visible", &PyGtk_Type, &obj))
        return NULL;
    return PyInt_FromLong(gtk_sheet_grid_visible(GTK_SHEET(PyGtk_Get(obj))));
}

static PyObject *
_wrap_gtk_sheet_set_column_title(PyObject *self, PyObject *args)
{
    int column;
    char *title;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!iz:gtk_sheet_set_column_title", &PyGtk_Type, &obj, &column, &title))
        return NULL;
    gtk_sheet_set_column_title(GTK_SHEET(PyGtk_Get(obj)), column, title);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_sheet_set_row_title(PyObject *self, PyObject *args)
{
    int row;
    char *title;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!iz:gtk_sheet_set_row_title", &PyGtk_Type, &obj, &row, &title))
        return NULL;
    gtk_sheet_set_row_title(GTK_SHEET(PyGtk_Get(obj)), row, title);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_sheet_row_button_add_label(PyObject *self, PyObject *args)
{
    int row;
    char *label;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!iz:gtk_sheet_row_button_add_label", &PyGtk_Type, &obj, &row, &label))
        return NULL;
    gtk_sheet_row_button_add_label(GTK_SHEET(PyGtk_Get(obj)), row, label);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_sheet_column_button_add_label(PyObject *self, PyObject *args)
{
    int column;
    char *label;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!iz:gtk_sheet_column_button_add_label", &PyGtk_Type, &obj, &column, &label))
        return NULL;
    gtk_sheet_column_button_add_label(GTK_SHEET(PyGtk_Get(obj)), column, label);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_sheet_row_button_justify(PyObject *self, PyObject *args)
{
    int row, justification;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!ii:gtk_sheet_row_button_justify", &PyGtk_Type, &obj, &row, &justification))
        return NULL;
    gtk_sheet_row_button_justify(GTK_SHEET(PyGtk_Get(obj)), row, justification);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_sheet_column_button_justify(PyObject *self, PyObject *args)
{
    int column, justification;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!ii:gtk_sheet_column_button_justify", &PyGtk_Type, &obj, &column, &justification))
        return NULL;
    gtk_sheet_column_button_justify(GTK_SHEET(PyGtk_Get(obj)), column, justification);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_sheet_moveto(PyObject *self, PyObject *args)
{
    PyObject *obj;
    double row_align, column_align;
    int row, column;

    if (!PyArg_ParseTuple(args, "O!iidd:gtk_sheet_moveto", &PyGtk_Type, &obj, &row, &column, &row_align, &column_align))
        return NULL;
    gtk_sheet_moveto(GTK_SHEET(PyGtk_Get(obj)), row, column, row_align, column_align);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_sheet_set_row_titles_width(PyObject *self, PyObject *args)
{
    int width;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!i:gtk_sheet_set_row_titles_width", &PyGtk_Type, &obj, &width))
        return NULL;
    gtk_sheet_set_row_titles_width(GTK_SHEET(PyGtk_Get(obj)), width);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_sheet_set_column_titles_height(PyObject *self, PyObject *args)
{
    int height;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!i:gtk_sheet_set_column_titles_height", &PyGtk_Type, &obj, &height))
        return NULL;
    gtk_sheet_set_column_titles_height(GTK_SHEET(PyGtk_Get(obj)), height);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_sheet_show_column_titles(PyObject *self, PyObject *args)
{
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_sheet_show_column_titles", &PyGtk_Type, &obj))
        return NULL;
    gtk_sheet_show_column_titles(GTK_SHEET(PyGtk_Get(obj)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_sheet_show_row_titles(PyObject *self, PyObject *args)
{
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_sheet_show_row_titles", &PyGtk_Type, &obj))
        return NULL;
    gtk_sheet_show_row_titles(GTK_SHEET(PyGtk_Get(obj)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_sheet_hide_column_titles(PyObject *self, PyObject *args)
{
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_sheet_hide_column_titles", &PyGtk_Type, &obj))
        return NULL;
    gtk_sheet_hide_column_titles(GTK_SHEET(PyGtk_Get(obj)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_sheet_hide_row_titles(PyObject *self, PyObject *args)
{
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_sheet_hide_row_titles", &PyGtk_Type, &obj))
        return NULL;
    gtk_sheet_hide_row_titles(GTK_SHEET(PyGtk_Get(obj)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_sheet_column_set_sensitivity(PyObject *self, PyObject *args)
{
    int column, sensitive;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!ii:gtk_sheet_column_set_sensitivity", &PyGtk_Type, &obj, &column, &sensitive))
        return NULL;
    gtk_sheet_column_set_sensitivity(GTK_SHEET(PyGtk_Get(obj)), column, sensitive);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_sheet_columns_set_sensitivity(PyObject *self, PyObject *args)
{
    int sensitive;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!i:gtk_sheet_columns_set_sensitivity", &PyGtk_Type, &obj, &sensitive))
        return NULL;
    gtk_sheet_columns_set_sensitivity(GTK_SHEET(PyGtk_Get(obj)), sensitive);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_sheet_row_set_sensitivity(PyObject *self, PyObject *args)
{
    int row, sensitive;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!ii:gtk_sheet_row_set_sensitivity", &PyGtk_Type, &obj, &row, &sensitive))
        return NULL;
    gtk_sheet_row_set_sensitivity(GTK_SHEET(PyGtk_Get(obj)), row, sensitive);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_sheet_rows_set_sensitivity(PyObject *self, PyObject *args)
{
    int sensitive;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!i:gtk_sheet_rows_set_sensitivity", &PyGtk_Type, &obj, &sensitive))
        return NULL;
    gtk_sheet_rows_set_sensitivity(GTK_SHEET(PyGtk_Get(obj)), sensitive);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_sheet_column_set_visibility(PyObject *self, PyObject *args)
{
    int column, visible;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!ii:gtk_sheet_column_set_visibility", &PyGtk_Type, &obj, &column, &visible))
        return NULL;
    gtk_sheet_column_set_visibility(GTK_SHEET(PyGtk_Get(obj)), column, visible);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_sheet_column_label_set_visibility(PyObject *self, PyObject *args)
{
    int column, visible;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!ii:gtk_sheet_column_label_set_visibility", &PyGtk_Type, &obj, &column, &visible))
        return NULL;
    gtk_sheet_column_label_set_visibility(GTK_SHEET(PyGtk_Get(obj)), column, visible);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_sheet_columns_labels_set_visibility(PyObject *self, PyObject *args)
{
    int visible;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!i:gtk_sheet_columns_labels_set_visibility", &PyGtk_Type, &obj, &visible))
        return NULL;
    gtk_sheet_columns_labels_set_visibility(GTK_SHEET(PyGtk_Get(obj)), visible);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_sheet_row_set_visibility(PyObject *self, PyObject *args)
{
    int row, visible;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!ii:gtk_sheet_row_set_visibility", &PyGtk_Type, &obj, &row, &visible))
        return NULL;
    gtk_sheet_row_set_visibility(GTK_SHEET(PyGtk_Get(obj)), row, visible);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_sheet_row_label_set_visibility(PyObject *self, PyObject *args)
{
    int row, visible;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!ii:gtk_sheet_row_label_set_visibility", &PyGtk_Type, &obj, &row, &visible))
        return NULL;
    gtk_sheet_row_label_set_visibility(GTK_SHEET(PyGtk_Get(obj)), row, visible);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_sheet_rows_labels_set_visibility(PyObject *self, PyObject *args)
{
    int visible;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!i:gtk_sheet_rows_labels_set_visibility", &PyGtk_Type, &obj, &visible))
        return NULL;
    gtk_sheet_rows_labels_set_visibility(GTK_SHEET(PyGtk_Get(obj)), visible);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_sheet_select_row(PyObject *self, PyObject *args)
{
    int row;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!i:gtk_sheet_select_row", &PyGtk_Type, &obj, &row))
        return NULL;
    gtk_sheet_select_row(GTK_SHEET(PyGtk_Get(obj)), row);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_sheet_select_column(PyObject *self, PyObject *args)
{
    int column;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!i:gtk_sheet_select_column", &PyGtk_Type, &obj, &column))
        return NULL;
    gtk_sheet_select_column(GTK_SHEET(PyGtk_Get(obj)), column);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_sheet_unclip_range(PyObject *self, PyObject *args)
{
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_sheet_unclip_range", &PyGtk_Type, &obj))
        return NULL;
    gtk_sheet_unclip_range(GTK_SHEET(PyGtk_Get(obj)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_sheet_get_vadjustment(PyObject *self, PyObject *args)
{
    PyObject *obj;
    GtkObject *ret;

    if (!PyArg_ParseTuple(args, "O!:gtk_sheet_get_vadjustment", &PyGtk_Type, &obj))
        return NULL;
    ret = (GtkObject *) gtk_sheet_get_vadjustment(GTK_SHEET(PyGtk_Get(obj)));
    if (ret)
        return PyGtk_New(ret);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_sheet_get_hadjustment(PyObject *self, PyObject *args)
{
    PyObject *obj;
    GtkObject *ret;

    if (!PyArg_ParseTuple(args, "O!:gtk_sheet_get_hadjustment", &PyGtk_Type, &obj))
        return NULL;
    ret = (GtkObject *) gtk_sheet_get_hadjustment(GTK_SHEET(PyGtk_Get(obj)));
    if (ret)
        return PyGtk_New(ret);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_sheet_unselect_range(PyObject *self, PyObject *args)
{
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_sheet_unselect_range", &PyGtk_Type, &obj))
        return NULL;
    gtk_sheet_unselect_range(GTK_SHEET(PyGtk_Get(obj)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_sheet_set_active_cell(PyObject *self, PyObject *args)
{
    int row, column;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!ii:gtk_sheet_set_active_cell", &PyGtk_Type, &obj, &row, &column))
        return NULL;
    return PyInt_FromLong(gtk_sheet_set_active_cell(GTK_SHEET(PyGtk_Get(obj)), row, column));
}

static PyObject *
_wrap_gtk_sheet_set_cell(PyObject *self, PyObject *args)
{
    int row, column, justification;
    char *string;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!iiiz:gtk_sheet_set_cell", &PyGtk_Type, &obj, &row, &column, &justification, &string))
        return NULL;
    gtk_sheet_set_cell(GTK_SHEET(PyGtk_Get(obj)), row, column, justification, string);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_sheet_set_cell_text(PyObject *self, PyObject *args)
{
    int row, column;
    char *string;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!iiz:gtk_sheet_set_cell_text", &PyGtk_Type, &obj, &row, &column, &string))
        return NULL;
    gtk_sheet_set_cell_text(GTK_SHEET(PyGtk_Get(obj)), row, column, string);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_sheet_cell_clear(PyObject *self, PyObject *args)
{
    int row, column;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!ii:gtk_sheet_cell_clear", &PyGtk_Type, &obj, &row, &column))
        return NULL;
    gtk_sheet_cell_clear(GTK_SHEET(PyGtk_Get(obj)), row, column);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_sheet_cell_delete(PyObject *self, PyObject *args)
{
    int row, column;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!ii:gtk_sheet_cell_delete", &PyGtk_Type, &obj, &row, &column))
        return NULL;
    gtk_sheet_cell_delete(GTK_SHEET(PyGtk_Get(obj)), row, column);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_sheet_cell_get_state(PyObject *self, PyObject *args)
{
    int row, column;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!ii:gtk_sheet_cell_get_state", &PyGtk_Type, &obj, &row, &column))
        return NULL;
    return PyInt_FromLong(gtk_sheet_cell_get_state(GTK_SHEET(PyGtk_Get(obj)), row, column));
}

static PyObject *
_wrap_gtk_sheet_set_column_width(PyObject *self, PyObject *args)
{
    int column, width;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!ii:gtk_sheet_set_column_width", &PyGtk_Type, &obj, &column, &width))
        return NULL;
    gtk_sheet_set_column_width(GTK_SHEET(PyGtk_Get(obj)), column, width);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_sheet_set_row_height(PyObject *self, PyObject *args)
{
    int row, height;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!ii:gtk_sheet_set_row_height", &PyGtk_Type, &obj, &row, &height))
        return NULL;
    gtk_sheet_set_row_height(GTK_SHEET(PyGtk_Get(obj)), row, height);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_sheet_add_column(PyObject *self, PyObject *args)
{
    int n;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!i:gtk_sheet_add_column", &PyGtk_Type, &obj, &n))
        return NULL;
    gtk_sheet_add_column(GTK_SHEET(PyGtk_Get(obj)), n);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_sheet_add_row(PyObject *self, PyObject *args)
{
    int n;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!i:gtk_sheet_add_row", &PyGtk_Type, &obj, &n))
        return NULL;
    gtk_sheet_add_row(GTK_SHEET(PyGtk_Get(obj)), n);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_sheet_insert_rows(PyObject *self, PyObject *args)
{
    int row, n;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!ii:gtk_sheet_insert_rows", &PyGtk_Type, &obj, &row, &n))
        return NULL;
    gtk_sheet_insert_rows(GTK_SHEET(PyGtk_Get(obj)), row, n);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_sheet_insert_columns(PyObject *self, PyObject *args)
{
    int column, n;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!ii:gtk_sheet_insert_columns", &PyGtk_Type, &obj, &column, &n))
        return NULL;
    gtk_sheet_insert_columns(GTK_SHEET(PyGtk_Get(obj)), column, n);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_sheet_delete_rows(PyObject *self, PyObject *args)
{
    int row, n;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!ii:gtk_sheet_delete_rows", &PyGtk_Type, &obj, &row, &n))
        return NULL;
    gtk_sheet_delete_rows(GTK_SHEET(PyGtk_Get(obj)), row, n);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_sheet_delete_columns(PyObject *self, PyObject *args)
{
    int column, n;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!ii:gtk_sheet_delete_columns", &PyGtk_Type, &obj, &column, &n))
        return NULL;
    gtk_sheet_delete_columns(GTK_SHEET(PyGtk_Get(obj)), column, n);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_sheet_column_set_justification(PyObject *self, PyObject *args)
{
    int column, justification;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!ii:gtk_sheet_column_set_justification", &PyGtk_Type, &obj, &column, &justification))
        return NULL;
    gtk_sheet_column_set_justification(GTK_SHEET(PyGtk_Get(obj)), column, justification);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_sheet_attach(PyObject *self, PyObject *args)
{
    PyObject *obj, *widget;
    double x_align, y_align;
    int row, column;

    if (!PyArg_ParseTuple(args, "O!O!iidd:gtk_sheet_attach", &PyGtk_Type, &obj, &PyGtk_Type, &widget, &row, &column, &x_align, &y_align))
        return NULL;
    gtk_sheet_attach(GTK_SHEET(PyGtk_Get(obj)), GTK_WIDGET(PyGtk_Get(widget)), row, column, x_align, y_align);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_sheet_move_child(PyObject *self, PyObject *args)
{
    int x, y;
    PyObject *obj, *widget;

    if (!PyArg_ParseTuple(args, "O!O!ii:gtk_sheet_move_child", &PyGtk_Type, &obj, &PyGtk_Type, &widget, &x, &y))
        return NULL;
    gtk_sheet_move_child(GTK_SHEET(PyGtk_Get(obj)), GTK_WIDGET(PyGtk_Get(widget)), x, y);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_sheet_button_attach(PyObject *self, PyObject *args)
{
    PyObject *obj, *widget;
    double x_align, y_align;
    int row, column;

    if (!PyArg_ParseTuple(args, "O!O!iidd:gtk_sheet_button_attach", &PyGtk_Type, &obj, &PyGtk_Type, &widget, &row, &column, &x_align, &y_align))
        return NULL;
    gtk_sheet_button_attach(GTK_SHEET(PyGtk_Get(obj)), GTK_WIDGET(PyGtk_Get(widget)), row, column, x_align, y_align);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_data_paint(PyObject *self, PyObject *args)
{
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_plot_data_paint", &PyGtk_Type, &obj))
        return NULL;
    gtk_plot_data_paint(GTK_PLOT_DATA(PyGtk_Get(obj)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_data_update(PyObject *self, PyObject *args)
{
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_plot_data_update", &PyGtk_Type, &obj))
        return NULL;
    gtk_plot_data_update(GTK_PLOT_DATA(PyGtk_Get(obj)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_data_draw_points(PyObject *self, PyObject *args)
{
    int n;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!i:gtk_plot_data_draw_points", &PyGtk_Type, &obj, &n))
        return NULL;
    gtk_plot_data_draw_points(GTK_PLOT_DATA(PyGtk_Get(obj)), n);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_data_draw_symbol(PyObject *self, PyObject *args)
{
    double x, y;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!dd:gtk_plot_data_draw_symbol", &PyGtk_Type, &obj, &x, &y))
        return NULL;
    gtk_plot_data_draw_symbol(GTK_PLOT_DATA(PyGtk_Get(obj)), x, y);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_data_set_a_scale(PyObject *self, PyObject *args)
{
    double scale;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!d:gtk_plot_data_set_a_scale", &PyGtk_Type, &obj, &scale))
        return NULL;
    gtk_plot_data_set_a_scale(GTK_PLOT_DATA(PyGtk_Get(obj)), scale);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_data_get_a_scale(PyObject *self, PyObject *args)
{
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_plot_data_get_a_scale", &PyGtk_Type, &obj))
        return NULL;
    return PyFloat_FromDouble(gtk_plot_data_get_a_scale(GTK_PLOT_DATA(PyGtk_Get(obj))));
}

static PyObject *
_wrap_gtk_plot_data_show_labels(PyObject *self, PyObject *args)
{
    int visible;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!i:gtk_plot_data_show_labels", &PyGtk_Type, &obj, &visible))
        return NULL;
    gtk_plot_data_show_labels(GTK_PLOT_DATA(PyGtk_Get(obj)), visible);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_data_labels_set_attributes(PyObject *self, PyObject *args)
{
    PyObject *obj, *py_foreground = Py_None, *py_background = Py_None;
    char *fontname;
    GdkColor *foreground = NULL, *background = NULL;
    int height, angle;

    if (!PyArg_ParseTuple(args, "O!ziiOO:gtk_plot_data_labels_set_attributes", &PyGtk_Type, &obj, &fontname, &height, &angle, &py_foreground, &py_background))
        return NULL;
    if (PyGdkColor_Check(py_foreground))
        foreground = PyGdkColor_Get(py_foreground);
    else if (py_foreground != Py_None) {
        PyErr_SetString(PyExc_TypeError, "foreground argument must be a GdkColor or None");
	return NULL;
    }
    if (PyGdkColor_Check(py_background))
        background = PyGdkColor_Get(py_background);
    else if (py_background != Py_None) {
        PyErr_SetString(PyExc_TypeError, "background argument must be a GdkColor or None");
	return NULL;
    }
    gtk_plot_data_labels_set_attributes(GTK_PLOT_DATA(PyGtk_Get(obj)), fontname, height, angle, foreground, background);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_data_get_numpoints(PyObject *self, PyObject *args)
{
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_plot_data_get_numpoints", &PyGtk_Type, &obj))
        return NULL;
    return PyInt_FromLong(gtk_plot_data_get_numpoints(GTK_PLOT_DATA(PyGtk_Get(obj))));
}

static PyObject *
_wrap_gtk_plot_data_set_connector(PyObject *self, PyObject *args)
{
    int connector;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!i:gtk_plot_data_set_connector", &PyGtk_Type, &obj, &connector))
        return NULL;
    gtk_plot_data_set_connector(GTK_PLOT_DATA(PyGtk_Get(obj)), connector);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_data_get_connector(PyObject *self, PyObject *args)
{
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_plot_data_get_connector", &PyGtk_Type, &obj))
        return NULL;
    return PyInt_FromLong(gtk_plot_data_get_connector(GTK_PLOT_DATA(PyGtk_Get(obj))));
}

static PyObject *
_wrap_gtk_plot_data_set_line_attributes(PyObject *self, PyObject *args)
{
    PyObject *obj, *color;
    double width;
    int line_style;

    if (!PyArg_ParseTuple(args, "O!idO!:gtk_plot_data_set_line_attributes", &PyGtk_Type, &obj, &line_style, &width, &PyGdkColor_Type, &color))
        return NULL;
    gtk_plot_data_set_line_attributes(GTK_PLOT_DATA(PyGtk_Get(obj)), line_style, width, PyGdkColor_Get(color));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_data_set_x_attributes(PyObject *self, PyObject *args)
{
    PyObject *obj, *color;
    double width;
    int line_style;

    if (!PyArg_ParseTuple(args, "O!idO!:gtk_plot_data_set_x_attributes", &PyGtk_Type, &obj, &line_style, &width, &PyGdkColor_Type, &color))
        return NULL;
    gtk_plot_data_set_x_attributes(GTK_PLOT_DATA(PyGtk_Get(obj)), line_style, width, PyGdkColor_Get(color));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_data_set_y_attributes(PyObject *self, PyObject *args)
{
    PyObject *obj, *color;
    double width;
    int line_style;

    if (!PyArg_ParseTuple(args, "O!idO!:gtk_plot_data_set_y_attributes", &PyGtk_Type, &obj, &line_style, &width, &PyGdkColor_Type, &color))
        return NULL;
    gtk_plot_data_set_y_attributes(GTK_PLOT_DATA(PyGtk_Get(obj)), line_style, width, PyGdkColor_Get(color));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_data_set_z_attributes(PyObject *self, PyObject *args)
{
    PyObject *obj, *color;
    double width;
    int line_style;

    if (!PyArg_ParseTuple(args, "O!idO!:gtk_plot_data_set_z_attributes", &PyGtk_Type, &obj, &line_style, &width, &PyGdkColor_Type, &color))
        return NULL;
    gtk_plot_data_set_z_attributes(GTK_PLOT_DATA(PyGtk_Get(obj)), line_style, width, PyGdkColor_Get(color));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_data_show_xerrbars(PyObject *self, PyObject *args)
{
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_plot_data_show_xerrbars", &PyGtk_Type, &obj))
        return NULL;
    gtk_plot_data_show_xerrbars(GTK_PLOT_DATA(PyGtk_Get(obj)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_data_show_yerrbars(PyObject *self, PyObject *args)
{
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_plot_data_show_yerrbars", &PyGtk_Type, &obj))
        return NULL;
    gtk_plot_data_show_yerrbars(GTK_PLOT_DATA(PyGtk_Get(obj)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_data_show_zerrbars(PyObject *self, PyObject *args)
{
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_plot_data_show_zerrbars", &PyGtk_Type, &obj))
        return NULL;
    gtk_plot_data_show_zerrbars(GTK_PLOT_DATA(PyGtk_Get(obj)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_data_hide_xerrbars(PyObject *self, PyObject *args)
{
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_plot_data_hide_xerrbars", &PyGtk_Type, &obj))
        return NULL;
    gtk_plot_data_hide_xerrbars(GTK_PLOT_DATA(PyGtk_Get(obj)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_data_hide_yerrbars(PyObject *self, PyObject *args)
{
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_plot_data_hide_yerrbars", &PyGtk_Type, &obj))
        return NULL;
    gtk_plot_data_hide_yerrbars(GTK_PLOT_DATA(PyGtk_Get(obj)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_data_hide_zerrbars(PyObject *self, PyObject *args)
{
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_plot_data_hide_zerrbars", &PyGtk_Type, &obj))
        return NULL;
    gtk_plot_data_hide_zerrbars(GTK_PLOT_DATA(PyGtk_Get(obj)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_data_fill_area(PyObject *self, PyObject *args)
{
    int fill;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!i:gtk_plot_data_fill_area", &PyGtk_Type, &obj, &fill))
        return NULL;
    gtk_plot_data_fill_area(GTK_PLOT_DATA(PyGtk_Get(obj)), fill);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_data_area_is_filled(PyObject *self, PyObject *args)
{
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_plot_data_area_is_filled", &PyGtk_Type, &obj))
        return NULL;
    return PyInt_FromLong(gtk_plot_data_area_is_filled(GTK_PLOT_DATA(PyGtk_Get(obj))));
}

static PyObject *
_wrap_gtk_plot_data_show_legend(PyObject *self, PyObject *args)
{
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_plot_data_show_legend", &PyGtk_Type, &obj))
        return NULL;
    gtk_plot_data_show_legend(GTK_PLOT_DATA(PyGtk_Get(obj)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_data_hide_legend(PyObject *self, PyObject *args)
{
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_plot_data_hide_legend", &PyGtk_Type, &obj))
        return NULL;
    gtk_plot_data_hide_legend(GTK_PLOT_DATA(PyGtk_Get(obj)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_data_set_legend(PyObject *self, PyObject *args)
{
    char *legend;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!s:gtk_plot_data_set_legend", &PyGtk_Type, &obj, &legend))
        return NULL;
    gtk_plot_data_set_legend(GTK_PLOT_DATA(PyGtk_Get(obj)), legend);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_data_set_legend_precision(PyObject *self, PyObject *args)
{
    int precision;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!i:gtk_plot_data_set_legend_precision", &PyGtk_Type, &obj, &precision))
        return NULL;
    gtk_plot_data_set_legend_precision(GTK_PLOT_DATA(PyGtk_Get(obj)), precision);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_data_get_legend_precision(PyObject *self, PyObject *args)
{
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_plot_data_get_legend_precision", &PyGtk_Type, &obj))
        return NULL;
    return PyInt_FromLong(gtk_plot_data_get_legend_precision(GTK_PLOT_DATA(PyGtk_Get(obj))));
}

static PyObject *
_wrap_gtk_plot_data_set_name(PyObject *self, PyObject *args)
{
    char *name;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!s:gtk_plot_data_set_name", &PyGtk_Type, &obj, &name))
        return NULL;
    gtk_plot_data_set_name(GTK_PLOT_DATA(PyGtk_Get(obj)), name);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_data_set_gradient_mask(PyObject *self, PyObject *args)
{
    int mask;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!i:gtk_plot_data_set_gradient_mask", &PyGtk_Type, &obj, &mask))
        return NULL;
    gtk_plot_data_set_gradient_mask(GTK_PLOT_DATA(PyGtk_Get(obj)), mask);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_data_get_gradient_mask(PyObject *self, PyObject *args)
{
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_plot_data_get_gradient_mask", &PyGtk_Type, &obj))
        return NULL;
    return PyInt_FromLong(gtk_plot_data_get_gradient_mask(GTK_PLOT_DATA(PyGtk_Get(obj))));
}

static PyObject *
_wrap_gtk_plot_data_gradient_set_visible(PyObject *self, PyObject *args)
{
    int visible;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!i:gtk_plot_data_gradient_set_visible", &PyGtk_Type, &obj, &visible))
        return NULL;
    gtk_plot_data_gradient_set_visible(GTK_PLOT_DATA(PyGtk_Get(obj)), visible);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_data_gradient_visible(PyObject *self, PyObject *args)
{
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_plot_data_gradient_visible", &PyGtk_Type, &obj))
        return NULL;
    return PyInt_FromLong(gtk_plot_data_gradient_visible(GTK_PLOT_DATA(PyGtk_Get(obj))));
}

static PyObject *
_wrap_gtk_plot_data_draw_gradient(PyObject *self, PyObject *args)
{
    int x, y;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!ii:gtk_plot_data_draw_gradient", &PyGtk_Type, &obj, &x, &y))
        return NULL;
    gtk_plot_data_draw_gradient(GTK_PLOT_DATA(PyGtk_Get(obj)), x, y);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_data_gradient_autoscale_a(PyObject *self, PyObject *args)
{
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_plot_data_gradient_autoscale_a", &PyGtk_Type, &obj))
        return NULL;
    gtk_plot_data_gradient_autoscale_a(GTK_PLOT_DATA(PyGtk_Get(obj)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_data_gradient_autoscale_da(PyObject *self, PyObject *args)
{
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_plot_data_gradient_autoscale_da", &PyGtk_Type, &obj))
        return NULL;
    gtk_plot_data_gradient_autoscale_da(GTK_PLOT_DATA(PyGtk_Get(obj)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_data_gradient_autoscale_z(PyObject *self, PyObject *args)
{
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_plot_data_gradient_autoscale_z", &PyGtk_Type, &obj))
        return NULL;
    gtk_plot_data_gradient_autoscale_z(GTK_PLOT_DATA(PyGtk_Get(obj)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_data_set_gradient_colors(PyObject *self, PyObject *args)
{
    PyObject *obj, *min_color, *max_color;

    if (!PyArg_ParseTuple(args, "O!O!O!:gtk_plot_data_set_gradient_colors", &PyGtk_Type, &obj, &PyGdkColor_Type, &min_color, &PyGdkColor_Type, &max_color))
        return NULL;
    gtk_plot_data_set_gradient_colors(GTK_PLOT_DATA(PyGtk_Get(obj)), PyGdkColor_Get(min_color), PyGdkColor_Get(max_color));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_data_set_gradient(PyObject *self, PyObject *args)
{
    PyObject *obj;
    double min, max;
    int levels, sublevels = 0;

    if (!PyArg_ParseTuple(args, "O!ddi|i:gtk_plot_data_set_gradient", &PyGtk_Type, &obj, &min, &max, &levels, &sublevels))
        return NULL;
    gtk_plot_data_set_gradient(GTK_PLOT_DATA(PyGtk_Get(obj)), min, max, levels, sublevels);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_data_remove_markers(PyObject *self, PyObject *args)
{
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_plot_data_remove_markers", &PyGtk_Type, &obj))
        return NULL;
    gtk_plot_data_remove_markers(GTK_PLOT_DATA(PyGtk_Get(obj)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_data_show_markers(PyObject *self, PyObject *args)
{
    int visible;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!i:gtk_plot_data_show_markers", &PyGtk_Type, &obj, &visible))
        return NULL;
    gtk_plot_data_show_markers(GTK_PLOT_DATA(PyGtk_Get(obj)), visible);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_data_markers_visible(PyObject *self, PyObject *args)
{
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_plot_data_markers_visible", &PyGtk_Type, &obj))
        return NULL;
    return PyInt_FromLong(gtk_plot_data_markers_visible(GTK_PLOT_DATA(PyGtk_Get(obj))));
}

static PyObject *
_wrap_gtk_plot_bar_set_width(PyObject *self, PyObject *args)
{
    double width;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!d:gtk_plot_bar_set_width", &PyGtk_Type, &obj, &width))
        return NULL;
    gtk_plot_bar_set_width(GTK_PLOT_BAR(PyGtk_Get(obj)), width);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_bar_get_width(PyObject *self, PyObject *args)
{
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_plot_bar_get_width", &PyGtk_Type, &obj))
        return NULL;
    return PyFloat_FromDouble(gtk_plot_bar_get_width(GTK_PLOT_BAR(PyGtk_Get(obj))));
}

static PyObject *
_wrap_gtk_plot_flux_set_arrow(PyObject *self, PyObject *args)
{
    int arrow_length, arrow_width, symbol_style;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!iii:gtk_plot_flux_set_arrow", &PyGtk_Type, &obj, &arrow_length, &arrow_width, &symbol_style))
        return NULL;
    gtk_plot_flux_set_arrow(GTK_PLOT_FLUX(PyGtk_Get(obj)), arrow_length, arrow_width, symbol_style);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_surface_set_color(PyObject *self, PyObject *args)
{
    PyObject *obj, *color;

    if (!PyArg_ParseTuple(args, "O!O!:gtk_plot_surface_set_color", &PyGtk_Type, &obj, &PyGdkColor_Type, &color))
        return NULL;
    gtk_plot_surface_set_color(GTK_PLOT_SURFACE(PyGtk_Get(obj)), PyGdkColor_Get(color));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_surface_set_shadow(PyObject *self, PyObject *args)
{
    PyObject *obj, *color;

    if (!PyArg_ParseTuple(args, "O!O!:gtk_plot_surface_set_shadow", &PyGtk_Type, &obj, &PyGdkColor_Type, &color))
        return NULL;
    gtk_plot_surface_set_shadow(GTK_PLOT_SURFACE(PyGtk_Get(obj)), PyGdkColor_Get(color));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_surface_set_grid_foreground(PyObject *self, PyObject *args)
{
    PyObject *obj, *color;

    if (!PyArg_ParseTuple(args, "O!O!:gtk_plot_surface_set_grid_foreground", &PyGtk_Type, &obj, &PyGdkColor_Type, &color))
        return NULL;
    gtk_plot_surface_set_grid_foreground(GTK_PLOT_SURFACE(PyGtk_Get(obj)), PyGdkColor_Get(color));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_surface_set_grid_background(PyObject *self, PyObject *args)
{
    PyObject *obj, *color;

    if (!PyArg_ParseTuple(args, "O!O!:gtk_plot_surface_set_grid_background", &PyGtk_Type, &obj, &PyGdkColor_Type, &color))
        return NULL;
    gtk_plot_surface_set_grid_background(GTK_PLOT_SURFACE(PyGtk_Get(obj)), PyGdkColor_Get(color));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_surface_set_grid_visible(PyObject *self, PyObject *args)
{
    int visible;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!i:gtk_plot_surface_set_grid_visible", &PyGtk_Type, &obj, &visible))
        return NULL;
    gtk_plot_surface_set_grid_visible(GTK_PLOT_SURFACE(PyGtk_Get(obj)), visible);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_surface_get_grid_visible(PyObject *self, PyObject *args)
{
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_plot_surface_get_grid_visible", &PyGtk_Type, &obj))
        return NULL;
    return PyInt_FromLong(gtk_plot_surface_get_grid_visible(GTK_PLOT_SURFACE(PyGtk_Get(obj))));
}

static PyObject *
_wrap_gtk_plot_surface_set_mesh_visible(PyObject *self, PyObject *args)
{
    int visible;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!i:gtk_plot_surface_set_mesh_visible", &PyGtk_Type, &obj, &visible))
        return NULL;
    gtk_plot_surface_set_mesh_visible(GTK_PLOT_SURFACE(PyGtk_Get(obj)), visible);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_surface_get_mesh_visible(PyObject *self, PyObject *args)
{
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_plot_surface_get_mesh_visible", &PyGtk_Type, &obj))
        return NULL;
    return PyInt_FromLong(gtk_plot_surface_get_mesh_visible(GTK_PLOT_SURFACE(PyGtk_Get(obj))));
}

static PyObject *
_wrap_gtk_plot_surface_set_light(PyObject *self, PyObject *args)
{
    double x, y, z;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!ddd:gtk_plot_surface_set_light", &PyGtk_Type, &obj, &x, &y, &z))
        return NULL;
    gtk_plot_surface_set_light(GTK_PLOT_SURFACE(PyGtk_Get(obj)), x, y, z);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_surface_set_ambient(PyObject *self, PyObject *args)
{
    double ambient;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!d:gtk_plot_surface_set_ambient", &PyGtk_Type, &obj, &ambient))
        return NULL;
    gtk_plot_surface_set_ambient(GTK_PLOT_SURFACE(PyGtk_Get(obj)), ambient);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_surface_use_height_gradient(PyObject *self, PyObject *args)
{
    int use_gradient;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!i:gtk_plot_surface_use_height_gradient", &PyGtk_Type, &obj, &use_gradient))
        return NULL;
    gtk_plot_surface_use_height_gradient(GTK_PLOT_SURFACE(PyGtk_Get(obj)), use_gradient);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_surface_set_transparent(PyObject *self, PyObject *args)
{
    int transparent;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!i:gtk_plot_surface_set_transparent", &PyGtk_Type, &obj, &transparent))
        return NULL;
    gtk_plot_surface_set_transparent(GTK_PLOT_SURFACE(PyGtk_Get(obj)), transparent);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_surface_get_nx(PyObject *self, PyObject *args)
{
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_plot_surface_get_nx", &PyGtk_Type, &obj))
        return NULL;
    return PyInt_FromLong(gtk_plot_surface_get_nx(GTK_PLOT_SURFACE(PyGtk_Get(obj))));
}

static PyObject *
_wrap_gtk_plot_surface_get_ny(PyObject *self, PyObject *args)
{
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_plot_surface_get_ny", &PyGtk_Type, &obj))
        return NULL;
    return PyInt_FromLong(gtk_plot_surface_get_ny(GTK_PLOT_SURFACE(PyGtk_Get(obj))));
}

static PyObject *
_wrap_gtk_plot_surface_set_xstep(PyObject *self, PyObject *args)
{
    double xstep;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!d:gtk_plot_surface_set_xstep", &PyGtk_Type, &obj, &xstep))
        return NULL;
    gtk_plot_surface_set_xstep(GTK_PLOT_SURFACE(PyGtk_Get(obj)), xstep);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_surface_set_ystep(PyObject *self, PyObject *args)
{
    double ystep;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!d:gtk_plot_surface_set_ystep", &PyGtk_Type, &obj, &ystep))
        return NULL;
    gtk_plot_surface_set_ystep(GTK_PLOT_SURFACE(PyGtk_Get(obj)), ystep);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_surface_get_xstep(PyObject *self, PyObject *args)
{
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_plot_surface_get_xstep", &PyGtk_Type, &obj))
        return NULL;
    return PyFloat_FromDouble(gtk_plot_surface_get_xstep(GTK_PLOT_SURFACE(PyGtk_Get(obj))));
}

static PyObject *
_wrap_gtk_plot_surface_get_ystep(PyObject *self, PyObject *args)
{
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_plot_surface_get_ystep", &PyGtk_Type, &obj))
        return NULL;
    return PyFloat_FromDouble(gtk_plot_surface_get_ystep(GTK_PLOT_SURFACE(PyGtk_Get(obj))));
}

static PyObject *
_wrap_gtk_plot_surface_build_mesh(PyObject *self, PyObject *args)
{
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_plot_surface_build_mesh", &PyGtk_Type, &obj))
        return NULL;
    gtk_plot_surface_build_mesh(GTK_PLOT_SURFACE(PyGtk_Get(obj)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_surface_recalc_nodes(PyObject *self, PyObject *args)
{
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_plot_surface_recalc_nodes", &PyGtk_Type, &obj))
        return NULL;
    gtk_plot_surface_recalc_nodes(GTK_PLOT_SURFACE(PyGtk_Get(obj)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_csurface_set_lines_visible(PyObject *self, PyObject *args)
{
    int visible;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!i:gtk_plot_csurface_set_lines_visible", &PyGtk_Type, &obj, &visible))
        return NULL;
    gtk_plot_csurface_set_lines_visible(GTK_PLOT_CSURFACE(PyGtk_Get(obj)), visible);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_csurface_get_lines_visible(PyObject *self, PyObject *args)
{
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_plot_csurface_get_lines_visible", &PyGtk_Type, &obj))
        return NULL;
    return PyInt_FromLong(gtk_plot_csurface_get_lines_visible(GTK_PLOT_CSURFACE(PyGtk_Get(obj))));
}

static PyObject *
_wrap_gtk_plot_csurface_set_lines_only(PyObject *self, PyObject *args)
{
    int lines_only;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!i:gtk_plot_csurface_set_lines_only", &PyGtk_Type, &obj, &lines_only))
        return NULL;
    gtk_plot_csurface_set_lines_only(GTK_PLOT_CSURFACE(PyGtk_Get(obj)), lines_only);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_csurface_lines_only(PyObject *self, PyObject *args)
{
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_plot_csurface_lines_only", &PyGtk_Type, &obj))
        return NULL;
    return PyInt_FromLong(gtk_plot_csurface_lines_only(GTK_PLOT_CSURFACE(PyGtk_Get(obj))));
}

static PyObject *
_wrap_gtk_plot_csurface_set_labels_visible(PyObject *self, PyObject *args)
{
    int visible;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!i:gtk_plot_csurface_set_labels_visible", &PyGtk_Type, &obj, &visible))
        return NULL;
    gtk_plot_csurface_set_labels_visible(GTK_PLOT_CSURFACE(PyGtk_Get(obj)), visible);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_csurface_labels_visible(PyObject *self, PyObject *args)
{
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_plot_csurface_labels_visible", &PyGtk_Type, &obj))
        return NULL;
    return PyInt_FromLong(gtk_plot_csurface_labels_visible(GTK_PLOT_CSURFACE(PyGtk_Get(obj))));
}

static PyObject *
_wrap_gtk_plot_pixmap_get_pixmap(PyObject *self, PyObject *args)
{
    GdkPixmap *ret;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_plot_pixmap_get_pixmap", &PyGtk_Type, &obj))
        return NULL;
    ret = gtk_plot_pixmap_get_pixmap(GTK_PLOT_PIXMAP(PyGtk_Get(obj)));
    if (ret)
        return PyGdkWindow_New(ret);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_pixmap_get_mask(PyObject *self, PyObject *args)
{
    PyObject *obj;
    GdkBitmap *ret;

    if (!PyArg_ParseTuple(args, "O!:gtk_plot_pixmap_get_mask", &PyGtk_Type, &obj))
        return NULL;
    ret = gtk_plot_pixmap_get_mask(GTK_PLOT_PIXMAP(PyGtk_Get(obj)));
    if (ret)
        return PyGdkWindow_New(ret);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_set_drawable(PyObject *self, PyObject *args)
{
    PyObject *obj, *drawable;

    if (!PyArg_ParseTuple(args, "O!O!:gtk_plot_set_drawable", &PyGtk_Type, &obj, &PyGdkWindow_Type, &drawable))
        return NULL;
    gtk_plot_set_drawable(GTK_PLOT(PyGtk_Get(obj)), PyGdkWindow_Get(drawable));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_get_drawable(PyObject *self, PyObject *args)
{
    GdkDrawable *ret;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_plot_get_drawable", &PyGtk_Type, &obj))
        return NULL;
    ret = gtk_plot_get_drawable(GTK_PLOT(PyGtk_Get(obj)));
    if (ret)
        return PyGdkWindow_New(ret);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_set_background_pixmap(PyObject *self, PyObject *args)
{
    PyObject *obj, *pixmap;

    if (!PyArg_ParseTuple(args, "O!O!:gtk_plot_set_background_pixmap", &PyGtk_Type, &obj, &PyGdkWindow_Type, &pixmap))
        return NULL;
    gtk_plot_set_background_pixmap(GTK_PLOT(PyGtk_Get(obj)), PyGdkWindow_Get(pixmap));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_set_transparent(PyObject *self, PyObject *args)
{
    int transparent;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!i:gtk_plot_set_transparent", &PyGtk_Type, &obj, &transparent))
        return NULL;
    gtk_plot_set_transparent(GTK_PLOT(PyGtk_Get(obj)), transparent);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_is_transparent(PyObject *self, PyObject *args)
{
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_plot_is_transparent", &PyGtk_Type, &obj))
        return NULL;
    return PyInt_FromLong(gtk_plot_is_transparent(GTK_PLOT(PyGtk_Get(obj))));
}

static PyObject *
_wrap_gtk_plot_set_background(PyObject *self, PyObject *args)
{
    PyObject *obj, *background;

    if (!PyArg_ParseTuple(args, "O!O!:gtk_plot_set_background", &PyGtk_Type, &obj, &PyGdkColor_Type, &background))
        return NULL;
    gtk_plot_set_background(GTK_PLOT(PyGtk_Get(obj)), PyGdkColor_Get(background));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_paint(PyObject *self, PyObject *args)
{
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_plot_paint", &PyGtk_Type, &obj))
        return NULL;
    gtk_plot_paint(GTK_PLOT(PyGtk_Get(obj)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_move(PyObject *self, PyObject *args)
{
    double x, y;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!dd:gtk_plot_move", &PyGtk_Type, &obj, &x, &y))
        return NULL;
    gtk_plot_move(GTK_PLOT(PyGtk_Get(obj)), x, y);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_resize(PyObject *self, PyObject *args)
{
    double width, height;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!dd:gtk_plot_resize", &PyGtk_Type, &obj, &width, &height))
        return NULL;
    gtk_plot_resize(GTK_PLOT(PyGtk_Get(obj)), width, height);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_set_magnification(PyObject *self, PyObject *args)
{
    double magnification;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!d:gtk_plot_set_magnification", &PyGtk_Type, &obj, &magnification))
        return NULL;
    gtk_plot_set_magnification(GTK_PLOT(PyGtk_Get(obj)), magnification);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_move_resize(PyObject *self, PyObject *args)
{
    double x, y, width, height;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!dddd:gtk_plot_move_resize", &PyGtk_Type, &obj, &x, &y, &width, &height))
        return NULL;
    gtk_plot_move_resize(GTK_PLOT(PyGtk_Get(obj)), x, y, width, height);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_clip_data(PyObject *self, PyObject *args)
{
    int clip;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!i:gtk_plot_clip_data", &PyGtk_Type, &obj, &clip))
        return NULL;
    gtk_plot_clip_data(GTK_PLOT(PyGtk_Get(obj)), clip);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_set_xrange(PyObject *self, PyObject *args)
{
    double xmin, xmax;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!dd:gtk_plot_set_xrange", &PyGtk_Type, &obj, &xmin, &xmax))
        return NULL;
    gtk_plot_set_xrange(GTK_PLOT(PyGtk_Get(obj)), xmin, xmax);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_set_yrange(PyObject *self, PyObject *args)
{
    double ymin, ymax;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!dd:gtk_plot_set_yrange", &PyGtk_Type, &obj, &ymin, &ymax))
        return NULL;
    gtk_plot_set_yrange(GTK_PLOT(PyGtk_Get(obj)), ymin, ymax);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_set_range(PyObject *self, PyObject *args)
{
    double xmin, xmax, ymin, ymax;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!dddd:gtk_plot_set_range", &PyGtk_Type, &obj, &xmin, &xmax, &ymin, &ymax))
        return NULL;
    gtk_plot_set_range(GTK_PLOT(PyGtk_Get(obj)), xmin, xmax, ymin, ymax);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_autoscale(PyObject *self, PyObject *args)
{
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_plot_autoscale", &PyGtk_Type, &obj))
        return NULL;
    gtk_plot_autoscale(GTK_PLOT(PyGtk_Get(obj)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_set_xscale(PyObject *self, PyObject *args)
{
    int scale_type;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!i:gtk_plot_set_xscale", &PyGtk_Type, &obj, &scale_type))
        return NULL;
    gtk_plot_set_xscale(GTK_PLOT(PyGtk_Get(obj)), scale_type);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_set_yscale(PyObject *self, PyObject *args)
{
    int scale_type;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!i:gtk_plot_set_yscale", &PyGtk_Type, &obj, &scale_type))
        return NULL;
    gtk_plot_set_yscale(GTK_PLOT(PyGtk_Get(obj)), scale_type);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_get_xscale(PyObject *self, PyObject *args)
{
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_plot_get_xscale", &PyGtk_Type, &obj))
        return NULL;
    return PyInt_FromLong(gtk_plot_get_xscale(GTK_PLOT(PyGtk_Get(obj))));
}

static PyObject *
_wrap_gtk_plot_get_yscale(PyObject *self, PyObject *args)
{
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_plot_get_yscale", &PyGtk_Type, &obj))
        return NULL;
    return PyInt_FromLong(gtk_plot_get_yscale(GTK_PLOT(PyGtk_Get(obj))));
}

static PyObject *
_wrap_gtk_plot_get_axis(PyObject *self, PyObject *args)
{
    PyObject *obj;
    int axis;
    GtkObject *ret;

    if (!PyArg_ParseTuple(args, "O!i:gtk_plot_get_axis", &PyGtk_Type, &obj, &axis))
        return NULL;
    ret = (GtkObject *) gtk_plot_get_axis(GTK_PLOT(PyGtk_Get(obj)), axis);
    if (ret)
        return PyGtk_New(ret);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_axis_set_visible(PyObject *self, PyObject *args)
{
    int axis, visible;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!ii:gtk_plot_axis_set_visible", &PyGtk_Type, &obj, &axis, &visible))
        return NULL;
    gtk_plot_axis_set_visible(GTK_PLOT(PyGtk_Get(obj)), axis, visible);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_axis_visible(PyObject *self, PyObject *args)
{
    int axis;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!i:gtk_plot_axis_visible", &PyGtk_Type, &obj, &axis))
        return NULL;
    return PyInt_FromLong(gtk_plot_axis_visible(GTK_PLOT(PyGtk_Get(obj)), axis));
}

static PyObject *
_wrap_gtk_plot_axis_set_title(PyObject *self, PyObject *args)
{
    int axis;
    char *title;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!iz:gtk_plot_axis_set_title", &PyGtk_Type, &obj, &axis, &title))
        return NULL;
    gtk_plot_axis_set_title(GTK_PLOT(PyGtk_Get(obj)), axis, title);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_axis_show_title(PyObject *self, PyObject *args)
{
    int axis;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!i:gtk_plot_axis_show_title", &PyGtk_Type, &obj, &axis))
        return NULL;
    gtk_plot_axis_show_title(GTK_PLOT(PyGtk_Get(obj)), axis);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_axis_hide_title(PyObject *self, PyObject *args)
{
    int axis;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!i:gtk_plot_axis_hide_title", &PyGtk_Type, &obj, &axis))
        return NULL;
    gtk_plot_axis_hide_title(GTK_PLOT(PyGtk_Get(obj)), axis);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_axis_move_title(PyObject *self, PyObject *args)
{
    PyObject *obj;
    double x, y;
    int axis, angle;

    if (!PyArg_ParseTuple(args, "O!iidd:gtk_plot_axis_move_title", &PyGtk_Type, &obj, &axis, &angle, &x, &y))
        return NULL;
    gtk_plot_axis_move_title(GTK_PLOT(PyGtk_Get(obj)), axis, angle, x, y);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_axis_justify_title(PyObject *self, PyObject *args)
{
    int axis, justification;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!ii:gtk_plot_axis_justify_title", &PyGtk_Type, &obj, &axis, &justification))
        return NULL;
    gtk_plot_axis_justify_title(GTK_PLOT(PyGtk_Get(obj)), axis, justification);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_axis_set_attributes(PyObject *self, PyObject *args)
{
    PyObject *obj, *color;
    double width;
    int axis;

    if (!PyArg_ParseTuple(args, "O!idO!:gtk_plot_axis_set_attributes", &PyGtk_Type, &obj, &axis, &width, &PyGdkColor_Type, &color))
        return NULL;
    gtk_plot_axis_set_attributes(GTK_PLOT(PyGtk_Get(obj)), axis, width, PyGdkColor_Get(color));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_axis_set_ticks(PyObject *self, PyObject *args)
{
    PyObject *obj;
    double major_step;
    int orientation, num_minor;

    if (!PyArg_ParseTuple(args, "O!idi:gtk_plot_axis_set_ticks", &PyGtk_Type, &obj, &orientation, &major_step, &num_minor))
        return NULL;
    gtk_plot_axis_set_ticks(GTK_PLOT(PyGtk_Get(obj)), orientation, major_step, num_minor);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_axis_set_major_ticks(PyObject *self, PyObject *args)
{
    int orientation;
    double major_step;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!id:gtk_plot_axis_set_major_ticks", &PyGtk_Type, &obj, &orientation, &major_step))
        return NULL;
    gtk_plot_axis_set_major_ticks(GTK_PLOT(PyGtk_Get(obj)), orientation, major_step);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_axis_set_minor_ticks(PyObject *self, PyObject *args)
{
    int orientation, num_minor;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!ii:gtk_plot_axis_set_minor_ticks", &PyGtk_Type, &obj, &orientation, &num_minor))
        return NULL;
    gtk_plot_axis_set_minor_ticks(GTK_PLOT(PyGtk_Get(obj)), orientation, num_minor);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_axis_set_ticks_length(PyObject *self, PyObject *args)
{
    int axis, length;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!ii:gtk_plot_axis_set_ticks_length", &PyGtk_Type, &obj, &axis, &length))
        return NULL;
    gtk_plot_axis_set_ticks_length(GTK_PLOT(PyGtk_Get(obj)), axis, length);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_axis_set_ticks_width(PyObject *self, PyObject *args)
{
    int axis;
    double width;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!id:gtk_plot_axis_set_ticks_width", &PyGtk_Type, &obj, &axis, &width))
        return NULL;
    gtk_plot_axis_set_ticks_width(GTK_PLOT(PyGtk_Get(obj)), axis, width);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_axis_show_ticks(PyObject *self, PyObject *args)
{
    int axis, major_mask, minor_mask;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!iii:gtk_plot_axis_show_ticks", &PyGtk_Type, &obj, &axis, &major_mask, &minor_mask))
        return NULL;
    gtk_plot_axis_show_ticks(GTK_PLOT(PyGtk_Get(obj)), axis, major_mask, minor_mask);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_axis_set_ticks_limits(PyObject *self, PyObject *args)
{
    PyObject *obj;
    double begin, end;
    int orientation;

    if (!PyArg_ParseTuple(args, "O!idd:gtk_plot_axis_set_ticks_limits", &PyGtk_Type, &obj, &orientation, &begin, &end))
        return NULL;
    gtk_plot_axis_set_ticks_limits(GTK_PLOT(PyGtk_Get(obj)), orientation, begin, end);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_axis_unset_ticks_limits(PyObject *self, PyObject *args)
{
    int orientation;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!i:gtk_plot_axis_unset_ticks_limits", &PyGtk_Type, &obj, &orientation))
        return NULL;
    gtk_plot_axis_unset_ticks_limits(GTK_PLOT(PyGtk_Get(obj)), orientation);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_axis_show_labels(PyObject *self, PyObject *args)
{
    int axis, labels_mask;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!ii:gtk_plot_axis_show_labels", &PyGtk_Type, &obj, &axis, &labels_mask))
        return NULL;
    gtk_plot_axis_show_labels(GTK_PLOT(PyGtk_Get(obj)), axis, labels_mask);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_axis_title_set_attributes(PyObject *self, PyObject *args)
{
    PyObject *obj, *py_foreground = Py_None, *py_background = Py_None;
    char *fontname;
    GdkColor *foreground = NULL, *background = NULL;
    int axis, height, angle, transparent, justification;

    if (!PyArg_ParseTuple(args, "O!iziiOOii:gtk_plot_axis_title_set_attributes", &PyGtk_Type, &obj, &axis, &fontname, &height, &angle, &py_foreground, &py_background, &transparent, &justification))
        return NULL;
    if (PyGdkColor_Check(py_foreground))
        foreground = PyGdkColor_Get(py_foreground);
    else if (py_foreground != Py_None) {
        PyErr_SetString(PyExc_TypeError, "foreground argument must be a GdkColor or None");
	return NULL;
    }
    if (PyGdkColor_Check(py_background))
        background = PyGdkColor_Get(py_background);
    else if (py_background != Py_None) {
        PyErr_SetString(PyExc_TypeError, "background argument must be a GdkColor or None");
	return NULL;
    }
    gtk_plot_axis_title_set_attributes(GTK_PLOT(PyGtk_Get(obj)), axis, fontname, height, angle, foreground, background, transparent, justification);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_axis_set_labels_attributes(PyObject *self, PyObject *args)
{
    PyObject *obj, *py_foreground = Py_None, *py_background = Py_None;
    char *fontname;
    GdkColor *foreground = NULL, *background = NULL;
    int axis, height, angle, transparent, justification;

    if (!PyArg_ParseTuple(args, "O!iziiOOii:gtk_plot_axis_set_labels_attributes", &PyGtk_Type, &obj, &axis, &fontname, &height, &angle, &py_foreground, &py_background, &transparent, &justification))
        return NULL;
    if (PyGdkColor_Check(py_foreground))
        foreground = PyGdkColor_Get(py_foreground);
    else if (py_foreground != Py_None) {
        PyErr_SetString(PyExc_TypeError, "foreground argument must be a GdkColor or None");
	return NULL;
    }
    if (PyGdkColor_Check(py_background))
        background = PyGdkColor_Get(py_background);
    else if (py_background != Py_None) {
        PyErr_SetString(PyExc_TypeError, "background argument must be a GdkColor or None");
	return NULL;
    }
    gtk_plot_axis_set_labels_attributes(GTK_PLOT(PyGtk_Get(obj)), axis, fontname, height, angle, foreground, background, transparent, justification);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_axis_set_labels_numbers(PyObject *self, PyObject *args)
{
    int axis, style, precision;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!iii:gtk_plot_axis_set_labels_numbers", &PyGtk_Type, &obj, &axis, &style, &precision))
        return NULL;
    gtk_plot_axis_set_labels_numbers(GTK_PLOT(PyGtk_Get(obj)), axis, style, precision);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_axis_set_labels_offset(PyObject *self, PyObject *args)
{
    int axis, offset;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!ii:gtk_plot_axis_set_labels_offset", &PyGtk_Type, &obj, &axis, &offset))
        return NULL;
    gtk_plot_axis_set_labels_offset(GTK_PLOT(PyGtk_Get(obj)), axis, offset);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_axis_get_labels_offset(PyObject *self, PyObject *args)
{
    int axis;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!i:gtk_plot_axis_get_labels_offset", &PyGtk_Type, &obj, &axis))
        return NULL;
    return PyInt_FromLong(gtk_plot_axis_get_labels_offset(GTK_PLOT(PyGtk_Get(obj)), axis));
}

static PyObject *
_wrap_gtk_plot_axis_use_custom_tick_labels(PyObject *self, PyObject *args)
{
    int axis, use;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!ii:gtk_plot_axis_use_custom_tick_labels", &PyGtk_Type, &obj, &axis, &use))
        return NULL;
    gtk_plot_axis_use_custom_tick_labels(GTK_PLOT(PyGtk_Get(obj)), axis, use);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_axis_set_labels_suffix(PyObject *self, PyObject *args)
{
    int axis;
    char *string;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!is:gtk_plot_axis_set_labels_suffix", &PyGtk_Type, &obj, &axis, &string))
        return NULL;
    gtk_plot_axis_set_labels_suffix(GTK_PLOT(PyGtk_Get(obj)), axis, string);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_axis_set_labels_prefix(PyObject *self, PyObject *args)
{
    int axis;
    char *string;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!is:gtk_plot_axis_set_labels_prefix", &PyGtk_Type, &obj, &axis, &string))
        return NULL;
    gtk_plot_axis_set_labels_prefix(GTK_PLOT(PyGtk_Get(obj)), axis, string);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_axis_get_labels_suffix(PyObject *self, PyObject *args)
{
    int axis;
    gchar *ret;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!i:gtk_plot_axis_get_labels_suffix", &PyGtk_Type, &obj, &axis))
        return NULL;
    ret = gtk_plot_axis_get_labels_suffix(GTK_PLOT(PyGtk_Get(obj)), axis);
    if (ret) {
        return PyString_FromString(ret);
    } else {
        Py_INCREF(Py_None);
        return Py_None;
    }
}

static PyObject *
_wrap_gtk_plot_axis_get_labels_prefix(PyObject *self, PyObject *args)
{
    int axis;
    gchar *ret;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!i:gtk_plot_axis_get_labels_prefix", &PyGtk_Type, &obj, &axis))
        return NULL;
    ret = gtk_plot_axis_get_labels_prefix(GTK_PLOT(PyGtk_Get(obj)), axis);
    if (ret) {
        return PyString_FromString(ret);
    } else {
        Py_INCREF(Py_None);
        return Py_None;
    }
}

static PyObject *
_wrap_gtk_plot_x0_set_visible(PyObject *self, PyObject *args)
{
    int visible;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!i:gtk_plot_x0_set_visible", &PyGtk_Type, &obj, &visible))
        return NULL;
    gtk_plot_x0_set_visible(GTK_PLOT(PyGtk_Get(obj)), visible);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_x0_visible(PyObject *self, PyObject *args)
{
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_plot_x0_visible", &PyGtk_Type, &obj))
        return NULL;
    return PyInt_FromLong(gtk_plot_x0_visible(GTK_PLOT(PyGtk_Get(obj))));
}

static PyObject *
_wrap_gtk_plot_y0_set_visible(PyObject *self, PyObject *args)
{
    int visible;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!i:gtk_plot_y0_set_visible", &PyGtk_Type, &obj, &visible))
        return NULL;
    gtk_plot_y0_set_visible(GTK_PLOT(PyGtk_Get(obj)), visible);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_y0_visible(PyObject *self, PyObject *args)
{
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_plot_y0_visible", &PyGtk_Type, &obj))
        return NULL;
    return PyInt_FromLong(gtk_plot_y0_visible(GTK_PLOT(PyGtk_Get(obj))));
}

static PyObject *
_wrap_gtk_plot_grids_set_on_top(PyObject *self, PyObject *args)
{
    int on_top;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!i:gtk_plot_grids_set_on_top", &PyGtk_Type, &obj, &on_top))
        return NULL;
    gtk_plot_grids_set_on_top(GTK_PLOT(PyGtk_Get(obj)), on_top);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_grids_on_top(PyObject *self, PyObject *args)
{
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_plot_grids_on_top", &PyGtk_Type, &obj))
        return NULL;
    return PyInt_FromLong(gtk_plot_grids_on_top(GTK_PLOT(PyGtk_Get(obj))));
}

static PyObject *
_wrap_gtk_plot_grids_set_visible(PyObject *self, PyObject *args)
{
    int vmajor, vminor, hmajor, hminor;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!iiii:gtk_plot_grids_set_visible", &PyGtk_Type, &obj, &vmajor, &vminor, &hmajor, &hminor))
        return NULL;
    gtk_plot_grids_set_visible(GTK_PLOT(PyGtk_Get(obj)), vmajor, vminor, hmajor, hminor);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_y0line_set_attributes(PyObject *self, PyObject *args)
{
    PyObject *obj, *color;
    double width;
    int line_style;

    if (!PyArg_ParseTuple(args, "O!idO!:gtk_plot_y0line_set_attributes", &PyGtk_Type, &obj, &line_style, &width, &PyGdkColor_Type, &color))
        return NULL;
    gtk_plot_y0line_set_attributes(GTK_PLOT(PyGtk_Get(obj)), line_style, width, PyGdkColor_Get(color));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_x0line_set_attributes(PyObject *self, PyObject *args)
{
    PyObject *obj, *color;
    double width;
    int style;

    if (!PyArg_ParseTuple(args, "O!idO!:gtk_plot_x0line_set_attributes", &PyGtk_Type, &obj, &style, &width, &PyGdkColor_Type, &color))
        return NULL;
    gtk_plot_x0line_set_attributes(GTK_PLOT(PyGtk_Get(obj)), style, width, PyGdkColor_Get(color));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_major_vgrid_set_attributes(PyObject *self, PyObject *args)
{
    PyObject *obj, *color;
    double width;
    int style;

    if (!PyArg_ParseTuple(args, "O!idO!:gtk_plot_major_vgrid_set_attributes", &PyGtk_Type, &obj, &style, &width, &PyGdkColor_Type, &color))
        return NULL;
    gtk_plot_major_vgrid_set_attributes(GTK_PLOT(PyGtk_Get(obj)), style, width, PyGdkColor_Get(color));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_minor_vgrid_set_attributes(PyObject *self, PyObject *args)
{
    PyObject *obj, *color;
    double width;
    int style;

    if (!PyArg_ParseTuple(args, "O!idO!:gtk_plot_minor_vgrid_set_attributes", &PyGtk_Type, &obj, &style, &width, &PyGdkColor_Type, &color))
        return NULL;
    gtk_plot_minor_vgrid_set_attributes(GTK_PLOT(PyGtk_Get(obj)), style, width, PyGdkColor_Get(color));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_major_hgrid_set_attributes(PyObject *self, PyObject *args)
{
    PyObject *obj, *color;
    double width;
    int style;

    if (!PyArg_ParseTuple(args, "O!idO!:gtk_plot_major_hgrid_set_attributes", &PyGtk_Type, &obj, &style, &width, &PyGdkColor_Type, &color))
        return NULL;
    gtk_plot_major_hgrid_set_attributes(GTK_PLOT(PyGtk_Get(obj)), style, width, PyGdkColor_Get(color));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_minor_hgrid_set_attributes(PyObject *self, PyObject *args)
{
    PyObject *obj, *color;
    double width;
    int style;

    if (!PyArg_ParseTuple(args, "O!idO!:gtk_plot_minor_hgrid_set_attributes", &PyGtk_Type, &obj, &style, &width, &PyGdkColor_Type, &color))
        return NULL;
    gtk_plot_minor_hgrid_set_attributes(GTK_PLOT(PyGtk_Get(obj)), style, width, PyGdkColor_Get(color));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_show_legends(PyObject *self, PyObject *args)
{
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_plot_show_legends", &PyGtk_Type, &obj))
        return NULL;
    gtk_plot_show_legends(GTK_PLOT(PyGtk_Get(obj)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_hide_legends(PyObject *self, PyObject *args)
{
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_plot_hide_legends", &PyGtk_Type, &obj))
        return NULL;
    gtk_plot_hide_legends(GTK_PLOT(PyGtk_Get(obj)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_set_legends_border(PyObject *self, PyObject *args)
{
    int border, shadow_width;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!ii:gtk_plot_set_legends_border", &PyGtk_Type, &obj, &border, &shadow_width))
        return NULL;
    gtk_plot_set_legends_border(GTK_PLOT(PyGtk_Get(obj)), border, shadow_width);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_legends_move(PyObject *self, PyObject *args)
{
    double x, y;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!dd:gtk_plot_legends_move", &PyGtk_Type, &obj, &x, &y))
        return NULL;
    gtk_plot_legends_move(GTK_PLOT(PyGtk_Get(obj)), x, y);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_legends_set_attributes(PyObject *self, PyObject *args)
{
    PyObject *obj, *py_foreground = Py_None, *py_background = Py_None;
    char *fontname;
    GdkColor *foreground = NULL, *background = NULL;
    int height;

    if (!PyArg_ParseTuple(args, "O!zi|OO:gtk_plot_legends_set_attributes", &PyGtk_Type, &obj, &fontname, &height, &py_foreground, &py_background))
        return NULL;
    if (PyGdkColor_Check(py_foreground))
        foreground = PyGdkColor_Get(py_foreground);
    else if (py_foreground != Py_None) {
        PyErr_SetString(PyExc_TypeError, "foreground argument must be a GdkColor or None");
	return NULL;
    }
    if (PyGdkColor_Check(py_background))
        background = PyGdkColor_Get(py_background);
    else if (py_background != Py_None) {
        PyErr_SetString(PyExc_TypeError, "background argument must be a GdkColor or None");
	return NULL;
    }
    gtk_plot_legends_set_attributes(GTK_PLOT(PyGtk_Get(obj)), fontname, height, foreground, background);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_polar_rotate(PyObject *self, PyObject *args)
{
    double angle;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!d:gtk_plot_polar_rotate", &PyGtk_Type, &obj, &angle))
        return NULL;
    gtk_plot_polar_rotate(GTK_PLOT_POLAR(PyGtk_Get(obj)), angle);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot3d_autoscale(PyObject *self, PyObject *args)
{
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_plot3d_autoscale", &PyGtk_Type, &obj))
        return NULL;
    gtk_plot3d_autoscale(GTK_PLOT3D(PyGtk_Get(obj)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot3d_rotate(PyObject *self, PyObject *args)
{
    double angle_x, angle_y, angle_z;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!ddd:gtk_plot3d_rotate", &PyGtk_Type, &obj, &angle_x, &angle_y, &angle_z))
        return NULL;
    gtk_plot3d_rotate(GTK_PLOT3D(PyGtk_Get(obj)), angle_x, angle_y, angle_z);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot3d_reset_angles(PyObject *self, PyObject *args)
{
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_plot3d_reset_angles", &PyGtk_Type, &obj))
        return NULL;
    gtk_plot3d_reset_angles(GTK_PLOT3D(PyGtk_Get(obj)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot3d_rotate_x(PyObject *self, PyObject *args)
{
    double angle;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!d:gtk_plot3d_rotate_x", &PyGtk_Type, &obj, &angle))
        return NULL;
    gtk_plot3d_rotate_x(GTK_PLOT3D(PyGtk_Get(obj)), angle);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot3d_rotate_y(PyObject *self, PyObject *args)
{
    double angle;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!d:gtk_plot3d_rotate_y", &PyGtk_Type, &obj, &angle))
        return NULL;
    gtk_plot3d_rotate_y(GTK_PLOT3D(PyGtk_Get(obj)), angle);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot3d_rotate_z(PyObject *self, PyObject *args)
{
    double angle;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!d:gtk_plot3d_rotate_z", &PyGtk_Type, &obj, &angle))
        return NULL;
    gtk_plot3d_rotate_z(GTK_PLOT3D(PyGtk_Get(obj)), angle);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot3d_set_xrange(PyObject *self, PyObject *args)
{
    double xmin, xmax;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!dd:gtk_plot3d_set_xrange", &PyGtk_Type, &obj, &xmin, &xmax))
        return NULL;
    gtk_plot3d_set_xrange(GTK_PLOT3D(PyGtk_Get(obj)), xmin, xmax);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot3d_set_yrange(PyObject *self, PyObject *args)
{
    double ymin, ymax;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!dd:gtk_plot3d_set_yrange", &PyGtk_Type, &obj, &ymin, &ymax))
        return NULL;
    gtk_plot3d_set_yrange(GTK_PLOT3D(PyGtk_Get(obj)), ymin, ymax);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot3d_set_zrange(PyObject *self, PyObject *args)
{
    double zmin, zmax;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!dd:gtk_plot3d_set_zrange", &PyGtk_Type, &obj, &zmin, &zmax))
        return NULL;
    gtk_plot3d_set_zrange(GTK_PLOT3D(PyGtk_Get(obj)), zmin, zmax);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot3d_set_xfactor(PyObject *self, PyObject *args)
{
    double xfactor;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!d:gtk_plot3d_set_xfactor", &PyGtk_Type, &obj, &xfactor))
        return NULL;
    gtk_plot3d_set_xfactor(GTK_PLOT3D(PyGtk_Get(obj)), xfactor);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot3d_set_yfactor(PyObject *self, PyObject *args)
{
    double yfactor;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!d:gtk_plot3d_set_yfactor", &PyGtk_Type, &obj, &yfactor))
        return NULL;
    gtk_plot3d_set_yfactor(GTK_PLOT3D(PyGtk_Get(obj)), yfactor);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot3d_set_zfactor(PyObject *self, PyObject *args)
{
    double zfactor;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!d:gtk_plot3d_set_zfactor", &PyGtk_Type, &obj, &zfactor))
        return NULL;
    gtk_plot3d_set_zfactor(GTK_PLOT3D(PyGtk_Get(obj)), zfactor);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot3d_get_xfactor(PyObject *self, PyObject *args)
{
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_plot3d_get_xfactor", &PyGtk_Type, &obj))
        return NULL;
    return PyFloat_FromDouble(gtk_plot3d_get_xfactor(GTK_PLOT3D(PyGtk_Get(obj))));
}

static PyObject *
_wrap_gtk_plot3d_get_yfactor(PyObject *self, PyObject *args)
{
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_plot3d_get_yfactor", &PyGtk_Type, &obj))
        return NULL;
    return PyFloat_FromDouble(gtk_plot3d_get_yfactor(GTK_PLOT3D(PyGtk_Get(obj))));
}

static PyObject *
_wrap_gtk_plot3d_get_zfactor(PyObject *self, PyObject *args)
{
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_plot3d_get_zfactor", &PyGtk_Type, &obj))
        return NULL;
    return PyFloat_FromDouble(gtk_plot3d_get_zfactor(GTK_PLOT3D(PyGtk_Get(obj))));
}

static PyObject *
_wrap_gtk_plot3d_plane_set_color(PyObject *self, PyObject *args)
{
    int plane;
    PyObject *obj, *color;

    if (!PyArg_ParseTuple(args, "O!iO!:gtk_plot3d_plane_set_color", &PyGtk_Type, &obj, &plane, &PyGdkColor_Type, &color))
        return NULL;
    gtk_plot3d_plane_set_color(GTK_PLOT3D(PyGtk_Get(obj)), plane, PyGdkColor_Get(color));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot3d_plane_set_visible(PyObject *self, PyObject *args)
{
    int plane, visible;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!ii:gtk_plot3d_plane_set_visible", &PyGtk_Type, &obj, &plane, &visible))
        return NULL;
    gtk_plot3d_plane_set_visible(GTK_PLOT3D(PyGtk_Get(obj)), plane, visible);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot3d_plane_visible(PyObject *self, PyObject *args)
{
    int plane;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!i:gtk_plot3d_plane_visible", &PyGtk_Type, &obj, &plane))
        return NULL;
    return PyInt_FromLong(gtk_plot3d_plane_visible(GTK_PLOT3D(PyGtk_Get(obj)), plane));
}

static PyObject *
_wrap_gtk_plot3d_corner_set_visible(PyObject *self, PyObject *args)
{
    int visible;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!i:gtk_plot3d_corner_set_visible", &PyGtk_Type, &obj, &visible))
        return NULL;
    gtk_plot3d_corner_set_visible(GTK_PLOT3D(PyGtk_Get(obj)), visible);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot3d_corner_visible(PyObject *self, PyObject *args)
{
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_plot3d_corner_visible", &PyGtk_Type, &obj))
        return NULL;
    return PyInt_FromLong(gtk_plot3d_corner_visible(GTK_PLOT3D(PyGtk_Get(obj))));
}

static PyObject *
_wrap_gtk_plot3d_corner_set_attributes(PyObject *self, PyObject *args)
{
    PyObject *obj, *color;
    double width;
    int line_style;

    if (!PyArg_ParseTuple(args, "O!idO!:gtk_plot3d_corner_set_attributes", &PyGtk_Type, &obj, &line_style, &width, &PyGdkColor_Type, &color))
        return NULL;
    gtk_plot3d_corner_set_attributes(GTK_PLOT3D(PyGtk_Get(obj)), line_style, width, PyGdkColor_Get(color));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot3d_frame_set_attributes(PyObject *self, PyObject *args)
{
    PyObject *obj, *color;
    double width;
    int line_style;

    if (!PyArg_ParseTuple(args, "O!idO!:gtk_plot3d_frame_set_attributes", &PyGtk_Type, &obj, &line_style, &width, &PyGdkColor_Type, &color))
        return NULL;
    gtk_plot3d_frame_set_attributes(GTK_PLOT3D(PyGtk_Get(obj)), line_style, width, PyGdkColor_Get(color));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot3d_get_axis(PyObject *self, PyObject *args)
{
    PyObject *obj;
    int orientation;
    GtkObject *ret;

    if (!PyArg_ParseTuple(args, "O!i:gtk_plot3d_get_axis", &PyGtk_Type, &obj, &orientation))
        return NULL;
    ret = (GtkObject *) gtk_plot3d_get_axis(GTK_PLOT3D(PyGtk_Get(obj)), orientation);
    if (ret)
        return PyGtk_New(ret);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot3d_get_side(PyObject *self, PyObject *args)
{
    PyObject *obj;
    int side;
    GtkObject *ret;

    if (!PyArg_ParseTuple(args, "O!i:gtk_plot3d_get_side", &PyGtk_Type, &obj, &side))
        return NULL;
    ret = (GtkObject *) gtk_plot3d_get_side(GTK_PLOT3D(PyGtk_Get(obj)), side);
    if (ret)
        return PyGtk_New(ret);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot3d_axis_show_major_ticks(PyObject *self, PyObject *args)
{
    int side, ticks_mask;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!ii:gtk_plot3d_axis_show_major_ticks", &PyGtk_Type, &obj, &side, &ticks_mask))
        return NULL;
    gtk_plot3d_axis_show_major_ticks(GTK_PLOT3D(PyGtk_Get(obj)), side, ticks_mask);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot3d_axis_show_minor_ticks(PyObject *self, PyObject *args)
{
    int side, ticks_mask;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!ii:gtk_plot3d_axis_show_minor_ticks", &PyGtk_Type, &obj, &side, &ticks_mask))
        return NULL;
    gtk_plot3d_axis_show_minor_ticks(GTK_PLOT3D(PyGtk_Get(obj)), side, ticks_mask);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot3d_axis_show_labels(PyObject *self, PyObject *args)
{
    int side, label_mask;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!ii:gtk_plot3d_axis_show_labels", &PyGtk_Type, &obj, &side, &label_mask))
        return NULL;
    gtk_plot3d_axis_show_labels(GTK_PLOT3D(PyGtk_Get(obj)), side, label_mask);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot3d_axis_show_title(PyObject *self, PyObject *args)
{
    int side;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!i:gtk_plot3d_axis_show_title", &PyGtk_Type, &obj, &side))
        return NULL;
    gtk_plot3d_axis_show_title(GTK_PLOT3D(PyGtk_Get(obj)), side);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot3d_axis_hide_title(PyObject *self, PyObject *args)
{
    int side;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!i:gtk_plot3d_axis_hide_title", &PyGtk_Type, &obj, &side))
        return NULL;
    gtk_plot3d_axis_hide_title(GTK_PLOT3D(PyGtk_Get(obj)), side);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot3d_axis_set_ticks(PyObject *self, PyObject *args)
{
    PyObject *obj;
    double major_step;
    int orientation, num_minor;

    if (!PyArg_ParseTuple(args, "O!idi:gtk_plot3d_axis_set_ticks", &PyGtk_Type, &obj, &orientation, &major_step, &num_minor))
        return NULL;
    gtk_plot3d_axis_set_ticks(GTK_PLOT3D(PyGtk_Get(obj)), orientation, major_step, num_minor);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot3d_axis_set_major_ticks(PyObject *self, PyObject *args)
{
    int orientation;
    double major_step;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!id:gtk_plot3d_axis_set_major_ticks", &PyGtk_Type, &obj, &orientation, &major_step))
        return NULL;
    gtk_plot3d_axis_set_major_ticks(GTK_PLOT3D(PyGtk_Get(obj)), orientation, major_step);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot3d_axis_set_minor_ticks(PyObject *self, PyObject *args)
{
    int orientation, num_minor;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!ii:gtk_plot3d_axis_set_minor_ticks", &PyGtk_Type, &obj, &orientation, &num_minor))
        return NULL;
    gtk_plot3d_axis_set_minor_ticks(GTK_PLOT3D(PyGtk_Get(obj)), orientation, num_minor);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot3d_axis_set_ticks_length(PyObject *self, PyObject *args)
{
    int orientation, length;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!ii:gtk_plot3d_axis_set_ticks_length", &PyGtk_Type, &obj, &orientation, &length))
        return NULL;
    gtk_plot3d_axis_set_ticks_length(GTK_PLOT3D(PyGtk_Get(obj)), orientation, length);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot3d_axis_set_ticks_width(PyObject *self, PyObject *args)
{
    int orientation;
    double width;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!id:gtk_plot3d_axis_set_ticks_width", &PyGtk_Type, &obj, &orientation, &width))
        return NULL;
    gtk_plot3d_axis_set_ticks_width(GTK_PLOT3D(PyGtk_Get(obj)), orientation, width);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot3d_axis_show_ticks(PyObject *self, PyObject *args)
{
    int side, major_mask, minor_mask;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!iii:gtk_plot3d_axis_show_ticks", &PyGtk_Type, &obj, &side, &major_mask, &minor_mask))
        return NULL;
    gtk_plot3d_axis_show_ticks(GTK_PLOT3D(PyGtk_Get(obj)), side, major_mask, minor_mask);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot3d_set_titles_offset(PyObject *self, PyObject *args)
{
    int offset;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!i:gtk_plot3d_set_titles_offset", &PyGtk_Type, &obj, &offset))
        return NULL;
    gtk_plot3d_set_titles_offset(GTK_PLOT3D(PyGtk_Get(obj)), offset);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot3d_get_titles_offset(PyObject *self, PyObject *args)
{
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_plot3d_get_titles_offset", &PyGtk_Type, &obj))
        return NULL;
    return PyInt_FromLong(gtk_plot3d_get_titles_offset(GTK_PLOT3D(PyGtk_Get(obj))));
}

static PyObject *
_wrap_gtk_plot3d_major_grids_set_visible(PyObject *self, PyObject *args)
{
    int x, y, z;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!iii:gtk_plot3d_major_grids_set_visible", &PyGtk_Type, &obj, &x, &y, &z))
        return NULL;
    gtk_plot3d_major_grids_set_visible(GTK_PLOT3D(PyGtk_Get(obj)), x, y, z);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot3d_minor_grids_set_visible(PyObject *self, PyObject *args)
{
    int x, y, z;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!iii:gtk_plot3d_minor_grids_set_visible", &PyGtk_Type, &obj, &x, &y, &z))
        return NULL;
    gtk_plot3d_minor_grids_set_visible(GTK_PLOT3D(PyGtk_Get(obj)), x, y, z);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot3d_major_zgrid_set_attributes(PyObject *self, PyObject *args)
{
    PyObject *obj, *color;
    double width;
    int line_style;

    if (!PyArg_ParseTuple(args, "O!idO!:gtk_plot3d_major_zgrid_set_attributes", &PyGtk_Type, &obj, &line_style, &width, &PyGdkColor_Type, &color))
        return NULL;
    gtk_plot3d_major_zgrid_set_attributes(GTK_PLOT3D(PyGtk_Get(obj)), line_style, width, PyGdkColor_Get(color));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot3d_minor_zgrid_set_attributes(PyObject *self, PyObject *args)
{
    PyObject *obj, *color;
    double width;
    int line_style;

    if (!PyArg_ParseTuple(args, "O!idO!:gtk_plot3d_minor_zgrid_set_attributes", &PyGtk_Type, &obj, &line_style, &width, &PyGdkColor_Type, &color))
        return NULL;
    gtk_plot3d_minor_zgrid_set_attributes(GTK_PLOT3D(PyGtk_Get(obj)), line_style, width, PyGdkColor_Get(color));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_canvas_new(PyObject *self, PyObject *args)
{
    int width, height;
    double magnification = 1.0;
    GtkObject *ret;

    if (!PyArg_ParseTuple(args, "ii|d:gtk_plot_canvas_new", &width, &height, &magnification))
        return NULL;
    ret = (GtkObject *) gtk_plot_canvas_new(width, height, magnification);
    if (ret)
        return PyGtk_New(ret);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_canvas_paint(PyObject *self, PyObject *args)
{
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_plot_canvas_paint", &PyGtk_Type, &obj))
        return NULL;
    gtk_plot_canvas_paint(GTK_PLOT_CANVAS(PyGtk_Get(obj)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_canvas_refresh(PyObject *self, PyObject *args)
{
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_plot_canvas_refresh", &PyGtk_Type, &obj))
        return NULL;
    gtk_plot_canvas_refresh(GTK_PLOT_CANVAS(PyGtk_Get(obj)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_canvas_freeze(PyObject *self, PyObject *args)
{
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_plot_canvas_freeze", &PyGtk_Type, &obj))
        return NULL;
    gtk_plot_canvas_freeze(GTK_PLOT_CANVAS(PyGtk_Get(obj)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_canvas_thaw(PyObject *self, PyObject *args)
{
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_plot_canvas_thaw", &PyGtk_Type, &obj))
        return NULL;
    gtk_plot_canvas_thaw(GTK_PLOT_CANVAS(PyGtk_Get(obj)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_canvas_grid_set_visible(PyObject *self, PyObject *args)
{
    int visible;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!i:gtk_plot_canvas_grid_set_visible", &PyGtk_Type, &obj, &visible))
        return NULL;
    gtk_plot_canvas_grid_set_visible(GTK_PLOT_CANVAS(PyGtk_Get(obj)), visible);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_canvas_grid_set_step(PyObject *self, PyObject *args)
{
    double step;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!d:gtk_plot_canvas_grid_set_step", &PyGtk_Type, &obj, &step))
        return NULL;
    gtk_plot_canvas_grid_set_step(GTK_PLOT_CANVAS(PyGtk_Get(obj)), step);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_canvas_grid_set_attributes(PyObject *self, PyObject *args)
{
    int line_style, width;
    GdkColor *color = NULL;
    PyObject *obj, *py_color = Py_None;

    if (!PyArg_ParseTuple(args, "O!iiO:gtk_plot_canvas_grid_set_attributes", &PyGtk_Type, &obj, &line_style, &width, &py_color))
        return NULL;
    if (PyGdkColor_Check(py_color))
        color = PyGdkColor_Get(py_color);
    else if (py_color != Py_None) {
        PyErr_SetString(PyExc_TypeError, "color argument must be a GdkColor or None");
	return NULL;
    }
    gtk_plot_canvas_grid_set_attributes(GTK_PLOT_CANVAS(PyGtk_Get(obj)), line_style, width, color);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_canvas_add_plot(PyObject *self, PyObject *args)
{
    double x, y;
    PyObject *obj, *plot;

    if (!PyArg_ParseTuple(args, "O!O!dd:gtk_plot_canvas_add_plot", &PyGtk_Type, &obj, &PyGtk_Type, &plot, &x, &y))
        return NULL;
    gtk_plot_canvas_add_plot(GTK_PLOT_CANVAS(PyGtk_Get(obj)), GTK_PLOT(PyGtk_Get(plot)), x, y);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_canvas_set_active_plot(PyObject *self, PyObject *args)
{
    PyObject *obj, *plot;

    if (!PyArg_ParseTuple(args, "O!O!:gtk_plot_canvas_set_active_plot", &PyGtk_Type, &obj, &PyGtk_Type, &plot))
        return NULL;
    gtk_plot_canvas_set_active_plot(GTK_PLOT_CANVAS(PyGtk_Get(obj)), GTK_PLOT(PyGtk_Get(plot)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_canvas_cancel_action(PyObject *self, PyObject *args)
{
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_plot_canvas_cancel_action", &PyGtk_Type, &obj))
        return NULL;
    gtk_plot_canvas_cancel_action(GTK_PLOT_CANVAS(PyGtk_Get(obj)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_canvas_unselect(PyObject *self, PyObject *args)
{
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_plot_canvas_unselect", &PyGtk_Type, &obj))
        return NULL;
    gtk_plot_canvas_unselect(GTK_PLOT_CANVAS(PyGtk_Get(obj)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_canvas_get_active_plot(PyObject *self, PyObject *args)
{
    PyObject *obj;
    GtkObject *ret;

    if (!PyArg_ParseTuple(args, "O!:gtk_plot_canvas_get_active_plot", &PyGtk_Type, &obj))
        return NULL;
    ret = (GtkObject *) gtk_plot_canvas_get_active_plot(GTK_PLOT_CANVAS(PyGtk_Get(obj)));
    if (ret)
        return PyGtk_New(ret);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_canvas_get_active_data(PyObject *self, PyObject *args)
{
    PyObject *obj;
    GtkObject *ret;

    if (!PyArg_ParseTuple(args, "O!:gtk_plot_canvas_get_active_data", &PyGtk_Type, &obj))
        return NULL;
    ret = (GtkObject *) gtk_plot_canvas_get_active_data(GTK_PLOT_CANVAS(PyGtk_Get(obj)));
    if (ret)
        return PyGtk_New(ret);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_canvas_set_size(PyObject *self, PyObject *args)
{
    int width, height;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!ii:gtk_plot_canvas_set_size", &PyGtk_Type, &obj, &width, &height))
        return NULL;
    gtk_plot_canvas_set_size(GTK_PLOT_CANVAS(PyGtk_Get(obj)), width, height);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_canvas_set_magnification(PyObject *self, PyObject *args)
{
    double magnification;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!d:gtk_plot_canvas_set_magnification", &PyGtk_Type, &obj, &magnification))
        return NULL;
    gtk_plot_canvas_set_magnification(GTK_PLOT_CANVAS(PyGtk_Get(obj)), magnification);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_plot_canvas_set_background(PyObject *self, PyObject *args)
{
    PyObject *obj, *color;

    if (!PyArg_ParseTuple(args, "O!O!:gtk_plot_canvas_set_background", &PyGtk_Type, &obj, &PyGdkColor_Type, &color))
        return NULL;
    gtk_plot_canvas_set_background(GTK_PLOT_CANVAS(PyGtk_Get(obj)), PyGdkColor_Get(color));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_icon_list_set_mode(PyObject *self, PyObject *args)
{
    int mode;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!i:gtk_icon_list_set_mode", &PyGtk_Type, &obj, &mode))
        return NULL;
    gtk_icon_list_set_mode(GTK_ICON_LIST(PyGtk_Get(obj)), mode);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_icon_list_get_mode(PyObject *self, PyObject *args)
{
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_icon_list_get_mode", &PyGtk_Type, &obj))
        return NULL;
    return PyInt_FromLong(gtk_icon_list_get_mode(GTK_ICON_LIST(PyGtk_Get(obj))));
}

static PyObject *
_wrap_gtk_icon_list_set_editable(PyObject *self, PyObject *args)
{
    int editable;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!i:gtk_icon_list_set_editable", &PyGtk_Type, &obj, &editable))
        return NULL;
    gtk_icon_list_set_editable(GTK_ICON_LIST(PyGtk_Get(obj)), editable);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_icon_list_is_editable(PyObject *self, PyObject *args)
{
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_icon_list_is_editable", &PyGtk_Type, &obj))
        return NULL;
    return PyInt_FromLong(gtk_icon_list_is_editable(GTK_ICON_LIST(PyGtk_Get(obj))));
}

static PyObject *
_wrap_gtk_icon_list_set_row_spacing(PyObject *self, PyObject *args)
{
    int spacing;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!i:gtk_icon_list_set_row_spacing", &PyGtk_Type, &obj, &spacing))
        return NULL;
    gtk_icon_list_set_row_spacing(GTK_ICON_LIST(PyGtk_Get(obj)), spacing);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_icon_list_get_row_spacing(PyObject *self, PyObject *args)
{
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_icon_list_get_row_spacing", &PyGtk_Type, &obj))
        return NULL;
    return PyInt_FromLong(gtk_icon_list_get_row_spacing(GTK_ICON_LIST(PyGtk_Get(obj))));
}

static PyObject *
_wrap_gtk_icon_list_set_col_spacing(PyObject *self, PyObject *args)
{
    int spacing;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!i:gtk_icon_list_set_col_spacing", &PyGtk_Type, &obj, &spacing))
        return NULL;
    gtk_icon_list_set_col_spacing(GTK_ICON_LIST(PyGtk_Get(obj)), spacing);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_icon_list_get_col_spacing(PyObject *self, PyObject *args)
{
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_icon_list_get_col_spacing", &PyGtk_Type, &obj))
        return NULL;
    return PyInt_FromLong(gtk_icon_list_get_col_spacing(GTK_ICON_LIST(PyGtk_Get(obj))));
}

static PyObject *
_wrap_gtk_icon_list_set_text_space(PyObject *self, PyObject *args)
{
    int size;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!i:gtk_icon_list_set_text_space", &PyGtk_Type, &obj, &size))
        return NULL;
    gtk_icon_list_set_text_space(GTK_ICON_LIST(PyGtk_Get(obj)), size);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_icon_list_get_text_space(PyObject *self, PyObject *args)
{
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_icon_list_get_text_space", &PyGtk_Type, &obj))
        return NULL;
    return PyInt_FromLong(gtk_icon_list_get_text_space(GTK_ICON_LIST(PyGtk_Get(obj))));
}

static PyObject *
_wrap_gtk_icon_list_set_icon_border(PyObject *self, PyObject *args)
{
    int width;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!i:gtk_icon_list_set_icon_border", &PyGtk_Type, &obj, &width))
        return NULL;
    gtk_icon_list_set_icon_border(GTK_ICON_LIST(PyGtk_Get(obj)), width);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_icon_list_get_icon_border(PyObject *self, PyObject *args)
{
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_icon_list_get_icon_border", &PyGtk_Type, &obj))
        return NULL;
    return PyInt_FromLong(gtk_icon_list_get_icon_border(GTK_ICON_LIST(PyGtk_Get(obj))));
}

static PyObject *
_wrap_gtk_icon_list_set_icon_width(PyObject *self, PyObject *args)
{
    int width;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!i:gtk_icon_list_set_icon_width", &PyGtk_Type, &obj, &width))
        return NULL;
    gtk_icon_list_set_icon_width(GTK_ICON_LIST(PyGtk_Get(obj)), width);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_icon_list_get_icon_width(PyObject *self, PyObject *args)
{
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_icon_list_get_icon_width", &PyGtk_Type, &obj))
        return NULL;
    return PyInt_FromLong(gtk_icon_list_get_icon_width(GTK_ICON_LIST(PyGtk_Get(obj))));
}

static PyObject *
_wrap_gtk_icon_list_freeze(PyObject *self, PyObject *args)
{
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_icon_list_freeze", &PyGtk_Type, &obj))
        return NULL;
    gtk_icon_list_freeze(GTK_ICON_LIST(PyGtk_Get(obj)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_icon_list_thaw(PyObject *self, PyObject *args)
{
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_icon_list_thaw", &PyGtk_Type, &obj))
        return NULL;
    gtk_icon_list_thaw(GTK_ICON_LIST(PyGtk_Get(obj)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_icon_list_set_background(PyObject *self, PyObject *args)
{
    PyObject *obj, *color;

    if (!PyArg_ParseTuple(args, "O!O!:gtk_icon_list_set_background", &PyGtk_Type, &obj, &PyGdkColor_Type, &color))
        return NULL;
    gtk_icon_list_set_background(GTK_ICON_LIST(PyGtk_Get(obj)), PyGdkColor_Get(color));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_icon_list_update(PyObject *self, PyObject *args)
{
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_icon_list_update", &PyGtk_Type, &obj))
        return NULL;
    gtk_icon_list_update(GTK_ICON_LIST(PyGtk_Get(obj)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_icon_list_set_selection_mode(PyObject *self, PyObject *args)
{
    int mode;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!i:gtk_icon_list_set_selection_mode", &PyGtk_Type, &obj, &mode))
        return NULL;
    gtk_icon_list_set_selection_mode(GTK_ICON_LIST(PyGtk_Get(obj)), mode);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_icon_list_unselect_all(PyObject *self, PyObject *args)
{
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_icon_list_unselect_all", &PyGtk_Type, &obj))
        return NULL;
    gtk_icon_list_unselect_all(GTK_ICON_LIST(PyGtk_Get(obj)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_dir_tree_new(PyObject *self, PyObject *args)
{
    GtkObject *ret;

    if (!PyArg_ParseTuple(args, ":gtk_dir_tree_new"))
        return NULL;
    ret = (GtkObject *) gtk_dir_tree_new();
    if (ret)
        return PyGtk_New(ret);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_dir_tree_open_dir(PyObject *self, PyObject *args)
{
    char *path;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!s:gtk_dir_tree_open_dir", &PyGtk_Type, &obj, &path))
        return NULL;
    return PyInt_FromLong(gtk_dir_tree_open_dir(GTK_DIR_TREE(PyGtk_Get(obj)), path));
}

static PyObject *
_wrap_gtk_file_list_set_filter(PyObject *self, PyObject *args)
{
    char *pattern;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!z:gtk_file_list_set_filter", &PyGtk_Type, &obj, &pattern))
        return NULL;
    gtk_file_list_set_filter(GTK_FILE_LIST(PyGtk_Get(obj)), pattern);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_file_list_open_dir(PyObject *self, PyObject *args)
{
    char *path;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!z:gtk_file_list_open_dir", &PyGtk_Type, &obj, &path))
        return NULL;
    return PyInt_FromLong(gtk_file_list_open_dir(GTK_FILE_LIST(PyGtk_Get(obj)), path));
}

static PyObject *
_wrap_gtk_file_list_get_path(PyObject *self, PyObject *args)
{
    gchar *ret;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_file_list_get_path", &PyGtk_Type, &obj))
        return NULL;
    ret = gtk_file_list_get_path(GTK_FILE_LIST(PyGtk_Get(obj)));
    if (ret) {
        return PyString_FromString(ret);
    } else {
        Py_INCREF(Py_None);
        return Py_None;
    }
}

static PyObject *
_wrap_gtk_file_list_get_filetype(PyObject *self, PyObject *args)
{
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_file_list_get_filetype", &PyGtk_Type, &obj))
        return NULL;
    return PyInt_FromLong(gtk_file_list_get_filetype(GTK_FILE_LIST(PyGtk_Get(obj))));
}

static PyObject *
_wrap_gtk_file_list_add_type_filter(PyObject *self, PyObject *args)
{
    int type;
    char *pattern;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!is:gtk_file_list_add_type_filter", &PyGtk_Type, &obj, &type, &pattern))
        return NULL;
    gtk_file_list_add_type_filter(GTK_FILE_LIST(PyGtk_Get(obj)), type, pattern);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_icon_file_selection_open_dir(PyObject *self, PyObject *args)
{
    char *path;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!s:gtk_icon_file_selection_open_dir", &PyGtk_Type, &obj, &path))
        return NULL;
    return PyInt_FromLong(gtk_icon_file_selection_open_dir(GTK_ICON_FILE_SELECTION(PyGtk_Get(obj)), path));
}

static PyObject *
_wrap_gtk_icon_file_selection_show_hidden(PyObject *self, PyObject *args)
{
    int visible;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!i:gtk_icon_file_selection_show_hidden", &PyGtk_Type, &obj, &visible))
        return NULL;
    gtk_icon_file_selection_show_hidden(GTK_ICON_FILE_SELECTION(PyGtk_Get(obj)), visible);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_icon_file_selection_show_tree(PyObject *self, PyObject *args)
{
    int visible;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!i:gtk_icon_file_selection_show_tree", &PyGtk_Type, &obj, &visible))
        return NULL;
    gtk_icon_file_selection_show_tree(GTK_ICON_FILE_SELECTION(PyGtk_Get(obj)), visible);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_icon_file_selection_set_filter(PyObject *self, PyObject *args)
{
    char *pattern;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!s:gtk_icon_file_selection_set_filter", &PyGtk_Type, &obj, &pattern))
        return NULL;
    gtk_icon_file_selection_set_filter(GTK_ICON_FILE_SELECTION(PyGtk_Get(obj)), pattern);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_item_entry_new(PyObject *self, PyObject *args)
{
    GtkObject *ret;

    if (!PyArg_ParseTuple(args, ":gtk_item_entry_new"))
        return NULL;
    ret = (GtkObject *) gtk_item_entry_new();
    if (ret)
        return PyGtk_New(ret);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_item_entry_new_with_max_length(PyObject *self, PyObject *args)
{
    int maxlen;
    GtkObject *ret;

    if (!PyArg_ParseTuple(args, "i:gtk_item_entry_new_with_max_length", &maxlen))
        return NULL;
    ret = (GtkObject *) gtk_item_entry_new_with_max_length(maxlen);
    if (ret)
        return PyGtk_New(ret);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_item_entry_set_text(PyObject *self, PyObject *args)
{
    int justification;
    char *string;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!si:gtk_item_entry_set_text", &PyGtk_Type, &obj, &string, &justification))
        return NULL;
    gtk_item_entry_set_text(GTK_ITEM_ENTRY(PyGtk_Get(obj)), string, justification);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_item_entry_set_justification(PyObject *self, PyObject *args)
{
    int justification;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!i:gtk_item_entry_set_justification", &PyGtk_Type, &obj, &justification))
        return NULL;
    gtk_item_entry_set_justification(GTK_ITEM_ENTRY(PyGtk_Get(obj)), justification);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_font_combo_new(PyObject *self, PyObject *args)
{
    GtkObject *ret;

    if (!PyArg_ParseTuple(args, ":gtk_font_combo_new"))
        return NULL;
    ret = (GtkObject *) gtk_font_combo_new();
    if (ret)
        return PyGtk_New(ret);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_font_combo_select(PyObject *self, PyObject *args)
{
    PyObject *obj;
    char *family;
    int bold, italic, height;

    if (!PyArg_ParseTuple(args, "O!siii:gtk_font_combo_select", &PyGtk_Type, &obj, &family, &bold, &italic, &height))
        return NULL;
    gtk_font_combo_select(GTK_FONT_COMBO(PyGtk_Get(obj)), family, bold, italic, height);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_font_combo_select_nth(PyObject *self, PyObject *args)
{
    int n, bold, italic, height;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!iiii:gtk_font_combo_select_nth", &PyGtk_Type, &obj, &n, &bold, &italic, &height))
        return NULL;
    gtk_font_combo_select_nth(GTK_FONT_COMBO(PyGtk_Get(obj)), n, bold, italic, height);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_combo_box_new(PyObject *self, PyObject *args)
{
    GtkObject *ret;

    if (!PyArg_ParseTuple(args, ":gtk_combo_box_new"))
        return NULL;
    ret = (GtkObject *) gtk_combo_box_new();
    if (ret)
        return PyGtk_New(ret);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_combo_box_hide_popdown_window(PyObject *self, PyObject *args)
{
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_combo_box_hide_popdown_window", &PyGtk_Type, &obj))
        return NULL;
    gtk_combo_box_hide_popdown_window(GTK_COMBO_BOX(PyGtk_Get(obj)));
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_border_combo_new(PyObject *self, PyObject *args)
{
    GtkObject *ret;

    if (!PyArg_ParseTuple(args, ":gtk_border_combo_new"))
        return NULL;
    ret = (GtkObject *) gtk_border_combo_new();
    if (ret)
        return PyGtk_New(ret);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_color_combo_get_color_at(PyObject *self, PyObject *args)
{
    PyObject *obj;
    gchar *ret;
    int row, column;

    if (!PyArg_ParseTuple(args, "O!ii:gtk_color_combo_get_color_at", &PyGtk_Type, &obj, &row, &column))
        return NULL;
    ret = gtk_color_combo_get_color_at(GTK_COLOR_COMBO(PyGtk_Get(obj)), row, column);
    if (ret) {
        return PyString_FromString(ret);
    } else {
        Py_INCREF(Py_None);
        return Py_None;
    }
}

static PyObject *
_wrap_gtk_toggle_combo_new(PyObject *self, PyObject *args)
{
    int rows, columns;
    GtkObject *ret;

    if (!PyArg_ParseTuple(args, "ii:gtk_toggle_combo_new", &rows, &columns))
        return NULL;
    ret = (GtkObject *) gtk_toggle_combo_new(rows, columns);
    if (ret)
        return PyGtk_New(ret);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_toggle_combo_get_nrows(PyObject *self, PyObject *args)
{
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_toggle_combo_get_nrows", &PyGtk_Type, &obj))
        return NULL;
    return PyInt_FromLong(gtk_toggle_combo_get_nrows(GTK_TOGGLE_COMBO(PyGtk_Get(obj))));
}

static PyObject *
_wrap_gtk_toggle_combo_get_ncols(PyObject *self, PyObject *args)
{
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_toggle_combo_get_ncols", &PyGtk_Type, &obj))
        return NULL;
    return PyInt_FromLong(gtk_toggle_combo_get_ncols(GTK_TOGGLE_COMBO(PyGtk_Get(obj))));
}

static PyObject *
_wrap_gtk_toggle_combo_select(PyObject *self, PyObject *args)
{
    int row, column;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!ii:gtk_toggle_combo_select", &PyGtk_Type, &obj, &row, &column))
        return NULL;
    gtk_toggle_combo_select(GTK_TOGGLE_COMBO(PyGtk_Get(obj)), row, column);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_char_selection_new(PyObject *self, PyObject *args)
{
    GtkObject *ret;

    if (!PyArg_ParseTuple(args, ":gtk_char_selection_new"))
        return NULL;
    ret = (GtkObject *) gtk_char_selection_new();
    if (ret)
        return PyGtk_New(ret);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_char_selection_set_selection(PyObject *self, PyObject *args)
{
    int code;
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!i:gtk_char_selection_set_selection", &PyGtk_Type, &obj, &code))
        return NULL;
    gtk_char_selection_set_selection(GTK_CHAR_SELECTION(PyGtk_Get(obj)), code);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_char_selection_get_selection(PyObject *self, PyObject *args)
{
    PyObject *obj;

    if (!PyArg_ParseTuple(args, "O!:gtk_char_selection_get_selection", &PyGtk_Type, &obj))
        return NULL;
    return PyInt_FromLong(gtk_char_selection_get_selection(GTK_CHAR_SELECTION(PyGtk_Get(obj))));
}

static PyObject *
_wrap_gtk_psfont_init(PyObject *self, PyObject *args)
{
    if (!PyArg_ParseTuple(args, ":gtk_psfont_init"))
        return NULL;
    return PyInt_FromLong(gtk_psfont_init());
}

static PyObject *
_wrap_gtk_psfont_unref(PyObject *self, PyObject *args)
{
    if (!PyArg_ParseTuple(args, ":gtk_psfont_unref"))
        return NULL;
    gtk_psfont_unref();
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gtk_psfont_get_psfontname(PyObject *self, PyObject *args)
{
    gchar *ret;
    char *fontname;

    if (!PyArg_ParseTuple(args, "s:gtk_psfont_get_psfontname", &fontname))
        return NULL;
    ret = gtk_psfont_get_psfontname(fontname);
    if (ret) {
        return PyString_FromString(ret);
    } else {
        Py_INCREF(Py_None);
        return Py_None;
    }
}

