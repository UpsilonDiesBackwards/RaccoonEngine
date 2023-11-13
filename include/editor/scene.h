#ifndef RACCOONENGINE_SCENE_H
#define RACCOONENGINE_SCENE_H

#include "engine/gentries/entity.h"

class Scene {
private:
    std::string name;
    std::vector<Gentry> sceneEntities;
public:
    Scene(const std::string& name);
    void AddEntity(const Gentry& entity);
    const std::vector<Gentry>& GetEntities() const;
    const std::string& GetName() const;
    bool SaveScene(const std::string& fileName) const;
    void LoadScene(const std::string& fileName);
};

#endif // RACCOONENGINE_SCENE_H 
