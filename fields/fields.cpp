//
// Created by User on 21/02/2024.
//

#include "fields.h"

fields::fields(std::string name, std::string city, std::string sportType, std::string ownerId, std::string description,
               std::string reviews, bool accessible, int counter)
               : name(std::move(name)), city(std::move(city)), sportType(std::move(sportType)), ownerId(std::move(ownerId)), description(std::move(description)), reviews(std::move(reviews)), accessible(accessible), reservationCounter(counter)
               {}


const std::string &fields::getName() const
{
    return this->name;
}

const std::string &fields::getCity() const {
    return city;
}

const std::string &fields::getSportType() const {
    return sportType;
}

const std::string &fields::getOwnerId() const {
    return ownerId;
}

const std::string &fields::getDescription() const {
    return description;
}

std::string fields::getReviews() const {
    return reviews;
}


bool fields::isAccessible() const {
    return this->accessible;
}

int fields::getReservationCounter() const {
    return this->reservationCounter;
}

void fields::setName(const std::string &name) {
    fields::name = name;
}

void fields::setCity(const std::string &city) {
        this->city = city;
}

void fields::setSportType(const std::string &sportType) {
        fields::sportType = sportType;
}

void fields::setDescription(const std::string &descriptionEdit) {
    this->description = descriptionEdit;
}

void fields::setAccessible(bool accessibleSet) {
    this->accessible = accessibleSet;
}

void fields::setCounter(int counter) {
    this->reservationCounter = counter;
}

void fields::appReview(std::string &rev)
{
    this->reviews += rev += '\n';
}

void fields::setReview(std::string &rev)
{
    this->reviews += rev;
}

void fields::fixArr(int type)
{
    if (type == 1) // for description.
    {
        this->description = '\0';
    }
    else // for reviews
    {
        this->reviews = '\0';
    }
}
