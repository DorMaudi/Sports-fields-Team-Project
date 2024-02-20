//
// Created by Roei on 16/02/2024.
//
// Player.cpp

#include "Players.h"

void Players::bookPitch(const std::string &feildName, const std::string &dateTime) {
std::string booking = feildName + " - " + dateTime;  //Look at the format string may be change to feilds and time
bookings.push_back(booking);
}

//also this: (Look at the format string may be change to feilds and time)
void Players::displayBookings() {
    std::cout << "Player's Bookings:" << std::endl;
    for (const auto &booking: bookings) {
        std::cout << booking <<  std::endl;
    }
}
