#pragma once

#include <iostream>

using namespace std;

class Worker
{
private:
    string name;
    string familia;
    int age;
public:
    Worker() : name(""), familia(""), age(0) {}

    ~Worker() {}

        void setName()
        {
            cin >> name;
        }

        void setFamilia()
        {
            cin >> familia;
        }

        void setAge()
        {
            cin >> age;
        }

        void setName(string nName) // прикольно, что в с++ функции перегружать можно
        {
            name = nName;
        }

        void setFamilia(string nFamilia)
        {
            familia = nFamilia;
        }

        void setAge(int Age)
        {
            age = Age;
        }



        const string& getName() const { return name; }

        const string& getFamilia() const { return familia; }

        int getAge() const { return age; }
};