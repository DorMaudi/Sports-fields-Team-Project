
#include "db.h"
#include "Auth.h"
#include "ui.h"

int main() {

    // make a new database.
    db dataBase;

    // load every user and field from the db.
    dataBase.init();

    setColor(C_GREEN);
    std::cout << "Hii\n";
    setColor(C_WHITE);
    std::cout << "Hii\n";

    return 0;
}