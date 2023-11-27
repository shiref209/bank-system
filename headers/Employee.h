#pragma once

#include "./Person.h"
class FileManager;
class Employee : public Person
{
    double salary = 5000;
    // FileManager *fileManager;

public:
    Employee() {}
    Employee(int id, string name, string password, double salary)
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
    void setSalary(double salary)
    {
        this->salary = salary;
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
