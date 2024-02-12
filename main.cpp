//
// Created by Dor Maudi on 11/02/2024.
//

#include "db.h"

int main() {

    // make a new db.
    db dataBase(R"(C:\Users\dorma\Documents\gitProjects\Sports-fields-Team-Project\dataBase\users)",
                R"(C:\Users\dorma\Documents\gitProjects\Sports-fields-Team-Project\dataBase\fields)");


    // load every user and field from the db.
    dataBase.init();

    return 0;
}