cmake_minimum_required(VERSION 3.10)

include(function.cmake)

if(UNIX AND NOT APPLE)
	set(CMAKE_CXX_COMPILER g++-11)
	add_compile_options(-fmodules-ts)
endif()

project(CPPExperiments)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CUSTOM_LIBRARIES "")
set(CUSTOM_INCLUDES "")

set(CMAKE_CXX_FLAGS "-Werror")

add_subdirectory(concepts)
add_subdirectory(3-way)
add_subdirectory(coroutine)
add_subdirectory(module)
add_subdirectory(ranges)

