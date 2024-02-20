
#include "db.h"
#include "Auth.h"

int main() {

    // make a new database.
    db dataBase;

    // load every user and field from the db.
    dataBase.init();
    Auth a;
    std::string userID = "208060111";
    std::string password = "abc123";
    std::string message;

    // Call the login function
    bool loggedIn = a.login(userID, password, message, dataBase);
    std::cout <<message;
    return 0;
}