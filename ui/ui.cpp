//
// Created by USER on 20/02/2024.
//
#include "db.h"
#include "ui.h"

int ui::welcomeScreen()
{
    system("cls");
    setColor(C_PURPLE);
    std::cout << "Welcome To Sport Fields Reservation System\n";
    int input = 0;
    while(input != 1 && input != 2)
    {
        setColor(C_WHITE);
        std::cout << "Registration \\ Login\nFor registration ";
        setColor(C_BLUE);
        std::cout << "enter 1.\n";
        setColor(C_WHITE);
        std::cout << "For login ";
        setColor(C_BLUE);
        std::cout << "enter 2.\n";
        std::cin >> input;
        if(input != 1 && input != 2)
        {
            setColor(C_RED);
            std::cout << "invalid value\n";
        }
    }
    setColor(C_WHITE);
    return input;
}

int ui::registration()
{
    system("cls");
    setColor(C_PURPLE);
    std::cout << "Registration:\n";
   int input = 0;
   while(input != 1 && input != 2)
   {
       setColor(C_WHITE);
       std::cout << "For manager registration ";
       setColor(C_BLUE);
       std::cout << "enter 1.\n";
       setColor(C_WHITE);
       std::cout << "For player registration ";
       setColor(C_BLUE);
       std::cout << "enter 2.\n";
       std::cin >> input;
       if(input != 1 && input != 2)
       {
           setColor(C_RED);
           std::cout << "invalid value\n";
       }
   }
    setColor(C_WHITE);
    return input;
}

void ui::registrationProcess(int type)
{
    system("cls");
    setColor(C_PURPLE);
    std::cout << "Welcome to the registration process, please enter the following fields to make an account:\n";
    std::string e;
    std::string id;
    bool flag = false;
    while(!flag)
    {
        setColor(C_WHITE);
        std::cout << "Enter ID (";
        setColor(C_BLUE);
        std::cout <<"unique, alphanumeric, minimum 9 characters";
        setColor(C_WHITE);
        std::cout << "):\n";
        std::cin >> id;
        flag = Auth::idAuth(e,id);
        if(!flag)
        {
            setColor(C_RED);
            std::cout << e <<'\n';
        }
    }

    flag = false;
    std::string password;
    while(!flag)
    {
        setColor(C_WHITE);
        std::cout << "Enter password (";
        setColor(C_BLUE);
        std::cout << "minimum 8 characters with no space";
        setColor(C_WHITE);
        std::cout << "):\n";
        std::cin >> password;
        flag = Auth::passwordAuth(e,password);
        if(!flag)
        {
            setColor(C_RED);
            std::cout << e << '\n';
        }
    }

    flag = false;
    std::string fName;
    while(!flag)
    {
        setColor(C_WHITE);
        std::cout << "Enter first name (";
        setColor(C_BLUE);
        std::cout << "alphabetical characters only";
        setColor(C_WHITE);
        std::cout << "):\n";
        std::cin >> fName;
        flag = Auth::firstNameAuth(e,fName);
        if(!flag)
        {
            setColor(C_RED);
            std::cout << e << '\n';
        }
    }

    flag = false;
    std::string lName;
    while(!flag)
    {
        setColor(C_WHITE);
        std::cout << "Enter last name (";
        setColor(C_BLUE);
        std::cout << "alphabetical characters only";
        setColor(C_WHITE);
        std::cout << "):\n";
        std::cin >> lName;
        flag = Auth::lastNameAuth(e,lName);
        if(!flag)
        {
            setColor(C_RED);
            std::cout << e << '\n';
        }
    }

    flag = false;
    std::string pNumber;
    while(!flag)
    {
        setColor(C_WHITE);
        std::cout << "Enter phone number (";
        setColor(C_BLUE);
        std::cout << "valid phone number format 05XXXXXXXX";
        setColor(C_WHITE);
        std::cout << "):\n";
        std::cin >> pNumber;
        flag = Auth::phonenumberAuth(e,pNumber);
        if(!flag)
        {
            setColor(C_RED);
            std::cout << e << '\n';
        }
    }

    flag = false;
    char gender;
    while(!flag)
    {
        setColor(C_WHITE);
        std::cout << "Enter gender (";
        setColor(C_BLUE);
        std::cout << "only one upper case character 'F' or 'M'";
        setColor(C_WHITE);
        std::cout << "):\n";
        std::cin >> gender;
        flag = Auth::genderAuth(e, gender);
        if(!flag)
        {
            setColor(C_RED);
            std::cout << e << '\n';
        }
    }

    if(type == 1)
    {
        flag = false;
        int day, month, year;
        while(!flag)
        {
            setColor(C_WHITE);
            std::cout << "Enter birth day:\nEnter day (";
            setColor(C_BLUE);
            std::cout << "1-31";
            setColor(C_WHITE);
            std::cout << "):\n";
            std::cin >> day;
            std::cout << "Enter month (";
            setColor(C_BLUE);
            std::cout << "1-12";
            setColor(C_WHITE);
            std::cout << "):\n";
            std::cin >> month;
            std::cout << "Enter year (";
            setColor(C_BLUE);
            std::cout << "1900 - 2006";
            setColor(C_WHITE);
            std::cout << "):\n";
            flag = Auth::dateAuth(e, day, month, year);
            if(!flag)
            {
                setColor(C_RED);
                std::cout << e << '\n';
            }
        }
    }
    system("cls");
    if(type == 1)
    {
        setColor(C_GREEN);
        std::cout << "Manager created successfully!\n";
    }
    else
    {
        setColor(C_GREEN);
        std::cout << "Player created successfully!\n";
    }

    // לשלוח לפונקציה שדור יכין את נתוני ההרשמה של המשתמש לממסד הנתונים
}

