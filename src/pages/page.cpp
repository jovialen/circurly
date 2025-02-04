#include "page.hpp"

#include <spdlog/spdlog.h>

#include "core/app.hpp"

void Page::quit() {
  SPDLOG_DEBUG("Requesting stop");
  m_state->running = false;
}

void Page::switch_page(const std::shared_ptr<Page> &page) {
  SPDLOG_INFO("Switching scene");
  page->set_state(m_state);
  m_state->page = page;
}

void Page::wait_for_events(bool wait) {
  SPDLOG_DEBUG("{} for events before processing",
               wait ? "Waiting" : "Not waiting");
  m_state->wait_for_events = wait;
}
