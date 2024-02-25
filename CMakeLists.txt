cmake_minimum_required(VERSION 3.27)
project(Sports_fields_Team_Project)

set(CMAKE_CXX_STANDARD 20)

include_directories(dataBase Auth person ui fields)

add_executable(Sports_fields_Team_Project main.cpp
        dataBase/db.cpp
        dataBase/db.h
        Auth/Auth.cpp
        Auth/Auth.h
        Auth/date.cpp
        Auth/date.h
        person/Manager.cpp
        person/Manager.h
        ui/ui.cpp
        ui/ui.h
        person/Player.cpp
        person/Player.h
        person/Person.cpp
        person/Person.h
        fields/fields.h
        fields/fields.cpp
        fields/reservation.h
        fields/reservation.cpp
)