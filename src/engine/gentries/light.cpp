//
// Created by tayler on 14/11/23.
//

#include "engine/gentries/light.h"

Light::Light(glm::vec3 position, glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular, float intensity, LightType type)
        : position(position), ambient(ambient), diffuse(diffuse), specular(specular), intensity(intensity), type(type) { }

Light::~Light() { }

glm::vec3 Light::getPosition() {
    return position;
}

glm::vec3 Light::getAmbient() {
    return ambient;
}

glm::vec3 Light::getSpecular() {
    return specular;
}

glm::vec3 Light::getDiffuse() {
    return diffuse;
}

//glm::vec3 Light::getColor() const {
//    return color;
//}

float Light::getIntensity() const {
    return intensity;
}

LightType Light::getType() const {
    return type;
}

void Light::setPosition(glm::vec3 newPosition) {
    position = newPosition;
}

void Light::setAmbient(glm::vec3 newAmbient) {
    ambient = newAmbient;
}

void Light::setDiffuse(glm::vec3 newDiffuse) {
    diffuse = newDiffuse;
}

void Light::setSpecular(glm::vec3 newSpecular) {
    specular = newSpecular;
}


//void Light::setColor(glm::vec3 newColor) {
//    color = newColor;
//}

void Light::setIntensity(float newIntensity) {
    intensity = newIntensity;
}

void Light::setType(LightType newType) {
    type = newType;
}
