/******************************************************************************
 * $Id: gvrasterlut.c,v 1.31 2005/08/30 12:58:56 andrey_kiselev Exp $
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
 * $Log: gvrasterlut.c,v $
 * Revision 1.31  2005/08/30 12:58:56  andrey_kiselev
 * Make the return value of unsigned gv_raster_layer_lut_get().
 *
 * Revision 1.30  2004/06/23 14:35:05  gmwalter
 * Added support for multi-band complex imagery.
 *
 * Revision 1.29  2003/03/07 17:03:03  gmwalter
 * Move last_complex_lut property setting down to c-level, fix magphase indeterminate
 * phase colour setting.
 *
 * Revision 1.28  2003/02/26 16:43:00  warmerda
 * don't crash on PCTs larger than 256 entries
 *
 * Revision 1.27  2002/05/27 19:34:02  warmerda
 * set the center pixel to red for phase lut
 *
 * Revision 1.26  2001/10/17 16:23:52  warmerda
 * added support for composing complex lut and pct
 *
 * Revision 1.25  2001/08/23 02:23:28  warmerda
 * enable alpha blending if palette has any non-255 alpha values
 *
 * Revision 1.24  2001/07/24 21:21:45  warmerda
 * added EV style phase colormap
 *
 * Revision 1.23  2001/01/30 19:34:11  warmerda
 * added gv_raster_layer_purge_all_textures calls
 *
 * Revision 1.22  2000/08/25 20:10:18  warmerda
 * modified phase to colour mapping to match EV
 *
 * Revision 1.21  2000/07/13 13:51:55  warmerda
 * make 2d color luts in greyscale
 *
 * Revision 1.20  2000/07/07 14:29:23  srawlin
 * removed debug print statement
 *
 * Revision 1.19  2000/06/27 21:26:04  warmerda
 * removed use of invalidated
 *
 * Revision 1.18  2000/06/23 12:56:18  warmerda
 * added multiple GvRasterSource support
 *
 * Revision 1.17  2000/06/20 14:32:06  warmerda
 * fixed free/g_new mismatch
 *
 * Revision 1.16  2000/06/20 13:26:55  warmerda
 * added standard headers
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <gtk/gtk.h>
#include "gvrastertypes.h"
#include "gvrasterlut.h"
#include "gdal.h"

#ifndef M_PI
#  define M_PI 3.14159265358979323846
#endif

static void gv_raster_layer_lut_hsv_to_rgb(  float h, float s, float v, float *r, float *g, float *b );
static int gv_raster_layer_lut_interpolate( guchar *lut, guchar start_color[4], guint start_index, guchar end_color[4], guint end_index );


static unsigned char *phase_lut = "\377\000\000\377\000\000\377\000\000\377\000\000\377\017\000\377\017\000\377\017\000\377\017\000\375\043\000\375\043\000\375\043\000\375\043\000\371\067\000\371\067\000\371\067\000\371\067\000\364\112\000\364\112\000\364\112\000\364\112\000\357\130\000\357\130\000\357\130\000\357\130\000\350\153\000\350\153\000\350\153\000\350\153\000\336\175\000\336\175\000\336\175\000\336\175\000\324\216\000\324\216\000\324\216\000\324\216\000\313\232\000\313\232\000\313\232\000\313\232\000\277\251\000\277\251\000\277\251\000\277\251\000\261\270\000\261\270\000\261\270\000\261\270\000\242\305\000\242\305\000\242\305\000\242\305\000\226\316\000\226\316\000\226\316\000\226\316\000\205\331\000\205\331\000\205\331\000\205\331\000\164\343\000\164\343\000\164\343\000\164\343\000\142\354\000\142\354\000\142\354\000\142\354\000\124\361\000\124\361\000\124\361\000\124\361\000\074\370\000\074\370\000\074\370\000\074\370\000\050\374\000\050\374\000\050\374\000\050\374\000\031\376\000\031\376\000\031\376\000\031\376\000\005\377\000\005\377\000\005\377\000\005\377\000\000\377\017\000\377\017\000\377\017\000\377\017\000\375\043\000\375\043\000\375\043\000\375\043\000\372\062\000\372\062\000\372\062\000\372\062\000\365\105\000\365\105\000\365\105\000\365\105\000\357\130\000\357\130\000\357\130\000\357\130\000\350\153\000\350\153\000\350\153\000\350\153\000\341\170\000\341\170\000\341\170\000\341\170\000\327\211\000\327\211\000\327\211\000\327\211\000\313\232\000\313\232\000\313\232\000\313\232\000\277\251\000\277\251\000\277\251\000\277\251\000\264\264\000\264\264\000\264\264\000\264\264\000\246\302\000\246\302\000\246\302\000\246\302\000\226\316\000\226\316\000\226\316\000\226\316\000\201\334\000\201\334\000\201\334\000\201\334\000\164\343\000\164\343\000\164\343\000\164\343\000\142\354\000\142\354\000\142\354\000\142\354\000\117\363\000\117\363\000\117\363\000\117\363\000\074\370\000\074\370\000\074\370\000\074\370\000\055\373\000\055\373\000\055\373\000\055\373\000\031\376\000\031\376\000\031\376\000\031\376\000\005\377\000\005\377\000\005\377\000\005\377\017\000\377\017\000\377\017\000\377\017\000\377\036\000\375\036\000\375\036\000\375\036\000\375\062\000\372\062\000\372\062\000\372\062\000\372\105\000\365\105\000\365\105\000\365\105\000\365\130\000\357\130\000\357\130\000\357\130\000\357\146\000\352\146\000\352\146\000\352\146\000\352\170\000\341\170\000\341\170\000\341\170\000\341\211\000\327\211\000\327\211\000\327\211\000\327\232\000\313\232\000\313\232\000\313\232\000\313\251\000\277\251\000\277\251\000\277\251\000\277\270\000\261\270\000\261\270\000\261\270\000\261\305\000\242\305\000\242\305\000\242\305\000\242\321\000\222\321\000\222\321\000\222\321\000\222\331\000\205\331\000\205\331\000\205\331\000\205\343\000\164\343\000\164\343\000\164\343\000\164\354\000\142\354\000\142\354\000\142\354\000\142\363\000\117\363\000\117\363\000\117\363\000\117\367\000\100\367\000\100\367\000\100\367\000\100\373\000\055\373\000\055\373\000\055\373\000\055\376\000\031\376\000\031\376\000\031\376\000\031\377\000\000\377\000\000\377\000\000\377\000\000";

int gv_raster_layer_lut_color_wheel_new_ev( 
    GvRasterLayer *layer, gint set_phase, gint set_magnitude )
{
    int i, q;
    float f_i, f_q;
    float magnitude, /* Calculated magnitude from I/Q data */
	phase_angle; /* Calculated phase angle from I/Q data */
    guchar *LUT;
    guchar *ptr; /* This is the pointer we use to walk across the LUT table */


    /* Allocate enough room to store the LUT */

    if( ( LUT = g_new( guchar, 256 * 256 * 4 ) ) == NULL )
    {
	return 1;
    } else {
	ptr = LUT;
	
	for( q = 0; q < 256; q++ )
	{
	    for( i = 0; i < 256; i++ )
	    {
                int	cmap_entry;

		f_i = -(( i - 127 ) / 128.0);
		f_q = ( q - 127 ) / 128.0;

                if( set_magnitude )
                {
                    magnitude = sqrt( f_i * f_i + f_q * f_q );
                    magnitude = MAX(0.0,MIN(1.0,magnitude));
                }
                else
                    magnitude = 1.0;

                if( set_phase )
                {
                    phase_angle = atan2( f_q, f_i ) - M_PI*0.5;
                    if( phase_angle < 0.0 )
                        phase_angle += 2 * M_PI;

                    cmap_entry = phase_angle * 256 / (2 * M_PI);
                    cmap_entry = MIN(255,MAX(0,cmap_entry));

                    if ((q == 127) && (i == 127))
                    {
                        /* We want the "indetermininate phase" LUT entry to be hardcoded 
                          to red (0 phase). */

                        *ptr++ = (int) (255*magnitude + 0.5);
                        *ptr++ = 0;
                        *ptr++ = 0;
                        *ptr++ = 255;
                    }
                    else
                    {
                        *ptr++ = (int) (phase_lut[cmap_entry*3+0]*magnitude + 0.5);
                        *ptr++ = (int) (phase_lut[cmap_entry*3+1]*magnitude + 0.5);
                        *ptr++ = (int) (phase_lut[cmap_entry*3+2]*magnitude + 0.5);
                        *ptr++ = 255;
                    }
                }
                else
                {
                    *ptr++ = (int) (255 * magnitude + 0.5);
                    *ptr++ = (int) (255 * magnitude + 0.5);
                    *ptr++ = (int) (255 * magnitude + 0.5);
                    *ptr++ = 255;
                }
	    }
	}

    }

    if ( gv_raster_layer_lut_put( layer, LUT, 256 ) )
    {
	g_free(LUT);
	return 1;
    }

    if (set_phase && set_magnitude )
        gv_data_set_property(GV_DATA(layer),"last_complex_lut","magphase");
    else if (set_magnitude)
        gv_data_set_property(GV_DATA(layer),"last_complex_lut","magnitude");
    else if (set_phase)
        gv_data_set_property(GV_DATA(layer),"last_complex_lut","phase");
    else
        gv_data_set_property(GV_DATA(layer),"last_complex_lut","unnamed");

    g_free(LUT);
    return 0;
}

