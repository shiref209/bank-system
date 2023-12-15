
#include <iostream>
#include "./headers/fileManager.h"
#include "./headers/InterfaceManager.h"
// #include "./headers/Person.h"
#include "./headers/Client.h"
// #include "./headers/Employee.h"
// #include "./headers/Admin.h"

using namespace std;

int main()
{
    vector<Client> allClients;
    allClients = fileManager.getAllClients();
    Client c1("cahmedz", "123456789", 12000);
    Client c2("cahmedx", "123456789", 13000);
    Client c3("cahmedc", "123456789", 14000);
    Client c4("cahmedv", "123456789", 15000);

    Employee e1("ahmedz", "123456789", 12000);
    Employee e2("ahmedx", "123456789", 13000);
    Employee e3("ahmedc", "123456789", 14000);
    Employee e4("ahmedv", "123456789", 15000);

    Admin a1("xahmedz", "123456789", 12000);
    Admin a2("xahmedx", "123456789", 13000);
    Admin a3("xahmedc", "123456789", 14000);
    Admin a4("xahmedv", "123456789", 15000);
    // a1.listEmployees();
    // a1.addEmployee(e1);
    // a1.addEmployee(e2);
    // a1.addEmployee(e3);
    // a1.addEmployee(e4);
    // cout << a1.searchEmployee(14)->getName() << endl;
    // cout << a1.searchClient(1)->getName() << endl;
    cout << allClients[1].getName() << endl;
    e1.editClient(2, "newnamezzzzz", "newpas2s", 10000);
    cout << allClients[1].getName() << endl;

    // a1.addClient(c1);
    // a4.addClient(c2);
    // a2.addClient(c3);
    // a3.addClient(c4);
    // allClients = a1.getAllClients();
    // Employee salah("salah", "123456789", -14000);
    // salah.deposit(1000);
    // salah.withdraw(500);
    // salah.transferTo(1000, sheref);
    // cout << salah.getSalary() << endl;
    // cout << sheref.getSalary() << endl;
    // cout << sheref.getId() << endl;

    // Client ahmed("ahmed", "123456789", 2400);
    // fileManager.addClient(sheref);
    // fileManager.addClient(ahmed);
    // Client khaled(3, "khaled", "123456789", 1);

    // Employee e1("shekos", "1234561234", 5000);
    // Admin a1("shekos", "1234561234", 5000);

    // cout << e1.getId() << endl;
    // cout << sheref.getBalance() << endl;
    // cout << ahmed.getId() << endl;
    // cout << a1.getId() << endl;

    // e1.addClient(khaled);
    // // cout << allClients[2].getName() << "    " << allClients[2].getBalance() << endl;

    // e1.editClient(3, "newkhaled", "987654321", 2);
    // // allClients = fileManager.getAllClients();
    // cout << allClients[2].getName() << "    " << allClients[2].getBalance() << endl;

    // Client *c3 = e1.searchClient(1);

    // Admin a1(1, "hemass", "124124124", 5000);
    // fileManager.addAdmin(a1);
    // a1.addEmployee(e1);
    // Employee *e2 = a1.searchEmployee(1);
    // a1.editEmployee(1, "newShekos", "987654321", 4000);
    // a1.editClient(3, "newkhalednewKh", "9876543dfs21", 3);
    // // allClients = fileManager.getAllClients();
    // a1.getName();
    // // e1.listClients();
    // e1.searchClient(1);
    // cout
    //     << allClients[2].getName() << "    " << allClients[2].getBalance() << endl;

    // cout << "hi" << endl;
    // // allClients = fileManager.getAllClients();

    // a1.editClient(3, "newkhKhKh", "9876543dfs21", 4);
    // // allClients = fileManager.getAllClients();
    // e1.searchClient(1);

    // cout << allClients[2].getName() << "    " << allClients[2].getBalance() << endl;
    return 0;
}