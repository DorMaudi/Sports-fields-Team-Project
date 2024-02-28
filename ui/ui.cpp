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
        setColor(C_L_BLUE);
        std::cout << "Registration \\ Login\n";
        setColor(C_WHITE);
        std::cout << "For registration - ";
        setColor(C_BLUE);
        std::cout << "enter 1.\n";
        setColor(C_WHITE);
        std::cout << "For login - ";
        setColor(C_BLUE);
        std::cout << "enter 2.\n";
        std::cin >> input;
        if(input != 1 && input != 2)
        {
            setColor(C_RED);
            std::cout << "invalid value!\n";
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
       std::cout << "For manager registration - ";
       setColor(C_BLUE);
       std::cout << "enter 1.\n";
       setColor(C_WHITE);
       std::cout << "For player registration - ";
       setColor(C_BLUE);
       std::cout << "enter 2.\n";
       std::cin >> input;
       if(input != 1 && input != 2)
       {
           setColor(C_RED);
           std::cout << "invalid value!\n";
       }
   }
    setColor(C_WHITE);
    return input;
}

void ui::registrationProcess(int type, db& db)
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
        flag = Auth::idAuth(e,id,db);
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
        flag = Auth::phoneNumberAuth(e,pNumber);
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

    int day, month, year;
    if(type == 1)
    {
        flag = false;
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
        db.dbMakeUser(DB_USER_TYPE_MANGER, id, password, fName, lName, pNumber, gender, day, month, year);
        setColor(C_GREEN);
        std::cout << "Manager created successfully!\n";
    }
    else
    {
        db.dbMakeUser(DB_USER_TYPE_PLAYER, id, password, fName, lName, pNumber, gender);
        setColor(C_GREEN);
        std::cout << "Player created successfully!\n";
    }
}

std::string ui::login(db& db)
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

        if (!Auth::login(id, pass, msg, db))
        {
            setColor(C_RED);
            std::cout << msg; //bad input.
            continue;
        }
        else
        {
            setColor(C_GREEN);
            std::cout << msg; //successfully login.
            return id;
        }
    }
}

void ui::playerPanel(db& db, std::string& id)
{
    auto user = db.startSession(id);
    system("cls");
    setColor(C_WHITE);
    std::cout << "WELCOME ";
    setColor(C_PURPLE);
    std::cout << user->getFirstName() << '\n';
    int option = 0;
    while(option < 1 || option > 5)
    {
        setColor(C_L_BLUE);
        std::cout << "Player Menu:\n";
        setColor(C_WHITE);
        std::cout << "Book field - ";
        setColor(C_BLUE);
        std::cout << "enter 1.\n";
        setColor(C_WHITE);
        std::cout << "Cancel reservation - ";
        setColor(C_BLUE);
        std::cout << "enter 2.\n";
        setColor(C_WHITE);
        std::cout << "Calendar - ";
        setColor(C_BLUE);
        std::cout << "enter 3.\n";
        setColor(C_WHITE);
        std::cout << "Edit profile - ";
        setColor(C_BLUE);
        std::cout << "enter 4.\n";
        setColor(C_WHITE);
        std::cout << "EXIT - ";
        setColor(C_BLUE);
        std::cout << "enter 5.\n";
        std::cin >> option;

        if(option < 1 || option > 5)
        {
            setColor(C_RED);
            std::cout << "invalid value\n";
        }
    }
    setColor(C_WHITE);
    enum menuOptions {bookFieldOption = 1, cancelReservationOption, calendarOption, editProfileOption, exitProgram};

    switch (option)
    {
        case bookFieldOption:
        {
            bookField(db, id);
            break;
        }
        case cancelReservationOption:
        {
            cancelReservation(db, id);
            break;
        }
        case calendarOption:
        {
            //////////////////////////////////////////////////////////////////////////////////////////////////////
            break;
        }
        case editProfileOption:
        {
            editProfile(db, id);
            break;
        }
        case exitProgram:
        {
            ///////////////////////////////////////////////////////////לוודא שאחרי שהמשתמש בוחר לצאת הוא חוזר לפונקציית ההתחלהwelcome screen
            break;
        }
    }
}

