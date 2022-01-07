cmake_minimum_required(VERSION 3.10)

project(Module)

file (GLOB HEADERS CONFIGURE_DEPENDS "*.h")

add_executable(Module ${HEADERS} shape.cpp main.cpp)

createSTDModule(${CMAKE_CURRENT_BINARY_DIR} string)
createSTDModule(${CMAKE_CURRENT_BINARY_DIR} memory)
createSTDModule(${CMAKE_CURRENT_BINARY_DIR} iostream)

