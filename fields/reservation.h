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
    std::string resId;
    std::string ID_player;
    std::string fieldName;
    date resDate;
    std::string time;

public:
    reservation(){}
    reservation(std::string resId, std::string idPlayer, std::string fieldName,
                const date &resDate, std::string time);

    const std::string &getId() const { return this->resId; }
    const std::string &getIdPlayer() const;
    const std::string &getFieldName() const;
    const std::string &getTime() const;
    const date &getDate() const { return this->resDate; }

    void setIdPlayer(const std::string &idPlayer);
    void setFieldName(const std::string &fieldName);
    void setTime(const std::string &time);


};


#endif //SPORTS_FIELDS_TEAM_PROJECT_RESERVATION_H
