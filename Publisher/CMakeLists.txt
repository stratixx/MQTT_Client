cmake_minimum_required(VERSION 3.10)
project(Publisher VERSION 1.0.0 DESCRIPTION "Publisher")
#set(CMAKE_CXX_STANDARD 11)
#find_package( Boost REQUIRED COMPONENTS program_options regex )
INCLUDE_DIRECTORIES(../MQTT_Client/include ../DataStore/include)
LINK_DIRECTORIES(../MQTT_Client/lib ../DataStore/lib)
add_executable(${PROJECT_NAME} src/${PROJECT_NAME}.cpp)
#target_link_libraries(${PROJECT_NAME} ${Boost_REGEX_LIBRARY})
target_link_libraries(${PROJECT_NAME} MQTT_Client DataStore)
set (EXECUTABLE_OUTPUT_PATH bin)



# Remove 'lib' prefix for shared libraries on Windows
#if (WIN32)
#  set(CMAKE_SHARED_LIBRARY_PREFIX "")
#endif ()
