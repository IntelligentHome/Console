
set(CMAKE_SYSTEM_NAME Generic)
cmake_minimum_required(VERSION 2.8)

project(Console)

include (../External/PlatformDependency.cmake)

set(SOURCES
    Console.cpp
    )

include_directories(
    ../External/include/
    )

add_library(${PROJECT_NAME} STATIC ${SOURCES})
