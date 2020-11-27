#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define UNDEF_INT 0
#define UNDEF_BOOL false
#define UNDEF_STRING NULL

typedef struct People{
    char* id;
    struct names{
        char* first;
        char* mid;
        char* last;
    } name;
    struct looks{
        char* eye_color;
        char* hair_color;
    } looks;
    struct specs{
        float happiness;
        float health;
        float criminal_rate;
    } specs;
    struct education{
        bool elementary;
        bool secondary;
        bool bachelor;
        bool master;
    } edu;
    struct address{
        char* country;
        char* country_code;
        char* city;
        char* neighbourhood;
        char* street;
        int street_number;
    } address;
    
} People;

// General

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

void init_names(People* human){
    human->name.first = UNDEF_STRING;
    human->name.mid = UNDEF_STRING;
    human->name.last = UNDEF_STRING;
}

void init_looks(People* human){
    human->looks.eye_color = UNDEF_STRING;
    human->looks.hair_color = UNDEF_STRING;
}

void init_specs(People* human){
    human->specs.happiness = UNDEF_INT;
    human->specs.health = UNDEF_INT;
    human->specs.criminal_rate = UNDEF_INT;
}

void init_edu(People* human){
    human->edu.elementary = UNDEF_BOOL;
    human->edu.secondary = UNDEF_BOOL;
    human->edu.bachelor = UNDEF_BOOL;
    human->edu.master = UNDEF_BOOL;
}

void init_address(People* human){
    human->address.country = UNDEF_STRING;
    human->address.country_code = UNDEF_STRING;
    human->address.city = UNDEF_STRING;
    human->address.neighbourhood = UNDEF_STRING;
    human->address.street = UNDEF_STRING;
    human->address.street_number = UNDEF_INT;
}

People* init_human(){
    People* human = (People*) malloc (sizeof (People));

    human->id = UNDEF_STRING;

    init_names(human);
    init_looks(human);
    init_specs(human);
    init_edu(human);
    init_address(human);

    return human;
}

void free_human(People* human){

}

// Sub-Functions

void get_names(People* human){
    printf("Enter: First Name: ");
    printf("Enter: Mid Name: ");
    printf("Enter: Last Name: ");
}

// Functions

void get_human(People* human){

}

// Start

void start(){
    People* human = init_human();
}