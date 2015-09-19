/******************************************************************************
 * $Id: gvutils.c,v 1.22 2004/06/23 14:35:05 gmwalter Exp $
 *
 * Project:  OpenEV
 * Purpose:  Various utility functions.
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
 * $Log: gvutils.c,v $
 * Revision 1.22  2004/06/23 14:35:05  gmwalter
 * Added support for multi-band complex imagery.
 *
 * Revision 1.21  2004/04/21 15:13:58  andrey_kiselev
 * Fix comparisons with NODATA value.
 *
 * Revision 1.20  2004/04/02 17:01:02  gmwalter
 * Updated nodata support for complex and
 * rgb data.
 *
 * Revision 1.19  2004/01/22 20:03:22  andrey_kiselev
 * gv_format_point_query() returns "[NODATA]" label if value marked as NODATA.
 *
 * Revision 1.18  2001/08/08 17:43:22  warmerda
 * avoid warning
 *
 * Revision 1.17  2001/04/22 17:32:25  pgs
 * added get_short_path_name
 *
 * Revision 1.16  2000/10/10 17:38:41  srawlin
 * changed lat/long decimal format to report position to 7 decimal digits
 *
 * Revision 1.15  2000/09/26 16:55:35  srawlin
 * changed lat/long decimal format to report N/S and E/W instead of +/-
 *
 * Revision 1.14  2000/09/26 16:32:41  srawlin
 * added degree_mode to set Lat/Long display to be either in the form dd:mm:ss (dms) or dd.dd (decimal)
 *
 * Revision 1.13  2000/08/25 20:08:44  warmerda
 * added phase/magnitude reporting
 *
 * Revision 1.12  2000/08/24 19:49:27  warmerda
 * don't operate o null strings
 *
 * Revision 1.11  2000/08/24 03:37:52  warmerda
 * added PIXEL as a coordinate system
 *
 * Revision 1.10  2000/08/24 03:26:01  warmerda
 * fixed +- sign for complex raster values
 *
 * Revision 1.9  2000/06/26 15:12:17  warmerda
 * don't crash if gvraster is null
 *
 * Revision 1.8  2000/06/23 12:56:52  warmerda
 * added multiple GvRasterSource support
 *
 * Revision 1.7  2000/06/20 13:26:55  warmerda
 * added standard headers
 *
 */

#include <stdio.h>
#include "gvutils.h"
#include "gvrasterlayer.h"
#include "ogr_srs_api.h"
#include "cpl_conv.h"

void gv_set_color_from_string( GvColor color, const char * string,
                               float def_red, float def_green,
                               float def_blue, float def_alpha )

{
    if( string != NULL )
    {
        def_alpha = 1.0;
        sscanf( string, "%f %f %f %f",
                &def_red, &def_green, &def_blue, &def_alpha );
    }

    if( def_red > 1.0 || def_green > 1.0 || def_blue > 1.0 || def_alpha > 1.0 )
    {
        def_red /= 255.0;
        def_green /= 255.0;
        def_blue /= 255.0;
        def_alpha /= 255.0;
    }
    color[0] = def_red;
    color[1] = def_green;
    color[2] = def_blue;
    color[3] = def_alpha;
}

void gv_complex_to_phase_mag( float real, float imaginary,
                              float *phase, float *magnitude )

{
    *magnitude = sqrt(real*real+imaginary*imaginary);
    *phase = atan2(imaginary, real);
}

const char *gv_format_point_query( GvViewArea *view,
                                   GvProperties *properties,
                                   double geo_x, double geo_y )

