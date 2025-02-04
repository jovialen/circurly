#include "context.hpp"

#include <glad/gl.h>
#include <spdlog/spdlog.h>

GLContext::GLContext() {
  SPDLOG_DEBUG("Creating OpenGL context");

  glfwDefaultWindowHints();
  glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);

  m_offscreen_window = glfwCreateWindow(100, 100, "Offscreen window", nullptr, nullptr);
  if (!m_offscreen_window) {
    SPDLOG_ERROR("Failed to create offscreen context");
    throw std::runtime_error("Failed to create offscreen context");
  }

  glfwMakeContextCurrent(m_offscreen_window);
  if (!gladLoadGL((GLADloadfunc) glfwGetProcAddress)) {
    SPDLOG_ERROR("Failed to load OpenGL");
    throw std::runtime_error("Failed to load OpenGL");
  }
}

GLContext::~GLContext() {
  SPDLOG_DEBUG("Destroying OpenGL context");
  glfwDestroyWindow(m_offscreen_window);
}
