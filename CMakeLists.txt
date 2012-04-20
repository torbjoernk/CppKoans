# CMakeLists.txt

cmake_minimum_required(VERSION 2.8)

project(CppKoans)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR})

add_definitions(
  -std=c++0x -g -O0
)

find_package(Boost REQUIRED COMPONENTS unit_test_framework)

set(cppkoans_SOURCES
  ${PROJECT_SOURCE_DIR}/cppkoans.cpp
  ${PROJECT_SOURCE_DIR}/helper.hpp
)

add_subdirectory(koans)

include_directories(
  ${Boost_INCLUDE_DIR}
)

add_executable(CppKoans
  ${cppkoans_SOURCES}
)

target_link_libraries(CppKoans
  ${Boost_LIBRARIES}
)