int gv_raster_layer_lut_color_wheel_new( GvRasterLayer *layer, gint h_type, gfloat h_param, gint s_type, gfloat s_param, gint v_type, gfloat v_param )
{
    int i, q;
    float f_i, f_q;
    float magnitude, /* Calculated magnitude from I/Q data */
	phase_angle; /* Calculated phase angle from I/Q data */
    float *h=NULL, *s=NULL, *v=NULL;
    float r, g, b;
    guchar *LUT;
    guchar *ptr; /* This is the pointer we use to walk across the LUT table */
    int    use_hsv = TRUE;


    /* Allocate enough room to store the LUT */

    if( ( LUT = g_new( guchar, 256 * 256 * 4 ) ) == NULL )
    {
	return 1;
    } else {
	/* Figure out the HSV mapping for the data -- each channel of H, S and V can be independantly specified as either
	   Magnitude - GV_RASTER_LAYER_LUT_MAGNITUDE,
	   Phase Angle - GV_RASTER_LAYER_LUT_PHASE_ANGLE,
	   Scalar - GV_RASTER_LAYER_LUT_SCALAR */

	switch( h_type )
	{
          case GV_RASTER_LAYER_LUT_MAGNITUDE:
            h = &magnitude;
            break;
          case GV_RASTER_LAYER_LUT_PHASE_ANGLE:
            h = &phase_angle;
            break;
          case GV_RASTER_LAYER_LUT_SCALAR:
            h = &h_param;
            if( h_param < 0.0 )
                use_hsv = FALSE;
            break;
          case GV_RASTER_LAYER_LUT_REAL:
            h = &f_q;
            break;
          case GV_RASTER_LAYER_LUT_IMAGINARY:
            h = &f_i;
            break;
          default:
            return 1;
	}

	switch( s_type )
	{
          case GV_RASTER_LAYER_LUT_MAGNITUDE:
            s = &magnitude;
            break;
          case GV_RASTER_LAYER_LUT_PHASE_ANGLE:
            s = &phase_angle;
            break;
          case GV_RASTER_LAYER_LUT_SCALAR:
            s = &s_param;
            break;
          case GV_RASTER_LAYER_LUT_REAL:
            s = &f_q;
            break;
          case GV_RASTER_LAYER_LUT_IMAGINARY:
            s = &f_i;
            break;
          default:
            return 1;
	}
	
	switch( v_type )
	{
          case GV_RASTER_LAYER_LUT_MAGNITUDE:
            v = &magnitude;
            break;
          case GV_RASTER_LAYER_LUT_PHASE_ANGLE:
            v = &phase_angle;
            break;
          case GV_RASTER_LAYER_LUT_SCALAR:
            v = &v_param;
            break;
          case GV_RASTER_LAYER_LUT_REAL:
            v = &f_q;
            break;
          case GV_RASTER_LAYER_LUT_IMAGINARY:
            v = &f_i;
            break;
          default:
            return 1;
	}

	ptr = LUT;
	
	for( q = 0;q < 256; q++ )
	{
	    for( i = 0; i < 256; i++ )
	    {
		f_i = -(( i - 127 ) / 128.0);
		f_q = ( q - 127 ) / 128.0;

		phase_angle = (atan2( f_q, f_i ) - M_PI*0.5) / ( 2 * M_PI );
                if( phase_angle < 0.0 )
                    phase_angle += 1.0;
                
		magnitude = sqrt( f_i * f_i + f_q * f_q );

                f_i = MAX(0,MIN(1,-1*f_i*0.5 + 0.5));
                f_q = MAX(0,MIN(1,f_q*0.5 + 0.5));

		if( magnitude > 1.0 )
		    magnitude = 1.0;

                if( use_hsv )
                    gv_raster_layer_lut_hsv_to_rgb( *h, *s, *v, &r, &g, &b );
                else
                    r = g = b = *v;

		*ptr++ = (unsigned char) ( r * 255 );
		*ptr++ = (unsigned char) ( g * 255 );
		*ptr++ = (unsigned char) ( b * 255 );
		*ptr++ = 255;

	    }
	}
    }

    if ( gv_raster_layer_lut_put( layer, LUT, 256 ) )
    {
	g_free(LUT);
	return 1;
    }

    if ((h_type == GV_RASTER_LAYER_LUT_SCALAR) &&
        (s_type == GV_RASTER_LAYER_LUT_SCALAR) &&
        (v_type == GV_RASTER_LAYER_LUT_REAL))
        gv_data_set_property(GV_DATA(layer),"last_complex_lut","real");
    else if ((h_type == GV_RASTER_LAYER_LUT_SCALAR) &&
        (s_type == GV_RASTER_LAYER_LUT_SCALAR) &&
        (v_type == GV_RASTER_LAYER_LUT_IMAGINARY))
        gv_data_set_property(GV_DATA(layer),"last_complex_lut","imaginary");
    else
        gv_data_set_property(GV_DATA(layer),"last_complex_lut","unnamed");

    g_free(LUT);
    return 0;
}

