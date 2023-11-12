#ifndef RACCOONENGINE_MODEL_RENDERER_H
#define RACCOONENGINE_MODEL_RENDERER_H

#include <vector>
#include <glm/fwd.hpp>
#include "engine/utils/modelloaders/obj_loader.h"

class Gentry;
class Shader;
class Viewport;

class model_renderer {
private:
    unsigned int VAO;
    unsigned int VBO;
    unsigned int EBO;
public:
    model_renderer();
    void Initialize();
    void Render(Gentry &gentry, Shader &shader, Viewport &viewport, glm::mat4 &projection) const;
};

#endif //RACCOONENGINE_MODEL_RENDERER_H
