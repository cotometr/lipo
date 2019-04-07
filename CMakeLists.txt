cmake_minimum_required(VERSION 3.6)
project(lipo)

set(CMAKE_CXX_STANDARD 11)

include_directories(/usr/share/arduino/libraries/SoftwareSerial)
include_directories(/usr/share/arduino/hardware/arduino/cores/arduino)
include_directories(/usr/share/arduino/hardware/arduino/variants/micro)
include_directories(../log)

set(SOURCE_FILES test/main.cpp lipo.cpp lipo.h)
#set(SOURCE_FILES test/main.cpp)

add_executable(lipo ${SOURCE_FILES})