//
// Created by Roei on 18/02/2024.
//

#ifndef CACHE_V2_7B015D1F02F4C813C2DA_JSON_PERSON_H
#define CACHE_V2_7B015D1F02F4C813C2DA_JSON_PERSON_H

// Player.h
#include <string>
#include <iostream>

class Person {
protected:
    std::string ID;
    std::string password;
    std::string f_name;
    std::string l_name;
    int phoneNumber;
    char gender;
public:
    Person(std::string ID, std::string password, std::string firstName, std::string lastName,
           int phoneNumber, char gender);
    // Get
    std::string getID() const;
    std::string getPassword() const;
    std::string getFirstName() const;
    std::string getLastName() const;
    int getPhoneNumber() const;
    char getGender() const;

    // Set
    void setID(const std::string& ID);
    void setPassword(const std::string& password);
    void setFirstName(const std::string& firstName);
    void setLastName(const std::string& lastName);
    void setPhoneNumber(int& phoneNumber);
    void setGender(char gender);

    // check functions
    bool isValidID(const std::string& ID);
    bool isValidPassword(const std::string& password);
    bool isValidPhoneNumber(const int& phoneNumber);
    bool isValidGender(char gender);
};


#endif //SPORTS_FIELDS_TEAM_PROJECT_PLAYERS_H
