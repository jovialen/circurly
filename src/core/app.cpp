#include "app.hpp"

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/gl.h>
#include <spdlog/spdlog.h>

#include "pages/start_page.hpp"

App::App() {
  SPDLOG_INFO("Initializing app");
  m_context = std::make_unique<GLContext>();
  m_window = std::make_shared<Window>(m_context, "Circurly");
  m_state = std::make_shared<AppState>();

  m_renderer = std::make_unique<Renderer>(m_window);

  m_state->page = std::make_shared<StartPage>();
  m_state->page->set_state(m_state);
}

void App::run() {
  SPDLOG_INFO("Starting...");
  m_state->running = true;

  // Setup
  glClearColor(0.15f, 0.15f, 0.15f, 1.0f);

  // First render is a bit slow, so do it while the window is invisible
  frame();
  m_window->set_visible(true);

  // Main loop
  while (!m_window->should_close() && m_state->running) {
    // Handle events
    if (!m_state->wait_for_events) {
      glfwPollEvents();
    } else {
      glfwWaitEvents();

      // Process two frames when waiting, one for events and one for rendering.
      // This prevents lag in the UI.
      frame(false);
    }

    frame();
  }

  SPDLOG_INFO("Stopping...");
}

void App::frame(bool render) {
  // Start frame
  m_renderer->begin_frame();

  // Process scene
  m_state->page->process();

  // End and render frame
  m_renderer->end_frame();
  if (render) {
    m_renderer->render_frame();
  }
}
