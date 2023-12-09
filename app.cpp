
#include <iostream>
#include "./headers/fileManager.h"
#include "./headers/InterfaceManager.h"
// #include "./headers/Person.h"
// #include "./headers/Client.h"
// #include "./headers/Employee.h"
// #include "./headers/Admin.h"

using namespace std;

int main()
{
    // FileManager::allClients;
    vector<Client> allClients;
    allClients = fileManager.getAllClients();
    Client sheref(1, "sherif", "123456789", 2000);
    Client ahmed(2, "ahmed", "123456789", 2400);
    fileManager.addClient(sheref);
    fileManager.addClient(ahmed);
    Client khaled(3, "khaled", "123456789", 1);

    Employee e1(1, "shekos", "1234561234", 5000);
    e1.addClient(khaled);
    // cout << allClients[2].getName() << "    " << allClients[2].getBalance() << endl;

    e1.editClient(3, "newkhaled", "987654321", 2);
    // allClients = fileManager.getAllClients();
    cout << allClients[2].getName() << "    " << allClients[2].getBalance() << endl;

    Client *c3 = e1.searchClient(1);

    Admin a1(1, "hemass", "124124124", 5000);
    fileManager.addAdmin(a1);
    a1.addEmployee(e1);
    Employee *e2 = a1.searchEmployee(1);
    a1.editEmployee(1, "newShekos", "987654321", 4000);
    a1.editClient(3, "newkhalednewKh", "9876543dfs21", 3);
    // allClients = fileManager.getAllClients();
    a1.getName();
    // e1.listClients();
    e1.searchClient(1);
    cout
        << allClients[2].getName() << "    " << allClients[2].getBalance() << endl;

    cout << "hi" << endl;
    // allClients = fileManager.getAllClients();

    a1.editClient(3, "newkhKhKh", "9876543dfs21", 4);
    // allClients = fileManager.getAllClients();
    e1.searchClient(1);

    cout << allClients[2].getName() << "    " << allClients[2].getBalance() << endl;
    return 0;
}