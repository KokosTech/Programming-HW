#include <stdio.h>
#include <string.h>

#define MAXLINE 32
#define PEOPLE 20
#define FILE_NAME "file.txt"

typedef struct{
    char name[MAXLINE];
    char last_name[MAXLINE];
} Person;

Person init_person(char[], int);
void print_person(Person);

int main(){

    Person people[PEOPLE];

    for(int i = 0; i < PEOPLE; ++i)
        people[i] = init_person(FILE_NAME, (i+1)*2);

    for(int i = 0; i < PEOPLE; ++i)
        print_person(people[i]);

    return 0;
}

Person init_person(char path[], int smth) {
    FILE *fp;

    fp = fopen(path, "r");

    Person person;
    for(int i = 0; i < smth; i += 2){
        fscanf(fp, "%s", person.name);
        fscanf(fp, "%s", person.last_name);
    }

    fclose(fp);

    return person;
}

void print_person(Person person) {
    printf("Name: %s %s\n", person.name, person.last_name);
}