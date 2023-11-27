#pragma once
using namespace std;
#include <iostream>
#include "./Validation.h"
class Person
{
    int id;
    string name;
    string password;

public:
    // Setters
    void
    setName(string name)
    {
        bool isValid = Validation::validateName(name);
        if (isValid)
        {
            this->name = name;
        };
    }
    void setPassword(string password)
    {
        bool isValid = Validation::validatePassword(password);
        if (isValid)
        {
            this->password = password;
        };
    }
    void setId(int id)
    {
        this->id = id;
    }
    // Getters
    int getId()
    {
        return id;
    }
    string getName()
    {
        return name;
    }
    string getPassword()
    {
        return password;
    }

    // pure virtual display
    virtual void display() = 0;
};