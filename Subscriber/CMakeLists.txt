cmake_minimum_required(VERSION 3.10)
project(Subscriber VERSION 1.0.0 DESCRIPTION "Subscriber")

file(GLOB CPP_FILES src/*.cpp)

add_definitions(${DataStore_DEFINITIONS})
add_definitions(${MQTT_Client_DEFINITIONS})

include_directories(${DataStore_INCLUDE_DIRS})
include_directories(${MQTT_Client_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} ${CPP_FILES})

target_link_libraries(${PROJECT_NAME} MQTT_Client DataStore)
