#pragma once
#include "./Person.h"
#include "./Employee.h"

using namespace std;

class Admin : public Employee, virtual public Person
{
    double salary = 5000;

public:
    Admin()
    {
    }
    Admin(int id, string name, string password, double salary)
    {
        this->setName(name);
        this->setPassword(password);
        this->setId(id);
        this->setSalary(salary);
    }
    double getSalary()
    {
        return salary;
    }
};