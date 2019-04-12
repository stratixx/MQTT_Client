cmake_minimum_required(VERSION 3.10)

project(MQTT_Client VERSION 1.0.0 DESCRIPTION "MQTT Client library")

#find_package( Boost 1.50.0 REQUIRED )

file(GLOB CPP_FILES src/*.cpp)

add_library(${PROJECT_NAME} STATIC ${CPP_FILES})

set_target_properties(${PROJECT_NAME} PROPERTIES
    VERSION ${PROJECT_VERSION}
    PUBLIC_HEADER include/${PROJECT_NAME}.h 
    POSITION_INDEPENDENT_CODE ON)

target_link_libraries(${PROJECT_NAME})

# Expose PROJECT definitions 
# to other subprojects through cache variable.
set(${PROJECT_NAME}_DEFINITIONS ${XXX_DEFINITIONS}
    CACHE INTERNAL "${PROJECT_NAME}: Definitions" FORCE)

# Expose PROJECT public includes to other
# subprojects through cache variable.
set(${PROJECT_NAME}_INCLUDE_DIRS ${PROJECT_SOURCE_DIR}/include
                                 ${Boost_INCLUDE_DIRS}
    CACHE INTERNAL "${PROJECT_NAME}: Include Directories" FORCE)
