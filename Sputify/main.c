#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "Login.h"

/// This is the main function ///

int main()
{

    printf("\n\n\n\t\t******************************************************\n");
    printf("\t\t*********   WELCOME TO OUR MUSICAL LIBRARY   *********\n");
    printf("\t\t******************************************************\n\n");
    ctr = 1;
    ct1 = 1;
    Login();
    clear();
    Read_fdata(ID);
    Read_Playlist(ID);
    Menu();

    return 0;
}
