#include "engine/gentries/entity.h"

Gentry::Gentry(const Transform& transform, const std::string& fPath, std::string& name) : name(
        (std::string &) "Game Entity") {
    obj_loader objLoader(fPath);
    objLoader.Load();

    meshes = objLoader.GetMeshes();
}

