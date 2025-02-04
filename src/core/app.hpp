#pragma once

#include <memory>

#include "render/context.hpp"
#include "render/renderer.hpp"
#include "render/window.hpp"

class App {
public:
	App();

	void run();

private:
	std::unique_ptr<GLContext> m_context;
	std::unique_ptr<Renderer> m_renderer;
	std::shared_ptr<Window> m_window;
};

