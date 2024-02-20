//
// Created by Dor Maudi on 11/02/2024.
//

#ifndef SPORTS_FIELDS_TEAM_PROJECT_DB_H
#define SPORTS_FIELDS_TEAM_PROJECT_DB_H


#include <string>
#include <fstream>
#include <filesystem>
#include <iostream>
#include <fileapi.h>
#include <vector>
#include "Manager.h"
#include "Players.h"

class db {

public:

    // constructor.
    db();

    // dtor.
    ~db();

    // basic functions to load db to mem & to save to disk.
    void init();    // loads all users and fields into mem.
    void commit(); // commits all from mem into disk.

    // create user / field on db.
    bool dbMakeUser(); // get Player& here.
    bool dbMakeField();

    // delete user / field on db.
    bool dbDelUser();
    bool dbDelField();

    // getFunctions.
    int getNumOfUsers() { return this->numOfUserFiles; }
    int getNumOfFields() { return this->numOfUserFiles; }
    const std::vector<Person*> getPersonArr() const { return this->personArr; }
    // const Field* getFieldArr() const { return this->fieldsArr; }

private:

    // set here the path to db folders.
    std::wstring userPath;
    std::wstring fieldsPath;
    std::vector<Person*> personArr;
    //std::vector<Fields*> fieldArr;
    int numOfUserFiles;
    int numOfFieldFiles;

    // memory management static functions.
    static void loadStringToMem(std::string& output, std::fstream& file);
    static void loadIntToMem(int& output, std::fstream& file);
    static void loadCharToMem(char& output, std::fstream& file);
    static void loadArrToMem(std::vector<std::string>& output, std::fstream& file);

};



#endif //SPORTS_FIELDS_TEAM_PROJECT_DB_H
