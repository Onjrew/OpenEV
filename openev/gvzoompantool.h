/******************************************************************************
 * $Id: gvzoompantool.h,v 1.2 2000/06/20 13:27:08 warmerda Exp $
 *
 * Project:  OpenEV
 * Purpose:  Zoom/Pan editing mode (most zoompan code in gvviewarea.c)
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
 * $Log: gvzoompantool.h,v $
 * Revision 1.2  2000/06/20 13:27:08  warmerda
 * added standard headers
 *
 */

#ifndef __GV_ZOOMPAN_TOOL_H__
#define __GV_ZOOMPAN_TOOL_H__

#include "gvtool.h"

#define GV_TYPE_ZOOMPAN_TOOL            (gv_zoompan_tool_get_type ())
#define GV_ZOOMPAN_TOOL(obj)            (GTK_CHECK_CAST ((obj), GV_TYPE_ZOOMPAN_TOOL, GvZoompanTool))
#define GV_ZOOMPAN_TOOL_CLASS(klass)    (GTK_CHECK_CLASS_CAST ((klass), GV_TYPE_ZOOMPAN_TOOL, GvZoompanToolClass))
#define GV_IS_ZOOMPAN_TOOL(obj)         (GTK_CHECK_TYPE ((obj), GV_TYPE_ZOOMPAN_TOOL))
#define GV_IS_ZOOMPAN_TOOL_CLASS(klass) (GTK_CHECK_CLASS_TYPE ((klass), GV_TYPE_ZOOMPAN_TOOL))

typedef struct _GvZoomPanTool       GvZoomPanTool;
typedef struct _GvZoomPanToolClass  GvZoomPanToolClass;

struct _GvZoomPanTool
{
    GvTool tool;
};

struct _GvZoomPanToolClass
{
    GvToolClass parent_class;
};

GtkType gv_zoompan_tool_get_type(void);
GvTool* gv_zoompan_tool_new(void);

#endif /* __GV_ZOOMPAN_TOOL_H__ */
