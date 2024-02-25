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

    std::string basePath = buffer;
    basePath.erase(basePath.find("\\Sports-fields-Team-Project\\", 0));

    this->userPath = basePath + R"(\Sports-fields-Team-Project\dataBase\users)";
    this->fieldsPath = basePath + R"(\Sports-fields-Team-Project\dataBase\fields)";
    this->reservationsPath = basePath + R"(\Sports-fields-Team-Project\dataBase\reservations)";
}

db::~db()
{
    // delete vectors.
    while (!this->personArr.empty())
    {
        delete this->personArr.back();
        this->personArr.pop_back();
    }
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
        //std::vector<std::string> vecUser;

        // args for manager.
        int day, month, year;

        loadIntToMem(type, myFile);
        loadStringToMem(id, myFile);
        loadStringToMem(password, myFile);
        loadStringToMem(name, myFile);
        loadStringToMem(lName, myFile);
        loadStringToMem(phone, myFile);
        loadCharToMem(gender, myFile);
        //loadArrToMem(vecUser, myFile);
        loadIntToMem(day, myFile);
        loadIntToMem(month, myFile);
        loadIntToMem(year, myFile);

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
        //std::string name;
        //std::string city;

        //loadStringToMem(name, myFile);
        //loadStringToMem(name, myFile);

        // call fields ctor here.


        ++this->numOfFieldFiles;
        myFile.close();
    }
    std::cout << "Loaded " << this->numOfFieldFiles << " fields into mem" << '\n';

    // create reservations using reservationCtor.
    for (const auto& curFile : std::filesystem::directory_iterator(this->reservationsPath))
    {
        myFile.open(curFile.path());

        // set fields into here.
        //std::string name;
        //std::string city;

        //loadStringToMem(name, myFile);
        //loadStringToMem(name, myFile);

        // call fields ctor here.


        ++this->numOfReservations;
        myFile.close();
    }
    std::cout << "Loaded " << this->numOfReservations << " reservations into mem" << '\n';
    //system("cls");
}

void db::commitToDisk()
{
    // save changes to disk.
    std::string tempId;
    std::fstream iFile;
    int userType = 0;

    enum userType {typePlayer = 1, typeManager};

    while (!this->personArr.empty())
    {
        auto p = this->personArr.back();
        tempId = p->getID();
        if (typeid(p) == typeid(Manager))
            userType = 2;
        else
            userType = 1;
        iFile.open(this->userPath.c_str(), std::ios::out | std::ios::trunc);

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
                        << "gender: " << p->getGender() << '\n'
                        << "reservations: " << p->getID() << '\n'; // call function here!
                break;
            }
            case typeManager:
            {
                iFile << "type: " << userType << '\n'
                      << "id: " << p->getID() << '\n'
                      << "pass: " << p->getID() << '\n'
                      << "name: " << p->getID() << '\n'
                      << "l_name: " << p->getID() << '\n'
                      << "phone: " << p->getID() << '\n'
                      << "gender: " << p->getID() << '\n';
                break;
            }
            default:
                std::cout << "DB Error!\n";
        }
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

void db::loadArrToMem(std::vector<std::string> &output, std::fstream &file)
{
    while (!file.eof())
    {
        char buf = (char)file.get();
        if (buf == ' ')
        {
            std::string singleValue;
            while (buf != '\n')
            {
                if (buf == ',')
                {
                    output.push_back(singleValue);
                    singleValue = "";
                }
                buf = (char)file.get();
                if (buf != ',')
                    singleValue += buf;
            }
            return;
        }
    }
}

bool db::dbMakeUser(int type, std::string &id, std::string &password, std::string &firstName, std::string &lastName, std::string &phoneNumber, char gender, int day, int month, int year)
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
                            << "b_day: " << day << '/' << month << '/' << year << '\n';
                newUserData.close();
            }
            //this->personArr.push_back(new Manager(id, password, firstName, lastName, phoneNumber, gender)); #######################
            this->numOfUserFiles += 1;
            break;
        }
        default:
        {
            std::cerr << "bad user type input!!!\n";
            return false;
        }
    }
    return true;
}

bool db::dbMakeField()
{

    return false;
}

bool db::dbDelUser()
{

    return false;
}

bool db::dbDelField()
{

    return false;
}
