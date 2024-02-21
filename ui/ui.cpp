//
// Created by USER on 20/02/2024.
//
#include "db.h"
#include "ui.h"

int ui::welcomeScreen()
{
    std::cout << "Welcome To Sport Fields Reservation System\n";
    int input = 0;
    while(input != 1 && input != 2)
    {
        std::cout << "Registration \\ Login\nFor registration enter 1.\nFor login enter 2.\n";
        std::cin >> input;
        if(input != 1 && input != 2)
            std::cout << "invalid value\n";
    }
    return input;
}

int ui::registration()
{
   std::cout << "Registration:\n";
   int input = 0;
   while(input != 1 && input != 2)
   {
       std::cout << "For manager registration enter 1.\nFor player registration enter 2.\n";
       std::cin >> input;
       if(input != 1 && input != 2)
           std::cout << "invalid value\n";
   }
   return input;
}

bool ui::managerRegistration()
{
    std::cout << "To register as a manager you need to fill 7 fields:\n";
    std::cout << "Enter ID (unique, alphanumeric, minimum 9 characters):\n";

}

bool ui::playerRegistration()
{
    std::cout << "To register as a player you need to fill 6 fields:\n";
    std::cout << "Enter ID (unique, alphanumeric, minimum 9 characters):\n";
}

std::string ui::login()
{
    std::cout << "To login you need to enter ID and password:\n";\
    while(true)
    {
        std::string id;
        std::string pass;
        std::string msg;

        std::cout << "Enter your ID:\n";
        std::cin >> id;

        std::cout << "Enter your password:\n;";
        std::cin >> pass;

        if (!Auth::login(id, pass, msg, db))
        {
            std::cout << msg; //bad input.
            continue;
        }
        else
        {
            std::cout << msg; //successfully login.
            return id;
        }
    }
}

void ui::playerPanel()
{
    std::cout << "WELCOME " << "name\n"; //להוסיף את שם המשתמש מממסד הנתונים
    int option = 0;
    while(option < 1 || option > 4)
    {
        std::cout << "Menu:\nBook field - enter 1\nCancel field - enter 2\nCalendar - enter 3\nEdit profile - enter 4\n";
        std::cin >> option;
        if(option < 1 || option > 4)
            std::cout << "invalid value\n";
    }

    enum menuOptions {bookF = 1, cancelF, cal, edit};

    switch (option)
    {
        case bookF:
        {
            break;
        }
        case cancelF:
        {
            break;
        }
        case cal:
        {
            break;
        }
        case edit:
        {
            break;
        }
        default:
        {
            break;
        }
    }
}

// להמשיך מהצגת רשימת המשחקים המתאימים לבחירתי
void ui::bookField()
{
    std::cout << "Book Field:\n";
    int sportOption = 0;
    while(sportOption < 1 || sportOption > 4)
    {
        std::cout << "Please choose a specific sport from this list-\nFor soccer - enter 1.\nFor Basketball - enter 2.\n"
                     "For tennis - enter 3.\nFor football - enter 4.\n";
        std::cin >> sportOption;
        if(sportOption < 1 || sportOption > 4)
            std::cout << "invalid value\n";
    }

    int cityOption = 0;
    while(cityOption < 1 || cityOption > 4)
    {
        std::cout << "Please choose a city to play in-\nFor Ashdod - enter 1.\nFor Tel Aviv - enter 2.\n"
                     "For Jerusalem - enter 3.\nFor Eilat - enter 4.\n";
        std::cin >> cityOption;
        if(cityOption < 1 || cityOption > 4)
            std::cout << "invalid value\n";
    }
}
