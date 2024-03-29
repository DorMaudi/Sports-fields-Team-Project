//
// Created by Dor Maudi on 11/02/2024.
//

#include "db.h"

db::db()
: numOfUserFiles(0), numOfFieldFiles(0), numOfReservations(0)
{
    // using winApi to fetch abs path for each database folder.
    TCHAR buffer[MAX_PATH];
    GetFullPathNameA("dataBase", MAX_PATH, buffer, nullptr); // set buffer to path.

    this->basePath = buffer;
    basePath.erase(basePath.find("\\Sports-fields-Team-Project\\", 0));

    this->userPath = basePath + R"(\Sports-fields-Team-Project\dataBase\users)";
    this->fieldsPath = basePath + R"(\Sports-fields-Team-Project\dataBase\fields)";
    this->reservationsPath = basePath + R"(\Sports-fields-Team-Project\dataBase\reservations)";

    std::fstream iFile;
    iFile.open(basePath + R"(\Sports-fields-Team-Project\dataBase\reservation_tracker.txt)", std::ios::in);
    loadIntToMem(reservationIdTracker, iFile);
    iFile.close();
}

db::~db()
{
    // delete vectors.
    while (!this->personArr.empty())
    {
        delete this->personArr.back();
        this->personArr.pop_back();
    }

    while (!this->fieldsArr.empty())
    {
        delete this->fieldsArr.back();
        this->fieldsArr.pop_back();
    }

    while (!this->reservationArr.empty())
    {
        delete this->reservationArr.back();
        this->reservationArr.pop_back();
    }

    std::fstream iFile;
    iFile.open(basePath + R"(\Sports-fields-Team-Project\dataBase\reservation_tracker.txt)", std::ios::out | std::ios::trunc);
    iFile << "id: " << this->reservationIdTracker << '\n';
    iFile.close();

}

void db::init()
{
    // create a new file instance.
    std::fstream myFile;

    // create users using userCtor.
    for (const auto& curFile : std::filesystem::directory_iterator(this->userPath))
    {
        myFile.open(curFile.path(), std::ios::in);

        int type = 0;

        // args for player.
        std::string id;
        std::string password;
        std::string name;
        std::string lName;
        std::string phone;
        char gender = 'A';

        // args for manager.
        std::string bDay;
        std::string bMon;
        std::string bYr;
        int day, month, year;

        loadIntToMem(type, myFile);
        loadStringToMem(id, myFile);
        loadStringToMem(password, myFile);
        loadStringToMem(name, myFile);
        loadStringToMem(lName, myFile);
        loadStringToMem(phone, myFile);
        loadCharToMem(gender, myFile);

        loadStringToMem(bDay, myFile);
        loadStringToMem(bMon, myFile);
        loadStringToMem(bYr, myFile);

        // use user ctor here.
        enum userType {PlayerType = 1, ManagerType};

        switch (type)
        {
            case PlayerType:
            {
                this->personArr.push_back(new Player(id, password, name, lName, phone, gender));
                break;
            }
            case ManagerType:
            {
                day = std::stoi(bDay);
                month = std::stoi(bMon);
                year = std::stoi(bYr);
                this->personArr.push_back(new Manager(id, password, name, lName, phone, gender, new date(day, month, year)));
                break;
            }
            default:
                continue;
        }

        ++this->numOfUserFiles;
        myFile.close();
    }
    std::cout << "Loaded " << this->numOfUserFiles << " users into mem" << '\n';


    // create fields using fieldsCtor.
    for (const auto& curFile : std::filesystem::directory_iterator(this->fieldsPath))
    {
        myFile.open(curFile.path());

        // set fields into here.
        std::string name;
        std::string city;
        std::string sportType;
        std::string ownerId;
        std::string description;
        std::string reviews;
        std::string accessible;
        std::string reservationCounter;


        loadStringToMem(name, myFile);
        loadStringToMem(city, myFile);
        loadStringToMem(sportType, myFile);
        loadStringToMem(ownerId, myFile);
        loadArrToMem(description, myFile);
        loadArrToMem(reviews, myFile);
        loadStringToMem(accessible, myFile);
        loadStringToMem(reservationCounter, myFile);

        bool accessibleBool = false;
        int accessibleInt = std::stoi(accessible);

        if (accessibleInt >= 1)
            accessibleBool = true;

        int reservationCounterInt = std::stoi(reservationCounter);

        // call fields ctor and add into fields vector.
        this->fieldsArr.push_back(new fields(name, city, sportType, ownerId, description, reviews, accessibleBool, reservationCounterInt));

        ++this->numOfFieldFiles;
        myFile.close();
    }
    std::cout << "Loaded " << this->numOfFieldFiles << " fields into mem" << '\n';

    // create reservations using reservationCtor.
    for (const auto& curFile : std::filesystem::directory_iterator(this->reservationsPath))
    {
        myFile.open(curFile.path());

        // set fields into here.
        std::string id;
        std::string userId;
        std::string fieldName;
        int day, month, year;
        std::string time;

        loadStringToMem(id, myFile);
        loadStringToMem(userId, myFile);
        loadStringToMem(fieldName, myFile);
        loadIntToMem(day, myFile);
        loadIntToMem(month, myFile);
        loadIntToMem(year, myFile);
        loadStringToMem(time, myFile);

        // call fields ctor here.
        this->reservationArr.push_back(new reservation(id, userId, fieldName, time, day, month, year));

        ++this->numOfReservations;
        myFile.close();
    }
    std::cout << "Loaded " << this->numOfReservations << " reservations into mem" << '\n';
    std::cout << "Id Tracker " << this->reservationIdTracker << '\n';
    system("CLS");
}

