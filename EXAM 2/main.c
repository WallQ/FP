#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "classrooms.h"

int loadClassrooms(Classrooms *classrooms, char *fileName) {
    FILE *fp = fopen(fileName, "rb");

    if (fp == NULL) {
        printf("Error opening file %s", fileName);
        return 0;
    }

    fread(&classrooms->counter, sizeof(int), 1, fp);

    if (classrooms->counter > 0) {
        classrooms->size = classrooms->counter;
        classrooms->classrooms = (Classroom *) malloc(classrooms->size * sizeof(Classroom));

        for (int i = 0; i < classrooms->counter; i++) {
            fread(&classrooms->classrooms[i], sizeof(Classroom), 1, fp);
            classrooms->classrooms[i].attendances = (int *) calloc(classrooms->classrooms[i].capacity, sizeof(int));
            fread(classrooms->classrooms[i].attendances, sizeof(int), classrooms->classrooms[i].capacity, fp);
        }
    }

    fclose(fp);

    return 1;
}

int insertClassroom(Classrooms *classrooms, char *name, int capacity) {
    for (int i = 0; i < classrooms->counter; i++) {
        if (strcmp(classrooms->classrooms[i].name, name) == 0) {
            return 0;
        }
    }

    if (classrooms->counter == classrooms->size) {
        int size = classrooms->size == 0 ? CLASSROOMS_INITIAL_SIZE : classrooms->size * 2;
        Classroom *newClassrooms = (Classroom *) realloc(classrooms->classrooms, size * sizeof(Classroom));

        if (newClassrooms == NULL) {
            return 0;
        }

        classrooms->size = size;
        classrooms->classrooms = newClassrooms;
    }

    classrooms->classrooms[classrooms->counter].capacity = capacity;
    classrooms->classrooms[classrooms->counter].occupation = 0;
    strcpy(classrooms->classrooms[classrooms->counter].name, name);
    classrooms->classrooms[classrooms->counter].attendances = (int *) calloc(capacity, sizeof(int));
    classrooms->counter++;

    return 1;
}

Classroom *searchClassroom(Classrooms *classrooms, char *name) {
    for (int i = 0; i < classrooms->counter; i++) {
        if (strcmp(classrooms->classrooms[i].name, name) == 0) {
            return &classrooms->classrooms[i];
        }
    }

    return 0;
}

int removeClassroom(Classrooms *classrooms, char *name) {
    for (int i = 0; i < classrooms->counter; i++) {
        if (strcmp(classrooms->classrooms[i].name, name) == 0) {
            free(classrooms->classrooms[i].attendances);

            for (int j = i; j < classrooms->counter - 1; j++) {
                classrooms->classrooms[j] = classrooms->classrooms[j + 1];
            }

            classrooms->classrooms[i].capacity = 0;
            classrooms->classrooms[i].occupation = 0;
            strcpy(classrooms->classrooms[i].name, "");
            classrooms->classrooms[i].attendances = NULL;

            classrooms->counter--;

            return 1;
        }
    }

    return 0;
}

void listClassrooms(Classrooms classrooms) {
    if (classrooms.counter == 0) {
        printf("No classrooms found");
        return;
    }

    for (int i = 0; i < classrooms.counter; i++) {
        printf("Classroom %s, capacity: %d, occupation: %d\n", classrooms.classrooms[i].name,
               classrooms.classrooms[i].capacity, classrooms.classrooms[i].occupation);
        for (int j = 0; j < classrooms.classrooms[i].capacity; j++) {
            printf("Student %d: %d\n", j + 1, classrooms.classrooms[i].attendances[j]);
        }
    }
}

int freeClassrooms(Classrooms *classrooms) {
    if (classrooms->classrooms) {
        free(classrooms->classrooms);
        classrooms->classrooms = NULL;
    }

    classrooms = NULL;
}

int markAttendances(Classrooms *classrooms, char *name) {
    for (int i = 0; i < classrooms->counter; i++) {
        if (strcmp(classrooms->classrooms[i].name, name) == 0) {
            for (int j = 0; j < classrooms->classrooms[i].capacity; j++) {
                classrooms->classrooms[i].attendances[j] = 1;
            }

            classrooms->classrooms[i].occupation = classrooms->classrooms[i].capacity;

            return 1;
        }
    }
}

void saveClassrooms(Classrooms classrooms, char *fileName) {
    FILE *fp = fopen(fileName, "wb");

    if (fp == NULL) {
        printf("Error opening file %s", fileName);
        return;
    }

    fwrite(&classrooms.counter, sizeof(int), 1, fp);

    for (int i = 0; i < classrooms.counter; i++) {
        fwrite(&classrooms.classrooms[i], sizeof(Classroom), 1, fp);
        fwrite(classrooms.classrooms[i].attendances, sizeof(int), classrooms.classrooms[i].capacity, fp);
    }

    fclose(fp);
}


int main() {
    Classrooms classrooms;
    char fileName[64] = "classrooms.data";

    if (!loadClassrooms(&classrooms, fileName)) {
        classrooms.counter = 0;
        classrooms.size = 0;
        classrooms.classrooms = NULL;
    }

    insertClassroom(&classrooms, "A", 10);

    Classroom *classroom = searchClassroom(&classrooms, "A");

    if (classroom) {
        printf("Classroom %s, capacity: %d, occupation: %d\n", classroom->name, classroom->capacity,
               classroom->occupation);
    }

    markAttendances(&classrooms, "A");

    listClassrooms(classrooms);

    removeClassroom(&classrooms, "A");

    saveClassrooms(classrooms, fileName);

    freeClassrooms(&classrooms);

    return 0;
}
