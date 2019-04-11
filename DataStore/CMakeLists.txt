cmake_minimum_required(VERSION 3.10)
project(DataStore VERSION 1.0.0 DESCRIPTION "Data store library")
#set(CMAKE_CXX_STANDARD 11)
add_library(${PROJECT_NAME} SHARED src/${PROJECT_NAME}.cpp)
set_target_properties(${PROJECT_NAME} PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION 1
    PUBLIC_HEADER include/${PROJECT_NAME}.h 
    LIBRARY_OUTPUT_DIRECTORY lib)
target_include_directories(${PROJECT_NAME} PRIVATE .)

