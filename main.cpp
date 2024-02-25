
#include "db.h"
#include "Auth.h"
#include "ui.h"

int main() {

    // make a new database.
    db dataBase;

    // load every user and field from the db.
    dataBase.init();


    // save all to disk.
    dataBase.commitToDisk();
    return 0;
}