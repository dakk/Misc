# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.6

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canoncical targets will work.
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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/cmake-gui

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/dak/libneuralnetworks/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dak/libneuralnetworks/src

# Include any dependencies generated for this target.
include CMakeFiles/neuralnetwork.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/neuralnetwork.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/neuralnetwork.dir/flags.make

CMakeFiles/neuralnetwork.dir/neuralnetwork.c.o: CMakeFiles/neuralnetwork.dir/flags.make
CMakeFiles/neuralnetwork.dir/neuralnetwork.c.o: neuralnetwork.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/dak/libneuralnetworks/src/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/neuralnetwork.dir/neuralnetwork.c.o"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/neuralnetwork.dir/neuralnetwork.c.o   -c /home/dak/libneuralnetworks/src/neuralnetwork.c

CMakeFiles/neuralnetwork.dir/neuralnetwork.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/neuralnetwork.dir/neuralnetwork.c.i"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -E /home/dak/libneuralnetworks/src/neuralnetwork.c > CMakeFiles/neuralnetwork.dir/neuralnetwork.c.i

CMakeFiles/neuralnetwork.dir/neuralnetwork.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/neuralnetwork.dir/neuralnetwork.c.s"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -S /home/dak/libneuralnetworks/src/neuralnetwork.c -o CMakeFiles/neuralnetwork.dir/neuralnetwork.c.s

CMakeFiles/neuralnetwork.dir/neuralnetwork.c.o.requires:
.PHONY : CMakeFiles/neuralnetwork.dir/neuralnetwork.c.o.requires

CMakeFiles/neuralnetwork.dir/neuralnetwork.c.o.provides: CMakeFiles/neuralnetwork.dir/neuralnetwork.c.o.requires
	$(MAKE) -f CMakeFiles/neuralnetwork.dir/build.make CMakeFiles/neuralnetwork.dir/neuralnetwork.c.o.provides.build
.PHONY : CMakeFiles/neuralnetwork.dir/neuralnetwork.c.o.provides

CMakeFiles/neuralnetwork.dir/neuralnetwork.c.o.provides.build: CMakeFiles/neuralnetwork.dir/neuralnetwork.c.o
.PHONY : CMakeFiles/neuralnetwork.dir/neuralnetwork.c.o.provides.build

# Object files for target neuralnetwork
neuralnetwork_OBJECTS = \
"CMakeFiles/neuralnetwork.dir/neuralnetwork.c.o"

# External object files for target neuralnetwork
neuralnetwork_EXTERNAL_OBJECTS =

libneuralnetwork.a: CMakeFiles/neuralnetwork.dir/neuralnetwork.c.o
libneuralnetwork.a: CMakeFiles/neuralnetwork.dir/build.make
libneuralnetwork.a: CMakeFiles/neuralnetwork.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C static library libneuralnetwork.a"
	$(CMAKE_COMMAND) -P CMakeFiles/neuralnetwork.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/neuralnetwork.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/neuralnetwork.dir/build: libneuralnetwork.a
.PHONY : CMakeFiles/neuralnetwork.dir/build

CMakeFiles/neuralnetwork.dir/requires: CMakeFiles/neuralnetwork.dir/neuralnetwork.c.o.requires
.PHONY : CMakeFiles/neuralnetwork.dir/requires

CMakeFiles/neuralnetwork.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/neuralnetwork.dir/cmake_clean.cmake
.PHONY : CMakeFiles/neuralnetwork.dir/clean

CMakeFiles/neuralnetwork.dir/depend:
	cd /home/dak/libneuralnetworks/src && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dak/libneuralnetworks/src /home/dak/libneuralnetworks/src /home/dak/libneuralnetworks/src /home/dak/libneuralnetworks/src /home/dak/libneuralnetworks/src/CMakeFiles/neuralnetwork.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/neuralnetwork.dir/depend
