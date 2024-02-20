#include "Auth.h"

#define ASCI_ZERO 48
#define ASCI_FIVE 53
#define ASCI_NINE 57

std::string formatDate(int day, int month, int year) {
    return std::to_string(day) + "/" + std::to_string(month) + "/" + std::to_string(year);
}


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

    int phoneNum;
    do {

        cond = false;
        std::string phoneNumberStr;
        std::cout << "Enter your Phone number: ";
        std::cin >> phoneNumberStr;

        if ((int)phoneNumberStr[0] != ASCI_ZERO && (int)phoneNumberStr[1] != ASCI_FIVE)
        {
            std::cout << "bad number\n";
            continue;
        }
        else
        {
            for (int i = 2; i <= 9; ++i)
            {
                if ((int)phoneNumberStr[i] < ASCI_ZERO || (int)phoneNumberStr[i] > ASCI_NINE)
                {
                    std::cout << "bad phone number\n";
                    continue;
                }
            }
            cond = true;
        }


    } while (!cond);

    this->ID = ID;
    this->Password = Password;
    this->F_Name = F_Name;
    this->L_Name = L_Name;
    this->Gender = Gender;
    this->B_Date= formatDate(day,month,year);
    this->PhoneNumber = PhoneNumber;
    //dbMakeUser()
}
