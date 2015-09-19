/******************************************************************************
 * $Id: gvmanager.h,v 1.6 2004/02/10 15:38:31 andrey_kiselev Exp $
 *
 * Project:  OpenEV
 * Purpose:  Preferences (and other?) manager.  Singleton object.
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
 * $Log: gvmanager.h,v $
 * Revision 1.6  2004/02/10 15:38:31  andrey_kiselev
 * Added gv_manager_add_dataset() function.
 *
 * Revision 1.5  2001/01/30 14:29:33  warmerda
 * added gv_manager_dump
 *
 * Revision 1.4  2000/06/29 14:38:22  warmerda
 * added busy status, and idle task list
 *
 * Revision 1.3  2000/06/26 15:12:00  warmerda
 * Added dataset/gvraster management
 *
 * Revision 1.2  2000/06/20 13:27:08  warmerda
 * added standard headers
 *
 */

#ifndef __GV_MANAGER_H__
#define __GV_MANAGER_H__

#include <gtk/gtkobject.h>
#include "gvtypes.h"
#include "gvproperties.h"
#include "gvraster.h"

#define GV_TYPE_MANAGER              (gv_manager_get_type ())
#define GV_MANAGER(obj)              (GTK_CHECK_CAST ((obj), GV_TYPE_MANAGER, GvManager))
#define GV_MANAGER_CLASS(klass)      (GTK_CHECK_CLASS_CAST ((klass), GV_TYPE_MANAGER, GvManagerClass))
#define GV_IS_MANAGER(obj)           (GTK_CHECK_TYPE ((obj), GV_TYPE_MANAGER))
#define GV_IS_MANAGER_CLASS(klass)   (GTK_CHECK_CLASS_TYPE ((klass), GV_TYPE_MANAGER))

typedef struct _GvManager       GvManager;
typedef struct _GvManagerClass  GvManagerClass;

typedef struct {
    GDALDatasetH  dataset;

    GvRaster     **rasters;
} GvDataset;

typedef struct _idle_task {
    struct _idle_task *next;
    char         *name;
    int          priority;
    GtkFunction  callback;
    void         *task_info;
} GvIdleTask;

struct _GvManager
{
    GtkObject  object;

    GvProperties preferences;

    GPtrArray *datasets;

    int        busy_flag;    /* TRUE if busy */

    GvIdleTask*idle_tasks; 
};

struct _GvManagerClass
{
    GtkObjectClass parent_class;

    void (* preferences_changed)(GvManager *man);
    void (* busy_changed)(GvManager *man);
};

GtkType    gv_manager_get_type   (void);
GvManager* gv_manager_new        (void);
GvManager* gv_get_manager        (void);

void       gv_manager_dump( GvManager * );
const char* gv_manager_get_preference(GvManager *, const char *);
GvProperties* gv_manager_get_preferences(GvManager *);
void       gv_manager_set_preference(GvManager *, const char *, const char *);

GDALDatasetH gv_manager_add_dataset( GvManager *, GDALDatasetH );
GDALDatasetH gv_manager_get_dataset( GvManager *, const char * );
GvRaster    *gv_manager_get_dataset_raster( GvManager *manager,
                                            GDALDatasetH dataset, int band );

void       gv_manager_set_busy( GvManager *manager, int busy_flag );
int        gv_manager_get_busy( GvManager *manager );
void       gv_manager_queue_task( GvManager *manager,
                                  const char *task_name, int priority,
                                  GtkFunction callback, void *task_info );
void       gv_manager_dequeue_task( GvManager *manager, GvIdleTask *task );

#endif /* __GV_MANAGER_H__ */
