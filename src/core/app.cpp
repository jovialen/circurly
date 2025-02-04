#include "app.hpp"

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/gl.h>

App::App() {}

void App::run() {
  // Load GLFW
  if (!glfwInit()) {
    return;
  }

  // Create window
  GLFWwindow *window =
      glfwCreateWindow(1280, 720, "Circurly", nullptr, nullptr);
  if (!window) {
    return;
  }

  // Load OpenGL
  glfwMakeContextCurrent(window);
  if (!gladLoadGL((GLADloadfunc) glfwGetProcAddress)) {
    return;
  }

  // Setup
  glClearColor(1, 1, 1, 1);

  // Main loop
  while (!glfwWindowShouldClose(window)) {
    // Rendering
    glClear(GL_COLOR_BUFFER_BIT);

    // Present
    glfwSwapBuffers(window);
    glfwWaitEvents();
  }

  // Cleanup
  glfwDestroyWindow(window);
  glfwTerminate();

  return;
}
