#ifndef RACCOONENGINE_INPUT_MANAGER_H
#define RACCOONENGINE_INPUT_MANAGER_H

#include <GLFW/glfw3.h>

class InputManager {
private:
    InputManager();
    ~InputManager();

    bool keys[512];
    bool mouseButtons[8];
    double mouseX, mouseY;

    bool prevKeys[512];
    bool prevMouseButtons[8];

    void initKeyCallbacks();
    void initMouseCallbacks();

    GLFWwindow* window;
public:
    static InputManager& getInstance();

    bool isKeyPressed(int key);
    bool isKeyDown(int key);
    bool isKeyUp(int key);
    
    bool isMouseButtonPressed(int button);
    bool isMouseButtonDown(int button);
    bool isMouseButtonUp(int button);
    
    double getMouseX();
    double getMouseY();

    void update();

    void setWindow(GLFWwindow* window);
};

#endif // RACCOONENGINE_INPUT_MANAGER_H
