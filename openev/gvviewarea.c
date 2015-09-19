/******************************************************************************
 * $Id: gvviewarea.c,v 1.126 2006/11/08 16:27:58 warmerda Exp $
 *
 * Project:  OpenEV
 * Purpose:  GTK/OpenGL View Canvas
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
 * $Log: gvviewarea.c,v $
 * Revision 1.126  2006/11/08 16:27:58  warmerda
 * Improved signature for testing if glReadPixels() failed.  The old
 * signature was too likely (1 in 64K times it would match).
 *
 * Revision 1.125  2005/01/14 15:27:26  warmerda
 * added flip flag access
 *
 * Revision 1.124  2004/08/20 18:01:14  warmerda
 * Ensure that adding a first layer results in the flip_y flag being reset
 * to 1.0 even if some previous raw image had resulted it in being set to
 * -1.0.
 *
 * Revision 1.123  2004/04/28 01:27:08  sduclos
 * GDK_GL_STENCIL_SIZE moved into S52 viewer glcontext
 *
 * Revision 1.122  2004/01/20 16:11:09  warmerda
 * Default GDK_GL_STENCIL_SIZE to 1 for S52 viewer
 *
 * Revision 1.121  2003/08/27 19:58:43  warmerda
 * added force_simple flag for gv_view_area_bmfont_draw
 *
 * Revision 1.120  2003/05/08 19:51:13  pgs
 * modified adjustment logic forpage size
 *
 * Revision 1.119  2003/03/07 22:18:26  warmerda
 * const correctness fix for get_layer_by_name
 *
 * Revision 1.118  2003/02/20 19:27:18  gmwalter
 * Updated link tool to include Diana's ghost cursor code, and added functions
 * to allow the cursor and link mechanism to use different gcps
 * than the display for georeferencing.  Updated raster properties
 * dialog for multi-band case.  Added some signals to layerdlg.py and
 * oeattedit.py to make it easier for tools to interact with them.
 * A few random bug fixes.
 *
 * Revision 1.117  2002/12/12 03:42:14  warmerda
 * verified Gillians change, and cleaned old cruft
 *
 * Revision 1.116  2002/12/12 01:04:26  gmwalter
 * Fix to deal with upside-down symbol bug, symbol migration in non-georeferenced mode.
 *
 * Revision 1.115  2002/11/04 21:42:07  sduclos
 * change geometric data type name to gvgeocoord
 *
 * Revision 1.114  2002/09/29 18:40:28  warmerda
 * ensure new_x and new_y in gv_view_area_get_volume are float not int
 * as per bug report from Sylvain Duclos.
 *
 * Revision 1.113  2002/09/16 17:20:02  warmerda
 * ensure depth buffer cleared in 3d render_to_func
 *
 * Revision 1.112  2002/09/12 20:26:51  warmerda
 * changed near clipping plane calc to improve depth resolution
 *
 * Revision 1.111  2002/09/11 18:58:33  warmerda
 * dmsg bug 475: disable depth testing in 2D mode
 *
 * Revision 1.110  2002/09/10 13:26:43  warmerda
 * added get_height_scale method
 *
 * Revision 1.109  2002/07/19 14:06:38  warmerda
 * Fixed bug reported by Gillian with switching between raw and georeferenced
 * mode for images with GCPs that effectively do x or y flips of the image
 * (such as some esrin ceos scenes).   Changes all in gv_view_area_set_raw().
 *
 * Revision 1.108  2002/07/16 14:17:05  warmerda
 * added support for getting background color
 *
 * Revision 1.107  2002/07/08 19:44:39  warmerda
 * added properties on GvViewArea
 *
 * Revision 1.106  2002/05/02 19:16:26  gmwalter
 * Updated key press function to allow smaller height and zoom increments in 3d
 * (original step sizes now require that shift be pressed as well).
 *
 * Revision 1.105  2002/03/20 19:19:14  warmerda
 * added exact_render flag
 *
 * Revision 1.104  2002/01/30 17:25:19  warmerda
 * added set_state and get_primary_raster functions
 *
 * Revision 1.103  2001/12/13 03:29:17  warmerda
 * avoid purging textures used in this render
 *
 * Revision 1.102  2001/12/12 15:32:39  warmerda
 * ensure volume is computed for fit_all_layers
 *
 * Revision 1.101  2001/10/23 02:29:07  warmerda
 * call gv_view_area_state_changed() in _add_layer()
 *
 * Revision 1.100  2001/10/19 13:26:47  warmerda
 * fixed up checkf or mesa windows
 *
 * Revision 1.99  2001/10/12 17:44:18  warmerda
 * avoid extra redraws when many raster layers displayed
 *
 * Revision 1.98  2001/10/12 02:11:45  warmerda
 * Always render on non-win32, swapbuffer doesnt do what we want on X/OpenGL
 *
 * Revision 1.97  2001/10/12 01:58:19  warmerda
 * avoid re-rendering if backing store OK
 *
 * Revision 1.96  2001/07/18 03:34:44  warmerda
 * fixed flipping problem
 *
 * Revision 1.95  2001/07/09 20:21:28  warmerda
 * fixed raw mesh info
 *
 * Revision 1.94  2001/07/03 14:26:05  warmerda
 * added set/get raw ability
 *
 * Revision 1.93  2001/06/15 00:01:53  warmerda
 * added GDK_GLX_RED/GREEN/BLUE_SIZE attribs for visual
 *
 * Revision 1.92  2001/05/07 19:14:02  warmerda
 * removed a bunch of debugging cruft
 *
 * Revision 1.91  2001/05/07 19:08:03  warmerda
 * draw text with origin off viewport properly
 *
 * Revision 1.90  2001/04/26 18:36:40  warmerda
 * added glFinish() before swapbuffers
 *
 * Revision 1.89  2001/04/09 18:20:14  warmerda
 * added ability to query list of available fonts
 *
 * Revision 1.88  2001/03/28 15:03:02  warmerda
 * Added direct_render flag within gv_view_area_render_to_func().  This flag
 * kicks in for 1:1 prints, and prevents any attempt to reapply the view
 * transformation since the naive code loses rotations, and 3D perspectives.
 * This relates to CIETMap bug 89, and OpenEV bug 212486.
 *
 * Revision 1.87  2001/03/27 18:38:05  warmerda
 * fixed return value
 *
 * Revision 1.86  2001/03/26 19:18:35  warmerda
 * restructure bmfont handling to preserve GdkFont handle
 *
 * Revision 1.85  2001/03/22 22:34:24  warmerda
 * fixed bug in gv_view_load_bmfont() with reporting load errors
 *
 * Revision 1.84  2001/02/15 16:35:32  warmerda
 * turned g_warning into CPLDebug call
 *
 * Revision 1.83  2001/02/03 22:21:08  warmerda
 * added gv_view_area_get_mode() and python covers
 *
 * Revision 1.82  2001/01/30 19:33:58  warmerda
 * removed printf
 *
 * Revision 1.81  2001/01/26 13:56:15  warmerda
 * ensure fit_all_layers(), Home, and fit_extents all produce compatible results.
 * Route all view setting through gv_viewarea_set_3d_view().
 * Fix up default view.
 * Remove view setting in get_volume() function.
 *
 * Revision 1.80  2001/01/19 15:19:49  warmerda
 * improve near range calculation when over scene
 *
 * Revision 1.79  2000/10/06 16:48:56  warmerda
 * added GvViewArea background color
 *
 * Revision 1.78  2000/09/29 16:09:17  srawlin
 * added Goto function requring fuction to map lat/long to view coordinates
 *
 * Revision 1.77  2000/09/21 02:57:20  warmerda
 * reorganized bitmap font support to allow any gdk supported font at runtime
 *
 * Revision 1.76  2000/09/13 15:58:55  srawlin
 * added python bindings for gv_view_area_get_zoom
 *
 * Revision 1.75  2000/09/07 21:02:26  warmerda
 * ensure projection string is cleared when last layer removed
 *
 * Revision 1.74  2000/08/25 19:58:00  warmerda
 * Fixed problems with setting slider adjustments out of bounds. This sometimes
 * caused a feedback loop as the slider itself tried to keep things legal.
 *
 * Revision 1.73  2000/08/24 17:05:01  srawlin
 * fixed 3D eye_pos passed to vec_near_far_range() (near/far clipping plane
 * calculation) to account for image flipping
 *
 * Revision 1.72  2000/08/24 15:44:30  srawlin
 * fixed flip about y axis in 3D mode
 *
 * Revision 1.71  2000/08/24 02:22:46  warmerda
 * fixed scrollbar step and page increments
 *
 * Revision 1.70  2000/08/23 15:45:45  warmerda
 * updated adjustments after user scrolls
 *
 * Revision 1.69  2000/08/17 16:50:51  warmerda
 * fixed leak of lock_adjustment flag
 *
 * Revision 1.68  2000/08/17 16:45:00  warmerda
 * get_world_extents works without layers now
 *
 * Revision 1.67  2000/08/16 22:14:36  warmerda
 * fixed scrolling for raw and projected views
 *
 * Revision 1.66  2000/08/16 14:07:47  warmerda
 * added prototype scrollbar support
 *
 * Revision 1.65  2000/08/02 17:47:01  warmerda
 * don't allow further processing of arrows or we will lose focus
 *
 * Revision 1.64  2000/07/25 17:51:48  warmerda
 * added finalize, and debug statements
 *
 * Revision 1.63  2000/07/24 14:26:30  warmerda
 * use up to char 126 in gdk_gl_use_gdk_font
 *
 * Revision 1.62  2000/07/21 01:31:11  warmerda
 * added read_only flag for GvData, and utilize for vector layers
 *
 * Revision 1.61  2000/07/17 19:10:00  warmerda
 * added tentative support for scaling wait between redraws to actual redraw time
 *
 * Revision 1.60  2000/07/13 18:04:33  srawlin
 * removed use of view.state.eye_az and .eye_el, contained same information as view.state.eye_dir
 *
 * Revision 1.59  2000/07/11 20:56:23  srawlin
 * added methods to get and set viewing direction relative to z-plane in 3D
 *
 * Revision 1.58  2000/07/10 22:13:39  srawlin
 * Added motion scaling based on distance to z-plane
 *
 * Revision 1.57  2000/07/10 20:45:00  srawlin
 * Added 3D Translate controls
 *
 * Revision 1.56  2000/07/10 16:20:33  srawlin
 * fixed bug when zooming in 3D and panning, also removed debug printfs
 *
 * Revision 1.55  2000/07/10 13:36:55  srawlin
 * updated 3D controls to be more like 2D
 *
 * Revision 1.54  2000/07/07 17:53:32  warmerda
 * ifdef out debug statement
 *
 * Revision 1.53  2000/07/05 11:26:26  srawlin
 * 3D - changed initial view, some mouse movement directions, set angle boundaries
 *
 * Revision 1.52  2000/07/04 15:47:18  warmerda
 * removed debug lines in 3d mode
 *
 * Revision 1.51  2000/07/03 20:58:31  warmerda
 * eye_pos in georef coordinates now
 *
 * Revision 1.50  2000/06/29 16:14:58  warmerda
 * added one more set_busy call
 *
 * Revision 1.49  2000/06/29 14:38:37  warmerda
 * use GvManager for idle tasks
 *
 * Revision 1.48  2000/06/23 12:56:52  warmerda
 * added multiple GvRasterSource support
 *
 * Revision 1.47  2000/06/20 13:26:55  warmerda
 * added standard headers
 *
 */

#include "gvviewarea.h"
#include "gvlayer.h"
#include "gvrasterlayer.h"
#include "gvundo.h"
#include "gvmanager.h"
#include "gvutils.h"
#include <gtk/gtksignal.h>
#include <gtkgl/gdkgl.h>
#include <gdk/gdkkeysyms.h>
#include "gextra.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include <math.h>

#define DEG2RAD         0.01745329252
#define LOG2(x)         (log(x) / 0.69314718056)
#define DEAD_ZONE       8.0
#define DRAG_THRESHOLD  10
#define WHEEL_ZOOM_INC  0.1

/* 3D motion Stuff */
#define MOVE_SPEED      0.04
#define AZ_SCALE        0.15
#define EL_SCALE        0.15
#define HEIGHT_SCALE    0.1
#define CONTIN_3DMOVE_INC 20.0

/* 2D Zooming */
#define CONTIN_ZOOM_INC 1.5
#define ZOOM_STEP       1

/* useful 3D vector copy function */
#define vec_copy(s,d) {d[0]=s[0];d[1]=s[1];d[2]=s[2];}
#define vec_add(a,b,c) {c[0]=a[0]+b[0];c[1]=a[1]+b[1];c[2]=a[2]+b[2];}
#define vec_scale(a,b,c) {c[0]=b*a[0];c[1]=b*a[1];c[2]=b*a[2];}

#define VIEW_EVENT_MASK (GDK_BUTTON_PRESS_MASK | GDK_BUTTON_RELEASE_MASK | \
             GDK_POINTER_MOTION_MASK | \
             GDK_POINTER_MOTION_HINT_MASK | \
             GDK_KEY_PRESS_MASK | GDK_ENTER_NOTIFY_MASK | \
             GDK_LEAVE_NOTIFY_MASK)

enum
{
    GLDRAW,
    GLCURSOR,
    ACTIVE_CHANGED,
    VIEW_STATE_CHANGED,
    LAST_SIGNAL
};

enum {
  ARG_0,
  ARG_HADJUSTMENT,
  ARG_VADJUSTMENT,
};

static void gv_view_area_class_init(GvViewAreaClass *klass);
static void gv_view_area_init(GvViewArea *view);

static void gv_view_area_update_adjustments( GvViewArea *view );
static gint gv_view_area_configure(GtkWidget *view, GdkEventConfigure *event);
static gint gv_view_area_reset_projection(GvViewArea *view, gvgeocoord width, gvgeocoord height);
static void gv_view_area_realize(GtkWidget *view);
static void gv_view_area_unrealize(GtkWidget *view);
static void gv_view_area_motion_handle_hint(GtkWidget *view, GdkEventMotion *event);
static gint gv_view_area_motion_notify(GtkWidget *view, GdkEventMotion *event);
static gint gv_view_area_button_press(GtkWidget *view, GdkEventButton *event);
static gint gv_view_area_button_release(GtkWidget*view, GdkEventButton *event);
static gint gv_view_area_key_press(GtkWidget *view, GdkEventKey *event);
static void gv_view_area_change_notify(GvViewArea *view, gpointer info);
static void gv_view_area_state_changed(GvViewArea *view);
static void gv_view_area_fit_layer(GvViewArea *view, GvLayer *layer);
static void gv_view_area_destroy(GtkObject *object);
static void gv_view_area_fit_extents_3D(GvViewArea *view,
                                     gvgeocoord llx, gvgeocoord lly, gvgeocoord minz,
                                     gvgeocoord width, gvgeocoord height, gvgeocoord deltaz );
