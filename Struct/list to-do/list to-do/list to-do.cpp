#include <iostream>
#include <string>
#include "func.h"
#include "utility.h"
#include <fstream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    size_t size = 0;
    short menu = -1;
    delo* mas = new delo[size];
    do 
    {
        cout << "MENU" << endl;
        cout << "1 - Ввести новую задачу;" << endl;
        cout << "2 - Редактировать дело;" << endl;
        cout << "3 - Удалить задачу;" << endl;     //Менюшка (Сделана)
        cout << "4 - найти задание;" << endl;
        cout << "5 - вывести на экран задания;" << endl;
        cin >> menu;
        switch (menu)  // Разобраться с ошибкой "мало аргумнетов"
        {
        case 1:
        {
            delo delo_;
            inputDelo(delo_);
            push_back(mas, size, delo_);
            ++size;
        }
        case 2:
        {
            editDelo(mas, size);
        }
        case 3:
        {
            
            deleteDelo();
        }
        case 4:
        {
            findDelo();
        }
        };
    }
    while (menu == 6); //Выход из менюшки
    cout << "Пока...";
}; 