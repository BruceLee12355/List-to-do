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
    cout << "������� �������� �������: "; cin >> d.name;
    cout << "������� ��������� �������: "; cin >> d.prior;
    cout << "�������  �������� �������: "; cin >> d.ops;
    cout << "�������  ���� ������� � ������� ���� /������/����� "; cin >> d.date;
}

void editDelo(delo* mas, int size, int index)
{
    setlocale(LC_ALL, "Russian");
    if (index > size) {
        cout << "������ ���� ��� � ����" << endl;
    }
    cout << "������� ��� ����: " << endl; cin >> mas[index].name;
    cout << "������� ��������� ����: " << endl; cin >> mas[index].prior;
    cout << "������� ��������: " << endl; cin >> mas[index].ops;
    cout << "���� ����: " << endl; cin >> mas[index].date;
}
