//
// Created by USER on 20/02/2024.
//

#ifndef SPORTS_FIELDS_TEAM_PROJECT_UI_H
#define SPORTS_FIELDS_TEAM_PROJECT_UI_H

#include <iostream>
#include <string>
#include <windows.h>
#include <sysinfoapi.h>
#include <iomanip>
#include "Auth.h"


#define C_WHITE 15
#define C_RED 12
#define C_GREEN 10
#define C_YELLOW 14
#define C_BLUE 9
#define C_PURPLE 13
#define C_L_BLUE 11


#define DAYS_OF_WEEK 6

static HANDLE consoleColor = GetStdHandle(STD_OUTPUT_HANDLE);

static void setColor(int color)
{
    SetConsoleTextAttribute(consoleColor,color);
}

class ui {
public:
    static void mainFunction(db& db);
    static int welcomeScreen();
    static int registration();
    static void registrationProcess(int type, db& db);
    static std::string login(db& db);
    static void playerPanel(db& db, std::string& id);
    static void managerPanel(db& db, std::string& id);
    static void bookField(db& db, std::string& id);
    static void cancelReservation(db& db, std::string& id);
    static void calendar(db& db, const std::string& id);
    static void editProfile(db& db, std::string& id);
    static void listOfScheduledGames(db& db, std::string& id);
    static void addField(db& db, std::string& id);
    static void deleteField(db& db, std::string& id);
    static void markDateAsUnavailable(db& , std::string& id);
    static void makeCalender(std::vector<date>& arr);
    static void displayCalenderPlayer(std::vector<date>& dateArr, db& db, const std::string& id);
    static void displayCalenderField(std::vector<date>& dateArr, db& db, std::string& fieldName);

private:

};


#endif //SPORTS_FIELDS_TEAM_PROJECT_UI_H
