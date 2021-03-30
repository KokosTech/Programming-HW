#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NAME_LENGTH 50
#define INIT_LENGTH 20
#define STEP 2
#define BUFF_SIZE 9

typedef struct {
    int number;
    char name[NAME_LENGTH];
} Person;

typedef struct {
    Person* people;
    int length;
    int size;
} PeopleArr;

void construct_people(PeopleArr* arr);
void init(PeopleArr* arr, int length);
void print(PeopleArr* arr);
void resize_arr(PeopleArr* arr);
void push(PeopleArr* arr, Person* person);

int main() {

    PeopleArr arr;

    construct_people(&arr);

    print(&arr);

    init(&arr, 30);

/*     for(int i = 0; i < 5; ++i) {
        Person person;
        person.number = 100 + i;

        char name[BUFF_SIZE] = "Person";
        char num[BUFF_SIZE];
        itoa(i, num, 10);
        strcat(name, num);
        strcpy(person.name, name);
        push(&arr, &person);
    } */

    print(&arr);
    pre_get(&arr, arr.size, 5);
    print(&arr);

    return 0;
}

void construct_people(PeopleArr* arr) {
    arr->people = (Person*)calloc(INIT_LENGTH, sizeof(Person));
    arr->length = 0;
    arr->size = INIT_LENGTH;
}

void init(PeopleArr* arr, int length) {
    while(length > arr->size) {
        resize_arr(arr);
    }

    for(int i = 0; i < length; ++i) {
        arr->people[i].number = i;
        char name[BUFF_SIZE] = "Person";
        char num[BUFF_SIZE];
        sprintf(num,"%d",i);
        strcat(name, num);
        strcpy(arr->people[i].name, name);
    }

    arr->length = length;
}

void print(PeopleArr* arr) {
    printf("Array size: %d\n", arr->size);
    printf("Array length: %d\n", arr->length);

    for(int i = 0; i < arr->length; ++i) {
        printf("Person number: %d, Name: %s\n", arr->people[i].number, arr->people[i].name);
    }
}

void resize_arr(PeopleArr* arr) {
    int new_size = arr->size * STEP;
    arr->people = realloc(arr->people, new_size * sizeof(Person));
    arr->size = new_size;
}

void push(PeopleArr* arr, Person* person) {
    if (arr->length == arr->size) {
        resize_arr(arr);
    }

    strcpy(arr->people[arr->length].name, person->name);
    arr->people[arr->length].number = person->number;
    arr->length++;
}

void remove_last(PeopleArr* arr){
    arr->length--;
}

void remove_element(Person** array, int sizeOfArray, int indexToRemove){
    Person* temp = malloc((sizeOfArray - 1) * sizeof(Person)); // allocate an array with a size 1 less than the current one

    memmove(
            temp,
            *array,
            (indexToRemove+1)*sizeof(Person)); // copy everything BEFORE the index

    memmove(
            temp+indexToRemove,
            (*array)+(indexToRemove+1),
            (sizeOfArray - indexToRemove)*sizeof(Person)); // copy everything AFTER the index

    // This may cause a memory leak at some point :)
    // Better than segmentation fault with:
    // free(*array)

    *array = temp;
}

void get(PeopleArr* arr, int index){

}

void pre_get(PeopleArr* array, int sizeOfArray, int indexToRemove){
    if(indexToRemove < 0){
        remove_last(array);
    } else {
        remove_element(&array->people, array->size, indexToRemove);
        remove_last(array);
    }
}
