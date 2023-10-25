#include <string>
#include <deps/glad/glad.h>
#include "engine/window.h"
#include "engine/utils/callbacks.h"

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

    gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
}

Window::~Window() {
    glfwDestroyWindow(window);
    glfwTerminate();
}
 
void Window::Render() {
    glClearColor(0.19f, 0.28f, 0.27f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
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
