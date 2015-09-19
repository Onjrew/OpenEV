#include <math.h>
#include <stdio.h>
#include <gtk/gtk.h>
#include <gdk/gdk.h>
#include "gtkplot.h"
#include "gtkplot3d.h"
#include "gtkplotdata.h"
#include "gtkplotsurface.h"
#include "gtkplotcanvas.h"
#include "gtkplotcsurface.h"
#include "gtkplotps.h"
#include "gtkplotprint.h"

GdkPixmap *pixmap=NULL;
GtkWidget **plots;
GtkWidget **buttons;
GtkPlotData *dataset[5];
GtkPlot3D *plot3d;
gint nlayers = 0;

void
quit ()
{
  gtk_main_quit();
}

gdouble function(GtkPlot *plot, 
                 GtkPlotData *data, 
                 gdouble x, gdouble y, gboolean *err)
{
 gdouble z;
 *err = FALSE;

 z = cos(((x-0.5)*(x-0.5) + (y-0.5)*(y-0.5))*24) / 3. + .5;
 return z;
}


GtkWidget *
new_layer(GtkWidget *canvas, GtkType type)
{
 gchar label[10];

 nlayers++;

 buttons = (GtkWidget **)g_realloc(buttons, nlayers * sizeof(GtkWidget *));
 plots = (GtkWidget **)g_realloc(plots, nlayers * sizeof(GtkWidget *));

 sprintf(label, "%d", nlayers);
 
 buttons[nlayers-1] = gtk_toggle_button_new_with_label(label);
/* gtk_button_set_relief(GTK_BUTTON(buttons[nlayers-1]), GTK_RELIEF_NONE);
*/
 gtk_widget_set_usize(buttons[nlayers-1], 20, 20);
 gtk_fixed_put(GTK_FIXED(canvas), buttons[nlayers-1], (nlayers-1)*20, 0);
 gtk_widget_show(buttons[nlayers-1]);

 if(type == GTK_TYPE_PLOT3D)
   plots[nlayers-1] = gtk_plot3d_new_with_size(NULL, .50, .50);
 else
   plots[nlayers-1] = gtk_plot_new_with_size(NULL, .40, .40);

 gtk_widget_show(plots[nlayers-1]);

 return plots[nlayers-1];
}

void
rotate_x(GtkWidget *button, gpointer data)
{
 GtkPlot3D *active_plot;
 GtkPlot *plot;

 plot = gtk_plot_canvas_get_active_plot(GTK_PLOT_CANVAS(data));

 if(GTK_IS_PLOT3D(plot)) 
     active_plot = GTK_PLOT3D(plot);
 else
     return;

 gtk_plot3d_rotate_x(active_plot, 10.);

 gtk_plot_canvas_paint(GTK_PLOT_CANVAS(data));
 gtk_plot_canvas_refresh(GTK_PLOT_CANVAS(data));
}

void
rotate_y(GtkWidget *button, gpointer data)
{
 GtkPlot3D *active_plot;
 GtkPlot *plot;

 plot = gtk_plot_canvas_get_active_plot(GTK_PLOT_CANVAS(data));

 if(GTK_IS_PLOT3D(plot)) 
     active_plot = GTK_PLOT3D(plot);
 else
     return;

 gtk_plot3d_rotate_y(active_plot, 10.);

 gtk_plot_canvas_paint(GTK_PLOT_CANVAS(data));
 gtk_plot_canvas_refresh(GTK_PLOT_CANVAS(data));
}

void
rotate_z(GtkWidget *button, gpointer data)
{
 GtkPlot3D *active_plot;
 GtkPlot *plot;

 plot = gtk_plot_canvas_get_active_plot(GTK_PLOT_CANVAS(data));

 if(GTK_IS_PLOT3D(plot)) 
     active_plot = GTK_PLOT3D(plot);
 else
     return;

 gtk_plot3d_rotate_z(active_plot, 10.);

 gtk_plot_canvas_paint(GTK_PLOT_CANVAS(data));
 gtk_plot_canvas_refresh(GTK_PLOT_CANVAS(data));
}


