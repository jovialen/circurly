#pragma once

#include <memory>

struct AppState;

class Page {
public:
  virtual ~Page() = default;

  virtual void process() = 0;

  void set_state(std::shared_ptr<AppState> state) { m_state = state; }

  void quit();
  void switch_page(const std::shared_ptr<Page> &page);
  void wait_for_events(bool wait = true);

protected:
  std::shared_ptr<AppState> m_state;
};
