#pragma once
using namespace std;
#include <iostream>
#include "./Person.h"

class Client : public Person
{
    double balance;

public:
    static int counter;

    // Constructor
    Client()
    {
        this->balance = 1500;
        counter++;
        this->setId(counter);
    }
    Client(string name, string password, double balance)
    {
        counter++;
        this->setId(counter);
        this->setName(name);
        this->setPassword(password);
        this->setBalance(balance);
    };
    double getBalance()
    {
        return balance;
    }

    // Setters & Getters
    void setBalance(double balance)
    {
        bool isValid = Validation::validateBalance(balance);
        if (isValid)
        {
            this->balance = balance;
        }
        else
        {
            // handle error phase 3

            cout << "invalid balance" << endl;
        }
    }
    // Methods
    void deposit(double amount)
    {
        if (amount < 0)
        {
            cout << "Invalid amount" << endl;
            return;
        }

        balance += amount;
    }
    void withdraw(double amount)
    {
        if (amount < 0)
        {
            cout << "Invalid amount" << endl;
            return;
        }
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
        if (amount < 0)
        {
            cout << "Invalid amount" << endl;
            return;
        }
        else
        {
            if ((this->balance - amount) >= 1500)
            {
                reciepient.deposit(amount);
                this->withdraw(amount);
            }
            else if ((this->balance - amount) < 1500 && (this->balance - amount) > 0)
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
int Client::counter = 0;