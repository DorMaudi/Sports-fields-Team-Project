
#include "db.h"
#include "Auth.h"
#include "ui.h"

int main() {

    // make a new db.
    db dataBase;

    // load every user and field from the db.
    dataBase.init();

    return 0;
}