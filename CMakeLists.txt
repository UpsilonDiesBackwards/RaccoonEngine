cmake_minimum_required(VERSION 3.26)
project(RaccoonEngine)

set(CMAKE_CXX_STANDARD 17)

include_directories(${CMAKE_SOURCE_DIR}/include)

find_package(glfw3 REQUIRED)

add_executable(RaccoonEngine
    src/main.cpp
    include/deps/glad/glad.h
    include/deps/glad/glad.c
    include/engine/window.h
    src/engine/windowing/window.cpp)

target_link_libraries(RaccoonEngine PRIVATE glfw)
