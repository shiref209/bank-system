#include <iostream>
#include "./headers/Person.h"
#include "./headers/Client.h"
#include "./headers/Employee.h"
#include "./headers/Admin.h"
#include "./headers/FileManager.h"

using namespace std;

int main()
{
    // Admin ahmed;
    // ahmed.setName("ali");
    // ahmed.setPassword("'123");
    // cout << ahmed.getPassword() << endl;
    // cout << ahmed.getName() << endl;
    FileManager file;
    Client sheref(1, "sherif", "123456789", 2000);
    Client ahmed(2, "ahmed", "123456789", 2400);
    file.addClient(sheref);
    file.addClient(ahmed);
    file.addClient(sheref);
    vector<Client> allClients;
    allClients = file.getAllClients();
    cout << allClients[0].getName();

    Admin a1(1, "hemass", "124124124", 5000);
    Admin a2(2, "sasass", "124124124", 5500);
    file.addAdmin(a1);
    file.addAdmin(a2);
    vector<Admin> allAdmins = file.getAllAdmins();
    cout << allAdmins[1].getName();

    cout << "hi" << endl;
    return 0;
}