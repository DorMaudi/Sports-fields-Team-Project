
#include "db.h"
#include "Auth.h"
#include "ui.h"

int main() {

    // make a new database.
    //db dataBase;

    // load every user and field from the db.
    //dataBase.init();

    // save all to disk.
    //dataBase.commitToDisk();


    std::vector<date> x;
    ui::makeCalender(x);

    for (auto i : x)
    {
        std::cout << i.getDay() << '/' << i.getMonth() << '/' << i.getYear() << '\n';
    }

    return 0;
}