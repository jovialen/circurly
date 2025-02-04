#include "start_page.hpp"

#include <imgui.h>
#include <spdlog/spdlog.h>

void StartPage::process() {
  auto center = ImGui::GetMainViewport()->GetCenter();
  auto size = ImGui::GetMainViewport()->Size;
  ImGui::SetNextWindowPos(center, ImGuiCond_Always, ImVec2(0.5, 0.5));
  ImGui::SetNextWindowSize(ImVec2(250, 300), ImGuiCond_Appearing);

  switch (m_state) {
  case StartPageState::Init:
    init();
    break;
  case StartPageState::New:
    new_workspace();
    break;
  case StartPageState::Load:
    load_workspace();
    break;
  }
}

void StartPage::init() {
  ImGui::Begin("Circurly", nullptr,
               ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize |
                   ImGuiWindowFlags_NoCollapse);

  if (ImGui::Button("New workspace")) {
    m_state = StartPageState::New;
  }

  if (ImGui::Button("Load workspace")) {
    m_state = StartPageState::Load;
  }

  if (ImGui::Button("Quit")) {
    quit();
  }

  ImGui::End();
}

void StartPage::new_workspace() {
  ImGui::Begin("New workspace", nullptr,
               ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize |
                   ImGuiWindowFlags_NoCollapse);

  static char name[32] = {'\0'};
  ImGui::InputText("Name", name, 32,
                   ImGuiInputTextFlags_ElideLeft |
                       ImGuiInputTextFlags_CharsNoBlank);

  if (ImGui::Button("Back")) {
    m_state = StartPageState::Init;
  }

  ImGui::SameLine();
  if (ImGui::Button("Create")) {
    SPDLOG_WARN("Not implemented yet");
  }

  ImGui::End();
}

void StartPage::load_workspace() {
  ImGui::Begin("Load workspace", nullptr,
               ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize |
                   ImGuiWindowFlags_NoCollapse);

  static int selected = 0;
  static const char *workspace_names[10] = {"1", "2", "3", "4", "5",
                                            "6", "7", "8", "9", "10"};

  ImGui::ListBox("Workspaces", &selected, workspace_names, 10);

  if (ImGui::Button("Back")) {
    m_state = StartPageState::Init;
  }

  ImGui::SameLine();
  if (ImGui::Button("Load")) {
    SPDLOG_WARN("Not implemented yet");
  }

  ImGui::End();
}
