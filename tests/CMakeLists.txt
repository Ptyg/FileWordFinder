cmake_minimum_required(VERSION 3.0)

set(TxtTestsSource test_txt.cpp)
set(XmlTestsSource test_xml.cpp)

add_executable(TestTxtAllMethods ${TxtTestsSource})
add_executable(TestXmlAllMethods ${XmlTestsSource})

target_link_libraries(TestTxtAllMethods PUBLIC 
    gtest_main
    fileWordFinder_lib
)


target_link_libraries(TestXmlAllMethods PUBLIC 
    gtest_main
    fileWordFinder_lib
)

add_test(XmlClassTest TestXmlAllMethods)
add_test(TxtClassTest TestTxtAllMethods)