# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/aanvi/CLionProjects/CSCI2270_Assignment2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/aanvi/CLionProjects/CSCI2270_Assignment2/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/CSCI2270_Assignment2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/CSCI2270_Assignment2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CSCI2270_Assignment2.dir/flags.make

CMakeFiles/CSCI2270_Assignment2.dir/main.cpp.o: CMakeFiles/CSCI2270_Assignment2.dir/flags.make
CMakeFiles/CSCI2270_Assignment2.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/aanvi/CLionProjects/CSCI2270_Assignment2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CSCI2270_Assignment2.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CSCI2270_Assignment2.dir/main.cpp.o -c /Users/aanvi/CLionProjects/CSCI2270_Assignment2/main.cpp

CMakeFiles/CSCI2270_Assignment2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CSCI2270_Assignment2.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/aanvi/CLionProjects/CSCI2270_Assignment2/main.cpp > CMakeFiles/CSCI2270_Assignment2.dir/main.cpp.i

CMakeFiles/CSCI2270_Assignment2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CSCI2270_Assignment2.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/aanvi/CLionProjects/CSCI2270_Assignment2/main.cpp -o CMakeFiles/CSCI2270_Assignment2.dir/main.cpp.s

# Object files for target CSCI2270_Assignment2
CSCI2270_Assignment2_OBJECTS = \
"CMakeFiles/CSCI2270_Assignment2.dir/main.cpp.o"

# External object files for target CSCI2270_Assignment2
CSCI2270_Assignment2_EXTERNAL_OBJECTS =

CSCI2270_Assignment2: CMakeFiles/CSCI2270_Assignment2.dir/main.cpp.o
CSCI2270_Assignment2: CMakeFiles/CSCI2270_Assignment2.dir/build.make
CSCI2270_Assignment2: CMakeFiles/CSCI2270_Assignment2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/aanvi/CLionProjects/CSCI2270_Assignment2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable CSCI2270_Assignment2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CSCI2270_Assignment2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CSCI2270_Assignment2.dir/build: CSCI2270_Assignment2

.PHONY : CMakeFiles/CSCI2270_Assignment2.dir/build

CMakeFiles/CSCI2270_Assignment2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CSCI2270_Assignment2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CSCI2270_Assignment2.dir/clean

CMakeFiles/CSCI2270_Assignment2.dir/depend:
	cd /Users/aanvi/CLionProjects/CSCI2270_Assignment2/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/aanvi/CLionProjects/CSCI2270_Assignment2 /Users/aanvi/CLionProjects/CSCI2270_Assignment2 /Users/aanvi/CLionProjects/CSCI2270_Assignment2/cmake-build-debug /Users/aanvi/CLionProjects/CSCI2270_Assignment2/cmake-build-debug /Users/aanvi/CLionProjects/CSCI2270_Assignment2/cmake-build-debug/CMakeFiles/CSCI2270_Assignment2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CSCI2270_Assignment2.dir/depend
