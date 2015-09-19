/******************************************************************************
 * $Id: gvtess.h,v 1.2 2000/06/20 13:27:08 warmerda Exp $
 *
 * Project:  OpenEV
 * Purpose:  Tesselation for GvAreas (will be discarded with GvAreas)
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
 * $Log: gvtess.h,v $
 * Revision 1.2  2000/06/20 13:27:08  warmerda
 * added standard headers
 *
 */

#ifndef __GV_TESS_H__
#define __GV_TESS_H__

#include "gvareas.h"

gint gv_area_tessellate(GvArea *area);

#endif /* __GV_TESS_H__ */
