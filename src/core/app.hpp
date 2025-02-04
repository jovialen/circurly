#pragma once

#include <memory>

#include "pages/page.hpp"
#include "render/context.hpp"
#include "render/renderer.hpp"
#include "render/window.hpp"

struct AppState {
  bool running = true;
  bool wait_for_events = true;
  std::shared_ptr<Page> page;
};

class App {
public:
  App();

  void run();

  const std::shared_ptr<AppState> &get_state() const { return m_state; }

private:
  void frame(bool render = true);

private:
  std::unique_ptr<GLContext> m_context;
  std::shared_ptr<Window> m_window;
  std::unique_ptr<Renderer> m_renderer;

  std::shared_ptr<AppState> m_state;
};
