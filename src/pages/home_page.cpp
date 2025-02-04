#include "home_page.hpp"

#include <imgui.h>

std::shared_ptr<Page> HomePage::process() {
  ImGui::ShowDemoWindow();
  return nullptr;
}
