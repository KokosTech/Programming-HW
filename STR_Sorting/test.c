#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <utf8.h>

#define UTF_BUFFER 40 // Safest - 40, Safe - 20/30, Not Safe - 10

int main(){
/*     clock_t t;
    t = clock();
    printf("Death!!!\n");
    t = clock() - t;
    printf("It took us: %f\n", ((float)t)/CLOCKS_PER_SEC); */

    char *locale;

    locale = setlocale(LC_ALL, "");

    wchar_t* test = L"Hello, World!";

    wprintf(L"%s\n", test);

    return 0;
}