{
    static gchar buf[256];
    double raster_x=0.0, raster_y=0.0, pix_real, pix_imaginary;
    GvLayer *layer;
    GvRaster *raster = NULL;
    GvRasterLayer *raster_layer = NULL;
    GList *layer_list, *node;
    const char *coord_mode, *pixel_mode, *degree_mode;
    const char *coord_sys = gv_view_area_get_projection(view);
    char    *latlong_srs = NULL;
    char east_west, north_south;

    /* Check the properties to see what options are in effect */
    coord_mode = gv_properties_get( properties, "_coordinate_mode" );
    if( coord_mode == NULL )
        coord_mode = "georef";

    pixel_mode = gv_properties_get( properties, "_pixel_mode" );
    if( pixel_mode == NULL )
        pixel_mode = "on";

    degree_mode = gv_properties_get( properties, "_degree_mode" );
    if( degree_mode == NULL )
        degree_mode = "dms";

    /* This code should be factored out into gvviewarea at some point. */
    layer_list = gv_view_area_list_layers( view );

    for( node = layer_list; node != NULL; node = node->next )
    {
        layer = GV_LAYER(node->data);
        if( gv_layer_is_visible(layer) && GV_IS_RASTER_LAYER( layer ) )
        {
            raster = GV_RASTER_LAYER(layer)->prototype_data;
            raster_layer = GV_RASTER_LAYER(layer);

            raster_x = geo_x;
            raster_y = geo_y;

            if( !gv_raster_layer_view_to_pixel( raster_layer,
                                                &raster_x, &raster_y, NULL )
                ||raster_x < 0 || raster_x >= raster->width
                || raster_y < 0 || raster_y >= raster->height )
            {
                raster = NULL;
                raster_layer = NULL;
            }
        }
    }

    /* Do we want to transform coordinate into a real `geo' space? */
    if( raster != NULL
        && (gv_view_area_get_projection(view) == NULL
            || EQUAL(gv_view_area_get_projection(view),"PIXEL"))
        && raster_layer->mesh_is_raw )
    {
        double geo_x_dbl, geo_y_dbl;

        geo_x_dbl = raster_x;
        geo_y_dbl = raster_y;
        gv_raster_pixel_to_georef( raster,
                                   &geo_x_dbl, &geo_y_dbl, NULL );
        coord_sys = gv_data_get_projection( GV_DATA(raster) );
        geo_x = geo_x_dbl;
        geo_y = geo_y_dbl;
    }

    if( g_strcasecmp(coord_mode,"latlong") == 0
        && (coord_sys != NULL && !EQUAL(coord_sys,"PIXEL")) )
    {
        latlong_srs = gv_make_latlong_srs( coord_sys );

        if( latlong_srs != NULL )
        {
            double      x, y, z;

            x = geo_x;
            y = geo_y;
            z = 0.0;

            if( gv_reproject_points( coord_sys, latlong_srs,
                                     1, &x, &y, &z ) )
            {
                geo_x = x;
                geo_y = y;
                coord_sys = latlong_srs;
            }
        }
    }

    buf[0] = '\0';
    if( g_strcasecmp(coord_mode,"off") == 0 )
    {
        /* do nothing */
    }
    else if( g_strcasecmp(coord_mode,"raster") == 0 )
    {
        if( raster != NULL )
            g_snprintf(buf, 64, "(%.2fP, %.2fL)", raster_x, raster_y );
    }
    else
    {
        if( coord_sys != NULL
            && strstr(coord_sys,"PROJCS") == NULL
            && strstr(coord_sys,"GEOGCS") != NULL )
        {
            /* Display in Degree Minute Second format */
            if ( g_strcasecmp(degree_mode, "dms") == 0 )
            {
                strcat( buf, "(");
                strcat( buf, GDALDecToDMS( geo_x, "Long", 2 ));
                strcat( buf, "," );
                strcat( buf, GDALDecToDMS( geo_y, "Lat", 2 ));
                strcat( buf, ")" );
            } else {
                /* Display in decimal format */
                if (geo_x < 0)
                    east_west = 'W';
                else
                    east_west = 'E';

                if (geo_y < 0)
                    north_south = 'S';
                else
                    north_south = 'N';

                g_snprintf(buf, 64, "(%.7f%c, %.7f%c)",
                           fabs(geo_x), east_west, fabs(geo_y), north_south );
            }
        }
        else if( coord_sys != NULL
                 && g_strcasecmp(coord_sys,"PIXEL") == 0 )
        {
            g_snprintf(buf, 64, "(%.2fP, %.2fL)", geo_x, geo_y );
        }
        else
        {
            g_snprintf(buf, 64, "(%.2fE, %.2fN)", geo_x, geo_y );
        }
    }

    if( latlong_srs != NULL )
        g_free( latlong_srs );

    /* Try to get a raster value */
    if( raster_layer != NULL
        && g_strcasecmp(pixel_mode, "on") == 0 )
    {
        const char  *nodata_mode;
        GvRaster    *rsrc;

        nodata_mode = gv_properties_get( properties, "_nodata_mode" );
        if( nodata_mode == NULL )
            nodata_mode = "on";

        if( buf[0] != '\0' )
            strcat( buf, ": " );

        if( raster_layer->mode == GV_RLM_COMPLEX )
        {
            rsrc = gv_raster_layer_get_data(raster_layer,0);
            if( rsrc != NULL
                && gv_raster_get_sample( rsrc, raster_x, raster_y,
                                         &pix_real, &pix_imaginary ) )
            {
                float   phase, magnitude;

                if( pix_imaginary < 0.0 )
                    g_snprintf(buf+strlen(buf), 64, "%g%gi",
                               pix_real, pix_imaginary );
                else
                    g_snprintf(buf+strlen(buf), 64, "%g+%gi",
                               pix_real, pix_imaginary );

                gv_complex_to_phase_mag( pix_real, pix_imaginary,
                                         &phase, &magnitude );
                g_snprintf(buf+strlen(buf), 64, ", phase:%g, magnitude:%g",
                           phase, magnitude );

                if ( g_strcasecmp( nodata_mode, "on") == 0 )
                {
                    double  nodata_real, nodata_imaginary;

                    if( gv_raster_layer_nodata_get( raster_layer, 0,
                                                    &nodata_real,
                                                    &nodata_imaginary )
                        && ABS(pix_real - nodata_real) < 0.0000000001
                        && ABS(pix_imaginary - nodata_imaginary) < 0.0000000001 )
                    {
                        g_snprintf(buf+strlen(buf), 64, " [NODATA]" );
                    }
                }
            }
        }
        else if( raster_layer->mode == GV_RLM_RGBA )
        {
            int     isource;
            double  rgba[4];
            double  rgba_imag[4];

            for( isource = 0; isource < 4; isource++ )
            {

                rsrc = gv_raster_layer_get_data(raster_layer,isource);
                if( rsrc == NULL
                    || !gv_raster_get_sample( rsrc, raster_x, raster_y,
                                              rgba + isource, 
                                              rgba_imag + isource) )
                {
                    rgba[isource] =
                        gv_raster_layer_get_const_value(raster_layer,isource);
                }
            }

            if( gv_raster_layer_get_data(raster_layer,3) == NULL )
            {
                if ((rgba_imag[0] != 0.0) || (rgba_imag[1] != 0.0) ||
                    (rgba_imag[2] != 0.0))
                {
                    if (rgba_imag[0] < 0.0)
                        g_snprintf(buf+strlen(buf), 64, "%.5g%.5gi r ",
                            rgba[0], rgba_imag[0] );
                    else
                        g_snprintf(buf+strlen(buf), 64, "%.5g+%.5gi r ",
                            rgba[0], rgba_imag[0] );

                    if (rgba_imag[1] < 0.0)
                        g_snprintf(buf+strlen(buf), 64, "%.5g%.5gi g ",
                            rgba[1], rgba_imag[1] );
                    else
                        g_snprintf(buf+strlen(buf), 64, "%.5g+%.5gi g ",
                            rgba[1], rgba_imag[1] );

                    if (rgba_imag[2] < 0.0)
                        g_snprintf(buf+strlen(buf), 64, "%.5g%.5gi b ",
                            rgba[2], rgba_imag[2] );
                    else
                        g_snprintf(buf+strlen(buf), 64, "%.5g+%.5gi b ",
                            rgba[2], rgba_imag[2] );
                }
                else
                    g_snprintf(buf+strlen(buf), 64, "%gr %gg %gb ",
                           rgba[0], rgba[1], rgba[2] );
            }
            else
            {
                if ((rgba_imag[0] != 0) || (rgba_imag[1] != 0) ||
                    (rgba_imag[2] != 0) || (rgba_imag[3] != 0))
                {
                    if (rgba_imag[0] < 0.0)
                        g_snprintf(buf+strlen(buf), 64, "%.4g%.4gi r ",
                            rgba[0], rgba_imag[0] );
                    else
                        g_snprintf(buf+strlen(buf), 64, "%.4g+%.4gi r ",
                            rgba[0], rgba_imag[0] );

                    if (rgba_imag[1] < 0.0)
                        g_snprintf(buf+strlen(buf), 64, "%.4g%.4gi g ",
                            rgba[1], rgba_imag[1] );
                    else
                        g_snprintf(buf+strlen(buf), 64, "%.4g+%.4gi g ",
                            rgba[1], rgba_imag[1] );

                    if (rgba_imag[2] < 0.0)
                        g_snprintf(buf+strlen(buf), 64, "%.4g%.4gi b ",
                            rgba[2], rgba_imag[2] );
                    else
                        g_snprintf(buf+strlen(buf), 64, "%.4g+%.4gi b ",
                            rgba[2], rgba_imag[2] );

                    if (rgba_imag[3] < 0.0)
                        g_snprintf(buf+strlen(buf), 64, "%.4g%.4gi a ",
                            rgba[3], rgba_imag[3] );
                    else
                        g_snprintf(buf+strlen(buf), 64, "%.4g+%.4gi a ",
                            rgba[3], rgba_imag[3] );
                }
                else
                    g_snprintf(buf+strlen(buf), 64, "%gr %gg %gb %ga",
                           rgba[0], rgba[1], rgba[2], rgba[3] );
            }

            if ( g_strcasecmp( nodata_mode, "on") == 0 )
            {
                double  nodata[3];

                if( (gv_raster_layer_nodata_get(raster_layer, 0, nodata, NULL) 
                     && ABS(rgba[0] - nodata[0]) < 0.0000000001) || 
                    (gv_raster_layer_nodata_get(raster_layer, 1, nodata+1, NULL) 
                     && ABS(rgba[1] - nodata[1]) < 0.0000000001) ||
                    (gv_raster_layer_nodata_get(raster_layer, 2, nodata+2, NULL) 
                     && ABS(rgba[2] - nodata[2]) < 0.0000000001) )
                {
                    g_snprintf(buf+strlen(buf), 64, " [NODATA]" );
                }
            }
        }
        else
        {
            rsrc = gv_raster_layer_get_data(raster_layer,0);
            if( rsrc != NULL &&
                gv_raster_get_sample( rsrc, raster_x, raster_y,
                                      &pix_real, &pix_imaginary ) )
            {
                g_snprintf(buf+strlen(buf), 64, "%g", pix_real);
            }

            if ( g_strcasecmp( nodata_mode, "on") == 0 )
            {
                double  nodata;

                if( gv_raster_layer_nodata_get( raster_layer, 0, &nodata, NULL )
                    && ABS(pix_real - nodata) < 0.0000000001 )
                {
                    g_snprintf(buf+strlen(buf), 64, " [NODATA]" );
                }
            }
        }
    }

    return buf;
}

