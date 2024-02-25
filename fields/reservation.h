//
// Created by User on 21/02/2024.
//

#ifndef SPORTS_FIELDS_TEAM_PROJECT_RESERVATION_H
#define SPORTS_FIELDS_TEAM_PROJECT_RESERVATION_H

#include <stringh>
#include <ctime>
#include <iomanip>
#include <iostream>
#include "date.h"

class reservation {

private:
    std::string ID_player;
    std::string fieldName;
    date date;
    std::string time;

public:
    reservation(std::string playerID, std::string field, std::string reservationDate, std::string reservationTime);
    const std::string &getIdPlayer() const;
    const std::string &getFieldName() const;
    const std::string &getDate() const;
    const std::string &getTime() const

    void setIdPlayer(const std::string &idPlayer);
    void setFieldName(const std::string &fieldName);
    void setDate(const std::string &date);
    void setTime(const std::string &time);

    bool validateDate(const std::string& dateStr);

};


#endif //SPORTS_FIELDS_TEAM_PROJECT_RESERVATION_H
