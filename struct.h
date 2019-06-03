#ifndef CURSWORK_DUBININ_8307_STRUCT_H
#define CURSWORK_DUBININ_8307_STRUCT_H

typedef struct RUS{
    int id;	/// Порядковый номер в списке
    char *name; /// Наименование субъекта
    float density; /// Плотность населения (чел/кв.м)
    int population; /// Население
    int area; /// Площадь (кв.км)
    float percent; /// Процент населения (%)
    int date[3]; /// Дата основания
    struct RUS *next; /// Указатель на следующий элемент списка
}RUS;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef struct head {	//Заголовочный элемент
    int size;	//количество листов списка
    struct RUS *first;	//указатель на первый элемент
}head;

#endif //CURSWORK_DUBININ_8307_STRUCT_H
