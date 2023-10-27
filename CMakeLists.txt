cmake_minimum_required(VERSION 3.26)
project(RaccoonEngine)

set(CMAKE_CXX_STANDARD 17)

include_directories(${CMAKE_SOURCE_DIR}/include)

find_package(glfw3 REQUIRED)
find_package(assimp REQUIRED)

add_executable(RaccoonEngine
    src/main.cpp
    include/deps/glad/glad.h
    include/deps/glad/glad.c
    include/engine/window.h
    src/engine/windowing/window.cpp
        include/engine/renderer/shader_compiler.h
        src/engine/renderer/shader_compiler.cpp
        include/engine/renderer/model_renderer.h
        src/engine/renderer/model_renderer.cpp
        include/engine/utils/modelloaders/obj_loader.h
        src/engine/utils/modelloaders/obj_loader.cpp
    include/engine/utils/callbacks.h
        include/engine/gentries/entity.h
        src/engine/gentries/entity.cpp
        include/editor/scene.h
        src/editor/scene.cpp
        src/engine/input_manager.cpp
)

target_link_libraries(RaccoonEngine PRIVATE glfw assimp)
