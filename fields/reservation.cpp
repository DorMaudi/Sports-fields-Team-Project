//
// Created by User on 21/02/2024.
//

#include "reservation.h"

reservation::reservation(const std::string& ID_player_, const std::string& fieldName_, const std::string& reservationDate,
                         const std::string& reservationTime, int day, int month, int year)
                         : date(day, month, year)
                         {}

const std::string &reservation::getIdPlayer() const {
    return ID_player;
}

const std::string &reservation::getFieldName() const {
    return fieldName;
}


const std::string &reservation::getTime() const {
    return time;
}

void reservation::setIdPlayer(const std::string &idPlayer) {
    ID_player = idPlayer;
}

void reservation::setFieldName(const std::string &fieldName) {
    reservation::fieldName = fieldName;
}


void reservation::setTime(const std::string &time) {
    reservation::time = time;
}

