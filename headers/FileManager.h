#pragma once
#include "./DataSource.h"

class FileManager : public DataSource
{
    // protected:
public:
    static vector<Client> allClients;
    static vector<Employee> allEmployees;
    static vector<Admin> allAdmins;

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
        return getAll(c, "Clients.txt", allClients);
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
        return getAll(e, "Employees.txt", allEmployees);
    }
    vector<Admin> getAllAdmins()
    {
        Admin a;
        return getAll(a, "Admins.txt", allAdmins);
    }
    void removeAllClients()
    {
        removeAll("Clients.txt");
    }
    void removeAllAdmins()
    {
        removeAll("Admins.txt");
    }
    void removeAllEmployees()
    {
        removeAll("Employees.txt");
    }
};
vector<Client> FileManager::allClients;
vector<Employee> FileManager::allEmployees;
vector<Admin> FileManager::allAdmins;