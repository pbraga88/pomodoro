# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
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
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/pbraga/Workspace/Pessoal/Repositories/Pomodoro/pomodoro/cmake

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pbraga/Workspace/Pessoal/Repositories/Pomodoro/pomodoro/cmake/build

# Include any dependencies generated for this target.
include CMakeFiles/Pomodoro.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Pomodoro.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Pomodoro.dir/flags.make

CMakeFiles/Pomodoro.dir/src/main.cpp.o: CMakeFiles/Pomodoro.dir/flags.make
CMakeFiles/Pomodoro.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pbraga/Workspace/Pessoal/Repositories/Pomodoro/pomodoro/cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Pomodoro.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Pomodoro.dir/src/main.cpp.o -c /home/pbraga/Workspace/Pessoal/Repositories/Pomodoro/pomodoro/cmake/src/main.cpp

CMakeFiles/Pomodoro.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Pomodoro.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pbraga/Workspace/Pessoal/Repositories/Pomodoro/pomodoro/cmake/src/main.cpp > CMakeFiles/Pomodoro.dir/src/main.cpp.i

CMakeFiles/Pomodoro.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Pomodoro.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pbraga/Workspace/Pessoal/Repositories/Pomodoro/pomodoro/cmake/src/main.cpp -o CMakeFiles/Pomodoro.dir/src/main.cpp.s

# Object files for target Pomodoro
Pomodoro_OBJECTS = \
"CMakeFiles/Pomodoro.dir/src/main.cpp.o"

# External object files for target Pomodoro
Pomodoro_EXTERNAL_OBJECTS =

bin/Pomodoro: CMakeFiles/Pomodoro.dir/src/main.cpp.o
bin/Pomodoro: CMakeFiles/Pomodoro.dir/build.make
bin/Pomodoro: lib/libpomodoroLib.so
bin/Pomodoro: CMakeFiles/Pomodoro.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pbraga/Workspace/Pessoal/Repositories/Pomodoro/pomodoro/cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable bin/Pomodoro"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Pomodoro.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Pomodoro.dir/build: bin/Pomodoro

.PHONY : CMakeFiles/Pomodoro.dir/build

CMakeFiles/Pomodoro.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Pomodoro.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Pomodoro.dir/clean

CMakeFiles/Pomodoro.dir/depend:
	cd /home/pbraga/Workspace/Pessoal/Repositories/Pomodoro/pomodoro/cmake/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pbraga/Workspace/Pessoal/Repositories/Pomodoro/pomodoro/cmake /home/pbraga/Workspace/Pessoal/Repositories/Pomodoro/pomodoro/cmake /home/pbraga/Workspace/Pessoal/Repositories/Pomodoro/pomodoro/cmake/build /home/pbraga/Workspace/Pessoal/Repositories/Pomodoro/pomodoro/cmake/build /home/pbraga/Workspace/Pessoal/Repositories/Pomodoro/pomodoro/cmake/build/CMakeFiles/Pomodoro.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Pomodoro.dir/depend

