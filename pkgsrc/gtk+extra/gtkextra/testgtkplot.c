#include <math.h>
#include <stdio.h>
#include <gtk/gtk.h>
#include <gdk/gdk.h>
#include "icons.h"
#include "gtkplot.h"
#include "gtkplotdata.h"
#include "gtkplotbar.h"
#include "gtkplotcanvas.h"
#include "gtkplotps.h"
#include "gtkplotprint.h"

GdkPixmap *pixmap;
GtkWidget **plots;
GtkWidget **buttons;
GtkPlotData *dataset[5];
gint nlayers = 0;

static void put_child(GtkPlotCanvas *canvas, gdouble x, gdouble y);

void
quit ()
{
  gtk_main_quit();
}

gdouble function(GtkPlot *plot, GtkPlotData *data, gdouble x, gboolean *err)
{
 gdouble y;
 *err = FALSE;
 y = (-.5+.3*sin(3.*x)*sin(50.*x));
/* y = 100*pow(x,2);
 y = 1./(10*x);
*/

 return y;
}

gdouble gaussian(GtkPlot *plot, GtkPlotData *data, gdouble x, gboolean *err)
{
 gdouble y;
 *err = FALSE;
 y = .65*exp(-.5*pow(x-.5,2)/.02);

 return y;
}

gint
move_item(GtkWidget *widget, GtkPlotCanvasChild *item, 
          gdouble x, gdouble y, gpointer data)
{
  GtkPlotCanvas *canvas = NULL;

  canvas = GTK_PLOT_CANVAS(widget);

  if(item->type == GTK_PLOT_CANVAS_DATA){
        printf("MOVING DATA\n");
        printf("Active point: %d -> %f %f\n", 
                canvas->active_point, x, y);
	canvas->active_data->x[canvas->active_point] = x;
	canvas->active_data->y[canvas->active_point] = y;
  }
 
  return TRUE;
}

gint
select_item(GtkWidget *widget, GdkEvent *event, GtkPlotCanvasChild *item, 
            gpointer data)
{
  GtkWidget **widget_list = NULL;
  GtkWidget *active_widget = NULL;
  GtkWidget *canvas = NULL;
  gint n = 0;

  switch(item->type){
    case GTK_PLOT_CANVAS_TEXT:
        printf("Item selected: TEXT\n");
        break;
    case GTK_PLOT_CANVAS_TITLE:
        printf("Item selected: TITLE\n");
        break;
    case GTK_PLOT_CANVAS_LEGENDS:
        printf("Item selected: LEGENDS\n");
        break;
    case GTK_PLOT_CANVAS_PLOT:
        printf("Item selected: PLOT\n");
        break;
    case GTK_PLOT_CANVAS_AXIS:
        printf("Item selected: AXIS\n");
        break;
    case GTK_PLOT_CANVAS_PIXMAP:
        printf("Item selected: PIXMAP\n");
        break;
    case GTK_PLOT_CANVAS_MARKER:
        printf("Item selected: MARKER\n");
        break;
    case GTK_PLOT_CANVAS_DATA:
        printf("Item selected: DATA\n");
        printf("Active point: %d -> %f %f\n", 
                GTK_PLOT_CANVAS(widget)->active_point,
                GTK_PLOT_CANVAS(widget)->active_x, 
                GTK_PLOT_CANVAS(widget)->active_y); 

/*
        gtk_plot_data_add_marker(GTK_PLOT_CANVAS(widget)->active_data,
                                 GTK_PLOT_CANVAS(widget)->active_point);
        GTK_PLOT_CANVAS_UNSET_FLAGS(GTK_PLOT_CANVAS(widget),
				    GTK_PLOT_CANVAS_CAN_SELECT_POINT|
				    GTK_PLOT_CANVAS_CAN_DND_POINT);
        gtk_plot_canvas_paint(GTK_PLOT_CANVAS(widget));
        gtk_plot_canvas_refresh(GTK_PLOT_CANVAS(widget));
*/

        break;
    case GTK_PLOT_CANVAS_NONE:
        printf("Item selected: NONE\n");
        break;
    case GTK_PLOT_CANVAS_CUSTOM:
        printf("This is a custom child. Isn't it neat?\n");
        break;
    default:
        ;
  }

  canvas = GTK_WIDGET(widget);
  widget_list = plots;
  active_widget = GTK_WIDGET(gtk_plot_canvas_get_active_plot(GTK_PLOT_CANVAS(widget)));

  while(n < nlayers)
    {
      if(widget_list[n] == active_widget){
            gtk_plot_canvas_set_active_plot(GTK_PLOT_CANVAS(canvas),
                                            GTK_PLOT(plots[n]));  
            GTK_BUTTON(buttons[n])->button_down = TRUE;
            GTK_TOGGLE_BUTTON(buttons[n])->active = TRUE;
            gtk_widget_set_state(buttons[n], GTK_STATE_ACTIVE);
      }else{
            GTK_BUTTON(buttons[n])->button_down = FALSE;
            GTK_TOGGLE_BUTTON(buttons[n])->active = FALSE;
            gtk_widget_set_state(buttons[n], GTK_STATE_NORMAL);
      }
      gtk_widget_queue_draw(buttons[n]);
      
      n++;
    }


  return TRUE;
}

