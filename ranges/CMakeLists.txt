cmake_minimum_required(VERSION 3.10)

project(Ranges)

file (GLOB SOURCES CONFIGURE_DEPENDS "*.cpp")
file (GLOB HEADERS CONFIGURE_DEPENDS "*.h")

add_executable(Ranges ${HEADERS} ${SOURCES})

