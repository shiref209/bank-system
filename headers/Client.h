#pragma once
using namespace std;
#include <iostream>
#include "./Person.h"

class Client : virtual public Person
{
    double balance = 1500;

public:
    // Constructor
    Client()
    {
        // this->id=
    }
    Client(int id, string name, string password, double salary)
    {
        this->setName(name);
        this->setPassword(password);
        this->setId(id);
        this->setBalance(balance);
    };
    double getBalance()
    {
        return balance;
    }

    // Setters & Getters
    void setBalance(double balance)
    {
        this->balance = balance;
    }
    // Methods
    void deposit(double amount)
    {
        balance += amount;
    }
    void withdraw(double amount)
    {
        if (amount <= this->balance)
        {
            balance -= amount;
        }
        else
        {
            cout << "Sorry, your balance is less than the amount" << endl;
        }
    }
    void transferTo(double amount, Client &reciepient)
    {
        if (this->balance - amount >= 1500)
        {
            reciepient.deposit(amount);
            this->withdraw(amount);
        }
        else if (this->balance - amount < 1500)
        {
            cout << "Your balance is under the minimum limit, please consider depositing minimum of" << 1500 - (this->balance - amount) << endl;
            reciepient.deposit(amount);
            this->withdraw(amount);
        }
        else
        {
            cout << "Insufficient Balance" << endl;
        }
    }
    void checkBalance()
    {
        cout << "Your balance is: " << this->getBalance() << endl;
    }
    void display()
    {
        cout << "Name: " << this->getName() << endl;
        cout << "Balance: " << this->getBalance() << endl;
    }
};