void ui::bookField(db& db, std::string& id)
{
    system("cls");
    setColor(C_PURPLE);
    std::cout << "Book Field:\n";
    std::string citySelector;
    std::string gameSelector;
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

        enum sports {soccer = 1,basketBall , tennis, footBall};
        switch (sportOption)
        {
            case soccer:
            {
                gameSelector = "Soccer";
                break;
            }
            case basketBall:
            {
                gameSelector = "BasketBall";
                break;
            }
            case tennis:
            {
                gameSelector = "Tennis";
                break;
            }
            case footBall:
            {
                gameSelector = "FootBall";
                break;
            }
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

        enum cities {Ashdod = 1,TelAviv , Jerusalem, Eilat};
        switch (sportOption)
        {
            case Ashdod:
            {
                gameSelector = "Ashdod";
                break;
            }
            case TelAviv:
            {
                gameSelector = "TelAviv";
                break;
            }
            case Jerusalem:
            {
                gameSelector = "Jerusalem";
                break;
            }
            case Eilat:
            {
                gameSelector = "Eilat";
                break;
            }
        }
    }
    setColor(C_WHITE);

    std::vector<int> possibleIndex;

    for (int i = 0; i < db.getNumOfFields(); ++i) {
        if (db.getFieldArr()[i]->getCity() == citySelector && db.getFieldArr()[i]->getSportType() == gameSelector)
        {
            possibleIndex.push_back(i+1);
            setColor(C_WHITE);
            std::cout <<"For " << db.getFieldArr()[i]->getName() << "- ";
            setColor(C_BLUE);
            std::cout << "enter " << i + 1 << '.' << '\n';
        }
    }
    setColor(C_WHITE);
    int selectedOption = 0;
    bool validValue = true;
    bool flag = false;
    while(!flag)
    {
        std::cin >> selectedOption;

        for (int i : possibleIndex)
        {
            if(possibleIndex[i] != selectedOption)
            {
                setColor(C_RED);
                std::cout << "invalid value\n";
                validValue = false;
                break;
            }
        }
        if (!validValue)
        {
            std::cout << "Select a valid value: \n";
            continue;
        }
        flag = true;
    }



    //להציג i-1 בהדפסה
    //הצגת לוח שנה ממוספר של השבוע הקרוב אותו מגרש שנבחר. שעות תפוסות וגם פנויות
    //שחקן צריך לבחור מתוך לוח שנה זה את הזמן המתאים למשחק

}

