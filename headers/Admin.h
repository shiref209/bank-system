#pragma once
#include "./Employee.h"

using namespace std;

class Admin : public Employee
// , virtual public Person
{
    double salary;
    static int counter;

public:
    Admin()
    {
        this->salary = 5000;
        counter++;
        this->setId(counter);
    }
    // Inherit same constructor of Parent employee to intialize obj of Admin(DRY)
    Admin(string name, string password, double salary) : Employee(name, password, salary)
    {
        this->counter++;
        this->setId(this->counter);
    }

    double getSalary()
    {
        return salary;
    }
    void addEmployee(Employee &employee);                                    // body at InterfaceManager.h
    Employee *searchEmployee(int id);                                        // body at InterfaceManager.h
    void listEmployees();                                                    // body at InterfaceManager.h
    void editEmployee(int id, string name, string password, double balance); // body at InterfaceManager.h
};
int Admin::counter = 0;