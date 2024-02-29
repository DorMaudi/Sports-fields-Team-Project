
#include "db.h"
#include "ui.h"

int main() {

    // make a new database.
    db dataBase;

    // load every user and field from the db.
    dataBase.init();

    // call main function.
    ui::mainFunction(dataBase);

    // save all to disk.
    dataBase.commitToDisk();

    return 0;
}