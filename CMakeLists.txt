# Minimum version of CMake required to build this project
cmake_minimum_required(VERSION 3.0)

# Name of the project
project(SmallIntegers)

add_subdirectory(googletest)
add_subdirectory(benchmark)

# Add a library to this build. The name of the library is MyLibrary and it
# consists of only the MyLibrary.cpp file
add_executable(SmallIntegerTest src/SmallIntegerTest.cpp)
target_link_libraries(SmallIntegerTest benchmark::benchmark)

add_executable(UnrollTest src/UnrollTest.cpp)
target_link_libraries(UnrollTest benchmark::benchmark)
