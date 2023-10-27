#ifndef RACCOONENGINE_SHADER_COMPILER_H
#define RACCOONENGINE_SHADER_COMPILER_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader {
private:
    unsigned int ID;
    void checkCompileErrors(unsigned int shader, std::string type);
public:
    Shader(const char* vPath, const char* fPath);
    void Use();
    void setBool(const std::string& name, bool value) const;
    void setInt(const std::string& name, int value) const;
    void setFloat(const std::string& name, float value) const;
};

#endif /* RACCOONENGINE_SHADER_COMPILER_H  */
