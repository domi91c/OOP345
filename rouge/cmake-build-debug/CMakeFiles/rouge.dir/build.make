# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_SOURCE_DIR = /Users/domi91c/OOP345/rouge

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/domi91c/OOP345/rouge/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/rouge.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/rouge.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/rouge.dir/flags.make

CMakeFiles/rouge.dir/main.cpp.o: CMakeFiles/rouge.dir/flags.make
CMakeFiles/rouge.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/domi91c/OOP345/rouge/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/rouge.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/rouge.dir/main.cpp.o -c /Users/domi91c/OOP345/rouge/main.cpp

CMakeFiles/rouge.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rouge.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/domi91c/OOP345/rouge/main.cpp > CMakeFiles/rouge.dir/main.cpp.i

CMakeFiles/rouge.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rouge.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/domi91c/OOP345/rouge/main.cpp -o CMakeFiles/rouge.dir/main.cpp.s

CMakeFiles/rouge.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/rouge.dir/main.cpp.o.requires

CMakeFiles/rouge.dir/main.cpp.o.provides: CMakeFiles/rouge.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/rouge.dir/build.make CMakeFiles/rouge.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/rouge.dir/main.cpp.o.provides

CMakeFiles/rouge.dir/main.cpp.o.provides.build: CMakeFiles/rouge.dir/main.cpp.o


# Object files for target rouge
rouge_OBJECTS = \
"CMakeFiles/rouge.dir/main.cpp.o"

# External object files for target rouge
rouge_EXTERNAL_OBJECTS =

rouge: CMakeFiles/rouge.dir/main.cpp.o
rouge: CMakeFiles/rouge.dir/build.make
rouge: CMakeFiles/rouge.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/domi91c/OOP345/rouge/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable rouge"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/rouge.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/rouge.dir/build: rouge

.PHONY : CMakeFiles/rouge.dir/build

CMakeFiles/rouge.dir/requires: CMakeFiles/rouge.dir/main.cpp.o.requires

.PHONY : CMakeFiles/rouge.dir/requires

CMakeFiles/rouge.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/rouge.dir/cmake_clean.cmake
.PHONY : CMakeFiles/rouge.dir/clean

CMakeFiles/rouge.dir/depend:
	cd /Users/domi91c/OOP345/rouge/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/domi91c/OOP345/rouge /Users/domi91c/OOP345/rouge /Users/domi91c/OOP345/rouge/cmake-build-debug /Users/domi91c/OOP345/rouge/cmake-build-debug /Users/domi91c/OOP345/rouge/cmake-build-debug/CMakeFiles/rouge.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/rouge.dir/depend

