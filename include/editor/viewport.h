#ifndef RACCOONENGINE_VIEWPORT_H
#define RACCOONENGINE_VIEWPORT_H
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "engine/input_manager.h"

class Viewport {
private:
    void updateViewportVectors();

    glm::vec3 position{};
    glm::vec3 front;
    glm::vec3 up{};
    glm::vec3 right{};
    glm::vec3 worldUp{};

    float yaw, pitch;

    float flySpeed;
    float sensitivity;
    float zoom;
public:
    Viewport(glm::vec3 position, glm::vec3 up, float yaw, float pitch);

    glm::mat4 getViewMatrix();
    
    void processKeyboard(InputManager& inputManager, float deltaTime);
    void processMouse(float xoffset, float yoffset, bool pitch_constraint = true);
    void processScrollWheel(float yoffset);
};

#endif // RACCOONENGINE_VIEWPORT_H
