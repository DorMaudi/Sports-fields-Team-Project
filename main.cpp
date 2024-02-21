#include "db.h"
#include "Auth.h"
#include <iostream> // Include for std::cout

int main() {
    // make a new database.
    db dataBase;

    // load every user and field from the db.
    dataBase.init();
    Auth a;
    std::string userID = "208060111\n"; // Remove '\n'
    std::string password = "abc123789\n"; // Remove '\n'
    std::string message;

    /*if(Auth::login(userID,password,message,dataBase)){
        std::cout<<"kaki\n";
    }*/
    auto personArr = dataBase.getPersonArr();
    int personArrSize = dataBase.getNumOfUsers();
    for (int i = 0; i < personArrSize; ++i) {
        if (personArr[i]->getID() == userID) {
            if (personArr[i]->getPassword() == password) {
                message = "Successful login";
                break; // Found the user, exit the loop
            } else {
                message = "Password is incorrect";
                break; // Found the user, exit the loop
            }
        }
    }

    std::cout << message << std::endl; // Output the result
    return 0; // Return 0 to indicate successful execution
}