gint
activate_plot(GtkWidget *widget, gpointer data)
{
  GtkWidget **widget_list = NULL;
  GtkWidget *active_widget = NULL;
  GtkWidget *canvas = NULL;
  gint n = 0;

  canvas = GTK_WIDGET(data);
  widget_list = buttons;
  active_widget = widget;

  while(n < nlayers)
    {
      if(widget_list[n] == active_widget){
            gtk_plot_canvas_set_active_plot(GTK_PLOT_CANVAS(canvas),
                                            GTK_PLOT(plots[n]));  
            GTK_BUTTON(buttons[n])->button_down = TRUE;
            GTK_TOGGLE_BUTTON(buttons[n])->active = TRUE;
            gtk_widget_set_state(buttons[n], GTK_STATE_ACTIVE);
      }else{
            GTK_BUTTON(buttons[n])->button_down = FALSE;
            GTK_TOGGLE_BUTTON(buttons[n])->active = FALSE;
            gtk_widget_set_state(buttons[n], GTK_STATE_NORMAL);
      }
      gtk_widget_queue_draw(buttons[n]);
      
      n++;
    }

  return TRUE;
}


GtkWidget *
new_layer(GtkWidget *canvas)
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

 gtk_signal_connect(GTK_OBJECT(buttons[nlayers-1]), "toggled",
                    (GtkSignalFunc) activate_plot, canvas);

 plots[nlayers-1] = gtk_plot_new_with_size(NULL, .5, .25);
 gtk_widget_show(plots[nlayers-1]);

 activate_plot(buttons[nlayers-1],canvas);

 return plots[nlayers-1];
}

gboolean
my_tick_label(GtkPlotAxis *axis, gdouble *tick_value, gchar *label, gpointer data)
{
  gboolean return_value = FALSE;

  if(*tick_value == 0.0){
    g_snprintf(label, 100, "custom label at 0.0");
    return_value = TRUE;
  }
  return return_value;
}

