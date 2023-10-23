#ifndef RACCOONENGINE_WINDOW_H
#define RACCOONENGINE_WINDOW_H

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <string>

class Window {
private:
    GLFWwindow* window;
    float aspectRatio;
public:
    Window(const std::string& title);
    ~Window();

    void Render();
    bool ShouldClose();
    void SwapBuffers();
    void PollEvents();
    void SetSizeCallback(GLFWwindowsizefun callback);
    GLFWwindow* GetGLFWWindow();

    float AspectRatio();
    glm::vec2 DisplaySize();
    glm::vec2 FrameBufferSize();
};

#endif //RACCOONENGINE_WINDOW_H