std::string ui::login()
{
    system("cls");
    setColor(C_PURPLE);
    std::cout << "To login you need to enter ID and password:\n";\
    while(true)
    {
        std::string id;
        std::string pass;
        std::string msg;

        setColor(C_WHITE);
        std::cout << "Enter your ID:\n";
        std::cin >> id;

        std::cout << "Enter your password:\n;";
        std::cin >> pass;

//        if (!Auth::login(id, pass, msg, db))
//        {
//            setColor(C_RED);
//            std::cout << msg; //bad input.
//            continue;
//        }
//        else
//        {
//            setColor(C_GREEN);
//            std::cout << msg; //successfully login.
//            return id;
//        }
    }
}

void ui::playerPanel()
{
    system("cls");
    setColor(C_PURPLE);
    std::cout << "WELCOME " << "name\n"; //להוסיף את שם המשתמש מממסד הנתונים
    int option = 0;
    while(option < 1 || option > 4)
    {
        setColor(C_L_BLUE);
        std::cout << "Menu:\n";
        setColor(C_WHITE);
        std::cout << "Book field -";
        setColor(C_BLUE);
        std::cout << "enter 1.\n";
        setColor(C_WHITE);
        std::cout << "Cancel field -";
        setColor(C_BLUE);
        std::cout << "enter 2.\n";
        setColor(C_WHITE);
        std::cout << "Calendar -";
        setColor(C_BLUE);
        std::cout << "enter 3.\n";
        setColor(C_WHITE);
        std::cout << "Edit profile -";
        setColor(C_BLUE);
        std::cout << "enter 4.\n";
        std::cin >> option;
        if(option < 1 || option > 4)
        {
            setColor(C_RED);
            std::cout << "invalid value\n";
        }
    }
    setColor(C_WHITE);
    enum menuOptions {bookFieldOption = 1, cancelFieldOption, calendarOption, editProfileOption};

    switch (option)
    {
        case bookFieldOption:
        {
            break;
        }
        case cancelFieldOption:
        {
            break;
        }
        case calendarOption:
        {
            break;
        }
        case editProfileOption:
        {
            editProfile();
            break;
        }
    }
}

// להמשיך מהצגת רשימת המשחקים המתאימים לבחירתי
void ui::bookField()
{
    system("cls");
    setColor(C_PURPLE);
    std::cout << "Book Field:\n";
    int sportOption = 0;
    while(sportOption < 1 || sportOption > 4)
    {
        setColor(C_WHITE);
        std::cout << "Please choose a specific sport from this list-\nFor soccer - ";
        setColor(C_BLUE);
        std::cout << "enter 1.\n";
        setColor(C_WHITE);
        std::cout << "For Basketball - ";
        setColor(C_BLUE);
        std::cout << "enter 2.\n";
        setColor(C_WHITE);
        std::cout << "For tennis - ";
        setColor(C_BLUE);
        std::cout << "enter 3.\n";
        setColor(C_WHITE);
        std::cout << "For football - ";
        setColor(C_BLUE);
        std::cout << "enter 4.\n";
        std::cin >> sportOption;
        if(sportOption < 1 || sportOption > 4)
        {
            setColor(C_RED);
            std::cout << "invalid value\n";
        }
    }

    int cityOption = 0;
    while(cityOption < 1 || cityOption > 4)
    {

        setColor(C_WHITE);
        std::cout << "Please choose a city to play in-\nFor Ashdod - ";
        setColor(C_BLUE);
        std::cout << "enter 1.\n";
        setColor(C_WHITE);
        std::cout << "For Tel Aviv - ";
        setColor(C_BLUE);
        std::cout << "enter 2.\n";
        setColor(C_WHITE);
        std::cout << "For Jerusalem - ";
        setColor(C_BLUE);
        std::cout << "enter 3.\n";
        setColor(C_WHITE);
        std::cout << "For Eilat - ";
        setColor(C_BLUE);
        std::cout << "enter 4.\n";
        std::cin >> cityOption;
        if(cityOption < 1 || cityOption > 4)
        {
            setColor(C_RED);
            std::cout << "invalid value\n";
        }
    }
    setColor(C_WHITE);

    //הצגת רשימת ממוספרת של המגרשים המתאימים
    //שחקן צריך לבחור את המגרש שבו הוא מעוניין
    //הצגת לוח שנה ממוספר של השבוע הקרוב אותו מגרש שנבחר. שעות תפוסות וגם פנויות
    //שחקן צריך לבחור מתוך לוח שנה זה את הזמן המתאים למשחק

}

