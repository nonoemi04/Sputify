/*********************************************************************/
/* Users.h - Header file for module Users.c                          */
/* Copyright: 2020                                                   */
/* License: Technical University of Cluj Napoca                      */
/* Authors: Calomfirescu Radu & Penzes Noemi                         */
/* Version: 07.01.2021                                               */
/* Updates:                                                          */
/*********************************************************************/

#ifndef USERS_H
#define USERS_H

///Other headers required

#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

///Function declarations

extern void Add_user(int);
extern int Count_users(int);
extern void Display_user();
extern void Manage_user();
extern void Delete_user();

#endif // USERS_H
