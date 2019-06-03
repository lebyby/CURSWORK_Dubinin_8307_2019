#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include "list.h"
#include "menu.h"
#include "search.h"

#define MAX 100
#define eps 0.00001

void work_search(head *h) { // Ввод элемента для поиска совпадений в картотеке
    int c = menu_search(); // Выбор типа элемента
    int int_;
    char n[MAX];
    float flot;
    if (c == 1){
        printf("Enter the id: ");
        scanf("%d", &int_);
        search_id(h, int_);
    } else if (c == 2) {
        printf("Enter the sudject's name: ");
        scanf("%s", n);
        search_name(h, n);
    } else if (c == 3) {
        printf("Enter the density (point input): ");
        scanf("%f", &flot);
        search_density(h, flot);
    } else if (c == 4) {
        printf("Enter the population: ");
        scanf("%d", &int_);
        search_pop(h, int_);
    } else if (c == 5) {
        printf("Enter the area: ");
        scanf("%d", &int_);
        search_area(h, int_);
    } else if (c == 6) {
        printf("Enter the percent (point input): ");
        scanf("%f", &flot);
        search_percent(h, flot);
    } else if (c == 7) {
        printf("Enter the date: ");
        scanf("%d", &int_);
        search_date(h, int_);
    } else if (c == 8) {
        printf("Enter the month: ");
        scanf("%d", &int_);
        search_month(h, int_);
    } else if (c == 9) {
        printf("Enter the year: ");
        scanf("%d", &int_);
        search_year(h, int_);
    }
}

//////////////////////////////////////Работа с разными типами//////////////////////////////////////////////////////

void search_id(head *h, int int_) { // Поиск порядкового номера
    RUS *current = h->first;
    int c = 0;
    while (current != NULL) {
        if(current->id == int_) {
            printf("%d. Subject: %s\n   Density: %.2f\n   Population: %d\n   Area: %d\n "
                   "  Percent: %.2f\n   Date of foundation: %d.%d.%d\n\n",
                   current->id, current->name, current->density, current->population, current->area,
                   current->percent, current->date[0], current->date[1],current->date[2]);
            c++;
        }
        current = current->next;
    }
    if(c == 0) {
        printf("List is empty\n");
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void search_name(head *h, char *name) { // Поиск имени субъекта
    RUS *current = h->first;
    int c = 0;
    while (current != NULL) {
        if(strcmp(current->name, name) == 0) {
            printf("%d. Subject: %s\n   Density: %.2f\n   Population: %d\n   Area: %d\n "
                   "  Percent: %.2f\n   Date of foundation: %d.%d.%d\n\n",
                   current->id, current->name, current->density, current->population, current->area,
                   current->percent, current->date[0], current->date[1],current->date[2]);
            c++;
        }
        current = current->next;
    }
    if(c == 0) {
        printf("List is empty\n");
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void search_density(head *h, float fl) { // Поиск по плотности субъекта
    RUS *current = h->first;
    int c = 0;
    while (current != NULL) {
        if(fabs(current->density - fl) < eps) {
            printf("%d. Subject: %s\n   Density: %.2f\n   Population: %d\n   Area: %d\n "
                   "  Percent: %.2f\n   Date of foundation: %d.%d.%d\n\n",
                   current->id, current->name, current->density, current->population, current->area,
                   current->percent, current->date[0], current->date[1],current->date[2]);
            c++;
        }
        current = current->next;
    }
    if(c == 0) {
        printf("List is empty\n");
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void search_pop(head *h, int int_) { // Поиск по кол-ву населения
    RUS *current = h->first;
    int c = 0;
    while (current != NULL) {
        if(current->population == int_) {
            printf("%d. Subject: %s\n   Density: %.2f\n   Population: %d\n   Area: %d\n "
                   "  Percent: %.2f\n   Date of foundation: %d.%d.%d\n\n",
                   current->id, current->name, current->density, current->population, current->area,
                   current->percent, current->date[0], current->date[1],current->date[2]);
            c++;
        }
        current = current->next;
    }
    if(c == 0) {
        printf("List is empty\n");
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void search_area(head *h, int int_) { // Поиск по площади
    RUS *current = h->first;
    int c = 0;
    while (current != NULL) {
        if(current->area == int_) {
            printf("%d. Subject: %s\n   Density: %.2f\n   Population: %d\n   Area: %d\n "
                   "  Percent: %.2f\n   Date of foundation: %d.%d.%d\n\n",
                   current->id, current->name, current->density, current->population, current->area,
                   current->percent, current->date[0], current->date[1],current->date[2]);
            c++;
        }
        current = current->next;
    }
    if(c == 0) {
        printf("List is empty\n");
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void search_percent(head *h, float fl) { // Поиск по процентному соотношению
    // населения этого субъекта от насселения страны
    RUS *current = h->first;
    int c = 0;
    while (current != NULL) {
        if(fabs(current->percent - fl) < eps) {
            printf("%d. Subject: %s\n   Density: %.2f\n   Population: %d\n   Area: %d\n "
                   "  Percent: %.2f\n   Date of foundation: %d.%d.%d\n\n",
                   current->id, current->name, current->density, current->population, current->area,
                   current->percent, current->date[0], current->date[1],current->date[2]);
            c++;
        }
        current = current->next;
    }
    if(c == 0) {
        printf("List is empty\n");
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void search_date(head *h, int int_) { // Поиск по дню основания
    RUS *current = h->first;
    int c = 0;
    while (current != NULL) {
        if(current->date[0] == int_) {
            printf("%d. Subject: %s\n   Density: %.2f\n   Population: %d\n   Area: %d\n "
                   "  Percent: %.2f\n   Date of foundation: %d.%d.%d\n\n",
                   current->id, current->name, current->density, current->population, current->area,
                   current->percent, current->date[0], current->date[1],current->date[2]);
            c++;
        }
        current = current->next;
    }
    if(c == 0) {
        printf("List is empty\n");
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void search_month(head *h, int int_) { // Поиск по месяцу основания
    RUS *current = h->first;
    int c = 0;
    while (current != NULL) {
        if(current->date[1] == int_) {
            printf("%d. Subject: %s\n   Density: %.2f\n   Population: %d\n   Area: %d\n "
                   "  Percent: %.2f\n   Date of foundation: %d.%d.%d\n\n",
                   current->id, current->name, current->density, current->population, current->area,
                   current->percent, current->date[0], current->date[1],current->date[2]);
            c++;
        }
        current = current->next;
    }
    if(c == 0) {
        printf("List is empty\n");
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void search_year(head *h, int int_) { // Поиск по году основания
    RUS *current = h->first;
    int c = 0;
    while (current != NULL) {
        if(current->date[2] == int_) {
            printf("%d. Subject: %s\n   Density: %.2f\n   Population: %d\n   Area: %d\n "
                   "  Percent: %.2f\n   Date of foundation: %d.%d.%d\n\n",
                   current->id, current->name, current->density, current->population, current->area,
                   current->percent, current->date[0], current->date[1],current->date[2]);
            c++;
        }
        current = current->next;
    }
    if(c == 0) {
        printf("List is empty\n");
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////