#ifndef STUDENT_H
#define STUDENT_H

#define MAX_STUDENTS 30

#define ERROR_STUDENT_NOT_FOUND "The student does not exist in the list."
#define ERROR_EMPTY_LIST "The student list is empty."
#define ERROR_FULL_LIST "The student list is full."
#define ERROR_STUDENT_REGISTERED "The student number is already assigned."

#define MIN_NUM_STUDENT 0
#define MAX_NUM_STUDENT 1000
#define MESSAGE_GET_NUMBER "Enter the student number [0-1000]: "

#define MAX_NAME_STUDENT 31
#define MESSAGE_GET_NAME "Enter the student name: "

#define MIN_DAY 1
#define MAX_DAY 31
#define MESSAGE_GET_BIRTH_DAY "Enter the day of birth: "

#define MIN_MONTH 1
#define MAX_MONTH 12
#define MESSAGE_GET_BIRTH_MONTH "Enter the month of birth: "

#define MIN_YEAR 1990
#define MAX_YEAR 2022
#define MESSAGE_GET_BIRTH_YEAR "Enter the year of birth: "

typedef struct
{
    int day, month, year;
} Data;

typedef struct
{
    int number;
    char name[MAX_NAME_STUDENT];
    Data birthDate;
} Student;

typedef struct
{
    int index;
    Student students[MAX_STUDENTS];
} Students;

void insertStudents(Students *students);
void searchStudents(Students students);
void updateStudents(Students *students);
void deleteStudents(Students *students);
void viewStudents(Students students);

#endif