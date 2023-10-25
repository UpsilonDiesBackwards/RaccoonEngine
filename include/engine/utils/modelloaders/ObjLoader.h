#ifndef RACCOONENGINE_OBJLOADER_H
#define RACCOONENGINE_OBJLOADER_H

#include <vector>
#include <string>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

struct Mesh {
    std::vector<float> vertices;
    std::vector<unsigned int> indices;
};

class ObjLoader {
private:
    std::string fPath;
    std::vector<Mesh> meshes;
public:
    ObjLoader(const std::string& fPath);
    bool Load();
    const std::vector<Mesh>& GetMeshes() const;
};

#endif // RACCOONENGINE_OBJLOADER_H
