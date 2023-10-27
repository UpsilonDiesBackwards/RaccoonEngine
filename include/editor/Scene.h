#ifndef RACCOONENGINE_SCENE_H
#define RACCOONENGINE_SCENE_H

#include "engine/gentries/Entity.h"

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
};

#endif // RACCOONENGINE_SCENE_H 
