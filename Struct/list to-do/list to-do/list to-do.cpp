#include <iostream>
#include <string>
using namespace std;


struct delo
{
    string name;
    int prior;
    string ops;
    int date;
};


void inputDelo(delo& d)
{
    setlocale(LC_ALL, "Russian");
    cout << "Введите название задания: "; cin >> d.name;
    cout << "Введите приоритет задания (от 1 до 10 где 1 наивысший приоритет!):"; cin >> d.prior;
    cout << "Введите  описание задания: "; cin >> d.ops;
    cout << "Введите  дату задания в формате день /неделя/месяц "; cin >> d.date;
}


int main()
{
    setlocale(LC_ALL, "Russian");
    string name = "";
    int prior = 1;
    string ops = "";
    string date = "";
    short menu = -1;
    do 
    {
        cout << "MENU" << endl;
        cout << "1 - Ввести новую задачу;" << endl;
        cout << "2 - Удалить задачу;" << endl;
        cout << "3 - редактировать задание;" << endl;
        cout << "4 - найти задание;" << endl;
        cout << "5 - вывести на экран задания;" << endl;
        cout << "6 - отсортировать задания;" << endl;
        cout << "Выберите пункт для меню: " << endl;
        cin >> menu;
        switch (menu) 
        {
        case 1:
            inputDelo();
            break;
        };
    }
    while (menu == 7);
};