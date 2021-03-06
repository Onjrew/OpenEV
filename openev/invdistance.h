/******************************************************************************
 * $Id: invdistance.h,v 1.2 2001/04/22 17:33:24 pgs Exp $
 *
 * Project:  CIETMAP / OpenEV
 * Purpose:  Weighted Inverse Distance Interpolator (point to raster)
 *           This implementation is independent of OpenEV, but does depend
 *           directly on GDAL.
 * Author:   Frank Warmerdam, warmerda@home.com
 *
 ******************************************************************************
 * Copyright (c) 2000, Frank Warmerdam
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
 * $Log: invdistance.h,v $
 * Revision 1.2  2001/04/22 17:33:24  pgs
 * changed WIDInterpolate to take variable exponent for d
 *
 * Revision 1.1  2000/09/12 19:17:47  warmerda
 * New
 *
 */

#ifndef __INVDISTANCE_H__
#define __INVDISTANCE_H__

#include "gdal.h"

CPL_C_START

int WIDInterpolate( int nPoints, double *padfX, double *padfY,
                    double *padfValue, double *padfWeight,
                    GDALRasterBandH hBand, double fExponent,
                    GDALProgressFunc pfnProgress, void * pCBData );

CPL_C_END

#endif /*__INVDISTANCE_H__ */