int
gv_raster_layer_lut_color_wheel_1d_new( GvRasterLayer *layer, float s, float v, float offset )
{
    float r, g, b, h;
    int i, e;
    guchar *lut;

    if( ( lut = g_new( guchar, 256 * 4 ) ) != NULL )
    {

	for( e = 0, i = 0; i < 256; i++ )
	{
	    h = ( i / 255.0 + offset );
	    
	    gv_raster_layer_lut_hsv_to_rgb( h, s, v, &r, &g, &b );

	    lut[e++] = (char) (r * 255.0);
	    lut[e++] = (char) (g * 255.0);
	    lut[e++] = (char) (b * 255.0);
	    lut[e++] = 255;
	}
    }

    if( gv_raster_layer_lut_put( layer, lut, 1 ) )
    {
	g_free( lut );
	return 1;
    }

    g_free( lut );
    return 0;
}

int
gv_raster_layer_lut_interpolated_new( GvRasterLayer *layer, GvRasterLayerLutInterpolate *color_pair, int offset )
{
    int i;
    guchar *lut;

    if( ( lut = g_new( guchar, 256 * 4 ) ) != NULL )
    {
	for( i = 0; color_pair[i+1].index != -1; i++ )
	{
	    gv_raster_layer_lut_interpolate( lut, color_pair[i].color, color_pair[i].index+offset, color_pair[i+1].color, color_pair[i+1].index+offset );
	}

	if ( gv_raster_layer_lut_put( layer, lut, 1 ) )
	{
	    g_free(lut);
	    return 1;
	}
        else
            g_free(lut);

    } else {
	return 1;
    }
    return 0;
}

