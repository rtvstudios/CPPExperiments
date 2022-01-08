cmake_minimum_required(VERSION 3.10)

project(Ranges)

file (GLOB HEADERS CONFIGURE_DEPENDS "*.h")

set(SOURCES
    iterator_example.cpp
    view_example.cpp
    main.cpp)

add_executable(Ranges ${HEADERS} ${SOURCES})

createSTDModule(${CMAKE_CURRENT_BINARY_DIR} iostream)
createSTDModule(${CMAKE_CURRENT_BINARY_DIR} vector)
createSTDModule(${CMAKE_CURRENT_BINARY_DIR} ranges)
createSTDModule(${CMAKE_CURRENT_BINARY_DIR} initializer_list)
createSTDModule(${CMAKE_CURRENT_BINARY_DIR} iterator)

