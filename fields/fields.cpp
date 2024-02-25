//
// Created by User on 21/02/2024.
//

#include "fields.h"

fields::fields(std::string name, std::string city, std::string sportType, std::string ID_manager,
               std::string description, reservation *res, std::string *reviews, int reviews_counter, bool accessible,
               int fieldsCounter) {
}

const std::string &fields::getName() const {
    return name;
}

const std::string &fields::getCity() const {
    return city;
}

const std::string &fields::getSportType() const {
    return sportType;
}

const std::string &fields::getIdManager() const {
    return ID_manager;
}

const std::string &fields::getDescription() const {
    return description;
}

reservation *fields::getRes() const {
    return res;
}

std::string *fields::getReviews() const {
    return reviews;
}

int fields::getReviewsCounter() const {
    return reviews_counter;
}

bool fields::isAccessible() const {
    return accessible;
}

int fields::getFieldsCounter() const {
    return fieldsCounter;
}

void fields::setName(const std::string &name) {
    fields::name = name;
}

void fields::setCity(const std::string &city) {
    if (city == "Ashdod" || city == "Tel-Aviv" || city == "Jerusalem" || city == "Eilat" || city == "Ashkelon") {
        this->city = city;
    }
}

void fields::setSportType(const std::string &sportType) {
    if (sportType == "Soccer" || sportType == "Basketball" || sportType == "Tennis" || sportType == "Football") {
        fields::sportType = sportType;
    }
}

void fields::setDescription(const std::string &description) {
    fields::description = description;
}

void fields::setRes(reservation *res) {
    fields::res = res;
}

void fields::setReviews(std::string *reviews) {
    this->reviews = reviews;
}

void fields::setReviewsCounter(int reviewsCounter) {
    this->reviews_counter=reviewsCounter;
}

void fields::setAccessible(bool accessible) {
    fields::accessible = accessible;
}

void fields::setFieldsCounter(int fieldsCounter) {
    fields::fieldsCounter = fieldsCounter;
}

void fields::setIdManager(const std::string &idManager) {
    ID_manager = idManager;
}
