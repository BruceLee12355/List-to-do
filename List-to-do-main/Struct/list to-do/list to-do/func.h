#pragma once
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
    cout << "Введите приоритет задания: "; cin >> d.prior;
    cout << "Введите  описание задания: "; cin >> d.ops;
    cout << "Введите  дату задания в формате день /неделя/месяц "; cin >> d.date;
}

void editDelo(delo* mas, int size, int index)
{
    setlocale(LC_ALL, "Russian");
    if (index > size) {
        cout << "Такого дела нет в базе" << endl;
    }
    cout << "Введите имя дела: " << endl; cin >> mas[index].name;
    cout << "Введите приоритет дела: " << endl; cin >> mas[index].prior;
    cout << "Введите описание: " << endl; cin >> mas[index].ops;
    cout << "Дата дела: " << endl; cin >> mas[index].date;
}
