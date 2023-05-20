#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <errno.h>
#include "person.h"

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "rus");
    if (argc < 3)
    {
        printf("Использование: программа входной_файл выходной_файл\n");
        return 1;
    }
    person p;
    char file[100];
    strcpy(file, argv[2]);
    FILE *in = fopen(argv[1], "rt");
    FILE *bin = fopen(argv[2], "wb");
    if (!in)
    {
        perror("Нельзя открыть файл");
        return 2;
    }
    if (!bin)
    {
        perror("Нельзя открыть файл");
        return 2;
    }
    while (fscanf(in, "%[^,],%[^,],%d,%d,%d,%d", p.name, p.gender, &p.ng, &p.linal, &p.matan, &p.VE) == 6)
    {
        fwrite(&p, sizeof(p), 1, bin);
        memset(p.name, '\0', sizeof(p.name));
        memset(p.gender, '\0', sizeof(p.gender));
    }
    fprintf(bin, "\n");
    fclose(bin);
    fclose(in);
    return 0;
}

