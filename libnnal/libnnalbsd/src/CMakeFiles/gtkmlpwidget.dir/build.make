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
include CMakeFiles/gtkmlpwidget.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/gtkmlpwidget.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/gtkmlpwidget.dir/flags.make

CMakeFiles/gtkmlpwidget.dir/gtkmlpwidget.c.o: CMakeFiles/gtkmlpwidget.dir/flags.make
CMakeFiles/gtkmlpwidget.dir/gtkmlpwidget.c.o: gtkmlpwidget.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/dak/libnnal/src/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/gtkmlpwidget.dir/gtkmlpwidget.c.o"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/gtkmlpwidget.dir/gtkmlpwidget.c.o   -c /home/dak/libnnal/src/gtkmlpwidget.c

CMakeFiles/gtkmlpwidget.dir/gtkmlpwidget.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/gtkmlpwidget.dir/gtkmlpwidget.c.i"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -E /home/dak/libnnal/src/gtkmlpwidget.c > CMakeFiles/gtkmlpwidget.dir/gtkmlpwidget.c.i

CMakeFiles/gtkmlpwidget.dir/gtkmlpwidget.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/gtkmlpwidget.dir/gtkmlpwidget.c.s"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -S /home/dak/libnnal/src/gtkmlpwidget.c -o CMakeFiles/gtkmlpwidget.dir/gtkmlpwidget.c.s

CMakeFiles/gtkmlpwidget.dir/gtkmlpwidget.c.o.requires:
.PHONY : CMakeFiles/gtkmlpwidget.dir/gtkmlpwidget.c.o.requires

CMakeFiles/gtkmlpwidget.dir/gtkmlpwidget.c.o.provides: CMakeFiles/gtkmlpwidget.dir/gtkmlpwidget.c.o.requires
	$(MAKE) -f CMakeFiles/gtkmlpwidget.dir/build.make CMakeFiles/gtkmlpwidget.dir/gtkmlpwidget.c.o.provides.build
.PHONY : CMakeFiles/gtkmlpwidget.dir/gtkmlpwidget.c.o.provides

CMakeFiles/gtkmlpwidget.dir/gtkmlpwidget.c.o.provides.build: CMakeFiles/gtkmlpwidget.dir/gtkmlpwidget.c.o
.PHONY : CMakeFiles/gtkmlpwidget.dir/gtkmlpwidget.c.o.provides.build

# Object files for target gtkmlpwidget
gtkmlpwidget_OBJECTS = \
"CMakeFiles/gtkmlpwidget.dir/gtkmlpwidget.c.o"

# External object files for target gtkmlpwidget
gtkmlpwidget_EXTERNAL_OBJECTS =

libgtkmlpwidget.a: CMakeFiles/gtkmlpwidget.dir/gtkmlpwidget.c.o
libgtkmlpwidget.a: CMakeFiles/gtkmlpwidget.dir/build.make
libgtkmlpwidget.a: CMakeFiles/gtkmlpwidget.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C static library libgtkmlpwidget.a"
	$(CMAKE_COMMAND) -P CMakeFiles/gtkmlpwidget.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gtkmlpwidget.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/gtkmlpwidget.dir/build: libgtkmlpwidget.a
.PHONY : CMakeFiles/gtkmlpwidget.dir/build

CMakeFiles/gtkmlpwidget.dir/requires: CMakeFiles/gtkmlpwidget.dir/gtkmlpwidget.c.o.requires
.PHONY : CMakeFiles/gtkmlpwidget.dir/requires

CMakeFiles/gtkmlpwidget.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/gtkmlpwidget.dir/cmake_clean.cmake
.PHONY : CMakeFiles/gtkmlpwidget.dir/clean

CMakeFiles/gtkmlpwidget.dir/depend:
	cd /home/dak/libnnal/src && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dak/libnnal/src /home/dak/libnnal/src /home/dak/libnnal/src /home/dak/libnnal/src /home/dak/libnnal/src/CMakeFiles/gtkmlpwidget.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/gtkmlpwidget.dir/depend