void ui::cancelField()
{
    system("cls");
    setColor(C_PURPLE);
    std::cout << "Cancel Field:\n";
    setColor(C_L_BLUE);
    std::cout << "My Reservation:\n";
    setColor(C_WHITE);

    //רשימה ממוספרת של כל ההזמנות של השחקן


    std::cout << "To cancel field enter his number option:\n";

    //מחיקת הזמנה מרשימת ההזמנות שלי
    setColor(C_GREEN);
    std::cout << "The cancellation was successfully.\n";

}

void ui::calendar()
{
    system("cls");
    setColor(C_PURPLE);
    std::cout << "Calendar:\n";
    setColor(C_L_BLUE);
    std::cout << "My Schedule:\n";

    setColor(C_WHITE);
    //רשימת\פןרמט לוח שנה של ההזמנות של השחקן עבור השבוע הקרוב בסדר כרונולוגי.
    //מירקור ההמשחק הקרוב
}

void ui::editProfile()
{
    system("cls");
    setColor(C_PURPLE);
    std::cout << "Edit Your Profile:\n";
    int editOption = 0;

    while(editOption < 1 || editOption > 4)
    {
        setColor(C_WHITE);
        std::cout << "To edit your password - ";
        setColor(C_BLUE);
        std::cout << "enter 1.\n";
        setColor(C_WHITE);
        std::cout << "To edit your first name - ";
        setColor(C_BLUE);
        std::cout << "enter 2.\n";
        setColor(C_WHITE);
        std::cout << "To edit your last name - ";
        setColor(C_BLUE);
        std::cout << "enter 3.\n";
        setColor(C_WHITE);
        std::cout << "To edit your phone number - ";
        setColor(C_BLUE);
        std::cout << "enter 4.\n";
        setColor(C_WHITE);
        std::cout << "To edit your gender - ";
        setColor(C_BLUE);
        std::cout << "enter 5.\n";
        std::cin >> editOption;

        if(editOption < 1 || editOption > 4)
        {
            setColor(C_RED);
            std::cout << "invalid value\n";
        }
    }

    enum editOptions {passwordOption = 1, firstNameOption, lastNameOption, phoneNumberOption, genderOption};

    bool flag = false;
    std::string e;
    switch (editOption)
    {
        case passwordOption:
        {
            std::string password;
            while(!flag)
            {
                setColor(C_WHITE);
                std::cout << "Enter password (";
                setColor(C_BLUE);
                std::cout << "minimum 8 characters with no space";
                setColor(C_WHITE);
                std::cout << "):\n";
                std::cin >> password;
                flag = Auth::passwordAuth(e,password);
                if(!flag)
                {
                    setColor(C_RED);
                    std::cout << e << '\n';
                }
            }
            break;
        }
        case firstNameOption:
        {
            flag = false;
            std::string fName;
            while(!flag)
            {
                setColor(C_WHITE);
                std::cout << "Enter first name (";
                setColor(C_BLUE);
                std::cout << "alphabetical characters only";
                setColor(C_WHITE);
                std::cout << "):\n";
                std::cin >> fName;
                flag = Auth::firstNameAuth(e,fName);
                if(!flag)
                {
                    setColor(C_RED);
                    std::cout << e << '\n';
                }
            }
            break;
        }
        case lastNameOption:
        {
            flag = false;
            std::string lName;
            while(!flag)
            {
                setColor(C_WHITE);
                std::cout << "Enter last name (";
                setColor(C_BLUE);
                std::cout << "alphabetical characters only";
                setColor(C_WHITE);
                std::cout << "):\n";
                std::cin >> lName;
                flag = Auth::lastNameAuth(e,lName);
                if(!flag)
                {
                    setColor(C_RED);
                    std::cout << e << '\n';
                }
            }
            break;
        }
        case phoneNumberOption:
        {
            flag = false;
            std::string pNumber;
            while(!flag)
            {
                setColor(C_WHITE);
                std::cout << "Enter phone number (";
                setColor(C_BLUE);
                std::cout << "valid phone number format 05XXXXXXXX";
                setColor(C_WHITE);
                std::cout << "):\n";
                std::cin >> pNumber;
                flag = Auth::phonenumberAuth(e,pNumber);
                if(!flag)
                {
                    setColor(C_RED);
                    std::cout << e << '\n';
                }
            }
            break;
        }
        case genderOption:
        {
            flag = false;
            char gender;
            while(!flag)
            {
                setColor(C_WHITE);
                std::cout << "Enter gender (";
                setColor(C_BLUE);
                std::cout << "only one upper case character 'F' or 'M'";
                setColor(C_WHITE);
                std::cout << "):\n";
                std::cin >> gender;
                flag = Auth::genderAuth(e, gender);
                if(!flag)
                {
                    setColor(C_RED);
                    std::cout << e << '\n';
                }
            }
            break;
        }
    }
}
