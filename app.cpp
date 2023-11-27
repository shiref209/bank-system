
#include <iostream>
#include "./headers/FileManager.h"
#include "./headers/InterfaceManager.h"
// #include "./headers/Person.h"
// #include "./headers/Client.h"
// #include "./headers/Employee.h"
// #include "./headers/Admin.h"

using namespace std;

int main()
{

    FileManager file;
    Client sheref(1, "sherif", "123456789", 2000);
    Client ahmed(2, "ahmed", "123456789", 2400);
    file.addClient(sheref);
    file.addClient(ahmed);
    vector<Client> allClients;
    allClients = file.getAllClients();
    Client khaled(3, "khaled", "123456789", 2500);

    Employee e1(1, "shekos", "1234561234", 5000);
    e1.addClient(khaled);
    e1.editClient(3, "newkhaled", "987654321", 5200);
    allClients = file.getAllClients();
    // cout << allClients[2].getName() << allClients[2].getId() << allClients[2].getBalance() << allClients[2].getPassword() << endl;

    Client *c3 = e1.searchClient(1);

    Admin a1(1, "hemass", "124124124", 5000);
    file.addAdmin(a1);
    a1.addEmployee(e1);
    Employee *e2 = a1.searchEmployee(1);
    a1.editEmployee(1, "newShekos", "987654321", 4000);
    a1.editClient(3, "newkhalednewKh", "9876543dfs21", 5200);
    cout << "hi" << endl;
    return 0;
}