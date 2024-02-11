//
// Created by Dor Maudi on 11/02/2024.
//

#ifndef SPORTS_FIELDS_TEAM_PROJECT_DB_H
#define SPORTS_FIELDS_TEAM_PROJECT_DB_H


#include <string>
#include <fstream>
#include <filesystem>
#include <iostream>

class db {

public:

    // constructor.
    db(std::string userPath, std::string fieldsPath);

    // basic functions to load db to mem & to save to disk.
    void init();    // loads all users and fields into mem.
    void commit(); // commits all users and fields into mem.

    // create user / field on db.
    bool dbMakeUser();
    bool dbMakeField();

    // delete user / field on db.
    bool dbDelUser();
    bool dbDelField();


private:

    // set here the path to db folders.
    std::string userPath;
    std::string fieldsPath;
    int numOfUserFiles;
    int numOfFieldFiles;

    // memory management static functions.
    static void loadStringToMem (std::string& output, std::fstream& file);
    static void loadIntToMem (int& output, std::fstream& file);
    static void loadCharToMem (char& output, std::fstream& file);

};



#endif //SPORTS_FIELDS_TEAM_PROJECT_DB_H
