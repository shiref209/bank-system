#pragma once

#include "./Person.h"
class FileManager;
class Employee : public Person
{
    double salary;
    static int counter;

    // FileManager *fileManager;

public:
    Employee()
    {
        this->salary = 5000;
        counter++;
        this->setId(counter);
    }
    Employee(string name, string password, double salary)
    {
        counter++;
        this->setId(counter);
        this->setName(name);
        this->setPassword(password);
        this->setSalary(salary);
    }
    double getSalary()
    {
        return salary;
    }
    void setSalary(double salary)
    {
        bool isValid = Validation::validateSalary(salary);
        if (isValid)
        {
            this->salary = salary;
        }
        else
        {
            cout << "invalid salary" << endl;
            // handle error phase 3
        }
    }
    void display()
    {
        cout << "Name:" << this->getName() << endl;
        cout << "Id:" << this->getId() << endl;
        cout << "Salary:" << this->getSalary() << endl;
    }

    void addClient(Client &client);                                        // body at InterfaceManager.h
    Client *searchClient(int id);                                          // body at InterfaceManager.h
    void listClients();                                                    // body at InterfaceManager.h
    void editClient(int id, string name, string password, double balance); // body at InterfaceManager.h
};
int Employee::counter = 0;
