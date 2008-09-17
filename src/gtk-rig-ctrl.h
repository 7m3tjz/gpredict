/* -*- Mode: C; tab-width: 4; indent-tabs-mode: t; c-basic-offset: 4 -*- */
/*
  Gpredict: Real-time satellite tracking and orbit prediction program

  Copyright (C)  2001-2007  Alexandru Csete, OZ9AEC.

  Authors: Alexandru Csete <oz9aec@gmail.com>

  Comments, questions and bugreports should be submitted via
  http://sourceforge.net/projects/gpredict/
  More details can be found at the project home page:

  http://gpredict.oz9aec.net/
 
  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.
  
  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  
  You should have received a copy of the GNU General Public License
  along with this program; if not, visit http://www.fsf.org/
*/
#ifndef __GTK_RIG_CTRL_H__
#define __GTK_RIG_CTRL_H__ 1

#include <glib.h>
#include <glib/gi18n.h>
#include <gtk/gtk.h>
#include "sgpsdp/sgp4sdp4.h"
#include "gtk-sat-module.h"
#include "radio-conf.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */




#define GTK_TYPE_RIG_CTRL          (gtk_rig_ctrl_get_type ())
#define GTK_RIG_CTRL(obj)          GTK_CHECK_CAST (obj,\
				                   gtk_rig_ctrl_get_type (),\
						           GtkRigCtrl)

#define GTK_RIG_CTRL_CLASS(klass)  GTK_CHECK_CLASS_CAST (klass,\
							 gtk_rig_ctrl_get_type (),\
							 GtkRigCtrlClass)

#define IS_GTK_RIG_CTRL(obj)       GTK_CHECK_TYPE (obj, gtk_rig_ctrl_get_type ())


typedef struct _gtk_rig_ctrl      GtkRigCtrl;
typedef struct _GtkRigCtrlClass   GtkRigCtrlClass;



struct _gtk_rig_ctrl
{
	GtkVBox vbox;
    
    GtkWidget *SatFreq;
    GtkWidget *RigFreq;
    
    /* target status labels*/
    GtkWidget *SatAz,*SatEl,*SatCnt;
    GtkWidget *SatRng,*SatRngRate,*SatDop;
   
    /* other widgets */
    GtkWidget *DevSel;   /*!< Device selector */
    GtkWidget *LO;       /*!< Local oscillator */
    GtkWidget *LockBut;
    
    radio_conf_t *conf;  /*!< Radio configuration */
    
    GSList *sats;       /*!< List of sats in parent module */
    sat_t  *target;     /*!< Target satellite */
    pass_t *pass;       /*!< Next pass of target satellite */
    qth_t  *qth;        /*!< The QTH for this module */
    
    guint delay;       /*!< Timeout delay. */
    guint timerid;     /*!< Timer ID */
    
    gboolean tracking;  /*!< Flag set when we are tracking a target. */
    gboolean busy;      /*!< Flag set when control algorithm is busy. */
    gboolean engaged;   /*!< Flag indicating that rig device is engaged. */
    gint     errcnt;    /*!< Error counter. */
};

struct _GtkRigCtrlClass
{
	GtkVBoxClass parent_class;
};



GtkType    gtk_rig_ctrl_get_type (void);
GtkWidget* gtk_rig_ctrl_new      (GtkSatModule *module);
void       gtk_rig_ctrl_update   (GtkRigCtrl *ctrl, gdouble t);


#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __GTK_RIG_ctrl_H__ */