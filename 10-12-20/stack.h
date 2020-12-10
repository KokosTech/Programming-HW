#include <stdio.h>
#include <stdbool.h>

#define STACK_MAX 9
#define STACK_MIN -1

typedef struct{
    int top;
    int* arr;
}Stack;

Stack* init(){
    Stack* stk = (Stack*)malloc(sizeof(Stack));
    stk->top = STACK_MIN;
    stk->arr = (int*)malloc(STACK_MAX * sizeof(int));
    return stk;
}

_Bool is_empty(Stack* stk){
    if(stk->top == STACK_MIN)
        return true;
    return false;
}

_Bool is_full(Stack* stk){
    if(stk->top == STACK_MAX)
        return true;
    return false;
}

int peek(Stack* stk){
    printf("Top item of arr: %d\n", *(stk->arr + stk->top));
}

void push(Stack* stk, int item){
    if(!is_full(stk))
        *(stk->arr + ++stk->top) = item;
    else
        printf("\nSorry, you can't add more, stack is full!\n");
}

void pop(Stack* stk){
    if(is_empty(stk))
        printf("Sorry, but the stack is empty, there's nothing to print :(");
    else
        stk->top--;
}