#include "engine/renderer/model_renderer.h"
#include "deps/glad/glad.h"
#include "engine/gentries/entity.h"
#include "engine/renderer/shader_compiler.h"
#include "editor/viewport.h"

model_renderer::model_renderer() : VAO(0), VBO(0), EBO(0) {
}

void model_renderer::Initialize() {
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

void model_renderer::Render(Gentry &gentry, Shader &shader, Viewport &viewport, glm::mat4 &projection) const {
    glUniformMatrix4fv(glGetUniformLocation(shader.ID, "projection"),
                       1, GL_FALSE, &projection[0][0]);

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