int main(int argc, char *argv[]){

 GtkWidget *window1;
 GtkWidget *vbox1;
 GtkWidget *scrollw1;
 GtkWidget *active_plot;
 GtkWidget *canvas;
 GtkWidget *button;
 GtkWidget *surface;
 gint page_width, page_height;
 gfloat scale = 1.;
 gint n;
 static gdouble *x, *y, *z;
 
 page_width = GTK_PLOT_LETTER_W * scale;
 page_height = GTK_PLOT_LETTER_H * scale;
 
 gtk_init(&argc,&argv);

 window1=gtk_window_new(GTK_WINDOW_TOPLEVEL);
 gtk_window_set_title(GTK_WINDOW(window1), "GtkPlot3D Demo");
 gtk_widget_set_usize(window1,550,650);
 gtk_container_border_width(GTK_CONTAINER(window1),0);

 gtk_signal_connect (GTK_OBJECT (window1), "destroy",
		     GTK_SIGNAL_FUNC (quit), NULL);

 vbox1=gtk_vbox_new(FALSE,0);
 gtk_container_add(GTK_CONTAINER(window1),vbox1);
 gtk_widget_show(vbox1);

 scrollw1=gtk_scrolled_window_new(NULL, NULL);
 gtk_container_border_width(GTK_CONTAINER(scrollw1),0);
 gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrollw1),
				GTK_POLICY_ALWAYS,GTK_POLICY_ALWAYS);
 gtk_box_pack_start(GTK_BOX(vbox1),scrollw1, TRUE, TRUE,0);
 gtk_widget_show(scrollw1);

 canvas = gtk_plot_canvas_new(page_width, page_height, 1.);
 GTK_PLOT_CANVAS_SET_FLAGS(GTK_PLOT_CANVAS(canvas), GTK_PLOT_CANVAS_DND_FLAGS);
 gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(scrollw1), canvas);

/*
 gdk_color_parse("light blue", &color);
 gdk_color_alloc(gtk_widget_get_colormap(canvas), &color);
 gtk_plot_canvas_set_background(GTK_PLOT_CANVAS(canvas), &color);
*/

 gtk_widget_show(canvas);

 plot3d = GTK_PLOT3D(new_layer(canvas, GTK_TYPE_PLOT3D));
 gtk_plot_canvas_add_plot(GTK_PLOT_CANVAS(canvas), GTK_PLOT(plot3d), .16, .02);
 gtk_widget_show(GTK_WIDGET(plot3d));

 x = (gdouble *)g_malloc(1600 * sizeof(gdouble));
 y = (gdouble *)g_malloc(1600 * sizeof(gdouble));
 z = (gdouble *)g_malloc(1600 * sizeof(gdouble));
 n = 0;

/*
 for(nx = 0; nx < 40; nx++)
   for(ny = 0; ny < 40; ny++)
   {
     x[n]=0.025*(gdouble)nx;
     y[n]=0.025*(gdouble)ny;
     z[n]=cos(((x[n]-0.5)*(x[n]-0.5) + (y[n]-0.5)*(y[n]-0.5))*24) / 4. + .5;
     n++;
   }

 surface = gtk_plot_csurface_new();
 gtk_plot_surface_set_points(GTK_PLOT_SURFACE(surface), 
                             x, y, z, NULL, NULL, NULL, 40, 40); 
 gtk_plot_data_set_legend(GTK_PLOT_DATA(surface), "cos ((r-r\\s0\\N)\\S2\\N)");
*/
/*
 for(nx = 0; nx < 10; nx++)
   for(ny = 0; ny < 10; ny++)
   {
     x[n]=(gdouble)0.1*(gdouble)nx;
     y[n]=(gdouble)0.1*(gdouble)ny;
     z[n]=(x[n]-0.5)*(x[n]-0.5) + (y[n]-0.5)*(y[n]-0.5);
     z[n]=x[n]*x[n] + y[n]*y[n];
     n++;
   }

 surface = gtk_plot_csurface_new();
 gtk_plot_surface_set_points(GTK_PLOT_SURFACE(surface), 
                             x, y, z, NULL, NULL, NULL, 10, 10); 

*/

 gtk_plot3d_axis_set_minor_ticks(GTK_PLOT3D(plot3d), GTK_PLOT_AXIS_X, 3);
 gtk_plot3d_axis_set_minor_ticks(GTK_PLOT3D(plot3d), GTK_PLOT_AXIS_Y, 3);

 gtk_plot3d_minor_grids_set_visible(GTK_PLOT3D(plot3d), FALSE, FALSE, FALSE);


 surface = gtk_plot_csurface_new_function((GtkPlotFunc3D) function);

 gtk_plot_surface_set_xstep(GTK_PLOT_SURFACE(surface), .025);
 gtk_plot_surface_set_ystep(GTK_PLOT_SURFACE(surface), .025);

