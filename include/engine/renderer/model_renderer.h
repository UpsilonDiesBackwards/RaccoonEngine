#ifndef RACCOONENGINE_MODEL_RENDERER_H
#define RACCOONENGINE_MODEL_RENDERER_H

#include <vector>
#include "engine/utils/modelloaders/obj_loader.h"

class model_renderer {
private:
    unsigned int VAO;
    unsigned int VBO;
    unsigned int EBO;
public:
    model_renderer();
    void Initialize();
    void Render(const std::vector<Mesh>& meshes);
};

#endif // RACCOONENGINE_MODEL_RENDERER_H
