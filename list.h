#ifndef CURSWORK_DUBININ_8307_LIST_H
#define CURSWORK_DUBININ_8307_LIST_H

#include "struct.h"

head MakeHead(); // Создание головы
int read(head *h); // Считывание с файла
head *DLC(head *h, FILE *f); // Добавление по строке
void add(RUS *SUBJ, head *h); // Добавление элемента
void output(head *h); // Вывод списка
void save_in_file(FILE *f, head *h); // Сохрание в новый файл

#endif //CURSWORK_DUBININ_8307_LIST_H
