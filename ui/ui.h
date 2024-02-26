//
// Created by USER on 20/02/2024.
//

#ifndef SPORTS_FIELDS_TEAM_PROJECT_UI_H
#define SPORTS_FIELDS_TEAM_PROJECT_UI_H

#include <iostream>
#include <string>
#include <windows.h>
#include "Auth.h"


#define C_WHITE 15
#define C_RED 12
#define C_GREEN 10
#define C_YELLOW 14
#define C_BLUE 9
#define C_PURPLE 13
#define C_L_BLUE 11

static HANDLE consoleColor = GetStdHandle(STD_OUTPUT_HANDLE);

static void setColor(int color)
{
    SetConsoleTextAttribute(consoleColor,color);
}

class ui {
public:
    static int welcomeScreen();
    static int registration();
    static void registrationProcess(int type, db& db);
    static std::string login(db& db);
    static void playerPanel(db& db, std::string& id);
    static void managerPanel(db& db, std::string& id);
    static void bookField(db& db);
    static void cancelField();
    static void calendar();
    static void editProfile();


private:

};


#endif //SPORTS_FIELDS_TEAM_PROJECT_UI_H
