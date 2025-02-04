#include "window.hpp"

#include <spdlog/spdlog.h>

Window::Window(const std::string &title) {
  SPDLOG_DEBUG("Creating window {}", title);
  m_handle = glfwCreateWindow(1280, 720, title.c_str(), nullptr, nullptr);
}

Window::~Window() { 
  SPDLOG_DEBUG("Destroying window");
  glfwDestroyWindow(m_handle);
}

void Window::present() {
  glfwSwapBuffers(m_handle);
}

bool Window::should_close() { return glfwWindowShouldClose(m_handle); }
