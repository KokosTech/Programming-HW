/* Група 1 - Калкулатор:
- Прочита от файла (group1.txt) стойностите
- Число едно, операция, Число 2
- Запазва прочетените стойности в масив от структури от тип, дефиниран от вас
- Пресмята автоматично, като взима число 1 и число 2 и разпознае една от операциите: PLUS, MINUS, ADD, DIVIDE
- Записва обратно във файла като добавя четвърта стойност накрая - резултата от операцията
- Бонус: Да работи с числа с десетична запетая */


#include <stdio.h>
#include <string.h>

#define FILE_NAME "calc.txt"
#define CALC 10
#define OPER 10

typedef struct {
    int number1;
    char op[OPER];
    int number2;
    int result;
} Calc;

int main(){
    Calc calc[CALC];

    init_calc(calc);
    calculate(calc);
    write_to_file(calc);

    return 0;
}

void init_calc(Calc* calc){
    FILE* fp;
    fp = fopen(FILE_NAME, "r");

    for(int i = 0; i < CALC; ++i) {
        fscanf(fp, "%d %s %d", &calc->number1, calc->op, &calc->number2);
        calc++;
    }

    calc->result = 0;

    fclose(fp);
}

void calculate(Calc* calc){
    for(int i = 0; i < CALC; ++i) {
        if(!strcmp(calc->op, "PLUS"))
            calc->result = calc->number1 + calc->number2;
        else if(!strcmp(calc->op, "MINUS"))
            calc->result = calc->number1 - calc->number2;
        else if(!strcmp(calc->op, "MULTIPLY"))
            calc->result = calc->number1 * calc->number2;
        else if(!strcmp(calc->op, "DIVIDE"))
            calc->result = calc->number1 / calc->number2;
        calc++;
    }
}

void write_to_file(Calc* calc) {
    FILE* fp;
    fp = fopen(FILE_NAME, "w");

    for(int i = 0; i < CALC; ++i) {
        fprintf(fp, "%d %s %d %d\n", calc->number1, calc->op, calc->number2, calc->result);
        calc++;
    }

    fclose(fp);
}

