#pragma once

#include <memory>
#include <string>

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include "context.hpp"

class Window {
public:
  Window(const std::unique_ptr<GLContext> &context, const std::string &title);
  ~Window();

  void set_visible(bool visible);
  void present();
  bool should_close();

  GLFWwindow *get_handle() { return m_handle; }
  const std::string &get_title() { return m_title; }

private:
  GLFWwindow *m_handle;
  std::string m_title;
};
