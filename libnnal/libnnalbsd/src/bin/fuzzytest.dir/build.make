# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/cmake-gui

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/dak/libnnal/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dak/libnnal/src

# Include any dependencies generated for this target.
include CMakeFiles/../bin/fuzzytest.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/../bin/fuzzytest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/../bin/fuzzytest.dir/flags.make

CMakeFiles/../bin/fuzzytest.dir/test/fuzzytest.c.o: CMakeFiles/../bin/fuzzytest.dir/flags.make
CMakeFiles/../bin/fuzzytest.dir/test/fuzzytest.c.o: test/fuzzytest.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/dak/libnnal/src/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/../bin/fuzzytest.dir/test/fuzzytest.c.o"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/../bin/fuzzytest.dir/test/fuzzytest.c.o   -c /home/dak/libnnal/src/test/fuzzytest.c

CMakeFiles/../bin/fuzzytest.dir/test/fuzzytest.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/../bin/fuzzytest.dir/test/fuzzytest.c.i"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -E /home/dak/libnnal/src/test/fuzzytest.c > CMakeFiles/../bin/fuzzytest.dir/test/fuzzytest.c.i

CMakeFiles/../bin/fuzzytest.dir/test/fuzzytest.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/../bin/fuzzytest.dir/test/fuzzytest.c.s"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -S /home/dak/libnnal/src/test/fuzzytest.c -o CMakeFiles/../bin/fuzzytest.dir/test/fuzzytest.c.s

CMakeFiles/../bin/fuzzytest.dir/test/fuzzytest.c.o.requires:
.PHONY : CMakeFiles/../bin/fuzzytest.dir/test/fuzzytest.c.o.requires

CMakeFiles/../bin/fuzzytest.dir/test/fuzzytest.c.o.provides: CMakeFiles/../bin/fuzzytest.dir/test/fuzzytest.c.o.requires
	$(MAKE) -f CMakeFiles/../bin/fuzzytest.dir/build.make CMakeFiles/../bin/fuzzytest.dir/test/fuzzytest.c.o.provides.build
.PHONY : CMakeFiles/../bin/fuzzytest.dir/test/fuzzytest.c.o.provides

CMakeFiles/../bin/fuzzytest.dir/test/fuzzytest.c.o.provides.build: CMakeFiles/../bin/fuzzytest.dir/test/fuzzytest.c.o
.PHONY : CMakeFiles/../bin/fuzzytest.dir/test/fuzzytest.c.o.provides.build

# Object files for target ../bin/fuzzytest
__/bin/fuzzytest_OBJECTS = \
"CMakeFiles/../bin/fuzzytest.dir/test/fuzzytest.c.o"

# External object files for target ../bin/fuzzytest
__/bin/fuzzytest_EXTERNAL_OBJECTS =

../bin/fuzzytest: CMakeFiles/../bin/fuzzytest.dir/test/fuzzytest.c.o
../bin/fuzzytest: libneuralnetwork.a
../bin/fuzzytest: CMakeFiles/../bin/fuzzytest.dir/build.make
../bin/fuzzytest: CMakeFiles/../bin/fuzzytest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C executable ../bin/fuzzytest"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/../bin/fuzzytest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/../bin/fuzzytest.dir/build: ../bin/fuzzytest
.PHONY : CMakeFiles/../bin/fuzzytest.dir/build

CMakeFiles/../bin/fuzzytest.dir/requires: CMakeFiles/../bin/fuzzytest.dir/test/fuzzytest.c.o.requires
.PHONY : CMakeFiles/../bin/fuzzytest.dir/requires

CMakeFiles/../bin/fuzzytest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/../bin/fuzzytest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/../bin/fuzzytest.dir/clean

CMakeFiles/../bin/fuzzytest.dir/depend:
	cd /home/dak/libnnal/src && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dak/libnnal/src /home/dak/libnnal/src /home/dak/libnnal/src /home/dak/libnnal/src /home/dak/libnnal/src/bin/fuzzytest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/../bin/fuzzytest.dir/depend
