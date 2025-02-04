add_subdirectory("glfw")
add_subdirectory("glad2/cmake")
add_subdirectory("spdlog")

add_library(imgui
	"imgui/imgui.cpp"
	"imgui/imgui_draw.cpp"
	"imgui/imgui_demo.cpp"
	"imgui/imgui_tables.cpp"
	"imgui/imgui_widgets.cpp"
	"imgui/backends/imgui_impl_opengl3.cpp"
	"imgui/backends/imgui_impl_glfw.cpp"
)

target_include_directories(imgui PUBLIC "imgui")
target_link_libraries(imgui PUBLIC glfw)

set(GLAD_SOURCES_DIR "${CMAKE_CURRENT_SOURCE_DIR}/glad2")
glad_add_library(glad2 REPRODUCIBLE API gl:core=3.3)

