//
// Created by Roei on 16/02/2024.
//

#include "Manager.h"

Manager::Manager(std::string &id, std::string &password, std::string &firstName, std::string &lastName, std::string &phoneNumber, char gender, date* B_date)
: Person(id, password, firstName, lastName, phoneNumber, gender)
{}