static gint gv_view_area_zoompan_handler(gpointer data );
static void gv_view_area_finalize( GtkObject *object );

static guint view_area_signals[LAST_SIGNAL] = { 0 };

static void  gv_view_area_set_arg        (GtkObject      *object,
                                          GtkArg         *arg,
                                          guint           arg_id);
static void  gv_view_area_get_arg        (GtkObject      *object,
                                          GtkArg         *arg,
                                          guint           arg_id);

static struct { char *gvname, *gdkname; } bmfontmap[] =
{
    { "Fixed", "-*-fixed-*-*-*-*-*-*-*-*-*-*-iso8859-*" },
    { "Times, 20pt", "-*-times-*-*-*-*-20-*-*-*-*-*-iso8859-*" },
    { "Times, 14pt", "-*-times-*-*-*-*-14-*-*-*-*-*-iso8859-*" },
    { NULL, NULL }  /* Sentinel */
};

/* Incremented each render */
static int render_counter = 0;

void
vec_point(vec3_t point, gvgeocoord az, gvgeocoord el)
{
    gvgeocoord c = cos(el * DEG2RAD);

    point[0] = c * cos(az * DEG2RAD);
    point[1] = c * sin(az * DEG2RAD);
    point[2] = sin(el * DEG2RAD);
}

/* Inverse of vec_point, given direction vector find az and el, az in [-180, 180] */
int
inv_vec_point(vec3_t point, gvgeocoord *az, gvgeocoord *el)
{
    gvgeocoord c, az1, az2;

    *el = asin(point[2]) / DEG2RAD;
    c = cos( *el * DEG2RAD);
    if ((c < 0.000001) &&  (c > -0.000001))
        c = 0.00001;
    az1 = (asin(point[1]/c)) / DEG2RAD;
    az2 = (acos(point[0]/c)) / DEG2RAD;

    if ((point[0] >= 0.0) && (point[1] >= 0.0))
        *az = az1;
    else if ((point[0] >= 0.0) && (point[1] <= 0.0))
        *az = az1;
    else if ((point[0] <= 0.0) && (point[1] >= 0.0))
        *az = az2;
    else if ((point[0] <= 0.0) && (point[1] <= 0.0))
        *az = -az2;
    else
    {
        printf("ERROR!  in gvviewarea.c, inv_vec_point.  Should never reach here.\n");
        /* printf("point[0] %f, point[1] %f, c %f, az1 %f, az2 %f\n", point[0], point[1], c, az1, az2); */
        return 0;
    }

    return 1;

}


static void
vec_near_far_range( vec3_t point, double *volume, double *min, double *max )

{
    vec3_t   nearest, furthest;

    /* Find nearest X in volume */
    if( point[0] < volume[0] )
        nearest[0] = volume[0];
    else if( point[0] > volume[1] )
        nearest[0] = volume[1];
    else
        nearest[0] = point[0];

    /* Find nearest Y in volume */
    if( point[1] < volume[2] )
        nearest[1] = volume[2];
    else if( point[1] > volume[3] )
        nearest[1] = volume[3];
    else
        nearest[1] = point[1];

    /* Find nearest Z in volume */
    if( point[2] < volume[4] )
        nearest[1] = volume[4];
    else if( point[2] > volume[5] )
        nearest[2] = volume[5];
    else
        nearest[2] = point[2];

    /* Find furthest X in volume */
    if( ABS(point[0] - volume[0]) > ABS(point[0] - volume[1]) )
        furthest[0] = volume[0];
    else
        furthest[0] = volume[1];

    /* Find furthest Y in volume */
    if( ABS(point[1] - volume[2]) > ABS(point[1] - volume[3]) )
        furthest[1] = volume[2];
    else
        furthest[1] = volume[3];

    /* Find furthest Z in volume */
    if( ABS(point[2] - volume[4]) > ABS(point[2] - volume[5]) )
        furthest[2] = volume[4];
    else
        furthest[2] = volume[5];

    /* find distances */

    *min = sqrt( (nearest[0] - point[0]) * (nearest[0] - point[0])
                 + (nearest[1] - point[1]) * (nearest[1] - point[1])
                 + (nearest[2] - point[2]) * (nearest[2] - point[2]) );

    *max = sqrt( (furthest[0] - point[0]) * (furthest[0] - point[0])
                 + (furthest[1] - point[1]) * (furthest[1] - point[1])
                 + (furthest[2] - point[2]) * (furthest[2] - point[2]) );

}

GtkType
gv_view_area_get_type(void)
{
    static GtkType view_area_type = 0;

    if (!view_area_type)
    {
    static const GtkTypeInfo view_area_info =
    {
        "GvViewArea",
        sizeof(GvViewArea),
        sizeof(GvViewAreaClass),
        (GtkClassInitFunc) gv_view_area_class_init,
        (GtkObjectInitFunc) gv_view_area_init,
        /* reserved_1 */ NULL,
        /* reserved_2 */ NULL,
        (GtkClassInitFunc) NULL,
    };

    view_area_type = gtk_type_unique( gtk_gl_area_get_type(),
                      &view_area_info );
    }
    return view_area_type;
}

static void
gv_view_area_class_init(GvViewAreaClass *klass)
{
    GtkObjectClass *object_class;
    GtkWidgetClass *widget_class;

    object_class = GTK_OBJECT_CLASS(klass);
    widget_class = GTK_WIDGET_CLASS(klass);

    view_area_signals[GLDRAW] =
    gtk_signal_new ("gldraw",
            GTK_RUN_FIRST,
            object_class->type,
            GTK_SIGNAL_OFFSET (GvViewAreaClass, gldraw),
            gtk_marshal_NONE__NONE,
            GTK_TYPE_NONE, 0);

    view_area_signals[GLCURSOR] =
    gtk_signal_new ("glcursor",
            GTK_RUN_FIRST,
            object_class->type,
            GTK_SIGNAL_OFFSET (GvViewAreaClass, glcursor),
            gtk_marshal_NONE__NONE,
            GTK_TYPE_NONE, 0);

    view_area_signals[ACTIVE_CHANGED] =
    gtk_signal_new ("active-changed",
            GTK_RUN_FIRST,
            object_class->type,
            GTK_SIGNAL_OFFSET (GvViewAreaClass, active_changed),
            gtk_marshal_NONE__NONE,
            GTK_TYPE_NONE, 0);

    view_area_signals[VIEW_STATE_CHANGED] =
    gtk_signal_new ("view-state-changed",
            GTK_RUN_FIRST,
            object_class->type,
            GTK_SIGNAL_OFFSET (GvViewAreaClass,
                       view_state_changed),
            gtk_marshal_NONE__NONE,
            GTK_TYPE_NONE, 0);

    gtk_object_class_add_signals(object_class, view_area_signals, LAST_SIGNAL);

    object_class->destroy = gv_view_area_destroy;
    object_class->finalize = gv_view_area_finalize;
    object_class->set_arg = gv_view_area_set_arg;
    object_class->get_arg = gv_view_area_get_arg;

    widget_class->realize = gv_view_area_realize;
    widget_class->unrealize = gv_view_area_unrealize;
    widget_class->configure_event = gv_view_area_configure;
    widget_class->expose_event = gv_view_area_expose;
    widget_class->button_press_event = gv_view_area_button_press;
    widget_class->button_release_event = gv_view_area_button_release;
    widget_class->motion_notify_event = gv_view_area_motion_notify;
    widget_class->key_press_event = gv_view_area_key_press;

    widget_class->set_scroll_adjustments_signal =
        gtk_signal_new ("set_scroll_adjustments",
                        GTK_RUN_LAST,
                        object_class->type,
                        GTK_SIGNAL_OFFSET (GvViewAreaClass,
                                           set_scroll_adjustments),
                        gtk_marshal_NONE__POINTER_POINTER,
                        GTK_TYPE_NONE, 2, GTK_TYPE_ADJUSTMENT, GTK_TYPE_ADJUSTMENT);

    klass->set_scroll_adjustments = gv_view_area_set_adjustments;
    klass->gldraw = NULL;
    klass->active_changed = NULL;
    klass->view_state_changed = NULL;
}

static void
gv_view_area_init(GvViewArea *view)
{
    view->state.tx = view->state.ty = view->state.rot = 0.0;
    view->state.zoom = 0.0;
    view->state.linear_zoom = 1.0;
    view->state.flip_x = view->state.flip_y = 1.0;
    view->state.shape_x = view->state.shape_y = 0.0;
    view->volume_current = FALSE;
    view->linear_measure = 1000.0;

    /* 3D Specific stuff */
    view->state.eye_pos[0] = 0.0;
    view->state.eye_pos[1] = 0.0;
    view->state.eye_pos[2] = 500.0;
    vec_point(view->state.eye_dir, 90.0, -45.0);  /* rotation = 90,  tilt  45 deg down */
    view->state.z_scale = 1.0;

    view->exact_render = FALSE;

    view->flag_3d = 0;    /* 0=2D, 1=3D, default 2D */

    view->bmfonts = g_array_new(FALSE,TRUE,sizeof(GvBMFontInfo));

    view->background[0] = view->background[1] = view->background[2] = 0.0;
    view->background[3] = 1.0;

    view->layers = NULL;
    view->projection = NULL;

    view->last_button = 0;
    view->dragging_mode = FALSE;
    view->display_dirty = TRUE;

    /* ghost cursor stuff */
    view->next_valid = FALSE;
    view->last_valid = FALSE;
    view->next_x = 0.0;
    view->next_y = 0.0;
    view->last_x = 0.0;
    view->last_y = 0.0;
    /* end of ghost cursor stuff */

    view->last_draw_time = 0.0;
    view->redraw_timer = NULL;

    view->vadj = NULL;
    view->hadj = NULL;
    view->lock_adjustments = FALSE;

    view->properties = NULL;

    GTK_WIDGET_SET_FLAGS(GTK_WIDGET(view), GTK_CAN_FOCUS);

    gtk_widget_set_events(GTK_WIDGET(view),
              gtk_widget_get_events(GTK_WIDGET(view)) |
              VIEW_EVENT_MASK);

    /* Need to handle motion hints BEFORE other handlers */
    gtk_signal_connect(GTK_OBJECT(view), "motion-notify-event",
               GTK_SIGNAL_FUNC(gv_view_area_motion_handle_hint), NULL);
}

GtkWidget *
gv_view_area_new(void)
{
    GdkGLContext *glcontext;
    GvViewArea *view;
    int attrlist[] = {
        GDK_GL_RGBA, 
        GDK_GL_DOUBLEBUFFER, 
        GDK_GL_DEPTH_SIZE, 	4, 
        GDK_GL_RED_SIZE, 	3, 
        GDK_GL_GREEN_SIZE, 	3, 
        GDK_GL_BLUE_SIZE, 	3, 
        GDK_GL_NONE};

#ifdef WIN32
    /* figure out how to actually share context later */
    glcontext = gdk_gl_context_attrlist_share_new(attrlist, NULL, TRUE);
    if (glcontext == NULL)
        return NULL;

    view = gtk_type_new(gv_view_area_get_type());
    GTK_GL_AREA(view)->glcontext = glcontext;

    return GTK_WIDGET(view);
#else
    /* Largely copied from gtkglarea.c - should be in the constructor(?) */
    GdkVisual *visual;

    // SD check that geometric data type are in sync with OpenGL
    g_assert(sizeof(gvgeocoord) == sizeof(GLgeocoord));

    visual = gdk_gl_choose_visual(attrlist);
    if (visual == NULL) return NULL;

    glcontext = gdk_gl_context_share_new(visual, NULL , TRUE);
    if (glcontext == NULL) return NULL;

    /* use colormap and visual suitable for OpenGL rendering */
    gtk_widget_push_colormap(gdk_colormap_new(visual, TRUE));
    gtk_widget_push_visual(visual);

    view = gtk_type_new(gv_view_area_get_type());
    GTK_GL_AREA(view)->glcontext = glcontext;

    /* pop back defaults */
    gtk_widget_pop_visual();
    gtk_widget_pop_colormap();

    return GTK_WIDGET(view);
#endif
}

gint
gv_view_area_set_projection( GvViewArea *view, const char *projection )

{
    if( view->projection != NULL )
        g_free( view->projection );

    view->projection = g_strdup( projection );

    return TRUE;
}

const char *
gv_view_area_get_projection( GvViewArea *view )

{
    return view->projection;
}


/* Set mode to 2D or 3D */
void
gv_view_area_set_mode(GvViewArea *view, int flag_3d)
{
    view->flag_3d= flag_3d;    /* 0=2D, 1=3D,  */

    /* Reset OpenGL Projection Method */
    if( GTK_WIDGET_REALIZED(GTK_WIDGET(view)) )
        gv_view_area_reset_projection(view,
                                      view->state.shape_x,
                                      view->state.shape_y);

    gv_view_area_state_changed(view);
}

int gv_view_area_get_mode(GvViewArea *view)

{
    return view->flag_3d;
}

/* Change 3D Scaling factor - has no effect unless in 3D mode */
void
gv_view_area_height_scale(GvViewArea *view, gvgeocoord scale)
{
    view->state.z_scale = scale;
    gv_view_area_state_changed(view);
}

gvgeocoord
gv_view_area_get_height_scale( GvViewArea *view )

{
    return view->state.z_scale;
}


/* Change 3D view position and direction */
void gv_view_area_set_3d_view( GvViewArea *view,
                               vec3_t eye_pos, vec3_t eye_dir )

{
    int    changed = FALSE;

    if( eye_pos != NULL
        && (eye_pos[0] != view->state.eye_pos[0]
            || eye_pos[1] != view->state.eye_pos[1]
            || eye_pos[2] != view->state.eye_pos[2]) )
    {
        vec_copy( eye_pos, view->state.eye_pos );
        changed = TRUE;
    }

    if( eye_dir != NULL
        && (eye_dir[0] != view->state.eye_dir[0]
            || eye_dir[1] != view->state.eye_dir[1]
            || eye_dir[2] != view->state.eye_dir[2]) )
    {
        gvgeocoord mag = sqrt(eye_dir[0] * eye_dir[0]
                         + eye_dir[1] * eye_dir[1]
                         + eye_dir[2] * eye_dir[2] );

        if( mag != 0.0 )
        {
            vec_scale( eye_dir, 1.0 / mag, view->state.eye_dir );
            changed = TRUE;
        }
    }

    if( changed )
        gv_view_area_state_changed(view);
}

