//
// Created by USER on 20/02/2024.
//

#ifndef SPORTS_FIELDS_TEAM_PROJECT_UI_H
#define SPORTS_FIELDS_TEAM_PROJECT_UI_H

#include <iostream>
#include <string>
#include "Auth.h"

class ui {
public:
    static int welcomeScreen();
    static int registration();
    static bool managerRegistration();
    static bool playerRegistration();
    static std::string login();
    static void playerPanel();
    static void managerPanel();



private:

};


#endif //SPORTS_FIELDS_TEAM_PROJECT_UI_H
