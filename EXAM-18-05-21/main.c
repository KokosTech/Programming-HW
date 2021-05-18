#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node{
    char str[1024];
    int data;

    int key;

    struct Node *next;
    struct Node *prev;
};

struct Node *head = NULL;
struct Node *two = NULL;
struct Node *last = NULL;

struct Node *third = NULL;
struct Node *third_last = NULL;

struct Node *current = NULL;

bool isEmpty(){
    return head == NULL;
}

int length(){
    int length = 0;
    struct Node *current;

    for (current = head; current != NULL; current = current->next){
        length++;
    }

    return length;
}

void displayForward(struct Node* head){
    struct Node *ptr = head;

    while (ptr != NULL){
        printf("%d: %s | %d\n", ptr->key, ptr->str, ptr->data);
        ptr = ptr->next;
    }
}

void displayBackward(){
    struct Node *ptr = last;

    while (ptr != NULL){
        printf("%d: %s | %d\n", ptr->key, ptr->str, ptr->data);
        ptr = ptr->prev;
    }
}

void pushFront(int key, char str[], int data){
    struct Node *link = (struct Node *)malloc(sizeof(struct Node));
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

void pushBack(int key, char str[], int data){
    struct Node *link = (struct Node *)malloc(sizeof(struct Node));
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

struct Node *popFirst(){
    struct Node *tempLink = head;

    if (head->next == NULL){
        last = NULL;
    } else {
        head->next->prev = NULL;
    }

    head = head->next;
    return tempLink;
}

struct Node *popLast(){
    struct Node *tempLink = last;

    if (head->next == NULL){
        head = NULL;
    } else {
        last->prev->next = NULL;
    }

    last = last->prev;
    return tempLink;
}

struct Node *delete (int key){
    struct Node *current = head;
    struct Node *previous = NULL;

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

bool add(int key, int newKey, char str[], int data){
    struct Node *current = head;

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

    struct Node *newLink = (struct Node *)malloc(sizeof(struct Node));
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

    FILE* fptr;
    struct Node *ptr = head;
    fptr = fopen(fname, "wb");
    while (ptr != NULL){
        // fprintf(fptr, "%d %s %d\n", ptr->key, ptr->str, ptr->data);
        fwrite(&ptr->key, sizeof(ptr->key), 1, fptr);
        fwrite(ptr->str, strlen(ptr->str)+1, 1, fptr);
        fwrite(&ptr->data, sizeof(ptr->data), 1, fptr);
        ptr = ptr->next;
    }

    fclose(fptr);
}

void readFromFile(){
    char fname[128];
    printf("\nREAD YOUR FILES TODAY FOR 100% FREE (LEGIT), ENTER NAME OF THE FILE: ");
        scanf("%s", fname);

    FILE* fptr;
    struct Node *ptr = head;
    fptr = fopen(fname, "rb");
    while (ptr != NULL){
        // fprintf(fptr, "%d %s %d\n", ptr->key, ptr->str, ptr->data);
        fread(&ptr->key, sizeof(ptr->key), 1, fptr);
        fread(ptr->str, strlen(ptr->str)+1, 1, fptr);
        fread(&ptr->data, sizeof(ptr->data), 1, fptr);
        ptr = ptr->next;
    }

    fclose(fptr);
}

struct Node* copyList(struct Node* head){
    struct Node* current = head;    // used to iterate over the original list
    struct Node* newList = NULL;    // head of the new list
    struct Node* tail = NULL;       // point to the last node in a new list
 
    while (current != NULL)
    {
        // special case for the first new node
        if (newList == NULL)
        {
            newList = (struct Node*)malloc(sizeof(struct Node));
            strcpy(newList->str, current->str);
            newList->data = current->data;
            newList->key = current->key;
            newList->next = NULL;
            tail = newList;
        }
        else {
            tail->next = (struct Node*)malloc(sizeof(struct Node));
            tail = tail->next;
            strcpy(tail->str, current->str);
            tail->data = current->data;
            tail->key = current->key;
            tail->next = NULL;
        }
        current = current->next;
    }
 
    return newList;
}

void combine() {
   struct Node *link;
   third = copyList(head);

   link = third;

   while(link->next!= NULL) {
      link = link->next;
   }

   link->next = two;
   two->prev = link;

   // assign link_last to last node of new list

   while(link->next!= NULL) {
      link = link->next;
   }

   third_last = link;  
}

void main(){
    printf("Exam 11-05-21\n\n");

    pushFront(1, "Aleko", 1.1);
    pushFront(2, "Alexandra", 2.2);
    pushFront(3, "Alexander", 3.3);
    pushFront(4, "Boris", 4.4);
    pushFront(5, "Valentin", 5.5);
    pushFront(6, "Vasko", 6.6);

    printf("\nList (First to Last):\n");
    displayForward(head);

    printf("\n");
    printf("\nList (Last to first):\n");
    displayBackward();

    printf("\nList, after deleting first record:\n");
    popFirst();
    displayForward(head);

    printf("\nList, after deleting last record:\n");
    popLast();
    displayForward(head);

    printf("\nList, insert after key(4):\n");
    pushFront(4, "Vhdsfbi", 4.6);
    displayForward(head);

/*     saveToFile();
    readFromFile();
    printf("AFTER READ:\n");
    displayForward(head); */

    printf("Copying LIST1 to LIST2:\n");
    two = copyList(head);
    printf("LIST 2:\n");
    displayForward(two);

    printf("\nList1, after delete key(4):\n");
    delete (4);
    displayForward(head);

    printf("\n\nMERGING LIST1 and LIST2 INTO LIST3:\n");
    combine();
    printf("LIST 3:\n");
    displayForward(third);
}