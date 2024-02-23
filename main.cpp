#include "db.h"
#include "Auth.h"
#include <iostream> // Include for std::cout

int main() {
    // make a new database.
    db dataBase;

    // load every user and field from the db.
    dataBase.init();

    return 0; // Return 0 to indicate successful execution
}
