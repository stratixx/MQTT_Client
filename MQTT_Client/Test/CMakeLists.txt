cmake_minimum_required(VERSION 3.1.0)
set(CMAKE_CXX_STANDARD 11)

project(Test1 VERSION 1.0.0 DESCRIPTION "Test1")

#Setup CMake to run tests
enable_testing()

#boost setup
set(Boost_USE_STATIC_LIBS TRUE)
find_package( Boost REQUIRED COMPONENTS thread  unit_test_framework  )
# windows options
if (WIN32)
	set(BOOST_LIBRARYDIR ${Boost_INCLUDE_DIRS}/lib32-msvc-14.1)
endif ()
include_directories(${Boost_INCLUDE_DIRS})
message(STATUS "boost libs: ${Boost_LIBRARIES}")
message(STATUS "boost inc: ${Boost_INCLUDE_DIRS}")

#project dependency 
include_directories(${DataStore_INCLUDE_DIRS})
include_directories(${MQTT_Client_INCLUDE_DIRS})


file(GLOB CPP_FILES src/*.cpp)

foreach(testFile IN ITEMS ${CPP_FILES})
    get_filename_component(testName ${testFile} NAME_WE)
    add_executable(${testName} ${testFile})

    target_link_libraries(${testName} MQTT_Client ${Boost_LIBRARIES})

    add_test(NAME ${testName} COMMAND ${testName})

endforeach()