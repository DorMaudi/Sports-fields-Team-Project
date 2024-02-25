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
#include "Person.h"
#include "Player.h"
#include "Manager.h"
#include "fields.h"
#include "reservation.h"

#define DB_USER_TYPE_PLAYER 1
#define DB_USER_TYPE_MANGER 2

class db {

public:

    // constructor.
    db();

    // dtor.
    ~db();

    // basic functions to load db to mem & to save to disk.
    void init();    // loads all users and fields into mem.
    void commitToDisk(); // commits all from mem into disk.

    // create user / field on db.
    // take player args and makes a new player on mem & on disk.
    bool dbMakeUser(int type, std::string &id, std::string &password, std::string &firstName,
                    std::string &lastName, std::string &phoneNumber, char gender,
                    int day = 0, int month = 0, int year = 0);
    bool dbMakeField();

    // delete user / field on db.
    bool dbDelUser();
    bool dbDelField();

    // getFunctions.
    int getNumOfUsers() const { return this->numOfUserFiles; }
    int getNumOfFields() const { return this->numOfUserFiles; }
    std::vector<Person*> getPersonArr() const { return this->personArr; }
    std::vector<fields*> getFieldArr() const { return this->fieldsArr; }
    std::vector<reservation*> getReservationArr() const { return this->reservationArr; }
    int getCurResId() const { return this->reservationIdTracker; }

private:

    // set here the path to db folders.
    // paths to each db folder.
    std::string basePath;
    std::string userPath;
    std::string fieldsPath;
    std::string reservationsPath;

    // vectors to hold each db on memory.
    std::vector<Person*> personArr;
    std::vector<fields*> fieldsArr;
    std::vector<reservation*> reservationArr;

    // counters that counts the amount of each db size.
    int numOfUserFiles;
    int numOfFieldFiles;
    int numOfReservations;
    int reservationIdTracker;

    // memory management static functions.
    static void loadStringToMem(std::string& output, std::fstream& file);
    static void loadIntToMem(int& output, std::fstream& file);
    static void loadCharToMem(char& output, std::fstream& file);
    static void loadArrToMem(std::vector<std::string>& output, std::fstream& file);

};



#endif //SPORTS_FIELDS_TEAM_PROJECT_DB_H
