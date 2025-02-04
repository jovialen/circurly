#include "app.hpp"

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/gl.h>

App::App() { m_window = std::make_unique<Window>("Circurly"); }

void App::run() {
  // Load OpenGL
  glfwMakeContextCurrent(*m_window);
  if (!gladLoadGL((GLADloadfunc) glfwGetProcAddress)) {
    return;
  }

  // Setup
  glClearColor(1, 1, 1, 1);

  // Main loop
  while (!m_window->should_close()) {
    // Rendering
    glClear(GL_COLOR_BUFFER_BIT);

    // Present
    m_window->present();
    glfwWaitEvents();
  }
}
