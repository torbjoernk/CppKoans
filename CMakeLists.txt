# CMakeLists.txt

cmake_minimum_required(VERSION 2.8)

project(CppKoans)

if (NOT WIN32)
add_definitions(
  -std=c++14 -g -O0
)
endif()

set(cppkoans_SOURCES
  ${PROJECT_SOURCE_DIR}/cppkoans.cpp
  ${PROJECT_SOURCE_DIR}/helper.hpp
  ${PROJECT_SOURCE_DIR}/headers/koan_handler.cpp
)

add_subdirectory(koans)
include_directories(headers)

add_executable(CppKoans
  ${cppkoans_SOURCES}
)
