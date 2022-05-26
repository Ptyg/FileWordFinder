cmake_minimum_required(VERSION 3.0)

set(SourcesTxt
    test_txt.cpp
)

set(SourcesXml
    test_xml.cpp
)

add_executable(TestTxts ${SourcesTxt})
target_link_libraries(TestTxts PUBLIC 
    gtest_main
    fileWordFinder_lib
)

add_executable(TestXmls ${SourcesXml})
target_link_libraries(TestXmls PUBLIC 
    gtest_main
    fileWordFinder_lib
)

add_test(
    TxtTest TestTxts
)

add_test(
    XmlTest TestXmls
)