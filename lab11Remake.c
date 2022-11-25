#include <stdio.h>
#include <locale.h>

int main(){ 
    setlocale(LC_ALL,"Rus");
    char a = '0';
    int flag = 0;
    int n1 = 0, n0, x, flag1 = 0, flag2 = 1;
    printf("Введите любые числа\n");
    while (a != EOF) {
        a = getchar();
        if ( (a < '0'|| a > '9') && (a < 'A' || a > 'F') && (a != ' ' && a != ',' && a != '\n' && a != '\t' && a != '-') ) flag = 1;
        if (a == '-') flag2 = -1;
        if (a == ' '|| a == ',' || a == '\n' || a == '\t') {
            if (flag == 0) {
                x = n0;
                if (n1 != 0) n0 = n1 * flag2;
                n1 = 0;
                flag1 += 1;
                flag2 = 1;
                //flag2 = 0;
            } else {
                flag = 0;
            }
        }
        if (a == 'A') n1 = n1 * 16 + 10;
        if (a == 'B') n1 = n1 * 16 + 11;
        if (a == 'C') n1 = n1 * 16 + 12;
        if (a == 'D') n1 = n1 * 16 + 13;
        if (a == 'E') n1 = n1 * 16 + 14;
        if (a == 'F') n1 = n1 * 16 + 15;
        if (a <= '9' && a >= '0') n1 = n1 * 16 + (int)(a - '0');
        if (a == EOF && flag1 > 1) {
            if(x >= 0){
                printf("Предпоследнее 16 - ичное число: %x\n",x);
            } else {
                printf("Предпоследнее 16 - ичное число: -%x\n",(0-x));
            }
            }
        if (a == EOF && flag1 < 2) {
        printf("Одно число(Отсутствие чисел).\n");
            } 
    }
}
