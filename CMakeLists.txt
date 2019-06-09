cmake_minimum_required(VERSION 3.1.0)

#stworzenie projektu
project(MQTT_Sniffer VERSION 1.0.0 DESCRIPTION "MQTT Sniffer project")

#składowe projektu
add_subdirectory(DataStore)
add_subdirectory(MQTT_Client) 
add_subdirectory(Publisher) 
add_subdirectory(Subscriber) 
add_subdirectory(paho.mqtt.c) 





#include(${CMAKE_ROOT}/Modules/ExternalProject.cmake)

#ExternalProject_add(
#paho
#DEPENDS libressl
#GIT_REPOSITORY "https://github.com/eclipse/paho.mqtt.c.git"
#GIT_TAG "master"
#UPDATE_COMMAND ""
#PATCH_COMMAND ""
#SOURCE_DIR "${CMAKE_BINARY_DIR}/paho_sourcedir"
#CMAKE_ARGS -DPAHO_WITH_SSL=FALSE -DOPENSSL_INC_SEARCH_PATH=${CMAKE_BINARY_DIR}/include -DOPENSSL_LIB_SEARCH_PATH=${CMAKE_BINARY_DIR}/lib -DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR}/paho_prefix
#)