void db::commitToDisk()
{
    // save changes to disk.
    std::string tempId;
    std::string tempName;
    std::fstream iFile;
    int userType = 0;

    enum userType {typePlayer = 1, typeManager};

    for (int i = 0; i < this->numOfUserFiles; ++i)
    {

        auto p = this->personArr.back();
        tempId = p->getID();
        if (p->getType() == DB_USER_TYPE_MANGER)
            userType = DB_USER_TYPE_MANGER;
        else
            userType = DB_USER_TYPE_PLAYER;
        iFile.open(this->userPath + "\\" + tempId + ".txt", std::ios::out | std::ios::trunc);

        switch (userType)
        {
            case typePlayer:
            {
                iFile << "type: " << userType << '\n'
                        << "id: " << p->getID() << '\n'
                        << "pass: " << p->getPassword() << '\n'
                        << "name: " << p->getFirstName() << '\n'
                        << "l_name: " << p->getLastName() << '\n'
                        << "phone: " << p->getPhoneNumber() << '\n'
                        << "gender: " << p->getGender() << '\n';
                break;
            }
            case typeManager:
            {
                auto pManager = (Manager*)p;
                iFile << "type: " << userType << '\n'
                      << "id: " << pManager->getID() << '\n'
                      << "pass: " << pManager->getPassword() << '\n'
                      << "name: " << pManager->getFirstName() << '\n'
                      << "l_name: " << pManager->getLastName() << '\n'
                      << "phone: " << pManager->getPhoneNumber() << '\n'
                      << "gender: " << pManager->getGender() << '\n'
                      << "day: " << pManager->getBirthday()->getDay() << '\n'
                      << "month: " << pManager->getBirthday()->getMonth() << '\n'
                      << "year: " << pManager->getBirthday()->getYear() << '\n';
                break;
            }
            default:
                std::cout << "DB Error!\n";
        }
        iFile.close();
    }

    for (int i = 0; i < this->numOfFieldFiles; ++i)
    {

        auto p = this->fieldsArr.back();
        tempName = p->getName();
        iFile.open(this->fieldsPath + "\\" + tempName + ".txt", std::ios::out | std::ios::trunc);

        std::string reviewParsed = p->getReviews();
        std::string descriptionParsed = p->getDescription();

        if (p->getDescription().empty())
        {
            p->fixArr(1);
        }

        if (p->getReviews().empty())
        {
            p->fixArr(0);
        }

        transFromMem(reviewParsed);
        transFromMem(descriptionParsed);

        iFile << "name: " << p->getName() << '\n'
              << "city: " << p->getCity() << '\n'
              << "sportType: " << p->getSportType() << '\n'
              << "ownerId: " << p->getOwnerId() << '\n'
              << "description: " << descriptionParsed << '\n'
              << "reviews: " << reviewParsed << '\n'
              << "accessible: " << p->isAccessible() << '\n'
              << "resCounter: " << p->getReservationCounter() << '\n';

        iFile.close();
        this->fieldsArr.pop_back();
    }

    for (int i = 0; i < this->numOfReservations; ++i) {

        auto p = this->reservationArr.back();
        tempId = p->getId();
        iFile.open(this->reservationsPath + "\\" + tempId + ".txt", std::ios::out | std::ios::trunc);

        iFile << "resId: " << p->getId() << '\n'
              << "userId: " << p->getIdPlayer() << '\n'
              << "fieldName: " << p->getFieldName() << '\n'
              << "day: " << p->getDate().getDay() << '\n'
              << "month: " << p->getDate().getMonth() << '\n'
              << "year: " << p->getDate().getYear() << '\n'
              << "time: " << p->getTime() << '\n';
        iFile.close();
    }
}

