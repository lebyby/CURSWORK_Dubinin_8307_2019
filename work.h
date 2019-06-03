#ifndef CURSWORK_DUBININ_8307_WORK_H
#define CURSWORK_DUBININ_8307_WORK_H

#include "struct.h"

////////////////////////////////////////Удаление//////////////////////////////////////////////////////////////////

int menu_delete(int r, head *h, int); // Выбор элемента для удаления
int delete(int id, head *h); // Удаление элемента

//////////////////////////////////////Добавление//////////////////////////////////////////////////////////////////

char* newChar(); // Создание новой строки
void record(head *, int); // Ввод нового элемента картотеки
void recording(RUS *SUBJ, head *h, int); // Добавление нового элеменкта картотеки

/////////////////////////////////////Редактирование///////////////////////////////////////////////////////////////

void work_editing(int size, head*);  // Выбор номера элемента для изменения
///
////
void edit_name(int id, head *h);  // Изменение имени
void edit_density(int id, head*); // Изменение плотности
void edit_pop(int id, head*); // Изменение населения
void edit_area(int id, head*); // Изменение площади
void edit_percent(int id, head*); // Изменение процента
void edit_day(int id, head*); // Изменение дня
void edit_month(int id, head*); // Изменение месяца
void edit_year(int id, head*); // Изменение года

#endif //CURSWORK_DUBININ_8307_WORK_H
