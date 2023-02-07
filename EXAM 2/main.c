#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "classrooms.h"

int loadClassrooms(Classrooms *classrooms, char *fileName) {
    FILE *fp = fopen(fileName, "rb");

    if (fp != NULL) {
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

    fp = fopen(fileName, "wb");
    if (fp != NULL) {
        classrooms->counter = 0;
        classrooms->size = CLASSROOMS_INITIAL_SIZE;
        classrooms->classrooms = (Classroom *) malloc(CLASSROOMS_INITIAL_SIZE * sizeof(Classroom));
        fclose(fp);
    }

    return 0;
}

void saveClassrooms(Classrooms *classrooms, char *fileName) {
    FILE *fp = fopen(fileName, "wb");

    if (fp != NULL) {
        fwrite(&classrooms->counter, sizeof(int), 1, fp);

        for (int i = 0; i < classrooms->counter; i++) {
            fwrite(&classrooms->classrooms[i], sizeof(Classroom), 1, fp);
            fwrite(classrooms->classrooms[i].attendances, sizeof(int), classrooms->classrooms[i].capacity, fp);
        }

        fclose(fp);
    }
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
    classrooms->classrooms[classrooms->counter].attendances = (int *) calloc(
            classrooms->classrooms[classrooms->counter].capacity, sizeof(int));

    classrooms->counter++;

    return 1;
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

Classroom *searchClassroom(Classrooms *classrooms, char *name) {
    for (int i = 0; i < classrooms->counter; ++i) {
        if (strcmp(classrooms->classrooms[i].name, name) == 0) {
            return &classrooms->classrooms[i];
        }
    }
}

void listClassrooms(Classrooms classrooms) {
    for (int i = 0; i < classrooms.counter; ++i) {
        printf("Capacity %d", classrooms.classrooms[i].capacity);
        printf("Occupation %d", classrooms.classrooms[i].occupation);
        printf("Occupation %s", classrooms.classrooms[i].name);
        for (int j = 0; j < classrooms.classrooms[i].capacity; ++j) {
            printf("Attendance %d: %d\n", j + 1, classrooms.classrooms[i].attendances[j]);
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

int main() {
    int option;
    Classrooms classrooms;

    loadClassrooms(&classrooms, "classrooms.bin");

    do {
        printf("1 - Insert\n");
        printf("2 - Search\n");
        printf("3 - Remove\n");
        printf("4 - List\n");
        printf("5 - Mark Attendance\n");
        printf("6 - Save\n");
        printf("0 - Exit\n");
        printf("Salas: %d/%d\n", classrooms.counter, classrooms.size);

        option = scanf("%d", option);

        switch (option) {
            case 0:
                break;
            case 1:
                insertClassroom(&classrooms, "Classroom 1", 1);
                break;
            case 2:
                searchClassroom(&classrooms, "Classroom 1");
                break;
            case 3:
                removeClassroom(&classrooms, "Classroom 1");
                break;
            case 4:
                listClassrooms(classrooms);
                break;
            case 5:
                markAttendances(&classrooms, "Classroom 1");
                break;
            case 6:
                saveClassrooms(&classrooms, "classrooms.bin");
                break;
            default:
                printf("Invalid Option!\n");
        }

    } while (option != 0);

    freeClassrooms(&classrooms);

    return 0;
}
