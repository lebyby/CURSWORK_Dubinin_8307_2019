#ifndef CURSWORK_DUBININ_8307_SORT_H
#define CURSWORK_DUBININ_8307_SORT_H

#include "struct.h"

void work_sort(head *);  // Выбор столбца для сортировки
void swap(RUS *a, RUS *b); // Замена

///////////////////////////////Работа с разными типами/////////////////////////////////////

void sort_id(head *h); // Сортировка по порядковому номеру
void sort_name(head *h); // Сортировка по имени
void sort_density(head *h); // Сортировка по плотности
void sort_pop(head *h); // Сортировка по населению
void sort_area(head *h); // Сортироска по площади
void sort_percent(head *h); // Сортировка по процентному соотношению
                        // населения этого субъекта от насселения страны
void sort_date(head *h); // Сортировка по дню основания
void sort_month(head *h); // Сортировка по месяцу основания
void sort_year(head *h); // Сортировка по году основания

#endif //CURSWORK_DUBININ_8307_SORT_H
