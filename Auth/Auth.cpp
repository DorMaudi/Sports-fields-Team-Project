#include "Auth.h"

#define passlen 7

std::string formatDate(int day, int month, int year) {
    return std::to_string(day) + "/" + std::to_string(month) + "/" + std::to_string(year);
}

bool Auth::idAuth(std::string &e, std::string ID) {
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
    //
    //
    // Add check for ID's in array to ensure no existing users with that ID
    //
    //
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
    // Check if the provided birth date is valid
    if (!date::dateAuth(day, month, year)) {
        e = "Your birth date is invalid.";
        return false;
    }
    return true;
}

bool Auth::phonenumberAuth(std::string& e, std::string phonenumber) {
    // Check if phone number starts with '05'
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

bool Auth::login(const std::string ID, const std::string Password, std::string &Message, db &database){
    auto personArr = database.getPersonArr();
    int personArrSize = database.getNumOfUsers();
    for (int i = 0; i < personArrSize; ++i) {
        if (personArr[i]->getID() == ID) {
            if (personArr[i]->getPassword() == Password) {
                Message = "Successful login";
                return true; // Found the user, exit the loop
            } else {
                Message = "Password is incorrect";
                return false; // Found the user, exit the loop
            }
        }
    }
    Message = "User not found";
    return false;
}


