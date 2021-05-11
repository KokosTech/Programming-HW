#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct node{
    char str[1024];
    float data;

    int key;

    struct node *next;
    struct node *prev;
};

struct node *head = NULL;
struct node *last = NULL;

struct node *current = NULL;

bool isEmpty(){
    return head == NULL;
}

int length(){
    int length = 0;
    struct node *current;

    for (current = head; current != NULL; current = current->next){
        length++;
    }

    return length;
}

void displayForward(){
    struct node *ptr = head;

    while (ptr != NULL){
        printf("%d: %s | %.2f\n", ptr->key, ptr->str, ptr->data);
        ptr = ptr->next;
    }
}

void displayBackward(){
    struct node *ptr = last;

    while (ptr != NULL){
        printf("%d: %s | %.2f\n", ptr->key, ptr->str, ptr->data);
        ptr = ptr->prev;
    }
}

void insertFirst(int key, char str[], float data){
    struct node *link = (struct node *)malloc(sizeof(struct node));
    link->key = key;
    strcpy(link->str, str);
    link->data = data;

    if (isEmpty()){
        last = link;
    }
    else{
        head->prev = link;
    }

    link->next = head;
    head = link;
}

void insertLast(int key, char str[], float data){
    struct node *link = (struct node *)malloc(sizeof(struct node));
    link->key = key;
    strcpy(link->str, str);
    link->data = data;

    if (isEmpty()){
        last = link;
    } else {
        last->next = link;
        link->prev = last;
    }

    last = link;
}

struct node *deleteFirst(){
    struct node *tempLink = head;

    if (head->next == NULL){
        last = NULL;
    } else {
        head->next->prev = NULL;
    }

    head = head->next;
    return tempLink;
}

struct node *deleteLast(){
    struct node *tempLink = last;

    if (head->next == NULL){
        head = NULL;
    } else {
        last->prev->next = NULL;
    }

    last = last->prev;
    return tempLink;
}

struct node *delete (int key){
    struct node *current = head;
    struct node *previous = NULL;

    if (head == NULL){
        return NULL;
    }

    while (current->key != key){
        if (current->next == NULL){
            return NULL;
        } else {
            previous = current;
            current = current->next;
        }
    }

    if (current == head){
        head = head->next;
    } else {
        current->prev->next = current->next;
    }

    if (current == last){
        last = current->prev;
    } else {
        current->next->prev = current->prev;
    }

    return current;
}

bool insertAfter(int key, int newKey, char str[], float data){
    struct node *current = head;

    if (head == NULL){
        return false;
    }
    
    while (current->key != key){
        if (current->next == NULL){
            return false;
        } else {
            current = current->next;
        }
    }

    struct node *newLink = (struct node *)malloc(sizeof(struct node));
    newLink->key = newKey;
    strcpy(newLink->str, str);
    newLink->data = data;

    if (current == last){
        newLink->next = NULL;
        last = newLink;
    } else {
        newLink->next = current->next;
        current->next->prev = newLink;
    }

    newLink->prev = current;
    current->next = newLink;
    return true;
}

void saveToFile(){
    char fname[128];
    printf("\nSAVE YOUR FILES TODAY FOR 100% FREE (LEGIT), ENTER NAME OF THE FILE: ");
        scanf("%s", fname);

    printf("\nSaving to %s file!\n");

    FILE* fp;
    struct node *ptr = head;
    fp = fopen(fname, "w");
    while (ptr != NULL){
        fprintf(fp, "%d %s %.2f\n", ptr->key, ptr->str, ptr->data);
        ptr = ptr->next;
    }

    fclose(fp);
}

void main(){
    printf("Exam 11-05-21\n\n");

    insertFirst(1, "Aleko", 1.1);
    insertFirst(2, "Alexandra", 2.2);
    insertFirst(3, "Alexander", 3.3);
    insertFirst(4, "Boris", 4.4);
    insertFirst(5, "Valentin", 5.5);
    insertFirst(6, "Vasko", 6.6);

    printf("\nList (First to Last):\n");
    displayForward();

    printf("\n");
    printf("\nList (Last to first):\n");
    displayBackward();

    printf("\nList , after deleting first record:\n");
    deleteFirst();
    displayForward();

    printf("\nList , after deleting last record:\n");
    deleteLast();
    displayForward();

    printf("\nList , insert after key(4):\n");
    insertFirst(4, "Vhdsfbi", 4.6);
    displayForward();

    saveToFile();

    printf("\nList  , after delete key(4):\n");
    delete (4);
    displayForward();
}