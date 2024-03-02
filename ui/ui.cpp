//
// Created by USER on 20/02/2024.
//
#include "db.h"
#include "ui.h"

int ui::welcomeScreen()
{
    //system("cls");
    std::string option, error;
    int input = 0;
    bool flag = false;

    do
    {
        setColor(C_PURPLE);
        std::cout << "Welcome To Sport Fields Reservation System\n";
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
        setColor(C_WHITE);
        std::cout << "For Exit - ";
        setColor(C_BLUE);
        std::cout << "enter 3.\n";
        std::cin >> option;

        // Check if the input is a valid digit
        if (Auth::isDigit(error, option) != 1 && Auth::isDigit(error, option) != 2 && Auth::isDigit(error, option) != 3)
        {
            std::cout << error << "\n";
            flag = false;
        }
        else
        {
            flag = true;
            input = std::stoi(option);
        }
    } while (!flag);

    setColor(C_WHITE);
    return input;
}

int ui::registration()
{
    system("cls");
    setColor(C_PURPLE);
    std::cout << "Registration:\n";
    std::string option;
    int input = 0;
    bool flag = false;

    do {
        setColor(C_WHITE);
        std::cout << "For manager registration - ";
        setColor(C_BLUE);
        std::cout << "enter 1.\n";
        setColor(C_WHITE);
        std::cout << "For player registration - ";
        setColor(C_BLUE);
        std::cout << "enter 2.\n";
        std::cin >> option;

        // Clear input buffer
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        // Check if the input is a valid integer
        if (option != "1" && option != "2") {
            setColor(C_RED);
            std::cout << "Invalid input. Please enter 1 or 2.\n";
        } else {
            flag = true;
            input = std::stoi(option);
        }
    } while (!flag);

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
            while (!(std::cin >> day))
            {
                // Clear the error flag
                std::cin.clear();
                // Discard the input buffer until the end of the line
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                setColor(C_RED);
                std::cout << "Invalid input. Please try again:\n";
                setColor(C_WHITE);
            }
            std::cout << "Enter month (";
            setColor(C_BLUE);
            std::cout << "1-12";
            setColor(C_WHITE);
            std::cout << "):\n";
            while (!(std::cin >> month))
            {
                // Clear the error flag
                std::cin.clear();
                // Discard the input buffer until the end of the line
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                setColor(C_RED);
                std::cout << "Invalid input. Please try again:\n";
                setColor(C_WHITE);
            }
            std::cout << "Enter year (";
            setColor(C_BLUE);
            std::cout << "1900 - 2006";
            setColor(C_WHITE);
            std::cout << "):\n";
            while (!(std::cin >> year))
            {
                // Clear the error flag
                std::cin.clear();
                // Discard the input buffer until the end of the line
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                setColor(C_RED);
                std::cout << "Invalid input. Please try again:\n";
                setColor(C_WHITE);
            }
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

        std::cout << "Enter your password:\n";
        std::cin >> pass;
        if(!Auth::idAuth_(msg,id)){
            setColor(C_RED);
            std::cout << msg << '\n'; //bad id input
            continue;
        }
        if (!Auth::login(id, pass, msg, db))
        {
            setColor(C_RED);
            std::cout << msg << '\n'; //bad input.
            continue;
        }
        else
        {
            setColor(C_GREEN);
            std::cout << msg << '\n'; //successfully login.
            return id;
        }
    }
}

