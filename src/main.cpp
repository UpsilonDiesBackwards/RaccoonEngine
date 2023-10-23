#include "engine/window.h"

int main () {
    Window window("Raccoon Engine");

    while (!window.ShouldClose()) {
        window.PollEvents();
        
        window.SwapBuffers();
    }

    return 0;
}
