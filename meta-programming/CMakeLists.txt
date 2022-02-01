cmake_minimum_required(VERSION 3.10)

project(Meta-programming)

file (GLOB HEADERS CONFIGURE_DEPENDS "*.h")

set(SOURCES
    main.cpp)

add_executable(Meta-programming ${HEADERS} ${SOURCES})

createSTDModule(${CMAKE_CURRENT_BINARY_DIR} iostream)
createSTDModule(${CMAKE_CURRENT_BINARY_DIR} initializer_list)

