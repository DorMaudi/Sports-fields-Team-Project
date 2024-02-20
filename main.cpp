
#include "db.h"
#include "Auth.h"

int main() {

    // make a new db.
    db dataBase;

    // load every user and field from the db.
    dataBase.init();
    Auth user;
    user.Register();
    

    return 0;
}