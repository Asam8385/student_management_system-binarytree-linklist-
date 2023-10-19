
/*
 * Menu.h
 * STUDENT DATABASE MANAGEMENT SYSTEM
 * Created by Hassif Abdulahi Mustafa on 18/03/2018.
 */

#ifndef Menu_h
#define Menu_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define max 2

#include "LinkedList.h"
#include "BinaryTree.h"

void menu(){

printf("\t\t\t  **************************************************************************************\n ");
printf("\t\t\t  **      |       |   |   STUDENT REPORT PROGRAM BY HASSIF 2018   |   |       |       **\n ");
printf("\t\t\t  **                                                                                  **\n ");
printf("\t\t\t  **      To Introduce New Student             ---->          choose  option '1'      **\n ");
printf("\t\t\t  **      To Introduce New Mark                ---->          choose  option '2'      **\n ");
printf("\t\t\t  **      To Remove Student                    ---->          choose  option '3'      **\n ");
printf("\t\t\t  **      To Print a Single Report             ---->          choose  option '4'      **\n ");
printf("\t\t\t  **      To Print Report of all Students      ---->          choose  option '5'      **\n ");
printf("\t\t\t  **      To Save to a FILE                    ---->          choose  option '6'      **\n ");
printf("\t\t\t  **      To Retrieve from a FILE              ---->          choose  option '7'      **\n ");
printf("\t\t\t  **      To EXIT                              ---->          choose  option '8'      **\n ");
printf("\t\t\t  **                                                                                  **\n ");
printf("\t\t\t  **************************************************************************************\n ");

}
    
void switchLinkedList (int option) {
    int exit = 0;
    int i, n;
    char Name[20], numberOfStudent[100];
    float Marks[max], Mark;
    struct Student *head = NULL;
    
switch(option){
        
    case 1:
        printf("Enter Student Name: ");
        scanf("%s", Name);
        printf("Enter Student Number: ");
        scanf("%s",numberOfStudent);
        for (i = 0; i < max; i++){
            Marks[i] = 0;
        }
        createStudent(Name, numberOfStudent, Marks);
        break;
        
    case 2:
        printf("\n Enter Student Name: ");
        scanf("%s", Name);
        printf("\n Enter Subject Number : ");
        scanf("%d", &n);
        printf("\n Enter the Mark: ");
        scanf("%f", &Mark);
        addingMark(Name, n, Mark);
        break;
        
    case 3:
        printf("\n Enter Name to Delete: ");
        scanf("%s", Name);
        deleteStudentRecord(Name);
        break;
        
    case 4:
        printf("\n Enter Name to Print: ");
        scanf("%s", Name);
        printf("Name \tStudent Number \tStudent Marks\n\n");
        PrintStudent(Name, head);
        break;
        
    case 5: studentsReport(head); break;
        
    case 6: writeFILE(head); break;
        
    case 7: readFILE(); break;
        
    case 8: exit = 1;   break;
        
    default:printf("\n\n ENTER ONLY ONE OF THE OPTIONS BELLOW\n\n");  exit = 0;
       
}
}


void switchBinaryTree (int option) {
    int exit = 0;
    int j, k;
    char name[20], studentNumber[100];
    float marks[10];
    float mark;
    struct Student *root = NULL;
        switch (option) {
            case 1:
                // Asks for input and passes it to studentNumber function
                printf("\nEnter Student Name: ");
                scanf("%s", name);
                printf("\nEnter Student number: ");
                scanf("%s", studentNumber);
                for (j = 0; j < max; j++) marks[j] = 0;
                    addStudent(name, studentNumber, marks);
                    break;
                
            case 2:
                // Asks for input and passes it to addMark function
                printf("\n ADD MARKS\n ");
                printf("\n Enter Student Name: ");
                scanf("%s", name);
                printf("\n Enter Subject Number out of [%d]: ", max);
                scanf("%d", &k);
                printf("\n Enter the Mark: ");
                scanf("%f", &mark);
                addMark(root, name, k, mark);
                break;
                
            case 3:
                // Asks for input and passes it to delete function
                printf("\n Enter a name to remove from the list: ");
                scanf("%s", name);
                delete(root, name);
                printf("\n %s deleted \n", name);
                balanceBinary(root);
                
                break;
                
            case 4:
                // Asks for input and searches the database for the
                // inputed student name and display the output
                printf("Enter Student Name: ");
                scanf("%s", name);
                printStudent(root, name);
                break;
                
            case 5:
                // Calls printRecord function and displays student records in the database
                printf("THE REPORT OF ALL STUDENTS IS : \n\n");
                printf("Name \tStudent Number \tStudent Marks\n");
                printRecord(root);
                break;
               
            // Calls writeList function
            case 6: writeList(root); break;
              
            //Calls readList function
            case 7: readList(); break;
                
            case 8: exit = 1;   break;
                
            default: printf("\n\n ENTER ONLY ONE OF THE OPTIONS BELLOW\n\n");
        }
        
}


#endif /* Menu_h */


