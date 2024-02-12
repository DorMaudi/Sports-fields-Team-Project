
#include "db.h"
#include "cstring"
#ifndef SPORTS_FIELDS_TEAM_PROJECT_AUTH_H
#define SPORTS_FIELDS_TEAM_PROJECT_AUTH_H


class Auth {
private:
    int PhoneNumber,B_Date;
    char Gender;
    std::string pass,ID,F_Name,L_Name;
public:
    bool Login (const std::string ID,const std::string Password,std::string Message);
};


#endif //SPORTS_FIELDS_TEAM_PROJECT_AUTH_H
