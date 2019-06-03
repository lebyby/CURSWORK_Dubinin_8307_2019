#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"
#include "work.h"
#include "menu.h"



void work_editing(int size, head *h){ // Выбор номера элемента для изменения
    //setlocale("LC_ALL", "");
    int c;

    printf("Enter subject's id: ");
    scanf("%d", &c);
    while ((c < 1) || (c > size)) {
            printf("Incorrect input! Try again: ");
            scanf("%d", &c);
    }
    int f = menu_edit(); // Выбор столбца
    if (f == 1) {
        edit_name(c, h);
    } else if (f == 2) {
        edit_density(c, h);
    } else if (f == 3) {
        edit_pop(c, h);
    } else if (f == 4) {
        edit_area(c, h);
    } else if (f == 5) {
        edit_percent(c, h);
    } else if (f == 6) {
        edit_day(c, h);
    } else if (f == 7) {
        edit_month(c, h);
    } else if (f == 8) {
        edit_year(c, h);
    }
}

//////////////////////////////////////Работа с разными типами//////////////////////////////////////////////////////

void edit_name(int id, head *h) {  // Изменение элемента
    RUS *current = h->first;
    char *edit = newChar();

    while (current != NULL)
    {
        if (current->id == id)
        {
               printf("The item you want to change: %s\n", current->name);
               printf("Introduced changes: ");
               scanf("%s", edit);
               current->name=edit;
               return;
        }
        current = current->next;
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void edit_density(int id, head *h) {  // Изменение элемента
    RUS *current = h->first;
    float edit;

    while (current != NULL)
    {
        if (current->id == id)
        {
            printf("The item you want to change: %f\n", current->density);
            printf("Introduced changes: ");
            scanf("%f", &edit);
            current->density=edit;
            return;
        }
        current = current->next;
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void edit_pop(int id, head *h) {  // Изменение элемента
    RUS *current = h->first;
    int edit;

    while (current != NULL)
    {
        if (current->id == id)
        {
            printf("The item you want to change: %d\n", current->population);
            printf("Introduced changes: ");
            scanf("%d", &edit);
            current->population = edit;
            return;
        }
        current = current->next;
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void edit_area(int id, head *h) {  // Изменение элемента
    RUS *current = h->first;
    int edit;

    while (current != NULL)
    {
        if (current->id == id)
        {
            printf("The item you want to change: %d\n", current->area);
            printf("Introduced changes: ");
            scanf("%d", &edit);
            current->area = edit;
            return;
        }
        current = current->next;
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void edit_percent(int id, head *h) {  // Изменение элемента
    RUS *current = h->first;
    float edit;

    while (current != NULL)
    {
        if (current->id == id)
        {
            printf("The item you want to change: %f\n", current->percent);
            printf("Introduced changes: ");
            scanf("%f", &edit);
            current->percent=edit;
            return;
        }
        current = current->next;
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void edit_day(int id, head *h) { // Изменение элемента
    RUS *current = h->first;
    int edit;

    while (current != NULL)
    {
        if (current->id == id)
        {
            printf("The item you want to change: %d\n", current->date[0]);
            printf("Introduced changes: ");
            scanf("%d", &edit);
            current->date[0] = edit;
            return;
        }
        current = current->next;
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void edit_month(int id, head *h) {  // Изменение элемента
    RUS *current = h->first;
    int edit;

    while (current != NULL)
    {
        if (current->id == id)
        {
            printf("The item you want to change: %d\n", current->date[1]);
            printf("Introduced changes: ");
            scanf("%d", &edit);
            current->date[1] = edit;
            return;
        }
        current = current->next;
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void edit_year(int id, head *h) {  // Изменение элемента
    RUS *current = h->first;
    int edit;

    while (current != NULL)
    {
        if (current->id == id)
        {
            printf("The item you want to change: %d\n", current->date[2]);
            printf("Introduced changes: ");
            scanf("%d", &edit);
            current->date[2] = edit;
            return;
        }
        current = current->next;
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////