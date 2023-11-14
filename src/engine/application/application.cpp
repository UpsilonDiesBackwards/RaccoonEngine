//
// Created by tayler on 12/11/23.
//

#include <iostream>
#include <glm/ext/matrix_clip_space.hpp>
#include "engine/application/application.h"
#include "engine/gentries/entity.h"
#include "engine/renderer/shader_compiler.h"
#include "engine/gentries/light.h"

Application::Application() : mWindow("Raccoon Engine"),
                        currentViewport(glm::vec3(0.0f, 0.0f, -3.0f),
                        glm::vec3(0.0f, 1.0f, 0.0f), -90.0f, 0.0f),
                        inputManager(InputManager::getInstance()) {

    inputManager.setWindow(mWindow.GetGLFWWindow());

    Rocket dRocket("Default Rocket");

    setCurrentRocket(dRocket);

    Scene dScene("Default Scene");
    currentRocket.currentScene = dScene;
}

Application::~Application() { mWindow.Shutdown(); }

Application Application::getApplicationInstance() {
    static Application application;
    return application;
}

Window Application::getWindow() {
    return mWindow;
}

Rocket Application::getCurrentRocket() {
    return currentRocket;
}

Viewport Application::getCurrentViewport() {
    return currentViewport;
}

Model Application::getModelRenderer() {
    return MRenderer;
}

void Application::setCurrentRocket(Rocket newRocket) {
    currentRocket = newRocket;
}

void Application::setCurrentViewport(Viewport newViewport) {
    currentViewport = newViewport;
}

void Application::Initialise() {
    MRenderer.Initialize();

//    glfwSetInputMode(mWindow.GetGLFWWindow(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    mWindow.InitializeImGui();
    applicationUpdate();
}

void Application::inputUpdate() {
    if (!mWindow.GetIsImguiHover()) {
        currentViewport.processKeyboard(inputManager, mWindow.getDeltaTime());
        currentViewport.processMouse(inputManager.getMouseX(), inputManager.getMouseY());
        currentViewport.processScrollWheel(inputManager.getMouseY());
    }

    if (inputManager.isKeyDown((GLFW_KEY_ESCAPE))) {
        glfwSetWindowShouldClose(mWindow.GetGLFWWindow(), GLFW_TRUE);
    }

    inputManager.update();
}

int Application::applicationUpdate() {
    Shader shader("/home/tayler/Projects/RaccoonEngine/assets/shaders/default.vert",
                  "/home/tayler/Projects/RaccoonEngine/assets/shaders/default.frag");

    Transform t {
            glm::vec3(0, 0, 0),
            glm::vec3(1, 1, 1),
            glm::vec3(1, 1, 1),
    };
    Gentry Tree(t, "/home/tayler/Projects/RaccoonEngine/assets/models/tree.obj", "Tree");

    currentRocket.currentScene.AddEntity(Tree);

    glm::vec3 position(1.0f, 2.0f, 3.0f);
    glm::vec3 ambient(1.0f, 1.0f, 1.0f);
    glm::vec3 diffuse(0.5f, 0.5f, 0.5f);
    glm::vec3 specular(1.0f, 1.0f, 1.0f);
    float intensity = 1.0f;

    Light light(position, ambient, diffuse, specular, intensity, LightType::Point);

    while (!mWindow.ShouldClose()) {
        mWindow.updateDeltaTime();

        mWindow.Render();

        inputUpdate();

        for (Gentry e : currentRocket.currentScene.GetEntities()) {
            MRenderer.Draw(e, shader, currentViewport, &light);
        }

        mWindow.RenderImGui(light);

        mWindow.PollEvents();
        mWindow.SwapBuffers();
    }
    return 0;
}


