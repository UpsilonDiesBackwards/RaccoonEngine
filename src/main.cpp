#include "engine/gentries/entity.h"
#include "editor/scene.h"
#include <iostream>
#include <glm/ext/matrix_clip_space.hpp>
#include "editor/viewport.h"
#include "engine/renderer/shader_compiler.h"
#include "engine/application/application.h"

int main () {
    Application app = Application::getApplicationInstance();
    app.Initialise();

    return 0;
}