static int
gv_raster_layer_lut_interpolate( guchar *lut, guchar start_color[4], guint start_index, guchar end_color[4], guint end_index )
{
    float spread = ( end_index - start_index );
    float step_r, step_g, step_b;
    int i, e;

    g_return_val_if_fail( lut != NULL, 1 );

    step_r = ( end_color[0] - start_color[0] ) / spread;
    step_g = ( end_color[1] - start_color[1] ) / spread;
    step_b = ( end_color[2] - start_color[2] ) / spread;

    for( e = start_index * 4, i = 0; i < end_index-start_index; i++ )
    {
	lut[e++%1024] = start_color[0] + (guchar) ( step_r * i );
	lut[e++%1024] = start_color[1] + (guchar) ( step_g * i );
	lut[e++%1024] = start_color[2] + (guchar) ( step_b * i );
	lut[e++%1024] = 255;
    }

    lut[e++%1024] = end_color[0];
    lut[e++%1024] = end_color[1];
    lut[e++%1024] = end_color[2];
    lut[e%1024] = 255;

    return 0;
}

/*
** The following function creates pc_lut_compose based on taking a 2D (complex)
** PCT in pc_lut and "precomposing" the LUT in the first raster source.  This
** is intended to simulate "magnitude" enhancements inexpensively.
**
** The compose operation only does something if a 1D GvRasterSource LUT 
** exists, and the PCT is 2D.
*/

