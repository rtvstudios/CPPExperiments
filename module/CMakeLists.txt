cmake_minimum_required(VERSION 3.10)

project(Module)

file (GLOB HEADERS CONFIGURE_DEPENDS "*.h")

add_executable(Module ${HEADERS} shape.cpp main.cpp)

createSTDModules(${CMAKE_CURRENT_BINARY_DIR})