void
build_example1(GtkWidget *active_plot)
{
 GdkColor color;
 GtkPlotAxis *axis;

 static gdouble px1[]={0., 0.2, 0.4, 0.6, 0.8, 1.0};
 static gdouble py1[]={.2, .4, .5, .35, .30, .40};
 static gdouble dx1[]={.2, .2, .2, .2, .2, .2};
 static gdouble dy1[]={.1, .1, .1, .1, .1, .1};

 static gdouble px2[]={0., -0.2, -0.4, -0.6, -0.8, -1.0};
 static gdouble py2[]={.2, .4, .5, .35, .30, .40};
 static gdouble dx2[]={.2, .2, .2, .2, .2, .2};
 static gdouble dy2[]={.1, .1, .1, .1, .1, .1};

 /* CUSTOM TICK LABELS */

 gtk_plot_axis_use_custom_tick_labels(GTK_PLOT(active_plot), GTK_PLOT_AXIS_RIGHT, TRUE);
 axis = gtk_plot_get_axis(GTK_PLOT(active_plot), GTK_PLOT_AXIS_RIGHT);
 gtk_signal_connect(GTK_OBJECT(axis), "tick_label", 
                    GTK_SIGNAL_FUNC(my_tick_label), NULL);

 dataset[0] = GTK_PLOT_DATA(gtk_plot_data_new());
 gtk_plot_add_data(GTK_PLOT(active_plot), dataset[0]);
 gtk_widget_show(GTK_WIDGET(dataset[0]));
 gtk_plot_data_set_points(dataset[0], px1, py1, dx1, dy1, 6);
 gdk_color_parse("red", &color);
 gdk_color_alloc(gdk_colormap_get_system(), &color); 

 gtk_plot_data_set_symbol(dataset[0],
                             GTK_PLOT_SYMBOL_DIAMOND,
			     GTK_PLOT_SYMBOL_EMPTY,
                             10, 2, &color, &color);
 gtk_plot_data_set_line_attributes(dataset[0],
                                      GTK_PLOT_LINE_SOLID,
                                      1, &color);

 gtk_plot_data_set_connector(dataset[0], GTK_PLOT_CONNECT_SPLINE);

 gtk_plot_data_show_yerrbars(dataset[0]);
 gtk_plot_data_set_legend(dataset[0], "Spline + EY");

 dataset[3] = GTK_PLOT_DATA(gtk_plot_data_new());
 gtk_plot_add_data(GTK_PLOT(active_plot), dataset[3]);
 gtk_widget_show(GTK_WIDGET(dataset[3]));
 gtk_plot_data_set_points(dataset[3], px2, py2, dx2, dy2, 6);
 gtk_plot_data_set_symbol(dataset[3],
                             GTK_PLOT_SYMBOL_SQUARE,
			     GTK_PLOT_SYMBOL_OPAQUE,
                             8, 2, 
                             &active_plot->style->black,
                             &active_plot->style->black);
 gtk_plot_data_set_line_attributes(dataset[3],
                                      GTK_PLOT_LINE_SOLID,
                                      4, &color);
 gtk_plot_data_set_connector(dataset[3], GTK_PLOT_CONNECT_STRAIGHT);

 gtk_plot_data_set_x_attributes(dataset[3], 
                                GTK_PLOT_LINE_SOLID,
                                0, &active_plot->style->black);
 gtk_plot_data_set_y_attributes(dataset[3], 
                                GTK_PLOT_LINE_SOLID,
                                0, &active_plot->style->black);

 gtk_plot_data_set_legend(dataset[3], "Line + Symbol");

 
 gdk_color_parse("blue", &color);
 gdk_color_alloc(gdk_colormap_get_system(), &color); 

 dataset[1] = gtk_plot_add_function(GTK_PLOT(active_plot), (GtkPlotFunc)function);
 gtk_widget_show(GTK_WIDGET(dataset[1]));
 gtk_plot_data_set_line_attributes(dataset[1],
                                      GTK_PLOT_LINE_SOLID,
                                      0, &color);

 gtk_plot_data_set_legend(dataset[1], "Function Plot");
}

