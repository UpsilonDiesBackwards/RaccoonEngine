#include <glm/ext/matrix_clip_space.hpp>
#include <glm/gtx/string_cast.hpp>
#include "engine/renderer/model.h"
#include "deps/glad/glad.h"
#include "engine/gentries/entity.h"
#include "engine/renderer/shader_compiler.h"
#include "editor/viewport.h"
#include "engine/application/application.h"

Model::Model() : VAO(0), VBO(0), EBO(0) {
}

void Model::Initialize() {
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

Application app = Application::getApplicationInstance();
void Model::Draw(Gentry &gentry, Shader &shader, Viewport viewport) const {
    glm::mat4 perspective = glm::perspective(glm::radians(45.0f), app.mWindow.AspectRatio(), 0.1f, 100.0f);

    glUniformMatrix4fv(glGetUniformLocation(shader.ID, "projection"),
                       1, GL_FALSE, &perspective[0][0]);

    glm::mat4 viewMatrix = viewport.getViewMatrix();
    glUniformMatrix4fv(glGetUniformLocation(shader.ID, "view"),
                       1, GL_FALSE,&viewMatrix[0][0]);

   for (const Mesh& mesh : gentry.meshes) {
       glBindVertexArray(VAO);

       glm::mat4 modelMatrix = *gentry.GenerateModelMatrix();
       glUniformMatrix4fv(glGetUniformLocation(shader.ID, "model"),
                          1, GL_FALSE, &modelMatrix[0][0]);

       glBindBuffer(GL_ARRAY_BUFFER, VBO);
       glBufferData(GL_ARRAY_BUFFER, mesh.vertices.size() * sizeof(float), &mesh.vertices[0], GL_STATIC_DRAW);

       glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
       glBufferData(GL_ELEMENT_ARRAY_BUFFER, mesh.indices.size() * sizeof(unsigned int), &mesh.indices[0], GL_STATIC_DRAW);

       shader.Use();

       glDrawElements(GL_TRIANGLES, mesh.indices.size(), GL_UNSIGNED_INT, nullptr);
   }
    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
