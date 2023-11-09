#include "editor/viewport.h"
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>

Viewport::Viewport(glm::vec3 position, glm::vec3 up, float yaw, float pitch) 
    : front(glm::vec3(0.0f, 0.0f, -1.0f)), moveSpeed(5.0f), sensitivity(0.2f), zoom(45.0f) {
    this->position = position;
    this->worldUp = up;
    this->yaw = yaw;
    this->pitch = pitch;
    this->up = glm::vec3(0.0f, 1.0f, 0.0f);
}

glm::mat4 Viewport::getViewMatrix() {
    glm::mat4 lookAt = glm::lookAt(position, position + front, up);
    return lookAt;
}

void Viewport::processKeyboard(InputManager &inputManager, float deltaTime) {
    float velocity = moveSpeed * deltaTime;

    if (inputManager.isKeyPressed(GLFW_KEY_W)) {
        position += front * velocity;    }

    if (inputManager.isKeyPressed(GLFW_KEY_S)) {
        position -= front * velocity;
    }

    if (inputManager.isKeyPressed(GLFW_KEY_A)) {
        position -= right * velocity;
    }

    if (inputManager.isKeyPressed(GLFW_KEY_D)) {
        position += right * velocity;
    }

    if (inputManager.isKeyPressed(GLFW_KEY_SPACE)) {
        position += up * velocity;
    }

    if (inputManager.isKeyPressed(GLFW_KEY_LEFT_SHIFT)) {
        position -= up * velocity;
    }
}

void Viewport::processMouse(double xpos, double ypos) {
    if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos;
    lastX = xpos;
    lastY = ypos;

    xoffset *= sensitivity;
    yoffset *= sensitivity;

    yaw   += xoffset;
    pitch += yoffset;

    if(pitch > 89.0f)
        pitch = 89.0f;
    if(pitch < -89.0f)
        pitch = -89.0f;

    glm::vec3 direction;
    direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    direction.y = sin(glm::radians(pitch));
    direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));

    front = glm::normalize(direction);
    right = glm::normalize(glm::cross(front, worldUp));
}

void Viewport::processScrollWheel(float yOffset) {
    if (zoom >= 1.0f && zoom <= 45.0f) zoom -= yOffset;
    if (zoom <= 1.0f) zoom = 1.0f;
    if (zoom >= 45.0f) zoom = 45.0f;
}