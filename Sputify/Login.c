#include "Login.h"




///These Functions allocate the storage of the app

void Default_memory(int d_memo)
{

    songs_ptr = (struct song *)malloc(D_MEMO * sizeof(struct song));
    playlist_ptr = (struct playlist *)malloc(D_MEMO * sizeof(struct playlist));


}
void Default_memory_allocation_playlist_for_songs(int d_memo, int ct)
{

    (playlist_ptr + ct)->s = (struct song *)malloc(D_MEMO * sizeof(struct song));

}
/*
void Upgrade_memory(int u_memo)
{

    songs_ptr = (struct song *)malloc(U_MEMO * sizeof(struct song));
    playlist_ptr = (struct playlist *)malloc(D_MEMO * sizeof(struct playlist));
}
*/

/// This function acceses the account ///

void Access_acc()
{
    if(songs_ptr != NULL)
    {
        free(songs_ptr);
        ctr = 1;
    }

    printf("\n\n\n\t\t******************************************************\n");
    printf("\t\t**** Please input your data to access an account! ****\n");
    printf("\t\t******************************************************\n");

    printf("\n\t\tUsername: ");
    scanf("%s", user);

    printf("\n\t\tPassword: ");
    scanf("%s", pwd);

    users_ptr=fopen("Users.txt", "r");

    int logged = 0;
    while(fscanf(users_ptr, "%d %s \t %s %s \t %s\n", &id, USER, k, PWD, type) != EOF)
    {
        if(strcmp(user, USER) == 0)
            if(strcmp(pwd, PWD) == 0)
            {
                printf("\n\t\t********************************************************");
                printf("\n\t\t**** Successfully logged into account %s! ID = %d ****", user, id);
                printf("\n\t\t********************************************************\n");
                sleep(1);
                Default_memory(D_MEMO);
                ctr = 1;
                ct1 = 1;
                ID = id;
                logged = 1;
                break;
            }
    }
    if(logged == 0)
    {
        printf("\n\t\tUser or password incorrect!\n");
        Access_acc();
    }
    fclose(users_ptr);
}





/// This function decides what is happening to the user ///

void Login()
{
    char user[20], pwd[20], USER[20], PWD[20], s[10], type[10];
    int id;

    songs_ptr = NULL;

    int nr = 0;
    nr = Count_users(nr);
    if(nr == 0)
    {
        printf("\n\t\t****** No account is registered!!! Plase sign up! ******\t");
        Add_user(nr);
        Access_acc();
    }

    else
    {
        printf( "\t\t\t\t Registered accounts: \n\n" );
        Display_user();
        if(nr == 4)
        {
            printf("\n\t\t\tMax no of accs, you can't add anymore!\n");
            Access_acc();
        }
        else
        {
            int option;
            printf("\n\t\t**** Would you like to add another one? (PRESS 1) ****\n");
            printf("\t\t** Or would you like to use one of these? (PRESS 2) **\n");
            printf("\n\t\tEnter your option: ");
            scanf("%d", &option);
            if (option == 1)
            {
                sleep(1);
                clear();
                Add_user(nr);
                Access_acc();
            }
            else
            {
                sleep(1);
                clear();
                Access_acc();
            }
        }
    }
}
