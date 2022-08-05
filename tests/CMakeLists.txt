cmake_minimum_required(VERSION 3.0)

set(TxtTestsSource test_txt.cpp)

add_executable(TestTxtAllMethods ${TxtTestsSource})
target_link_libraries(TestTxtAllMethods PUBLIC 
    gtest_main
    fileWordFinder_lib
)

add_test(TxtClassTest TestTxtAllMethods)