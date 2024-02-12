#include "Auth.h"
#include "date.h"
#include <iostream>
#include <cctype>

bool Auth::Register() {
    // Declaration of variables
    std::string Password, ID, F_Name, L_Name, B_Date;
    int PhoneNumber;
    char Gender;
    bool cond;

    // Loop to get a valid ID (containing only numbers)
    do {
        std::cout << "ID: " << std::endl;
        std::cin >> ID;

        // Check if ID contains only numbers
        cond = true;
        for (char c : ID) {
            if (!isdigit(c)) {
                std::cout << "ID should contain only numbers." << std::endl;
                cond = false;
                break;
            }
        }
    } while (!cond);

    // Loop to get a valid Password (minimum length of 6 characters)
    do {
        std::cout << "Password: " << std::endl;
        std::cin >> Password;
        if (Password.size() < 6) {
            std::cout << "Your password should be longer than 6 letters." << std::endl;
            cond = false;
        } else {
            cond = true;
        }
    } while (!cond);

    // Loop to get a valid first name (containing only letters)
    do {
        std::cout << "What's your first name?" << std::endl;
        std::cin >> F_Name;
        cond = true;
        for (char c : F_Name) {
            if (!isalpha(c)) {
                std::cout << "Your first name should only contain letters." << std::endl;
                cond = false;
                break;
            }
        }
    } while (!cond);

    // Loop to get a valid last name (containing only letters)
    do {
        std::cout << "What's your last name?" << std::endl;
        std::cin >> L_Name;
        cond = true;
        for (char c : L_Name) {
            if (!isalpha(c)) {
                std::cout << "Your last name should only contain letters." << std::endl;
                cond = false;
                break;
            }
        }
    } while (!cond);

    // Loop to get a valid gender (either 'M' or 'F')
    do {
        std::cout << "What's your gender?\nM/F: "<<std::endl;
        std::cin >> Gender;
        cond = true;
        // Check if the entered gender is valid
        if (Gender != 'M' && Gender != 'F') {
            std::cout << "Invalid gender. Please enter 'M' for male or 'F' for female." << std::endl;
            cond = false;
        }
    } while (!cond);

    int day,month,year;

    do {
        std::cout << "Enter a day > month > year: " << std::endl;
        std::cin >> day >> month >> year;

        // Validate the date using dateAuth from date.h
        if (!date::dateAuth(day, month, year)) {
            std::cout << "Your birth date is invalid." << std::endl;
            cond = false;
        } else {
            cond = true;
        }
    } while (!cond);

    do {
        std::cout << "Enter your Phone number: ";
        std::cin >> PhoneNumber;

        // Convert the phone number to a string for length and prefix validation
        std::string phoneNumberStr = std::to_string(PhoneNumber);

        if (phoneNumberStr.length() != 10 || phoneNumberStr.substr(0, 2) != "05") {
            std::cout << "Invalid phone number format. Please enter a 10-digit number starting with '05'." << std::endl;
            cond = false;
        } else {
            cond = true;
        }
    } while (!cond);

    this->ID = ID;
    this->Password = Password;
    this->F_Name = F_Name;
    this->L_Name = L_Name;
    this->Gender = Gender;
    //B_Date =
    this->PhoneNumber = PhoneNumber;
}
