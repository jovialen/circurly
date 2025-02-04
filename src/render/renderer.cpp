#include "renderer.hpp"

#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>
#include <imgui.h>
#include <glad/gl.h>

#include <spdlog/spdlog.h>

Renderer::Renderer(const std::shared_ptr<Window> &target) {
  SPDLOG_DEBUG("Creating renderer");

  // Configure ImGui
  IMGUI_CHECKVERSION();
  ImGui::CreateContext();

  ImGuiIO &io = ImGui::GetIO();
  io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
  io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;

  // Setup backend
  if (!ImGui_ImplOpenGL3_Init()) {
    SPDLOG_ERROR("Failed to initialize OpenGL backend for the renderer");
    throw std::runtime_error(
        "Failed to initialize OpenGL backend for the renderer");
  }
  set_target(target);
}

Renderer::~Renderer() {
  SPDLOG_DEBUG("Destroying renderer");

  ImGui_ImplOpenGL3_Shutdown();
  ImGui_ImplGlfw_Shutdown();
  ImGui::DestroyContext();
}

void Renderer::render() {
  ImGui_ImplOpenGL3_NewFrame();
  ImGui_ImplGlfw_NewFrame();
  ImGui::NewFrame();

  ImGui::ShowDemoWindow();

  ImGui::Render();

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
  m_target->present();
}

void Renderer::set_target(std::shared_ptr<Window> target) {
  if (!ImGui_ImplGlfw_InitForOpenGL(target->get_handle(), true)) {
    SPDLOG_ERROR("Failed to set window as render target");
    throw std::runtime_error("Failed to set window as render target");
  }

  m_target = target;
}
