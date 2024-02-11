//
// Created by Dor Maudi on 11/02/2024.
//

#include "db.h"

db::db(std::string userPath, std::string fieldsPath)
        : userPath(std::move(userPath)), fieldsPath(std::move(fieldsPath)), numOfUserFiles(0), numOfFieldFiles(0)
{}

void db::init()
{
    // create a new file instance.
    std::fstream myFile;

    // create users using userCtor.
    for (const auto& entry : std::filesystem::directory_iterator(this->userPath))
    {
        myFile.open(entry.path(), std::ios::in);

        std::string id;
        std::string password;
        int age = 0;
        char gender = 'A';

        loadStringToMem(id, myFile);
        loadStringToMem(password, myFile);
        loadIntToMem(age, myFile);
        loadCharToMem(gender, myFile);

        // use user ctor here.
        std::cout << "user entry\nid: " << id
                  << "password: " << password
                  << "age: " << age << '\n'
                  << "gender: " << gender << '\n' << '\n';

        ++this->numOfUserFiles;
        myFile.close();
    }
    std::cout << "Loaded " << this->numOfUserFiles << " users into mem" << '\n';

    // create fields using fieldsCtor.
    for (const auto& entry : std::filesystem::directory_iterator(this->fieldsPath))
    {
        myFile.open(entry.path());

        // set fields into here.
        std::string name;
        std::string city;

        loadStringToMem(name, myFile);
        loadStringToMem(name, myFile);

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

bool db::dbMakeUser()
{
    // if user exist return false, else create a new user.

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
