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

// Free

void free_names(People* human){
    free(human->name.first);
    free(human->name.mid);
    free(human->name.last);
}

void free_looks(People* human){
    free(human->looks.eye_color);
    free(human->looks.hair_color);
}

void free_address(People* human){
    free(human->address.country);
    free(human->address.country_code);
    free(human->address.city);
    free(human->address.neighbourhood);
    free(human->address.street);
}


void free_human(People* human){
    free_names(human);
    free_looks(human);
    free_address(human);
    free(human);
}

// Sub-Functions

void get_names(People* human){
    printf("Enter: First Name: ");
        human->name.first = get_string();
    printf("Enter: Mid Name: ");
        human->name.mid = get_string();
    printf("Enter: Last Name: ");
        human->name.last = get_string();
}

void print_names(People* human){
    printf("First Name: %s\n", human->name.first);
    printf("Mid Name: %s\n", human->name.mid);
    printf("Last Name: %s\n", human->name.last);
}

// Functions

void get_human(People* human){
    get_names(human);
}

void print_human(People* human){
    printf("Human Specifications:\n\n");
    print_names(human);

}

// Start

void start(){
    People* human = init_human();
    get_human(human);
    print_human(human);
    free_human(human);
}