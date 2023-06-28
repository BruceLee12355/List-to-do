#pragma once
#include <iostream>
#include <string>

using namespace std;

struct delo
{
    string name;
    string prior;
    string ops;
    string date;
};
 
void inputDelo(delo& d) //Ввод дела(Сделано)                   
{
    setlocale(LC_ALL, "Russian");
    cout << "Введите название задания: "; cin >> d.name;
    cout << "Введите приоритет задания: "; cin >> d.prior;
    cout << "Введитеописание задания: "; cin >> d.ops;
    cout << "Введите дату задания в формате: день.месяц.год: "; cin >> d.date;
}

void editDelo(delo* mas, int size) //Редактор дел(не пашет)
{
    int index = 0;
    setlocale(LC_ALL, "Russian");
    cout << "Введите номер дела: ";
    cin >> index;
    if (index >= size)
    {
        cout << "Такого дела нет в базе" << endl;
    }
    cout << "Введите имя дела: " << endl; cin >> mas[index].name;
    cout << "Введите приоритет дела: " << endl; cin >> mas[index].prior;
    cout << "Введите описание: " << endl; cin >> mas[index].ops;
    cout << "Дата дела: " << endl; cin >> mas[index].date;
}

void deleteDelo(delo* mas, int size) //Доделать удаление
{
    int index = 0;
    setlocale(LC_ALL, "Russian");
    cin >> index;
    if (index >= size) {
        cout << "Такого дела нет в базе" << endl;
    }
}

int findDelo(delo* mas, int size, string prior,
string name = "", string ops = "", string date = "")
{
    for (int i = 0; i < size; ++i)
    {
        if (mas[i].name == name)
        {
            return i;
        }
        else if (mas[i].prior == prior)
        {
            return i;
        }
        else if (mas[i].ops == ops)
        {
            return i;
        }
        else if (mas[i].date == date)
        {
            return i;
        }
        cout << "Ты че написал. ";
        return -1;
    }
}
void outDelo(delo* mas, int index, int size) //Вывод всех дел на экран
{
    for (int i = 0; i < size; ++i)
    {
        cout << "Все ваши дела: " << endl;
        cout << mas[index].name;
        cout << mas[index].prior;
        cout << mas[index].ops;
        cout << mas[index].date;
    }
}
