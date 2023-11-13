#ifndef RACCOONENGINE_ENTITY_H
#define RACCOONENGINE_ENTITY_H

#include <glm/vec3.hpp>
#include <glm/glm.hpp>
#include <glm/ext/matrix_transform.hpp>
#include "engine/renderer/model.h"
#include "engine/utils/modelloaders/obj_loader.h"

struct Transform {
    glm::vec3 position = {0.0f, 0.0f, 10.0f};
    glm::vec3 eulerRotation = {1.0f, 1.0f, 1.0f};
    glm::vec3 scale = {1.0f, 1.0f, 1.0f};
};

class Gentry {
public:
    Gentry(Transform transform, const std::string& fPath, std::string name);

    std::string name;
    Transform transform;
    std::vector<Mesh> meshes;
    glm::mat4 modelMatrix;
    const glm::mat4* GenerateModelMatrix();

    void SetPosition(glm::vec3 newPos);
    void SetEulerRotation(glm::vec3 newERot);
    void SetScale(glm::vec3 newScale);

    void EulerRotate(glm::vec3 angles);
    void Update(float deltaTime);
};

#endif // RACCOONENGINE_ENTITY_H
