
#pragma once
#include <iostream>
using namespace std;

class Gmail {
    string name;
    string gmailn;

public:
    Gmail(string userName, string userEmail);
    void displayInfo() const;
    string getName() const;
    string getEmail() const;
};

