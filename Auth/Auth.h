
#include "db.h"
#include <string>
#include "date.h"
#include <iostream>
#include <cctype>
#ifndef SPORTS_FIELDS_TEAM_PROJECT_AUTH_H
#define SPORTS_FIELDS_TEAM_PROJECT_AUTH_H


class Auth {
private:
    int PhoneNumber;
    char Gender;
    std::string Password,ID,F_Name,L_Name,B_Date;
public:
    bool Login (const std::string& ID, const std::string& Password, std::string& Message);
    bool Register ();
};


#endif //SPORTS_FIELDS_TEAM_PROJECT_AUTH_H