void ui::playerPanel(db& db, std::string& id)
{
    system("cls");
    auto user = db.startSession(id);
    std::string tempUid = user->getID();
    setColor(C_WHITE);
    std::cout << "WELCOME ";
    setColor(C_PURPLE);
    std::cout << user->getFirstName() << '\n';
    int option = 0;

    while (option < 1 || option > 5) {
        id = tempUid;
        setColor(C_L_BLUE);
        std::cout << "Player Menu: ";
        setColor(C_YELLOW);
        std::cout << user->getFirstName() << " {" << tempUid << "}\n";
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

        // Clear input buffer
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (option < 1 || option > 5) {
            setColor(C_RED);
            std::cout << "Invalid value. Please enter a number between 1 and 5.\n";
        }

        setColor(C_WHITE);
        enum menuOptions {
            bookFieldOption = 1, cancelReservationOption, calendarOption, editProfileOption, exitProgram
        };

        switch (option) {
            case bookFieldOption: {
                bookField(db, id);
                option = 0;
                break;
            }
            case cancelReservationOption: {
                cancelReservation(db, tempUid);
                option = 0;
                break;
            }
            case calendarOption: {
                calendar(db, tempUid);
                option = 0;
                break;
            }
            case editProfileOption: {
                editProfile(db, id);
                option = 0;
                break;
            }
            case exitProgram: {
                // Add any necessary cleanup or exit logic here
                system("cls");
                break;
            }
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
        if (sportOption > 4 || sportOption < 1) {
            setColor(C_RED);
            std::cout << "Invalid input. Please enter a number between 1 and 4.\n";
            // Clear input buffer
            fflush(stdin);
            setColor(C_WHITE);
            continue;
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
                gameSelector = "Basketball";
                break;
            }
            case tennis:
            {
                gameSelector = "Tennis";
                break;
            }
            case footBall:
            {
                gameSelector = "Football";
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
        std::cout << "For Tel-Aviv - ";
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
        if (cityOption > 4 || cityOption < 1)
        {
            setColor(C_RED);
            std::cout << "Invalid input. Please enter a number between 1 and 4.\n";
            // Clear input buffer
            fflush(stdin);
            setColor(C_WHITE);
            continue;
        }

        enum cities {Ashdod = 1,TelAviv , Jerusalem, Eilat};
        switch (cityOption)
        {
            case Ashdod:
            {
                citySelector = "Ashdod";
                break;
            }
            case TelAviv:
            {
                citySelector = "Tel-Aviv";
                break;
            }
            case Jerusalem:
            {
                citySelector = "Jerusalem";
                break;
            }
            case Eilat:
            {
                citySelector = "Eilat";
                break;
            }
        }
    }
    setColor(C_WHITE);

    int counter = 0;
    for (int i = 0; i < db.getNumOfFields(); ++i)
    {
        if (db.getFieldArr()[i]->getCity() == citySelector && db.getFieldArr()[i]->getSportType() == gameSelector)
            ++counter;
    }

    if(counter == 0)
    {
        setColor(C_RED);
        system("cls");
        std::cout << "There is no fields available.\n";
        return;
    }


    std::vector<int> possibleIndex;
    int k = 0;
    for (int i = 0; i < db.getNumOfFields(); ++i) {
        if (db.getFieldArr()[i]->getCity() == citySelector && db.getFieldArr()[i]->getSportType() == gameSelector)
        {
            possibleIndex.push_back(i);
            setColor(C_WHITE);
            std::cout <<"For " << db.getFieldArr()[i]->getName() << " - ";
            setColor(C_BLUE);
            std::cout << "enter " << k + 1 << '.' << '\n';
            ++k;
        }
    }
    if(db.getFieldArr().empty())
    {
        setColor(C_RED);
        std::cout << "There is no fields available.\n";
        return;
    }

    setColor(C_WHITE);
    std::string nameOfFieldSelected;
    int selectedOption = 0;
    bool validValue = true;
    bool flag = false;
    while(!flag)
    {
        std::cin >> selectedOption;
        nameOfFieldSelected = db.getFieldArr()[possibleIndex[selectedOption-1]]->getName();
        for (int i : possibleIndex)
        {
            if(!possibleIndex[selectedOption-1])
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

    std::vector<date> cal;
    makeCalender(cal);
    std::string selectedName = db.getFieldArr()[possibleIndex[selectedOption-1]]->getName();
    displayCalenderField(cal, db, selectedName);

    int revPick = 0;
    while (revPick != 1 && revPick != 2)
    {
        setColor(C_WHITE);
        std::cout << "If you would like to leave a review first ";
        setColor(C_BLUE);
        std::cout << "press 1.\n";
        setColor(C_WHITE);
        std::cout << "If you just want to make a reservation ";
        setColor(C_BLUE);
        std::cout << "press 2.\n";

        std::cin >> revPick;
        if (revPick != 1 && revPick != 2)
        {
            setColor(C_RED);
            std::cout << "Invalid input try again!\n";
            fflush(stdin);
            setColor(C_WHITE);
        }
    }

    if (revPick == 1)
    {
        std::cout << "Leave a review to " << selectedName << " (review must be only characters and numbers no like [ / or _ ] allowed)\n";
        std::string thisReview;
        std::string revBody;
        for (auto x : db.getPersonArr())
        {
            if (x->getID() == id)
            {
                thisReview += x->getFirstName();
                thisReview += " : ";
                break;
            }
        }
        std::getline(std::cin >> std::ws, revBody);
        thisReview += revBody;
        db.getFieldArr()[possibleIndex[selectedOption-1]]->setReview(thisReview);
        setColor(C_GREEN);
        std::cout << "Thanks for leaving a review for the other people to watch!\n";
        setColor(C_WHITE);
    }

    std::cout << "The available dates are: " << cal[0].getDay() << "/" << cal[0].getMonth() << "/" << cal[0].getYear() << " ~ " << cal[6].getDay() << "/" << cal[6].getMonth() << "/" << cal[6].getYear() << '\n';

    bool validBook = false;
    int hh = 0;
    int dd = 0;
    int mm = 0;
    int yr = 0;
    while (!validBook)
    {

        bool validDD = false;
        while (!validDD) {
            setColor(C_WHITE);
            std::cout << "\nPlease select a date to schedule (";
            setColor(C_BLUE);
            std::cout << "Just pick the [dd] of the date for ex: to pick 23/4/2025 just enter 23";
            setColor(C_WHITE);
            std::cout << ").\n";
            std::cin >> dd;

            for (auto z: cal)
            {
                if (dd == z.getDay())
                {
                    mm = z.getMonth();
                    yr = z.getYear();
                    validDD = true;
                    break;
                }
            }
            if (!validDD)
            {
                setColor(C_RED);
                std::cout << "Bad input! try again.\n";
                setColor(C_WHITE);
            }
        }


        bool validHH = false;
        while (!validHH) {
            setColor(C_WHITE);
            std::cout << "\nPlease select an hour to schedule (";
            setColor(C_BLUE);
            std::cout
                    << "Just pick the [hh] of the date for ex: to pick 12:00 just enter 12 or to pick 8:00 just enter 8";
            setColor(C_WHITE);
            std::cout << ").\n";
            std::cin >> hh;

            for (int i = 8; i < 21; ++i) {
                if (hh == i) {
                    validHH = true;
                    break;
                }
            }
            if (!validHH)
            {
                setColor(C_RED);
                std::cout << "Bad input! try again.\n";
                setColor(C_WHITE);
            }
        }

        if (db.getReservationArr().empty())
            break;
        int counterX = 0;
        for (auto g: db.getReservationArr())
        {
            if (dd != g->getDate().getDay() || hh != std::stoi(g->getTime()) && nameOfFieldSelected == g->getFieldName())
            {
                validBook = true;
            }
            else
            {
                ++counterX;
            }
        }
        if (counterX == db.getNumOfReservations())
        {
            setColor(C_RED);
            std::cout << "This date and time is unavailable\n";
            setColor(C_WHITE);
            validBook = false;
        }
    }

    std::string stringHH;
    stringHH = std::to_string(hh);
    db.dbMakeReservation(id, nameOfFieldSelected, dd, mm, yr, stringHH);

    setColor(C_GREEN);
    system("cls");
    std::cout << "You have booked " << dd << '/' << mm << '/' << yr << " at: " << hh << ":00" << '\n';
    for (auto i : db.getFieldArr())
    {
        if (i->getName() == selectedName)
        {
            i->setCounter(i->getReservationCounter() + 1);
            break;
        }
    }
    setColor(C_WHITE);

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
            possibleIndex.push_back(i);
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

    if (possibleIndex.empty())
    {
        setColor(C_RED);
        system("cls");
        std::cout << "You don't have any reservations to cancel.\n";
        return;
    }

    int userOption = 0;
    bool validValue = true;
    bool flag = false;
    std::cout << "To cancel field enter his id number:\n";
    while(!flag)
    {
        std::cin >> userOption;

        for (int i : possibleIndex)
        {
            //if(possibleIndex[userOption-1] != userOption-1)
            if(userOption > possibleIndex.size() || userOption < 1)
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
    system("cls");
    std::cout << "The cancellation was successfully.\n";
}

void ui::calendar(db& db, const std::string& id)
{
    system("cls");
    setColor(C_PURPLE);
    std::cout << "Calendar:\n";
    setColor(C_L_BLUE);
    std::cout << "My Schedule:\n";

    setColor(C_WHITE);

    std::vector<date> cal;
    makeCalender(cal);
    displayCalenderPlayer(cal, db, id);
}

void ui::editProfile(db& db, std::string& id)
{
    system("cls");
    setColor(C_PURPLE);
    std::cout << "Edit Your Profile:\n";
    int editOption = 0;

    while(editOption < 1 || editOption > 5)
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

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (editOption < 1 || editOption > 5) {
            setColor(C_RED);
            std::cout << "Invalid value. Please enter a number between 1 and 5.\n";
        }
    }

    enum editOptions {passwordOption = 1, firstNameOption, lastNameOption, phoneNumberOption, genderOption};

    bool flag = false;
    std::string e;

    auto p = db.startSession(id);
    Manager* g = nullptr;
    int type = p->getType();
    if (type == DB_USER_TYPE_MANGER)
        g = dynamic_cast<Manager*>(p);

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
    if (type == DB_USER_TYPE_PLAYER)
        db.dbMakeUser(DB_USER_TYPE_PLAYER, id, password, fName, lName, pNumber, gender);
    else
        db.dbMakeUser(DB_USER_TYPE_MANGER, id, password, fName, lName, pNumber, gender, g->getBirthday()->getDay(), g->getBirthday()->getMonth(), g->getBirthday()->getYear());

    setColor(C_GREEN);
    system("cls");
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
    while(option < 1 || option > 6) {
        setColor(C_L_BLUE);
        std::cout << "Manager Menu: " ;
        setColor(C_YELLOW);
        std::cout << manager->getFirstName() << " {" << manager->getID() << "}\n";
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
        std::cout << "enter 6.\n";
        std::cin >> option;

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (option < 1 || option > 6) {
            setColor(C_RED);
            std::cout << "Invalid value. Please enter a number between 1 and 6.\n";
        }

        setColor(C_WHITE);
        enum menuOptions {
            ScheduledGames = 1,
            markDatesAsUnavailable,
            addFieldOption,
            deleteFieldOption,
            editProfileOption,
            exitProgram
        };
        int selectedOption = 0;
        int indexOption = 0;
        switch (option) {
            case ScheduledGames: {
                listOfScheduledGames(db, id);
                option = 0;
                break;
            }
            case markDatesAsUnavailable: {
                markDateAsUnavailable(db, id);
                option = 0;
                break;
            }
            case addFieldOption: {
                addField(db, id);
                option = 0;
                break;
            }
            case deleteFieldOption: {
                deleteField(db, id);
                option = 0;
                break;
            }
            case editProfileOption: {
                editProfile(db, id);
                option = 0;
                break;
            }
            case exitProgram: {
                system("cls");
                break;
            }
        }
    }
}

void ui::listOfScheduledGames(db &db, std::string &id)
{
    system("cls");
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
        if (!(std::cin >> selectedOption)) // Check if input is valid
        {
            setColor(C_RED);
            std::cout << "Invalid input\n";
            setColor(C_WHITE);
            std::cout << "Enter a valid value (1 or 2): \n";
            std::cin.clear(); // Clear error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
        }
        else if(selectedOption != 1 && selectedOption != 2)
        {
            setColor(C_RED);
            std::cout << "Invalid value\n";
            setColor(C_WHITE);
            std::cout << "Enter a valid value (1 or 2): ";
        }
    }

    system("cls");
    std::vector<int> vec;
    if(selectedOption == 1)
    {
        int k = 0;
        for(int i = 0; i < db.getNumOfFields(); ++i)
        {
            if(db.getFieldArr()[i]->getOwnerId() == id)
            {
                vec.push_back(i);
                std::cout << k + 1 << ". " << db.getFieldArr()[i]->getName() << '\n';
                ++k;
            }
        }
        if(vec.empty())
        {
            setColor(C_RED);
            system("cls");
            std::cout << "You don't have any fields.\n";
            setColor(C_WHITE);
            return;
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

        std::vector<int> vecRes;
        std::string selectedField = db.getFieldArr()[vec[indexOption-1]]->getName();
        int numReservations = db.getFieldArr()[vec[indexOption-1]]->getReservationCounter();
        int indexRes = 0;
        for (auto n : db.getReservationArr())
        {
            if (n->getFieldName() == selectedField)
            {
                vecRes.push_back(indexRes);
                ++indexRes;
            }
        }

        if (vecRes.empty())
        {
            setColor(C_RED);
            system("cls");
            std::cout << "No reservation for this field.\n";
            setColor(C_WHITE);
            return;
        }

        int i, j;
        int n = (int)vecRes.size();
        bool swapped;
        for (i = 0; i < n - 1; i++)
        {
            swapped = false;
            for (j = 0; j < n - i - 1; j++)
            {
                if (db.getReservationArr()[vecRes[j]]->getDate().getYear() >= db.getReservationArr()[vecRes[j+1]]->getDate().getYear())
                    if (db.getReservationArr()[vecRes[j]]->getDate().getMonth() >= db.getReservationArr()[vecRes[j+1]]->getDate().getMonth())
                        if (db.getReservationArr()[vecRes[j]]->getDate().getDay() >= db.getReservationArr()[vecRes[j+1]]->getDate().getDay())
                            if (std::stoi(db.getReservationArr()[vecRes[j]]->getTime()) > std::stoi(db.getReservationArr()[vecRes[j+1]]->getTime()))
                            {
                                std::swap(vecRes[j], vecRes[j + 1]);
                                swapped = true;
                            }
            }
            // If no two elements were swapped
            // by inner loop, then break
            if (swapped == false)
                break;
        }


        for(auto u : vecRes)
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
        setColor(C_WHITE);
        std::cout << "This field was ordered: ";
        setColor(C_BLUE);
        std::cout << numReservations;
        setColor(C_WHITE);
        std::cout << " Times.\n";
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

        if(validResIndex.empty())
        {
            setColor(C_RED);
            system("cls");
            std::cout << "You don't have any scheduled games on this date.\n";
            setColor(C_WHITE);
            return;
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
        system("cls");
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
    system("cls");
    setColor(C_PURPLE);
    std::cout << "Add Field:\n";
    std::string e;
    std::string name;
    bool flag = false;
    while(!flag)
    {
        setColor(C_WHITE);
        std::cout << "Enter field name (";
        setColor(C_BLUE);
        std::cout <<"letters only without space";
        setColor(C_WHITE);
        std::cout << "):\n";
        std::cin >> name;
        flag = Auth::fieldNameAuth(e,name);
        if(!flag)
        {
            setColor(C_RED);
            std::cout << e <<'\n';
        }
    }

    flag = false;
    std::string city;
    while(!flag)
    {
        setColor(C_WHITE);
        std::cout << "Enter city name (";
        setColor(C_BLUE);
        std::cout << "from this options - Ashdod, Tel-Aviv, Jerusalem, Eilat, Ashkelon";
        setColor(C_WHITE);
        std::cout << "):\n";
        std::cin >> city;
        flag = Auth::cityAuth(e, city);
        if(!flag)
        {
            setColor(C_RED);
            std::cout << e << '\n';
        }
    }

    flag = false;
    std::string sportType;
    while(!flag)
    {
        setColor(C_WHITE);
        std::cout << "Enter sport type (";
        setColor(C_BLUE);
        std::cout << "from this options - Soccer, Basketball, Tennis, Football";
        setColor(C_WHITE);
        std::cout << "):\n";
        std::cin >> sportType;
        flag = Auth::sportTypeAuth(e, sportType);
        if(!flag)
        {
            setColor(C_RED);
            std::cout << e << '\n';
        }
    }

    flag = false;
    std::string description;
    while(!flag)
    {
        setColor(C_WHITE);
        std::cout << "Enter description (";
        setColor(C_BLUE);
        std::cout << "max 250 characters";
        setColor(C_WHITE);
        std::cout << "):\n";
        fflush(stdin);
        std::getline(std::cin >> std::ws, description);
        flag = Auth::fieldDescription(e, description);
        if(!flag)
        {
            setColor(C_RED);
            std::cout << e << '\n';
        }
    }

    std::string reviews;


    bool accessible;
    flag = false;
    while(!flag)
    {
        setColor(C_WHITE);
        std::cout << "for accessible field - ";
        setColor(C_BLUE);
        std::cout << "enter 0.\n";
        setColor(C_WHITE);
        std::cout << "For not accessible field - ";
        setColor(C_BLUE);
        std::cout << "enter 1.\n";
        setColor(C_WHITE);
        std::cin >> accessible;
        flag = Auth::accessibleField(e,accessible);
        if(!flag)
        {
            setColor(C_RED);
            std::cout << e << '\n';
        }
    }

    int counter = 0;


    db.dbMakeField(name, city, sportType, id, description, reviews, accessible, counter);
}

void ui::deleteField(db &db, std::string &id)
{
    system("cls");
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
            std::cout << k + 1 << ". " << db.getFieldArr()[i]->getName() << '\n';
            ++k;
        }
    }

    if (vec.empty())
    {
        setColor(C_RED);
        system("cls");
        std::cout << "You don't have any field to delete.\n";
        setColor(C_WHITE);
        return;
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
    setColor(C_GREEN);
    std::cout << "You have deleted the selected field successfully.\n";
    setColor(C_WHITE);
}

void ui::makeCalender(std::vector<date>& arr)
{
    SYSTEMTIME time;
    GetSystemTime(&time);
    auto firstDay = date(time.wDay, time.wMonth, time.wYear);
    arr.push_back(firstDay);

    int daysInMonth[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int weekOption = 0;
    enum weekCase {freeWeek=1, jumpMonth, jumpYear};

    if (firstDay.getDay() + 6 <= daysInMonth[firstDay.getMonth()-1]) // if entire week is on the same month.
        weekOption = 1;
    else if (firstDay.getDay() + 6 > daysInMonth[firstDay.getMonth()-1] && firstDay.getMonth() != 12)
        weekOption = 2;
    else
        weekOption = 3;


    switch (weekOption)
    {
        case freeWeek:
        {
            for (int j = 0; j < DAYS_OF_WEEK; ++j) // if entire week is on the same month.
            {
                date newDay = date(firstDay.getDay()+j+1, firstDay.getMonth(), firstDay.getYear());
                arr.push_back(newDay);
            }
            return;
        }
        case jumpMonth:
        {
            for (int i = 0; i < DAYS_OF_WEEK; ++i) // day is out of range of current month.
            {
                if (firstDay.getDay()+i+1 <= daysInMonth[firstDay.getMonth()-1])
                {
                    date newDay = date(firstDay.getDay()+i+1, firstDay.getMonth(), firstDay.getYear());
                    arr.push_back(newDay);
                }
                else
                {
                    date newDay = date(firstDay.getDay()+i+1-daysInMonth[firstDay.getMonth()-1], firstDay.getMonth()+1, firstDay.getYear());
                    arr.push_back(newDay);
                }
            }
            return;
        }
        case jumpYear:
        {
            for (int i = 0; i < DAYS_OF_WEEK; ++i) // month is out of range in current year.
            {
                if (firstDay.getDay()+i+1 <= daysInMonth[firstDay.getMonth()-1])
                {
                    date newDay = date(firstDay.getDay()+i+1, firstDay.getMonth(), firstDay.getYear());
                    arr.push_back(newDay);
                }
                else
                {
                    date newDay = date(firstDay.getDay()+i+1-daysInMonth[firstDay.getMonth()-1], 1, firstDay.getYear()+1);
                    arr.push_back(newDay);
                }
            }
            return;
        }
        default:
            break;
    }
}

void ui::displayCalenderPlayer(std::vector<date> &dateArr, db &db, const std::string &id)
{
    system("cls");
    std::vector<int> vec;

    for(int i = 0; i < db.getNumOfReservations(); ++i)
    {
        if(db.getReservationArr()[i]->getIdPlayer() == id)
        {
            vec.push_back(i);
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

    setColor(C_WHITE);
    bool fistRes = true;
    for (auto z : dateArr)
    {
        setColor(C_WHITE);
        std::cout << std::to_string(z.getDay()) << '/' << std::to_string(z.getMonth()) << '/' << std::to_string(z.getYear()) << ": ";
        for (auto y : vec)
        {
            if (z == db.getReservationArr()[y]->getDate() && db.getReservationArr()[y]->getIdPlayer() == id)
            {
                if (fistRes)
                {
                    setColor(C_BLUE);
                    fistRes = false;
                }
                else
                    setColor(C_WHITE);
                std::cout << '['<<db.getReservationArr()[y]->getFieldName() << " " << db.getReservationArr()[y]->getTime() << ":00]";
            }
        }
        std::cout << '\n';
    }
}

void ui::displayCalenderField(std::vector<date> &dateArr, db &db, std::string &fieldName)
{
    system("cls");
    setColor(C_WHITE);

    std::cout << "This is the calender for ";
    setColor(C_BLUE);
    std::cout << fieldName << '\n';
    fields* getCurField;
    for (auto i : db.getFieldArr())
    {
       if(i->getName() == fieldName)
       {
           getCurField = i;
           if(i->isAccessible())
           {
               setColor(C_WHITE);
               std::cout << " This Field is ";
               setColor(C_YELLOW);
               std::cout << "ACCESSIBLE.\n";
               break;
           }
       }
    }
    setColor(C_WHITE);
    std::cout << "The color - ";
    setColor(C_GREEN);
    std::cout << "Green ";
    setColor(C_WHITE);
    std::cout << "marks an empty hour that you can schedule.\n";
    std::cout << "The color - ";
    setColor(C_RED);
    std::cout << "Red ";
    setColor(C_WHITE);
    std::cout << "marks a taken hour that you can't schedule.\n";
    std::cout << "The color - ";
    setColor(C_PURPLE);
    std::cout << "Purple ";
    setColor(C_WHITE);
    std::cout << "marks a closed field for this day (you can't make a reservation).\n";
    std::cout << "Description: " << getCurField->getDescription() << "\n\n";

    for (auto q : dateArr)
    {
        std::cout << std::to_string(q.getDay()) << '/' << std::to_string(q.getMonth()) << '/' << std::to_string(q.getYear()) << ": ";
        bool foundReservation = false;
        for (int l = 8; l < 21; ++l) {
            bool reservationFoundForHour = false;
            for (auto b : db.getReservationArr())
            {
                if (b->getDate() == q && b->getFieldName() == fieldName && std::stoi(b->getTime()) == l)
                {
                    foundReservation = true;
                    reservationFoundForHour = true;
                    if (b->getIdPlayer() != "0") {
                        setColor(C_RED);
                    } else {
                        setColor(C_PURPLE);
                    }
                    std::cout << l << ":00 ";
                }
            }
            if (!reservationFoundForHour) {
                setColor(C_GREEN);
                std::cout << l << ":00 ";
            }
        }
        setColor(C_WHITE);
        std::cout << '\n';
    }
    setColor(C_L_BLUE);
    std::cout << "\nReviews: \n" << getCurField->getReviews() << "\n\n";
    setColor(C_WHITE);

}

void ui::markDateAsUnavailable(db &db, std::string& id)
{
    system("cls");
    std::vector<date> cal;
    makeCalender(cal);

    std::vector<int> managerFields;
    std::string fieldName;
    int index = 0;
    for (auto i : db.getFieldArr())
    {
        if (i->getOwnerId() == id)
        {
            managerFields.push_back(index);
        }
        ++index;
    }

    if(managerFields.empty())
    {
        setColor(C_RED);
        std::cout << "You don't have any fields.\n";
        setColor(C_WHITE);
        return;
    }

    bool validIndex = false;
    int indexA = 0;
    while (!validIndex)
    {
        int k = 0;
        for (auto i : managerFields)
        {
            setColor(C_WHITE);
            std::cout << "For " << db.getFieldArr()[i]->getName() << " - ";
            setColor(C_BLUE);
            std::cout << "Enter " << k+1 << '\n';
            ++k;
        }
        std::cin >> indexA;

        if (indexA < 1 || indexA > k)
        {
            setColor(C_RED);
            std::cout << "Invalid index, try again!\n";
            setColor(C_WHITE);
            // Clear input buffer
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
        {
            validIndex = true;
        }
    }

    std::cout << "The available dates are: " << cal[0].getDay() << "/" << cal[0].getMonth() << "/" << cal[0].getYear() << " ~ " << cal[6].getDay() << "/" << cal[6].getMonth() << "/" << cal[6].getYear() << '\n';
    std::cout << "Enter a day to make unavailable (for ex: [dd] for 25/6/2026 just enter 25).\n";

    bool validDay = false;
    int dd = 0;
    int mm = 0;
    int year = 0;
    while (!validDay)
    {
        std::cin >> dd;
        for (auto i : cal)
        {
            if (i.getDay() == dd)
            {
                validDay = true;
                mm = i.getMonth();
                year = i.getYear();
                break;
            }
        }
        if (!validDay)
        {
            setColor(C_RED);
            std::cout << "Invalid day, try again!\n";
        }
    }

    for (auto i : db.getReservationArr())
    {
        if (i->getFieldName() == db.getFieldArr()[indexA-1]->getName() && i->getDate().getDay() == dd)
        {
            db.dbDelReservation(i->getIdPlayer(), db.getFieldArr()[indexA-1]->getName(), i->getTime());
        }
    }

    for (int i = 8; i < 21; ++i)
    {
        std::string zero = "0";
        std::string hr = std::to_string(i);
        std::string arrName = db.getFieldArr()[indexA-1]->getName();
        db.dbMakeReservation(zero, arrName, dd, mm, year, hr);
    }

    setColor(C_GREEN);
    system("cls");
    std::cout << "The date selected will be unavailable\n";
}

void ui::mainFunction(db& db)
{
    system("cls");
    while (true)
    {
        int selector = welcomeScreen();
        if (selector == 1) // want to register.
        {
            selector = registration();
            registrationProcess(selector, db);
            continue;
        }
        else if (selector == 2) // want to log in.
        {
            std::string id = login(db);
            for (auto i : db.getPersonArr())
            {
                if (i->getID() == id)
                {
                    if (i->getType() == 2)
                    {
                        managerPanel(db, id);
                        break;
                    }
                    else
                    {
                        playerPanel(db, id);
                        break;
                    }
                }
            }
        }
        else
        {
            std::cout << "Good Bye!\n";
            break;
        }
    }
}
