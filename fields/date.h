//
// Created by User on 23/02/2024.
//

#ifndef SPORTS_FIELDS_TEAM_PROJECT_DATE_H
#define SPORTS_FIELDS_TEAM_PROJECT_DATE_H


class date {
private:
    int day;
    int month;
    int year;

public:
    // Constructor
    Date(int d, int m, int y);

    // Getters
    int getDay() const;
    int getMonth() const;
    int getYear() const;

    // Setters
    void setDay(int d);
    void setMonth(int m);
    void setYear(int y);

    // Function to check validity of the date
    bool isValidDate() const;

};


#endif //SPORTS_FIELDS_TEAM_PROJECT_DATE_H
