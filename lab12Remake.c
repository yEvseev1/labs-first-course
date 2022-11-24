#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"rus");
    int numb = 0, flag = 0, dg;
    char a;
    printf("Введите число: \n");
    while(a != '\n'){
        a = getchar();
        if ( (a < '0'|| a > '9') && (a < 'A' || a > 'F') && (a != ' ' && a != ',' && a != '\n' && a != '\t') ) flag = 1;
        if(a == ' ' || a == ',' || a == '\n' || a == '\t'){
            if(flag == 1){
                printf("Это не число.\n");
            }
        }
        if(a >= '0' && a <= '9') {
            dg = (int)(a - '0');
            numb = numb * 10 + ((dg % 10) % 2 == 0 ? dg % 10 - 1 : dg % 10);   
        }
    }
    if(flag == 0) printf("Полученное число: %d\n",numb);
}
