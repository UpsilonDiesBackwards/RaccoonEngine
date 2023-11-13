//
// Created by tayler on 12/11/23.
//

#include <iostream>
#include <glm/ext/matrix_clip_space.hpp>
#include "engine/application/application.h"
#include "engine/gentries/entity.h"
#include "engine/renderer/shader_compiler.h"

Application::Application() : mWindow("Raccoon Engine"),
                        currentViewport(glm::vec3(0.0f, 0.0f, 0.0f),
                        glm::vec3(0.0f, 1.0f, 0.0f), -90.0f, 0.0f),
                        inputManager(InputManager::getInstance()) {

    inputManager.setWindow(mWindow.GetGLFWWindow());

    Rocket dRocket("Default Rocket");

    setCurrentRocket(dRocket);
    std::cout << "\nNew rocket: " << dRocket.rocketName;

    Scene dScene("Default Scene");
    currentRocket.currentScene = dScene;

    Transform transform1;
    Gentry Tree(transform1, "/home/tayler/Projects/WhiskyEngine/assets/models/tree.obj", "Tree");

    getCurrentRocket().getCurrentScene().AddEntity(Tree);
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

ModelRenderer Application::getModelRenderer() {
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

    glfwSetInputMode(mWindow.GetGLFWWindow(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);

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

    glm::mat4 perspective = glm::perspective(glm::radians(45.0f), mWindow.AspectRatio(), 0.1f, 100.0f);

    Transform transform1;
    Gentry Tree(transform1, "/home/tayler/Projects/RaccoonEngine/assets/models/tree.obj", "Tree");

    while (!mWindow.ShouldClose()) {
        mWindow.updateDeltaTime();

        mWindow.Render();

        inputUpdate();

        MRenderer.Render(Tree, shader, currentViewport, perspective);

        mWindow.RenderImGui();

        mWindow.PollEvents();
        mWindow.SwapBuffers();
    }
    return 0;
}


