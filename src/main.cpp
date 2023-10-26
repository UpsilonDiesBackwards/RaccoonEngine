#include "engine/window.h"
#include "engine/utils/modelloaders/ObjLoader.h"
#include "engine/renderer/ModelRenderer.h"
#include "engine/gentries/Entity.h"

int main () {
    Window window("Raccoon Engine // INDEV BUILD // ASSET LOADING");

    ModelRenderer renderer;
    renderer.Initialize();
    
    Gentry entity(entity.transform, "/home/tayler/Projects/WhiskyEngine/assets/models/tree.obj");

    while (!window.ShouldClose()) {
        window.PollEvents();
        
        renderer.Render(entity.meshes);

        window.SwapBuffers();
    }

    return 0;
}
