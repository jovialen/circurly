#pragma once

#include <memory>

#include "window.hpp"

class Renderer {
public:
	Renderer(const std::shared_ptr<Window> &target);
	~Renderer();

	void render();

	void set_target(std::shared_ptr<Window> target);
	const std::shared_ptr<Window> &get_target() { return m_target; }

private:
	std::shared_ptr<Window> m_target;
};
