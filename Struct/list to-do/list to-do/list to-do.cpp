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
        cout << "6 - Выход" << endl;
        cin >> menu;
        switch (menu)
        {
        case 1:
        {
            delo delo_;
            inputDelo(delo_);
            push_back(mas, size, delo_);
            ++size;
            break;
        }
        case 2:
        {

            editDelo(mas, size);
            break;
        }
        case 3:
        {
            delo delo_;
            deleteDelo(mas, size);
            --size;
            break;
        }
        case 4:
        {
            delo;
            //findDelo(mas, size);
            break;
        }
        case 5:
        {
            delo delo_;
            //outDelo(mas, size);
            break;
        }
        };
    } while (menu != 6); //Выход из менюшки;

    cout << "Пока..." << '\n' << '\n';
}; 