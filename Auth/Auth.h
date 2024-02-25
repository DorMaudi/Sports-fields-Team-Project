
#ifndef SPORTS_FIELDS_TEAM_PROJECT_AUTH_H
#define SPORTS_FIELDS_TEAM_PROJECT_AUTH_H

#include <string>
#include <iostream>
#include <cctype>
#include <vector>
#include "db.h"
#include "date.h"

class Auth {
private:
    //std::vector<Person*> personArr; unused
public:

    static bool login (const std::string ID, const std::string Password, std::string &Message, db& datebase);

    bool Register ();
  
    // Validates the ID and Passowrd

    static bool idAuth(std::string &e, std::string ID, db &database);
    // Validates the format of an ID, ensuring it has exactly 9 digits and contains only numeric characters.

    static bool passwordAuth(std::string& e, std::string password);
    // Validates the length of a password, ensuring it meets the required length criteria.

    static bool firstNameAuth(std::string& e, std::string name);
    // Validates the format of a first name, ensuring it contains only alphabetic characters.

    static bool lastNameAuth(std::string& e, std::string name);
    // Validates the format of a last name, ensuring it contains only alphabetic characters.

    static bool genderAuth(std::string& e, char gender);
    // Validates the format of a gender input, ensuring it is either 'M' for male or 'F' for female.

    static bool dateAuth(std::string& e, int day, int month, int year);
    // Validates the format of a date input, ensuring it represents a valid date.

    static bool phoneNumberAuth(std::string& e, std::string phonenumber);
    
    // Validates the format of a phone number, ensuring it starts with '05' and consists only of digits.

};


#endif //SPORTS_FIELDS_TEAM_PROJECT_AUTH_H
