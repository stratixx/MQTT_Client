cmake_minimum_required(VERSION 3.1.0)
set(CMAKE_CXX_STANDARD 11)

project(Publisher VERSION 1.0.0 DESCRIPTION "Publisher")

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
add_executable(${PROJECT_NAME} ${CPP_FILES})

target_link_libraries(${PROJECT_NAME} MQTT_Client DataStore ${Boost_LIBRARIES})

#Setup CMake to run tests
include(CTest)
enable_testing()
file(GLOB TEST_FILES test/*.cpp)
set(BUILD_TESTING true)

foreach(testFile IN ITEMS ${TEST_FILES})
    get_filename_component(testName ${testFile} NAME_WE)
    add_executable(${testName} ${testFile})

    target_include_directories(${testName} PRIVATE ${Boost_INCLUDE_DIRS})

    target_link_libraries(${testName} MQTT_Client ${Boost_LIBRARIES})

    set_target_properties(${testName} PROPERTIES 
            RUNTIME_OUTPUT_DIRECTORY  testBin)
            
    add_test(NAME ${testName} COMMAND ${testName})

endforeach()