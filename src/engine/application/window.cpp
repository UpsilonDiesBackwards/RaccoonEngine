#include <string>
#include "deps/glad/glad.h"
#include <iostream>
#include "engine/application/window.h"
#include "engine/utils/callbacks.h"
#include "deps/imgui/imgui_impl_opengl3.h"
#include "deps/imgui/imgui_impl_glfw.h"
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
    glfwWindowHint(GLFW_SAMPLES, 4);

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    aspectRatio = static_cast<float>(mode->width) / static_cast<float>(mode->height);
    lastFrameTime = static_cast<float>(glfwGetTime());

    isImguiHover = false;

    gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
}

Window::~Window() {
    glfwDestroyWindow(window);
}

void Window::Shutdown() {
    ShutdownImGui();
    glfwTerminate();
}

void Window::Render() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.19f, 0.28f, 0.27f, 1.0f);

    glEnable(GL_MULTISAMPLE);
}

bool Window::ShouldClose() const {
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

float Window::AspectRatio() const {
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

void Window::InitializeImGui() {
    ImGui::CreateContext();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 330");

    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;

    ImFont* customEditorFont = io.Fonts->AddFontFromFileTTF("/home/tayler/Projects/RaccoonEngine/assets/fonts/retro_gaming/RetroGaming.ttf", 18);
    io.FontDefault = customEditorFont;
}

void Window::RenderImGui() {
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    ImGui::ShowDemoWindow();

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void Window::ShutdownImGui() {
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}

bool Window::GetIsImguiHover() {
    return isImguiHover = ImGui::IsAnyItemHovered() || ImGui::IsAnyItemActive();
}
