//
// Created by Jacob on 2/12/2024.
//

#include "date.h"

bool date::dateAuth(int day, int month, int year, std::string& e) {
    // Basic validation for month and year (assuming Gregorian calendar)
    if (year < 1900 || year > 2006) {
        // Invalid year
        e = "invalid year.";
        return false;
    }

    if (month < 1 || month > 12) {
        // Invalid month
        e = "invalid month.";
        return false;
    }

    // Array to store the number of days in each month (assuming non-leap year)
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Adjust February for leap years (29 days)
    if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
        // Leap year
        daysInMonth[1] = 29;
    }

    // Validate the day based on the number of days in the given month
    if (day < 1 || day > daysInMonth[month - 1]) {
        // Invalid day
        e = "invalid day.";
        return false;
    }

    // Date is considered valid if it passes all validation checks
    return true;
}

date::date(int day, int month, int year)
: day(day), month(month), year(year)
{}

bool date::operator==(const date &other) const
{
    if (this->day == other.getDay() && this->month == other.getMonth() && this->year == other.getYear())
        return true;
    else
        return false;
}
