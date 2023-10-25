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
    include/engine/renderer/ShaderCompiler.h
    src/engine/renderer/ShaderCompiler.cpp
    include/engine/renderer/ModelRenderer.h
    src/engine/renderer/ModelRenderer.cpp
    include/engine/utils/modelloaders/ObjLoader.h
    src/engine/utils/modelloaders/ObjLoader.cpp
    include/engine/utils/callbacks.h
)

target_link_libraries(RaccoonEngine PRIVATE glfw assimp)