void ui::cancelReservation(db& db, std::string& id)
{
    system("cls");
    setColor(C_PURPLE);
    std::cout << "Cancel Field:\n";
    setColor(C_L_BLUE);
    std::cout << "My Reservations:\n";
    setColor(C_WHITE);

    int zIndex = 0;
    std::vector<int> possibleIndex;
    for(int i = 0; i < db.getNumOfReservations(); ++i)
    {
        if (db.getReservationArr()[i]->getIdPlayer() == id)
        {
            ++zIndex;
            possibleIndex.push_back(i + 1);
            std::cout << zIndex <<". Field name: ";
            setColor(C_YELLOW);
            std::cout << db.getReservationArr()[i]->getFieldName();
            setColor(C_WHITE);
            std::cout << " Date: ";
            setColor(C_YELLOW);
            std::cout << db.getReservationArr()[i]->getDate().getDay() << '/'
                        << db.getReservationArr()[i]->getDate().getMonth() << '/' << db.getReservationArr()[i]->getDate().getYear();
            setColor(C_WHITE);
            std::cout << " Time: ";
            setColor(C_YELLOW);
            std::cout << db.getReservationArr()[i]->getTime() << '\n';
            setColor(C_WHITE);
        }
    }

    int userOption = 0;
    bool validValue = true;
    bool flag = false;
    std::cout << "To cancel field enter his number option:\n";
    while(!flag)
    {
        std::cin >> userOption;

        for (int i : possibleIndex)
        {
            if(possibleIndex[i] != userOption)
            {
                setColor(C_RED);
                std::cout << "invalid value\n";
                validValue = false;
                break;
            }
        }
        if (!validValue)
        {
            std::cout << "Select a valid value: \n";
            continue;
        }
        flag = true;
    }

    std::string tempFieldName = db.getReservationArr()[zIndex - 1]->getFieldName();
    std::string tempTime = db.getReservationArr()[zIndex - 1]->getTime();

    db.dbDelReservation(id, tempFieldName, tempTime);
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

void ui::editProfile(db& db, std::string& id)
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

        if(editOption < 1 || editOption > 5)
        {
            setColor(C_RED);
            std::cout << "invalid value\n";
        }
    }

    enum editOptions {passwordOption = 1, firstNameOption, lastNameOption, phoneNumberOption, genderOption};

    bool flag = false;
    std::string e;

    auto p = db.startSession(id);
    std::string password = p->getPassword();
    std::string fName = p->getFirstName();
    std::string lName = p->getLastName();
    std::string pNumber = p->getPhoneNumber();
    char gender = p->getGender();

    switch (editOption)
    {
        case passwordOption:
        {
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
            while(!flag)
            {
                setColor(C_WHITE);
                std::cout << "Enter phone number (";
                setColor(C_BLUE);
                std::cout << "valid phone number format 05XXXXXXXX";
                setColor(C_WHITE);
                std::cout << "):\n";
                std::cin >> pNumber;
                flag = Auth::phoneNumberAuth(e,pNumber);
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
    db.dbDelUser(id);
    db.dbMakeUser(DB_USER_TYPE_PLAYER, id, password, fName, lName, pNumber, gender);

    setColor(C_GREEN);
    std::cout << "Updated private information successfully!\n";
}

void ui::managerPanel(db& db, std::string& id)
{
    auto manager = db.startSession(id);
    system("cls");
    setColor(C_WHITE);
    std::cout << "WELCOME ";
    setColor(C_PURPLE);
    std::cout << manager->getFirstName() << '\n';
    int option = 0;
    while(option < 1 || option > 6)
    {
        setColor(C_L_BLUE);
        std::cout << "Manager Menu:\n";
        setColor(C_WHITE);
        std::cout << "List of scheduled games - ";
        setColor(C_BLUE);
        std::cout << "enter 1.\n";
        setColor(C_WHITE);
        std::cout << "Mark dates as unavailable - ";
        setColor(C_BLUE);
        std::cout << "enter 2.\n";
        setColor(C_WHITE);
        std::cout << "Add field - ";
        setColor(C_BLUE);
        std::cout << "enter 3.\n";
        setColor(C_WHITE);
        std::cout << "Delete field - ";
        setColor(C_BLUE);
        std::cout << "enter 4.\n";
        setColor(C_WHITE);
        std::cout << "Edit profile - ";
        setColor(C_BLUE);
        std::cout << "enter 5.\n";
        setColor(C_WHITE);
        std::cout << "EXIT - ";
        setColor(C_BLUE);
        std::cout << "enter 6.";
        std::cin >> option;

        if(option < 1 || option > 6)
        {
            setColor(C_RED);
            std::cout << "invalid value\n";
        }
    }
    setColor(C_WHITE);
    enum menuOptions {ScheduledGames = 1, markDatesAsUnavailable, addField, deleteField, editProfileOption, exitProgram};
    int selectedOption = 0;
    int indexOption = 0;
    switch (option)
    {
        case ScheduledGames:
        {
            listOfScheduledGames(db, id);
            break;
        }
        case markDatesAsUnavailable:
        {
            break;
        }
        case addField:
        {
            break;
        }
        case deleteField:
        {
            break;
        }
        case editProfileOption:
        {
            editProfile(db,id);
            break;
        }
        case exitProgram:
        {
            ///////////////////////////////////////////////////////////לוודא שאחרי שהמשתמש בוחר לצאת הוא חוזר לפונקציית ההתחלהwelcome screen
            break;
        }
    }
}

void ui::listOfScheduledGames(db &db, std::string &id)
{

    int selectedOption = 0;
    int indexOption = 0;

    setColor(C_WHITE);
    std::cout << "For list of scheduled games of specific field - ";
    setColor(C_BLUE);
    std::cout << "enter 1.\n";
    setColor(C_WHITE);
    std::cout << "For list of scheduled games of specific date - ";
    setColor(C_BLUE);
    std::cout << "enter 2.\n";

    while (selectedOption != 1 && selectedOption != 2)
    {
        std::cin >> selectedOption;

        if(selectedOption != 1 && selectedOption != 2)
        {
            setColor(C_RED);
            std::cout << "invalid value\n";
            setColor(C_WHITE);
            std::cout << "enter a valid value (1 or 2):\n";
        }

    }

    std::vector<int> vec;
    if(selectedOption == 1)
    {
        int k = 0;
        for(int i = 0; i < db.getNumOfFields(); ++i)
        {
            if(db.getFieldArr()[i]->getOwnerId() == id)
            {
                vec.push_back(i);
                std::cout << k + 1 << ". " << db.getFieldArr()[i]->getName();
                ++k;
            }
        }

        while(indexOption < 1 || indexOption > k + 1)
        {
            setColor(C_WHITE);
            std::cout << "enter a number option from the list:\n";
            std::cin >> indexOption;

            if(indexOption < 1 || indexOption > k + 1)
            {
                setColor(C_RED);
                std::cout << "invalid value\n";
            }
        }

        int i, j;
        int n = (int)vec.size();
        bool swapped;
        for (i = 0; i < n - 1; i++)
        {
            swapped = false;
            for (j = 0; j < n - i - 1; j++)
            {
                if (db.getReservationArr()[vec[j]]->getDate().getYear() >= db.getReservationArr()[vec[j+1]]->getDate().getYear())
                    if (db.getReservationArr()[vec[j]]->getDate().getMonth() >= db.getReservationArr()[vec[j+1]]->getDate().getMonth())
                        if (db.getReservationArr()[vec[j]]->getDate().getDay() >= db.getReservationArr()[vec[j+1]]->getDate().getDay())
                            if (std::stoi(db.getReservationArr()[vec[j]]->getTime()) > std::stoi(db.getReservationArr()[vec[j+1]]->getTime()))
                            {
                                std::swap(vec[j], vec[j + 1]);
                                swapped = true;
                            }
            }
            // If no two elements were swapped
            // by inner loop, then break
            if (swapped == false)
                break;
        }

        std::string selectedField = db.getFieldArr()[vec[indexOption-1]]->getName();

        for(auto u : vec)
        {
            setColor(C_WHITE);
            std::cout << "Date: ";
            setColor(C_YELLOW);
            std::cout << db.getReservationArr()[u]->getDate().getDay() << '/' << db.getReservationArr()[u]->getDate().getMonth() << '/' << db.getReservationArr()[u]->getDate().getYear() << ' ';
            setColor(C_WHITE);
            std::cout << "Time: ";
            setColor(C_YELLOW);
            std::cout << db.getReservationArr()[u]->getTime() << ":00\n";
        }
    }
    else
    {
        bool valid = false;
        int d, m, y;
        while(!valid)
        {
            std::string e;
            setColor(C_WHITE);
            std::cout << "enter day: (1-31)\n";
            std::cin >> d;
            std::cout << "enter month: (1-12)\n";
            std::cin >> m;
            std::cout << "enter year: (>=1900)\n";
            std::cin >> y;

            valid = Auth::dateAuth(e, d, m, y);
            if(!valid)
            {
                std::cout << e << '\n';
            }
        }

        std::vector<int> validFieldIndex;
        std::vector<int> validResIndex;

        for (int i = 0; i < db.getNumOfFields(); ++i)
        {
            if (db.getFieldArr()[i]->getOwnerId() == id)
                validFieldIndex.push_back(i);
        }

        for (auto i : validFieldIndex)
        {
            for (int j = 0; j < db.getNumOfReservations(); ++j)
            {
                if (db.getFieldArr()[i]->getName() == db.getReservationArr()[j]->getFieldName())
                    if (db.getReservationArr()[j]->getDate().getDay() == d && db.getReservationArr()[j]->getDate().getMonth() == m && db.getReservationArr()[j]->getDate().getYear() == y)
                        validResIndex.push_back(j);
            }
        }

        int i, j;
        int n = (int)validResIndex.size();
        bool swapped;
        for (i = 0; i < n - 1; i++)
        {
            swapped = false;
            for (j = 0; j < n - i - 1; j++)
            {
                if (std::stoi(db.getReservationArr()[validResIndex[j]]->getTime()) > std::stoi(db.getReservationArr()[validResIndex[j+1]]->getTime()))
                {
                    std::swap(validResIndex[j], validResIndex[j + 1]);
                    swapped = true;
                }
            }
            // If no two elements were swapped
            // by inner loop, then break
            if (swapped == false)
                break;
        }

        int index = 0;
        for(int k : validResIndex)
        {
            setColor(C_PURPLE);
            std::cout << "Scheduled Games: \n";
            setColor(C_WHITE);
            std::cout << index +1 <<". Field: ";
            setColor(C_YELLOW);
            std::cout << db.getReservationArr()[k]->getFieldName();
            setColor(C_WHITE);
            std::cout << " Date: ";
            setColor(C_YELLOW);
            std::cout << db.getReservationArr()[k]->getDate().getDay() << '/' << db.getReservationArr()[k]->getDate().getMonth()
                      << '/' << db.getReservationArr()[k]->getDate().getYear();
            setColor(C_WHITE);
            std::cout << "Time: ";
            setColor(C_YELLOW);
            std::cout << db.getReservationArr()[k]->getTime() << ":00\n";
        }
    }
}

void ui::addField(db &db, std::string &id)
{

}

void ui::deleteField(db &db, std::string &id)
{
    setColor(C_PURPLE);
    std::cout << "Delete Field:\n";
    std::vector<int> vec;
    int indexOption = 0;
    int k = 0;
    for(int i = 0; i < db.getNumOfFields(); ++i)
    {
        if(db.getFieldArr()[i]->getOwnerId() == id)
        {
            vec.push_back(i);
            std::cout << k + 1 << ". " << db.getFieldArr()[i]->getName();
            ++k;
        }
    }

    while(indexOption < 1 || indexOption > k + 1)
    {
        setColor(C_WHITE);
        std::cout << "enter a number option from the list to cancel the specific field:\n";
        std::cin >> indexOption;

        if(indexOption < 1 || indexOption > k + 1)
        {
            setColor(C_RED);
            std::cout << "invalid value\n";
        }
    }

    std::string delThisField = db.getFieldArr()[vec[indexOption - 1]]->getName();
    db.dbDelField(delThisField);
}
