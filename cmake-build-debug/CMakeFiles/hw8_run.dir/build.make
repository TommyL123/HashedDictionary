# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/tommythemoney/Documents/TommyL123-hw8

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/tommythemoney/Documents/TommyL123-hw8/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/hw8_run.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/hw8_run.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/hw8_run.dir/flags.make

CMakeFiles/hw8_run.dir/main.cpp.o: CMakeFiles/hw8_run.dir/flags.make
CMakeFiles/hw8_run.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/tommythemoney/Documents/TommyL123-hw8/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/hw8_run.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/hw8_run.dir/main.cpp.o -c /Users/tommythemoney/Documents/TommyL123-hw8/main.cpp

CMakeFiles/hw8_run.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hw8_run.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/tommythemoney/Documents/TommyL123-hw8/main.cpp > CMakeFiles/hw8_run.dir/main.cpp.i

CMakeFiles/hw8_run.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hw8_run.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/tommythemoney/Documents/TommyL123-hw8/main.cpp -o CMakeFiles/hw8_run.dir/main.cpp.s

CMakeFiles/hw8_run.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/hw8_run.dir/main.cpp.o.requires

CMakeFiles/hw8_run.dir/main.cpp.o.provides: CMakeFiles/hw8_run.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/hw8_run.dir/build.make CMakeFiles/hw8_run.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/hw8_run.dir/main.cpp.o.provides

CMakeFiles/hw8_run.dir/main.cpp.o.provides.build: CMakeFiles/hw8_run.dir/main.cpp.o


# Object files for target hw8_run
hw8_run_OBJECTS = \
"CMakeFiles/hw8_run.dir/main.cpp.o"

# External object files for target hw8_run
hw8_run_EXTERNAL_OBJECTS =

hw8_run: CMakeFiles/hw8_run.dir/main.cpp.o
hw8_run: CMakeFiles/hw8_run.dir/build.make
hw8_run: src/libhw8_library.a
hw8_run: CMakeFiles/hw8_run.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/tommythemoney/Documents/TommyL123-hw8/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable hw8_run"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hw8_run.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/hw8_run.dir/build: hw8_run

.PHONY : CMakeFiles/hw8_run.dir/build

CMakeFiles/hw8_run.dir/requires: CMakeFiles/hw8_run.dir/main.cpp.o.requires

.PHONY : CMakeFiles/hw8_run.dir/requires

CMakeFiles/hw8_run.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/hw8_run.dir/cmake_clean.cmake
.PHONY : CMakeFiles/hw8_run.dir/clean

CMakeFiles/hw8_run.dir/depend:
	cd /Users/tommythemoney/Documents/TommyL123-hw8/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/tommythemoney/Documents/TommyL123-hw8 /Users/tommythemoney/Documents/TommyL123-hw8 /Users/tommythemoney/Documents/TommyL123-hw8/cmake-build-debug /Users/tommythemoney/Documents/TommyL123-hw8/cmake-build-debug /Users/tommythemoney/Documents/TommyL123-hw8/cmake-build-debug/CMakeFiles/hw8_run.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/hw8_run.dir/depend

