#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#include "list.h"
#include "menu.h"

int main() {
    SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода
    head h = MakeHead(); // Создаем голову
    int i = work_menu(&h); // Работаем с основным меню
    if (i == 0) menu_saving(&h); // Сохраняем в файл, если произошли какие-либо изменения
    printf("\n\nThanks for using the program");
    return 0;
}
