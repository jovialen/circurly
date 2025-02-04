#include "app.hpp"

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/gl.h>
#include <spdlog/spdlog.h>

App::App() {
  SPDLOG_INFO("Initializing app");
  m_window = std::make_unique<Window>("Circurly");
}

void App::run() {
  SPDLOG_INFO("Starting...");

  // Load OpenGL
  SPDLOG_DEBUG("Loading OpenGL");
  glfwMakeContextCurrent(*m_window);
  if (!gladLoadGL((GLADloadfunc) glfwGetProcAddress)) {
    SPDLOG_CRITICAL("Failed to load OpenGL");
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

  SPDLOG_INFO("Stopping...");
}
