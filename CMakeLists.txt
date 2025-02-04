cmake_minimum_required(VERSION 3.10.0 FATAL_ERROR)
project(circurly VERSION 0.1.0 LANGUAGES C CXX)

add_subdirectory("lib")

set(CIR_SOURCES
	"src/main.cpp"
	"src/core/app.cpp"
	"src/pages/home_page.cpp"
	"src/pages/page.cpp"
	"src/render/context.cpp"
	"src/render/renderer.cpp"
	"src/render/window.cpp"
)

add_executable(circurly ${CIR_SOURCES})

target_include_directories(circurly PRIVATE "src")

target_compile_definitions(circurly PRIVATE "SPDLOG_ACTIVE_LEVEL=SPDLOG_LEVEL_TRACE")

target_link_libraries(circurly PRIVATE glfw glad2 imgui spdlog)

set_target_properties(circurly PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON
	CXX_EXTENSIONS OFF
	POSITION_INDEPENDENT_CODE ON
	FOLDER "Circurly")

