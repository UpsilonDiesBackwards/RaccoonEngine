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
        include/engine/application/window.h
        src/engine/application/window.cpp
        include/engine/renderer/shader_compiler.h
        src/engine/renderer/shader_compiler.cpp
        include/engine/utils/modelloaders/obj_loader.h
        src/engine/utils/modelloaders/obj_loader.cpp
    include/engine/utils/callbacks.h
        include/engine/gentries/entity.h
        src/engine/gentries/entity.cpp
        include/editor/scene.h
        src/editor/scene.cpp
        src/engine/application/input_manager.cpp
        src/editor/viewport.cpp
        src/engine/renderer/model_renderer.cpp
        src/editor/imgui/imgui.cpp
        src/editor/imgui/imgui_demo.cpp
        src/editor/imgui/imgui_draw.cpp
        src/editor/imgui/imgui_impl_glfw.cpp
        src/editor/imgui/imgui_impl_opengl3.cpp
        src/editor/imgui/imgui_tables.cpp
        src/editor/imgui/imgui_widgets.cpp
        include/deps/imgui/imconfig.h
        include/deps/imgui/imgui.h
        include/deps/imgui/imgui_impl_glfw.h
        include/deps/imgui/imgui_impl_opengl3.h
        include/deps/imgui/imgui_impl_opengl3_loader.h
        include/deps/imgui/imgui_internal.h
        include/deps/imgui/imstb_rectpack.h
        include/deps/imgui/imstb_textedit.h
        include/deps/imgui/imstb_truetype.h
        include/engine/application/application.h
        include/engine/application/rocket.h
        src/engine/application/rocket.cpp
        src/engine/application/application.cpp
)

target_link_libraries(RaccoonEngine PRIVATE glfw assimp)
