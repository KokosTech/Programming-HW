#include "func.h"

int main(){
    char* str[2];
    char c;

    printf("Please enter the first string: ");
        str[0] = get_string();
    printf("Please enter the second string: ");
        str[1] = get_string();
    printf("\n-----------------------------------\n\n");
   
printf("\nPre: %s, %s\n", str[0], str[1]);
    for(int i = 0; i < 2; ++i)
        printf("The lenght of string %d is: %d\n", i + 1, strl(str[i]));
    
    char* cpy = (char *) malloc(1);
    strcp(cpy, str[0]);
    printf("String one copied to a new string called 'cpy': %s\n", cpy);

    strcat(cpy, str[1]);
    printf("String 'cpy' extended with string two: %s\n", cpy);

    printf("Search a char in 'cpy': ");
        scanf(" %c", &c);
    strch(cpy, c);

    return 0;
}