void db::loadStringToMem(std::string &output, std::fstream &file)
{
    while (!file.eof())
    {
        char buf = (char)file.get();
        if (buf == ' ')
        {
            while (buf != '\n')
            {
                buf = (char)file.get();
                if (buf != '\n')
                    output += buf;
            }
            return;
        }
    }
}

void db::loadIntToMem(int &output, std::fstream &file)
{
    std::string num;
    while (!file.eof()) {
        char buf = (char) file.get();
        if (buf == ' ') {
            while (buf != '\n') {
                buf = (char)file.get();
                num += buf;
                output = std::stoi(num);
            }
            return;
        }
    }
}

void db::loadCharToMem(char &output, std::fstream &file)
{
    while (!file.eof())
    {
        char buf = (char)file.get();
        if (buf == ' ')
        {
            while (true)
            {
                buf = (char)file.get();
                output = (char)buf;
                return;
            }
        }
    }
}

void db::loadArrToMem(std::string &output, std::fstream &file)
{
    while (!file.eof())
    {
        char buf = (char)file.get();
        if (buf == ' ')
        {
            while (buf != '\n')
            {
                buf = (char)file.get();
                if (buf == '_')
                {
                    output += ' ';
                    continue;
                }
                if (buf == '/')
                {
                    output += '\n';
                    continue;
                }
                if (buf != '\n')
                    output += buf;
            }
            return;
        }
    }
}

void db::dbMakeUser(int type, std::string &id, std::string &password, std::string &firstName, std::string &lastName, std::string &phoneNumber, char gender, int day, int month, int year)
{
    // creating a new user on file.
    std::string newUserPath = this->userPath;
    newUserPath += ("\\" + id + ".txt");
    std::fstream newUserData;
    newUserData.open(newUserPath, std::ios::out);

    // create user on disk & on mem.
    switch (type)
    {
        case DB_USER_TYPE_PLAYER:
        {
            if (!newUserData.bad())
            {
                newUserData << "type: " << type << '\n'
                            << "id: " + id + '\n'
                            << "pass: " + password + '\n'
                            << "name: " + firstName + '\n'
                            << "l_name: " + lastName + '\n'
                            << "phone: " + phoneNumber + '\n'
                            << "gender: " << gender << '\n';
                newUserData.close();
            }
            this->personArr.push_back(new Player(id, password, firstName, lastName, phoneNumber, gender));
            this->numOfUserFiles += 1;
            break;
        }
        case DB_USER_TYPE_MANGER:
        {
            if (!newUserData.bad())
            {
                newUserData << "type: " << type << '\n'
                            << "id: " + id + '\n'
                            << "pass: " + password + '\n'
                            << "name: " + firstName + '\n'
                            << "l_name: " + lastName + '\n'
                            << "phone: " + phoneNumber + '\n'
                            << "gender: " << gender << '\n'
                            << "b_day: " << day << '\n'
                            << "b_mon: " << month << '\n'
                            << "b_yr: " << year << '\n';
                newUserData.close();
            }
            this->personArr.push_back(new Manager(id, password, firstName, lastName, phoneNumber, gender, new date(day, month, year)));
            this->numOfUserFiles += 1;
            break;
        }
        default:
        {
            std::cerr << "bad user type input!!!\n";
        }
    }
}

void db::dbMakeField(std::string& name, std::string& city, std::string& sportType, std::string& ownerId, std::string& description, std::string& reviews, bool accessible, int reservationCounter)
{
    // creating a new field on file.
    std::string newFieldPath = this->fieldsPath;
    newFieldPath += ("\\" + name + ".txt");
    std::fstream newFieldData;
    newFieldData.open(newFieldPath, std::ios::out);

    std::string stringifyBool;
    if (accessible)
        stringifyBool = "1";
    else
        stringifyBool = "0";

    transFromMem(description);
    transFromMem(reviews);

    newFieldData << "name: " << name << '\n'
                    << "city: " << city << '\n'
                    << "sportType: " << sportType << '\n'
                    << "ownerId: " << ownerId << '\n'
                    << "description: " << description << '\n'
                    << "reviews: " << reviews << '\n'
                    << "accessible: " << stringifyBool << '\n'
                    << "resCounter: " << std::to_string(reservationCounter) << '\n';
    ++this->numOfFieldFiles;
    newFieldData.close();

    transFromDisk(description);
    transFromDisk(reviews);
    this->fieldsArr.push_back(new fields(name, city, sportType, ownerId, description, reviews, accessible, reservationCounter));
}

