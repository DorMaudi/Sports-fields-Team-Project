
#ifndef SPORTS_FIELDS_TEAM_PROJECT_PERSON_H
#define SPORTS_FIELDS_TEAM_PROJECT_PERSON_H

#include <string>

class Person {
protected:
    std::string ID;
    std::string password;
    std::string f_name;
    std::string l_name;
    std::string phoneNumber;
    char gender;
public:
    Person(std::string& ID, std::string& password, std::string& firstName, std::string& lastName, std::string& phoneNumber, char gender) ;
    virtual int getType() const = 0;
    // Get
    std::string getID() const { return ID; }
    std::string getPassword() const { return password; }
    std::string getFirstName() const { return f_name; }
    std::string getLastName() const { return l_name; }
    std::string getPhoneNumber() const { return phoneNumber; }
    char getGender() const { return gender; }

    // Set
    void setID(const std::string& id) { this->ID = id; }
    void setPassword(const std::string& pass) { this->password = pass; }
    void setFirstName(const std::string& firstName) { this->f_name = firstName; }
    void setLastName(const std::string& lastName) { this->l_name = lastName; }
    void setPhoneNumber(const std::string& phoneNum) { this->phoneNumber = phoneNum; }
    void setGender(char gen) { this->gender = gen; }

};

#endif //SPORTS_FIELDS_TEAM_PROJECT_PERSON_H
