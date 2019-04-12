cmake_minimum_required(VERSION 2.8.10)

# Remove 'lib' prefix for shared libraries on Windows
if (WIN32)
  set(CMAKE_SHARED_LIBRARY_PREFIX "")
endif ()

add_subdirectory(DataStore)
add_subdirectory(MQTT_Client) 
add_subdirectory(Publisher) 
add_subdirectory(Subscriber) 
