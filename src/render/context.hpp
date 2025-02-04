#pragma once

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

class GLContext {
public:
	GLContext();
	~GLContext();

	GLFWwindow *get_share() const { return m_offscreen_window; }

private:
	GLFWwindow *m_offscreen_window;
};


