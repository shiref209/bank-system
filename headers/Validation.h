#pragma once
#include <iostream>
using namespace std;

class Validation
{
public:
    static bool validateName(string name)
    {
        int length = name.length();
        string x;
        for (int i = 0; i < length; i++)
        {
            if (length < 5 || length > 20)
            {
                cout << "Invalid name" << endl;
                return false;
                break;
            }

            if (!((name[i] >= 'A' && name[i] <= 'Z') || (name[i] >= 'a' && name[i] <= 'z')))
            {
                cout << "Name must only contain alphabetics" << endl;
                return false;
                break;
            };
            return true;
        }
    };
    static bool validatePassword(string password)
    {
        int length = password.length();
        if (length < 5 || length > 20)
        {
            cout << "Password must be min 5 chars and max 20 chars";
            return false;
        }
        else
        {
            return true;
        }
    }
};
