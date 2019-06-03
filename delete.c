#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "work.h"


int menu_delete(int r, head *h, int size) { // Выбор элемента для удаления
    int n, y=size, size1 = (h->size);
    if (r == 2) {
         if (size == 1) {
            y=1;
            delete(y, h);
            puts("");
        } else {
            printf("Enter the number of the list item you want to delete: ");
            scanf("%d", &n);
            while (n > size || n < 1) {
                printf("Input error. Enter the value again: ");
                scanf("%d", &n);
            }
            int f = delete(n, h);
            if (f != 0) {
                printf("Removed %d-th item\n\nList:\n", n);
            } else y = size1-1;
            output(h);
        }
    }
    return y;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int delete(int id, head *h) {  // Удаление элемента
    RUS *current = h->first;
    RUS *previous = current;
    int y =0;
    while (current != NULL && current->next != NULL)
    {
        if (current->name == NULL && current->next != NULL){

            current = current->next;
        }
        if (current->id == id)
        {
            y=1;
            previous->next = current->next;
            if (current == h->first)
                h->first = current->next;
            free(current);
        }
        previous = current;
        current = current->next;
    }
    if (y == 0) printf("This item has already been deleted\n");
    return y;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////