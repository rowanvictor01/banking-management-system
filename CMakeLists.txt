cmake_minimum_required(VERSION 3.10)
project(Banking-Management-System C)

# Set C Standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Collect all source files
file(GLOB SOURCES "src/*.c")

# Create executable
add_executable(bankc ${SOURCES})

# Add include directory
target_include_directories(bankc PRIVATE ${CMAKE_SOURCE_DIR}/include)

# Set output directory
set_target_properties(bankc PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
