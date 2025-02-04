#include "app.hpp"

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/gl.h>
#include <spdlog/spdlog.h>

App::App() {
  SPDLOG_INFO("Initializing app");
  m_context = std::make_unique<GLContext>();
  m_window = std::make_unique<Window>(m_context, "Circurly");

  m_renderer = std::make_unique<Renderer>(m_window);
}

void App::run() {
  SPDLOG_INFO("Starting...");

  // Setup
  glClearColor(1, 1, 1, 1);

  // Main loop
  while (!m_window->should_close()) {
    // Rendering
    m_renderer->render();

    // Handle events
    glfwWaitEvents();
  }

  SPDLOG_INFO("Stopping...");
}
