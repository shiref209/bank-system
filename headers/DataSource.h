#pragma once
#include <vector>
// #include "./Person.h"
#include "./Client.h"
// #include "./Employee.h"
#include "./Admin.h"
#include <fstream>
// #include <string>

class DataSource
{
public:
    // helpers
    // **********************************
    template <typename T>
    void addData(string fileName, T &object, bool isEditing = 0)
    {
        ofstream file;
        // Check if it's inside an edit method, file will be truncated on first line then append data
        if (isEditing)
        {
            file.open(fileName, ios::trunc);
            file.close();
            file.open(fileName, ios::app);
        }
        else
        {
            file.open(fileName, ios::app);
        }
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
            // else if (prop == "")
            // {
            //     cout << "empty line" << endl;
            // }
            else
            {
                // cout << "Empty line" << endl;
            };
            if (line.length() == 0)
            {
                allObjects.push_back(object);
            }
        }
        return allObjects;
    }
    void removeAll(string fileName)
    {
        ofstream file(fileName, ios::trunc);
        if (file.is_open())
        {
            cout << "file opened " << endl;
        }
        cout << "deleted" << endl;
        file.close();
    }
    template <typename T>
    void getSingle(T object, string fileName, int id)
    {
        ifstream file(fileName);
        string line;
        // dynamic cast to chect class of object
        Client *client = dynamic_cast<Client *>(object);
        Employee *employee = dynamic_cast<Employee *>(object);
        Admin *admin = dynamic_cast<Admin *>(object);
        // vars to extract data
        int seperatorIndex;
        string prop;
        string value;
        bool isFound = false;
        // Use a while loop together with the getline() function to read the file line by line
        while (getline(file, line))
        {
            seperatorIndex = line.find(":");
            prop = line.substr(0, seperatorIndex);
            if ((prop != "id" && !isFound) || (prop == ""))
            {
                continue;
            }
            value = line.substr(seperatorIndex + 1, -1);
            if (prop == "id" && stoi(value) == id)
            {
                object->setId(stoi(value));
                isFound = true;
                continue;
            }
            // Code done when user searched is found to extract rest of data
            if (isFound)
            {
                if (prop == "name")
                {
                    object->setName(value);
                    continue;
                }
                else if (prop == "password")
                {
                    object->setPassword(value);
                    continue;
                }
                else if (prop == "balance")
                {
                    // balance only limited to client
                    client->setBalance(stod(value));
                    break;
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
                    // cout << "empty line" << endl;
                    break;
                }
            }
        }
    }
    template <typename T>
    void editPerson(T &object, bool isEditing, string fileName, int id, string name, string password, double balance)
    {
        // check for type of person edited by dynamic casting
        Client *client = dynamic_cast<Client *>(&object[0]);
        Employee *employee = dynamic_cast<Employee *>(&object[0]);
        for (int i = 0; i < object.size(); i++)
        {
            if (i == 0)
            {
                isEditing = true;
            }
            else
            {
                isEditing = false;
            }
            if (object[i].getId() == id)
            {
                // edit data
                object[i].setName(name);
                object[i].setPassword(password);
                if (client)
                {
                    client[i].setBalance(balance);
                }
                else if (employee)
                {
                    employee[i].setSalary(balance);
                }

                // write the edited data to file
                addData(fileName, object[i], isEditing);
            }
            else
            {
                addData(fileName, object[i], isEditing);
            }
        }
    }

    virtual void addClient(Client) = 0;
    virtual void addEmployee(Employee) = 0;
    virtual void addAdmin(Admin) = 0;
    virtual vector<Client> getAllClients() = 0;
    virtual vector<Employee> getAllEmployees() = 0;
    virtual vector<Admin> getAllAdmins() = 0;
    virtual void removeAllClients() = 0;
    virtual void removeAllEmployees() = 0;
    virtual void removeAllAdmins() = 0;
};