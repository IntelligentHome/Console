
set(CMAKE_SYSTEM_NAME Generic)
cmake_minimum_required(VERSION 2.8)

project(Console)

include (../External/PlatformDependency.cmake)

if (${_TARGET_PLATFORM} STREQUAL "AVR")

    set (SOURCES
        ConsoleAvr.cpp
        )
elseif (${_TARGET_PLATFORM} STREQUAL "RASPBERRYPI")

    set (SOURCES
        ConsoleRpi.cpp
        )
endif()

message (STATUS "_TARGET_PLATFORM = ${_TARGET_PLATFORM}")
message (STATUS "CMAKE_CXX_COMPILER + ${CMAKE_CXX_COMPILER}")
message (STATUS "SOURCES-Console = ${SOURCES}")

include_directories(
    ../External/include/
    )

add_library(${PROJECT_NAME} STATIC ${SOURCES})
