/******************************************************************************
 * $Id: gvundo.h,v 1.3 2000/06/20 13:27:08 warmerda Exp $
 *
 * Project:  OpenEV
 * Purpose:  Generic undo management.
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
 * $Log: gvundo.h,v $
 * Revision 1.3  2000/06/20 13:27:08  warmerda
 * added standard headers
 *
 */

#ifndef __GV_UNDO_H__
#define __GV_UNDO_H__

#include "gvdata.h"

void gv_undo_register_data(GvData *data);
void gv_undo_open(void);
void gv_undo_close(void);
void gv_undo_push(GvDataMemento *memento);
void gv_undo_pop(void);
void gv_undo_clear(void);
void gv_undo_enable();
void gv_undo_disable();
gint gv_undo_can_undo(void);
gint gv_undo_start_group(void);
void gv_undo_end_group(gint);

#endif /*__GV_UNDO_H__*/
