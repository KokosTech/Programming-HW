#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PEOPLE 2

typedef struct{
    char* f_name;
    char* l_name;

} People;

People*** init_people(){
    People **peep = (People**) malloc(PEOPLE * sizeof(People*));

    // allocate 100 structs and have the array point to them
    for (int i = 0; i < PEOPLE; i++) {
        peep[i] = (People*) malloc(sizeof(People));
    }

    return &peep;
}

char *get_string(){    
    int logSize = 0, phySize = 1;  
    char *res, c;

    res = (char *)malloc(sizeof(char));
    c = getchar();

    while(c != '\n'){
        if(logSize == phySize){
            phySize *= 2;
            res = (char *)realloc(res, sizeof(char) * phySize);
        }
        res[logSize++] = c;
        c = getchar();
    }

    res = (char *)realloc(res, sizeof(char *) * (logSize + 1));
    res[logSize] = '\0';
    return res;
}

void init_names(People* person, char f_name[], char l_name[]){
    person->f_name = (char*) malloc(sizeof(f_name));
    person->l_name = (char*) malloc(sizeof(l_name));
}

void get_names(People*** people){
    char f_name[50], l_name[50];
    for(int i = 0; i < PEOPLE; ++i){
        printf("Enter first name: ");
            scanf("%s", &f_name);
        printf("Enter last name: ");
            scanf("%s", &l_name);
        
        init_names((*people)[i], f_name, l_name);
    }

    free(f_name);
    free(l_name);
}

void print_names(People*** people){
    for(int i = 0; i < PEOPLE; ++i)
        printf("Names: %s %s\n\n", (*people)[i]->f_name, (*people)[i]->l_name);
}