int
gv_raster_layer_lut_compose( GvRasterLayer *layer )

{
    unsigned char *lut;
    int x, y, src;

    if( layer->pc_lut_composed != NULL )
    {
        g_free( layer->pc_lut_composed );
        layer->pc_lut_composed = NULL;
    }

    /*
    ** Do we want to generate a composed PCT?
    */
    if( ( layer->mode != GV_RLM_COMPLEX 
          || layer->pc_lut == NULL 
          || layer->source_list[0].lut == NULL ) &&
        ( layer->mode != GV_RLM_RGBA
          || layer->pc_lut_rgba_complex == NULL ) )
        return TRUE;


    if( layer->mode == GV_RLM_COMPLEX )
    {
        /*
        ** Create the composed PCT.
        */
        layer->pc_lut_composed = g_new( guchar, 256 * 4 * 256 );
        lut = layer->source_list[0].lut;
        for( x = 0; x < 256; x++ )
        {
            for( y = 0; y < 256; y++ )
            {
                float p_mag, mp_mag;
                int   dx, dy;

                dx = x - 128;
                dy = y - 128;

                /* compute magnitude scaled between 0.0 and 1.0 */
                p_mag = sqrt((double)(dx*dx+dy*dy)) / 128.0;

                if( p_mag > 1.0 )
                    p_mag = 1.0;

                /* compute modified pseudo magnitude */
                mp_mag = lut[(int) (p_mag * 255.99)] / 255.0;

                if( dx != 0 || dy != 0 )
                {
                    dx = (int) floor(dx * mp_mag / p_mag + 0.5);
                    dy = (int) floor(dy * mp_mag / p_mag + 0.5);

                    dx = MIN(MAX(-128,dx),127);
                    dy = MIN(MAX(-128,dy),127);
                }
                
                memcpy( layer->pc_lut_composed + (x + y*256)*4,
                        layer->pc_lut + ((dx+128)+(dy+128)*256)*4,
                        4 );
            }
        }
    }
    else
    {
        for( src = 0 ; src < layer->source_count; src++ )
        {
            if (layer->source_list[src].lut_rgba_composed != NULL)
            {
                g_free(layer->source_list[src].lut_rgba_composed);
                layer->source_list[src].lut_rgba_composed = NULL;
            }
            if ( layer->source_list[src].lut != NULL )
            {

                /*
                ** Create the composed PCT.
                */
                layer->source_list[src].lut_rgba_composed = \
                                   g_new( guchar, 256 * 4 * 256 );
                lut = layer->source_list[src].lut;
                for( x = 0; x < 256; x++ )
                {
                    for( y = 0; y < 256; y++ )
                    {
                        float p_mag, mp_mag;
                        int   dx, dy;

                        dx = x - 128;
                        dy = y - 128;

                        /* compute magnitude scaled between 0.0 and 1.0 */
                        p_mag = sqrt((double)(dx*dx+dy*dy)) / 128.0;

                        if( p_mag > 1.0 )
                            p_mag = 1.0;

                        /* compute modified pseudo magnitude */
                        mp_mag = lut[(int) (p_mag * 255.99)] / 255.0;

                        if( dx != 0 || dy != 0 )
                        {
                            dx = (int) floor(dx * mp_mag / p_mag + 0.5);
                            dy = (int) floor(dy * mp_mag / p_mag + 0.5);

                            dx = MIN(MAX(-128,dx),127);
                            dy = MIN(MAX(-128,dy),127);
                        }
                
                        memcpy( layer->source_list[src].lut_rgba_composed + 
                                (x + y*256)*4,
                                layer->pc_lut_rgba_complex + 
                                  ((dx+128)+(dy+128)*256)*4,
                                4 );
                    }
                }
            }
        }
    }
    return TRUE;
}

