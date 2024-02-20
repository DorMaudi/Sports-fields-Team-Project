#include "Auth.h"

#define ASCII_ZERO 48
#define ASCII_FIVE 53
#define ASCII_NINE 57
#define passlen 7

std::string formatDate(int day, int month, int year) {
    return std::to_string(day) + "/" + std::to_string(month) + "/" + std::to_string(year);
}


/*bool Auth::Register() {
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

    // Loop to get a valid Password (minimum length of 8 characters)
    do {
        std::cout << "Password: " << std::endl;
        std::cin >> Password;
        if (Password.size() < 8) {
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

        if ((int)phoneNumberStr[0] != ASCII_ZERO && (int)phoneNumberStr[1] != ASCII_FIVE)
        {
            std::cout << "bad number\n";
            continue;
        }
        else
        {
            for (int i = 2; i <= 9; ++i)
            {
                if ((int)phoneNumberStr[i] < ASCII_ZERO || (int)phoneNumberStr[i] > ASCII_NINE)
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
*/

bool Auth::idAuth(std::string &e, std::string ID) {
    // Check if the ID has 9 digits
    if (ID.size() != 9){
        e = "Your ID is not 9 Numbers";
        return false;
    }
    // Check if all characters in ID are digits
    for (char c : ID) {
        if (!isdigit(c)) {
            e = "ID should contain only numbers.";
            return false;
        }
    }
    //
    //
    // Add check for ID's in array to ensure no existing users with that ID
    //
    //
    return true;
}

bool Auth::passwordAuth (std::string& e, std::string password){
    // Check if password length meets the required length
    if (password.size() <= passlen) {
        e = "Your password should be longer than " + std::to_string(passlen+1) +" letters.";
        return false;
    }
    return true;
}

bool Auth::firstNameAuth(std::string& e, std::string name) {
    // Check if first name contains only alphabetic characters
    for (char c : name) {
        if (!isalpha(c)) {
            e = "Your first name should only contain letters.";
            return false;
        }
    }
    return true;
}

bool Auth::lastNameAuth(std::string& e, std::string name) {
    // Check if last name contains only alphabetic characters
    for (char c : name) {
        if (!isalpha(c)) {
            e = "Your last name should only contain letters.";
            return false;
        }
    }
    return true;
}

bool Auth::genderAuth(std::string &e, char gender) {
    // Check if gender is either 'M' or 'F'
    if (gender != 'M' && gender != 'F') {
        e = "Invalid gender. Please enter 'M' for male or 'F' for female.";
        return false;
    }
    return true;
}

bool Auth::dateAuth(std::string &e, int day, int month, int year) {
    // Check if the provided birth date is valid
    if (!date::dateAuth(day, month, year)) {
        e = "Your birth date is invalid.";
        return false;
    }
    return true;
}

bool Auth::phonenumberAuth(std::string& e, std::string phonenumber) {
    // Check if phone number starts with '05'
    if (phonenumber[0] != '0' || phonenumber[1] != '5') {
        e = "Phone number should start with '05'";
        return false;
    }

    // Check if phone number length is at least 10
    if (phonenumber.size() < 10) {
        e = "Phone number is too short";
        return false;
    }

    // Check if all characters in the phone number are digits
    for (size_t i = 2; i < phonenumber.size(); ++i) {
        if (!isdigit(phonenumber[i])) {
            e = "Phone number should contain only digits";
            return false;
        }
    }

    return true;
}

bool Auth::login(const std::string ID, const std::string Password, std::string &Message, db database)
{
    auto personArr = database.getPersonArr();
    int personArrSize = database.getNumOfUsers();
    for (int i = 0; i < personArrSize; ++i) {
        if (personArr[i]->getID() == ID)
            if (personArr[i]->getPassword() == Password) {
                return true;
            }else {
                Message = "Password is incorrect";
                return false;
            }
    }
    Message = "User not found";
    return false;
}


