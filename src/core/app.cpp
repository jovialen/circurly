#include "app.hpp"

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/gl.h>
#include <spdlog/spdlog.h>

#include "pages/home_page.hpp"

App::App() {
  SPDLOG_INFO("Initializing app");
  m_context = std::make_unique<GLContext>();
  m_window = std::make_unique<Window>(m_context, "Circurly");

  m_renderer = std::make_unique<Renderer>(m_window);
  m_page = std::make_shared<HomePage>();
}

void App::run() {
  SPDLOG_INFO("Starting...");

  // Setup
  glClearColor(0.15f, 0.15f, 0.15f, 1.0f);

  // Main loop
  while (!m_window->should_close()) {
    // Start frame
    m_renderer->begin_frame();

    // Process scene
    for (auto next_page = m_page->process(); next_page != nullptr;
         next_page = m_page->process()) {
      m_renderer->restart_frame();
      m_page = next_page;
    }

    // End and render frame
    m_renderer->end_frame();

    // Handle events
    glfwWaitEvents();
  }

  SPDLOG_INFO("Stopping...");
}
