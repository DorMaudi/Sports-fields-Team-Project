//
// Created by Roei on 16/02/2024.
//

#include "Manager.h"

Manager::Manager(const std::string &id, const std::string &password, const std::string &firstName, const std::string &lastName,
                 const std::string &phoneNumber, char gender,const std::string B_date): Person(id, password, firstName, lastName, phoneNumber, gender){
    setBirthday(B_date);
}


void Manager::setBirthday(std::string B_date) {
    // Check if the birthday string is in the format "dd mm yyyy"
    if (B_date.length() == 10 && B_date[2] == ' ' && B_date[5] == ' ') {
        bool valid = true;
        for (int i = 0; i < 10; ++i) {
            if (i != 2 && i != 5 && !isdigit(B_date[i])) {
                valid = false;
                break;
            }
        }
        if (valid) {
            B_date = B_date;
        } else {
            std::cout << "Invalid birthday format. Please use the format 'dd mm yyyy'." << std::endl;
        }
    } else {
        std::cout << "Invalid birthday format. Please use the format 'dd mm yyyy'." << std::endl;
    }
}


std::string Manager::getBirthday() {
    return B_date;
}


/*
void Manager::addOrder(const std::vector<std::string> &feildOrder) {
    orders.push_back(feildOrder);
}

//need to check the print
void Manager::displayOrders(){
    std::cout << "Manager's Orders:" << std::endl;
    for (const auto &order : orders) {
        for (const auto &feild : order) {
            std::cout << feild << std::endl;
        }
        std::cout << "--------" << std::endl;
    }
}
*/