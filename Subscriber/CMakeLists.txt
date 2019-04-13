cmake_minimum_required(VERSION 3.1.0)
set(CMAKE_CXX_STANDARD 11)

project(Subscriber VERSION 1.0.0 DESCRIPTION "Subscriber")

# windows options
if (WIN32)
	#boost setup
	set(Boost_USE_STATIC_LIBS TRUE)
	find_package( Boost REQUIRED COMPONENTS thread    )
	set(BOOST_LIBRARYDIR ${Boost_INCLUDE_DIRS}/lib32-msvc-14.1)
	include_directories(${Boost_INCLUDE_DIRS})
endif ()
message(STATUS "boost libs: ${Boost_LIBRARIES}")
message(STATUS "boost inc: ${Boost_INCLUDE_DIRS}")

#project dependency 
include_directories(${DataStore_INCLUDE_DIRS})
include_directories(${MQTT_Client_INCLUDE_DIRS})


file(GLOB CPP_FILES src/*.cpp)
add_executable(${PROJECT_NAME} ${CPP_FILES})

target_link_libraries(${PROJECT_NAME} MQTT_Client DataStore ${Boost_LIBRARIES})
