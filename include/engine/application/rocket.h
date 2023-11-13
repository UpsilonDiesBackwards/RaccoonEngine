//
// Created by tayler on 12/11/23.
// Rocket is the name associated with Raccoon Engine Project files. A "rocket" is a project.
//

#ifndef RACCOONENGINE_ROCKET_H
#define RACCOONENGINE_ROCKET_H

#include <string>
#include <vector>
#include "editor/scene.h"

class Rocket {
public:
    std::string rocketName;
    Rocket(std::string name);


    Scene currentScene = Scene("Default Scene");
    std::vector<Scene> scenes();

    void setCurrentScene(Scene newScene);

    Scene getCurrentScene();
};

#endif //RACCOONENGINE_ROCKET_H
