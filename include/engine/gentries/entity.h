#ifndef RACCOONENGINE_ENTITY_H
#define RACCOONENGINE_ENTITY_H

#include <glm/vec3.hpp>
#include <glm/glm.hpp>
#include <string>
#include <vector>
#include "engine/renderer/model_renderer.h"
#include "engine/utils/modelloaders/obj_loader.h"

struct Transform {
    glm::vec3 position = {0.0f, 0.0f, 10.0f};
    glm::vec3 eulerRotation = {1.0f, 1.0f, 1.0f};
    glm::vec3 scale = {1.0f, 1.0f, 1.0f};
};

class Gentry {
public:
    Gentry(const Transform& transform, const std::string& fPath, std::string& name);

    std::string& name;
    Transform transform;
    std::vector<Mesh> meshes;
    const glm::mat4 GenerateModelMatrix();
    glm::mat4 modelMatrix = glm::mat4(1.0f);
};

#endif // RACCOONENGINE_ENTITY_H
