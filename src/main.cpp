#include <memory>
#include <vector>

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>

#include "core/app.hpp"

bool init() {
  std::vector<spdlog::sink_ptr> sinks;
  sinks.emplace_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
  sinks.emplace_back(std::make_shared<spdlog::sinks::basic_file_sink_mt>("logs/circurly.log", true));
  auto error_log = sinks.emplace_back(std::make_shared<spdlog::sinks::basic_file_sink_mt>("logs/error.log", true));
  error_log->set_level(spdlog::level::warn);

  auto logger = std::make_shared<spdlog::logger>("Circurly", sinks.begin(), sinks.end());
  logger->set_level(spdlog::level::trace);

  spdlog::set_default_logger(logger);

  return glfwInit();
}

void terminate() {
  glfwTerminate();
}

int main(int argc, char *argv[]) {
  if (!init()) {
    return 1;
  }

  App app;
  app.run();

  terminate();
}
