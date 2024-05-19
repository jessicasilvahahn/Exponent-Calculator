cmake_minimum_required(VERSION 3.5)
 
# Locate GTest
find_package(GTest REQUIRED)
find_package (Threads REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Link runTests with what we want to test and the GTest and pthread library
add_executable(runUnitTests ./tests/unit/tests.cpp exponentCalculator.cpp)
target_link_libraries(runUnitTests ${GTEST_LIBRARIES} pthread)