#ifndef RACCOONENGINE_CALLBACKS_H
#define RACCOONENGINE_CALLBACKS_H

#include <cstdio>
#include <GLFW/glfw3.h>

static void glfw_error_callback(int error, const char* erroDesc) {
    std::cerr << "GLFW Error: " << erroDesc << std::endl;
    throw ("GLFW Error!");
}

static void glfw_window_close_callback(GLFWwindow* window) {
    printf("\n\nWindow closed");
    glfwSetWindowShouldClose(window, GLFW_TRUE);
}

#endif /* ifndef  */
