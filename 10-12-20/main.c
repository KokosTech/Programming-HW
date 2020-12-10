#include "stack.h"

int main(){
    int input;
    Stack* stk = init();

    for(int i = 0; i < 10; ++i){
        printf("Please enter an input number: ");
            scanf("%d", &input);
        push(stk, input);
    }
    for(int i = 0; i < 10; ++i){
        pop(stk);
        peek(stk);
    }
}