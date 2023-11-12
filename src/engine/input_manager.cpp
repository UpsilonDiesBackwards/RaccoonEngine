#include "engine/input_manager.h"
#include <GLFW/glfw3.h>

InputManager::InputManager() {
    for (int i =0; i < 512; ++i) {
        keys[i] = false;
        prevKeys[i] = false;
    }

    for (int i = 0; i < 8; ++i) {
        mouseButtons[i] = false;
        prevMouseButtons[i] = false;
    }

    mouseX = 0.0;
    mouseY = 0.0;
}

InputManager::~InputManager() { }

InputManager& InputManager::getInstance() { // Singletons my beloved
    static InputManager instance;
    return instance;
}

void InputManager::setWindow(GLFWwindow* newWindow) {
    window = newWindow;
    initKeyCallbacks();
    initMouseCallbacks();
}

bool InputManager::isKeyPressed(int key) {
    return keys[key];
}

bool InputManager::isKeyDown(int key) {
    return keys[key] && !prevKeys[key];
}

bool InputManager::isKeyUp(int key) {
    return !keys[key] && prevKeys[key];
}

bool InputManager::isMouseButtonPressed(int button) {
    return mouseButtons[button];
}

bool InputManager::isMouseButtonDown(int button) {
    return mouseButtons[button] && !prevMouseButtons[button];
}

bool InputManager::isMouseButtonUp(int button) {
    return !mouseButtons[button] && prevMouseButtons[button];
}

double InputManager::getMouseX() {
    return mouseX;
}

double InputManager::getMouseY() {
    return mouseY;
}

void InputManager::update() {
    // Copy current state to the previous state
    for (int i = 0; i < 512; ++i) {
        prevKeys[i] = keys[i];
    }

    for (int i = 0; i < 8; ++i) {
        prevMouseButtons[i] = mouseButtons[i];
    }
}

void InputManager::initKeyCallbacks() {
    // Set up key callback
    glfwSetKeyCallback(window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
        InputManager& inputManager = InputManager::getInstance();
        if (action == GLFW_PRESS) {
            inputManager.keys[key] = true;
        } else if (action == GLFW_RELEASE) {
            inputManager.keys[key] = false;
        }
    });
}

void InputManager::initMouseCallbacks() {
    // Set up mouse button callback
    glfwSetMouseButtonCallback(window, [](GLFWwindow* window, int button, int action, int mods) {
        InputManager& inputManager = InputManager::getInstance();
        if (action == GLFW_PRESS) {
            inputManager.mouseButtons[button] = true;
        } else if (action == GLFW_RELEASE) {
            inputManager.mouseButtons[button] = false;
        }
    });

    // Set up mouse position callback
    glfwSetCursorPosCallback(window, [](GLFWwindow* window, double xpos, double ypos) {
        InputManager& inputManager = InputManager::getInstance();
        inputManager.mouseX = xpos;
        inputManager.mouseY = ypos;
    });
}
