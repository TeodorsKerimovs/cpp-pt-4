cmake_minimum_required(VERSION 3.10)

set(This ptts)

 # Add all .cpp, - files under src/ directory
 file(GLOB SOURCES_CPP "./*.cpp")

 set(SOURCES ${SOURCES_CPP})

 add_executable(${This} ${SOURCES})
 set_target_properties(${This} PROPERTIES OUTPUT_NAME "run_unit_tests")
 target_link_libraries(${This} PUBLIC
     gtest_main
     cpp-pt-4
 )

add_test(
    NAME ${This}
    COMMAND ${This}
)