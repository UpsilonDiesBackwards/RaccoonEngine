#include "engine/gentries/entity.h"
#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>
#include <iostream>
#include "glm/gtx/transform.hpp"

Gentry::Gentry(Transform transform, const std::string& fPath, std::string name) : name(name) {
    obj_loader objLoader(fPath);
    objLoader.Load();

    meshes = objLoader.GetMeshes();
}

const glm::mat4 *Gentry::GenerateModelMatrix() {
    glm::mat4 modelMatrix = glm::mat4(1.0f);

    modelMatrix = glm::translate(modelMatrix, transform.position);
    modelMatrix = glm::rotate(modelMatrix, glm::radians(0.0f), transform.eulerRotation);
    modelMatrix = glm::scale(modelMatrix, transform.scale);

    this->modelMatrix = modelMatrix;

    return &this->modelMatrix;
}

void Gentry::SetPosition(glm::vec3 newPos) {
    transform.position = newPos;
}

void Gentry::SetEulerRotation(glm::vec3 newERot) {
    transform.eulerRotation = newERot;
}

void Gentry::SetScale(glm::vec3 newScale) {
    transform.scale = newScale;

}

void Gentry::EulerRotate(glm::vec3 angles) {
    transform.eulerRotation = glm::radians(angles);
}

void Gentry::Update(float deltaTime) {
    transform.position += glm::vec3(0.0f, 0.0f, 1.0f) * deltaTime;
    glm::vec3 rotationSpeed(0.0f, 1.0f, 0.0f);
    transform.eulerRotation += rotationSpeed * deltaTime;
    transform.scale += glm::vec3(0.1f, 0.1f, 0.1f) * deltaTime;

    GenerateModelMatrix();
}

