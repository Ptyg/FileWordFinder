cmake_minimum_required(VERSION 3.0)

project(fileWordFinder LANGUAGES CXX)

add_executable(${POJECT_NAME} main.cpp)

target_include_directories(${POJECT_NAME} "./headers")