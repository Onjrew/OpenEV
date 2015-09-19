/******************************************************************************
 * $Id: gvrasterlut.h,v 1.15 2005/08/30 12:58:56 andrey_kiselev Exp $
 *
 * Project:  OpenEV
 * Purpose:  Compute, and apply LUT to GvRaster.
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
 * $Log: gvrasterlut.h,v $
 * Revision 1.15  2005/08/30 12:58:56  andrey_kiselev
 * Make the return value of unsigned gv_raster_layer_lut_get().
 *
 * Revision 1.14  2004/06/23 14:35:05  gmwalter
 * Added support for multi-band complex imagery.
 *
 * Revision 1.13  2001/10/17 16:23:52  warmerda
 * added support for composing complex lut and pct
 *
 * Revision 1.12  2001/07/24 21:21:45  warmerda
 * added EV style phase colormap
 *
 * Revision 1.11  2000/06/20 13:27:08  warmerda
 * added standard headers
 *
 */

#ifndef _GV_RASTER_LAYER_LUT_H_
#define _GV_RASTER_LAYER_LUT_H_

#include <gtk/gtk.h>
#include "gvrasterlayer.h"

enum {
    GV_RASTER_LAYER_LUT_MAGNITUDE,
    GV_RASTER_LAYER_LUT_PHASE_ANGLE,
    GV_RASTER_LAYER_LUT_SCALAR,
    GV_RASTER_LAYER_LUT_REAL,
    GV_RASTER_LAYER_LUT_IMAGINARY
};

enum {
    GV_RASTER_LAYER_LUT_NONE = 0,
    GV_RASTER_LAYER_LUT_1D,
    GV_RASTER_LAYER_LUT_2D
};

typedef struct _GvRasterLayerLutInterpolate GvRasterLayerLutInterpolate;

struct _GvRasterLayerLutInterpolate {
    guchar color[4];
    gint index;
};

int gv_raster_layer_lut_color_wheel_new_ev( 
    GvRasterLayer *layer, gint set_phase, gint set_magnitude );
int gv_raster_layer_lut_color_wheel_new( GvRasterLayer *layer, gint h_type, gfloat h_param, gint s_type, gfloat s_param, gint v_type, gfloat v_param );
int gv_raster_layer_lut_color_wheel_1d_new( GvRasterLayer *layer, float s, float v, float offset );
int gv_raster_layer_lut_interpolated_new( GvRasterLayer *layer, GvRasterLayerLutInterpolate *color_pair, int offset );
int gv_raster_layer_lut_new( GvRasterLayer *layer, gint h_type, gfloat h_param, gint s_type, gfloat s_param, gint v_type, gfloat v_param );
int gv_raster_layer_lut_put( GvRasterLayer *layer, guchar *lut, gint height );
unsigned char *gv_raster_layer_lut_get( GvRasterLayer *layer,
                                        int *width, int *height,
                                        int rgba_complex);
int gv_raster_layer_lut_compose( GvRasterLayer *layer );
long gv_raster_layer_lut_type_get( GvRasterLayer *layer );
int gv_raster_layer_apply_gdal_color_table( GvRasterLayer *layer,
                                            GDALColorTableH color_table );

#endif
