#include "engine/window.h"
#include "engine/renderer/model_renderer.h"
#include "engine/gentries/entity.h"
#include "editor/scene.h"
#include <iostream>
#include <glm/ext/matrix_clip_space.hpp>
#include "engine/input_manager.h"
#include "editor/viewport.h"
#include "engine/renderer/shader_compiler.h"
#include "deps/imgui/imgui.h"
#include "deps/imgui/imgui_impl_glfw.h"
#include "deps/imgui/imgui_impl_opengl3.h"

int main () {
    scene nScene("Default scene");
    Window window("Raccoon Engine // INDEV BUILD :: VIEWPORT BUILD >> " + nScene.GetName());
    InputManager& inputManager = InputManager::getInstance();
    inputManager.setWindow(window.GetGLFWWindow());
    Viewport viewport(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), -90.0f, 0.0f);

    Shader shader("/home/tayler/Projects/RaccoonEngine/assets/shaders/default.vert",
                  "/home/tayler/Projects/RaccoonEngine/assets/shaders/default.frag");

    model_renderer renderer;
    renderer.Initialize();

    Transform transform1;
    Gentry Tree(transform1, "/home/tayler/Projects/WhiskyEngine/assets/models/tree.obj", (std::string &) "Tree");

    nScene.AddEntity(Tree);

    glm::mat4 perspective = glm::perspective(glm::radians(45.0f), window.AspectRatio(), 0.1f, 100.0f);

    window.InitializeImGui();
    while (!window.ShouldClose()) {
        window.updateDeltaTime();

        window.RenderImGui();

        if (!window.GetIsImguiHover()) {
            viewport.processKeyboard(inputManager, window.getDeltaTime());
            viewport.processMouse(inputManager.getMouseX(), inputManager.getMouseY());
            viewport.processScrollWheel(inputManager.getMouseY());
        }

        if (inputManager.isKeyDown((GLFW_KEY_ESCAPE))) {
            glfwSetWindowShouldClose(window.GetGLFWWindow(), GLFW_TRUE);
        }

        window.Render();
        for (const Gentry& entity : nScene.GetEntities()) {
            renderer.Render(const_cast<Gentry &>(entity), shader, viewport, perspective);
        }

        inputManager.update();

        window.RenderImGui();

        window.SwapBuffers();
        window.PollEvents();
    }

    window.ShutdownImGui();
    return 0;
}