void
build_example2(GtkWidget *active_plot)
{
 GdkColor color;
 static double px2[] = {.1, .2, .3, .4, .5, .6, .7, .8};
 static double py2[] = {.012, .067, .24, .5, .65, .5, .24, .067};
 static double dx2[] = {.1, .1, .1, .1, .1, .1, .1, .1};

 dataset[4] = gtk_plot_add_function(GTK_PLOT(active_plot), (GtkPlotFunc)gaussian);
 gtk_widget_show(GTK_WIDGET(dataset[4]));
 gdk_color_parse("dark green", &color);
 gdk_color_alloc(gdk_colormap_get_system(), &color); 
 gtk_plot_data_set_line_attributes(dataset[4],
                                      GTK_PLOT_LINE_DASHED,
                                      2, &color);

 gtk_plot_data_set_legend(dataset[4], "Gaussian");


 gdk_color_parse("blue", &color);
 gdk_color_alloc(gdk_colormap_get_system(), &color); 
/*
 GTK_PLOT(active_plot)->xscale = GTK_PLOT_SCALE_LOG10;
*/

 dataset[2] = GTK_PLOT_DATA(gtk_plot_bar_new(GTK_ORIENTATION_VERTICAL));
 gtk_plot_add_data(GTK_PLOT(active_plot), dataset[2]);
 gtk_widget_show(GTK_WIDGET(dataset[2]));
 gtk_plot_data_set_points(dataset[2], px2, py2, dx2, NULL, 8);

 gtk_plot_data_set_symbol(dataset[2],
                          GTK_PLOT_SYMBOL_NONE,
			  GTK_PLOT_SYMBOL_OPAQUE,
                          10, 2, &color, &color);

 gtk_plot_data_set_line_attributes(dataset[2],
                                   GTK_PLOT_LINE_NONE,
                                   1, &color);
 gtk_plot_data_set_legend(dataset[2], "V Bars");

}

