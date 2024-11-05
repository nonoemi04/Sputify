/*********************************************************************/
/* menu.h - Header file for module menu.c                            */
/* Copyright: 2020                                                   */
/* License: Technical University of Cluj Napoca                      */
/* Authors: Calomfirescu Radu & Penzes Noemi                         */
/* Version: 07.01.2021                                               */
/* Updates:                                                          */
/*********************************************************************/


#ifndef MENU_H
#define MENU_H

#define D_MEMO 100
#define U_MEMO 200

///Other headers required
#include <stdio.h>
#include <stdlib.h>
#include "Add_song.h"
#include "createplaylist.h"
#include "Login.h"
#include "Users.h"

///Constant declarations

FILE *ptr, *users_ptr;

int ctr, ct1, ID;

struct song {
    int id;
    char genre[20];
    char name[30];
    char artist[20];
};

struct playlist {
    char name_playlist[30];
    int length_songs;
    struct song *s;
};

struct users {
    int Id;
    char username[20];
    char pwd[20];
};

struct playlist *playlist_ptr;
struct song *songs_ptr;
struct users *user_ptr;

///Function declarations

extern void menu();
extern void Information();

#endif // MENU_H
