cmake_minimum_required(VERSION 3.25.1)

project(fileWordFinder VERSION 1.2.0 DESCRIPTION "help to find word in txt files from dir and object where word is stored")
set(CMAKE_CXX_STANDARD 20)

# compile the library
set(LIB_HDRS
    lib_include/FileAbstract.hpp
    lib_include/FileTxt.hpp
    lib_include/FileXml.hpp
    lib_include/getDirectoryFiles.hpp
    lib_include/Log.hpp
    lib_include/outResultBase.hpp
    lib_include/outResultXml.hpp
)

set(LIB_SRC 
    lib_src/FileTxt.cpp
    lib_src/FileXml.cpp
    lib_src/Log.cpp
)
add_library(${PROJECT_NAME}_lib STATIC ${LIB_SRC} ${LIB_HDRS})
target_include_directories(${PROJECT_NAME}_lib PUBLIC ${PROJECT_SOURCE_DIR}/lib_include)

# compile the app
add_executable(${PROJECT_NAME} app/app.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/lib_include)

# link lib
target_link_libraries(${PROJECT_NAME} PRIVATE ${PROJECT_NAME}_lib)


