/*********************************************************************/
/* Add_song.h - Header file for module Add_song.c                    */
/* Copyright: 2020                                                   */
/* License: Technical University of Cluj Napoca                      */
/* Authors: Calomfirescu Radu & Penzes Noemi                         */
/* Version: 07.01.2021                                               */
/* Updates:                                                          */
/*********************************************************************/

#ifndef ADD_SONG_H
#define ADD_SONG_H

///Other headers required

#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "Login.h"

///Function declarations

extern void add_Song();
extern void Name_and_Artist();
extern void Delete_Song();
extern void View_Songs();
extern void Update_FileData();
extern void Read_fdata();

#endif // ADD_SONG_H
