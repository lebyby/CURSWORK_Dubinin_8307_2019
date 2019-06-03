#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "work.h"
#include "menu.h"
#include "list.h"
#include "search.h"
#include "sort.h"


int work_menu(head *h) // Меню для запуска действий
{
    int d=2;
    int c = menu();
    int k = read(h), size = h->size+1, maxsize = size;
    if (size > 0) {
        while (c != 8) {
            d = 0;
            if (c == 0) {
                printf("This card file contains basic information about the subjects of the Russian Federation "
                       "(data collected for 2017):\n\nthe name of the subject, "
                       "population density (people per square meter), population, area (square km), "
                       "the percentage of the population of the subject of the total population of the country,"
                       " the date of Foundation of the subject.");
            } else if (c == 1) {
                record(h, size);
                size++;
                maxsize++;
                output(h);
            } else if (c == 2) {
                work_editing(size, h);
                output(h);
            } else if (c == 3) {
                size = menu_delete(k, h, maxsize);
            } else if (c == 4) {
                output(h);
            } else if (c == 5) {
                work_search(h);
            } else if (c == 6) {
                work_sort(h);
            } else if (c == 7) {
                system("cls");
            }
            c = menu();
        }
    } else printf("Error. List is empty\n");
    return d;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int menu() { // Меню для выбора действия
    char c[10];
    int i = 0, j = 0;
    printf("Select action:\n0 - Card file information\n1 - Add to list\n2 - Editing cards"
           "\n3 - Delete cards\n4 - Card file Output\n5 - Search cards by parameter"
           "\n6 - Sorting filing for the parameter\n7 - Clear console\n8 - Exit\nEnter a parameter: ");
    scanf("%s", c);
    while (j != 1) {
        j = 0;
        if (strlen(c) > 1) {
            printf("Incorrect input! Try again: ");
            scanf("%s", c);
        } else if ((c[i] < '0') || (c[i] > '8')) {
            printf("Incorrect input! Try again: ");
            scanf("%s", c);
            i++;
        } else { j = 1; }
    }
    i = atoi(c);
    return i;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int menu_search(){ // Меню для поиска
    char c[10];
    int i = 0, j = 0;
    printf("Select action:\n1 - Search by id\n2 - Search by name"
           "\n3 - Search by density\n4 - Search by population\n5 - Search by area"
           "\n6 - Search by percent\n7 - Search by date\n8 - Search by month\n9 - Search by year\nEnter a parameter: ");
    scanf("%s", c);
    while (j != 1) {
        j = 0;
        if (strlen(c) > 1) {
            printf("Incorrect input! Try again: ");
            scanf("%s", c);
        } else if ((c[i] < '1') || (c[i] > '9')) {
            printf("Incorrect input! Try again: ");
            scanf("%s", c);
            i++;
        } else { j = 1; }
    }
    i = atoi(c);
    return i;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int menu_sort(){ // Меню сортировки
    char c[10];
    int i = 0, j = 0;
    printf("Select action:\n1 - Sort by id\n2 - Sort by name"
           "\n3 - Sort by density\n4 - Sort by population\n5 - Sort by area"
           "\n6 - Sort by percent\n7 - Sort by date\n8 - Sort by month\n9 - Sort by year\nEnter a parameter: ");
    scanf("%s", c);
    while (j != 1) {
        j = 0;
        if (strlen(c) > 1) {
            printf("Incorrect input! Try again: ");
            scanf("%s", c);
        } else if ((c[i] < '1') || (c[i] > '9')) {
            printf("Incorrect input! Try again: ");
            scanf("%s", c);
            i++;
        } else { j = 1; }
    }
    i = atoi(c);
    return i;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int menu_edit(){ // Меню для корректировки
    char c[10];
    int i = 0, j = 0;
    printf("Select action:\n1 - Edit by name"
           "\n2 - Edit by density\n3 - Edit by population\n4 - Edit by area"
           "\n5 - Edit by percent\n6 - Edit by date\n7 - Edit by month\n8 - Edit by year\nEnter a parameter: ");
    scanf("%s", c);
    while (j != 1) {
        j = 0;
        if (strlen(c) > 1) {
            printf("Incorrect input! Try again: ");
            scanf("%s", c);
        } else if ((c[i] < '1') || (c[i] > '8')) {
            printf("Incorrect input! Try again: ");
            scanf("%s", c);
            i++;
        } else { j = 1; }
    }
    i = atoi(c);
    return i;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void menu_saving(head *h) { // Меню для сохранения в новый файл
    FILE *f;
    f = fopen("newFILE.csv", "a");
    char r[10];
    int j=0;
    printf("Do you want to save the changes to a new file?\n1 - Yes\n2 - No\nEnter parameter: ");
    scanf("%s", r);
    while (j != 1) {
        j = 0;
        if (strlen(r) > 1) {
            printf("Incorrect input! Try again: ");
            scanf("%s", r);
        } else if ((r[0] < '1') || (r[0] > '2')) {
            printf("Incorrect input! Try again: ");
            scanf("%s", r);
        } else { j = 1; }
    }
    j = atoi(r);
    if (j == 1) {
        save_in_file(f, h);
        printf("The changes are saved to a new file");
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////