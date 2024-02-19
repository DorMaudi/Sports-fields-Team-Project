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

void db::init()
{
    // create a new file instance.
    std::fstream myFile;

    // create users using userCtor.
    for (const auto& curFile : std::filesystem::directory_iterator(this->userPath))
    {
        myFile.open(curFile.path(), std::ios::in);

        std::string id;
        std::string password;
        int age = 0;
        char gender = 'A';
        std::vector<std::string> vecUser;

        loadStringToMem(id, myFile);
        loadStringToMem(password, myFile);
        loadIntToMem(age, myFile);
        loadCharToMem(gender, myFile);
        loadArrToMem(vecUser, myFile);

        // use user ctor here.
        std::cout << "user entry\nid: " << id
                  << "password: " << password
                  << "age: " << age << '\n'
                  << "gender: " << gender << '\n' << '\n'
                  << "Arr: " << vecUser[0] << '\n';

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

}

void db::commit()
{
    // save changes to disk.

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
                output = std::stoi(num, nullptr, 10);
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
