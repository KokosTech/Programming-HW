#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <string.h>
#include <time.h>

#define Q_NUM 2
#define PEOPLE_NUMBER 20
#define UNDEF_STRING NULL
#define DEFAULT_NAME "Number "

// Structure

typedef struct{
    char* name;
    int points;
    bool qualities[2];
} Guess;

Guess* init(){
    Guess* guesses[PEOPLE_NUMBER];
    for(int i = 0; i < PEOPLE_NUMBER; ++i){
        guesses[i] = (Guess*)malloc(sizeof(Guess));
        guesses[i]->name = DEFAULT_NAME;
    }
    Guess*(*p)[] = &guesses;
    return (*p);
}

Guess* init_gss(){
    Guess** gss = init();

    char buffer[3];
    char *buffer2;
    buffer2 = (char*) malloc(sizeof(DEFAULT_NAME));
    strcpy(buffer2, DEFAULT_NAME);

    for(int i = 0; i < PEOPLE_NUMBER; ++i) {
        sprintf(buffer,"%d", i+1);
        buffer2 = (char*) realloc(buffer2, (sizeof(buffer) + sizeof(buffer2)));
        strcat(buffer2, buffer); 

        // IDK Why this $hit doesn't work, probably something with the pointers, 
        // but it's pain to fix, that's why I'm creating the "STUPID" verison
        
        *gss[i]->name = (char*) realloc((*gss[i]).name, sizeof(buffer2));
        strcpy(*gss[i]->name, buffer2); 

        (*gss)[i].points = 0;

        buffer[0] = "\0";

        strcpy(buffer2, DEFAULT_NAME);
    }

    return (*gss);
}

/* Guess* init_src(){
    Guess** src = init();
    
    

    return src;
}

// Functions

bool is_liar(int index) {
    //check in source of truth
    if (index % 3 == 0) {
        return true;
    }

    return false;
}

bool is_introvert(int index){
    //check in source of truth
    if (index % 7 == 0) {
        return true;
    }

    return false;
}
 */