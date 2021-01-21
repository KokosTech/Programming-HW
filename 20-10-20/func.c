#include <stdio.h>
#include <stdlib.h>

int strl(const char* str){
    int i = 0;

    while(*(str + i) != '\0' || *(str + i) == 32)
        i++;

    return i;
}

void strct(char* dest, const char* src){
    int num = strl(src) + 1;
    int dnum = strl(dest) + 1;
    int sum = num + dnum;

    dest = realloc(dest, sum * sizeof(char));

    for(int i = 0; i < num; ++i){
        *(dest + (dnum + i)) = *(src + i);}
}

void strcp(char* dest, const char* src){
    int num = strl(src) + 1;
    printf("\n%d\n", num);
    dest = realloc(dest, num * sizeof(char));
    for(int i = 0; i < num; ++i)
        *(dest + i) = *(src + i);
}

void strch(const char* str, const char ch){
    int fl[] = {-1, -1};

    for(int i = 0; i < strl(str); ++i)
        if(*(str + i) == ch){
            fl[0] = i;
            break;
        }

    for(int i = strl(str) - 1; i > -1; i--)
        if(*(str + i) == ch){
            fl[1] = i;
            break;
        }

    if (fl[0] == -1 && fl[1] == -1)
            printf("The char '%c' is not found\n", ch);
    else if(fl[0] == fl[1])
        printf("There's only one char '%c' on index: %d\n", ch, fl[0]);
    else
        printf("The first '%c' is on index: %d\nThe last '%c' is on index: %d\n", ch, fl[0], ch, fl[1]);
    
}

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