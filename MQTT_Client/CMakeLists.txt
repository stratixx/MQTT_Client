cmake_minimum_required(VERSION 3.1.0)
set(CMAKE_CXX_STANDARD 11)


project(MQTT_Client VERSION 1.0.0 DESCRIPTION "MQTT Client library")

set(Boost_USE_STATIC_LIBS TRUE)
find_package( Boost REQUIRED COMPONENTS thread  unit_test_framework  )

file(GLOB CPP_FILES src/*.cpp)

add_library(${PROJECT_NAME} STATIC ${CPP_FILES})

set_target_properties(${PROJECT_NAME} PROPERTIES
    VERSION ${PROJECT_VERSION}
    PUBLIC_HEADER include/${PROJECT_NAME}.h 
    POSITION_INDEPENDENT_CODE ON)

if (WIN32)
    target_link_libraries(${PROJECT_NAME} wsock32 paho-mqtt3c-static )
else(WIN32)
    target_link_libraries(${PROJECT_NAME}   ) #tu wpisz biblioteke do socketow na Linux
endif ()

target_include_directories(${PROJECT_NAME} PUBLIC ${Boost_INCLUDE_DIRS} paho.mqtt.c/src )


# Expose PROJECT definitions 
# to other subprojects through cache variable.
set(${PROJECT_NAME}_DEFINITIONS ${XXX_DEFINITIONS}
    CACHE INTERNAL "${PROJECT_NAME}: Definitions" FORCE)

# Expose PROJECT public includes to other
# subprojects through cache variable.
set(${PROJECT_NAME}_INCLUDE_DIRS ${PROJECT_SOURCE_DIR}/include
                                 ${Boost_INCLUDE_DIRS}
    CACHE INTERNAL "${PROJECT_NAME}: Include Directories" FORCE)



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