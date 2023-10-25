#ifndef RACCOONENGINE_MODELRENDERER_H
#define RACCOONENGINE_MODELRENDERER_H

#include <vector>
#include "engine/utils/modelloaders/ObjLoader.h"

class ModelRenderer {
private:
    unsigned int VAO;
    unsigned int VBO;
    unsigned int EBO;
public:
    ModelRenderer();
    void Initialize();
    void Render(const std::vector<Mesh>& meshes);
};

#endif RACCOONENGINE_MODELRENDERER_H
