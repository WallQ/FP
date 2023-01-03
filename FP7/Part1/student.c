#include "student.h"
#include "input.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void displayStudent(Student student)
{
    printf("\n%3d %-30s %d/%d/%d", student.number, student.name, student.birthDate.day, student.birthDate.month, student.birthDate.year);
}

int searchStudent(Students students, int number)
{
    for (size_t i = 0; i < students.index; i++)
    {
        if (students.students[i].number == number)
        {
            return i;
        }
    }

    return -1;
}

int insertStudent(Students *students)
{
    int number = getInt(MIN_NUM_STUDENT, MAX_NUM_STUDENT, MESSAGE_GET_NUMBER);

    if (searchStudent(*students, number) == -1)
    {
        students->students[students->index].number = number;
        getString(students->students[students->index].name, MAX_NAME_STUDENT, MESSAGE_GET_NAME);
        students->students[students->index].birthDate.day = getInt(MIN_DAY, MAX_DAY, MESSAGE_GET_BIRTH_DAY);
        students->students[students->index].birthDate.month = getInt(MIN_MONTH, MAX_MONTH, MESSAGE_GET_BIRTH_MONTH);
        students->students[students->index].birthDate.year = getInt(MIN_YEAR, MAX_YEAR, MESSAGE_GET_BIRTH_YEAR);

        return students->index++;
    }

    return -1;
}

void updateStudent(Student *student)
{
    getString((*student).name, MAX_NAME_STUDENT, MESSAGE_GET_NAME);
    (*student).birthDate.day = getInt(MIN_DAY, MAX_DAY, MESSAGE_GET_BIRTH_DAY);
    (*student).birthDate.month = getInt(MIN_MONTH, MAX_MONTH, MESSAGE_GET_BIRTH_MONTH);
    (*student).birthDate.year = getInt(MIN_YEAR, MAX_YEAR, MESSAGE_GET_BIRTH_YEAR);
}

void deleteStudent(Student *student)
{
    student->number = 0;
    strcpy(student->name, "");
    student->birthDate.day = 0;
    student->birthDate.month = 0;
    student->birthDate.year = 0;
}

void insertStudents(Students *students)
{
    if (students->index < MAX_STUDENTS)
    {
        if (insertStudent(students) == -1)
        {
            puts(ERROR_STUDENT_REGISTERED);
        }
    }
    else
    {
        puts(ERROR_FULL_LIST);
    }
}

void searchStudents(Students students)
{
    int number = searchStudent(students, getInt(MIN_NUM_STUDENT, MAX_NUM_STUDENT, MESSAGE_GET_NUMBER));

    if (number != -1)
    {
        displayStudent(students.students[number]);
    }
    else
    {
        puts(ERROR_STUDENT_NOT_FOUND);
    }
}

void updateStudents(Students *students)
{
    int number = searchStudent(*students, getInt(MIN_NUM_STUDENT, MAX_NUM_STUDENT, MESSAGE_GET_NUMBER));

    if (number != -1)
    {
        updateStudent(&(*students).students[number]);
    }
    else
    {
        puts(ERROR_STUDENT_NOT_FOUND);
    }
}

void deleteStudents(Students *students)
{
    int i, number = searchStudent(*students, getInt(MIN_NUM_STUDENT, MAX_NUM_STUDENT, MESSAGE_GET_NUMBER));

    if (number != -1)
    {
        for (i = number; i < students->index - 1; i++)
        {
            students->students[i] = students->students[i + 1];
        }

        deleteStudent(&students->students[i]);
        students->index--;
    }
    else
    {
        puts(ERROR_STUDENT_NOT_FOUND);
    }
}

void viewStudents(Students students)
{
    if (students.index > 0)
    {
        for (size_t i = 0; i < students.index; i++)
        {
            displayStudent(students.students[i]);
        }
    }
    else
    {
        puts(ERROR_EMPTY_LIST);
    }
}