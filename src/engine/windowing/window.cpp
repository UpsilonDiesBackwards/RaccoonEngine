#include <string>
#include <deps/glad/glad.h>
#include <iostream>
#include "engine/window.h"
#include "engine/utils/callbacks.h"
#include <iostream>

Window::Window(const std::string& title) {
    glfwSetErrorCallback(glfw_error_callback);
    glfwInit();

    GLFWmonitor* monitor = glfwGetPrimaryMonitor();
    const GLFWvidmode* mode = glfwGetVideoMode(monitor);

    window = glfwCreateWindow(mode->width, mode->height, title.c_str(), nullptr, nullptr);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_MAXIMIZED, GLFW_TRUE);

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    aspectRatio = static_cast<float>(mode->width) / static_cast<float>(mode->height);
    lastFrameTime = static_cast<float>(glfwGetTime());

    gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
}

Window::~Window() {
    glfwDestroyWindow(window);
    glfwTerminate();
}

void Window::Render() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.19f, 0.28f, 0.27f, 1.0f);
}

bool Window::ShouldClose() {
    glfwSetWindowCloseCallback(window, glfw_window_close_callback);
    return glfwWindowShouldClose(window);
}

void Window::SwapBuffers() {
    glfwSwapBuffers(window);
}

void Window::PollEvents() {
    glfwPollEvents();
}

void Window::SetSizeCallback(GLFWwindowsizefun callback) {
    glfwSetWindowSizeCallback(window, callback);
}

float Window::AspectRatio() {
    return aspectRatio;
}

void Window::updateDeltaTime() {
    double currentFrame = glfwGetTime();
    deltaTime = currentFrame - lastFrameTime;
    lastFrameTime = currentFrame;
}

float Window::getDeltaTime() const {
    return deltaTime;
}

glm::vec2 Window::DisplaySize() {
    int width, height;
    glfwGetWindowSize(window, &width, &height);
    return {static_cast<float>(width), static_cast<float>(height)};
}

glm::vec2 Window::FrameBufferSize() {
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    return {static_cast<float>(width), static_cast<float>(height)};
}

GLFWwindow* Window::GetGLFWWindow() {
    return window;
}