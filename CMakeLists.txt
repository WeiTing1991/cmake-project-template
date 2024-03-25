# root level of CMake
# cmake version
cmake_minimum_required(VERSION 3.15...3.29)

# project staement
project(
    cmake_template
    VERSION 0.1
    DESCRIPTION "A simple CMake project template"
    LANGUAGES CXX)
set(MODERN_CMAKE_BUILD_TESTING ON)

add_subdirectory(src)
add_subdirectory(app)
