# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.31

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/nicolai/dev/circulrly

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nicolai/dev/circulrly/bin

# Include any dependencies generated for this target.
include CMakeFiles/circurly.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/circurly.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/circurly.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/circurly.dir/flags.make

CMakeFiles/circurly.dir/codegen:
.PHONY : CMakeFiles/circurly.dir/codegen

CMakeFiles/circurly.dir/src/main.cpp.o: CMakeFiles/circurly.dir/flags.make
CMakeFiles/circurly.dir/src/main.cpp.o: /home/nicolai/dev/circulrly/src/main.cpp
CMakeFiles/circurly.dir/src/main.cpp.o: CMakeFiles/circurly.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/nicolai/dev/circulrly/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/circurly.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/circurly.dir/src/main.cpp.o -MF CMakeFiles/circurly.dir/src/main.cpp.o.d -o CMakeFiles/circurly.dir/src/main.cpp.o -c /home/nicolai/dev/circulrly/src/main.cpp

CMakeFiles/circurly.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/circurly.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nicolai/dev/circulrly/src/main.cpp > CMakeFiles/circurly.dir/src/main.cpp.i

CMakeFiles/circurly.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/circurly.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nicolai/dev/circulrly/src/main.cpp -o CMakeFiles/circurly.dir/src/main.cpp.s

# Object files for target circurly
circurly_OBJECTS = \
"CMakeFiles/circurly.dir/src/main.cpp.o"

# External object files for target circurly
circurly_EXTERNAL_OBJECTS =

circurly: CMakeFiles/circurly.dir/src/main.cpp.o
circurly: CMakeFiles/circurly.dir/build.make
circurly: CMakeFiles/circurly.dir/compiler_depend.ts
circurly: CMakeFiles/circurly.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/nicolai/dev/circulrly/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable circurly"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/circurly.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/circurly.dir/build: circurly
.PHONY : CMakeFiles/circurly.dir/build

CMakeFiles/circurly.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/circurly.dir/cmake_clean.cmake
.PHONY : CMakeFiles/circurly.dir/clean

CMakeFiles/circurly.dir/depend:
	cd /home/nicolai/dev/circulrly/bin && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nicolai/dev/circulrly /home/nicolai/dev/circulrly /home/nicolai/dev/circulrly/bin /home/nicolai/dev/circulrly/bin /home/nicolai/dev/circulrly/bin/CMakeFiles/circurly.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/circurly.dir/depend

