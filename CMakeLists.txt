cmake_minimum_required(VERSION 3.26.4)
project(Sports_fields_Team_Project)

set(CMAKE_CXX_STANDARD 20)

include_directories(dataBase , Auth)

add_executable(Sports_fields_Team_Project main.cpp
        dataBase/db.cpp
        dataBase/db.h
        Auth/Auth.cpp
        Auth/Auth.h
        Auth/date.cpp
        Auth/date.h)
