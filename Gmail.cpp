#include "Gmail.h"
#pragma once

Gmail::Gmail(string userName, string userEmail)
{
    
        name = userName;
        gmailn = userEmail;
    
}

void Gmail::displayInfo() const
{
    cout << "Имя пользователя: " << name << endl;
    cout << "Почта: " << gmailn << endl;
}

string Gmail::getName() const
{
    return name;
}

string Gmail::getEmail() const
{
    return gmailn;
}
