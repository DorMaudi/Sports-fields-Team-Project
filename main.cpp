
#include "db.h"
#include "Auth.h"
#include "ui.h"

int main() {

    // make a new database.
    db dataBase;

    // load every user and field from the db.
    dataBase.init();

    std::string x = "123456789";
    dataBase.dbDelUser(x);

    std::string ID = "123456789";
    std::string password = "1598745";
    std::string f_name = "david";
    std::string l_name = "kof";
    std::string phoneNumber = "054477784";
    char gender = 'F';

    dataBase.dbMakeUser(DB_USER_TYPE_PLAYER, ID, password, f_name, l_name, phoneNumber, gender);

    // save all to disk.
    dataBase.commitToDisk();
    return 0;
}