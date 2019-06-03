#ifndef CURSWORK_DUBININ_8307_SEARCH_H
#define CURSWORK_DUBININ_8307_SEARCH_H

#include "struct.h"

void work_search(head *h); // Ввод элемента для поиска совпадений в картотеке

///////////////////////////////Работа с разными типами/////////////////////////////////////

void search_id(head *h, int id); // Поиск порядкового номера
void search_name(head *h, char *name); // Поиск имени субъекта
void search_density(head *h, float density); // Поиск по плотности субъекта
void search_pop(head *h, int pop); // Поиск по кол-ву населения
void search_area(head *h, int area); // Поиск по площади
void search_percent(head *h, float percent); // Поиск по процентному соотношению
                                // населения этого субъекта от насселения страны
void search_date(head *h, int date); // Поиск по дню основания
void search_month(head *h, int month); // Поиск по месяцу основания
void search_year(head *h, int year); // Поиск по году основания

#endif //CURSWORK_DUBININ_8307_SEARCH_H