void db::dbMakeReservation(std::string& id, std::string& fieldName, int day, int month, int year, std::string& time)
{
    // creating a new reservation on file.
    ++this->reservationIdTracker;
    std::string newReservationPath = this->reservationsPath;
    newReservationPath += ("\\" + std::to_string(this->reservationIdTracker) + ".txt");
    std::fstream newReservationData;
    newReservationData.open(newReservationPath, std::ios::out);

    newReservationData << "resId: " << std::to_string(this->reservationIdTracker) << '\n'
                        << "userId: " << id << '\n'
                        << "fieldName: " << fieldName << '\n'
                        << "day: " << std::to_string(day) << '\n'
                        << "month: " << std::to_string(month) << '\n'
                        << "year: " << std::to_string(year) << '\n'
                        << "time: " << time << '\n';
    newReservationData.close();

    std::string idTracker = std::to_string(this->reservationIdTracker);

    this->reservationArr.push_back(new reservation(idTracker, id, fieldName, time, day, month, year));
    ++this->numOfReservations;
}

void db::dbDelUser(std::string& id)
{
    // delete file on disk.
    std::string pathToUser = this->userPath + "\\" + id + ".txt";
    std::remove(pathToUser.c_str());
    int counter = 0;

    for (auto i : this->personArr)
    {
        if (i->getID() == id)
        {
            this->personArr.erase(this->personArr.begin() + counter);
            break;
        }
        ++counter;
    }
    --this->numOfUserFiles;
}

void db::dbDelField(std::string& nameOfField)
{
    // delete file on disk.
    dbDelReservationByField(nameOfField);

    std::string pathToField = this->fieldsPath + "\\" + nameOfField + ".txt";
    std::remove(pathToField.c_str());
    int counter = 0;

    for (auto i : this->fieldsArr)
    {
        if (i->getName() == nameOfField)
        {
            this->fieldsArr.erase(this->fieldsArr.begin() + counter);
            break;
        }
        ++counter;
    }
    --this->numOfFieldFiles;
}

void db::dbDelReservation(const std::string& id, const std::string& fieldName, const int dd, const std::string& hour)
{
    // delete file on disk.
    int counter = 0;

    for (auto i : this->reservationArr)
    {
        if (i->getIdPlayer() == id && i->getFieldName() == fieldName && i->getDate().getDay() == dd && i->getTime() == hour)
        {
            std::string pathToRes = this->reservationsPath + "\\" + i->getId() + ".txt";
            std::remove(pathToRes.c_str());
            this->reservationArr.erase(this->reservationArr.begin() + counter);
            break;
        }
        ++counter;
    }
    --this->numOfReservations;
}

void db::dbDelReservationByField(std::string &fieldName)
{
    // delete file on disk.
    int counter = 0;

    for (auto i : this->reservationArr)
    {
        if (i->getFieldName() == fieldName)
        {
            std::string pathToRes = this->reservationsPath + "\\" + i->getId() + ".txt";
            std::remove(pathToRes.c_str());
            this->fieldsArr.erase(this->fieldsArr.begin() + counter);
            break;
        }
        ++counter;
    }
    --this->numOfReservations;
}

Person *db::startSession(std::string &id) const
{
    for (int i = 0; i < this->numOfUserFiles; ++i)
    {
        if (this->personArr[i]->getID() == id)
            return this->personArr[i];
    }
}

void db::transFromDisk(std::string &text)
{
    for (auto i : text)
    {
        if (i == '_')
        {
            i = ' ';
            continue;
        }
        if (i == '/')
        {
            i = '\n';
            continue;
        }
    }
}

void db::setDescForField(std::string& fieldName, std::string &desc)
{
    for (auto i : fieldsArr)
    {
        if (i->getName() == fieldName)
        {
            i->setDescription(desc);
            return;
        }
    }
}

void db::addReviewToField(std::string &fieldName, std::string &review)
{
    for (auto i : this->fieldsArr)
    {
        if (i->getName() == fieldName)
        {
            i->appReview(review);
            return;
        }
    }
}

void db::transFromMem(std::string &text)
{
    for (int i = 0; i < text.size()+1; ++i)
    {
        if (text[i] == ' ')
        {
            text[i] = '_';
            continue;
        }
        if (text[i] == '\n')
        {
            text[i] = '/';
            continue;
        }
    }
}
