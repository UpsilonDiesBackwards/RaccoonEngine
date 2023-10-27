#include "engine/window.h"
#include "engine/utils/modelloaders/ObjLoader.h"
#include "engine/renderer/ModelRenderer.h"
#include "engine/gentries/Entity.h"
#include "editor/Scene.h"
#include <cstdio>
#include <iostream>

int main () {
    Scene nScene("Default Scene");
    Window window("Raccoon Engine // INDEV BUILD >> " + nScene.GetName());

    ModelRenderer renderer;
    renderer.Initialize();
    
    Transform transform1;
    Gentry Tree(transform1, "/home/tayler/Projects/WhiskyEngine/assets/models/tree.obj", (std::string &) "Tree");
    
    Transform transform2;
    Gentry Plane(transform2, "/home/tayler/Projects/RaccoonEngine/assets/models/plane.obj", (std::string &) "Plane");

    nScene.AddEntity(Tree);
    nScene.AddEntity(Plane);

    nScene.SaveScene("DefaultScene.rcsc");

    while (!window.ShouldClose()) {
        window.PollEvents();
        
        for (const Gentry& entity : nScene.GetEntities()) {
            renderer.Render(entity.meshes);
            std::cout << "Load gEntity" + entity.name + " from scene " + nScene.GetName();
        }
   
        window.SwapBuffers();
    }

    return 0;
}
