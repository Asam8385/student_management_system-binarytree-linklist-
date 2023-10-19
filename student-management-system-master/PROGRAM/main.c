
/*
 * STUDENT DATABASE MANAGEMENT SYSTEM
 * Created by Hassif Abdulahi Mustafa on 18/03/2018.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Menu.h"
#include "LinkedList.h"
#include "BinaryTree.h"

#define max 2 // This defines the number of marks needed


int main(int argc, char const *argv[])
{
    int option = 0, exit = 0, arg;
    char mode[10];
    char l[10] = "linked";
    char b[10] = "binary";
    
    // Checks if user inputed a valid argument, and if not
    // then asks user to choose mode */
    if(argc==1 || ((strcmp(argv[1], l)!=0) &&
                   (strcmp(argv[1], b)!=0)))
    {
        printf("***| STUDENT DATABASE MANAGEMENT SYSTEM |***"
        "\n\nPlease Select/Enter the System Structure you Want:\n"
              "\n1.Linked                     \n2.Binary\n");
        scanf("%d", &arg);
        fpurge(stdin); // purge input for invalid characters.
        switch(arg){ case 1: strcpy(mode, l);  break;
                     case 2: strcpy(mode, b);  break; }
    }
    else { strcpy(mode, argv[1]); }
    
    // runs if mode is linked, and goes through while loop with the different
    // options until user quits
    if(strcmp(mode, l) == 0)
    {
        while(exit == 0)
        {
            menu();
            printf("\n\t\t\t  ** Type your Option **\n ");
            scanf("%d", &option);
            fpurge(stdin);
            switchLinkedList(option);
        }
}  else if(strcmp(mode, b) == 0){

        while(exit == 0)
        {
            menu();
            printf("\n\t\t\t  ** Type your Option **\n ");
            scanf("%d", &option);
            fpurge(stdin);
            switchBinaryTree(option);
        }
     }
}
        

