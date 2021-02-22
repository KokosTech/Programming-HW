#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <string.h>
#include <time.h>

#define Q_NUM 2
#define PEOPLE_NUMBER 20
#define DEFAULT_NAME "Number "

typedef struct{
    char* name;
    int points;
    bool qualities[Q_NUM];
} Guess;

