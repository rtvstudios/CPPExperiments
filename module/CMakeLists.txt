cmake_minimum_required(VERSION 3.10)

project(Module)

file (GLOB HEADERS CONFIGURE_DEPENDS "*.h")

set(SOURCES
    shape.cpp
    main.cpp)

add_executable(Module ${HEADERS} ${SOURCES})

createSTDModule(${CMAKE_CURRENT_BINARY_DIR} string)
createSTDModule(${CMAKE_CURRENT_BINARY_DIR} memory)
createSTDModule(${CMAKE_CURRENT_BINARY_DIR} iostream)

