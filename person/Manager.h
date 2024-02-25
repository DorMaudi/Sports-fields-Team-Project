//
// Created by Roei on 16/02/2024.
//

#ifndef SPORTS_FIELDS_TEAM_PROJECT_MANAGER_H
#define SPORTS_FIELDS_TEAM_PROJECT_MANAGER_H

#include "Person.h"
#include <vector> // make its in arr
#include "date.h"

class Manager : public Person {
private:
    date* B_date;

    //std::vector<std::vector<std::string>> orders; // Array of orders (pitches with player names by date-time)

public:
    Manager(std::string &id, std::string &password, std::string &firstName, std::string &lastName, std::string &phoneNumber, char gender, date* B_date);
    ~Manager() { delete B_date; }

    void setBirthday(int day, int month, int year) { this->B_date = new date(day, month, year); }

    date* getBirthday() const { return B_date; }
/*void addOrder(const std::vector<std::string> &feildOrder);  //Look at the format string may be changed to fields and time
    void displayOrders();*/
    /*void addOrder(const std::vector<std::string> &feildOrder);  //Look at the format string may be changed to fields and time
    void displayOrders();*/
};

#endif //SPORTS_FIELDS_TEAM_PROJECT_MANAGER_H
