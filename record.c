#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"
#include "work.h"


char* newChar() // Создание новой строки
{
    char* string;
    if((string = (char*)malloc(sizeof(char)*100)) == NULL)
    {
        printf("Memory allocation error\n");
        free(string);
        return 0;
    }
    string[0] = '\0';
    return string;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void record(head *h, int id) // Ввод нового элемента картотеки
{
    RUS *current = malloc(sizeof(RUS));
    current->name = newChar();
    printf("\nEnter the name of the Russian Federation subject: ");
    scanf("%s", current->name);
    printf("Enter the density of the subject: ");
    scanf("%f", &current->density);
    while (current->density < 0) { // Проверка на ввод
        printf("Input error. Enter the value again: ");
        scanf("%f", &current->density);
    }
    printf("Enter the number of people living in this subject: ");
    scanf("%d", &current->population);
    while (current->population < 0) { // Проверка на ввод
        printf("Input error. Enter the value again: ");
        scanf("%d", &current->population);
    }
    printf("Enter the area of the subject: ");
    scanf("%d", &current->area);
    while (current->area < 0) { // Проверка на ввод
        printf("Input error. Enter the value again: ");
        scanf("%d", &current->area);
    }
    printf("Enter the percentage of the population living in this subject"
           " of the total population of the country: ");
    scanf("%f", &current->percent);
    while (current->percent < 0) { // Проверка на ввод
        printf("Input error. Enter the value again: ");
        scanf("%f", &current->percent);
    }
    printf("Enter the day of the base of the subject: ");
    scanf("%d", &current->date[0]);
    while (current->date[0] < 0|| current->date[0] > 31) { // Проверка на ввод
        printf("Input error. Enter the value again: ");
        scanf("%d", &current->date[0]);
    }
    printf("Enter the month on the basis of the subject: ");
    scanf("%d", &current->date[1]);
    while (current->date[1] < 0|| current->date[1] > 12) { // Проверка на ввод
        printf("Input error. Enter the value again: ");
        scanf("%d", &current->date[1]);
    }
    printf("Enter the year the subject was founded: ");
    scanf("%d", &current->date[2]);
    while (current->date[2] < 0 || current->date[2] > 2019) { // Проверка на ввод
        printf("Input error. Enter the value again: ");
        scanf("%d", &current->date[2]);
    }
    recording(current, h, id); // Добавление нового элеменкта картотеки
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void recording(RUS *SUBJ, head *h, int id) { // Добавление нового элеменкта картотеки
    RUS *current = NULL;
    SUBJ->next = NULL;
    SUBJ->id = 1;
    if (h->first == NULL) {
        h->first = SUBJ;
    } else {
        current = h->first;
        while (current->next != NULL) {
            SUBJ->id++;
            current =  current->next;
        }
        SUBJ->id = id+1;
        current->next =  SUBJ;
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////