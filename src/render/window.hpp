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

	void present();
	bool should_close();

	operator GLFWwindow *() const { return m_handle; };

private:
	GLFWwindow *m_handle;
};

