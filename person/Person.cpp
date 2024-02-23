//
// Created by dorma on 23/02/2024.
//

#include "Person.h"

Person::Person(std::string& ID, std::string& password, std::string& firstName, std::string& lastName, std::string& phoneNumber, char gender)
        : ID(std::move(ID)) , password(std::move(password)) , f_name(std::move(firstName)) , l_name(std::move(lastName)) , phoneNumber(std::move(phoneNumber)) , gender(gender)
{}