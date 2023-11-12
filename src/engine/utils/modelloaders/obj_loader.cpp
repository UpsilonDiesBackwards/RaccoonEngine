#include "engine/utils/modelloaders/obj_loader.h"

obj_loader::obj_loader(const std::string& filePath) : fPath(filePath) {}

bool obj_loader::Load() {
    Assimp::Importer importer;
    const aiScene* scene = importer.ReadFile(fPath, aiProcess_Triangulate | aiProcess_FlipUVs);
    
    if (!scene || scene-> mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) {
        return false;
    }

    for (unsigned int meshIndex =0; meshIndex < scene-> mNumMeshes; ++meshIndex) {
        const aiMesh* mesh = scene->mMeshes[meshIndex];
        Mesh newMesh;

        for (unsigned int vertexIndex = 0; vertexIndex < mesh->mNumVertices; ++vertexIndex) {
            aiVector3D vertex = mesh-> mVertices[vertexIndex];
            newMesh.vertices.push_back(vertex.x);
            newMesh.vertices.push_back(vertex.y);
            newMesh.vertices.push_back(vertex.z);            
        }

        for (unsigned int faceIndex = 0; faceIndex < mesh->mNumFaces; ++faceIndex) {
            const aiFace& face = mesh->mFaces[faceIndex];
            for (unsigned int indexIndex = 0; indexIndex < face.mNumIndices; ++indexIndex) {
                newMesh.indices.push_back(face.mIndices[indexIndex]);
            }
        }
        meshes.push_back(newMesh);
        
    }

    return true;
}

const std::vector<Mesh>& obj_loader::GetMeshes() const {
    return meshes;
}