#include "editor/scene.h"
#include <fstream>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <cstdio>
#include <iostream>
#include <sstream>

scene::scene(const std::string& name) : name(name) { }

void scene::AddEntity(const Gentry& entity) {
    sceneEntities.push_back(entity);
}

const std::vector<Gentry>& scene::GetEntities() const {
    return sceneEntities;
}

const std::string& scene::GetName() const {
    return name;
}

bool scene::SaveScene(const std::string& fName) const {
    rapidjson::Document doc;
    rapidjson::Value sceneData(rapidjson::kObjectType);

    sceneData.AddMember("Name", rapidjson::Value(name.c_str(), doc.GetAllocator()), doc.GetAllocator());

    rapidjson::Value entityArray(rapidjson::kArrayType);
    for (const Gentry& entity : sceneEntities) {
        rapidjson::Value entityJson(rapidjson::kObjectType);

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

//    printf("Saved scene: %s", name.c_str());
    return false;
}

void scene::LoadScene(const std::string& filePath) {
    std::ifstream sceneFile(filePath);

    if(!sceneFile.is_open()) {
        std::cout << "Failed to open scene from the directory: " + filePath + " is there a corresponding *.rcsc scene File present?";
    }

    std::stringstream buffer;
    buffer << sceneFile.rdbuf();
    std::string jsonString = buffer.str();

    rapidjson::Document doc;
    doc.Parse(jsonString.c_str());

    if (doc.HasParseError()) {
        std::cout << "Error parsing scene file!";
        return;
    }

    const rapidjson::Value& entities = doc["Entities"];

    for (rapidjson::SizeType i = 0; i < entities.Size(); i++) {
        const rapidjson::Value& entityData = entities[i];

//        std::string name = entityData["Name"].GetString();

        double posX = entityData["PosX"].GetDouble();
        double posY = entityData["PosY"].GetDouble();
        double posZ = entityData["PosZ"].GetDouble();

        double eRotX = entityData["ERotX"].GetDouble();
        double eRotY = entityData["ERotY"].GetDouble();
        double eRotZ = entityData["ERotZ"].GetDouble();

        double scaX = entityData["ScaX"].GetDouble();
        double scaY = entityData["ScaY"].GetDouble();
        double scaZ = entityData["ScaZ"].GetDouble();

        Transform transform;
        transform.position = glm::vec3(posX, posY, posZ);
        transform.eulerRotation = glm::vec3(eRotX, eRotY, eRotZ);
        transform.scale = glm::vec3(scaX, scaY, scaZ);

        Gentry nGentry(transform, "", (std::string &) "");
        sceneEntities.push_back(nGentry);

        printf("Loaded scene: %s", name.c_str());
    }
}
