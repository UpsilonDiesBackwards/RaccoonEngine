#ifndef RACCOONENGINE_ENTITY_H
#define RACCOONENGINE_ENTITY_H

#include <glm/vec3.hpp>
#include <glm/glm.hpp>
#include "engine/renderer/ModelRenderer.h" 

struct Transform {
    glm::vec3 position = {0.0f, 0.0f, 0.0f};
    glm::vec3 eulerRotation = {0.0f, 0.0f, 0.0f};
    glm::vec3 scale = {1.0f, 1.0f, 1.0f};

    glm::mat4 modelMatrix = glm::mat4(1.0f);
};

class Gentry {
public:
    std::string& name;
    Transform transform;
    std::vector<Mesh> meshes;
    Gentry(const Transform& transform, const std::string& fPath, std::string& name);
};

#endif // RACCOONENGINE_ENTITY_H
