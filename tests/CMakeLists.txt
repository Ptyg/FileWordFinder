cmake_minimum_required(VERSION 3.0)

set(This Test)

set(Sources
    test.cpp
)

add_executable(${This} ${Sources})
target_link_libraries(${This} PUBLIC 
    gtest_main
    fileWordFinder_lib
)

add_test(
    NAME ${This}
    COMMAND ${This} 
)