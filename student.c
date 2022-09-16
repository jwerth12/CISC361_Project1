/*
* student.c
* Created on 9/10/2022
* Author: Jenn Werth
*/

#include "student.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

student_t *head;
student_t *tail;

student_t * makeStudent() {

    student_t *student = (student_t *) malloc(sizeof(student_t));
    int len;

    char last[BUFFERSIZE];
    printf("Enter student last name \n");
    fgets(last, 128, stdin);
    len = (int) strlen(last);
    last[len-1] = '\0';
    student->last = (char *) malloc(len);
    strcpy(student->last, last);

    char first[BUFFERSIZE];
    printf("Enter a student's first name \n");
    fgets(first, 128, stdin);
    len = (int) strlen(first);
    first[len-1] = '\0';
    student->first = (char *) malloc(len);
    strcpy(student->first, first);

    printf("Enter student id\n");
    long id;
    scanf("%li", &id);
    getchar();
    student->id = id;

    char year[BUFFERSIZE];
    printf("Enter student year (Freshman, Sophomore, Junior, Senior) \n");
    fgets(year, 128, stdin);
    len = (int) strlen(year);
    year[len-1] = '\0';
    student->year = (char *) malloc(len);
    strcpy(student->year, year);

    printf("Enter student's expected graduation year\n");
    int grad;
    scanf("%d", &grad);
    getchar();
    student->grad = grad;
    return student;
}

void printForward() {
    student_t *current = head;
    if (head == NULL) {
        printf("No students currently in list\n");
    }
    else {
        while (current != NULL) {
            printf("Name: %s, %s \nID Number: %li \nCurrent Year: %s \nExpected Graduation: %d\n", current->last, current->first, current->id, current->year, current->grad);
            current = current->next;
        }
    }
}

void printBackward() {
    student_t *current = tail;
    if (head == NULL)
    {
        printf("No students currently in list\n");
    }
    else
    {
        while (current != NULL)
        {
            printf("Name: %s, %s \nID Number: %li \nCurrent Year: %s \nExpected Graduation: %d\n", current->last, current->first, current->id, current->year, current->grad);
            current = current->prev;
        }
    }
}
void addStudent(student_t **head, student_t **tail) {
    student_t * newStudent = makeStudent();

    if (*head == NULL) {
        *head = newStudent;
        *tail = newStudent;
    }
    else
    {
        student_t *current = *head;

        while (current->next != NULL)
        {
            current = current->next;
        }

        newStudent->prev = current;
        newStudent->next = NULL;

        current->next = (student_t *)malloc(sizeof(student_t));
        current->next = newStudent;

        *tail = newStudent;
        current->next->next = NULL;
    }
}

void removeStudent(student_t **head, student_t **tail, char *remove) {

    student_t *current = *head;
    while (current != NULL) {
        if (strcmp(current->last, remove) == 0) {
            if (current == *head) {
                if (current->next == NULL) {
                    *head = NULL;
                }
                else {
                    current->next->prev = NULL;
                    *head = current->next;
                }
                
                // free current
            }
            else if (current->next == NULL) {
                current->prev->next = NULL;
                *tail = current->prev;
            }
            else {
                current->next->prev = current->prev;
                current->prev->next = current->next;
            } 
            //free(current);
        }
        current = current->next;
    }
    free(current);
}

// idk about this one 
void quit() {
    student_t *hold;
    while (head != NULL) {
        hold = head; 
        free(hold->last);
        free(hold->first);
        free(hold->year);
        head = head->next;
    }
}

int main() {

    student_t *student = (student_t *) malloc(sizeof(student_t));
    student->first = NULL;
    student->last = NULL;
    student->next = NULL;
    student->prev = NULL;

    head = student;
    tail = student;
    
    int option = 0;

    printf("Welcome! Let's get started! \n Type the corresponding number to the action you would like to perform.");

    while (option != 5) {
        printf("What would you like to do? \n 1. Add a student \n 2. Remove a student \n 3. Print List Forward \n 4. Print List Backward \n 5. Exit \n");
        scanf("%d", &option);
        getchar();

        if (option == 1)
        {
            addStudent(&head, &tail);
        }
        else if (option == 2)
        {
            if (head == NULL) {
                printf("There are no students in the list to be deleted\n");
            }
            else
            {

                char remove[128];
                printf("Type the last name of the student(s) you would like to remove\n");
                fgets(remove, 128, stdin);
                int len = (int)strlen(remove);
                remove[len - 1] = '\0';
                removeStudent(&head, &tail, remove);
            }
        }
        else if (option == 3)
        {
            printForward();
        }
        else if (option == 4)
        {
            printBackward();
        }
        else if (option == 5)
        {
            quit(&head);
        }
        else
        {
            printf("Please enter a valid option\n");
        }
    }
}


/*

valgrind./ executable 

scp command to move file to his virtual machine 

*/
