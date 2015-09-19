/******************************************************************************
 * $Id: gvrasterconvert.c,v 1.20 2004/06/23 14:35:03 gmwalter Exp $
 *
 * Project:  OpenEV
 * Purpose:  Raster conversion functions (float->byte, apply lut, etc)
 * Author:   Frank Warmerdam, warmerda@home.com
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
 * $Log: gvrasterconvert.c,v $
 * Revision 1.20  2004/06/23 14:35:03  gmwalter
 * Added support for multi-band complex imagery.
 *
 * Revision 1.19  2004/04/02 17:01:02  gmwalter
 * Updated nodata support for complex and
 * rgb data.
 *
 * Revision 1.18  2003/05/18 11:02:56  andrey_kiselev
 * Memory leak fixed.
 *
 * Revision 1.17  2001/10/17 20:12:53  warmerda
 * fixed type casting warning
 *
 * Revision 1.16  2001/10/17 16:23:51  warmerda
 * added support for composing complex lut and pct
 *
 * Revision 1.15  2001/08/21 23:44:47  warmerda
 * fixed nodata_mask freeing logic
 *
 * Revision 1.14  2001/08/17 00:54:41  warmerda
 * fixed nodata_mask leak
 *
 * Revision 1.13  2000/09/29 04:27:02  warmerda
 * fixed nodata handling in grayscale case
 *
 * Revision 1.12  2000/08/25 20:11:07  warmerda
 * added preliminary nodata support
 *
 * Revision 1.11  2000/06/26 15:13:11  warmerda
 * include alpha in RGB if alpha blending set on
 *
 * Revision 1.10  2000/06/23 12:54:59  warmerda
 * largely rewrote
 *
 * Revision 1.9  2000/06/20 13:26:55  warmerda
 * added standard headers
 *
 */

#include <stdlib.h>
#include <math.h>
#include "gvrasterlayer.h"

static unsigned char *
gv_raster_layer_gltile_complex( GvRasterLayer *layer, int tile, int lod, 
                                int *format, int *type, int *needs_free )

{
    unsigned char *raw_data;
    int i, pixel_count;
    int * rgba_data, *LUT = (int *) layer->pc_lut;
    unsigned char *nodata_mask = NULL;
    unsigned char *rgba_ptr=NULL;

    if( layer->pc_lut == NULL )
    {								
        g_warning("gv_raster_layer_gltile_complex without pc_lut!" );
        return NULL;
    }

    pixel_count = (layer->tile_x >> lod) * (layer->tile_y >> lod);

    if( layer->source_list[0].nodata_active )
    {
        nodata_mask = g_new( unsigned char, pixel_count );
        memset( nodata_mask, 1, pixel_count );
    }

    if( layer->pc_lut_composed != NULL )
        LUT = (int *) layer->pc_lut_composed;

    raw_data = gv_raster_layer_srctile_xy_get( layer, 0, tile, lod, 
                                               needs_free, nodata_mask );

    rgba_data = g_new(int,pixel_count);
        
    for( i = 0; i < pixel_count; i++ )
    {
        rgba_data[i] = LUT[raw_data[i*2+1]+raw_data[i*2]*256];
    }

    if( nodata_mask != NULL )
    {
        rgba_ptr = (unsigned char *) rgba_data;
        for( i = 0; i < pixel_count; i++ )
        {
            if( nodata_mask[i] == 0 )
                rgba_ptr[i*4+3] = 0;
        }
        rgba_ptr = NULL;
    }
    
    if( *needs_free )
        g_free( raw_data );

    if( nodata_mask != NULL )
        g_free( nodata_mask );
        
    *format = GL_RGBA;
    *type = GL_UNSIGNED_BYTE;
    *needs_free = TRUE;

    return (unsigned char *) rgba_data;
}

static unsigned char *
gv_raster_layer_gltile_single( GvRasterLayer *layer, int tile, int lod, 
                               int *format, int *type, int *needs_free )

{
    int            pixel_count;
    unsigned char *raw_data;
    unsigned char *nodata_mask = NULL;

    pixel_count = (layer->tile_x >> lod) * (layer->tile_y >> lod);

    if( layer->source_list[0].nodata_active )
    {
        nodata_mask = g_new( unsigned char, pixel_count );
        memset( nodata_mask, 1, pixel_count );
    }

    raw_data = gv_raster_layer_srctile_xy_get( layer, 0, tile, lod, 
                                               needs_free, nodata_mask );

    *format = GL_LUMINANCE;
    *type = GL_UNSIGNED_BYTE;

    if( layer->pc_lut != NULL )
    {								
        int i;
        int * rgba_data, *LUT = (int *) layer->pc_lut;

        rgba_data = g_new(int,pixel_count);
        
        for( i = 0; i < pixel_count; i++ )
        {
            rgba_data[i] = LUT[raw_data[i]];
        }

        if( *needs_free )
            g_free( raw_data );
        
        *needs_free = TRUE;
        raw_data = (unsigned char *) rgba_data;
        *format = GL_RGBA;
        
        if( nodata_mask != NULL )
        {
            for( i = 0; i < pixel_count; i++ )
            {
                if( nodata_mask[i] == 0 )
                    rgba_data[i] = 0;
            }
        }
    }
    else if( nodata_mask != NULL )
    {
        int i;
        unsigned char * la_data;

        la_data = g_new(unsigned char,pixel_count*2);

        for( i = 0; i < pixel_count; i++ )
        {
            if( nodata_mask[i] == 0 )
            {
                la_data[i*2+0] = 0;
                la_data[i*2+1] = 0;
            }
            else
            {
                la_data[i*2+0] = raw_data[i];
                la_data[i*2+1] = 255;
            }
        }
        
        if( *needs_free )
            g_free( raw_data );
        
        *needs_free = TRUE;
        raw_data = (unsigned char *) la_data;
        *format = GL_LUMINANCE_ALPHA;
    }

    if( nodata_mask != NULL )
        g_free( nodata_mask );

    return raw_data;
}

