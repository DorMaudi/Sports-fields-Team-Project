//
// Created by User on 21/02/2024.
//

#include "reservation.h"

#include <utility>

reservation::reservation(std::string resId, std::string idPlayer, std::string fieldName,
                         const date &resDate, std::string time) : resId(std::move(resId)), ID_player(std::move(idPlayer)),
                                                                  fieldName(std::move(fieldName)), resDate(resDate),
                                                                  time(std::move(time)) {}

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