int
gv_raster_layer_lut_put( GvRasterLayer *layer, guchar *lut, gint height )
{
    int	i;

    g_return_val_if_fail( layer != NULL, 1 );
    g_return_val_if_fail( GV_IS_RASTER_LAYER( layer ), 1 );

    if (layer->mode == GV_RLM_RGBA && height == 256)
    {
        /* Lut to apply to complex bands in rgba mode */
        if( layer->pc_lut_rgba_complex )
        {
	    g_free( layer->pc_lut_rgba_complex );
            layer->pc_lut_rgba_complex = NULL;
        }

        if( lut == NULL )
        {
            layer->pc_lut_rgba_complex = NULL;
        }
        else
        {
            layer->pc_lut_rgba_complex = g_new( guchar, 256 * 4 * height );
            memcpy( layer->pc_lut_rgba_complex, lut, 256 * 4 * height );
        }
        /*
        ** Turn on Alpha blending if any of the colors have a non-255 alpha
        ** value.
        */
        for( i = 0; layer->pc_lut_rgba_complex != NULL && i < 256 * height; 
             i++ )
        {
            if( layer->pc_lut_rgba_complex[i*4 + 3] != 255 )
            {
                gv_raster_layer_blend_mode_set( layer, 
                                            GV_RASTER_LAYER_BLEND_MODE_FILTER,
                                            0, 0 );
                break;
            }
        }

    }
    else
    {
        if( layer->pc_lut )
        {
	    g_free( layer->pc_lut );
            layer->pc_lut = NULL;
        }

        if( lut == NULL )
        {
            layer->pc_lut = NULL;
        }
        else if( (layer->mode == GV_RLM_COMPLEX && height != 256)
                 || (layer->mode != GV_RLM_COMPLEX && height != 1) )
        {
            g_warning( "Attempt to apply lut of inappropriate height in" 
                       " gv_raster_layer_lut_put()." );
            return 1;
        }
        else
        {
            layer->pc_lut = g_new( guchar, 256 * 4 * height );
            memcpy( layer->pc_lut, lut, 256 * 4 * height );
        }
        /*
        ** Turn on Alpha blending if any of the colors have a non-255 alpha
        ** value.
        */
        for( i = 0; layer->pc_lut != NULL && i < 256 * height; i++ )
        {
            if( layer->pc_lut[i*4 + 3] != 255 )
            {
                gv_raster_layer_blend_mode_set( layer, 
                                            GV_RASTER_LAYER_BLEND_MODE_FILTER,
                                            0, 0 );
                break;
            }
        }

    }


    /*
    ** Purge old textures, to force regeneration and notify all of change.
    */
    gv_raster_layer_purge_all_textures( layer );
    gv_layer_display_change( GV_LAYER(layer), NULL );

    /*
    ** Regenerate 2D composed Complex lut if needed.
    */
    gv_raster_layer_lut_compose( layer );

    return 0;
}


