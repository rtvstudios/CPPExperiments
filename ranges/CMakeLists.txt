cmake_minimum_required(VERSION 3.10)

project(Ranges)

file (GLOB SOURCES CONFIGURE_DEPENDS "*.cpp")
file (GLOB HEADERS CONFIGURE_DEPENDS "*.h")

add_executable(Ranges ${HEADERS} ${SOURCES})

createSTDModule(${CMAKE_CURRENT_BINARY_DIR} iostream)
createSTDModule(${CMAKE_CURRENT_BINARY_DIR} vector)
createSTDModule(${CMAKE_CURRENT_BINARY_DIR} ranges)
createSTDModule(${CMAKE_CURRENT_BINARY_DIR} initializer_list)
createSTDModule(${CMAKE_CURRENT_BINARY_DIR} iterator)

