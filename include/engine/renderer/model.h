#ifndef RACCOONENGINE_MODEL_H
#define RACCOONENGINE_MODEL_H

#include <vector>
#include <glm/fwd.hpp>
#include "engine/utils/modelloaders/obj_loader.h"

class Gentry;
class Shader;
class Viewport;

class Model {
private:
    unsigned int VAO;
    unsigned int VBO;
    unsigned int EBO;
public:
    Model();
    void Initialize();
    void Draw(Gentry &gentry, Shader &shader, Viewport viewport) const;
};

#endif //RACCOONENGINE_MODEL_H
