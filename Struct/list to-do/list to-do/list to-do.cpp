#include <iostream>
#include <string>
#include "func.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    string name = "";
    int prior = 1;
    string ops = "";
    string date = "";
    int const index = 1;
    short menu = -1;
    int mas[index]{};
    do 
    {
        cout << "MENU" << endl;
        cout << "1 - Ввести новую задачу;" << endl;
        cout << "2 - Редактировать дело;" << endl;
        cout << "3 - Удалить задачу;" <<  endl;
        cout << "4 - найти задание;" << endl;
        cout << "5 - вывести на экран задания;" << endl;
        cin >> menu;
        switch (menu) 
        {
        case 1:
        {
            delo delo_;
            inputDelo(delo_);
            menu = mas[index];
            break; 
        }
        case 2:
        {
            editDelo();
            break;
        }
        case 4:
        {
            findDelo();
        }
        };
    }
    while (menu == 6);
};