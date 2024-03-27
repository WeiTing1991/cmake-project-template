# Add the include directory to the search path for include files
include_directories(${PROJECT_SOURCE_DIR}/include)

# Add the source files in the src directory to the build
add_executable(MyApp ${PROJECT_SOURCE_DIR}/src/main.cpp)

# Link any necessary libraries
#target_link_libraries(MyApp MyLibrary)
