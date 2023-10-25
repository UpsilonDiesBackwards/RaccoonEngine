#ifndef RACCOONENGINE_CALLBACKS_H
#define RACCOONENGINE_CALLBACKS_H

#include <cstdio>
#include <GLFW/glfw3.h>

static void glfw_error_callback(int error, const char* erroDesc) {
    fprintf(stderr, "GLFW Error: %s\n", erroDesc);
    throw ("GLFW Error!");
}

static void glfw_window_close_callback(GLFWwindow* window) {
    printf("Window closed\n");
}

void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);


#endif /* ifndef  */
