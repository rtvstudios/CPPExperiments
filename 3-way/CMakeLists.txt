cmake_minimum_required(VERSION 3.10)

project(3-Way)

file (GLOB SOURCES CONFIGURE_DEPENDS "*.cpp")
file (GLOB HEADERS CONFIGURE_DEPENDS "*.h")

add_executable(3-Way ${HEADERS} ${SOURCES})

