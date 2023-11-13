//
// Created by tayler on 12/11/23.
//

#ifndef RACCOONENGINE_APPLICATION_H
#define RACCOONENGINE_APPLICATION_H

#include "window.h"
#include "input_manager.h"
#include "rocket.h"
#include "editor/viewport.h"
#include "engine/renderer/model.h"

class Application {
private:
    Application();
public:
    static Application getApplicationInstance();
    ~Application();

    void Initialise();
    int applicationUpdate();
    void inputUpdate();
    void renderLoop();

    Window mWindow;
    Rocket currentRocket = Rocket("Default Rocket");
    InputManager& inputManager;
    Viewport currentViewport;

    Model MRenderer;

    Window getWindow();
    Rocket getCurrentRocket();
    Viewport getCurrentViewport();
    Model getModelRenderer();

    void setCurrentRocket(Rocket newRocket);
    void setCurrentViewport(Viewport newViewport);
};

#endif //RACCOONENGINE_APPLICATION_H
