#include "window.hpp"

#include <glad/gl.h>
#include <spdlog/spdlog.h>

Window::Window(const std::unique_ptr<GLContext> &context,
               const std::string &title)
    : m_title(title) {
  SPDLOG_DEBUG("Creating window {}", title);

  glfwDefaultWindowHints();
  glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
  m_handle =
      glfwCreateWindow(1280, 720, title.c_str(), nullptr, context->get_share());

  if (!m_handle) {
    SPDLOG_CRITICAL("Failed to create window");
    throw std::runtime_error("Failed to create window");
  }

  glfwMakeContextCurrent(m_handle);
}

Window::~Window() {
  SPDLOG_DEBUG("Destroying window {}", m_title);
  glfwDestroyWindow(m_handle);
}

void Window::set_visible(bool visible) {
  if (visible) {
    glfwShowWindow(m_handle);
  } else {
    glfwHideWindow(m_handle);
  }
}

void Window::present() { glfwSwapBuffers(m_handle); }

bool Window::should_close() { return glfwWindowShouldClose(m_handle); }
