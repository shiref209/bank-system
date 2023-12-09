// Here definition of methods body of Employee and Amin to be handled by FileManager class
// It's seperate to avoid circular dependency and to make sure all classes are ready to be implemented in sequence
#pragma once
#include "./FileManager.h"
// one object to deal with all methods
FileManager fileManager;

void Employee::addClient(Client &client)
{
    fileManager.addClient(client);
};
void Admin::addEmployee(Employee &employee)
{
    fileManager.addEmployee(employee);
};
Client *Employee::searchClient(int id)
{
    Client *c = new Client();
    fileManager.getSingle(c, "Clients.txt", id);
    // void singleSearch()

    // ifstream file("Clients.txt");
    // string line;
    // // vars to extract data
    // int seperatorIndex;
    // string prop;
    // string value;
    // bool isFound = false;
    // while (getline(file, line))
    // {
    //     seperatorIndex = line.find(":");
    //     prop = line.substr(0, seperatorIndex);
    //     if ((prop != "id" && !isFound) || (prop == ""))
    //     {
    //         continue;
    //     }
    //     value = line.substr(seperatorIndex + 1, -1);
    //     if (prop == "id" && stoi(value) == id)
    //     {
    //         c->setId(stoi(value));
    //         isFound = true;
    //         continue;
    //     }
    //     // Code done when user searched is found to extract rest of data
    //     if (isFound)
    //     {
    //         if (prop == "name")
    //         {
    //             c->setName(value);
    //             continue;
    //         }
    //         else if (prop == "password")
    //         {
    //             c->setPassword(value);
    //             continue;
    //         }
    //         else if (prop == "balance")
    //         {
    //             // balance only limited to client
    //             c->setBalance(stod(value));
    //             break;
    //         }
    //         // else if (prop == "salary")
    //         // {
    //         //     // check by dynamic casting if it's employee or admin
    //         //     if (employee)
    //         //     {
    //         //         employee->setSalary(stod(value));
    //         //     }
    //         //     else
    //         //     {
    //         //         // it's admin
    //         //         admin->setSalary(stod(value));
    //         //     };
    //         // }
    //         else if (prop == "")
    //         {
    //             cout << "empty line" << endl;
    //             break;
    //         }
    //     }
    // }
    return c;
};
Employee *Admin::searchEmployee(int id)
{
    Employee *e = new Employee();
    fileManager.getSingle(e, "Employees.txt", id);
    return e;
};
void Employee::listClients()
{
    vector<Client> allClients = fileManager.getAllClients();
    cout << "List of all clients:" << endl;
    for (int i = 0; i < allClients.size(); i++)
    {
        cout << allClients[i].getId() << endl;
        cout << allClients[i].getName() << endl;
        cout << allClients[i].getPassword() << endl;
        cout << allClients[i].getBalance() << endl;
    }
}
void Employee::editClient(int id, string name, string password, double balance)
{
    FileManager::allClients = fileManager.getAllClients();
    bool isFirstLine = false;
    fileManager.editPerson(FileManager::allClients, isFirstLine, "Clients.txt", id, name, password, balance);
    cout << "edited    " << name << endl;
}
void Admin::listEmployees()
{
    vector<Employee> allEmployees = fileManager.getAllEmployees();
    cout << "List of all Employees:" << endl;

    for (int i = 0; i < allEmployees.size(); i++)
    {
        cout << allEmployees[i].getId() << endl;
        cout << allEmployees[i].getName() << endl;
        cout << allEmployees[i].getPassword() << endl;
        cout << allEmployees[i].getSalary() << endl;
    }
}
void Admin::editEmployee(int id, string name, string password, double balance)
{
    vector<Employee> allEmployees = fileManager.getAllEmployees();
    bool isFirstLine = false;
    fileManager.editPerson(allEmployees, isFirstLine, "Employees.txt", id, name, password, balance);
}