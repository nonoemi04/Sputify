#include "Users.h"
#define MAXUSERS 4






/// This function adds a user ///

void Add_user(int ctr)
{
    int id = ctr;
    char name[20], pwd[20], type[10]= "default", USER[20], PWD[20], s[10];

    users_ptr = fopen("Users.txt", "a+");

    printf("\n\n\n\t\t************* Please input the following: *************\n");
    printf("\n\t\tUsername: ");
    scanf("%s", name);
    printf("\n\t\t*******************************************************\n");
    printf("\n\t\tPassword: ");
    scanf("%s", pwd);
    printf("\n\t\t*******************************************************\n");

    int ok = 1;

    while(fscanf(users_ptr, "%d %s \t %s %s \t %s\n", &id, USER, s, PWD, type) != EOF)
        if(strcmp(name, USER) == 0)
        {
            ok = 0;
            break;
        }

    if(ok == 1)
        fprintf(users_ptr, "%d %s \t %s %s \t %s\n", id + 1, name, "password", pwd, type);
    else
    {
        printf("\n\n\t\t****** Username already taken, please try again *******\n");
        sleep(2);
        clear();
        Add_user(ctr);
    }
    printf("\n\t\t************** User successfully added!! **************\n");
    sleep(1);
    clear();
    fclose(users_ptr);

}






/// This function displays the user ///

void Display_user()
{
    int id;
    char user[20], pwd[20], type[10], s[10];

    users_ptr = fopen("Users.txt", "r");

    while(fscanf(users_ptr, "%d %s \t %s %s \t %s\n", &id, user, s, pwd, type) !=EOF)
    {
        printf(" \t\t%d. %s \t %s: %s\n", id, user, "type", type);
    }
    fclose(users_ptr);

}





/// This function counts the number of users ///

int Count_users(int CTR)
{
    int id;
    char user[20], pwd[20], type[10], s[10];

    users_ptr = fopen("Users.txt", "r");
    CTR = 0;
    while(fscanf(users_ptr, "%d %s \t %s %s \t %s\n", &id, user, s, pwd, type) != EOF)
        CTR++;

    fclose(users_ptr);

    return CTR;
}




/// This function tells information about the current status of the users ///

void Manage_user()
{
    char option1[10];
    int CTR = 0;
    CTR = Count_users(CTR);
    if(CTR > MAXUSERS-1)
    {
        printf("\n\t\tSorry, you have reached the maximum number of users!\n");
        printf("\n\t\tYou are logged in to account %s\n", user);
        printf("\n\t\t*******************************************************\n");
        Display_user();
        printf("\n\t\t*************** Press any letter to go back *************\n");
        scanf("%c", &option1);
        scanf("%c", &option1);
        clear();
    }
    else
    {

        printf("\n\n\n\t\tAt this moment, there are %d users, you can add %d more\n", CTR, MAXUSERS - CTR);
        printf("\n\t\tYou are logged in to account %s\n", user);
        printf("\n\t\t*******************************************************\n");
        Display_user();
        printf("\n\t\t\t\tWould you like to add one?\n\n\t\tPress (1) for yes\t\tPress any other key for no\n");
        printf("\n\t\tEnter your option: ");
        int option;
        scanf("%d", &option);

        if (option == 1)
            Add_user(CTR);

    }

}




/// WIP

void Delete_user()
{
      int id, option, i;
      char user[20], s[10]="password", pswd[20];

      ptr = fopen("Users.txt", "r+");

      int nruser = 0;

      while(fscanf(ptr, "%d %s \t %s %s \t \n", &id, user, s, pswd)!= EOF)
      {
          nruser ++;
          (user_ptr + id)->Id = id;
          strcpy((user_ptr+id)->username, user);
          strcpy((user_ptr+id)->pwd, pswd);
      }

      printf("\nChoose an user(enter the number of the user): ");
        scanf("%d", &option);

        if (option > nruser)
            printf("This is not a valid choice");
        else
        {
            for(i = option; i < nruser; i ++)
                {
                    ((user_ptr + i)->Id)=((user_ptr + i + 1)->Id);
                    strcpy((user_ptr + i)->username, (user_ptr + i + 1)->username);
                    strcpy((user_ptr + i)->pwd, (user_ptr + i + 1)->pwd);
                    ((user_ptr + i)->Id)--;
                    printf("%d ", (user_ptr + i)->Id);
                }
            nruser--;
            switch(option)
            {
                case 1:
                    ptr=fopen("User1.txt", "w+");
                    break;
                case 2:
                    ptr=fopen("User2.txt", "w+");
                    break;
                case 3:
                    ptr=fopen("User3.txt", "w+");
                    break;
                case 4:
                    ptr=fopen("User4.txt", "w+");
                    break;
            }

        }

    fclose(ptr);

    ptr=fopen("Users.txt", "w+");

    for (int i = 1; i <= nruser; i ++)
    {
        fprintf(ptr, "%d ", (user_ptr + i)->Id);
        fprintf(ptr, "%s \t", (user_ptr + i)->username);
        fprintf(ptr, " %s", s);
        fprintf(ptr, " %s \t \n", (user_ptr + i)->pwd);
    }

    fclose(ptr);
    Access_acc();
    Menu();
}


