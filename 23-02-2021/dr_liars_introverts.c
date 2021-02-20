#include "guess.h"

enum Behaviour {Liar = 2, Introvert = 4, Extrovert = 4, Sincere = 2};

// Redefine structure or enum to be able to have source of truth

int main (){
    
    // Define source of truth (zapulnete masiva)

    // Init Guesses
 
/*     char buffer[3];
    char buffer2[25] = "Number ";

    for(int i = 0; i < PEOPLE_NUMBER; ++i) {
        sprintf(buffer,"%d", i+1);
        strcat(buffer2, buffer);

        strcpy(guesses[i].name, buffer2);
        guesses[i].points = 0;

        printf("%s\n", guesses[i].name);

        if (is_liar(i)) {
            guesses[i].points += Liar;
        }

        if (is_introvert(i)) {
            guesses[i].points += Introvert;
        }
        buffer[0] = "\0";
        strcpy(buffer2, "Number ");
    } */

    Guess** guesses = init_gss();
    for(int i = 0; i < PEOPLE_NUMBER; ++i)
        printf("Name: %s\n", (*guesses)[i].name);
    // Print for each person how many points
    // what was guessed

    return 0;
}