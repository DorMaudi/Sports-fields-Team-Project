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

void ui::managerRegistration()
{
    std::cout << "To register as a manager you need to fill 7 fields:\n";
    std::string e;
    std::string id;
    Auth a;
    bool flag = false;
    while(!flag)
    {
        std::cout << "Enter ID (unique, alphanumeric, minimum 9 characters):\n";
        std::cin >> id;
        flag = a.idAuth(e,id);
        if(!flag)
            std::cout << e <<'\n';
    }




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

    //הצגת רשימת ממוספרת של המגרשים המתאימים
    //שחקן צריך לבחור את המגרש שבו הוא מעוניין
    //הצגת לוח שנה ממוספר של השבוע הקרוב אותו מגרש שנבחר. שעות תפוסות וגם פנויות
    //שחקן צריך לבחור מתוך לוח שנה זה את הזמן המתאים למשחק

}

void ui::cancelField()
{
    std::cout << "Cancel Field:\nMy Reservation:\n";

    //רשימה ממוספרת של כל ההזמנות של השחקן


    std::cout << "To cancel field enter his number option:\n";

    //מחיקת הזמנה מרשימת ההזמנות שלי

    std::cout << "The cancellation was successfully.\n";

}

void ui::calendar()
{
    std::cout << "Calendar:\nMy Schedule:\n";

    //רשימת\פןרמט לוח שנה של ההזמנות של השחקן עבור השבוע הקרוב בסדר כרונולוגי.
    //מירקור ההמשחק הקרוב
}

void ui::editProfile()
{
    std::cout << "Edit Your Profile:\n";
    int editOption = 0;

    while(editOption < 1 || editOption > 4)
    {
        std::cout << "To edit your password - enter 1.\nTo edit your first name - enter 2.\n"
                     "To edit your last name - enter 3.\nTo edit your phone number - enter 4.\nTo edit your gender - enter 5.\n";

        std::cin >> editOption;

        if(editOption < 1 || editOption > 4)
            std::cout << "invalid value\n";
    }

    enum editOptions {pass = 1, fName, Lname, phone, gen};

    switch (editOption)
    {
        case pass:
        {
            break;
        }
        case fName:
        {
            break;
        }
        case Lname:
        {
            break;
        }
        case phone:
        {
            break;
        }
        case gen:
        {
            break;
        }
        default:
        {
            break;
        }
    }



}
