#pragma once

#include <memory>

#include "render/window.hpp"

class App {
public:
	App();

	void run();

private:
	std::unique_ptr<Window> m_window;
};

