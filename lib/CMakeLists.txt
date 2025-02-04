add_subdirectory("glfw")
add_subdirectory("glad2/cmake")

add_library(imgui "imgui/imgui.cpp")
target_include_directories(imgui PUBLIC "imgui")

set(GLAD_SOURCES_DIR "${CMAKE_CURRENT_SOURCE_DIR}/glad2")
glad_add_library(glad2 REPRODUCIBLE MX API gl:core=3.3)

