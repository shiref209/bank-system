#pragma once
#include "./Employee.h"

using namespace std;

class Admin : public Employee
// , virtual public Person
{
    double salary = 5000;

public:
    Admin()
    {
    }
    // Inherit same constructor of Parent employee to intialize obj of Admin(DRY)
    Admin(int id, string name, string password, double salary) : Employee(id, name, password, salary) {}

    double getSalary()
    {
        return salary;
    }
    void addEmployee(Employee &employee);                                    // body at InterfaceManager.h
    Employee *searchEmployee(int id);                                        // body at InterfaceManager.h
    void listEmployees();                                                    // body at InterfaceManager.h
    void editEmployee(int id, string name, string password, double balance); // body at InterfaceManager.h
};