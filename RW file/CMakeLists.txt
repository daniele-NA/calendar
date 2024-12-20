cmake_minimum_required(VERSION 3.28)
project(ProvaStringhe)

set(CMAKE_CXX_STANDARD 17)

add_executable(ProvaStringhe main.cpp
        beckend/database.h
        beckend/file-management.h)
