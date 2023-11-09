#ifndef RACCOONENGINE_VIEWPORT_H
#define RACCOONENGINE_VIEWPORT_H

#include <glm/glm.hpp>
#include "engine/input_manager.h"

class InputManager;

class Viewport {
private:
    glm::vec3 position;
    glm::vec3 front;
    glm::vec3 up;
    glm::vec3 right;
    glm::vec3 worldUp;

    float yaw;
    float pitch;

    float moveSpeed, sensitivity, zoom;
    bool firstMouse = true;
    float lastX, lastY;
public:

    Viewport(glm::vec3 position, glm::vec3 up, float yaw, float pitch);

    glm::mat4 getViewMatrix();

    void processKeyboard(InputManager& inputManager, float deltaTime);
    void processMouse(double xpos, double ypos);
    void processScrollWheel(float yOffset);
};
#endif /* ifndef  */
