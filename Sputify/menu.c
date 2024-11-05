#include "menu.h"

void Menu()
{
    int option;
    int ok = 1;
    printf("\n\n\n\t\t*********************************************************\n");
    printf("\t\t**** Successfully logged into account %s! ID = %d  ****\n", user, id);
    printf("\t\t*********************************************************\n\n");
    while(ok == 1)
    {
        printf("\n\n\n\t\t*********************************************************\n");
        printf("\t\t*******************    MAIN MENU    *********************\n");
        printf("\t\t*********************************************************\n\n");
        printf("\t\t1.    Add a song\n");
        printf("\t\t2.    Delete a song\t\n");
        printf("\t\t3.    View all songs\t\n");
        printf("\t\t4.    Create a playlist\t\n");
        printf("\t\t5.    View your playlists\t\n");
        printf("\t\t6.    View users\t\n");
        printf("\t\t7.    Log into another account\t\n");
        printf("\t\t8.    Instructions and Information\t\n");
        printf("\n\t\t***** Enter any other key to close the application ******\n");
        printf("\n\t\tEnter your option: ");
        scanf("%d", &option);
        switch(option) {
            case 1:
                 sleep(1);
                 clear();
                 add_song();
                break;
            case 2:
                 sleep(1);
                 clear();
                 Delete_Song();
                break;
            case 3:
                 sleep(1);
                 clear();
                 View_Songs();
                 printf("\n\t\t************** Press any letter to go back ************\n");
                 scanf("%c", &option);
                 scanf("%c", &option);
                 clear();
                break;
            case 4:
                 sleep(1);
                 clear();
                 Read_Playlist();
                 Create_Playlist();
                break;
            case 5:
                 sleep(1);
                 clear();
                 View_Playlists();
                 printf("\n\t\t************** Press any letter to go back ************\n");
                 scanf("%c", &option);
                 scanf("%c", &option);
                 clear();
                break;
            case 6:
                 sleep(1);
                 clear();
                 Manage_user();
                break;
            case 7:
                 sleep(1);
                 clear();
                 Access_acc();
                 Read_fdata();
                break;
            case 8:
                 sleep(1);
                 clear();
                 Information();
                 printf("\n\t\t************** Press any letter to go back ************\n");
                 scanf("%c", &option);
                 scanf("%c", &option);
                 clear();
                break;
            default:
                free(songs_ptr);
                free(playlist_ptr);
                clear();
                ok = 0;
        }
    }
}








/// This function clears the console ///

void clear() {

    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #endif
}







/// This function shows the instructions and some basic information///

void Information()
{

    printf("\n\n\n\t\t*********************************************************");
    printf("\n\t\t********************** INFORMATION **********************");
    printf("\n\t\t*********************************************************\n");
    printf("\n\t\tHere we provide you some information about the service we offer\n");
    printf("\n\t1)Our application only allows a maximum of 4 users at a time.\n");
    printf("\n\t2)The normal type user(default) allows a maximum of 100 songs.\n");
    printf("\n\t3)To navigate through our app, you will have to input the corresponding\n\t number of the option you desire.\n");
    printf("\n\t4)When working with songs, the option refers to the id number of the song.\n");
    printf("\n\t5)_Press any key_ requires you to press ENTER after input.\n");
    printf("\n\n\t\tThe project has been created by Calomfirescu Radu and \n\tPenzes Noemi. We plan to add a premium version for accounts in\n\tthe near future and an option to delete the current users and playlists.\n\n\t\tThank you for using our application!");
    printf("\n\n\t\t*********************************************************");

}


