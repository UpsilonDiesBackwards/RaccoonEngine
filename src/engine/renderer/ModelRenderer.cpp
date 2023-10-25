#include "engine/renderer/ModelRenderer.h"
#include "deps/glad/glad.h"

ModelRenderer::ModelRenderer() : VAO(0), VBO(0), EBO(0) {
}

void ModelRenderer::Initialize() {
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0); // Need to change this! (probably)
   
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void ModelRenderer::Render(const std::vector<Mesh>& meshes) {
   glBindVertexArray(VAO);

   for (const Mesh& mesh : meshes) {
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, mesh.vertices.size() * sizeof(float), &mesh.vertices[0], GL_STATIC_DRAW);

        glDrawElements(GL_TRIANGLES, mesh.indices.size(), GL_UNSIGNED_INT, &mesh.indices[0]);
   }

   glBindVertexArray(0);
   glBindBuffer(GL_ARRAY_BUFFER, 0);
}
