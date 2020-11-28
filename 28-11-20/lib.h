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
    printf("Enter First Name: ");
        human->name.first = get_string();
    printf("Enter Mid Name: ");
        human->name.mid = get_string();
    printf("Enter Last Name: ");
        human->name.last = get_string();
}
void print_names(People* human){
    printf("\nNames:\n\n");
    printf("First Name: %s\n", human->name.first);
    printf("Mid Name: %s\n", human->name.mid);
    printf("Last Name: %s\n", human->name.last);
}

void get_looks(People* human){
    printf("Enter eye color: ");
        human->looks.eye_color = get_string();
    printf("Enter hair color: ");
        human->looks.hair_color = get_string();
}
void print_looks(People* human){
    printf("\nLooks:\n\n");
    printf("Eye color: %s\n", human->looks.eye_color);
    printf("Hair color: %s\n", human->looks.hair_color);
}

void get_specs(People* human){
    printf("Enter happiness: ");
        scanf("%f", &(human->specs.happiness));
    printf("Enter health: ");
        scanf("%f", &(human->specs.health));
    printf("Enter criminal rate: ");
        scanf("%f", &(human->specs.criminal_rate));
    fflush(stdin);
}
void print_specs(People* human){
    printf("\nSpecs:\n\n");
    printf("Happiness: %.2f\n", human->specs.happiness);
    printf("Health: %.2f\n", human->specs.health);
    printf("Criminal rate: %.2f\n", human->specs.criminal_rate);
}

void get_edu(People* human){
    char el, se, ba, ma;

    printf("Do you have elementary education (y/N): ");
        scanf(" %c", &el);
    if(el == 'y' || el == 'Y')
        human->edu.elementary = true;
    else{
        fflush(stdin);
        return;
    }
    printf("Do you have secondary education (y/N): ");
        scanf(" %c", &se);
    if(se == 'y' || se == 'Y')
        human->edu.secondary = true;
    else{
        fflush(stdin);
        return;
    }
    printf("Do you have a bachelor degree (y/N): ");
        scanf(" %c", &ba);
    if(ba == 'y' || ba == 'Y')
        human->edu.bachelor = true;
    else{
        fflush(stdin);
        return;
    }
    printf("Do you have a master degree (y/N): ");
        scanf(" %c", &ma);
    if(ma == 'y' || ma == 'Y')
        human->edu.master = true;
    fflush(stdin);
}
void print_edu(People* human){
    printf("\nEducation:\n\n");
    printf("Elementary: %s\n", human->edu.elementary ? "Yes" : "No");
    printf("Secondary: %s\n", human->edu.secondary ? "Yes" : "No");
    printf("Bachelor: %s\n", human->edu.bachelor ? "Yes" : "No");
    printf("Master: %s\n", human->edu.master ? "Yes" : "No");
}

void get_address(People* human){
    fflush(stdin);
    getchar();
    printf("Enter a country: ");
        human->address.country = get_string();
    printf("Enter %s's country code: ", human->address.country);
        human->address.country_code = get_string();
    printf("Enter a city: ");
        human->address.city = get_string();
    printf("Enter a neighbourhood: ");
        human->address.neighbourhood = get_string();
    printf("Enter a street: ");
        human->address.street = get_string();
    printf("Enter a street number: ");
        scanf("%d", &human->address.street_number);
    fflush(stdin);
}
void print_address(People* human){
    printf("\nAddress:\n\n");
    printf("Country: %s\n", human->address.country);
    printf("Country Code: %s\n", human->address.country_code);
    printf("City: %s\n", human->address.city);
    printf("Neighbourhood: %s\n", human->address.neighbourhood);
    printf("Street: %s\n", human->address.street);
    printf("Street Number: %d\n", human->address.street_number);

}
// Functions

void get_human(People* human){
    get_names(human);
    get_looks(human);
    get_specs(human);
    get_edu(human);
    get_address(human);
}

void print_human(People* human){
    printf("\nHuman Specifications:\n");
    print_names(human);
    print_looks(human);
    print_specs(human);
    print_edu(human);
    print_address(human);

}

// Start

void start(){
    People* human = init_human();
    get_human(human);
    print_human(human);
    free_human(human);
}