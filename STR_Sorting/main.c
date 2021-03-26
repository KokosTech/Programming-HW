#include "sorting.h"

// To-Do: insertion sort for strings
// To-Do: quicksort
// To-Do: mergesort
// To-Do: 3-way quicksort
// To-Do: LSD string sort
// To-Do: MSD string sort
// To-Do: 3-way string quicksort

#define FILE_NAME "words.txt"

int main(){

    FILE* fp;
    fp = fopen(FILE_NAME, "r");

    char strings[MAX_STRINGS][MAX_STRING_LEN];

    for(int i = 0; i < MAX_STRINGS; ++i) {
        fscanf(fp, "%s", &strings[i]);
    }

    clock_t t;
    t = clock();

    //InsertionSort(strings);
    //quickSortMain(strings, MAX_STRINGS);
    MergeSort(strings, 0, MAX_STRINGS-1);

    t = clock() - t;
    printf("It took us: %f seconds\n", ((float)t)/CLOCKS_PER_SEC);

    for(int i = 0; i < MAX_STRINGS; ++i) {
        printf("%s\n", strings[i]);
    }

    return 0;
}