cmake_minimum_required(VERSION  3.10)

project(MyUtils  CXX)

set(CMAKE_CXX_STANDARD  17)
set(CMAKE_CXX_STANDARD_REQUIRED  True)

if(NOT  CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE  Release)
endif()

set(CMAKE_CXX_FLAGS  "-Wall  -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG  "-Og")
set(CMAKE_CXX_FLAGS_RELEASE  "-O3")

include_directories(${PROJECT_SOURCE_DIR}/include)
file(GLOB_RECURSE  SOURCES  "src/*.cpp")

add_executable(MyExecutable  "src/main.cpp"  ${SOURCES})
