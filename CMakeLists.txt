cmake_minimum_required(VERSION 3.28)

project(library)

# Set C++ standard globally
set(CMAKE_CXX_STANDARD 26)

# Enable the generation of the compile_commands.json file
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Adds include directories globally
include_directories("inc")

# Recursively find all .cpp files
file(GLOB_RECURSE CPP_SOURCES "src/*.cpp")

foreach(SOURCE_FILE ${CPP_SOURCES})
    # Get the relative path of SOURCE_FILE from the src directory
    file(RELATIVE_PATH SOURCE_REL_PATH "${CMAKE_CURRENT_SOURCE_DIR}/src" "${SOURCE_FILE}")

    # Replace all forward slashes in the relative path with dot
    string(REPLACE "/" "." UNIQUE_NAME "${SOURCE_REL_PATH}")

    # Remove the file extension to get a valid target name
    string(REGEX REPLACE "(.main)?(.test)?.cpp" "" TARGET_NAME "${UNIQUE_NAME}")

    # Create an executable for each source file
    add_executable(${TARGET_NAME} ${SOURCE_FILE})

endforeach()
