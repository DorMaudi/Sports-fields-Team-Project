#include "Auth.h"

#define passlen 7

std::string formatDate(int day, int month, int year) {
    return std::to_string(day) + "/" + std::to_string(month) + "/" + std::to_string(year);
}

bool Auth::idAuth(std::string &e, std::string ID, db &database) {
    // Check if the ID has 9 digits
    if (ID.size() != 9){
        e = "Your ID is not 9 Numbers";
        return false;
    }
    // Check if all characters in ID are digits
    for (char c : ID) {
        if (!isdigit(c)||c == ' ') {
            e = "ID should contain only numbers.";
            return false;
        }
    }
    auto personArr = database.getPersonArr();
    int personArrSize = database.getNumOfUsers();
    for (int i = 0; i < personArrSize; ++i) {
        if (personArr[i]->getID() == ID) {
            e = "ID already exists";
            return false;
        }
    }
    return true;
}

bool Auth::passwordAuth (std::string& e, std::string password){
    // Check if password length meets the required length
    if (password.size() <= passlen) {
        e = "Your password should be longer than " + std::to_string(passlen+1) +" letters.";
        return false;
    }
    for (char c : password) {
        if (c == ' ') {
            e = "Your password should not contain spaces.";
            return false;
        }
    }
    return true;
}

bool Auth::firstNameAuth(std::string& e, std::string name) {
    // Check if first name contains only alphabetic characters
    for (char c : name) {
        if (!isalpha(c)||c == ' ') {
            e = "Your first name should only contain letters.";
            return false;
        }
    }
    return true;
}

bool Auth::lastNameAuth(std::string& e, std::string name) {
    // Check if last name contains only alphabetic characters
    for (char c : name) {
        if (!isalpha(c)||c == ' ') {
            e = "Your last name should only contain letters.";
            return false;
        }
    }
    return true;
}

bool Auth::genderAuth(std::string &e, char gender) {
    // Check if gender is either 'M' or 'F'
    if (gender != 'M' && gender != 'F') {
        e = "Invalid gender. Please enter 'M' for male or 'F' for female.";
        return false;
    }
    return true;
}

bool Auth::dateAuth(std::string &e, int day, int month, int year) {
    // Check if the provided birthdate is valid
    if (!date::dateAuth(day, month, year, e)) {
        e = "Your birth date is invalid.";
        return false;
    }
    return true;
}

bool Auth::phoneNumberAuth(std::string& e, std::string phonenumber) {
    // Check if phone number starts with "05"
    if (phonenumber[0] != '0' || phonenumber[1] != '5') {
        e = "Phone number should start with '05'";
        return false;
    }

    // Check if phone number length is at least 10
    if (phonenumber.size() < 10) {
        e = "Phone number is too short";
        return false;
    }

    // Check if all characters in the phone number are digits
    for (size_t i = 2; i < phonenumber.size(); ++i) {
        if (!isdigit(phonenumber[i])) {
            e = "Phone number should contain only digits";
            return false;
        }
    }

    return true;
}

bool Auth::login(const std::string ID, const std::string Password, std::string &e, db &database){

    auto personArr = database.getPersonArr();
    int personArrSize = database.getNumOfUsers();
    for (int i = 0; i < personArrSize; ++i) {
        if (personArr[i]->getID() == ID) {
            if (personArr[i]->getPassword() == Password) {
                e = "Successful login";
                return true; // Found the user, exit the loop
            } else {
                e = "Password is incorrect";
                return false; // Found the user, exit the loop
            }
        }
    }
    e = "User not found";
    return false;
}

bool Auth::ownerAuth(std::string &e, std::string ID, std::string fieldName, db &database, fields Fields) {
    auto personArr = database.getPersonArr();
    auto fieldArr = database.getFieldArr();
    int personArrSize = database.getNumOfUsers();
    int fieldArrSize = database.getNumOfFields();
    for (int i = 0; i < personArrSize; ++i) {
        if (personArr[i]->getID() == ID) {
            for (int j = 0; j < fieldArrSize; ++j) {
                if (fieldArr[j]->getName() == fieldName && fieldArr[j]->getOwnerId() == ID) {
                    return true;
                }
            }
            e = "You don't own any field with the name '" + fieldName + "'.";
            return false;
        }
    }
    // If the loop completes without finding the user, set error message
    e = "User with ID '" + ID + "' not found.";
    return false;
}

bool Auth::cityAuth(std::string& e, std::string city) {
    if (city == "Ashdod" || city == "Tel-Aviv" || city == "Jerusalem" || city == "Eilat" || city == "Ashkelon"){
        return true;
    }
    e = "We dont have that city.";
    return false;
}

bool Auth::sportTypeAuth(std::string &e, std::string sportType) {
    if (sportType == "Soccer" || sportType == "Basketball" || sportType == "Tennis" || sportType == "Football")
        return true;
    e = "We dont have a field for that sport type.";
    return false;
}

bool Auth::fieldNameAuth(std::string &e, std::string fieldName) {
    for (char c : fieldName) {
        if (!isalpha(c)||c == ' ') {
            e = "Field name should only contain letters.";
            return false;
        }
    }
    return true;
}
bool Auth::fieldAuth(std::string& e, std::string fieldName, db& db)
{
    for (auto i : db.getFieldArr())
    {
        if (i->getName() == fieldName)
        {
            e = "There is a fields with this name already.";
            return false;
        }
    }
    return true;
}

bool Auth::fieldDescription(std::string &e, std::string desc)
{
    if (desc.length() > 250)
    {
       e = "Description is longer than 250 characters.";
       return false;
    }
     return true;
}

bool Auth::accessibleField(std::string &e, bool acces)
{
    if (acces != 0 && acces != 1)
    {
        e = "incorrect value";
        return false;
    }
    return true;
}
//bool Auth::reservationAuth(std::string&e ,std::string sportType, std::string city, std::string fieldName, int day,int month, int year, db& database) {

//}