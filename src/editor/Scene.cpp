#include "editor/Scene.h"
#include <fstream>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

Scene::Scene(const std::string& name) : name(name) { }

void Scene::AddEntity(const Gentry& entity) {
    sceneEntities.push_back(entity);
}

const std::vector<Gentry>& Scene::GetEntities() const {
    return sceneEntities;
}

const std::string& Scene::GetName() const {
    return name;
}

bool Scene::SaveScene(const std::string& fName) const {
    rapidjson::Document doc;
    rapidjson::Value sceneData(rapidjson::kObjectType);

    sceneData.AddMember("Name", rapidjson::Value(name.c_str(), doc.GetAllocator()), doc.GetAllocator());

    rapidjson::Value entityArray(rapidjson::kArrayType);
    for (const Gentry& entity : sceneEntities) {
        rapidjson::Value entityJson(rapidjson::kObjectType);

        entityJson.AddMember("Name", entity.name, doc.GetAllocator());

        entityJson.AddMember("PosX", entity.transform.position.x, doc.GetAllocator());
        entityJson.AddMember("PosY", entity.transform.position.y, doc.GetAllocator());
        entityJson.AddMember("PosZ", entity.transform.position.z, doc.GetAllocator());

        entityJson.AddMember("ERotX", entity.transform.eulerRotation.x, doc.GetAllocator());
        entityJson.AddMember("ERotY", entity.transform.eulerRotation.y, doc.GetAllocator());
        entityJson.AddMember("ERotZ", entity.transform.eulerRotation.z, doc.GetAllocator());

        entityJson.AddMember("ScaX", entity.transform.scale.x, doc.GetAllocator());
        entityJson.AddMember("ScaY", entity.transform.scale.y, doc.GetAllocator());
        entityJson.AddMember("ScaZ", entity.transform.scale.z, doc.GetAllocator());   

        entityArray.PushBack(entityJson, doc.GetAllocator());
    }
    sceneData.AddMember("Entities", entityArray, doc.GetAllocator());

    rapidjson::StringBuffer buffer;
    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
    sceneData.Accept(writer);

    std::ofstream file(fName);
    if (file.is_open()) {
        file << buffer.GetString();
        file.close();
        return true;
    }

    return false;
}
