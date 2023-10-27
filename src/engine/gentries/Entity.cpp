#include "engine/gentries/Entity.h"

Gentry::Gentry(const Transform& transform, const std::string& fPath, std::string& name) : name(
        (std::string &) "Game Entity") {
    ObjLoader objLoader(fPath);
    objLoader.Load();

    meshes = objLoader.GetMeshes();
}

