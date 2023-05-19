#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <errno.h>
#include "person.h"
int main(int argc, char *argv[]) {
    setlocale(LC_ALL, "rus");
    if (argc < 2) {
        printf("Использование: программа входной_файл ключи\n");
        return 1;
    }
    person p;
    char file[100];
    strcpy(file, argv[1]);
    FILE *bin = fopen(argv[1], "r");
    if (!bin) {
        perror("Нельзя открыть файл");
        return 2;
    }
    int AllSum = 0;
    double avgsum = 0;
    int answer = 0;
    int n = 0;
    while (fread(&p,sizeof(p),1,bin) == 1) {
        AllSum += p.linal + p.matan + p.VE;
        n++;
    }
    avgsum = (double)AllSum / n;
    int sum = 0;
    fseek(bin, 0, SEEK_SET);
    while(fread(&p,sizeof(p),1,bin) == 1){
        sum += p.linal + p.matan + p.VE;
        if(p.linal > 3 && p.matan > 3 && p.VE > 3 && sum > avgsum && !strcmp(p.gender ,"ж")){
            answer++;
        }
        sum = 0;
    }
    printf("Answer - %d",answer);
    fclose(bin);
    return 0;
}