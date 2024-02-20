//
// Created by Roei on 18/02/2024.
//

#include "Person.h"
#include <regex>

Person::Person(const std::string& ID, const std::string& password, const std::string& firstName,const std::string& lastName, const std::string& phoneNumber, char gender) {
    setID(ID);
    setPassword(password);
    setFirstName(firstName);
    setLastName(lastName);
    setPhoneNumber(phoneNumber);
    setGender(gender);
}

std::string Person::getID() const {
    return ID;
}

std::string Person::getPassword() const {
    return password;
}

std::string Person::getFirstName() const {
    return f_name;
}

std::string Person::getLastName() const {
    return l_name;
}

std::string Person::getPhoneNumber() const {
    return phoneNumber;
}

char Person::getGender() const {
    return gender;
}

void Person::setID(const std::string& ID) {
    if (isValidID(ID)) {
        this->ID = ID;
    }
}

void Person::setPassword(const std::string& password) {
    if (isValidPassword(password)) {
        this->password = password;
    }
}

void Person::setFirstName(const std::string& firstName) {
    this->f_name = firstName;
}

void Person::setLastName(const std::string& lastName) {
    this->l_name = lastName;
}

void Person::setPhoneNumber(const std::string& phoneNumber) {
    if (isValidPhoneNumber(phoneNumber)) {
        this->phoneNumber = phoneNumber;
    }
}

void Person::setGender(char gender) {
    if (isValidGender(gender)) {
        this->gender = gender;
    }
}

bool Person::isValidID(const std::string& ID) {
    // Check if ID is alphanumeric and has a minimum length of 9 characters
    return std::regex_match(ID, std::regex("[[:alnum:]]{9,}"));
}

bool Person::isValidPassword(const std::string& password) {
    // Check if password has a minimum length of 8 characters and contains no spaces
    return (password.length() >= 8) && (password.find(' ') == std::string::npos);
}

bool Person::isValidPhoneNumber(const std::string& phoneNumber) {
    // Check if phone number has valid format 05xxxxxxxxx
    return std::regex_match(phoneNumber, std::regex("05\\d{9}"));
}

bool Person::isValidGender(char gender) {
    // Check if gender is either 'F' or 'M'
    return (gender == 'F' || gender == 'M');
}
