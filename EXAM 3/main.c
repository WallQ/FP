#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STR 124
#define MAX_SPEAKERS 3

typedef struct {
    unsigned int id;
    char name[MAX_STR + 1];
    char city[MAX_STR + 1];
} Member;

typedef struct {
    char name[MAX_STR + 1];
    char title[MAX_STR + 1];
    char abstract[MAX_STR + 1];
    unsigned short duration_min;
} Speaker;

typedef struct {
    unsigned short number;
    unsigned short year;
    char title[MAX_STR + 1];
    char city[MAX_STR + 1];
    Speaker speakers[MAX_SPEAKERS];
    unsigned int *participant_ids;
    unsigned short n_speakers;
    unsigned short n_participants;
    unsigned short n_beers;
} Meetup;

void free_n_meetups(Meetup **meetups, unsigned int *n_meetups, unsigned int *max_meetups, unsigned int n) {
    unsigned int i;

    for (i = 0; i < n; i++) {
        free(meetups[i]);
    }

    meetups = NULL;
    *n_meetups = 0;
    *max_meetups = 0;
}

int initialize_meetup_list(Meetup **meetups, unsigned int *n_meetups, unsigned int *max_meetups, unsigned int n) {
    int valor = 1;

    if (n > max_meetups) return 0;

    for (int i = 0; i < max_meetups; i++) {
        Meetup *newMeetup = (Meetup *) calloc(1, sizeof(Meetup));

        if (!newMeetup) {
            free_n_meetups(&meetups, &n_meetups, &max_meetups, i);
            valor = 0;
            break;
        }

        meetups[i] = newMeetup;
        strcpy(meetups[i]->city, "");
        strcpy(meetups[i]->title, "");
        meetups[i]->year = 2022;
        meetups[i]->number = i + 1;
        meetups[i]->n_participants = 10;
        meetups[i]->n_beers = 0;

        n_meetups++;
    }

    return valor;
}

double beers_year(Meetup **meetups, unsigned int *n_meetups, unsigned int year) {

}

int containsWord(char string[MAX_STR + 1], char word[MAX_STR + 1]) {
    int stringLength = strlen(string);
    int wordLength = strlen(word);
    int count = 0;

    for (int i = 0; i <= stringLength - wordLength; ++i) {
        int j;
        for (j = 0; j < wordLength; ++j) {
            if (string[i + j] != word[j]) {
                break;
            }
        }

        if (j == wordLength) {
            count++;
        }
    }

    return count;
}

bool isPalindrome(int number, int n_digits) {
    int reverse_num = 0;
    int original_num = number;
    for (int i = 0; i < n_digits; i++) {
        int digit = number % 10;
        reverse_num = reverse_num * 10 + digit;
        number /= 10;
    }
    return reverse_num == original_num;
}

int main() {
    return 0;
}
