/******************************************************************************
 * $Id: gvrecords.h,v 1.5 2003/08/06 22:26:03 warmerda Exp $
 *
 * Project:  OpenEV
 * Purpose:  GvRecords declarations.
 * Author:   Frank Warmerdam, warmerdam@pobox.com
 *
 ******************************************************************************
 * Copyright (c) 2003, Frank Warmerdam <warmerdam@pobox.com>
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
 * $Log: gvrecords.h,v $
 * Revision 1.5  2003/08/06 22:26:03  warmerda
 * added progress monitor to gv_records load/save funcs
 *
 * Revision 1.4  2003/08/06 17:07:44  warmerda
 * added support to save only selected records in gv_records_to_dbf
 *
 * Revision 1.3  2003/07/27 04:57:28  warmerda
 * complete implementation
 *
 * Revision 1.2  2003/05/23 20:44:25  warmerda
 * fixed header
 *
 * Revision 1.1  2003/05/23 20:43:08  warmerda
 * New
 *
 */

#ifndef __GV_RECORDS_H__
#define __GV_RECORDS_H__

#include "gvdata.h"
#include "gdal.h"

#define GV_TYPE_RECORDS           (gv_records_get_type ())
#define GV_RECORDS(obj)           (GTK_CHECK_CAST ((obj), GV_TYPE_RECORDS,\
                                                  GvRecords))
#define GV_RECORDS_CLASS(klass)   (GTK_CHECK_CLASS_CAST((klass),GV_TYPE_RECORDS,\
                                                       GvRecordsClass))
#define GV_IS_RECORDS(obj)        (GTK_CHECK_TYPE ((obj), GV_TYPE_RECORDS))
#define GV_IS_RECORDS_CLASS(klass) (GTK_CHECK_CLASS_TYPE ((klass), GV_TYPE_SHAPES))

#define GV_RFT_INTEGER  1
#define GV_RFT_FLOAT    2
#define GV_RFT_STRING   3

#define GV_NULL_MARKER  '\01'

typedef struct
{
    GvDataClass parent_class;
} GvRecordsClass;

typedef struct
{
    GvData data;

    int nRecordLength;

    int nFieldCount;
    char **papszFieldName;
    int *panFieldOffset;
    int *panFieldWidth;
    int *panFieldType;

    int nRecordCount;

    int nMainDataSize;
    char *pachMainData;

    int nUsedFieldCount;
    int *panUsedFieldList;

} GvRecords;

GtkType gv_records_get_type (void);
GvData* gv_records_new(void);
GvData* gv_records_from_dbf(const char *, GDALProgressFunc, void * );
int     gv_records_to_dbf(GvRecords *, const char *, int, int *,
                          GDALProgressFunc, void * );
GvData* gv_records_from_rec(const char *, GDALProgressFunc, void * );

gint gv_records_create_records(GvRecords *, int);
gint gv_records_num_records(GvRecords *);
gint gv_records_add_field(GvRecords *, const char *field_name, 
                          int field_type, int width, int precision );
const char *gv_records_get_raw_record_data(GvRecords *, int);
const char *gv_records_get_raw_field_data(GvRecords *, int, int);
void gv_records_set_raw_field_data(GvRecords *, int, int, const char *);
void gv_records_set_used_properties(GvRecords *, int nCount, int *panList);
int *gv_records_get_used_properties(GvRecords *, int *pnCount);

#endif /* ndef __GV_RECORDS_H__ */






