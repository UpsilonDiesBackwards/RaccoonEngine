//
// Created by tayler on 14/11/23.
//

#ifndef RACCOONENGINE_LIGHT_H
#define RACCOONENGINE_LIGHT_H

#include <glm/vec3.hpp>

enum class LightType {
    Point,
    Directional,
    Global,
};


class Light {
public:
    Light(glm::vec3 position, glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular, float intensity, LightType type);
    ~Light();

    // Getter methods
    glm::vec3 getPosition();
    glm::vec3 getAmbient();
    glm::vec3 getDiffuse();
    glm::vec3 getSpecular();

//    glm::vec3 getColor() const;
    float getIntensity() const;
    LightType getType() const;

    // Setter methods
    void setPosition(glm::vec3 position);
    void setAmbient(glm::vec3 ambient);
    void setDiffuse(glm::vec3 diffuse);
    void setSpecular(glm::vec3 specular);

    void setColor(glm::vec3 color);
    void setIntensity(float intensity);
    void setType(LightType type);

private:
    glm::vec3 position;
    glm::vec3 ambient;
    glm::vec3 diffuse;
    glm::vec3 specular;
//    glm::vec3 color;
    float intensity;
    LightType type;
};

#endif //RACCOONENGINE_LIGHT_H
