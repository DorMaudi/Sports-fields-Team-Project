//
// Created by Roei on 16/02/2024.
//

#define SPORTS_FIELDS_TEAM_PROJECT_PLAYERS_H

// Player.h

#ifndef PLAYER_H
#define PLAYER_H
#include "Person.h"
#include "vector" // make its in arr

class Players : public Person {
private:
    std::vector<std::string> bookings;
public:
    Players(const std::string &id, const std::string &password, const std::string &firstName, const std::string &lastName,
           const std::string &phoneNumber, char gender) : Person(id, password, firstName, lastName, phoneNumber,gender) {}

    void bookPitch(const std::string &feildName, const std::string &dateTime); //maybe need to change "date &dateTime" instead of string
    void displayBookings();
};


#endif //SPORTS_FIELDS_TEAM_PROJECT_PLAYERS_H
