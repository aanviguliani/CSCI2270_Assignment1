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
CMAKE_SOURCE_DIR = /Users/aanvi/CLionProjects/CSCI2270_Assignment4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/aanvi/CLionProjects/CSCI2270_Assignment4/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ProducerConsumer.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ProducerConsumer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ProducerConsumer.dir/flags.make

CMakeFiles/ProducerConsumer.dir/ProducerConsumer.cpp.o: CMakeFiles/ProducerConsumer.dir/flags.make
CMakeFiles/ProducerConsumer.dir/ProducerConsumer.cpp.o: ../ProducerConsumer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/aanvi/CLionProjects/CSCI2270_Assignment4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ProducerConsumer.dir/ProducerConsumer.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ProducerConsumer.dir/ProducerConsumer.cpp.o -c /Users/aanvi/CLionProjects/CSCI2270_Assignment4/ProducerConsumer.cpp

CMakeFiles/ProducerConsumer.dir/ProducerConsumer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ProducerConsumer.dir/ProducerConsumer.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/aanvi/CLionProjects/CSCI2270_Assignment4/ProducerConsumer.cpp > CMakeFiles/ProducerConsumer.dir/ProducerConsumer.cpp.i

CMakeFiles/ProducerConsumer.dir/ProducerConsumer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ProducerConsumer.dir/ProducerConsumer.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/aanvi/CLionProjects/CSCI2270_Assignment4/ProducerConsumer.cpp -o CMakeFiles/ProducerConsumer.dir/ProducerConsumer.cpp.s

CMakeFiles/ProducerConsumer.dir/ProducerConsumerDriver.cpp.o: CMakeFiles/ProducerConsumer.dir/flags.make
CMakeFiles/ProducerConsumer.dir/ProducerConsumerDriver.cpp.o: ../ProducerConsumerDriver.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/aanvi/CLionProjects/CSCI2270_Assignment4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ProducerConsumer.dir/ProducerConsumerDriver.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ProducerConsumer.dir/ProducerConsumerDriver.cpp.o -c /Users/aanvi/CLionProjects/CSCI2270_Assignment4/ProducerConsumerDriver.cpp

CMakeFiles/ProducerConsumer.dir/ProducerConsumerDriver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ProducerConsumer.dir/ProducerConsumerDriver.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/aanvi/CLionProjects/CSCI2270_Assignment4/ProducerConsumerDriver.cpp > CMakeFiles/ProducerConsumer.dir/ProducerConsumerDriver.cpp.i

CMakeFiles/ProducerConsumer.dir/ProducerConsumerDriver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ProducerConsumer.dir/ProducerConsumerDriver.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/aanvi/CLionProjects/CSCI2270_Assignment4/ProducerConsumerDriver.cpp -o CMakeFiles/ProducerConsumer.dir/ProducerConsumerDriver.cpp.s

# Object files for target ProducerConsumer
ProducerConsumer_OBJECTS = \
"CMakeFiles/ProducerConsumer.dir/ProducerConsumer.cpp.o" \
"CMakeFiles/ProducerConsumer.dir/ProducerConsumerDriver.cpp.o"

# External object files for target ProducerConsumer
ProducerConsumer_EXTERNAL_OBJECTS =

ProducerConsumer: CMakeFiles/ProducerConsumer.dir/ProducerConsumer.cpp.o
ProducerConsumer: CMakeFiles/ProducerConsumer.dir/ProducerConsumerDriver.cpp.o
ProducerConsumer: CMakeFiles/ProducerConsumer.dir/build.make
ProducerConsumer: CMakeFiles/ProducerConsumer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/aanvi/CLionProjects/CSCI2270_Assignment4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ProducerConsumer"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ProducerConsumer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ProducerConsumer.dir/build: ProducerConsumer

.PHONY : CMakeFiles/ProducerConsumer.dir/build

CMakeFiles/ProducerConsumer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ProducerConsumer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ProducerConsumer.dir/clean

CMakeFiles/ProducerConsumer.dir/depend:
	cd /Users/aanvi/CLionProjects/CSCI2270_Assignment4/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/aanvi/CLionProjects/CSCI2270_Assignment4 /Users/aanvi/CLionProjects/CSCI2270_Assignment4 /Users/aanvi/CLionProjects/CSCI2270_Assignment4/cmake-build-debug /Users/aanvi/CLionProjects/CSCI2270_Assignment4/cmake-build-debug /Users/aanvi/CLionProjects/CSCI2270_Assignment4/cmake-build-debug/CMakeFiles/ProducerConsumer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ProducerConsumer.dir/depend

