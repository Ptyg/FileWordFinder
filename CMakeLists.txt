cmake_minimum_required(VERSION 3.13.4)

project(fileWordFinder VERSION 2.0.0 DESCRIPTION "help to find word in txt files from dir and object where word is stored")
set(CMAKE_CXX_STANDARD 17)
set(DO_TEST FALSE)
add_compile_options(
    -Wall
)

set(LIB_SRC 
    lib_src/FileAbstract.cpp
    lib_src/FileTxt.cpp
    lib_src/FileXml.cpp
)

# compile the library
add_library(${PROJECT_NAME}_lib STATIC ${LIB_SRC})
target_include_directories(${PROJECT_NAME}_lib PUBLIC ${PROJECT_SOURCE_DIR}/lib_include)

if (DO_TEST)
    enable_testing()
    add_subdirectory(googletest)
    add_subdirectory(tests)
endif(DO_TEST)

# compile the app
add_executable(${PROJECT_NAME} app/app.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/lib_include)
target_link_libraries(${PROJECT_NAME} PRIVATE ${PROJECT_NAME}_lib)


