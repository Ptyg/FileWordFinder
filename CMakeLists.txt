cmake_minimum_required(VERSION 3.13.4)

project(fileWordFinder VERSION 1.0.1 DESCRIPTION "help to find word in txt files from dir and object where word is stored")
set(CMAKE_CXX_STANDARD 17)

set(LIB_SRC 
    lib_src/FileAbstract.cpp
    lib_src/FileTxt.cpp
    lib_src/FileXml.cpp
    lib_src/getDirectoryFiles.cpp
    lib_src/getNotAllDirectoryFiles.cpp
    lib_src/outResultBase.cpp
    lib_src/outResultXml.cpp
)



# compile the library
add_library(${PROJECT_NAME}_lib STATIC ${LIB_SRC})
target_include_directories(${PROJECT_NAME}_lib PUBLIC ${PROJECT_SOURCE_DIR}/lib_include)

enable_testing()

add_subdirectory(googletest)
add_subdirectory(tests)

# compile the app
add_executable(${PROJECT_NAME} app/app.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/lib_include)
target_link_libraries(${PROJECT_NAME} PRIVATE ${PROJECT_NAME}_lib)


