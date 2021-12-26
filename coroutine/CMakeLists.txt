cmake_minimum_required(VERSION 3.10)

project(Coroutine)

file (GLOB SOURCES CONFIGURE_DEPENDS "*.cpp")
file (GLOB HEADERS CONFIGURE_DEPENDS "*.h")

add_executable(Coroutine ${HEADERS} ${SOURCES})

