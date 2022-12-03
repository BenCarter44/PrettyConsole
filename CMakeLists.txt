# CMakeList.txt : CMake project for PrettyConsole, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("PrettyConsole")
option(DLLHEADER_COMPILE "Complie DLL/Shared Libs" OFF)

# Add source to this project's executable.

# add_executable (PrettyConsole "PrettyConsole.cpp" "PrettyConsole.h" "console.h" "console.cpp" "row.h" "row.cpp" "styles.h" "styles.cpp" "styleAttribute.h" "styleAttribute.cpp" "screenComponent.h" "screenComponent.cpp" "rectangle.h" "rectangle.cpp" "line.h" "line.cpp" "point.h" "point.cpp")

#add_definitions(-DDLLHEADER_COMPILE)
#add_library(PrettyConsoleLib SHARED "PrettyConsole.h" "console.h" "console.cpp" "row.h" "row.cpp" "styles.h" "styles.cpp" "styleAttribute.h" "styleAttribute.cpp" "screenComponent.h" "screenComponent.cpp" "rectangle.h" "rectangle.cpp" "line.h" "line.cpp" "point.h" "point.cpp")


if (DLLHEADER_COMPILE)
    add_definitions(-DDLLHEADER_COMPILE)
    add_library(PrettyConsoleLib SHARED "PrettyConsole.h" "MyString.h" "MyString.cpp" "console.h" "console.cpp" "row.h" "row.cpp" "styles.h" "styles.cpp" "styleAttribute.h" "styleAttribute.cpp" "screenComponent.h" "screenComponent.cpp" "rectangle.h" "rectangle.cpp" "line.h" "line.cpp" "point.h" "point.cpp")
else()
    add_executable(PrettyConsole "PrettyConsole.cpp" "MyString.h" "MyString.cpp" "PrettyConsole.h" "console.h" "console.cpp" "row.h" "row.cpp" "styles.h" "styles.cpp" "styleAttribute.h" "styleAttribute.cpp" "screenComponent.h" "screenComponent.cpp" "rectangle.h" "rectangle.cpp" "line.h" "line.cpp" "point.h" "point.cpp")
endif()

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)
# TODO: Add tests and install targets if needed.
