#include <stdio.h>
#include <stdlib.h>
#include "func.c"

int strl(const char* str); // outputs str length 

void strct(char* dest, const char* src); // connects 2 strings

void strcp(char* dest, const char* src); // copies a string to a string

void strch(const char* str, const char ch); // finds the first and the last charackter

char *get_string();