#ifndef EXAM_2_CLASSROOMS_H
#define EXAM_2_CLASSROOMS_H

#define CLASSROOMS_INITIAL_SIZE 5
#define CLASSROOMS_NAME_MAX 64

typedef struct {
    int capacity;
    int occupation;
    char name[CLASSROOMS_NAME_MAX];
    int *attendances;
} Classroom;

typedef struct {
    int counter;
    int size;
    Classroom *classrooms;
} Classrooms;

int loadClassrooms(Classrooms *classrooms, char *fileName);

int insertClassroom(Classrooms *classrooms, char *name, int capacity);

Classroom *searchClassroom(Classrooms *classrooms, char *name);

int removeClassroom(Classrooms *classrooms, char *name);

void listClassrooms(Classrooms classrooms);

int freeClassrooms(Classrooms *classrooms);

int markAttendances(Classrooms *classrooms, char *name);

void saveClassrooms(Classrooms classrooms, char *fileName);

#endif
