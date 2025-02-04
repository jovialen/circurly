#include "workspace_page.hpp"

#include <imgui.h>
#include <spdlog/spdlog.h>

WorkspacePage::WorkspacePage(const std::string &name) : m_name(name) {
  SPDLOG_INFO("Loading workspace {}", name);
}

void WorkspacePage::process() {
  ImGui::PushStyleColor(ImGuiCol_DockingEmptyBg, ImVec4(0.15, 0.15, 0.15, 1.0));
  ImGui::DockSpaceOverViewport();

  ImGui::ShowDemoWindow();

  ImGui::PopStyleColor();
}
