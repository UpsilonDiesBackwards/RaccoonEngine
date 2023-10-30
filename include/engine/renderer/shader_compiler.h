#ifndef RACCOONENGINE_SHADER_COMPILER_H
#define RACCOONENGINE_SHADER_COMPILER_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <glm/glm.hpp>

class Shader {
private:
    void checkCompileErrors(unsigned int shader, std::string type);
public:
    Shader(const char* vPath, const char* fPath);
    void Use();
    void setBool(const std::string& name, bool value) const;
    void setInt(const std::string& name, int value) const;
    void setFloat(const std::string& name, float value) const;
    void setMat4(const std::string &name, const glm::mat4 &mat) const;

    unsigned int ID;
};

#endif /* RACCOONENGINE_SHADER_COMPILER_H  */
