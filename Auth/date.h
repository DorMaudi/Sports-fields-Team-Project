//
// Created by Jacob on 2/12/2024.
//

#ifndef SPORTS_FIELDS_TEAM_PROJECT_DATE_H
#define SPORTS_FIELDS_TEAM_PROJECT_DATE_H

#include <string>

class date {
private:
    int day;
    int month;
    int year;

public:

    date(){}
    date(int day, int month, int year);

    static bool dateAuth (int day, int month, int year, std::string& e);

    int getDay() const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }
};


#endif //SPORTS_FIELDS_TEAM_PROJECT_DATE_H
