#pragma once
#include "./Person.h"
// #include <iostream>
// using namespace std;

class Employee : virtual public Person
{
    double salary = 5000;

public:
    double getSalary()
    {
        return salary;
    }
    void display()
    {
        cout << "Name:" << this->getName() << endl;
        cout << "Id:" << this->getId() << endl;
        cout << "Salary:" << this->getSalary() << endl;
    }
};