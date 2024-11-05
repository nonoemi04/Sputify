/*********************************************************************/
/* Login.h - Header file for module Login.c                          */
/* Copyright: 2020                                                   */
/* License: Technical University of Cluj Napoca                      */
/* Authors: Calomfirescu Radu & Penzes Noemi                         */
/* Version: 07.01.2021                                               */
/* Updates:                                                          */
/*********************************************************************/

#ifndef LOGIN_H
#define LOGIN_H
#define D_MEMO 100
#define U_MEMO 200

///Other headers required

#include <stdio.h>
#include <stdlib.h>
#include "Users.h"
#include "menu.h"

///Function declarations

extern void Default_memory(int default_memo);
extern void Upgrade_memory(int upgrade_memo);
extern void Default_memory_allocation_playlist_for_songs(int default_memo, int ct);
extern void Login();
extern void Access_acc();

///Variable declarations

char user[20], pwd[20], USER[20], PWD[20], k[10], type[10];
int id;

#endif // LOGIN_H
