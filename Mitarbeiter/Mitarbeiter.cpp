#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "Worker.h"
#include "WorkerDataBase.h"

using namespace std;

void cinWorker(WorkerDatabase* w)
{
    string nameS, familiaS;
    cout << "\nВведите имя сотрудника: ";
    cin >> nameS;
    cout << "\nВведите фамилию сотрудника: ";
    cin >> familiaS;
    w->removeWorker(nameS, familiaS);
}

int main()
{
    setlocale(LC_ALL, "Russian");

    bool choice;

    int ch;

    WorkerDatabase w;

    cout << "1: Создать сотрудника\n";
    cout << "2: Удалить сотрудника\n";
    cout << "3: Показать список сотрудников\n";
    cout << "4: Экспорт базы данных\n";
    cout << "5: Импорт базы данных\n";

    do
    {
        x:
        cout << "\n\nВыберите действие: ";
        cin >> ch;
        if (ch == 1)
        {
            w.addWorker();
        }
        else if(ch == 2)
        {
            cinWorker(&w);
        }
        else if (ch == 3)
        {
            w.displayWorkers();
        }
        else if (ch == 4)
        {
            w.saveToFile("Idk.txt");
            cout << "\nБаза экспортирована!";
        }
        else if (ch == 5)
        {
            w.loadFromFile("Idk.txt");
            cout << "\nБаза импортированна!";
        }
        else
        {
            cout << "\nОшибка!\n";
            goto x;
        }

        cout << "\n\nПродолжим? Если да, напишите цифру 1\nЕсли нет, напишите любую другую цифру: ";
        cin >> ch;
        if (ch == 1)
        {
            choice = true;
        }
        else
        {
            return 0;
        }
    } while (choice);
    return 0;
}
