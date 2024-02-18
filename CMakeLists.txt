cmake_minimum_required(VERSION 3.14)

project(Protocol LANGUAGES CXX)

#set(QT_DIR /lib/x86_64-linux-gnu/cmake/Qt5)
#set(QT_DIR /lib/x86_64-linux-gnu/cmake/Qt6)
#set(CMAKE_PREFIX_PATH /lib/x86_64-linux-gnu/cmake/Qt5)
#set(CMAKE_PREFIX_PATH /lib/x86_64-linux-gnu/cmake)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)  
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core REQUIRED)

add_executable(Protocol
  protocol.h   protocol.cpp main.cpp
)
target_link_libraries(Protocol Qt${QT_VERSION_MAJOR}::Core)
