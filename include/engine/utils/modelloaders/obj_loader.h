#ifndef RACCOONENGINE_OBJ_LOADER_H
#define RACCOONENGINE_OBJ_LOADER_H

#include <vector>
#include <string>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

struct Mesh {
    std::vector<float> vertices;
    std::vector<unsigned int> indices;
};

class obj_loader {
private:
    std::string fPath;
    std::vector<Mesh> meshes;
public:
    obj_loader(const std::string& fPath);
    bool Load();
    const std::vector<Mesh>& GetMeshes() const;
};

#endif // RACCOONENGINE_OBJ_LOADER_H
