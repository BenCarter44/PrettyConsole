# CMakeList.txt : CMake project for PrettyConsole, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("PrettyConsole")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)


file(GLOB SOURCES "${CMAKE_SOURCE_DIR}/src/*.cpp")

file(GLOB_RECURSE HEADERS "${CMAKE_SOURCE_DIR}/include/*.h")
file(GLOB_RECURSE HEADERS2 "${CMAKE_SOURCE_DIR}/include/*.hpp")

# Add source to this project's executable.

add_executable(PrettyConsole ${SOURCES} ${HEADERS} ${HEADERS2})
target_include_directories(PrettyConsole PRIVATE "${CMAKE_SOURCE_DIR}/include")

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# TODO: Add tests and install targets if needed.
