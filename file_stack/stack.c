#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "stack.txt"

typedef struct NNode {
    int data;
    struct NNode* next;
} Node;

void peek(Node* n) {

    printf("Data of top Node is %d\n", n->data);
}

Node* push(Node* n, int new_val) {
//    while (n->next) {
//        n = n->next;
//    }

    Node* new_node = (Node*)calloc(1, sizeof(Node));
    new_node->data = new_val;

    new_node->next = n;
//    n = &new_node;
//    n = new_node;

    return new_node;

//    n->next = new_node;
}

Node* pop(Node* n) {
//    if (n->next) {
//        return;
//    }
//
//    while (n->next->next) {
//        n = n->next;
//    }
//
//    free(n->next->next);
//    n->next = NULL;

    Node* temp_node = (Node*)calloc(1, sizeof(Node));
    temp_node = n;

    n = n->next;

    free(temp_node);

    return n;
}

void print(Node* n) {
    int index = 0;
    while(n->next) {
        printf("Node %d = %d\n", ++index, n->data);
        n = n->next;
    }
    printf("Node %d = %d\n", index, n->data);
}

Node* command_file(Node* head){
    FILE* fp;
    char cmd[1024];
    int data = 0;

    fp = fopen(FILE_NAME, "r");

    while(1) {
        fscanf(fp, "%s", cmd);

        if(!strcmp(cmd, "PUSH")){
            fscanf(fp, "%d", &data);
            head = push(head, data);
        } else if(!strcmp(cmd, "POP")){
            head = pop(head);
        } else if(!strcmp(cmd, "PEEK")){
            peek(head);
        } else if(!strcmp(cmd, "END")){
            break;
        }
    }

    fclose(fp);

    return head;
}

int main() {
    Node* head = (Node*)calloc(1, sizeof(Node));
    head->data = 7;
    
    head = command_file(head);
    print(head);


    return 0;
}