#ifndef RACCOONENGINE_WINDOW_H
#define RACCOONENGINE_WINDOW_H

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <string>

class Window {
private:
    GLFWwindow* window;
    float aspectRatio;
    float lastFrameTime;
public:
    Window(const std::string& title);
    ~Window();
    void Shutdown();

    void Render();
    bool ShouldClose() const;
    void SwapBuffers();
    void PollEvents();
    void SetSizeCallback(GLFWwindowsizefun callback);
    GLFWwindow* GetGLFWWindow();

    float AspectRatio() const;
    glm::vec2 DisplaySize();
    glm::vec2 FrameBufferSize();

    float deltaTime;
    float getDeltaTime() const;
    void updateDeltaTime();

    void InitializeImGui();
    void RenderImGui();
    void ShutdownImGui();

    bool isImguiHover;
    bool GetIsImguiHover();
};

#endif //RACCOONENGINE_WINDOW_H