/* Change 3D view position and direction to given location on z-plane */
void gv_view_area_set_3d_view_look_at( GvViewArea *view,
                                       vec3_t eye_pos, gvgeocoord *eye_look_at )
{
    if( eye_look_at != NULL )
    {
        vec3_t eye_dir;
        gvgeocoord mag;

        eye_dir[0] = eye_look_at[0] - eye_pos[0];
        eye_dir[1] = eye_look_at[1] - eye_pos[1];
        eye_dir[2] = -eye_pos[2];

        mag = sqrt(eye_dir[0] * eye_dir[0]
                         + eye_dir[1] * eye_dir[1]
                         + eye_dir[2] * eye_dir[2] );

        if( mag != 0.0 )
        {
            vec_scale( eye_dir, 1.0 / mag, view->state.eye_dir );
            gv_view_area_set_3d_view( view, eye_pos, eye_dir );
        }
    }
    else
    {
        gv_view_area_set_3d_view( view, eye_pos, view->state.eye_dir );
    }
}


/* Get point in z-plane that looking at, false if not meaningful */
gint
gv_view_area_get_look_at_pos( GvViewArea *view,
                              gvgeocoord *x, gvgeocoord *y)
{
    /* Check if looking up above z-plane */
    if (view->state.eye_dir[2] >= 0.0)
    {
        return FALSE;
    } else {

        *x = view->state.eye_pos[0] - view->state.eye_dir[0]
            * (view->state.eye_pos[2]/ view->state.eye_dir[2]);

        *y = view->state.eye_pos[1] - view->state.eye_dir[1]
            * (view->state.eye_pos[2]/ view->state.eye_dir[2]);
    }

    return TRUE;
}

void
gv_view_area_queue_draw(GvViewArea *view)
{
    gv_manager_set_busy( gv_get_manager(), TRUE );

    view->display_dirty = TRUE;

    gtk_widget_queue_draw(GTK_WIDGET(view));
}
void
gv_view_area_queue_cursor_draw(GvViewArea *view, int next_valid, gvgeocoord x, gvgeocoord y)
{
    gv_manager_set_busy( gv_get_manager(), TRUE );
    view->next_valid = next_valid;
    view->next_x = x;
    view->next_y = y;
    gtk_widget_queue_draw(GTK_WIDGET(view));
}

void
gv_view_area_zoom(GvViewArea *view, gvgeocoord zoom)
{
    view->state.zoom += zoom;
    view->state.linear_zoom = pow(2.0, view->state.zoom);

    gv_view_area_state_changed(view);
}

gvgeocoord
gv_view_area_get_zoom(GvViewArea *view)
{
    return view->state.zoom;
}

void
gv_view_area_rotate(GvViewArea *view, gvgeocoord angle)
{
    view->state.rot += angle;
    gv_view_area_state_changed(view);
}

void
gv_view_area_translate(GvViewArea *view, gvgeocoord dx, gvgeocoord dy)
{
    gvgeocoord cr, sr;

    dx /= view->state.linear_zoom;
    dy /= view->state.linear_zoom;
    cr = cos(-view->state.rot * DEG2RAD);
    sr = sin(-view->state.rot * DEG2RAD);
    view->state.tx += (dx * cr - dy * sr) * view->state.flip_x;
    view->state.ty += (dx * sr + dy * cr) * view->state.flip_y;

    gv_view_area_state_changed(view);
}

void
gv_view_area_set_translation(GvViewArea *view, gvgeocoord x, gvgeocoord y)
{
    view->state.tx = x;
    view->state.ty = y;

    gv_view_area_state_changed(view);
}

int
gv_view_area_get_flip_x( GvViewArea *view )
{
    return view->state.flip_x;
}

int
gv_view_area_get_flip_y( GvViewArea *view )
{
    return view->state.flip_y;
}

void gv_view_area_set_flip_xy( GvViewArea *view, int flip_x, int flip_y )
{
    if( flip_x == view->state.flip_x && flip_y == view->state.flip_y )
        return;

    view->state.flip_x = flip_x;
    view->state.flip_y = flip_y;

    gv_view_area_state_changed(view);
}

void
gv_view_area_copy_state(GvViewArea *view, GvViewArea *copy)
{
    gv_view_area_set_state( view, &(copy->state) );
}

void
gv_view_area_set_state(GvViewArea *view, GvViewAreaState *state)
{
    /* consider preserving mouse position, and re-deriving zoom or log_zoom */

    view->state = *state;

    gv_view_area_state_changed(view);
}

void
gv_view_area_map_location(GvViewArea *view, gvgeocoord x, gvgeocoord y,
             gvgeocoord *geo_x, gvgeocoord *geo_y)
{
    const char *coord_sys = gv_view_area_get_projection(view);
    char    *latlong_srs = NULL;

    *geo_x = x;
    *geo_y = y;

    /* Don't need to do anything in the case of a view with
       raw PIXEL projection */
    if (coord_sys != NULL && !EQUAL(coord_sys,"PIXEL"))
    {
        latlong_srs = gv_make_latlong_srs( coord_sys );

        if( latlong_srs != NULL )
        {
            double      temp_x, temp_y, temp_z;

            temp_x = x;
            temp_y = y;
            temp_z = 0.0;

            if( gv_reproject_points( latlong_srs, coord_sys,
                                     1, &temp_x, &temp_y, &temp_z ) )
            {
                *geo_x = temp_x;
                *geo_y = temp_y;

                /* printf(" (x,y)=(%f,%f), (geo_x, geo_y)=(%f,%f)\n", x,y,temp_x,temp_y); */
            }
        }
    }

    /* geo_x, geo_y contains the original x,y pair or the reprojected values
       if view is lat/long */
}

void
gv_view_area_map_pointer(GvViewArea *view, gvgeocoord px, gvgeocoord py,
                                           gvgeocoord *x, gvgeocoord *y)
{
    gvgeocoord fx, fy, cr, sr;

    cr = cos(-view->state.rot * DEG2RAD);
    sr = sin(-view->state.rot * DEG2RAD);
    fx = px - view->state.shape_x / 2.0;
    fy = view->state.shape_y / 2.0 - py;
    fx /= view->state.linear_zoom;
    fy /= view->state.linear_zoom;
    *x = (fx * cr - fy * sr) * view->state.flip_x - view->state.tx;
    *y = (fx * sr + fy * cr) * view->state.flip_y - view->state.ty;
}

void

gv_view_area_inverse_map_pointer(GvViewArea *view, gvgeocoord x,   gvgeocoord y,
                                                   gvgeocoord *px, gvgeocoord *py)
{
    gvgeocoord fx, fy, cr, sr;

    cr = cos(view->state.rot * DEG2RAD);
    sr = sin(view->state.rot * DEG2RAD);

    x += view->state.tx;
    y += view->state.ty;

    fx = (x * cr * view->state.flip_x - y * sr * view->state.flip_y)
        * view->state.linear_zoom;
    fy = (x * sr * view->state.flip_x + y * cr * view->state.flip_y)
        * view->state.linear_zoom;

    *px = fx + view->state.shape_x / 2.0;
    *py = view->state.shape_y / 2.0 - fy;
}

void
gv_view_area_correct_for_transform(GvViewArea *view, gvgeocoord x, gvgeocoord y,
                   gvgeocoord *cx, gvgeocoord *cy)
{
    /* Correct a vector for rotation and zoom: used for sprites */
    gvgeocoord cr, sr;

    cr = cos(-view->state.rot * DEG2RAD);
    sr = sin(-view->state.rot * DEG2RAD);

    *cx = (x * cr - y * sr) * view->state.flip_x / view->state.linear_zoom;
    *cy = (x * sr + y * cr) * view->state.flip_y / view->state.linear_zoom;
}

void
gv_view_area_add_layer(GvViewArea *view, GtkObject *layer_obj)
{
    GvLayer *layer;

    g_return_if_fail(GV_IS_LAYER(layer_obj));
    layer = GV_LAYER(layer_obj);

    if (GTK_WIDGET_REALIZED(GTK_WIDGET(view)))
    {
        /* Call the one time setup function for the layer */
        /* If the view area is not yet realized, this is deferred to
           gv_view_area_realize() */
        if (gtk_gl_area_make_current(GTK_GL_AREA(view)))
        {
            gv_layer_setup(layer, view);
        }

        /* If this is the first layer, set initial view area
           transformation based on layer extents.  Also ensure
           we are reset back to unflipped even if we previously got
          flipped for a raw image. */
        if (view->layers == NULL)
        {
            view->state.flip_y = 1.0;
            gv_view_area_fit_layer(view, layer);
        }
    }

    /* Maintain reference to layer */
    gtk_object_ref(GTK_OBJECT(layer));
    gtk_object_sink(GTK_OBJECT(layer));

    g_assert( layer->view == NULL );

    view->volume_current = FALSE;
    view->layers = g_list_append(view->layers, layer);

    layer->view = view;

    gtk_signal_connect_object(GTK_OBJECT(layer), "changed",
                              GTK_SIGNAL_FUNC(gv_view_area_change_notify),
                              GTK_OBJECT(view));
    gtk_signal_connect_object(GTK_OBJECT(layer), "display-change",
                              GTK_SIGNAL_FUNC(gv_view_area_change_notify),
                              GTK_OBJECT(view));

    gtk_signal_emit(GTK_OBJECT(view), view_area_signals[ACTIVE_CHANGED]);

    gv_view_area_state_changed(view);
}

void
gv_view_area_remove_layer(GvViewArea *view, GtkObject *layer_obj)
{
    GvLayer *layer;
    GList *link;

    g_return_if_fail(GV_IS_LAYER(layer_obj));
    layer = GV_LAYER(layer_obj);

    if (GTK_WIDGET_REALIZED(GTK_WIDGET(view)))
    {
    /* Allow layer to destroy gl handles if necessary */
    if (gtk_gl_area_make_current(GTK_GL_AREA(view)))
    {
        gv_layer_teardown(layer, view);
    }
    }

    if (layer_obj == view->active_layer)
    {
    gv_view_area_set_active_layer(view, NULL);
    }

    g_assert( layer->view == view );
    layer->view = NULL;

    link = g_list_find(view->layers, layer);
    if (link == NULL)
    {
    CPLDebug( "OpenEV",
                  "gv_view_area_remove_link(): layer %s is not in view",
          gtk_type_name(GTK_OBJECT_TYPE(layer)));
    return;
    }

    view->layers = g_list_remove_link(view->layers, link);
    view->volume_current = FALSE;



    /* clear projection if no layers are left. */
    if( view->layers == NULL )
    {
        if( view->projection != NULL )
        {
            g_free( view->projection );
            view->projection = NULL;
        }
    }

    gtk_signal_disconnect_by_data(layer_obj, GTK_OBJECT(view));
    gtk_object_unref(layer_obj);

    gtk_signal_emit(GTK_OBJECT(view), view_area_signals[ACTIVE_CHANGED]);

    gv_view_area_queue_draw(view);
}

GtkObject *
gv_view_area_active_layer(GvViewArea *view)
{
    return view->active_layer;
}

void
gv_view_area_set_active_layer(GvViewArea *view, GtkObject *layer)
{
    g_return_if_fail(layer == NULL || GV_IS_LAYER(layer));

    /* Ignore if this is already the active layer */
    if (layer == view->active_layer) return;

    if (layer)
    {
    /* Make sure this layer is in the list */
    if (g_list_find(view->layers, (gpointer)layer) == NULL)
    {
        CPLDebug( "OpenEV",
                      "gv_view_area_set_active_layer(): layer %s not in view",
              gtk_type_name(GTK_OBJECT_TYPE(layer)));
        return;
    }
    }

    view->active_layer = layer;

    gtk_signal_emit(GTK_OBJECT(view), view_area_signals[ACTIVE_CHANGED]);
}

GtkObject *
gv_view_area_get_layer_of_type(GvViewArea *view, GtkType layer_type,
                               gint read_only_ok )
{
    GList *list;

    /* First check the active layer */
    if(view->active_layer &&
       gtk_type_is_a(GTK_OBJECT_TYPE(view->active_layer), layer_type)
       && (read_only_ok || !gv_data_is_read_only(GV_DATA(view->active_layer))))
    {
    return view->active_layer;
    }

    /* Next move through the list in order */
    list = view->layers;
    while (list)
    {
    GvLayer *layer = (GvLayer*)list->data;
    if( gtk_type_is_a(GTK_OBJECT_TYPE(layer), layer_type)
            && (read_only_ok || !gv_data_is_read_only(GV_DATA(layer))) )
    {
        return GTK_OBJECT(layer);
    }
    list = g_list_next(list);
    }
    return NULL;
}

GtkObject *
gv_view_area_get_named_layer(GvViewArea *view, const char *name)
{
    GList *list;

    list = view->layers;
    while (list)
    {
    GvLayer *layer = (GvLayer*)list->data;
    if (GV_DATA(layer)->name && strcmp(GV_DATA(layer)->name, name) == 0)
    {
        return GTK_OBJECT(layer);
    }
    list = g_list_next(list);
    }
    return NULL;
}

GList *
gv_view_area_list_layers(GvViewArea *view)
{
    return g_list_copy(view->layers);
}

void
gv_view_area_swap_layers(GvViewArea *view, gint index_a, gint index_b)
{
    gpointer *layer_a, *layer_b;

    g_return_if_fail(index_a != index_b);

    /* Put indicies in ascending order */
    if (index_a > index_b)
    {
    gint tmp = index_b;
    index_b = index_a;
    index_a = tmp;
    }

    layer_a = g_list_nth_data(view->layers, index_a);
    layer_b = g_list_nth_data(view->layers, index_b);
    g_return_if_fail(layer_a && layer_b);

    /* Perform swap */
    view->layers = g_list_remove(view->layers, layer_a);
    view->layers = g_list_remove(view->layers, layer_b);
    view->layers = g_list_insert(view->layers, layer_b, index_a);
    view->layers = g_list_insert(view->layers, layer_a, index_b);

    gv_view_area_queue_draw(view);
}