int main(int argc, char *argv[]){
 GtkWidget *window1;
 GtkWidget *vbox1;
 GtkWidget *scrollw1;
 GtkWidget *active_plot;
 GtkWidget *canvas;
 GtkPlotCanvasChild *text;
 GdkColor color;
 gint page_width, page_height;
 gfloat scale = 1.;
 
 page_width = GTK_PLOT_LETTER_W * scale;
 page_height = GTK_PLOT_LETTER_H * scale;
 
 gtk_init(&argc,&argv);

 window1=gtk_window_new(GTK_WINDOW_TOPLEVEL);
 gtk_window_set_title(GTK_WINDOW(window1), "GtkPlot Demo");
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

 active_plot = new_layer(canvas);
/*
 gtk_plot_clip_data(GTK_PLOT(active_plot), TRUE);
*/
 gtk_plot_set_range(GTK_PLOT(active_plot), -1., 1., -1., 1.4);
 gtk_plot_legends_move(GTK_PLOT(active_plot), .500, .05);
 gtk_plot_set_legends_border(GTK_PLOT(active_plot), 0, 0);
 gtk_plot_axis_hide_title(GTK_PLOT(active_plot), GTK_PLOT_AXIS_TOP);
 gtk_plot_axis_show_ticks(GTK_PLOT(active_plot), 3, 15, 3);
 gtk_plot_axis_set_ticks(GTK_PLOT(active_plot), GTK_PLOT_AXIS_X, 1., 1);
 gtk_plot_axis_set_ticks(GTK_PLOT(active_plot), GTK_PLOT_AXIS_Y, 1., 1);
 gtk_plot_axis_set_visible(GTK_PLOT(active_plot), GTK_PLOT_AXIS_TOP, TRUE);
 gtk_plot_axis_set_visible(GTK_PLOT(active_plot), GTK_PLOT_AXIS_RIGHT, TRUE);
 gtk_plot_x0_set_visible(GTK_PLOT(active_plot), TRUE);
 gtk_plot_y0_set_visible(GTK_PLOT(active_plot), TRUE);
 gtk_plot_canvas_add_plot(GTK_PLOT_CANVAS(canvas), GTK_PLOT(active_plot), .15, .06);
 gtk_plot_axis_set_labels_suffix(GTK_PLOT(active_plot), GTK_PLOT_AXIS_LEFT, "%");
 gtk_widget_show(active_plot);

 build_example1(active_plot);

 active_plot = new_layer(canvas);
 gdk_color_parse("light yellow", &color);
 gdk_color_alloc(gtk_widget_get_colormap(active_plot), &color);
 gtk_plot_set_background(GTK_PLOT(active_plot), &color);

 gdk_color_parse("light blue", &color);
 gdk_color_alloc(gtk_widget_get_colormap(canvas), &color);
 gtk_plot_legends_set_attributes(GTK_PLOT(active_plot),
                                 NULL, 0,
				 NULL,
                                 &color);
 gtk_plot_set_range(GTK_PLOT(active_plot), 0. , 1., 0., .85);
/*
 gtk_plot_set_range(GTK_PLOT(active_plot), 0.1 , 100., 0., .85);
 gtk_plot_set_xscale(GTK_PLOT(active_plot), GTK_PLOT_SCALE_LOG10);
*/
 gtk_plot_axis_set_visible(GTK_PLOT(active_plot), GTK_PLOT_AXIS_TOP, TRUE);
 gtk_plot_axis_set_visible(GTK_PLOT(active_plot), GTK_PLOT_AXIS_RIGHT, TRUE);
 gtk_plot_grids_set_visible(GTK_PLOT(active_plot), TRUE, TRUE, TRUE, TRUE);
 gtk_plot_canvas_add_plot(GTK_PLOT_CANVAS(canvas), GTK_PLOT(active_plot), .15, .4);
 gtk_plot_axis_hide_title(GTK_PLOT(active_plot), GTK_PLOT_AXIS_TOP);
 gtk_plot_axis_hide_title(GTK_PLOT(active_plot), GTK_PLOT_AXIS_RIGHT);
 gtk_plot_set_legends_border(GTK_PLOT(active_plot), 2, 3);
 gtk_plot_legends_move(GTK_PLOT(active_plot), .58, .05);
 gtk_widget_show(active_plot);

 build_example2(active_plot);

 gtk_signal_connect(GTK_OBJECT(canvas), "select_item",
                    (GtkSignalFunc) select_item, NULL);

 gtk_signal_connect(GTK_OBJECT(canvas), "move_item",
                    (GtkSignalFunc) move_item, NULL);


 gtk_plot_canvas_put_text(GTK_PLOT_CANVAS(canvas), .40, .020, 
                          "Times-BoldItalic", 16, 0, NULL, NULL, TRUE,
                          GTK_JUSTIFY_CENTER,
                          "DnD titles, legends and plots");
 gtk_plot_canvas_put_text(GTK_PLOT_CANVAS(canvas), .40, .72,  
                          "Times-Roman", 16, 0, NULL, NULL, TRUE,
                          GTK_JUSTIFY_CENTER,
                          "You can use \\ssubscripts\\b\\b\\b\\b\\b\\b\\b\\b\\b\\b\\N\\Ssuperscripts");

 text = gtk_plot_canvas_put_text(GTK_PLOT_CANVAS(canvas), .40, .755,  
                          "Times-Roman", 16, 0, NULL, NULL, TRUE,
                          GTK_JUSTIFY_CENTER, 
                          "Format text mixing \\Bbold \\N\\i, italics, \\ggreek \\4\\N and \\+different fonts");

 gtk_plot_text_set_border((GtkPlotText*)text->data, 
                           GTK_PLOT_BORDER_SHADOW, 2, 0, 2);

 gtk_plot_text_set_border(&GTK_PLOT(active_plot)->left->title, 
                          GTK_PLOT_BORDER_SHADOW, 2, 0, 2);

 gtk_widget_show(window1);
 put_child(GTK_PLOT_CANVAS(canvas), .5, .5);

/*
 gtk_plot_export_ps (GTK_PLOT(active_plot), "demo.ps", 0, 0, GTK_PLOT_LETTER);
*/
 gtk_plot_canvas_export_ps(GTK_PLOT_CANVAS(canvas), "demoplot.ps", 0, 0, 
                           GTK_PLOT_LETTER);
 
 gtk_main();

 return(0);
}

static void
put_child(GtkPlotCanvas *canvas, gdouble x, gdouble y)
{
  GdkColormap *colormap;
  GdkBitmap *mask;

  colormap = gdk_colormap_get_system();

  pixmap = gdk_pixmap_colormap_create_from_xpm_d(NULL, colormap, &mask, NULL,
                                                 plot_icon2);

  gtk_plot_canvas_put_pixmap(canvas, pixmap, x, y); 
  gdk_bitmap_unref(mask);
}
