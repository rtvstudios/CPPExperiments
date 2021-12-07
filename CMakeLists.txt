cmake_minimum_required(VERSION 3.10)

project(CPPExperiments)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CUSTOM_LIBRARIES "")
set(CUSTOM_INCLUDES "")

set(CMAKE_CXX_FLAGS "-Werror")

add_subdirectory(concepts)