char *gv_make_latlong_srs( const char * projected_srs )

{
    OGRSpatialReferenceH  hSRSProjected, hSRSLatLong;
    char                  *osr_wkt, *glib_wkt;

    if( projected_srs == NULL )
        return NULL;

    hSRSProjected = OSRNewSpatialReference( projected_srs );
    if( hSRSProjected == NULL )
        return FALSE;

    if( OSRIsGeographic( hSRSProjected ) )
    {
        OSRDestroySpatialReference( hSRSProjected );
        return g_strdup( projected_srs );
    }

    hSRSLatLong = OSRCloneGeogCS( hSRSProjected );
    OSRDestroySpatialReference( hSRSProjected );
    if( hSRSLatLong == NULL )
        return NULL;

    osr_wkt = NULL;
    glib_wkt = NULL;
    OSRExportToWkt( hSRSLatLong, &osr_wkt );
    if( osr_wkt != NULL )
    {
        glib_wkt = g_strdup( osr_wkt );
        CPLFree( osr_wkt );
    }

    if( hSRSLatLong != NULL )
        OSRDestroySpatialReference( hSRSLatLong );

    return glib_wkt;
}

int gv_reproject_points( const char *source_srs,
                         const char *destination_srs,
                         int count, double *x, double *y, double *z )