/* April 2004 note: modified to include rgba_complex argument     */
/* so that real or complex lut can be selected for rgba case      */
/* (before there was no complex or mixed real-complex rgba mode). */
unsigned char *
gv_raster_layer_lut_get( GvRasterLayer *layer, int *width, int *height, 
                         int rgba_complex )
{
    int   width_ret=256, height_ret;

    /* The argument rgba_complex indicates whether a complex or real
     * lut should be returned in the rgba case.  If rgba_complex is 1,
     * the complex lut will be returned.  Otherwise, the real one
     * will be returned.  The rgba_complex argument is IGNORED if the
     * layer mode is not RGBA.
     */
    g_return_val_if_fail( layer != NULL, NULL );
    g_return_val_if_fail( GV_IS_RASTER_LAYER( layer ), NULL );

    if( layer->mode == GV_RLM_COMPLEX )
        height_ret = 256;
    else if ( layer->mode == GV_RLM_RGBA )
    {
        if (rgba_complex == 1)
            height_ret = 256;
        else
            height_ret = 1;
    }
    else 
        height_ret = 1;

    if ( layer->mode == GV_RLM_RGBA )
    {
        if((rgba_complex != 1) && ( layer->pc_lut == NULL ))
        {
            width_ret = 0;
            height_ret = 0;
        }
        else if((rgba_complex == 1) && ( layer->pc_lut_rgba_complex == NULL ))
        {
            width_ret = 0;
            height_ret = 0;
        }
    }
    else
    {
        if( layer->pc_lut == NULL )
        {
            width_ret = 0;
            height_ret = 0;
        }
    }

    if( width != NULL )
        *width = width_ret;

    if( height != NULL )
        *height = height_ret;
    
    if ((layer->mode == GV_RLM_RGBA) && (rgba_complex == 1))
        return layer->pc_lut_rgba_complex;
    else
        return layer->pc_lut;
}


long
gv_raster_layer_lut_type_get( GvRasterLayer *layer )
{
    g_return_val_if_fail( layer != NULL, -1 );
    g_return_val_if_fail( GV_IS_RASTER_LAYER( layer ), -1 );

    if( layer->mode == GV_RLM_COMPLEX )
        return GV_RASTER_LAYER_LUT_2D;
    else if( layer->mode == GV_RLM_SINGLE )
        return GV_RASTER_LAYER_LUT_1D;
    else
        return GV_RASTER_LAYER_LUT_NONE;
}

static void
gv_raster_layer_lut_hsv_to_rgb(  float h, float s, float v, float *r, float *g, float *b )
{
    float f;
    int i;

    /* Find hue at max saturation */
    h *= 6;
    i = (int)h;
    f = h - i;

    switch(i)
    {
	case 0:
	case 6:
	    *r = 1.0;
	    *g = f;
	    *b = 0.0;
	    break;

	case 1:
	    *r = 1.0 - f;
	    *g = 1.0;
	    *b = 0.0;
	    break;

	case 2:
	    *r = 0.0;
	    *g = 1.0;
	    *b = f;
	    break;

	case 3:
	    *r = 0.0;
	    *g = 1.0-f;
	    *b = 1.0;
	    break;

	case 4:
	    *r = f;
	    *g = 0.0;
	    *b = 1.0;
	    break;

	case 5:
	    *r = 1.0;
	    *g = 0.0;
	    *b = 1.0-f;
	    break;

    }

    f = ( 0.3086 * *r + 0.6094 * *g + 0.082 * *b ) * (1.0 - s );
    *r = f + *r * s;
    *g = f + *g * s;
    *b = f + *b * s;

    /* Scale towards 0,0,0 using value */

    *r *= v;
    *g *= v;
    *b *= v;
}

gint 
gv_raster_layer_apply_gdal_color_table( GvRasterLayer *layer, 
                                        GDALColorTableH color_table )

{
    guchar lut[256*4];
    int    i;

    memset( lut, 0, 256*4 );

    if( GDALGetColorEntryCount( color_table ) > 256 )
    {
        CPLDebug( "OpenEV", "gv_raster_layer_apply_gdal_color_table(): "
                  "PCT has %d entries, only using 256.",
                  GDALGetColorEntryCount( color_table ) );
    }

    for( i = 0; i < MIN(256,GDALGetColorEntryCount( color_table )); i++ )
    {
        GDALColorEntry entry;

        GDALGetColorEntryAsRGB( color_table, i, &entry );
        
        lut[i*4  ] = entry.c1;
        lut[i*4+1] = entry.c2;
        lut[i*4+2] = entry.c3;
        lut[i*4+3] = entry.c4;
    }

    return gv_raster_layer_lut_put( layer, lut, 1 );
}
