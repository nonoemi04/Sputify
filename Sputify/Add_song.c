#include "Add_song.h"






/// This function inputs the data from the keyboard ///

void Name_and_Artist()
{
    printf("\n\n\n\t\t*********************  NEW SONG  ***********************\n\n");
    (songs_ptr + ctr)->id = ctr;
    printf("\t\tGenre: %s", (songs_ptr + ctr)->genre);
    printf("\n\t\t********************************************************\n");
    printf("\t\tSong name: ");
    gets((songs_ptr + ctr)->name);
    gets((songs_ptr + ctr)->name);
    printf("\n\t\t********************************************************\n");
   // fgets((songs_ptr+ctr)->name, sizeof((songs_ptr+ctr)->name), stdin);
    printf("\t\tArtist name: ");
    gets((songs_ptr + ctr)->artist);
    printf("\n\t\t********************************************************\n");
    //strtok((songs_ptr+ctr)->name, "\n");
    //strtok((songs_ptr+ctr)->artist, "\n");
    printf("\n\t\t*********** You have entered a new song! ***************");

    ctr++;
    Update_FileData(ID);

    sleep(2);
    clear();

}






///This function chooses the genre ///

void add_song()
{

    int option;
    printf("\n\n\n\t\t********************************************************\n");
    printf("\t\t******************    MUSIC GENRES    ******************\n");
    printf("\t\t********************************************************\n\n");
    printf("\n");
    printf("\t\t1.     K-Pop\n");
    printf("\t\t2.     Rock\n");
    printf("\t\t3.     Manele\n");
    printf("\t\t4.     Rap\n");
    printf("\t\t5.     Jazz\n");
    printf("\t\t6.     Electro\n");
    printf("\t\t7.     Metal\n");
    printf("\t\t8.     Latino\n");
    printf("\t\t9.     Opera\n\n");
    printf("\t\t0.     Go back\n\n");
    printf("\t\t****************************************************\n\n");
    printf("\t\tPlease enter your genre option:  ");
    scanf("%d", &option);
    switch (option) {
        case 1:
            clear();
            strcpy((songs_ptr+ctr)->genre, "K-pop");
            Name_and_Artist();
            break;
        case 2:
            clear();
            strcpy((songs_ptr+ctr)->genre, "Rock");
            Name_and_Artist();
            break;
        case 3:
            clear();
            strcpy((songs_ptr+ctr)->genre, "Manele");
            Name_and_Artist();
            break;
        case 4:
            clear();
            strcpy((songs_ptr+ctr)->genre, "Rap");
            Name_and_Artist();
            break;
        case 5:
            clear();
            strcpy((songs_ptr+ctr)->genre, "Jazz");
            Name_and_Artist();
            break;
        case 6:
            clear();
            strcpy((songs_ptr+ctr)->genre, "Electro");
            Name_and_Artist();
            break;
        case 7:
            clear();
            strcpy((songs_ptr+ctr)->genre, "Metal");
            Name_and_Artist();
            break;
        case 8:
            clear();
            strcpy((songs_ptr+ctr)->genre, "Latino");
            Name_and_Artist();
            break;
        case 9:
            clear();
            strcpy((songs_ptr+ctr)->genre, "Opera");
            Name_and_Artist();
            break;
        case 0:
            break;
        default:
            printf("This is not a genre!");
            break;


    }


}






/// This function deletes a song entry ///

void Delete_Song()
{
    int option, i;
    if(ctr == 1)
        printf("\n\n\n\t\t********** There are no songs to delete **********");
    else
    {
        printf("\n\n\n\t\t********** Choose a song to delete ***********\n");
        for(i = 1; i < ctr; i ++)
        {
            printf("\n\t     %d.\t", i);
            printf("\t%s", (songs_ptr + i)->genre);
            printf("\t%s",(songs_ptr + i)->name);
            printf("\t%s", (songs_ptr + i)->artist);
        }
        printf("\n\n\t\t**********************************************\n");
        printf("\n\t\tEnter your option: ");
        scanf("%d", &option);
        if (option >= ctr)
            printf("\n\t\t*********** This is not a valid choice **********");
        else
        {
            for(i = option; i < ctr; i ++)
                {
                    strcpy((songs_ptr + i)->genre, (songs_ptr + i + 1)->genre);
                    strcpy((songs_ptr + i)->name, (songs_ptr + i + 1)->name);
                    strcpy((songs_ptr + i)->artist, (songs_ptr + i + 1)->artist);
                }
            ctr--;
        }
    }
    Update_FileData(ID);
    sleep(1);
    clear();
}






/// This function updates the file with data from the list ///

void Update_FileData(int id)
{
    switch(id)
    {
        case 1:
             ptr = fopen("User1.txt", "w");
             break;
        case 2:
             ptr = fopen("User2.txt", "w");
             break;
        case 3:
             ptr = fopen("User3.txt", "w");
             break;
        case 4:
             ptr = fopen("User4.txt", "w");
             break;
    }
    for(int i = 1; i < ctr; i ++)
    {
        fprintf(ptr, "%3d", (songs_ptr + i)->id);
        fprintf(ptr, "\t\t%18s", (songs_ptr + i)->genre);
        fprintf(ptr, "\t\t%18s", (songs_ptr + i)->name);
        fprintf(ptr, "\t\t%18s\n", (songs_ptr + i)->artist);
    }
    fclose(ptr);
}






/// This function reads the data from the file ///

void Read_fdata(int id)
{
    char genre[20], name[30], artist[20];

    switch(id)
    {
        case 1:
             ptr = fopen("User1.txt", "r");
             break;
        case 2:
             ptr = fopen("User2.txt", "r");
             break;
        case 3:
             ptr = fopen("User3.txt", "r");
             break;
        case 4:
             ptr = fopen("User4.txt", "r");
             break;
    }
    while (fscanf(ptr, "%d\t\t%s\t\t%s\t\t%s\n", &id, genre, name, artist) != EOF)
    {

        (songs_ptr + ctr)->id = id;
        strcpy((songs_ptr + ctr)->genre, genre);
        strcpy((songs_ptr + ctr)->name, name);
        strcpy((songs_ptr + ctr)->artist, artist);

        ctr ++;
    }
    fclose(ptr);

}






/// This function shows the data in the list ///

void View_Songs()
{
    int i = 0;
    char option;
    printf("\n\n\n\t\t******************************************************\n");
    printf("\t\t****************    LIST OF SONGS    *****************\n");
    printf("\t\t******************************************************\n\n");
    if(ctr == 1)
        printf("\n\t\t*********** There are no songs to be shown ***********\n");
    else
    {
        for(i = 1; i < ctr; i ++)
        {
            printf("      %3d.",  (songs_ptr + i)->id);
            printf("\tGenre: %8s|", (songs_ptr + i)->genre);
            printf("\tName: %16s|", (songs_ptr + i)->name);
            printf("\tArtist: %12s|\n", (songs_ptr + i)->artist);
        }
    }
}


