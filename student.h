/*
* student.h
* Created on 9/10/2022
* Author: Jenn Werth
*/

#ifndef STUDENT_H
#define STUDENT_H

typedef struct Student {
    char *first;
    char *last;
    long id;
    char *year;
    int grad;
    struct Student *prev;
    struct Student *next;
} student_t;

student_t * makeStudent();

void addStudent(student_t **student, student_t **tail);

void removeStudent(student_t **head, student_t **tail, char *last);

void printForward();
void printBackward();

void quit();

#endif /* STUDENT_HP */

// add student, delete student, print forward, print backward
/*

student_t *head;
student_t *tail;
student_t *current;
*/
