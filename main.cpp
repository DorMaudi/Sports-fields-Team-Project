
#include "db.h"
#include "Auth.h"

int main() {

    // make a new database.
    db dataBase;

    // load every user and field from the db.
    dataBase.init();
    std::string e="05589a1102";
    Auth a;
    a.phonenumberAuth(e,e);
    std::cout<<e;

    return 0;
}