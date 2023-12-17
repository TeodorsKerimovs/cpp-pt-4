# From Teo. Cmake implementation based on:
# https://cmake.org/cmake/help/latest/guide/tutorial/index.html
# https://github.com/Kitware/CMake/tree/master/Help/guide/tutorial
# for unit tests https://www.youtube.com/watch?v=Lp1ifh9TuFI


cmake_minimum_required(VERSION 3.10)
set(This cpp-pt-4)
project(${This} C CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

option(BUILD_RAYTRACER "BUILD_RAYTRACER" ON)
option(BUILD_TESTS "BUILD_TESTS")

# Use the option in an if statement
if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
    add_subdirectory(tests/googletest)
endif()

 # Add all .c, - files under src/ directory
 file(GLOB SOURCES_C "src/*.c")
 # Add all .cpp, - files under src/ directory
 file(GLOB SOURCES_CPP "src/*.cpp")
 # Add all .hpp, - files under src/ directory
 file(GLOB HEADERS_HPP "src/*.hpp")
 # Add all .h, - files under src/ directory
 file(GLOB HEADERS_H "src/*.h")

 set(SOURCES ${SOURCES_C} ${SOURCES_CPP})
 set(HEADERS ${HEADERS_H} ${HEADERS_HPP})

add_library(${This} STATIC ${SOURCES} ${HEADERS})

if(BUILD_RAYTRACER)
    set(EXECUTABLE_NAME This)
    add_executable(${EXECUTABLE_NAME} ${SOURCES} ${HEADERS})
    set_target_properties(${EXECUTABLE_NAME} PROPERTIES OUTPUT_NAME "run_raytracer")
endif()



set(CMAKE_BUILD_TYPE Debug)