GdkPixmap *
gv_view_area_create_thumbnail(GvViewArea *view, GtkObject *layerobj,
                  gint width, gint height)
{
#ifdef WIN32
    return NULL;
#else
    GvLayer *layer;
    GdkPixmap *pixmap;
    GdkVisual *visual;
    GdkGLContext *glcontext;
    GdkGLPixmap *glpixmap;
    GvRect extents;
    gvgeocoord aspect;
    gint visible;

    if( !GTK_WIDGET_REALIZED(view) )
        return NULL;

    g_return_val_if_fail(GV_IS_LAYER(layerobj), NULL);

    layer = GV_LAYER(layerobj);

    visual = gtk_widget_get_visual(GTK_WIDGET(view));
    pixmap = gdk_pixmap_new(NULL, width, height, visual->depth);
    glcontext = GTK_GL_AREA(view)->glcontext;
    glpixmap = gdk_gl_pixmap_new(visual, pixmap);

    if (!gdk_gl_pixmap_make_current(glpixmap, glcontext))
    {
    CPLDebug( "OpenEV",
                  "gv_view_area_create_thumbnail(): offscreen render failed.");
    gdk_gl_pixmap_unref(glpixmap);
    gdk_pixmap_unref(pixmap);
    return NULL;
    }

    /* Add 5% to extents in each direction to get a nice border */
    gv_layer_extents(layer, &extents);
    extents.x -= extents.width * 0.05;
    extents.y -= extents.height * 0.05;
    extents.width *= 1.1;
    extents.height *= 1.1;

    /* Fix aspect ratio */
    aspect = (gvgeocoord)width / (gvgeocoord)height;
    if( (extents.width / extents.height) > aspect )
    {
    gvgeocoord newheight = extents.width / aspect;
    extents.y -= (newheight - extents.height) / 2.0;
    extents.height = newheight;
    }
    else
    {
    gvgeocoord newwidth = extents.height * aspect;
    extents.x -= (newwidth - extents.width) / 2.0;
    extents.width = newwidth;
    }

    /* glpixmap is in the front left buffer */
    glDrawBuffer(GL_FRONT_LEFT);
    glViewport(0, 0, width, height);

    /* Set background to black */
    glClearColor(view->background[0], view->background[1], view->background[2],
                 view->background[3] );
    glClear(GL_COLOR_BUFFER_BIT);

    /* Make sure there is something to draw */
    if (extents.width > 0 || extents.height > 0)
    {
    /* Temporarily make visible, and turn on presentation mode */
    visible = gv_layer_set_visible_temp(layer, TRUE);
    gv_layer_set_presentation(layer, TRUE);

    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
        if( view->state.flip_y < 0 )
        {
            gluOrtho2D(extents.x, extents.x + extents.width,
                       extents.y + extents.height, extents.y );
        }
        else
        {
            gluOrtho2D(extents.x, extents.x + extents.width,
                       extents.y, extents.y + extents.height);
        }

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gv_layer_draw(layer, view);

    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);

    /* Turn off presentation mode and restore visibility */
    gv_layer_set_visible_temp(layer, visible);
    gv_layer_set_presentation(layer, FALSE);
    }
    glFinish();

    /* Restore the view as the current context before destroying
       the glpixmap */
    if (!gtk_gl_area_make_current(GTK_GL_AREA(view)))
    {
    g_warning("gv_view_area_create_thumbnail(): view context restore failed.");
    }
    glViewport(0, 0, view->state.shape_x, view->state.shape_y);
    glDrawBuffer(GL_BACK);

    gdk_gl_pixmap_unref(glpixmap);
    return pixmap;
#endif
}

gint
gv_view_area_render_to_func(GvViewArea *view,
                            gint width, gint height,
                            gint (*scanline_handler)( void *, void * ),
                            void *cb_data )
{
    GvRect extents;
    gvgeocoord aspect;
    guint8 *scanline;
    gvgeocoord xmin, xmax, ymin, ymax;
    gint line, errcode = 0;
    gint x_chunk, x_chunk_size, y_chunk, y_chunk_size;
    GList *list;
    guint8 *row_of_chunks;
    int     direct_render, save_exact;

    if (!gtk_gl_area_make_current(GTK_GL_AREA(view))) return -1;

    direct_render = (width == view->state.shape_x)
                 && (height == view->state.shape_y);

    save_exact = view->exact_render;
    view->exact_render = TRUE;

    x_chunk_size = view->state.shape_x;
    y_chunk_size = view->state.shape_y;

    gv_view_area_get_extents(view, &xmin, &ymin, &xmax, &ymax );
    extents.x = xmin;
    extents.width = xmax - xmin;
    extents.y = ymin;
    extents.height = ymax - ymin;

    /* Fix aspect ratio */
    aspect = (gvgeocoord)width / (gvgeocoord)height;
    if ( (extents.width / extents.height) > aspect )
    {
    gvgeocoord newheight = extents.width / aspect;
    extents.y -= (newheight - extents.height) / 2.0;
    extents.height = newheight;
    }
    else
    {
    gvgeocoord newwidth = extents.height * aspect;
    extents.x -= (newwidth - extents.width) / 2.0;
    extents.width = newwidth;
    }

    /* allocate a buffer large enough to hold one RGB row of chunks */
    row_of_chunks = g_malloc(width * y_chunk_size * 3);
    if( row_of_chunks == NULL )
    {
        g_warning( "out of memory in gv_view_area_render_to_func" );
        view->exact_render = save_exact;
        return -1;
    }
    memset( row_of_chunks, 0, width*y_chunk_size*3 );

    /* glpixmap is in the front left buffer */
    glDrawBuffer(GL_BACK);
    glReadBuffer(GL_BACK);

    /* Make sure there is something to draw */
    if (extents.width == 0 || extents.height == 0)
    {
        view->exact_render = save_exact;
        return -1;
    }

    for( y_chunk=0; y_chunk < height && errcode == 0; y_chunk += y_chunk_size)
    {
        GvRect chunk_extents;

        chunk_extents.height =
            extents.height * (y_chunk_size / (double) height);
        if( view->state.flip_y < 0 )
        {
            chunk_extents.y = extents.y
                + extents.height * (y_chunk / (double) height);
        }
        else
        {
            chunk_extents.y = extents.y + extents.height
                - extents.height * ((y_chunk+y_chunk_size) / (double) height);
        }

        for( x_chunk = 0;
             x_chunk < width && errcode == 0;
             x_chunk += x_chunk_size )
        {
            chunk_extents.width =
                extents.width * (x_chunk_size / (double) width);
            chunk_extents.x = extents.x
                + extents.width * (x_chunk / (double) width);

            /* Set background to black */
            glClearColor(view->background[0], view->background[1],
                         view->background[2], view->background[3] );
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            render_counter++;

            if( !direct_render )
            {
                glMatrixMode(GL_PROJECTION);
                glPushMatrix();
                glLoadIdentity();
                if( view->state.flip_y < 0 )
                {
                    gluOrtho2D(chunk_extents.x,
                               chunk_extents.x + chunk_extents.width,
                               chunk_extents.y + chunk_extents.height,
                               chunk_extents.y );
                }
                else
                {
                    gluOrtho2D(chunk_extents.x,
                               chunk_extents.x + chunk_extents.width,
                               chunk_extents.y,
                               chunk_extents.y + chunk_extents.height);
                }

                glMatrixMode(GL_MODELVIEW);
                glLoadIdentity();
            }

            for( list = view->layers; list != NULL; list = g_list_next(list) )
            {
                GvLayer  *layer = GV_LAYER( list->data );

                gv_layer_set_presentation(layer, TRUE);
                gv_layer_draw(layer, view);
                gv_layer_set_presentation(layer, FALSE);
            }

            if( !direct_render )
            {
                glMatrixMode(GL_PROJECTION);
                glPopMatrix();
                glMatrixMode(GL_MODELVIEW);
            }

            glFinish();

            for( line = 0;
                 line < y_chunk_size && errcode == 0
                     && (line + y_chunk) < height;
                 line++ )
            {
                const static char *signature = "glReadPixels() check signature";

                scanline = row_of_chunks +
                    x_chunk * 3
                    + line * width * 3;

                if( x_chunk_size * y_chunk_size >= strlen(signature) )
                    memcpy( scanline, signature, strlen(signature) );
                    
                glReadPixels( 0, y_chunk_size - line - 1,
                              MIN(x_chunk_size,width-x_chunk), 1,
                              GL_RGB, GL_UNSIGNED_BYTE, scanline );

                if( x_chunk_size * y_chunk_size >= strlen(signature) 
                    && memcmp( scanline, signature, strlen(signature)) == 0 )
                {
                    CPLDebug( "OpenEV",
                              "glReadPixels() appears to have failed." );
                    errcode = 1;
                }
            }
        }

        for( line = 0;
             line < y_chunk_size && errcode == 0
                 && (line + y_chunk) < height;
             line++ )
        {
            scanline = row_of_chunks + line * width * 3;
            errcode =  scanline_handler( cb_data, scanline );
        }
    }

    g_free( row_of_chunks );

    view->exact_render = save_exact;

    return errcode;
}

GPtrArray *gv_view_area_get_fontnames( GvViewArea *view )

{
    GPtrArray   *ret_list;
    int     font;

    ret_list = g_ptr_array_new();

    for( font = 0; bmfontmap[font].gvname != NULL; font++ )
        g_ptr_array_add( ret_list, bmfontmap[font].gvname );

    return ret_list;
}

gint
gv_view_area_bmfont_load(GvViewArea *view, gchar *name)
{
    gint     font;
    GvBMFontInfo new_finfo;

    /* translate aliases */
    for (font=0; bmfontmap[font].gvname != NULL; font++)
    {
    if (strcmp(name, bmfontmap[font].gvname) == 0)
    {
            name = bmfontmap[font].gdkname;
        break;
    }
    }

    /* Do we already have this font loaded? */
    for (font=0; font < view->bmfonts->len; font++ )
    {
        GvBMFontInfo    *finfo;

        finfo = &(g_array_index( view->bmfonts, GvBMFontInfo, font ));
    if (strcmp(name, finfo->name) == 0)
            return font;
    }

    /* Try to load the font */
    if (!gtk_gl_area_make_current(GTK_GL_AREA(view)))
    {
        g_warning("gv_view_area_bmfont_load(): can't make view area current");
        return -1;
    }

    new_finfo.listbase = glGenLists(96);
    if (new_finfo.listbase == 0)
    {
        g_warning("gv_view_area_bmfont_load(): font allocation failed");
        return -1;
    }

    new_finfo.gdkfont = gdk_font_load(name);
    if (!new_finfo.gdkfont)
    {
        g_warning("gv_view_area_bmfont_load(): gdk font load failed: %s",
                  name );
        return -1;
    }

    gdk_gl_use_gdk_font(new_finfo.gdkfont, 0, 127, new_finfo.listbase);


    new_finfo.name = g_strdup(name);
    g_array_append_val( view->bmfonts, new_finfo);

    return view->bmfonts->len-1;
}

GvBMFontInfo *
gv_view_area_bmfont_get_info(GvViewArea *view, gint font)
{
    GvBMFontInfo    *finfo;

    if (font < 0 || font >= view->bmfonts->len )
        return NULL;

    finfo = &(g_array_index( view->bmfonts, GvBMFontInfo, font ));
    return finfo;
}

void
gv_view_area_bmfont_draw(GvViewArea *view, gint font, gvgeocoord x, gvgeocoord y,
                         gchar *text, int force_simple )
{
    GvBMFontInfo    *finfo;

    if (font < 0 || font >= view->bmfonts->len )
        return;

    finfo = &(g_array_index( view->bmfonts, GvBMFontInfo, font ));

    /*
     * In 3D it would be too hard to determine whats in/out of view, so
     * we just do the simple thing.  This will result in strings with an
     * origin out of the view frustrum not being drawn, but that's life.
     */
    if( view->flag_3d || force_simple )
    {
        glRasterPos2f(x, y);
    }
    /*
     * Ensure we initially position the raster position within the
     * view frustrum, then offset to our desired location.
     */
    else
    {
        gvgeocoord  vx, vy, vx_screen, vy_screen, tx_screen, ty_screen;

        vx_screen = view->state.shape_x/2;
        vy_screen = view->state.shape_y/2;

        gv_view_area_map_pointer( view, vx_screen, vy_screen,
                                  &vx, &vy );
        gv_view_area_inverse_map_pointer( view, x, y, &tx_screen, &ty_screen );

        /* position in frustrum */
        glRasterPos2f(vx, vy);

        /* shift to desired location. */
        glBitmap( 0, 0, 0, 0,
                  (int) -(vx_screen - floor(tx_screen)),
                  (int) (vy_screen - ceil(ty_screen)),
                  NULL );
    }

    glPushAttrib(GL_LIST_BASE);
    glListBase(finfo->listbase);
    glCallLists(strlen(text), GL_UNSIGNED_BYTE, (GLubyte*)text);
    glPopAttrib();
}

void gv_view_area_set_background_color( GvViewArea *view, GvColor new_color )

{
    if( new_color[0] != view->background[0]
        || new_color[1] != view->background[1]
        || new_color[2] != view->background[2]
        || new_color[3] != view->background[3] )
    {
        gv_color_copy( view->background, new_color );
        gv_view_area_state_changed(view);
    }
}

void gv_view_area_get_background_color( GvViewArea *view, GvColor color )

{
    color[0] = view->background[0];
    color[1] = view->background[1];
    color[2] = view->background[2];
    color[3] = view->background[3];
}

/*****************************************************************/

static gint
gv_view_area_reset_projection(GvViewArea *view, gvgeocoord width, gvgeocoord height)
{
    if( !gtk_gl_area_make_current(GTK_GL_AREA(view)) )
        return 1;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (! view->flag_3d)
    {
        /* Assumes clipping plane of [-1.0, 1.0]
        gluOrtho2D(-width/2.0, width/2.0, -height/2.0, height/2.0); */
        glOrtho(-width/2.0, width/2.0, -height/2.0, height/2.0, -1000.0f, 1000.0f);
    } else {
        gluPerspective(90.0f,(GLgeocoord)width/(GLgeocoord)height,10.0f,3000000.0f);
    }
    glMatrixMode(GL_MODELVIEW);

    return 0;

}
static gint
gv_view_area_configure(GtkWidget *widget, GdkEventConfigure *event)
{
    GvViewArea *view = GV_VIEW_AREA(widget);
    int w, h;

    if (!gtk_gl_area_make_current(GTK_GL_AREA(view))) return 0;

    CPLDebug( "OpenEV", "VENDOR = %s", glGetString( GL_VENDOR ) );
    CPLDebug( "OpenEV", "RENDERER = %s", glGetString( GL_RENDERER ) );
    CPLDebug( "OpenEV", "VERSION = %s", glGetString( GL_VERSION ) );
    CPLDebug( "OpenEV", "EXTENSIONS = %s", glGetString( GL_EXTENSIONS ) );

    w = event->width;
    h = event->height;

    gv_view_area_reset_projection(view, (gvgeocoord)w, (gvgeocoord)h);

    view->state.shape_x = (gvgeocoord)w;
    view->state.shape_y = (gvgeocoord)h;

    gv_view_area_state_changed( view );

    return 0;
}

