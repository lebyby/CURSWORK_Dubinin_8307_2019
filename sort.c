#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "list.h"
#include "menu.h"
#include "sort.h"
#include <locale.h>


void work_sort(head *h){ // Выбор столбца для сортировки
    int c = menu_sort();
    if (c == 1){
        sort_id(h);
    } else if (c == 2) {
        sort_name(h);
    } else if (c == 3) {
        sort_density(h);
    } else if (c == 4) {
        sort_pop(h);
    } else if (c == 5) {
        sort_area(h);
    } else if (c == 6) {
        sort_percent(h);
    } else if (c == 7) {
        sort_date(h);
    } else if (c == 8) {
        sort_month(h);
    } else if (c == 9) {
        sort_year(h);
    }
    printf("Sorted by the selected option list:\n");
    output(h);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void swap(RUS * now, RUS *next) { // Замена
    int id =  now->id;
    size_t len = strlen( now->name);
    char *name = (char *)malloc(len * sizeof(char));
    strcpy(name,  now->name);
    float density =  now->density;
    int pop =  now->population;
    int area =  now->area;
    float per =  now->percent;
    int date =  now->date[0];
    int month =  now->date[1];
    int year =  now->date[2];

    now->id = next->id;
    now->name = next->name;
    now->density = next->density;
    now->population = next->population;
    now->area = next->area;
    now->percent = next->percent;
    now->date[0] = next->date[0];
    now->date[1] = next->date[1];
    now->date[2] = next->date[2];

    next->id = id;
    next->name = name;
    next->density = density;
    next->population = pop;
    next->area = area;
    next->percent = per;
    next->date[0] = date;
    next->date[1] = month;
    next->date[2] = year;
}

////////////////////////////////////////Работа с разными типами///////////////////////////////////////////////

void sort_id(head *h) { // Сортировка по порядковому номеру
    int swapped;
    RUS *current;
    RUS *next = NULL;

    if (h->first == NULL)
        return;

    do {
        swapped = 0;
        current = h->first;
        while (current->next != NULL) {
            next = current->next;
            if (current->id > next->id) {
                swap(current, current->next);
                swapped = 1;
            }
            current =  current->next;
        }
        current = next;
    } while (swapped);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void sort_name(head *h) { // Сортировка по имени
    int swapped;
    RUS *current;
    RUS *next = NULL;

    if (h->first == NULL)
        return;

    do {
        swapped = 0;
        current = h->first;

        while (current->next != NULL) {
            next = current->next;
            if (strcmp(current->name, next->name) > 0) {
                swap(current, current->next);
                swapped = 1;
            }
            current = current->next;
        }
        current = next;
    } while (swapped);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void sort_density(head *h) { // Сортировка по плотности
    int swapped;
    RUS *current;
    RUS *next = NULL;

    if (h->first == NULL)
        return;

    do {
        swapped = 0;
        current = h->first;
        while (current->next != NULL) {
            next = current->next;
            if (current->density > next->density) {
                swap(current, current->next);
                swapped = 1;
            }
            current =  current->next;
        }
        current = next;
    } while (swapped);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void sort_pop(head *h) { // Сортировка по населению
    int swapped;
    RUS *current;
    RUS *next = NULL;

    if (h->first == NULL)
        return;

    do {
        swapped = 0;
        current = h->first;
        while (current->next != NULL) {
            next = current->next;
            if (current->population > next->population) {
                swap(current, current->next);
                swapped = 1;
            }
            current =  current->next;
        }
        current = next;
    } while (swapped);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void sort_area(head *h) { // Сортироска по площади
    int swapped;
    RUS *current;
    RUS *next = NULL;

    if (h->first == NULL)
        return;

    do {
        swapped = 0;
        current = h->first;
        while (current->next != NULL) {
            next = current->next;
            if (current->area > next->area) {
                swap(current, current->next);
                swapped = 1;
            }
            current =  current->next;
        }
        current = next;
    } while (swapped);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void sort_percent(head *h) { // Сортировка по процентному соотношению населения этого субъекта от насселения страны
    int swapped;
    RUS *current;
    RUS *next = NULL;

    if (h->first == NULL)
        return;

    do {
        swapped = 0;
        current = h->first;
        while (current->next != NULL) {
            next = current->next;
            if (current->percent > next->percent) {
                swap(current, current->next);
                swapped = 1;
            }
            current =  current->next;
        }
        current = next;
    } while (swapped);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void sort_date(head *h) { // Сортировка по дню основания
    int swapped;
    RUS *current;
    RUS *next = NULL;

    if (h->first == NULL)
        return;

    do {
        swapped = 0;
        current = h->first;
        while (current->next != NULL) {
            next = current->next;
            if (current->date[0] > next->date[0]) {
                swap(current, current->next);
                swapped = 1;
            }
            current =  current->next;
        }
        current = next;
    } while (swapped);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void sort_month(head *h) { // Сортировка по месяцу основания
    int swapped;
    RUS *current;
    RUS *next = NULL;

    if (h->first == NULL)
        return;

    do {
        swapped = 0;
        current = h->first;
        while (current->next != NULL) {
            next = current->next;
            if (current->date[1] > next->date[1]) {
                swap(current, current->next);
                swapped = 1;
            }
            current =  current->next;
        }
        current = next;
    } while (swapped);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void sort_year(head *h) { // Сортировка по году основания
    int swapped;
    RUS *current;
    RUS *next = NULL;

    if (h->first == NULL)
        return;

    do {
        swapped = 0;
        current = h->first;
        while (current->next != NULL) {
            next = current->next;
            if (current->date[2] > next->date[2]) {
                swap(current, current->next);
                swapped = 1;
            }
            current =  current->next;
        }
        current = next;
    } while (swapped);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////