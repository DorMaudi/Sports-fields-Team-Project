//
// Created by Dor Maudi on 11/02/2024.
//

#include "db.h"

db::db()
: numOfUserFiles(0), numOfFieldFiles(0)
{
    // using winApi to fetch abs path for each database folder.
    WCHAR buffer[MAX_PATH];
    GetFullPathNameW(L"dataBase", MAX_PATH, buffer, nullptr); // set buffer to path.

    std::wstring basePath = buffer;
    basePath.erase(basePath.find(L"\\Sports-fields-Team-Project\\", 0));

    this->userPath = basePath + L"\\Sports-fields-Team-Project\\dataBase\\users";
    this->fieldsPath = basePath + L"\\Sports-fields-Team-Project\\dataBase\\fields";
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
        std::string id;
        std::string password;
        std::string name;
        std::string lName;
        std::string phone;
        char gender = 'A';
        std::vector<std::string> vecUser;

        loadIntToMem(type, myFile);
        loadStringToMem(id, myFile);
        loadStringToMem(password, myFile);
        loadStringToMem(name, myFile);
        loadStringToMem(lName, myFile);
        loadStringToMem(phone, myFile);
        loadCharToMem(gender, myFile);
        loadArrToMem(vecUser, myFile);

        // use user ctor here.
        enum userType {PlayerType = 1, ManagerType};

        switch (type)
        {
            case PlayerType:
            {
                this->personArr.push_back(new Players(id, password, name, lName, phone, gender));
                break;
            }
            case ManagerType:
            {
                this->personArr.push_back(new Manager(id, password, name, lName, phone, gender));
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
                      << "id: " << p->getID() << '\n'
                      << "id: " << p->getID() << '\n'
                      << "id: " << p->getID() << '\n';
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

bool db::dbMakeUser() // add Player& newUser
{
    // creating a new user on file.
    std::wstring newUser = this->userPath;
    const wchar_t* wtNewUser = newUser.c_str();
    //newUser.append("\\" + getUserID + ".txt"); //
    std::fstream newUserData;

    if (!newUserData.bad())
    {
        newUserData.open(wtNewUser, std::ios::out);
        //newUserData << "id: " + this->userId + '\n' + "pass: " + this->password + '\n' + "age: 18\n" + "gender: " + this->gender + '\n';
        newUserData.close();
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
