#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"
#define MAX 100


head MakeHead()  // Создание головы
{
    head h;
    h.first = NULL;
    h.size = 0;
    return h;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int read(head *h) {    // Считывание
    FILE *f;
    int r=1;
    if ((f = fopen("FILE.csv", "r")) != NULL) {
        fseek(f,0,SEEK_END);
        long pos = ftell(f);
        if(pos>0) // Файл непустой
        {
            rewind(f);
            while (!(feof(f))) {
                h = DLC(h, f);    // Добавление по строке
            }
        }
        if (fclose(f) == EOF) {
            printf("Error closing file\n");
            r=0;
        }
    }
    else {
        printf("Error opening file\n");
        r=0;
    }
    return r+1;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

head *DLC(head *h, FILE *f) {		// Добавление по строке
    RUS *current;
    current = (RUS*)malloc(sizeof(RUS));
    current->name = (char*)malloc(MAX * sizeof(char));
    if (current && current->name) {
        fscanf(f, "%[^;];%f;%d;%d;%f;%d;%d;%d", current->name, &(current->density), &(current->population),
               &(current->area), &(current->percent), &(current->date[0]), &(current->date[1]), &(current->date[2]));
        fgetc(f);
        add(current, h);
    }
    else{
        printf("Memory allocation error\n");
        if (current)
            free(current);
        if (current->name)
            free(current->name);
    }
    return h;
}

void add(RUS *SUBJ, head *h) { // Добавление элемента
    RUS *current = NULL;
    SUBJ->next = NULL;
    SUBJ->id = 1;
    if (h->first == NULL) {
        h->first = SUBJ;
    } else {
        SUBJ->id++;
        (h->size)++;
        current = h->first;
        while (current->next != NULL) {
            SUBJ->id++;
            current =  current->next;
        }
        current->next =  SUBJ;
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void output(head *h) {		// Вывод списка
    RUS *current = h->first;
    puts(" _____________________________________________________________________________________________________");
    puts("| N|            Name subject           | Density | Population|  Area  | Percent(%)|Date of foundation|");
    puts("|//|///////////////////////////////////|/////////|///////////|////////|///////////|//////////////////|");
    for (int i = 0; current != NULL; i++) {
        printf("|%2d|%35s|%9.2f|%11d|%8d|%9.2f  | %6d.%2d.%4d   |\n", current->id, current->name, current->density,
                current->population, current->area, current->percent, current->date[0], current->date[1],
                current->date[2]);
        current = current->next;
    }
    puts("|//|///////////////////////////////////|/////////|///////////|////////|///////////|//////////////////|");
    getchar();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void save_in_file(FILE *file, head *h) { // Сохрание в новый файл
    RUS *current = h->first;
    if (current == NULL)
        return;

    while (current != NULL) {
        fprintf(file, "%s;%.2f;%d;%d;%.2f;%d;%d;%d\n", current->name, current->density, current->population,
                current->area, current->percent, current->date[0], current->date[1],current->date[2]);
        current = current->next;
    }
    fclose(file);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////


