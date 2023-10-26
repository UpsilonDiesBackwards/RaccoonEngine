#include "engine/gentries/Entity.h"

Gentry::Gentry(const Transform& transform, const std::string& fPath) {
    ObjLoader objLoader(fPath);
    objLoader.Load();

    meshes = objLoader.GetMeshes();
}

