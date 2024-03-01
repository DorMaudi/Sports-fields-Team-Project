//
// Created by dorma on 23/02/2024.
//

#ifndef SPORTS_FIELDS_TEAM_PROJECT_PLAYER_H
#define SPORTS_FIELDS_TEAM_PROJECT_PLAYER_H

#include "Person.h"
#include "vector" // make its in arr

class Player : public Person {
private:
    std::vector<std::string> bookings;
public:
    Player(std::string &id, std::string &password, std::string &firstName, std::string &lastName, std::string &phoneNumber, char gender);
    virtual int getType() const { return 1; }
};


#endif //SPORTS_FIELDS_TEAM_PROJECT_PLAYER_H
