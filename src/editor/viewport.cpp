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

void Viewport::processMouse(float xOffset, float yOffset) {
    xOffset *= sensitivity;
    yOffset *= sensitivity;

    yaw += xOffset;
    pitch += yOffset;

    // Screw gimbal-lock, all my homies hate gimbal lock
    if (pitch > 89.0f) pitch = 89.0f;
    if (pitch < -89.0f) pitch = -89.0f;

    updateViewportVectors();
}

void Viewport::processScrollWheel(float yOffset) {
    if (zoom >= 1.0f && zoom <= 45.0f) zoom -= yOffset;
    if (zoom <= 1.0f) zoom = 1.0f;
    if (zoom >= 45.0f) zoom = 45.0f;
}

void Viewport::updateViewportVectors() {
    glm::vec3 nFront;

    nFront.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    nFront.y = sin(glm::radians(pitch));
    nFront.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));

    front = glm::normalize(nFront);
    right = glm::normalize(glm::cross(front, worldUp));
    up = glm::normalize(glm::cross(right, front));

    std::cout << "y: " << yaw << " p: " << pitch << "\n" << "newfront: " << glm::to_string(nFront);
}