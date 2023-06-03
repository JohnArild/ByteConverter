cmake_minimum_required(VERSION 3.10)

# Set the project name
project(byteconverter)

# Set C++ standard
set(CMAKE_CXX_STANDARD 14)

# Add the source files
set(SOURCE_FILES src/main.cpp src/ByteConverter.cpp)

# Generate the executable from the source files
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

# Specify include directory
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)
