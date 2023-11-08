#include "engine/gentries/entity.h"
#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>
#include "glm/gtx/transform.hpp"

Gentry::Gentry(const Transform& transform, const std::string& fPath, std::string& name) : name(
        (std::string &) "Game Entity") {
    obj_loader objLoader(fPath);
    objLoader.Load();

    meshes = objLoader.GetMeshes();
}

const glm::mat4 *Gentry::GenerateModelMatrix() {
    glm::mat4 modelMatrix = glm::mat4(1.0f);

    modelMatrix = glm::translate(modelMatrix, transform.position);
    modelMatrix = glm::rotate(modelMatrix, glm::radians(45.0f), transform.eulerRotation);
    modelMatrix = glm::scale(modelMatrix, transform.scale);

    // Other debug prints

    this->modelMatrix = modelMatrix;

    return &this->modelMatrix;
}
