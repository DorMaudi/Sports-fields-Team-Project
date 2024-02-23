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

    date(int day, int month, int year);

    static bool dateAuth (int day, int month, int year, std::string& e);
};


#endif //SPORTS_FIELDS_TEAM_PROJECT_DATE_H