gint
gv_view_area_expose(GtkWidget *widget, GdkEventExpose *event)
{
    GvViewArea *view = GV_VIEW_AREA(widget);
    GList *list;
    GvLayer *layer;
    GTimer *timer;


    if (!gtk_gl_area_make_current(GTK_GL_AREA(view))) return 0;

    /*
    ** If the display state hasn't changed in any way, then just refresh from
    ** our display buffer.  Otherwise we will actually need to rerender with
    ** OpenGL.  We avoid rerendering for interactivity on software rendered
    ** systems.
    */

    if( (!view->display_dirty)
        && ((strstr(glGetString(GL_RENDERER), "Mesa Windows") != NULL) ||
        (strstr(glGetString(GL_RENDERER),"Mesa X11") != NULL) ||
        (strstr(glGetString(GL_RENDERER), "Mesa GLX Indirect") != NULL)))
    {

        gtk_gl_area_swap_buffers(GTK_GL_AREA(view));
    gtk_signal_emit(GTK_OBJECT(view), view_area_signals[GLCURSOR]);
        return 0;
    }

    view->display_dirty = FALSE;

    render_counter++;

    gv_manager_set_busy( gv_get_manager(), TRUE );

    timer = g_timer_new();
    g_timer_start( timer );

    glDisable(GL_DITHER);
    glShadeModel(GL_FLAT);
    glClearColor(view->background[0], view->background[1],
                 view->background[2], view->background[3] );

    /* Do we need these??? */
    if (view->flag_3d)
    {
#ifdef notdef
        glEnable(GL_CULL_FACE);
#endif
        glEnable(GL_NORMALIZE);
        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_LEQUAL);
    }
    else
    {
        glDisable(GL_NORMALIZE);
        glDisable(GL_DEPTH_TEST);
    }

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();

    if (view->flag_3d)
    {
        double     min_range, max_range;
        vec3_t eye_pos, eye_dir, flip_eye_pos;
        int   debug3d = 0;

        if( gv_manager_get_preference(gv_get_manager(),"DEBUG3D") != NULL )
            debug3d =
                atoi(gv_manager_get_preference(gv_get_manager(),"DEBUG3D"));

        eye_pos[0] = view->state.eye_pos[0];
        eye_pos[1] = view->state.eye_pos[1];
        eye_pos[2] = view->state.eye_pos[2];

        eye_dir[0] = view->state.eye_dir[0];
        eye_dir[1] = view->state.eye_dir[1];
        eye_dir[2] = view->state.eye_dir[2];


        /* Compute the near and far clipping planes - taking into account any image flips */
        gv_view_area_get_volume( view, NULL );

        flip_eye_pos[0] = view->state.flip_x * eye_pos[0];
        flip_eye_pos[1] = view->state.flip_y * eye_pos[1];
        flip_eye_pos[2] = eye_pos[2];

        vec_near_far_range( flip_eye_pos, view->view_volume,
                            &min_range, &max_range);

        if( min_range < max_range / 500.0 || min_range >= max_range )
            min_range = max_range / 500.0;

        max_range = max_range * 1.2;
        min_range = min_range * 0.5;

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(90.0f,
                       (gvgeocoord)view->state.shape_x/(gvgeocoord)view->state.shape_y,
                       min_range*0.5, max_range );
        glMatrixMode(GL_MODELVIEW);

        if( debug3d )
        {
            printf( "================ Redraw Start ===================\n" );
            printf( "Clipping planes: near=%g, far=%g\n",
                    min_range, max_range );
        }

        /* Set view orientation */
        gluLookAt(eye_pos[0], eye_pos[1], eye_pos[2],
              eye_pos[0] + eye_dir[0],
                  eye_pos[1] + eye_dir[1],
                  eye_pos[2] + eye_dir[2],
                  0.0, 0.0, 1.0);

        glScale(1.0 * view->state.flip_x, 1.0 * view->state.flip_y, view->state.z_scale);

        if( debug3d )
        {
            printf( "eye=(%g,%g,%g)  eye_dir=(%g,%g,%g)\n",
                    eye_pos[0], eye_pos[1], eye_pos[2],
                    eye_dir[0], eye_dir[1], eye_dir[2] );
        }

    } else {
        glRotate(view->state.rot, 0.0, 0.0, 1.0);

        glScale(view->state.linear_zoom * view->state.flip_x,
                 view->state.linear_zoom * view->state.flip_y, 1.0);

        glTranslate(view->state.tx, view->state.ty, 0.0);
    }

    list = view->layers;
    while (list)
    {
    layer = (GvLayer*)list->data;
    gv_layer_draw(layer, view);
    list = g_list_next(list);
    }

    /* Give other interested objects a chance to add to the drawing */
    gtk_signal_emit(GTK_OBJECT(view), view_area_signals[GLDRAW]);

    /* draw banded zoom area */
    if (view->dragging_mode)
    {
        gvgeocoord x[4], y[4];

        gv_view_area_map_pointer( view,
                                  view->state.mpos_x, view->state.mpos_y,
                                  x+0, y+0 );
        gv_view_area_map_pointer( view,
                                  view->last_mpos_x, view->state.mpos_y,
                                  x+1, y+1 );
        gv_view_area_map_pointer( view,
                                  view->last_mpos_x, view->last_mpos_y,
                                  x+2, y+2 );
        gv_view_area_map_pointer( view,
                                  view->state.mpos_x, view->last_mpos_y,
                                  x+3, y+3 );

    glColor3f(1.0, 0.5, 0.0);
    glBegin(GL_LINE_LOOP);
    glVertex2(x[0], y[0]);
    glVertex2(x[1], y[1]);
    glVertex2(x[2], y[2]);
    glVertex2(x[3], y[3]);
    glEnd();
    }

    gtk_gl_area_swap_buffers(GTK_GL_AREA(view));
    /* Don't XOR last ghost cursor position, since view has been redrawn */
    /* (only has effect in logical cursor mode) */
    view->last_valid=FALSE;
    gtk_signal_emit(GTK_OBJECT(view),view_area_signals[GLCURSOR]);

    glFinish();

    /*
     * Capture time this draw took.
     */
    view->last_draw_time = g_timer_elapsed(timer,NULL);
    g_timer_stop( timer );
    g_timer_destroy( timer );

    /*
     * Setup timer so we know when we should do the next redraw, even if
     * all the idle work isn't done yet.
     */
    if( view->redraw_timer != NULL )
        g_timer_destroy( view->redraw_timer );

    view->redraw_timer = g_timer_new();
    g_timer_start( view->redraw_timer );

    return 0;
}

static void
gv_view_area_realize(GtkWidget *widget)
{
    GvViewArea *view = GV_VIEW_AREA(widget);
    GtkGLAreaClass *parent_class;
    GList *list;
    GvLayer *layer;
    const char *auto_fit_flag;

    /* Call parent class function first */
    parent_class = gtk_type_class(gtk_gl_area_get_type());
    GTK_WIDGET_CLASS(parent_class)->realize(GTK_WIDGET(view));

    g_return_if_fail(GTK_WIDGET_REALIZED(GTK_WIDGET(view)));

    /* Make gl area current so layers can create gl handles */
    if (!gtk_gl_area_make_current(GTK_GL_AREA(view))) return;

    /* Call the one time setup function for all layers */
    list = view->layers;
    while (list)
    {
    layer = (GvLayer*)list->data;
    gv_layer_setup(layer, view);
    list = g_list_next(list);
    }

    /* Set up the inital view transformation using the first layer */
    auto_fit_flag = gv_properties_get(&(view->properties),
                                      "_supress_realize_auto_fit");
    if (view->layers && (auto_fit_flag == NULL || EQUAL(auto_fit_flag,"off")))
    {
    layer = (GvLayer*)view->layers->data;
    gv_view_area_fit_layer(view, layer);
    }
}

static void
gv_view_area_unrealize(GtkWidget *widget)
{
    GvViewArea *view = GV_VIEW_AREA(widget);
    GtkGLAreaClass *parent_class;
    GList *list;
    gint font;

    /* Make gl area current so layers can clean up gl handles */
    if (!gtk_gl_area_make_current(GTK_GL_AREA(view)))
    {
    g_warning("gv_view_area_unrealize(): can't make view area current");
    return;
    }

    /* Teardown all layers */
    view->active_layer = NULL;
    list = view->layers;
    while (list)
    {
    GvLayer *layer = (GvLayer*)list->data;
    gv_layer_teardown(layer, view);
    list = g_list_next(list);
    }

    /* Destroy bmfont listbase array */
    for( font=0; font < view->bmfonts->len; font++ )
    {
        GvBMFontInfo    *finfo;

        finfo = &(g_array_index( view->bmfonts, GvBMFontInfo, font ));

        if( finfo->gdkfont != NULL )
            gdk_font_unref(finfo->gdkfont);

        g_free( finfo->name );
        glDeleteLists(finfo->listbase, 96);
    }
    g_array_free( view->bmfonts, TRUE );

    /* Call parent class function */
    parent_class = gtk_type_class(gtk_gl_area_get_type());
    GTK_WIDGET_CLASS(parent_class)->unrealize(GTK_WIDGET(view));
}

static void
gv_view_area_fit_layer(GvViewArea *view, GvLayer *layer)
{
    GvRect rect;

    /* Set the view transformation to show the full extents of the layer */

    /* Make sure the view area is realized so the state.shape has been
       set (a configure event has been recieved) */
    if (!GTK_WIDGET_REALIZED(GTK_WIDGET(view))) return;

    /*
     * Set the view projection.
     */
    if( view->projection != NULL )
    {
        g_free( view->projection );
        view->projection = NULL;
    }

    if( gv_data_get_projection(GV_DATA(layer)) != NULL )
    {
        view->projection = g_strdup(gv_data_get_projection(GV_DATA(layer)));
    }

    /*
     * Get the layer extents.
     */
    gv_layer_extents(layer, &rect);

    /*
     * If this is an image, we want to try and orient the image with
     * pixel (0,0) in the top left if possible.
     */
    if( GV_IS_RASTER_LAYER(layer) )
    {
        GvRaster     *raster;

        raster = GV_RASTER_LAYER(layer)->prototype_data;

        if( GV_RASTER_LAYER(layer)->mesh_is_raw
            || (raster->gcp_count == 0
                && raster->geotransform[2] == 0.0
                && raster->geotransform[4] == 0.0
                && raster->geotransform[5] > 0.0) )
        {
            rect.y = rect.y + rect.height;
            rect.height *= -1;
        }
    }

    gv_view_area_fit_extents(view, rect.x, rect.y, rect.width, rect.height );

    /* Setup 3D specific extent information */
    gv_view_area_fit_extents_3D(view,
                                rect.x, rect.y, 0.0,
                                rect.width, rect.height,
                                (rect.width+rect.height)*0.5 );
}

void
gv_view_area_fit_all_layers(GvViewArea *view)

{
    GvRect rect;
    double volume[6];

    /*
     * Set 2D view.
     */
    gv_view_area_get_world_extents( view, &rect );
    gv_view_area_fit_extents(view, rect.x, rect.y, rect.width, rect.height );

    /*
     * Also do a default 3D view.
     */
    gv_view_area_get_volume( view, volume );
    gv_view_area_fit_extents_3D( view,
                                 volume[0],
                                 volume[2],
                                 volume[4],
                                 volume[1] - volume[0],
                                 volume[3] - volume[2],
                                 volume[5] - volume[4] );
}

void
gv_view_area_get_world_extents(GvViewArea *view, GvRect *extents )

{
    GvRect rect;
    int    flip_y = FALSE, first = TRUE, first_raster = TRUE;
    GList *list;

    rect.x = 0;
    rect.y = 0;
    rect.width = 0;
    rect.height = 0;

    /* Make sure the view area is realized so the state.shape has been
       set (a configure event has been recieved) */
    if (!GTK_WIDGET_REALIZED(GTK_WIDGET(view)))
    {
        *extents = rect;
        return;
    }

    /*
     * Get the layers extents.
     */
    list = view->layers;
    while (list)
    {
    GvLayer *layer = (GvLayer*)list->data;
        GvRect  layer_rect;

        gv_layer_extents(layer, &layer_rect);

        if( layer_rect.width == 0 && layer_rect.height == 0 )
            /* do nothing */;

        else if( first )
        {
            rect = layer_rect;
            first = FALSE;

            if( first_raster && GV_IS_RASTER_LAYER(layer) )
            {
                GvRasterLayer *rlayer = GV_RASTER_LAYER(layer);
                GvRaster     *raster = rlayer->prototype_data;

                if( rlayer->mesh_is_raw )
                {
                    flip_y = TRUE;
                }
                else if( raster->gcp_count == 0
                         && raster->geotransform[2] == 0.0
                         && raster->geotransform[4] == 0.0 )
                {
                    if( raster->geotransform[5] > 0.0 )
                    {
                        flip_y = TRUE;
                    }
                }

                first_raster = FALSE;
            }
        }
        else
        {
            gvgeocoord     new_x, new_y;

            new_x = MIN(rect.x,layer_rect.x);
            rect.width = MAX(rect.x+rect.width,
                             layer_rect.x+layer_rect.width) - new_x;
            new_y = MIN(rect.y,layer_rect.y);
            rect.height = MAX(rect.y+rect.height,
                              layer_rect.y+layer_rect.height) - new_y;
            rect.x = new_x;
            rect.y = new_y;
        }

    list = g_list_next(list);
    }

    /*
     * If we found a "raw" raster layer, flip the coordinate system.
     */
    if( flip_y )
    {
        rect.y = rect.y + rect.height;
        rect.height *= -1;
    }

    *extents = rect;
}

