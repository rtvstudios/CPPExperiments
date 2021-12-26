cmake_minimum_required(VERSION 3.10)

if(UNIX AND NOT APPLE)
	set(CMAKE_CXX_COMPILER g++-11)
endif()

project(CPPExperiments)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CUSTOM_LIBRARIES "")
set(CUSTOM_INCLUDES "")

set(CMAKE_CXX_FLAGS "-Werror")

add_subdirectory(concepts)

