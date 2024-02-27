//
// Created by User on 21/02/2024.
//

#include "reservation.h"

reservation::reservation(std::string id, std::string &ID_player_, std::string &fieldName_,
                         std::string &reservationTime, int day, int month, int year)
                         : resDate(day, month, year), resId(std::move(id)), ID_player(std::move(ID_player_)), fieldName(std::move(fieldName_)), time(std::move(reservationTime))
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

