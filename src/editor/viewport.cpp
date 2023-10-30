#include "editor/viewport.h"
#include <iostream>
#include <glm/gtx/string_cast.hpp>

Viewport::Viewport(glm::vec3 position, glm::vec3 up, float yaw, float pitch)
    : front(glm::vec3(0.0f, 0.0f, -5.0f)), flySpeed(2.0f), sensitivity(1.0f), zoom(45.0f) {
    
        this->position = position;
        this->worldUp = up;
        this->yaw = yaw;
        this->pitch = pitch;
        updateViewportVectors();
}

glm::mat4 Viewport::getViewMatrix() {
    return glm::lookAt(position, position + front, up);
}

void Viewport::processKeyboard(InputManager& inputManager, float deltaTime) {
    float vel = flySpeed * deltaTime;

    if (inputManager.isKeyPressed((GLFW_KEY_W))) {
        position = position + front * vel;
//        std::cout << "Move forward\n";
    }

    if (inputManager.isKeyPressed((GLFW_KEY_S))) {
        position = position - front * vel;
//        std::cout << "Move backward\n";
    }

    if (inputManager.isKeyPressed((GLFW_KEY_A))) {
        position = position - right * vel;
//        std::cout << "Move left\n";
    }

    if (inputManager.isKeyPressed((GLFW_KEY_D))) {
        position = position + right * vel;
//        std::cout << "Move right\n";
    }

//    std::cout << glm::to_string(position) << "\n";
}

void Viewport::processMouse(float xoffset, float yoffset, bool pitch_constraint) {
    xoffset *= sensitivity;
    yoffset *= sensitivity;

    yaw += xoffset;
    pitch += yoffset;

    if (pitch_constraint) { // Screw gimbal-lock, all my homies hate gimbal-lock
        if (pitch > 89.0f) pitch = 89.0f;
        if (pitch < -89.0f) pitch = -89.0f;
    }
    updateViewportVectors();
}

void Viewport::processScrollWheel(float yoffset) {
    if (zoom >= 1.0f && zoom <= 45.0f) zoom -= yoffset;
    if (zoom <= 1.0f) zoom = 1.0f;
    if (zoom >= 45.0f) zoom = 45.0f;
} 

void Viewport::updateViewportVectors() {
    glm::vec3 newFront;

    newFront.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    newFront.y = sin(glm::radians(pitch));
    newFront.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    
    front = glm::normalize(newFront);
    right = glm::normalize(glm::cross(front, worldUp));
    up = glm::normalize(glm::cross(right, front));
}
