/******************************************************************************
 * $Id: gvpoitool.h,v 1.1 2002/02/28 18:52:22 gmwalter Exp $
 *
 * Project:  OpenEV
 * Purpose:  Pegion of interest editing mode.
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
 */

#ifndef __GV_POI_TOOL_H__
#define __GV_POI_TOOL_H__

#include "gvtypes.h"
#include "gvtool.h"

#define GV_TYPE_POI_TOOL            (gv_poi_tool_get_type ())
#define GV_POI_TOOL(obj)            (GTK_CHECK_CAST ((obj), GV_TYPE_POI_TOOL, GvPoiTool))
#define GV_POI_TOOL_CLASS(klass)    (GTK_CHECK_CLASS_CAST ((klass), GV_TYPE_POI_TOOL, GvPoiToolClass))
#define GV_IS_POI_TOOL(obj)         (GTK_CHECK_TYPE ((obj), GV_TYPE_POI_TOOL))
#define GV_IS_POI_TOOL_CLASS(klass) (GTK_CHECK_CLASS_TYPE ((klass), GV_TYPE_POI_TOOL))

typedef struct _GvPoiTool       GvPoiTool;
typedef struct _GvPoiToolClass  GvPoiToolClass;

struct _GvPoiTool
{
    GvTool tool;

    gint poi_marked : 1;
    gvfloat poi_size;  /* Default size of lines to draw to mark point */

    GvVertex v_center;
};

struct _GvPoiToolClass
{
    GvToolClass parent_class;

    void (* poi_changed)(GvPoiTool *tool);
};

GtkType gv_poi_tool_get_type(void);
GvTool* gv_poi_tool_new(void);

gint gv_poi_tool_get_point(GvPoiTool *tool, GvVertex *point);
gint gv_poi_tool_new_point(GvPoiTool *tool, GvVertex *point);

#endif /* __GV_POI_TOOL_H__ */
