cmake_minimum_required(VERSION 3.29)

# This is your project statement. You should always list languages;
# Listing the version is nice here since it sets lots of useful variables
project(
  cmake_template
  VERSION 1.0
  LANGUAGES CXX)


add_subdirectory(src)
add_subdirectory(app)
