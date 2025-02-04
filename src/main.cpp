#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/gl.h>

int main(int argc, char *argv[]) {
  // Load GLFW
  if (!glfwInit()) {
    return 1;
  }

  // Create window
  GLFWwindow *window =
      glfwCreateWindow(1280, 720, "Circurly", nullptr, nullptr);
  if (!window) {
    return 2;
  }

  // Load OpenGL
  glfwMakeContextCurrent(window);
  if (!gladLoadGL((GLADloadfunc) glfwGetProcAddress)) {
    return 3;
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

  return 0;
}
