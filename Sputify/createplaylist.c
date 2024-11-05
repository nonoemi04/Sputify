#include "createplaylist.h"







/// This function creates a playlist ///

void Create_Playlist()
{
    int ok = 1;
    int option;
    char name[30];
    printf("\n\n\n\t\t ****************** CREATE A PLAYLIST ******************\n");
    printf("\n\t\tEnter a name for your playlist: ");
    scanf("%s", name);
    strcpy((playlist_ptr+ct1)->name_playlist, name);
    Default_memory_allocation_playlist_for_songs(D_MEMO, ct1);
   // getline(nululet = p[ct1].name, sizeof(p[ct1].name), stdin);
   // strtok(p[ct1].name, "\n");
    printf("\n\t\t****************************************************\n");
    int ct_songs = 1;
    while (ok == 1)
    {
        printf("\n\n\t\t\tChoose a song to add to your playlist");
        View_Songs();
        printf("\n\t0. Save the playlist and close");
        printf("\n\t\t****************************************************");
        printf("\n\t\tEnter your option: ");
        scanf("%d", &option);
        if(option >= ctr)
            printf("Not a valid option...");
        else if(option)
        {
            ((playlist_ptr + ct1)->s + ct_songs)->id = (songs_ptr + option)->id;
            strcpy(((playlist_ptr + ct1)->s + ct_songs)->genre, (songs_ptr + option)->genre);
            strcpy(((playlist_ptr + ct1)->s + ct_songs)->name, (songs_ptr + option)->name);
            strcpy(((playlist_ptr + ct1)->s + ct_songs)->artist, (songs_ptr + option)->artist);
            (playlist_ptr + ct1)->length_songs = ct_songs;
            ct_songs ++;
            printf("\n\t\t******************** Succes! ***********************");
            sleep(1);
            clear();
        }
        else
            ok = 0;
    }
    ct1++;

    printf("\n\t\t*********** The playlist has been created! **********\n");

    Update_Playlist(ID);

    sleep(1);
    clear();
}






/// This function reads the data from the file ///

void Read_Playlist(int id)
{
    char name[37], songgenre[37], songname[37], songartist[37];
    int length;
    switch(id)
    {
        case 1:
             ptr = fopen("Playlist_User1.txt", "r");
             break;
        case 2:
             ptr = fopen("Playlist_User2.txt", "r");
             break;
        case 3:
             ptr = fopen("Playlist_User3.txt", "r");
             break;
        case 4:
             ptr = fopen("Playlist_User4.txt", "r");
             break;
    }

    while (fscanf(ptr, "%s\t%d", name, &length) != EOF)
    {
        Default_memory_allocation_playlist_for_songs(D_MEMO, ct1);
        strcpy((playlist_ptr + ct1)->name_playlist, name);
        (playlist_ptr + ct1)->length_songs = length;
        for(int i = 1; i <= length; i ++)
        {
            fscanf(ptr, "%d\t\t%s\t\t%s\t\t%s", &id, songgenre, songname, songartist);
            ((playlist_ptr + ct1)->s + i)->id = id;
            strcpy(((playlist_ptr + ct1)->s + i)->genre, songgenre);
            strcpy(((playlist_ptr + ct1)->s + i)->name, songname);
            strcpy(((playlist_ptr + ct1)->s + i)->artist, songartist);
        }
        ct1 ++;
    }

    fclose(ptr);

}






/// This function updates the file with data from the list ///

void Update_Playlist(int id)
{
    switch(id)
    {
        case 1:
             ptr = fopen("Playlist_User1.txt", "w");
             break;
        case 2:
             ptr = fopen("Playlist_User2.txt", "w");
             break;
        case 3:
             ptr = fopen("Playlist_User3.txt", "w");
             break;
        case 4:
             ptr = fopen("Playlist_User4.txt", "w");
             break;
    }
    for(int i = 1; i < ct1; i ++)
    {
        fprintf(ptr, "%s\t%d\n", (playlist_ptr + i)->name_playlist, (playlist_ptr + i)->length_songs);
        for(int j = 1; j <= (playlist_ptr + i)->length_songs; j ++)
        {
            fprintf(ptr, "%d", ((playlist_ptr + i)->s + j)->id);
            fprintf(ptr, "\t\t%s", ((playlist_ptr + i)->s + j)->genre);
            fprintf(ptr, "\t\t%s", ((playlist_ptr + i)->s + j)->name);
            fprintf(ptr, "\t\t%s\n", ((playlist_ptr + i)->s + j)->artist);
        }
    }

    fclose(ptr);
}







/// This function shows the data in the list ///

void View_Playlists()
{
    printf("\n\n\n\t\t******************************************************\n");
    printf("\t\t**************    LIST OF PLAYLISTS    ***************\n");
    printf("\t\t******************************************************\n\n");
    if(ct1 == 1)
        printf("\n\n\n\t\t*************** There are no playlists ***************\n");
    else
    {
        for(int i = 1; i < ct1; i ++)
        {
            printf("\t\t%s\t%d\n", (playlist_ptr + i)->name_playlist, (playlist_ptr + i)->length_songs);
            printf("\t\t******************************************************\n");
            for(int j = 1; j <= (playlist_ptr + i)->length_songs; j ++)
            {
                printf("\t\t%d", ((playlist_ptr + i)->s + j)->id);
                printf("\t\t%s", ((playlist_ptr + i)->s + j)->genre);
                printf("\t\t%s", ((playlist_ptr + i)->s + j)->name);
                printf("\t\t%s\n", ((playlist_ptr + i)->s + j)->artist);
            }
            printf("\n\n");
        }
    }
}

