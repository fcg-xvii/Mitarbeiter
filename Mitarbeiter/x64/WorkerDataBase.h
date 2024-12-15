#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "Worker.h"

class WorkerDatabase
{
private:
    vector<Worker> workers;
public:
    void addWorker()
    {
        Worker newWorker;
        cout << "\n�������� ��� ���������: ";
        newWorker.setName();
        cout << "\n�������� ������� ���������: ";
        newWorker.setFamilia();
        cout << "\n�������� ������� ���������: ";
        newWorker.setAge();

        workers.push_back(newWorker);
    }

    void displayWorkers() const {
        for (int i = 0; i < workers.size(); i++)
        {
            string name, familia;
            name = workers[i].getName();
            familia = workers[i].getFamilia();
            cout << endl << name << " " << familia;
        }
    }

    void removeWorker(const string& Name, const string& familia) {
        for (auto it = workers.begin(); it != workers.end(); ++it)
        {
            if (it->getName() == Name && it->getFamilia() == familia) {
                workers.erase(it);
                break;
            }
        }
    }

    void saveToFile(const string& filePath) const {
        ofstream file(filePath);
        if (!file.is_open()) {
            cout << "\n������ �������� �����!\n";
            return;
        }

        for (int i = 0; i < workers.size(); i++)
        {
            file << workers[i].getName() << "," << workers[i].getFamilia() << "," << workers[i].getAge() << "\n";
        }

        file.close();
    }

    void loadFromFile(const string& filePath) {
        ifstream file(filePath);
        if (!file.is_open()) {
            cerr << "\n������ �������� ����� ��� ������!\n";
            return;
        }

        workers.clear();

        string line;
        while (getline(file, line)) {
            istringstream iss(line);
            string name, familia;
            int age;

            getline(iss, name, ',');
            getline(iss, familia, ',');
            iss >> age;

            Worker newWorker;
            newWorker.setName(name);
            newWorker.setFamilia(familia);
            newWorker.setAge(age);

            workers.push_back(newWorker);
        }

        file.close();
    }
};