static unsigned char *
gv_raster_layer_gltile_rgba( GvRasterLayer *layer, int tile, int lod, 
                             int *format, int *type, int *needs_free )

{
    unsigned char *red, *green, *blue, *alpha=NULL, *ret_data=NULL;
    int free_red, free_green, free_blue, free_alpha=FALSE;
    int pixel_count;
    unsigned char *nodata_r=NULL, *nodata_g=NULL;
    unsigned char *nodata_b=NULL, *nodata_a=NULL;

    /* variables that are only used for complex bands*/
    char *LUT=NULL;
    int i;
    unsigned char *cred=NULL, *cgreen=NULL, *cblue=NULL, *calpha=NULL;


    /* Is alpha blending enabled? */
    if( layer->gl_info.blend_enable )
    {
        *format = GL_RGBA;
        *type = GL_UNSIGNED_BYTE;
    }
    else
    {
        *format = GL_RGB;
        *type = GL_UNSIGNED_BYTE;
    }

    /* Get nodata information */
    pixel_count = (layer->tile_x >> lod) * (layer->tile_y >> lod);

    if( layer->source_list[0].nodata_active )
    {
        nodata_r = g_new( unsigned char, pixel_count );
        memset( nodata_r, 1, pixel_count );
    }

    if( layer->source_list[1].nodata_active )
    {
        nodata_g = g_new( unsigned char, pixel_count );
        memset( nodata_g, 1, pixel_count );
    }

    if( layer->source_list[2].nodata_active )
    {
        nodata_b = g_new( unsigned char, pixel_count );
        memset( nodata_b, 1, pixel_count );
    }

    /* Get source data */

    red   = gv_raster_layer_srctile_xy_get( layer, 0, tile, lod, &free_red,
                                            nodata_r );
    green = gv_raster_layer_srctile_xy_get( layer, 1, tile, lod, &free_green,
                                            nodata_g );
    blue  = gv_raster_layer_srctile_xy_get( layer, 2, tile, lod, &free_blue,
                                            nodata_b );
    
    if( red == NULL || green == NULL || blue == NULL )
    {
        g_warning( "failed to fetch component in gv_raster_layer_gltile_rgba");
        if ( nodata_r != NULL )
            g_free( nodata_r );
        if ( nodata_g != NULL )
            g_free( nodata_g );
        if ( nodata_b != NULL )
            g_free( nodata_b );

        return NULL;
    }

    cred = g_new( unsigned char, pixel_count );
    if ( (layer->source_list[0].data != NULL) &&
         (layer->source_list[0].data->gdal_type == GDT_CFloat32) )
    {
        if (layer->source_list[0].lut_rgba_composed != NULL)
            LUT = (char *) layer->source_list[0].lut_rgba_composed;
        else
            LUT = (char *) layer->pc_lut_rgba_complex;
        for ( i = 0; i < pixel_count; i++ )
        {
            cred[i] = LUT[red[i*2+1]*4+red[i*2]*4*256+0];
        }
    }
    else
    {
        memcpy(cred, red, pixel_count);
    }

    cgreen = g_new( unsigned char, pixel_count );
    if ((layer->source_list[1].data != NULL) &&
        ( layer->source_list[1].data->gdal_type == GDT_CFloat32 ))
    {
        if (layer->source_list[1].lut_rgba_composed != NULL)
            LUT = (char *) layer->source_list[1].lut_rgba_composed;
        else
            LUT = (char *) layer->pc_lut_rgba_complex;
        for ( i = 0; i < pixel_count; i++ )
        {
            cgreen[i] = LUT[green[i*2+1]*4+green[i*2]*4*256+1];
        }
    }
    else
    {
        memcpy(cgreen, green, pixel_count);
    }


    cblue = g_new( unsigned char, pixel_count );
    if ( (layer->source_list[2].data != NULL) &&
         (layer->source_list[2].data->gdal_type == GDT_CFloat32) )
    {
        if (layer->source_list[2].lut_rgba_composed != NULL)
            LUT = (char *) layer->source_list[2].lut_rgba_composed;
        else
            LUT = (char *) layer->pc_lut_rgba_complex;
        for ( i = 0; i < pixel_count; i++ )
        {
            cblue[i] = LUT[blue[i*2+1]*4+blue[i*2]*4*256+2];
        }
    }
    else
    {
        memcpy(cblue, blue, pixel_count);
    }

        
    if( *format == GL_RGBA )
    {
        if( layer->source_list[3].nodata_active )
        {
            nodata_a = g_new( unsigned char, pixel_count );
            memset( nodata_a, 1, pixel_count );
        }
        alpha = gv_raster_layer_srctile_xy_get( layer, 3, tile, lod, 
                                                &free_alpha, nodata_a );

        calpha = g_new( unsigned char, pixel_count );
        if ( (layer->source_list[3].data != NULL) &&
             (layer->source_list[3].data->gdal_type == GDT_CFloat32) )
        {
            if (layer->source_list[3].lut_rgba_composed != NULL)
                LUT = (char *) layer->source_list[3].lut_rgba_composed;
            else
                LUT = (char *) layer->pc_lut_rgba_complex;
            for ( i = 0; i < pixel_count; i++ )
            {
                calpha[i] = LUT[alpha[i*2+1]*4+alpha[i*2]*4*256+0];
            }
        }
        else
        {
            memcpy(calpha, alpha, pixel_count);
        }

    }

    /* Interleave */

    if( *format == GL_RGBA )
    {
        int i, pixel_count;

        pixel_count = (layer->tile_x >> lod) * (layer->tile_y >> lod);
        ret_data = (unsigned char *) g_malloc(pixel_count*4);
        
        for( i = 0; i < pixel_count; i++ )
        {
            ret_data[i*4  ] = cred[i];
            ret_data[i*4+1] = cgreen[i];
            ret_data[i*4+2] = cblue[i];
            ret_data[i*4+3] = calpha[i];
        }
        /* If this really slows things down, then could combine
           all of these into a single for loop by creating a
           case-type statement:
           if ((nodata_r != NULL) && (nodata_g != NULL) 
               && (nodata_b != NULL) && (nodata_a != NULL))
           {
             (single for loop that assigns r,g,b,a and checks nodata_r,
             nodata_g, nodata_b, nodata_a)
           }
           else if ((nodata_r != NULL) && (nodata_g != NULL)
                    && (nodata_b != NULL))
           {
             (single for loop that assigns r,g,b,a and checks nodata_r,
             nodata_g, nodata_b)
           }
           etc.
        */
        if (nodata_r != NULL)
        {
            for( i = 0; i < pixel_count; i++ )
            {
                if ( nodata_r[i] == 0 )
                    ret_data[i*4+3] = 0;
            }
        }
        if (nodata_g != NULL)
        {
            for( i = 0; i < pixel_count; i++ )
            {
                if ( nodata_g[i] == 0 )
                    ret_data[i*4+3] = 0;
            }
        }
        if (nodata_b != NULL)
        {
            for( i = 0; i < pixel_count; i++ )
            {
                if ( nodata_b[i] == 0 )
                    ret_data[i*4+3] = 0;
            }
        }
        if (nodata_a != NULL)
        {
            for( i = 0; i < pixel_count; i++ )
            {
                if ( nodata_a[i] == 0 )
                    ret_data[i*4+3] = 0;
            }
        }
    }
    else
    {
        int i, pixel_count;

        pixel_count = (layer->tile_x >> lod) * (layer->tile_y >> lod);
        ret_data = (unsigned char *) g_malloc(pixel_count*3);
        
        for( i = 0; i < pixel_count; i++ )
        {
            ret_data[i*3  ] = cred[i];
            ret_data[i*3+1] = cgreen[i];
            ret_data[i*3+2] = cblue[i];
        }
    }
    *needs_free = TRUE;

    if( free_red )
        g_free( red );

    if( free_green )
        g_free( green );

    if( free_blue )
        g_free( blue );

    if( free_alpha )
        g_free( alpha );

    if ( nodata_r != NULL )
        g_free( nodata_r );
    if ( nodata_g != NULL )
        g_free( nodata_g );
    if ( nodata_b != NULL )
        g_free( nodata_b );
    if ( nodata_a != NULL )
        g_free( nodata_a );
    if ( cred != NULL );
        g_free( cred );
    if ( cgreen != NULL );
        g_free( cgreen );
    if ( cblue != NULL );
        g_free( cblue );
    if ( calpha != NULL );
        g_free( calpha );

    return ret_data;
}

unsigned char *
gv_raster_layer_gltile_get( GvRasterLayer *layer, int tile, int lod, 
                            int *format, int *type, int *needs_free )

{
    if( layer->mode == GV_RLM_SINGLE )
        return gv_raster_layer_gltile_single( layer, tile, lod, format, type,
                                              needs_free );
    else if( layer->mode == GV_RLM_RGBA )
        return gv_raster_layer_gltile_rgba( layer, tile, lod, format, type,
                                            needs_free );
    else if( layer->mode == GV_RLM_COMPLEX )
        return gv_raster_layer_gltile_complex( layer, tile, lod, format, type,
                                               needs_free );
    else 
    {
        g_warning( "unexpected layer mode in gv_raster_layer_gltile_get()" );
        return NULL;
    }
        
}
