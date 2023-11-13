//
// Created by tayler on 12/11/23.
//

#include "engine/application/rocket.h"

Rocket::Rocket(std::string name) { rocketName = name; }

void Rocket::setCurrentScene(Scene newScene) {
    currentScene = newScene;
}

Scene Rocket::getCurrentScene() {
    return currentScene;
}
