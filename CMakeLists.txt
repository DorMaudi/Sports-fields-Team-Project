cmake_minimum_required(VERSION 3.27)
project(Sports_fields_Team_Project)

set(CMAKE_CXX_STANDARD 20)

include_directories(dataBase)

add_executable(Sports_fields_Team_Project main.cpp
        dataBase/db.cpp
        dataBase/db.h)
