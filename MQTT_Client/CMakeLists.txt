cmake_minimum_required(VERSION 3.10)
project(MQTT_Client VERSION 0.1.0 DESCRIPTION "MQTT client library")
#set(CMAKE_CXX_STANDARD 11)
add_library(MQTT_Client SHARED src/MQTT_Client.cpp)
set_target_properties(MQTT_Client PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION 1
    PUBLIC_HEADER include/MQTT_Client.h 
    LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
target_include_directories(MQTT_Client PRIVATE .)

