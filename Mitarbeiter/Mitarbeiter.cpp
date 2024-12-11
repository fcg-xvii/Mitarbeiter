#include <iostream>
#include <string>
#include <vector>

using namespace std;

class worker
{
private:
    string name;
    string familia;
    int age;
public:
    worker() : name(""), familia(""), age(0) {}  // Использую инициализацию членов в конструкторе

    ~worker() {}

        void getName()
        {
            cin >> name;
        }

        void getFamilia()
        {
            cin >> familia;
        }

        void getAge()
        {
            cin >> age;
        }

        // Перегружаю операторы
        const string& getName() const { return name; }

        const string& getFamilia() const { return familia; }

        int getAge() const { return age; }
};

class workerDatabase
{
private:
    vector<worker> workers;
public:
    void addWorker()
    {
        worker newWorker;
        cout << "\nНапишите имя работника: ";
        newWorker.getName();
        cout << "\nНапишите фамилию работника: ";
        newWorker.getFamilia();
        cout << "\nНапишите возраст работника: ";
        newWorker.getAge();

        workers.push_back(newWorker);
    }

    void displayWorkers() const {
            for (const auto &localWorker : workers) 
            {
                cout << localWorker << endl; // ошибка отсутствует оператор "<<", соответствующий этим операндам

            }
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    workerDatabase w;
    w.addWorker();
    w.displayWorkers();
}