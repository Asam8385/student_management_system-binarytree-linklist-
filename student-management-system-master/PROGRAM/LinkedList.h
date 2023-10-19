/*
 * LinkedList.h
 * STUDENT DATABASE MANAGEMENT SYSTEM
 * Created by Hassif Abdulahi Mustafa on 18/03/2018.
*/

#ifndef LinkedList_h
#define LinkedList_h


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


#define max 2 // This defines the number of marks needed

struct Student{
    char   Name[20];
    float  Marks[max];
    char   numberOfStudent[100];
    struct Student *next;
};

struct Student *head = NULL;
void addingStudent(struct Student *head);
void addingMark( char *Name, int n, float Mark);
int  deleteStudentRecord(char *Name);
void PrintStudent(char *Name, struct Student *head);
void writeFILE(struct Student *head);
void readFILE(void);

//insert the student in the linked list
void addingStudent(struct Student *root){
    // if list is empty
    if (head == NULL) {
        head = root;
        head->next = NULL;
        return ;
    }
    
    // New Students will be added to the root of the list
    // Adds a new student by soring them alphabetically
    if (strcmp(root->Name, head->Name) < 0) {
        struct Student *current = head;
        head = root;
        head->next = current;  // Inserts in the begining of the list
        return ;
    }
    struct Student *hold = head;
    while (hold->next!=NULL) {
        if (strcmp(root->Name, hold->next->Name) < 0) {
            struct Student *current = hold->next;
            hold->next = root;
            root->next = current;   // Inserts at the end of the list
            return ;
        }
        hold = hold->next;
    }
    root->next = NULL;
    hold->next = root;
    return ;
}


// this function allocates memory for a student
void createStudent(char *sName, char *numberOfStudent, float marks[]) {
    // Creating the new Students:
    struct Student *new = (struct Student*) malloc(sizeof(struct Student)); // Allocates memory to new Node
    strcpy(new->Name, sName);     // Copy Students Info into New Node
    strcpy(new->numberOfStudent, numberOfStudent);
    int j;  for (j = 0; j < max; j++) {
        new->Marks[j] = marks[j];}
    new->next = NULL;
    addingStudent(new); // call add function to add student
}

//adding mark of a student
void addingMark( char *sName, int courseNumber, float mark){ // takes in name, number of course and marks as argument
    struct Student *current = head;
    while (current != NULL){
        if(strcmp(current->Name, sName) == 0){ // if name is the same as the name entred add mark
            current->Marks[courseNumber - 1] = mark; // mark added
            return;
        }
        else{
            current = current->next;
        }
    }
}

int deleteStudentRecord(char *sName)  // Remove Studemnt from database
{
    struct Student *current, *previous = NULL;
    current = head;
    while (current != NULL) //while is not empty
    {
        if (strcmp(current->Name, sName) == 0 )   // Compares Names in database with the name inputed
        {
            if (current == head)
            {
                head = current->next;       // Rework linked list
                free(current);             // Frees the node (desalocates memory)
                printf("\n %s Deleted\n", current->Name);
                return 1;
            }
            else
            {
                previous->next = current->next;    // Rework linked list
                free(current);                 // Frees the node (desalocates memory)
                printf("\n %s Deleted\n", current->Name);
                return 1;
            }
        }
        else
        {
            previous = current;
            current = current->next;      // Rework linked list
        }
    }
    
    return 0;
}


// this function is for printing a single student report
void PrintStudent(char *sName, struct Student *current){
    int j;
    if(strcmp(sName, current->Name) == 0){ // Compares Names in database with the name inputed
        printf("%s \t\t%s \n",
               current->Name, current->numberOfStudent);
        for (j = 0; j < max; j++)
        {
            printf("\t\t\t\t\tMarks[%d] = %.2f %%\n\n",
                   j+1, current->Marks[j]);
        }
        printf("\n");
        return;
    }
    else{
        PrintStudent(sName, current->next); // recursively recall function
    }
}

//print student report
void studentsReport(struct Student *current){
    int j;
    current = head;
    printf("THE REPORT OF ALL STUDENTS IS : \n\n");
    printf("Name \tStudent Number \tStudent Marks\n\n");
    
    while (current != NULL){
        printf("%s \t\t%s \n",
               current->Name, current->numberOfStudent);
        
        for (j = 0; j < max; j++)
            
        {
            printf("\t\t\t\tMarks[%d] = %.2f %%\n\n",
                   j+1, current->Marks[j]);
        }
        
        current = current->next;
    }
    return;
}
//save the student list into a file
void writeFILE(struct Student *head){
    FILE *FILE = fopen("StudentList.bin","wb");
    if (FILE != NULL)
    {
        struct Student *variable = head;
        struct Student *nextNode;
        
        
        while(variable != NULL){
            nextNode = variable->next;
            variable->next = NULL;
            
            fseek(FILE, 0, SEEK_END);
            fwrite(variable, sizeof(struct Student), 1, FILE);
            
            printf("WRITTING Student ***| %s |** \n", variable->Name);
            variable->next = nextNode;
            nextNode = NULL;
            variable = variable->next;
        }
        printf("\nFile Saved\n");
        fclose(FILE);
        return;
    }
    else {
        printf("\n Error\n");
    }
}

//read the student info from file
void readFILE(){
    struct Student *readStudent = (struct Student *)malloc(sizeof(struct Student));
    FILE *FILE = fopen("StudentList.bin", "rb");
    size_t j = fread(readStudent, sizeof(struct Student), 1, FILE);
    while(j == 1){
        printf("READING Student ***| %s |*** \n",readStudent->Name);
        addingStudent(readStudent);
        PrintStudent(readStudent->Name, readStudent);
        
        readStudent = (struct Student *)malloc(sizeof(struct Student));
        j = fread(readStudent, sizeof(struct Student), 1, FILE);
    }
    fclose(FILE);
    return;
}
#endif /* LinkedList_h */