/*
 gtk_plot_surface_set_xstep(GTK_PLOT_SURFACE(surface), .1);
 gtk_plot_surface_set_ystep(GTK_PLOT_SURFACE(surface), .1);
*/

 gtk_plot_data_set_legend(GTK_PLOT_DATA(surface), "cos ((r-r\\s0\\N)\\S2\\N)");

 gtk_plot_add_data(GTK_PLOT(plot3d), GTK_PLOT_DATA(surface));
 gtk_widget_show(surface);

 gtk_plot_data_set_gradient(GTK_PLOT_DATA(surface), .2, .8, 6, 3);
/* 
 gtk_plot_surface_set_transparent(GTK_PLOT_SURFACE(surface), TRUE);
*/
 gtk_plot_csurface_set_lines_visible(GTK_PLOT_CSURFACE(surface), FALSE);
/*******************/
 active_plot = new_layer(canvas, GTK_TYPE_PLOT);
 gtk_plot_canvas_add_plot(GTK_PLOT_CANVAS(canvas), GTK_PLOT(active_plot), .26, .56);

 gtk_plot_axis_set_minor_ticks(GTK_PLOT(active_plot), GTK_PLOT_AXIS_LEFT, 1);
 gtk_plot_axis_set_minor_ticks(GTK_PLOT(active_plot), GTK_PLOT_AXIS_BOTTOM, 1);

 surface = gtk_plot_csurface_new_function((GtkPlotFunc3D) function);

 gtk_plot_surface_set_xstep(GTK_PLOT_SURFACE(surface), .025);
 gtk_plot_surface_set_ystep(GTK_PLOT_SURFACE(surface), .025);

/*
 gtk_plot_surface_set_xstep(GTK_PLOT_SURFACE(surface), .1);
 gtk_plot_surface_set_ystep(GTK_PLOT_SURFACE(surface), .1);
*/

 gtk_plot_data_set_legend(GTK_PLOT_DATA(surface), "cos ((r-r\\s0\\N)\\S2\\N)");
 gtk_plot_add_data(GTK_PLOT(active_plot), GTK_PLOT_DATA(surface));
 gtk_widget_show(surface);

 gtk_plot_data_set_gradient(GTK_PLOT_DATA(surface), .2, .8, 6, 0);

 gtk_plot_surface_set_grid_visible(GTK_PLOT_SURFACE(surface), FALSE);
 gtk_plot_csurface_set_lines_only(GTK_PLOT_CSURFACE(surface), TRUE);

/*
 gtk_plot_csurface_set_lines_visible(GTK_PLOT_CSURFACE(surface), FALSE);
*/


 button = gtk_button_new_with_label("Rotate X");
 gtk_fixed_put(GTK_FIXED(canvas), button, 80, 0);
 gtk_widget_show(button);

 gtk_signal_connect(GTK_OBJECT(button), "clicked",
                    GTK_SIGNAL_FUNC(rotate_x), canvas);

 button = gtk_button_new_with_label("Rotate Y");
 gtk_fixed_put(GTK_FIXED(canvas), button, 160, 0);
 gtk_widget_show(button);

 gtk_signal_connect(GTK_OBJECT(button), "clicked",
                    GTK_SIGNAL_FUNC(rotate_y), canvas);

 button = gtk_button_new_with_label("Rotate Z");
 gtk_fixed_put(GTK_FIXED(canvas), button, 240, 0);
 gtk_widget_show(button);

 gtk_signal_connect(GTK_OBJECT(button), "clicked",
                    GTK_SIGNAL_FUNC(rotate_z), canvas);

 gtk_widget_show(window1);

 gtk_plot_canvas_export_ps(GTK_PLOT_CANVAS(canvas), "democsurface.ps", 0, 0,
                           GTK_PLOT_LETTER);

 gtk_main();

 return(0);
}

