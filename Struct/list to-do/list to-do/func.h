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
 
void inputDelo(delo& d) //���� ����(�������)                   
{
    setlocale(LC_ALL, "Russian");
    cout << "������� �������� �������: "; cin >> d.name;
    cout << "������� ��������� �������: "; cin >> d.prior;
    cout << "��������������� �������: "; cin >> d.ops;
    cout << "������� ���� ������� � �������: ����.�����.���: "; cin >> d.date;
}

void editDelo(delo* mas, int size) //�������� ���(�� �����)
{
    int index = 0;
    setlocale(LC_ALL, "Russian");
    cout << "������� ����� ����: ";
    cin >> index;
    if (index >= size)
    {
        cout << "������ ���� ��� � ����" << endl;
    }
    cout << "������� ��� ����: " << endl; cin >> mas[index].name;
    cout << "������� ��������� ����: " << endl; cin >> mas[index].prior;
    cout << "������� ��������: " << endl; cin >> mas[index].ops;
    cout << "���� ����: " << endl; cin >> mas[index].date;
}

void deleteDelo(delo* mas, int size) //�������� ��������
{
    int index = 0;
    setlocale(LC_ALL, "Russian");
    cin >> index;
    if (index >= size) {
        cout << "������ ���� ��� � ����" << endl;
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
        cout << "�� �� �������. ";
        return -1;
    }
}
void outDelo(delo* mas, int index, int size) //����� ���� ��� �� �����
{
    for (int i = 0; i < size; ++i)
    {
        cout << "��� ���� ����: " << endl;
        cout << mas[index].name;
        cout << mas[index].prior;
        cout << mas[index].ops;
        cout << mas[index].date;
    }
}
