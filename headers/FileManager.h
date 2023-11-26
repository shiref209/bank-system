#pragma once
#include <vector>
#include "./Person.h"
#include "./Client.h"
#include "./Employee.h"
#include "./Admin.h"
#include <fstream>
// #include <iostream>
#include <string>
// using namespace std;
class DataSource
{
public:
    template <typename T>
    // helpers
    // **********************************
    void addData(string fileName, T &object)
    {
        ofstream file(fileName, ios::app);
        if (file.is_open())
        {
            file << "id:" << object.getId() << endl;
            file << "name:" << object.getName() << endl;
            file << "password:" << object.getPassword() << endl;
            // Dynamic casting to check
            Client *client = dynamic_cast<Client *>(&object);
            Employee *employee = dynamic_cast<Employee *>(&object);
            Admin *admin = dynamic_cast<Admin *>(&object);
            if (client)
            {
                file << "balance:" << client->getBalance() << endl;
            }
            else if (employee)
            {
                file << "salary:" << employee->getSalary() << endl;
            }
            else if (admin)
            {
                file << "salary:" << admin->getSalary() << endl;
            }
            file << endl;
        }
        else
        {
            cout << "file not open" << endl;
        }

        file.close();
    }
    // Get All helper
    template <typename T>
    vector<T> getAll(T &object, string fileName)
    {
        ifstream file(fileName);
        string line;
        vector<T> allObjects;
        T person;
        // dynamic cast to chect class of object
        Client *client = dynamic_cast<Client *>(&object);
        Employee *employee = dynamic_cast<Employee *>(&object);
        Admin *admin = dynamic_cast<Admin *>(&object);

        // vars to extract data
        int seperatorIndex;
        string prop;
        string value;
        // Use a while loop together with the getline() function to read the file line by line
        while (getline(file, line))
        {
            // Extract data from line
            seperatorIndex = line.find(":");
            prop = line.substr(0, seperatorIndex);
            value = line.substr(seperatorIndex + 1, -1);
            if (prop == "id")
            {
                object.setId(stoi(value));
            }
            else if (prop == "name")
            {
                object.setName(value);
            }
            else if (prop == "password")
            {
                object.setPassword(value);
            }
            else if (prop == "balance")
            {
                // balance only limited to client
                client->setBalance(stod(value));
            }
            else if (prop == "salary")
            {
                // check by dynamic casting if it's employee or admin
                if (employee)
                {
                    employee->setSalary(stod(value));
                }
                else
                {
                    // it's admin
                    admin->setSalary(stod(value));
                };
            }
            else if (prop == "")
            {
                cout << "empty line" << endl;
            }
            else
            {
                cout << "Empty line" << endl;
            };
            if (line.length() == 0)
            {
                allObjects.push_back(object);
            }
        }
        return allObjects;
    }

    virtual void addClient(Client) = 0;
    virtual void addEmployee(Employee) = 0;
    virtual void addAdmin(Admin) = 0;
    virtual vector<Client> getAllClients() = 0;
    virtual vector<Employee> getAllEmployees() = 0;
    virtual vector<Admin> getAllAdmins() = 0;
    // virtual void removeAllClients() = 0;
    // virtual void removeAllEmployees() = 0;
    // virtual void removeAllAdmins() = 0;
};

class FileManager : public DataSource
{
public:
    void addClient(Client c)
    {
        addData("Clients.txt", c);
        // ofstream file("Clients.txt", ios::app);
        // if (file.is_open())
        // {
        //     file << "id:" << to_string(c.getId()) << endl;
        //     file << "name:" << c.getName() << endl;
        //     file << "password:" << c.getPassword() << endl;
        //     file << "balance:" << to_string(c.getBalance()) << endl;
        //     file << endl;
        // }
        // else
        // {
        //     cout << "file not open" << endl;
        // }

        // file.close();
    };
    void addEmployee(Employee c)
    {
        addData("Employees.txt", c);
    };
    void addAdmin(Admin c)
    {
        addData("Admins.txt", c);
    };
    // Get all

    // vector<Client> getAllClients()
    vector<Client> getAllClients()
    {
        Client c;
        return getAll(c, "Clients.txt");
        // ifstream file("Clients.txt");
        // string line;
        // vector<Client> Clients;
        // Client c;
        // // vars to extract data
        // int seperatorIndex;
        // string prop;
        // string value;
        // // Use a while loop together with the getline() function to read the file line by line
        // while (getline(file, line))
        // {
        //     // Output the text from the file
        //     // Extract data from line
        //     seperatorIndex = line.find(":");
        //     prop = line.substr(0, seperatorIndex);
        //     value = line.substr(seperatorIndex + 1, -1);
        //     if (prop == "id")
        //     {
        //         c.setId(stoi(value));
        //     }
        //     else if (prop == "name")
        //     {
        //         c.setName(value);
        //     }
        //     else if (prop == "password")
        //     {
        //         c.setPassword(value);
        //     }
        //     else if (prop == "balance")
        //     {
        //         c.setBalance(stod(value));
        //     }
        //     else if (prop == "")
        //     {
        //         cout << "empty line" << endl;
        //     }
        //     else
        //     {
        //         cout << "Empty line" << endl;
        //     };
        //     // cout << value << endl;
        //     if (line.length() == 0)
        //     {
        //         Clients.push_back(c);
        //     }
        // }
        // return Clients;
    }
    vector<Employee> getAllEmployees()
    {
        Employee e;
        return getAll(e, "Employees.txt");
    }
    vector<Admin> getAllAdmins()
    {
        Admin a;
        return getAll(a, "Admins.txt");
    }
};