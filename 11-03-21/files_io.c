#include <stdio.h>
#include <string.h>

#define FILE_NAME "test.txt"
#define MAX_LINE 30
#define PEOPLE_COUNT 5

typedef struct {
    char first_name[MAX_LINE];
    char last_name[MAX_LINE];
    int age;
} Person;

void init_people(Person* people);
void print_people(Person* people);
void to_file(Person* people);
// Write definition of this function
// Make the user to enter the new names and age

void edit_person(Person*, int);

int main() {

    Person people[PEOPLE_COUNT];

    init_people(people);
    print_people(people);

    edit_person(people, 4);

    to_file(people);

    init_people(people);
    printf("\nAfter edit:\n");
    print_people(people);

    return 0;
}

void init_people(Person* people) {
    FILE* fp;
    fp = fopen(FILE_NAME, "r");

    for(int i = 0; i < PEOPLE_COUNT; ++i) {
        fscanf(fp, "%s %s %d", people->first_name, people->last_name, &people->age);
        people++;
    }

    fclose(fp);
}

void edit_person(Person* people, int index){
    char temp[MAX_LINE];
    people += index - 1;

    printf("Edit the first name: ");
        scanf("%s", people->first_name);
    printf("Edit the last name: ");
        scanf("%s", people->last_name);
    printf("Edit the age: ");
        scanf("%d", &people->age);

}

void print_people(Person* people) {
    for(int i = 0; i < PEOPLE_COUNT; ++i) {
        printf("First name: %s, Last name: %s, Age: %d\n",
               people->first_name, people->last_name, people->age);
        people++;
    }
}

void to_file(Person* people) {
    FILE* fp;
    fp = fopen(FILE_NAME, "w");

    for(int i = 0; i < PEOPLE_COUNT; ++i) {
        fprintf(fp, "%s %s %d\n", people->first_name, people->last_name, people->age);
        people++;
    }

    fclose(fp);
}