void
gv_view_area_fit_extents(GvViewArea *view,
                         gvgeocoord llx,   gvgeocoord lly,
                         gvgeocoord width, gvgeocoord height )
{
    /* Make sure the view area is realized so the state.shape has been
       set (a configure event has been recieved) */
    if (!GTK_WIDGET_REALIZED(GTK_WIDGET(view))) return;

    if (width == 0.0 || height == 0.0)
    {
    view->state.linear_zoom = 1.0;
    }
    else
    {
    gvgeocoord zoomx, zoomy;

    zoomx = view->state.shape_x / width;
    zoomy = view->state.shape_y / ABS(height);

    view->state.linear_zoom = MIN(zoomx, zoomy);
    }

    view->state.rot = 0.0;
    view->state.tx = -(width/2.0 + llx);
    view->state.ty = -(height/2.0 + lly);
    view->state.zoom = LOG2(view->state.linear_zoom);

    if( height < 0.0 )
    {
        view->state.flip_y = -1.0;
    }

    gv_view_area_state_changed(view);
}

void
gv_view_area_fit_extents_3D(GvViewArea *view,
                            gvgeocoord llx, gvgeocoord lly, gvgeocoord minz,
                            gvgeocoord width, gvgeocoord height, gvgeocoord delta_z )

{
    vec3_t  new_eye_pos, new_eye_dir;
    double  eye_az, eye_el, linear_measure;

    /* Make sure the view area is realized so the state.shape has been
       set (a configure event has been recieved) */
    if (!GTK_WIDGET_REALIZED(GTK_WIDGET(view))) return;

    if (width == 0.0 || height == 0.0) return;

    linear_measure = MAX(MAX(width,height),delta_z);

    new_eye_pos[0] = llx + width * 0.5;
    new_eye_pos[1] = lly - linear_measure * 0.5;
    new_eye_pos[2] = minz + linear_measure * 0.5;

    eye_az = 90.0;   /* rotation ? */
    eye_el = -45.0;  /* tilt  0 --> extreem  -90 --> none*/
    vec_point(new_eye_dir, eye_az, eye_el);

    gv_view_area_set_3d_view( view, new_eye_pos, new_eye_dir );
}

void
gv_view_area_get_extents(GvViewArea *view,
                         gvgeocoord *xmin, gvgeocoord *ymin,
                         gvgeocoord *xmax, gvgeocoord *ymax )

{
    gvgeocoord       x[4], y[4];

    gv_view_area_map_pointer( view, 0, 0,
                              x+0, y+0 );
    gv_view_area_map_pointer( view, 0, view->state.shape_y,
                              x+1, y+1 );
    gv_view_area_map_pointer( view, view->state.shape_x, 0,
                              x+2, y+2 );
    gv_view_area_map_pointer( view, view->state.shape_x, view->state.shape_y,
                              x+3, y+3 );

    *xmin = MIN(MIN(x[0],x[1]),MIN(x[2],x[3]));
    *ymin = MIN(MIN(y[0],y[1]),MIN(y[2],y[3]));
    *xmax = MAX(MAX(x[0],x[1]),MAX(x[2],x[3]));
    *ymax = MAX(MAX(y[0],y[1]),MAX(y[2],y[3]));
}

void
gv_view_area_get_volume( GvViewArea *view, double *volume )

{
    GvRect rect;
    int    first = TRUE;
    GList *list;

    if( view->volume_current )
    {
        if( volume != NULL )
            memcpy( volume, view->view_volume, sizeof(double) * 6 );
        return;
    }

    view->view_volume[0] = 0.0;
    view->view_volume[1] = 1000.0;
    view->view_volume[2] = 0.0;
    view->view_volume[3] = 1000.0;
    view->view_volume[4] = 0.0;
    view->view_volume[5] = 1000.0;
    view->linear_measure = 1000.0;

    /* Make sure the view area is realized so the state.shape has been
       set (a configure event has been recieved) */
    if (!GTK_WIDGET_REALIZED(GTK_WIDGET(view))) return;

    /*
     * Get the layers extents.
     */
    list = view->layers;
    while (list)
    {
    GvLayer *layer = (GvLayer*)list->data;
        GvRect  layer_rect;

        gv_layer_extents(layer, &layer_rect);

        if( layer_rect.width == 0 && layer_rect.height == 0 )
        {
            /* do nothing */;
        }

        else if( first )
        {
            rect = layer_rect;
            first = FALSE;
        }
        else
        {
            gvgeocoord    new_x, new_y;
            new_x = MIN(rect.x,layer_rect.x);
            rect.width = MAX(rect.x+rect.width,
                             layer_rect.x+layer_rect.width) - new_x;
            new_y = MIN(rect.y,layer_rect.y);
            rect.height = MAX(rect.y+rect.height,
                              layer_rect.y+layer_rect.height) - new_y;
            rect.x = new_x;
            rect.y = new_y;
        }

    list = g_list_next(list);
    }

    if( !first )
    {
        view->view_volume[0] = rect.x;
        view->view_volume[1] = rect.x + rect.width;
        view->view_volume[2] = rect.y;
        view->view_volume[3] = rect.y + rect.height;
        view->view_volume[4] = 0.0;
        view->view_volume[5] = (rect.width + rect.height) * 0.5;
        view->volume_current = TRUE;

        view->linear_measure = MAX(rect.width,rect.height);
    }

    if( volume != NULL )
        memcpy( volume, view->view_volume, sizeof(double) * 6 );

#ifdef notdef
    printf( "gv_view_area_get_volume(): %g, %g, %g, %g, %g, %g\n",
            view->view_volume[0],
            view->view_volume[1],
            view->view_volume[2],
            view->view_volume[3],
            view->view_volume[4],
            view->view_volume[5] );
#endif
}

static void
gv_view_area_motion_handle_hint(GtkWidget *view, GdkEventMotion *event)
{
    /* If this is a hint place the event mouse position */
    /* with the real value (round trip query) */

    if (event->is_hint)
    {
    int x, y;
    gtk_widget_get_pointer(view, &x, &y);
    event->x = (gdouble)x;
    event->y = (gdouble)y;
    }
}

void
motion(GvViewArea *view, gvgeocoord move, gvgeocoord strafe, gvgeocoord vert)
{
    vec3_t delta;
    vec3_t new_eye_pos, new_eye_dir;

    /* scaling factor for all motion, always > 0 */
    gvgeocoord scaling_factor = MOVE_SPEED * view->state.eye_pos[2] + (0.0001 * view->linear_measure);

    vec_copy( view->state.eye_dir, new_eye_dir);
    vec_copy( view->state.eye_pos, new_eye_pos);

    if (move != 0.0)
    {
    vec_copy(new_eye_dir, delta);
        /* Scale movement based on height above z plane, previously scaled
           by view->linear_measure */
    vec_scale(delta, move * scaling_factor, delta);
    vec_add(new_eye_pos, delta, new_eye_pos);
    }

    if (strafe != 0.0)
    {
    gvgeocoord norm = sqrt(new_eye_dir[0]*new_eye_dir[0]
                          + new_eye_dir[1]*new_eye_dir[1]);
    if (norm > 0.0)
    {
        delta[0] = new_eye_dir[1] / norm;
        delta[1] = -new_eye_dir[0] / norm;
        delta[2] = 0.0;
        vec_scale(delta, strafe * scaling_factor ,delta);
        vec_add(new_eye_pos, delta, new_eye_pos);
    }
    }

    if (vert != 0.0)
    {
        vec3_t perp;
        gvgeocoord perp_norm;
        gvgeocoord norm =  sqrt(new_eye_dir[0]*new_eye_dir[0]
                          + new_eye_dir[1]*new_eye_dir[1]
                          + new_eye_dir[2]*new_eye_dir[2]);

        /* Get a vector perpendicular to eye_dir */
        perp[0] = - new_eye_dir[0];
        perp[1] = - new_eye_dir[1];
        perp[2] =  (norm/ new_eye_dir[2]) - new_eye_dir[2];

        perp_norm = 1 / sqrt(perp[0]*perp[0]
                         + perp[1]*perp[1]
                         + perp[2]*perp[2]);

        vec_scale(perp, perp_norm * vert * scaling_factor, perp);
        vec_add(new_eye_pos, perp, new_eye_pos);
    }

    gv_view_area_set_3d_view( view, new_eye_pos, new_eye_dir );
}

static gint
gv_view_area_motion_notify(GtkWidget *widget, GdkEventMotion *event)
{
    GvViewArea *view = GV_VIEW_AREA(widget);

    if (event->state & GDK_BUTTON1_MASK && view->dragging_mode)
    {
        gv_view_area_queue_draw( view );
    }

    else if( view->last_button != 0
             && (ABS(view->last_mpos_x - event->x) > DRAG_THRESHOLD
                 || ABS(view->last_mpos_y - event->y) > DRAG_THRESHOLD )
             && (g_get_current_time_as_double() - view->last_zoom_time) > 0.0
             &&  !view->flag_3d)
    {
        view->dragging_mode = TRUE;
        view->last_button = 0;

        gv_view_area_queue_draw(view);
        return FALSE;
    }

    /* zoom */
    else if (event->state & GDK_BUTTON2_MASK
             && event->state & GDK_SHIFT_MASK )
    {
        gvgeocoord ax, ay, bx, by, dz;

        /* Translate origin to the center of the view */
        ax = view->state.mpos_x - view->state.shape_x / 2.0;
        ay = view->state.shape_y / 2.0 - view->state.mpos_y;
        bx = event->x - view->state.shape_x / 2.0;
        by = view->state.shape_y / 2.0 - event->y;

        /* Put an insensitive area about the origin */
        if (!(fabs(bx) < DEAD_ZONE && fabs(by) < DEAD_ZONE) &&
            !(fabs(ax) < DEAD_ZONE && fabs(ay) < DEAD_ZONE))
        {
            /* The "delta" zoom (multiplicative) is the projection of
               b (new pos) on a (old pos) divided by the length of a.
               That is: (a.b)/|a|^2 */
            if (ax*ax+ay*ay != 0.0)
            {
                dz = (ax*bx+ay*by) / (ax*ax+ay*ay);

                /* Sanity check on dz */
                dz = MAX(dz, 1.0e-2);
                dz = MIN(dz, 1.0e2);

                /* gv_view_area_zoom() expects a log (base 2)
                   zoom factor */
                gv_view_area_zoom(view, LOG2(dz));
            }
        }
    }
    /* rotate */
    else if (event->state & GDK_SHIFT_MASK
             && event->state & GDK_BUTTON1_MASK )

    {
        gvgeocoord ax, ay, bx, by, dr;

        /* Translate origin to the center of the view */
        ax = view->state.mpos_x - view->state.shape_x / 2.0;
        ay = view->state.shape_y / 2.0 - view->state.mpos_y;
        bx = event->x - view->state.shape_x / 2.0;
        by = view->state.shape_y / 2.0 - event->y;

        /* Put an insensitive area about the origin */
        if (!(fabs(bx) < DEAD_ZONE && fabs(by) < DEAD_ZONE))
        {
            /* The "delta" rotation is found by taking arc sin of the
               the normalized length of the cross product of b (new pos)
               and a (old pos).  That is: arcsin(|axb|/(|a||b|)) */
            dr = asin((ax*by-ay*bx) /
                      (sqrt(ax*ax+ay*ay) * sqrt(bx*bx+by*by)));

            /* gv_view_area_rotate() expects an angle in degrees */
            gv_view_area_rotate(view, dr / DEG2RAD);
        }
    }

    /* translate */
    else if (event->state & GDK_CONTROL_MASK
             && event->state & GDK_BUTTON2_MASK )
    {
        gv_view_area_translate(view, event->x - view->state.mpos_x,
                               view->state.mpos_y - event->y);
    }

    /* Auto-scroll as we drag outside of window */
    if (event->state & GDK_BUTTON1_MASK)
    {
    if (event->x < 0.0 || event->x > view->state.shape_x ||
        event->y < 0.0 || event->y > view->state.shape_y)
    {
        /* Scroll to mouse pos */
        gvgeocoord dx = 0, dy = 0;
        if (event->x < 0.0)
        dx = -event->x;
        if (event->x > view->state.shape_x)
        dx = view->state.shape_x - event->x;
        if (event->y < 0.0)
        dy = event->y;
        if (event->y > view->state.shape_y)
        dy = event->y - view->state.shape_y;
        gv_view_area_translate(view, dx, dy);

        /* Need to put this event back on the queue
           so it keeps scrolling -- see gtktext.c for example */
    }
    }

    /* Change 3D view direction */
    if (view->flag_3d
        && !(event->state & GDK_CONTROL_MASK)
        && ((event->state & GDK_BUTTON1_MASK)
            || (event->state & GDK_BUTTON2_MASK)
            || (event->state & GDK_BUTTON3_MASK)))
    {
        gvgeocoord eye_az, eye_el;
        int return_value;

        return_value = inv_vec_point(view->state.eye_dir, &eye_az, &eye_el);

        eye_az += (event->x - view->state.mpos_x) * AZ_SCALE;
        eye_el += (event->y - view->state.mpos_y) * EL_SCALE;

        if (eye_el < -89.9) eye_el = -89.9;
        if (eye_el > 45.1) eye_el = 45.1;

        vec_point(view->state.eye_dir, eye_az, eye_el);

        gv_view_area_state_changed(view);

        /* For case when trying to zoom and pan - force zoom update */
        gv_view_area_zoompan_handler((gpointer)view);
    }

    /* Change 3D position (translate on when CTRL) */
    if (view->flag_3d
        && (event->state & GDK_CONTROL_MASK)
        && ((event->state & GDK_BUTTON1_MASK) ||
            (event->state & GDK_BUTTON2_MASK) ||
            (event->state & GDK_BUTTON3_MASK)))
    {
        motion(view, 0.0, -(event->x - view->state.mpos_x) * 0.10, -(event->y - view->state.mpos_y)* 0.10);
    }
    view->state.mpos_x = event->x;
    view->state.mpos_y = event->y;

    return 0;
}


static gint
gv_view_area_zoompan_handler(gpointer data )

