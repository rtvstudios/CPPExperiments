cmake_minimum_required(VERSION 3.10)

if(UNIX AND NOT APPLE)
	add_compile_options(-fmodules-ts)
endif()

project(Module)

file (GLOB HEADERS CONFIGURE_DEPENDS "*.h")

add_executable(Module ${HEADERS} shape.cpp main.cpp)

createSTDModules(${CMAKE_CURRENT_BINARY_DIR})

