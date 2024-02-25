//
// Created by User on 21/02/2024.
//

#ifndef SPORTS_FIELDS_TEAM_PROJECT_RESERVATION_H
#define SPORTS_FIELDS_TEAM_PROJECT_RESERVATION_H

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
    reservation(const std::string& ID_player_, const std::string& fieldName_, const std::string& reservationDate,
                const std::string& reservationTime, int day, int month, int year);

    const std::string &getIdPlayer() const;
    const std::string &getFieldName() const;
    const std::string &getTime() const;

    void setIdPlayer(const std::string &idPlayer);
    void setFieldName(const std::string &fieldName);
    void setTime(const std::string &time);


};


#endif //SPORTS_FIELDS_TEAM_PROJECT_RESERVATION_H