{
    GvViewArea *view = (GvViewArea *) data;
    double      time_elapsed, cur_time;
    gvgeocoord  zoom = 0.0;

    if( view->last_button == 0 )
        return( FALSE );

    cur_time = g_get_current_time_as_double();
    time_elapsed = cur_time - view->last_zoom_time;
    view->last_zoom_time = MAX(cur_time,view->last_zoom_time);
    if( time_elapsed < 0 )
    {
        time_elapsed = 0;
    }
    else if( time_elapsed > 1.0 )
        time_elapsed = 1.0;
    else if( !view->flag_3d
             && (ABS(view->last_mpos_x - view->state.mpos_x) > DRAG_THRESHOLD
                 || ABS(view->last_mpos_y - view->state.mpos_y) > DRAG_THRESHOLD ))
    {
        view->dragging_mode = TRUE;
        view->last_button = 0;

        gv_view_area_queue_draw(view);
        return FALSE;
    }

    if( view->last_button == 1 )
        zoom = CONTIN_ZOOM_INC * time_elapsed;
    else if( view->last_button == 3 )
        zoom = -(CONTIN_ZOOM_INC * time_elapsed);

    if( zoom != 0.0 )
    {
        gv_view_area_translate(view,
                               view->state.shape_x/2 - view->state.mpos_x,
                               view->state.mpos_y - view->state.shape_y/2 );
        gv_view_area_zoom(view, zoom );
        gv_view_area_translate(view,
                               view->state.mpos_x - view->state.shape_x/2,
                               view->state.shape_y/2 - view->state.mpos_y );
    }

    return TRUE;
}

static gint
gv_view_area_3d_motion_handler(gpointer data )

{
    GvViewArea *view = (GvViewArea *) data;
    double      time_elapsed, cur_time;
    gvgeocoord  move = 0.0;

    if( view->last_button == 0 )
        return( FALSE );

    cur_time = g_get_current_time_as_double();
    time_elapsed = cur_time - view->last_zoom_time;
    view->last_zoom_time = MAX(cur_time,view->last_zoom_time);
    if( time_elapsed < 0 )
    {
        time_elapsed = 0;
    }
    else if( time_elapsed > 1.0 )
    {
        time_elapsed = 1.0;
    }

    if( view->last_button == 1 )
        move = CONTIN_3DMOVE_INC * time_elapsed;
    else if( view->last_button == 3 )
        move = -(CONTIN_3DMOVE_INC * time_elapsed);

    /* Move Forward or backwards */
    if( move != 0.0 )
        motion(view, move, 0.0, 0.0);

    return TRUE;
}

void
gv_view_area_zoompan_event(GvViewArea *view, GdkEventButton *event)

{
    /* note: we want this function to work properly for "zoom mode"
       with no control, and the modeless "cntl-button" method. */

    if( event->type == GDK_2BUTTON_PRESS )
    {
        view->dragging_mode = FALSE;
        gv_view_area_translate(view,
                               view->state.shape_x/2 - event->x,
                               event->y - view->state.shape_y/2 );

        view->last_button = 0;

        if( event->button == 1 )
            gv_view_area_zoom( view, ZOOM_STEP );
        else if( event->button == 3 )
            gv_view_area_zoom( view, -ZOOM_STEP );

    }
    else if( event->type == GDK_BUTTON_PRESS
             && (event->button == 1 || event->button == 3) )
    {
        view->last_button = event->button;
        view->last_button_time = g_get_current_time_as_double();
        view->last_zoom_time = view->last_button_time + 0.25;
        view->last_mpos_x = view->state.mpos_x;
        view->last_mpos_y = view->state.mpos_y;

        gv_manager_queue_task( gv_get_manager(), "zoompan-handler", 2,
                               gv_view_area_zoompan_handler, view );
    }
    else if( event->type == GDK_BUTTON_PRESS
             || event->type == GDK_BUTTON_RELEASE )
    {
        view->last_button = 0;
    }
}

void
gv_view_area_3d_move_event(GvViewArea *view, GdkEventButton *event)

{
    /* note: we want this function to work properly for "zoom mode"
       with no control, and the modeless "cntl-button" method. */

    /* Double Click */
    if( event->type == GDK_2BUTTON_PRESS )
    {
        view->last_button = 0;

        if( event->button == 1 )
            motion(view, 10.0, 0.0, 0.0);
        else if( event->button == 3 )
            motion(view, -10.0, 0.0, 0.0);

    }
    /* Click and hold */
    else if( event->type == GDK_BUTTON_PRESS
             && (event->button == 1 || event->button == 3) )
    {
        view->last_button = event->button;
        view->last_button_time = g_get_current_time_as_double();
        view->last_zoom_time = view->last_button_time + 0.25;
        view->last_mpos_x = view->state.mpos_x;
        view->last_mpos_y = view->state.mpos_y;

        gv_manager_queue_task( gv_get_manager(), "3d-motion-handler", 2,
                               gv_view_area_3d_motion_handler, view );
    }
    /* Click and release */
    else if( event->type == GDK_BUTTON_PRESS
             || event->type == GDK_BUTTON_RELEASE )
    {
        view->last_button = 0;
    }
}

static gint
gv_view_area_button_press(GtkWidget *widget, GdkEventButton *event)
{
    GvViewArea *view = GV_VIEW_AREA(widget);

    if (event->button == 4)
    {
        gv_view_area_zoom(view, -WHEEL_ZOOM_INC);
    }
    else if (event->button == 5)
    {
        gv_view_area_zoom(view, WHEEL_ZOOM_INC);
    }

    /* new zoom logic stuff */
    if( (event->button == 1 || event->button == 3)
        && (event->state & GDK_CONTROL_MASK) )
    {
        if ( view->flag_3d )
        {
            gv_view_area_3d_move_event( view, event);
        } else {
            gv_view_area_zoompan_event( view, event );
        }
    }
    else if (view->flag_3d && (event->button == 1 || event->button == 2 || event->button == 3))
    {
            gv_view_area_3d_move_event( view, event);
    }
    else if( event->state & GDK_CONTROL_MASK )
    {
        if ( view->flag_3d )
        {
            /* Nothing? */
        } else {
            gv_view_area_zoompan_event( view, event );
        }
    }


    view->state.mpos_x = event->x;
    view->state.mpos_y = event->y;

    return 0;
}

static gint
gv_view_area_button_release(GtkWidget *widget, GdkEventButton *event)
{
    GvViewArea *view = GV_VIEW_AREA(widget);

    view->state.mpos_x = event->x;
    view->state.mpos_y = event->y;

    if( view->dragging_mode )
    {
        gvgeocoord x[4], y[4], min_x, max_x, min_y, max_y;

        gv_view_area_map_pointer( view,
                                  view->state.mpos_x, view->state.mpos_y,
                                  x+0, y+0 );
        gv_view_area_map_pointer( view,
                                  view->last_mpos_x, view->state.mpos_y,
                                  x+1, y+1 );
        gv_view_area_map_pointer( view,
                                  view->last_mpos_x, view->last_mpos_y,
                                  x+2, y+2 );
        gv_view_area_map_pointer( view,
                                  view->state.mpos_x, view->last_mpos_y,
                                  x+3, y+3 );

        min_x = MIN(MIN(x[0],x[1]),MIN(x[2],x[3]));
        min_y = MIN(MIN(y[0],y[1]),MIN(y[2],y[3]));
        max_x = MAX(MAX(x[0],x[1]),MAX(x[2],x[3]));
        max_y = MAX(MAX(y[0],y[1]),MAX(y[2],y[3]));

        gv_view_area_fit_extents( view, min_x, min_y,
                                  max_x - min_x, max_y - min_y );

        view->dragging_mode = FALSE;
    }

    /* new zoom logic stuff */
    if( (event->button == 1 || event->button == 3) )
    {
        if ( view->flag_3d )
        {
            gv_view_area_3d_move_event(view, event);
        } else {
            gv_view_area_zoompan_event( view, event );
        }
    }

    return 0;
}

static gint
gv_view_area_key_press(GtkWidget *widget, GdkEventKey *event)
{
    GvViewArea *view = GV_VIEW_AREA(widget);

    gvgeocoord move = 0.0;
    gvgeocoord strafe = 0.0;
    gvgeocoord vert = 0.0;

    int     big_step_x, big_step_y;

    big_step_x = (int) (view->state.shape_x / 1.3);
    big_step_y = (int) (view->state.shape_x / 1.3);

    switch (event->keyval)
    {
      case GDK_z:
        if (event->state & GDK_CONTROL_MASK)
        {
            gv_undo_pop();
        }
        break;

      case GDK_Escape:
        if( view->dragging_mode )
        {
            view->dragging_mode = FALSE;
            gv_view_area_queue_draw( view );
        }
        break;

      case '-':
          if (view->flag_3d)
          {
              view->state.z_scale -= HEIGHT_SCALE*0.1;
              gv_view_area_state_changed(view);
          }
      break;

      case '_':
          if (view->flag_3d)
          {
              view->state.z_scale -= HEIGHT_SCALE;
              gv_view_area_state_changed(view);
          }
      break;

      case '=':
          if (view->flag_3d)
          {
              view->state.z_scale += HEIGHT_SCALE*0.1;
              gv_view_area_state_changed(view);
          }
      break;

      case '+':
          if (view->flag_3d)
          {
              view->state.z_scale += HEIGHT_SCALE;
              gv_view_area_state_changed(view);
          }
      break;

      case GDK_F1:
        if( event->state & GDK_CONTROL_MASK )
        {
            view->state.flip_x *= -1;
            gv_view_area_state_changed(view);
        }
        break;

      case GDK_F2:
          /* Flip along y */
        if( event->state & GDK_CONTROL_MASK )
        {
            view->state.flip_y *= -1;
            gv_view_area_state_changed(view);

        } else {

            /* Switch between 2D and 3D Modes on-the-fly */
            if ( view->flag_3d )
            {
                gv_view_area_set_mode(view, 0);
                gv_view_area_state_changed(view);
            } else {
                gv_view_area_set_mode(view, 1);
                gv_view_area_state_changed(view);
            }
        }
        break;

      case GDK_Page_Up:
        if (view->flag_3d)
        {
            move = 0.1;
            if (event->state & GDK_SHIFT_MASK)
                move = 1.0; /* Use bigger inc. if shifted */

            motion(view, move, strafe, vert);
        } else {
            gv_view_area_zoom( view, ZOOM_STEP );
        }
        break;

      case GDK_Page_Down:
        if (view->flag_3d)
        {
            move = -0.1;
            if (event->state & GDK_SHIFT_MASK)
                move = -1.0; /* Use bigger inc. if shifted */

            motion(view, move, strafe, vert);
        } else {
            gv_view_area_zoom( view, -ZOOM_STEP );
        }
        break;

      case GDK_Right:
          if (view->flag_3d)
          {
              strafe = 1.0;
              motion(view, move, strafe, vert);
          } else {

              if (event->state & GDK_CONTROL_MASK)
                  gv_view_area_translate( view, -big_step_x, 0 );
              else if (event->state & GDK_SHIFT_MASK)
                  gv_view_area_translate( view, -big_step_x/2, 0 );
              else
                  gv_view_area_translate( view, -10, 0 );
          }
          return TRUE; /* Don't let focus change */
          break;

      case GDK_Left:
          if (view->flag_3d)
          {
              strafe = -1.0;
              motion(view, move, strafe, vert);
          } else {
              if (event->state & GDK_CONTROL_MASK)
                  gv_view_area_translate( view, big_step_x, 0 );
              else if (event->state & GDK_SHIFT_MASK)
                  gv_view_area_translate( view, big_step_x/2, 0 );
              else
                  gv_view_area_translate( view, 10, 0 );
          }
          return TRUE; /* Don't let focus change */
          break;

      case GDK_Up:
          if (view->flag_3d)
          {
              vert = 1.0;
              motion(view, move, strafe, vert);
          } else {
              if (event->state & GDK_CONTROL_MASK)
                  gv_view_area_translate( view, 0, -big_step_y );
              else if (event->state & GDK_SHIFT_MASK)
                  gv_view_area_translate( view, 0, -big_step_y/2 );
              else
                  gv_view_area_translate( view, 0, -10 );
          }
          return TRUE; /* Don't let focus change */
          break;

      case GDK_Down:
          if (view->flag_3d)
          {
              vert = -1.0;
              motion(view, move, strafe, vert);
          } else {
              if (event->state & GDK_CONTROL_MASK)
                  gv_view_area_translate( view, 0, big_step_y );
              else if (event->state & GDK_SHIFT_MASK)
                  gv_view_area_translate( view, 0, big_step_y/2 );
              else
                  gv_view_area_translate( view, 0, 10 );
          }
          return TRUE; /* Don't let focus change */
          break;

      case GDK_Home:
        gv_view_area_fit_all_layers( view );
        break;
    }
    /* FIXME: add flipping controls, etc. */

    return 0;
}

static void
gv_view_area_change_notify(GvViewArea *view, gpointer info)
{
    gv_view_area_queue_draw(view);
}

static void
gv_view_area_state_changed(GvViewArea *view)
{
    gtk_signal_emit(GTK_OBJECT(view), view_area_signals[VIEW_STATE_CHANGED]);
    gv_view_area_queue_draw(view);
    gv_view_area_update_adjustments( view );
}

static void
gv_view_area_destroy(GtkObject *object)
{
    GtkGLAreaClass *parent_class;
    GvViewArea *view;

    view = GV_VIEW_AREA(object);

    CPLDebug( "OpenEV", "gv_view_area_destroy" );

    /* Remove all layers */
    view->active_layer = NULL;
    while (view->layers != NULL)
    {
    GvLayer *layer = (GvLayer*)view->layers->data;
    gv_view_area_remove_layer(view, GTK_OBJECT(layer));
    }

    gv_view_area_set_adjustments( view, NULL, NULL );

    /* Call parent class function */
    parent_class = gtk_type_class(gtk_gl_area_get_type());
    GTK_OBJECT_CLASS(parent_class)->destroy(object);
}

static void
gv_view_area_finalize(GtkObject *object)
{
    GvLayerClass *parent_class;

    CPLDebug( "OpenEV", "gv_view_area_finalize" );

    /* Call parent class function */
    parent_class = gtk_type_class(gtk_gl_area_get_type());
    GTK_OBJECT_CLASS(parent_class)->finalize(object);
}

static void
gv_view_area_set_arg (GtkObject        *object,
                      GtkArg           *arg,
                      guint             arg_id)
{
    GvViewArea *view;

    view = GV_VIEW_AREA (object);

    switch (arg_id)
    {
      case ARG_HADJUSTMENT:
        gv_view_area_set_adjustments (view,
                                      GTK_VALUE_POINTER (*arg),
                                      view->vadj);
        break;
      case ARG_VADJUSTMENT:
        gv_view_area_set_adjustments (view,
                                      view->hadj,
                                      GTK_VALUE_POINTER (*arg));
        break;
      default:
        break;
    }
}

