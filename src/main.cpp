#include "engine/window.h"
#include "engine/utils/modelloaders/obj_loader.h"
#include "engine/renderer/model_renderer.h"
#include "engine/gentries/entity.h"
#include "editor/scene.h"
#include <cstdio>
#include <iostream>
#include <glm/ext/matrix_clip_space.hpp>
#include "engine/input_manager.h"
#include "engine/utils/callbacks.h"
#include "editor/viewport.h"
#include "engine/renderer/shader_compiler.h"
#include "editor/viewport.h"
#include "engine/renderer/shader_compiler.h"

int main () {
    scene nScene("Default scene");
    Window window("Raccoon Engine // INDEV BUILD :: VIEWPORT BUILD >> " + nScene.GetName());
    InputManager& inputManager = InputManager::getInstance();
    inputManager.setWindow(window.GetGLFWWindow());
    Viewport viewport(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), -90.0f, 0.0f);

    Viewport viewport(glm::vec3(0, 0, 3), glm::vec3(1, 1, 1), -90, 0);

    Shader shader("/home/tayler/Projects/RaccoonEngine/assets/shaders/default.vert",
                  "/home/tayler/Projects/RaccoonEngine/assets/shaders/default.frag");

    Viewport viewport(glm::vec3(0, 0, 0), glm::vec3(1, 1, 1), -90, 0);

    Shader shader("/home/tayler/Projects/RaccoonEngine/assets/shaders/default.vert",
                  "/home/tayler/Projects/RaccoonEngine/assets/shaders/default.frag");

    model_renderer renderer;
    renderer.Initialize();

    Shader shader("/home/tayler/Projects/RaccoonEngine/assets/shaders/default.vert", "/home/tayler/Projects/RaccoonEngine/assets/shaders/default.frag");

    Transform transform1;
    Gentry Tree(transform1, "/home/tayler/Projects/WhiskyEngine/assets/models/tree.obj", (std::string &) "Tree");
    
//    Transform transform2;
//    Gentry Plane(transform2, "/home/tayler/Projects/RaccoonEngine/assets/models/plane.obj", (std::string &) "Plane");

    nScene.AddEntity(Tree);
//    nScene.AddEntity(Plane);
//    nScene.AddEntity(Plane);

    nScene.SaveScene("DefaultScene.rcsc");

    nScene.LoadScene("DefaultScene.rcsc");

    glm::mat4 perspective = glm::perspective(glm::radians(45.0f), window.AspectRatio(), 0.1f, 100.0f);

    while (!window.ShouldClose()) {
        window.updateDeltaTime();

        glfwSetInputMode(window.GetGLFWWindow(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);

        viewport.processKeyboard(inputManager, window.getDeltaTime());
        viewport.processMouse(inputManager.getMouseX(), inputManager.getMouseY());
        viewport.processScrollWheel(inputManager.getMouseY());

        if (inputManager.isKeyDown((GLFW_KEY_ESCAPE))) {
            glfwSetWindowShouldClose(window.GetGLFWWindow(), GLFW_TRUE);
        }

        window.Render();
        for (const Gentry& entity : nScene.GetEntities()) {
            renderer.Render(const_cast<Gentry &>(entity), shader, viewport, perspective);
        }

        inputManager.update();

        window.SwapBuffers();
        window.PollEvents();
    }

    return 0;
}
