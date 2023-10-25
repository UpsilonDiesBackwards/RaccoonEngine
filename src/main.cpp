#include "engine/window.h"
#include "engine/utils/modelloaders/ObjLoader.h"
#include "engine/renderer/ModelRenderer.h"

int main () {
    Window window("Raccoon Engine // INDEV BUILD");

    ObjLoader objLoader("/home/tayler/Projects/WhiskyEngine/assets/models/tree.obj");
    ModelRenderer renderer;
    renderer.Initialize();
    const std::vector<Mesh>& meshes = objLoader.GetMeshes();
    objLoader.Load();

    while (!window.ShouldClose()) {
        window.PollEvents();
        
        renderer.Render(meshes);

        window.SwapBuffers();
    }

    return 0;
}