static void
gv_view_area_get_arg (GtkObject        *object,
                      GtkArg           *arg,
                      guint             arg_id)
{
    GvViewArea *view;

    view = GV_VIEW_AREA (object);

    switch (arg_id)
    {
      case ARG_HADJUSTMENT:
        GTK_VALUE_POINTER (*arg) = view->hadj;
        break;
      case ARG_VADJUSTMENT:
        GTK_VALUE_POINTER (*arg) = view->vadj;
        break;
      default:
        arg->type = GTK_TYPE_INVALID;
        break;
    }
}

static void
gv_view_area_update_adjustments( GvViewArea *view )

{
    GvRect   world_extents;
    GvRect   view_extents;

    if( !GTK_WIDGET_REALIZED(GTK_WIDGET(view)) )
        return;

    if( view->hadj == NULL && view->vadj == NULL )
        return;

    if( view->lock_adjustments )
        return;

    gv_view_area_get_world_extents( view, &world_extents );
    if( world_extents.width == 0 || world_extents.height == 0 )
        return;

    if( world_extents.height < 0.0 )
    {
        world_extents.y += world_extents.height;
        world_extents.height *= -1;
    }

    gv_view_area_get_extents( view, &view_extents.x, &view_extents.y,
                              &view_extents.width, &view_extents.height);
    view_extents.width = ABS(view_extents.x-view_extents.width);
    view_extents.height = ABS(view_extents.y-view_extents.height);

    view->lock_adjustments = TRUE;

    if( view->hadj != NULL )
    {
        if( view->state.flip_x < 0 )
        {
            view->hadj->upper = -world_extents.x;
            view->hadj->lower = -(world_extents.x + world_extents.width);
            view->hadj->value = -(view_extents.x+view_extents.width);
            view->hadj->page_size = ABS(view_extents.width);
        }
        else
        {
            view->hadj->lower = world_extents.x;
            view->hadj->upper = world_extents.x + world_extents.width;
            view->hadj->value = view_extents.x;
            view->hadj->page_size = view_extents.width;
        }

        if( view->hadj->page_size > view->hadj->upper - view->hadj->lower )
            view->hadj->page_size = view->hadj->upper - view->hadj->lower;
        if( view->hadj->value < view->hadj->lower )
            view->hadj->value = view->hadj->lower;
        if( view->hadj->value+view->hadj->page_size > view->hadj->upper )
            view->hadj->value = view->hadj->upper - view->hadj->page_size;

        view->hadj->page_increment = view->hadj->page_size;
        view->hadj->step_increment = view->hadj->page_increment / 4;

        gtk_adjustment_changed( view->hadj );
    }

    if( view->vadj != NULL )
    {
        if( view->state.flip_y > 0 )
        {
            view->vadj->upper = -world_extents.y;
            view->vadj->lower = -(world_extents.y + world_extents.height);
            view->vadj->value = -(view_extents.y+view_extents.height);
            view->vadj->page_size = ABS(view_extents.height);
        }
        else
        {
            view->vadj->lower = world_extents.y;
            view->vadj->upper = world_extents.y + world_extents.height;
            view->vadj->value = view_extents.y;
            view->vadj->page_size = view_extents.height;
        }

        if( view->vadj->page_size > view->vadj->upper - view->vadj->lower )
            view->vadj->page_size = view->vadj->upper - view->vadj->lower;
        if( view->vadj->value < view->vadj->lower )
            view->vadj->value = view->vadj->lower;
        if( view->vadj->value+view->vadj->page_size > view->vadj->upper )
            view->vadj->value = view->vadj->upper - view->vadj->page_size;

        view->vadj->page_increment = view->vadj->page_size;
        view->vadj->step_increment = view->vadj->page_increment / 4;

        gtk_adjustment_changed( view->vadj );
    }

    view->lock_adjustments = FALSE;
}

static void
gv_view_area_adjustment (GtkAdjustment *adjustment,
                         GvViewArea    *view)
{
    gvgeocoord     xmin, ymin, width, height;
    static int local_lock = FALSE;

    g_return_if_fail (adjustment != NULL);
    g_return_if_fail (GTK_IS_ADJUSTMENT (adjustment));
    g_return_if_fail (view != NULL);
    g_return_if_fail (GV_IS_VIEW_AREA (view));

    if( !GTK_WIDGET_REALIZED(GTK_WIDGET(view)) )
        return;

    if( view->lock_adjustments || local_lock )
        return;

    if( view->vadj == NULL || view->hadj == NULL )
        return;

    xmin = view->hadj->value * view->state.flip_x;
    width = view->hadj->page_size * view->state.flip_x;

    if( view->state.flip_y > 0 )
    {
        ymin = (-1 * view->vadj->value) - view->vadj->page_size;
        height = view->vadj->page_size;
    }
    else
    {
        ymin = view->vadj->value;
        height = view->vadj->page_size;
    }

    view->lock_adjustments = TRUE;
    gv_view_area_fit_extents( view, xmin, ymin, width, height );
    view->lock_adjustments = FALSE;

    local_lock = TRUE;
    gv_view_area_update_adjustments( view );
    local_lock = FALSE;
}

static void
gv_view_area_disconnect (GtkAdjustment *adjustment,
                         GvViewArea    *view)
{
    g_return_if_fail (adjustment != NULL);
    g_return_if_fail (GTK_IS_ADJUSTMENT (adjustment));
    g_return_if_fail (view != NULL);
    g_return_if_fail (GV_IS_VIEW_AREA (view));

    if (adjustment == view->hadj)
        gv_view_area_set_adjustments (view, NULL, view->vadj);
    if (adjustment == view->vadj)
        gv_view_area_set_adjustments (view, view->hadj, NULL);
}

void
gv_view_area_set_adjustments (GvViewArea    *view,
                              GtkAdjustment *hadj,
                              GtkAdjustment *vadj)
{
    g_return_if_fail (view != NULL);
    g_return_if_fail (GV_VIEW_AREA (view));

    if (hadj)
        g_return_if_fail (GTK_IS_ADJUSTMENT (hadj));

    if (vadj)
        g_return_if_fail (GTK_IS_ADJUSTMENT (vadj));

    if (view->hadj && (view->hadj != hadj))
    {
        gtk_signal_disconnect_by_data (GTK_OBJECT (view->hadj), view);
        gtk_object_unref (GTK_OBJECT (view->hadj));
    }

    if (view->vadj && (view->vadj != vadj))
    {
        gtk_signal_disconnect_by_data (GTK_OBJECT (view->vadj), view);
        gtk_object_unref (GTK_OBJECT (view->vadj));
    }

    if( hadj == NULL )
        view->hadj = NULL;
    else if (view->hadj != hadj)
    {
        view->hadj = hadj;
        gtk_object_ref (GTK_OBJECT (view->hadj));
        gtk_object_sink (GTK_OBJECT (view->hadj));

        gtk_signal_connect (GTK_OBJECT (view->hadj), "changed",
                            (GtkSignalFunc) gv_view_area_adjustment,
                            view);
        gtk_signal_connect (GTK_OBJECT (view->hadj), "value_changed",
                            (GtkSignalFunc) gv_view_area_adjustment,
                            view);
        gtk_signal_connect (GTK_OBJECT (view->hadj), "disconnect",
                            (GtkSignalFunc) gv_view_area_disconnect,
                            view);

        gv_view_area_adjustment (hadj, view);
    }

    if( vadj == NULL )
        view->vadj = NULL;
    else if (view->vadj != vadj)
    {
        view->vadj = vadj;
        gtk_object_ref (GTK_OBJECT (view->vadj));
        gtk_object_sink (GTK_OBJECT (view->vadj));

        gtk_signal_connect (GTK_OBJECT (view->vadj), "changed",
                            (GtkSignalFunc) gv_view_area_adjustment,
                            view);
        gtk_signal_connect (GTK_OBJECT (view->vadj), "value_changed",
                            (GtkSignalFunc) gv_view_area_adjustment,
                            view);
        gtk_signal_connect (GTK_OBJECT (view->vadj), "disconnect",
                            (GtkSignalFunc) gv_view_area_disconnect,
                            view);
        gv_view_area_adjustment (vadj, view);
    }

    gv_view_area_update_adjustments( view );
}

/************************************************************************/
/*                        gv_view_area_set_raw()                        */
/*                                                                      */
/*      Try to reset whether this layer is in georeferenced or raw      */
/*      mode relative to the indicated raster layer.                    */
/************************************************************************/

int gv_view_area_set_raw( GvViewArea *view, GtkObject *ref_layer,
                          int raw_enable )

{
    GvRasterLayer *rlayer = NULL;
    gvgeocoord    xmin, ymin, xmax, ymax;
    double    pl_xmin, pl_ymin, pl_xmax, pl_ymax;

    if( ref_layer != NULL && GV_IS_RASTER_LAYER(ref_layer) )
        rlayer = GV_RASTER_LAYER(ref_layer);
    else
        rlayer = GV_RASTER_LAYER(gv_view_area_get_primary_raster(view));

    if( !raw_enable == !gv_view_area_get_raw(view, ref_layer) )
        return TRUE;

    /* For now we need a raster layer. */
    if( rlayer == NULL )
        return FALSE;

    /* Get the current view extents, and transform to raster PL coordinates.*/
    gv_view_area_get_extents( view, &xmin, &ymin, &xmax, &ymax );

    pl_xmin = xmin;
    pl_ymin = ymin;
    pl_xmax = xmax;
    pl_ymax = ymax;

    if( !gv_raster_layer_view_to_pixel( rlayer, &pl_xmin, &pl_ymin, NULL )
        || !gv_raster_layer_view_to_pixel( rlayer, &pl_xmax, &pl_ymax, NULL ) )
        return FALSE;

    /* Now force the raster layer to change it's mesh coordinate system. */
    if( !gv_raster_layer_set_raw( rlayer, raw_enable ) )
        return FALSE;

    /* Clear or set projection on view. */
    if( raw_enable || gv_data_get_projection(GV_DATA(rlayer)) == NULL )
        gv_view_area_set_projection( view, "PIXEL" );
    else
        gv_view_area_set_projection( view,
                                     gv_data_get_projection(GV_DATA(rlayer)) );

    /* Reset the view */
    if( !gv_raster_layer_pixel_to_view( rlayer, &pl_xmin, &pl_ymin, NULL )
        || !gv_raster_layer_pixel_to_view( rlayer, &pl_xmax, &pl_ymax, NULL ) )
        return FALSE;

    /*
     * A bunch of hacky stuff to ensure the correct orientation of the
     * new extents even if this requires some flipping.  We must always
     * keep an upper-right origin in pixel/line space (raw) and a lower left
     * origin in georeferenced space.
     */
    if( !raw_enable && pl_ymax < pl_ymin )
    {
        double  temp;

        temp = pl_ymax;
        pl_ymax = pl_ymin;
        pl_ymin = temp;
    }
    else if( raw_enable && pl_ymax > pl_ymin )
    {
        double  temp;

        temp = pl_ymax;
        pl_ymax = pl_ymin;
        pl_ymin = temp;
    }
    if( pl_xmax < pl_xmin )
    {
        double  temp;

        temp = pl_xmax;
        pl_xmax = pl_xmin;
        pl_xmin = temp;

    }

    if( !raw_enable )
        view->state.flip_y = 1.0;

    gv_view_area_fit_extents( view,
                              pl_xmin, pl_ymin,
                              pl_xmax - pl_xmin, pl_ymax - pl_ymin );

    return TRUE;
}

/************************************************************************/
/*                        gv_view_area_get_raw()                        */
/*                                                                      */
/*      Determine whether this view is in "raw" mode relative to the    */
/*      given layer.  TRUE is returned for raw mode.                    */
/************************************************************************/

int gv_view_area_get_raw( GvViewArea *view, GtkObject *ref_layer )

{
    GvRasterLayer *rlayer = NULL;

    if( ref_layer != NULL && GV_IS_RASTER_LAYER(ref_layer) )
        rlayer = GV_RASTER_LAYER(ref_layer);
    else
        rlayer = GV_RASTER_LAYER(gv_view_area_get_primary_raster(view));

    if( rlayer )
        return rlayer->mesh_is_raw;
    else
        return FALSE;
}

/************************************************************************/
/*                    gv_view_area_redraw_timeout()                     */
/*                                                                      */
/*      Returns TRUE if "quite a while" has elapsed since the last      */
/*      view redraw.  This is used by the various layers to decide      */
/*      if they should stop doing idle work.                            */
/************************************************************************/

int gv_view_area_redraw_timeout( GvViewArea *view )

{
    float   max_work_time;

    if( view->redraw_timer == NULL )
        return TRUE;

    max_work_time = MAX(0.25,MIN(2.0,view->last_draw_time*3));

    if( g_timer_elapsed(view->redraw_timer,NULL) > max_work_time )
    {
        g_timer_destroy( view->redraw_timer );
        view->redraw_timer = NULL;
        return TRUE;
    }
    else
        return FALSE;
}

/************************************************************************/
/*                   gv_view_area_pending_idle_work()                   */
/*                                                                      */
/*      Returns TRUE if any of the layers displayed on this view        */
/*      report they still have idle work pending, else it returns       */
/*      FALSE.                                                          */
/************************************************************************/

int gv_view_area_pending_idle_work( GvViewArea *view )

{
    GList *list;


    list = view->layers;
    while (list)
    {
    GvLayer *layer = (GvLayer*)list->data;
        if( layer->pending_idle )
            return TRUE;
    list = g_list_next(list);
    }

    return FALSE;
}

/************************************************************************/
/*                       gv_get_render_counter()                        */
/************************************************************************/

int gv_get_render_counter()

{
    return render_counter;
}

/************************************************************************/
/*                  gv_view_area_get_primary_raster()                   */
/************************************************************************/

GtkObject *gv_view_area_get_primary_raster( GvViewArea *view )

{
    GList *layer_list, *node;

    layer_list = gv_view_area_list_layers( view );

    for( node = layer_list; node != NULL; node = node->next )
    {
        GvLayer *layer;

        layer = GV_LAYER(node->data);
        if( gv_layer_is_visible(layer) && GV_IS_RASTER_LAYER( layer ) )
            return GTK_OBJECT(layer);
    }

    return NULL;
}

const char *
gv_view_area_get_property(GvViewArea *data, const char *name)
{
    return gv_properties_get( &(data->properties), name );
}

void
gv_view_area_set_property(GvViewArea *data, const char *name, const char *value)
{
    gv_properties_set( &(data->properties), name, value );
}

GvProperties *
gv_view_area_get_properties(GvViewArea *data)
{
    return &(data->properties);
}

