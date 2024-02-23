//
// Created by User on 23/02/2024.
//

#include "date.h"

// Constructor
Date::Date(int d, int m, int y) : day(d), month(m), year(y) {}

// Getters
int Date::getDay() const {
    return day;
}

int Date::getMonth() const {
    return month;
}

int Date::getYear() const {
    return year;
}

// Setters
void Date::setDay(int d) {
    day = d;
}

void Date::setMonth(int m) {
    month = m;
}

void Date::setYear(int y) {
    year = y;
}

// Function to check validity of the date
bool Date::isValidDate() const {
    if (day < 1 || day > 31 || month < 1 || month > 12 || year < 1900 || year > 2100)
        return false;

    // Additional validation based on leap years can be added here if needed

    return true;
}