{
    int success = TRUE;
    OGRSpatialReferenceH   hSRSNew = NULL, hSRSOld = NULL;
    OGRCoordinateTransformationH hTransform = NULL;

    if( source_srs == NULL || destination_srs == NULL )
        return FALSE;

    /*
     * Try and establish if we can, or need to do reprojection.
     */
    hSRSNew = OSRNewSpatialReference( destination_srs );
    if( hSRSNew == NULL )
        return FALSE;

    hSRSOld = OSRNewSpatialReference(source_srs);
    if( hSRSOld == NULL )
    {
        OSRDestroySpatialReference( hSRSNew );
        return FALSE;
    }

    if( OSRIsSame( hSRSOld, hSRSNew ) )
    {
        OSRDestroySpatialReference( hSRSOld );
        OSRDestroySpatialReference( hSRSNew );

        return TRUE;
    }

    /*
     * Establish transformation.
     */

    hTransform = OCTNewCoordinateTransformation( hSRSOld, hSRSNew );
    if( hTransform == NULL )
    {
        OSRDestroySpatialReference( hSRSOld );
        OSRDestroySpatialReference( hSRSNew );

        return FALSE;
    }

    /*
     * Transform all the mesh points.
     */

    success = OCTTransform( hTransform, count, x, y, z );

    OCTDestroyCoordinateTransformation( hTransform );
    OSRDestroySpatialReference( hSRSOld );
    OSRDestroySpatialReference( hSRSNew );

    return success;
}

#ifndef WIN32
int gv_launch_url( const char * url )

{
    return 0;
}

char * gv_short_path_name( const char * lpszLongPath)
{
	return (char *) lpszLongPath;
}

#else
#include "windows.h"
int gv_launch_url( const char * url )

{
    HINSTANCE   hInstance;

    hInstance = ShellExecute( NULL, "open", url, "", "", SW_SHOWNORMAL );

    return ((int) hInstance) > 32;
}

char * gv_short_path_name( const char * lpszLongPath)
{
	int ret;
	char * lpszShortPath;

	lpszShortPath = (char *) malloc(MAX_PATH * sizeof(char));
	lpszShortPath[0] = 0;

	ret = GetShortPathName(lpszLongPath, lpszShortPath, MAX_PATH);

	#ifdef DEBUG
		printf("gv_short_path_name: returned %d for (%s)\n", ret, lpszShortPath);
	#endif

	if (ret > 0)
		return lpszShortPath;
	else
	{
		free(lpszShortPath);
		return "";
	}
}
#endif
