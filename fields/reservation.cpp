//
// Created by User on 21/02/2024.
//

#include "reservation.h"

reservation::reservation(std::string playerID, std::string field, std::string reservationDate, std::string reservationTime) {
        ID_player = playerID;
        fieldName = field;
        date = reservationDate;
        time = reservationTime;
}

const std::string &Reservation::getIdPlayer() const {
    return ID_player;
}

const std::string &Reservation::getFieldName() const {
    return fieldName;
}

const std::string &Reservation::getDate() const {
    return date;
}

const std::string &Reservation::getTime() const {
    return time;
}

void Reservation::setIdPlayer(const std::string &idPlayer) {
    this->ID_player = idPlayer;
}

void Reservation::setFieldName(const std::string &fieldName) {
    this->fieldName = fieldName;
}

void Reservation::setDate(const std::string &date) {
    if (validateDte){
        this->date = date;
    }
}

void Reservation::setTime(const std::string &time) {
    this->time = time;
}

bool validateDate(const std::string& dateStr) {
    std::tm tm = {};
    std::istringstream ss(dateStr);
    ss >> std::get_time(&tm, "%d-%m-%Y");
    if (ss.fail()) {
        return false;
    }
    std::time_t time = std::mktime(&tm);
    return time != -1;
}
