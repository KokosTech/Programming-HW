#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <string.h>
#include <time.h>

#define Q_NUM 2
#define PEOPLE_NUMBER 20
#define DEFAULT_NAME "Number "
#define MAXLINE 40
#define PEOPLE_NUMBER 20

enum Behaviour {Liar_or_Sincere = 2, Introvert_or_Extrovert = 4};

typedef struct{
    char name[MAXLINE];
    int points;
    bool qualities[Q_NUM];
} Guess;

bool is_liar_or_sincere(int);
bool is_introvert_or_extrovert(int);


Guess guesses[PEOPLE_NUMBER];

Guess src_truth[PEOPLE_NUMBER];

int main (int argc, char **argv){

    srand (time(NULL));

    char buffer[3];

    // INIT 

    for(int i = 0; i < PEOPLE_NUMBER; ++i) {
        strcpy(guesses[i].name, DEFAULT_NAME);
        strcpy(src_truth[i].name, DEFAULT_NAME);
        sprintf(buffer,"%d", i+1);
        strcat(guesses[i].name, buffer);
        strcat(src_truth[i].name, buffer);

        guesses[i].points = 0;
        for(int j = 0; j < Q_NUM; ++j)
            src_truth[i].qualities[j] = rand() % Q_NUM;
        
    }

    for(int i = 0; i < PEOPLE_NUMBER; ++i) {
        printf("Person: %s:\n", src_truth[i].name);
        printf("Liar(0) or Sincere(1): ");
            scanf("%d", &guesses[i].qualities[0]);
        printf("Introvert(0) or Extrovert(1): ");
            scanf("%d", &guesses[i].qualities[0]);

        putchar('\n');

        if(is_liar_or_sincere(i)) guesses[i].points += Liar_or_Sincere;
        if(is_introvert_or_extrovert(i)) guesses[i].points += Introvert_or_Extrovert;
    }

    for(int i = 0; i < PEOPLE_NUMBER; ++i){
        printf("\nName: %s\n", src_truth[i].name);
        printf("[SRC] Sincere vs Liar: %d\n", src_truth[i].qualities[0]);
        printf("[GUESS] Sincere vs Liar: %d\n", guesses[i].qualities[0]);
        printf("[SRC] Introver vs Extrovert: %d\n", src_truth[i].qualities[1]);
        printf("[GUESS] Introver vs Extrovert: %d\n", guesses[i].qualities[1]);
        printf("Points: %d\n", guesses[i].points);
    }

    return 0;
}

bool is_liar_or_sincere(int index) {
    //check in source of truth
    if (src_truth[index].qualities[0] == guesses[index].qualities[0]) {
        return true;
    }

    return false;
}

bool is_introvert_or_extrovert(int index){
    //check in source of truth
    if (src_truth[index].qualities[1] == guesses[index].qualities[1]) {
        return true;
    }

    return false;
}