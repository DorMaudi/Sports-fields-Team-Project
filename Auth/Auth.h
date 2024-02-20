
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
    bool login (const std::string& ID, const std::string& Password, std::string& Message);
    bool Register ();
    bool idAuth (std::string &e, std::string ID);
    bool passwordAuth (std::string& e, std::string password);
    bool firstNameAuth (std::string& e, std::string name);
    bool lastNameAuth (std::string& e, std::string name);
    bool genderAuth (std::string& e, char gender);
    bool dateAuth (std::string&e ,int day,int month, int year);
    bool phonenumberAuth (std::string& e, std::string phonenumber);
};


#endif //SPORTS_FIELDS_TEAM_PROJECT_AUTH_H
