# CMakeList.txt : CMake project for PrettyConsole, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("PrettyConsole")

# Add source to this project's executable.
add_executable (PrettyConsole "PrettyConsole.cpp" "PrettyConsole.h" "console.h" "console.cpp" "row.h" "row.cpp" "styles.h" "styles.cpp" "styleAttribute.h" "styleAttribute.cpp" "screenComponent.h" "screenComponent.cpp" "rectangle.h" "rectangle.cpp" "line.h" "line.cpp")
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)
# TODO: Add tests and install targets if needed.
