#pragma once
#include "./Person.h"
#include "./Employee.h"

using namespace std;

class Admin : public Employee, virtual public Person
{
    double salary = 5000;

public:
    double getSalary()
    {
        return salary;
    }
};