#include "engine/window.h"
#include "engine/utils/modelloaders/obj_loader.h"
#include "engine/renderer/model_renderer.h"
#include "engine/gentries/entity.h"
#include "editor/scene.h"
#include <cstdio>
#include <iostream>
#include "engine/input_manager.h"
#include "engine/utils/callbacks.h"

int main () {
    scene nScene("Default scene");
    Window window("Raccoon Engine // INDEV BUILD >> " + nScene.GetName());
    InputManager& inputManager = InputManager::getInstance();
    inputManager.setWindow(window.GetGLFWWindow());

    model_renderer renderer;
    renderer.Initialize();
    
    Transform transform1;
    Gentry Tree(transform1, "/home/tayler/Projects/WhiskyEngine/assets/models/tree.obj", (std::string &) "Tree");
    
    Transform transform2;
    Gentry Plane(transform2, "/home/tayler/Projects/RaccoonEngine/assets/models/plane.obj", (std::string &) "Plane");

    nScene.AddEntity(Tree);
    nScene.AddEntity(Plane);

    nScene.SaveScene("DefaultScene.rcsc");

    nScene.LoadScene("DefaultScene.rcsc");

    while (!window.ShouldClose()) {

        if (inputManager.isKeyDown((GLFW_KEY_ESCAPE))) {
//            glfwSetWindowShouldClose(window.GetGLFWWindow(), GLFW_TRUE);
            glfw_window_close_callback(window.GetGLFWWindow());
        }

        for (const Gentry& entity : nScene.GetEntities()) {
            renderer.Render(entity.meshes);
//            std::cout << "Loaded gEntity from scene " + nScene.GetName();
        }

        inputManager.update();

        window.SwapBuffers();
        window.PollEvents();
    }

    return 0;
}
