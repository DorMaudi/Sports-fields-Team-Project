//
// Created by Roei on 16/02/2024.
//

#ifndef SPORTS_FIELDS_TEAM_PROJECT_MANAGER_H
#define SPORTS_FIELDS_TEAM_PROJECT_MANAGER_H
#include "Person.h"
#include "vector" // make its in arr

class Manager : public Person {
private:
    std::vector<std::vector<std::string>> orders; // Array of orders (pitches with player names by date-time)
public:
    Manager(const std::string &id, const std::string &password, const std::string &firstName, const std::string &lastName,
            const std::string &phoneNumber, char gender) : Person(id, password, firstName, lastName, phoneNumber, gender) {}

    void addOrder(const std::vector<std::string> &feildOrder);  //Look at the format string may be change to feilds and time
    void displayOrders();
};

#endif //SPORTS_FIELDS_TEAM_PROJECT_MANAGER_H
