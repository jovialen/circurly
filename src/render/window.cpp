#include "window.hpp"

Window::Window(const std::string &title) {
  m_handle = glfwCreateWindow(1280, 720, title.c_str(), nullptr, nullptr);
}

Window::~Window() { glfwDestroyWindow(m_handle); }

void Window::present() {
  glfwSwapBuffers(m_handle);
}

bool Window::should_close() { return glfwWindowShouldClose(m_handle); }
