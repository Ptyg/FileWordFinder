cmake_minimum_required(VERSION 3.0)

project(fileWordFinder VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
include_directories("./include")
file(GLOB CPP_SOURCES "src/*.cpp")

add_compile_options(
    -Wall
)

if(NOT CMAKE_CXX_EXTENSIONS)
    set(CMAKE_CXX_EXTENSIONS OFF)
endif()

add_executable(
    file_word_finder 
    ${CPP_SOURCES}
)