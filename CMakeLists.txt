cmake_minimum_required(VERSION 3.29.1)

project(cmake_template VERSION 1.0 LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_TOOLCHAIN_FILE ./VCPKG/vcpkg/scripts/buildsystems/vcpkg.cmake)
set(CMAKE_CXX_STANDARD 17)

# check the operating system, and set the vcpkg target triplet accordingly
if (WIN32)
    message("Configuring for windows")
    set(VCPKG_TARGET_TRIPLET "x64-windows" CACHE STRING "")
endif()
if (UNIX AND NOT APPLE)
    message("Configuring for linux")
    set(VCPKG_TARGET_TRIPLET "x64-linux" CACHE STRING "")
endif()
if (APPLE)

    message("Configuring for apple")
    set(VCPKG_TARGET_TRIPLET "x64-osx" CACHE STRING "" )
endif()

set(REQUIRE_PACKAGE
    glfw3
    glad
)
# Define the path to the vcpkg executable
set(VCPKG_EXECUTABLE "${CMAKE_SOURCE_DIR}/VCPKG/vcpkg")

# Run vcpkg install command
execute_process(
    COMMAND ${VCPKG_EXECUTABLE} install
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/VCPKG
    RESULT_VARIABLE VCPKG_INSTALL_RESULT
)

# Check the result of the installation
if(VCPKG_INSTALL_RESULT)
    message(FATAL_ERROR "Failed to install dependencies with Vcpkg.")
endif()

add_executable(${PROJECT_NAME} src/main.cpp)

# set(INSTALLED_DIR ./vcpkg_installed/arm64-osx/share)
# set(glad_DIR ${INSTALLED_DIR}/glad)
# set(glfw3_DIR ${INSTALLED_DIR}/glfw3)

foreach(PACKAGE ${REQUIRE_PACKAGE})
    find_package(${PACKAGE} CONFIG REQUIRED)
endforeach()

find_package(OpenGL REQUIRED)
#find_package(glad CONFIG REQUIRED)
#find_package(glfw3 CONFIG REQUIRED)

target_link_libraries(${PROJECT_NAME} PRIVATE
    glfw
    glad::glad
    OpenGL::GL
)













