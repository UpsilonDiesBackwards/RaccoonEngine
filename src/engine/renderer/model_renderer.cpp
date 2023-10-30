#import <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>
#import "deps/glad/glad.h"
#import "engine/renderer/model_renderer.h"
#include "engine/gentries/entity.h"
#include "engine/renderer/shader_compiler.h"
#include "editor/viewport.h"
#include "engine/utils/modelloaders/obj_loader.h"

model_renderer::model_renderer() : VAO(0), VBO(0), EBO(0) {
}

void model_renderer::Initialize() {
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void model_renderer::Render(Gentry& gentry, Shader& shader, Viewport& viewport, const glm::mat4& projection) const {
    shader.Use();

    glUniformMatrix4fv(glGetUniformLocation(shader.ID, "project"), 1, GL_FALSE,&projection[0][0]);
    glm::mat4 viewMatrix = viewport.getViewMatrix();
    glUniformMatrix4fv(glGetUniformLocation(shader.ID, "camera"), 1, GL_FALSE,&viewMatrix[0][0]);

    for (const Mesh& mesh : gentry.meshes) {
        glm::mat4 modelMatrix = gentry.GenerateModelMatrix();

        std::cout << "\n" << "model matrix:" << glm::to_string(modelMatrix);

        glBindVertexArray(this->VAO);

        glUniformMatrix4fv(glGetUniformLocation(shader.ID, "model"), 1, GL_FALSE, &modelMatrix[0][0]);

        glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
        glBufferData(GL_ARRAY_BUFFER, mesh.vertices.size() * sizeof(float), &mesh.vertices[0], GL_STATIC_DRAW);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, mesh.indices.size() * sizeof(unsigned int), &mesh.indices[0], GL_STATIC_DRAW);

        glDrawElements(GL_TRIANGLES, mesh.indices.size(), GL_UNSIGNED_INT, nullptr);
    }

    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
