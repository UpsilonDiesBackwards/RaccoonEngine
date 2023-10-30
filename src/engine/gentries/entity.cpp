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

const glm::mat4 Gentry::GenerateModelMatrix() {
    modelMatrix = glm::translate(modelMatrix, transform.position);
    modelMatrix = glm::rotate(modelMatrix, glm::radians(90.0f), transform.eulerRotation);
    modelMatrix = glm::scale(modelMatrix, transform.scale);

    return modelMatrix;
}
