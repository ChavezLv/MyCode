# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_SOURCE_DIR = /workspace/arctern-base

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /workspace/arctern-base/build-trt

# Include any dependencies generated for this target.
include src/Algorithms/licenseLandmark/CMakeFiles/licenseLandmark.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/Algorithms/licenseLandmark/CMakeFiles/licenseLandmark.dir/compiler_depend.make

# Include the progress variables for this target.
include src/Algorithms/licenseLandmark/CMakeFiles/licenseLandmark.dir/progress.make

# Include the compile flags for this target's objects.
include src/Algorithms/licenseLandmark/CMakeFiles/licenseLandmark.dir/flags.make

src/Algorithms/licenseLandmark/CMakeFiles/licenseLandmark.dir/licenseLandmark.cpp.o: src/Algorithms/licenseLandmark/CMakeFiles/licenseLandmark.dir/flags.make
src/Algorithms/licenseLandmark/CMakeFiles/licenseLandmark.dir/licenseLandmark.cpp.o: ../src/Algorithms/licenseLandmark/licenseLandmark.cpp
src/Algorithms/licenseLandmark/CMakeFiles/licenseLandmark.dir/licenseLandmark.cpp.o: src/Algorithms/licenseLandmark/CMakeFiles/licenseLandmark.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspace/arctern-base/build-trt/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/Algorithms/licenseLandmark/CMakeFiles/licenseLandmark.dir/licenseLandmark.cpp.o"
	cd /workspace/arctern-base/build-trt/src/Algorithms/licenseLandmark && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/Algorithms/licenseLandmark/CMakeFiles/licenseLandmark.dir/licenseLandmark.cpp.o -MF CMakeFiles/licenseLandmark.dir/licenseLandmark.cpp.o.d -o CMakeFiles/licenseLandmark.dir/licenseLandmark.cpp.o -c /workspace/arctern-base/src/Algorithms/licenseLandmark/licenseLandmark.cpp

src/Algorithms/licenseLandmark/CMakeFiles/licenseLandmark.dir/licenseLandmark.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/licenseLandmark.dir/licenseLandmark.cpp.i"
	cd /workspace/arctern-base/build-trt/src/Algorithms/licenseLandmark && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspace/arctern-base/src/Algorithms/licenseLandmark/licenseLandmark.cpp > CMakeFiles/licenseLandmark.dir/licenseLandmark.cpp.i

src/Algorithms/licenseLandmark/CMakeFiles/licenseLandmark.dir/licenseLandmark.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/licenseLandmark.dir/licenseLandmark.cpp.s"
	cd /workspace/arctern-base/build-trt/src/Algorithms/licenseLandmark && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspace/arctern-base/src/Algorithms/licenseLandmark/licenseLandmark.cpp -o CMakeFiles/licenseLandmark.dir/licenseLandmark.cpp.s

src/Algorithms/licenseLandmark/CMakeFiles/licenseLandmark.dir/trt/TrtLicenseLandMarkImpl.cpp.o: src/Algorithms/licenseLandmark/CMakeFiles/licenseLandmark.dir/flags.make
src/Algorithms/licenseLandmark/CMakeFiles/licenseLandmark.dir/trt/TrtLicenseLandMarkImpl.cpp.o: ../src/Algorithms/licenseLandmark/trt/TrtLicenseLandMarkImpl.cpp
src/Algorithms/licenseLandmark/CMakeFiles/licenseLandmark.dir/trt/TrtLicenseLandMarkImpl.cpp.o: src/Algorithms/licenseLandmark/CMakeFiles/licenseLandmark.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspace/arctern-base/build-trt/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/Algorithms/licenseLandmark/CMakeFiles/licenseLandmark.dir/trt/TrtLicenseLandMarkImpl.cpp.o"
	cd /workspace/arctern-base/build-trt/src/Algorithms/licenseLandmark && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/Algorithms/licenseLandmark/CMakeFiles/licenseLandmark.dir/trt/TrtLicenseLandMarkImpl.cpp.o -MF CMakeFiles/licenseLandmark.dir/trt/TrtLicenseLandMarkImpl.cpp.o.d -o CMakeFiles/licenseLandmark.dir/trt/TrtLicenseLandMarkImpl.cpp.o -c /workspace/arctern-base/src/Algorithms/licenseLandmark/trt/TrtLicenseLandMarkImpl.cpp

src/Algorithms/licenseLandmark/CMakeFiles/licenseLandmark.dir/trt/TrtLicenseLandMarkImpl.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/licenseLandmark.dir/trt/TrtLicenseLandMarkImpl.cpp.i"
	cd /workspace/arctern-base/build-trt/src/Algorithms/licenseLandmark && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspace/arctern-base/src/Algorithms/licenseLandmark/trt/TrtLicenseLandMarkImpl.cpp > CMakeFiles/licenseLandmark.dir/trt/TrtLicenseLandMarkImpl.cpp.i

src/Algorithms/licenseLandmark/CMakeFiles/licenseLandmark.dir/trt/TrtLicenseLandMarkImpl.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/licenseLandmark.dir/trt/TrtLicenseLandMarkImpl.cpp.s"
	cd /workspace/arctern-base/build-trt/src/Algorithms/licenseLandmark && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspace/arctern-base/src/Algorithms/licenseLandmark/trt/TrtLicenseLandMarkImpl.cpp -o CMakeFiles/licenseLandmark.dir/trt/TrtLicenseLandMarkImpl.cpp.s

# Object files for target licenseLandmark
licenseLandmark_OBJECTS = \
"CMakeFiles/licenseLandmark.dir/licenseLandmark.cpp.o" \
"CMakeFiles/licenseLandmark.dir/trt/TrtLicenseLandMarkImpl.cpp.o"

# External object files for target licenseLandmark
licenseLandmark_EXTERNAL_OBJECTS =

src/Algorithms/licenseLandmark/liblicenseLandmark.a: src/Algorithms/licenseLandmark/CMakeFiles/licenseLandmark.dir/licenseLandmark.cpp.o
src/Algorithms/licenseLandmark/liblicenseLandmark.a: src/Algorithms/licenseLandmark/CMakeFiles/licenseLandmark.dir/trt/TrtLicenseLandMarkImpl.cpp.o
src/Algorithms/licenseLandmark/liblicenseLandmark.a: src/Algorithms/licenseLandmark/CMakeFiles/licenseLandmark.dir/build.make
src/Algorithms/licenseLandmark/liblicenseLandmark.a: src/Algorithms/licenseLandmark/CMakeFiles/licenseLandmark.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/workspace/arctern-base/build-trt/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library liblicenseLandmark.a"
	cd /workspace/arctern-base/build-trt/src/Algorithms/licenseLandmark && $(CMAKE_COMMAND) -P CMakeFiles/licenseLandmark.dir/cmake_clean_target.cmake
	cd /workspace/arctern-base/build-trt/src/Algorithms/licenseLandmark && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/licenseLandmark.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/Algorithms/licenseLandmark/CMakeFiles/licenseLandmark.dir/build: src/Algorithms/licenseLandmark/liblicenseLandmark.a
.PHONY : src/Algorithms/licenseLandmark/CMakeFiles/licenseLandmark.dir/build

src/Algorithms/licenseLandmark/CMakeFiles/licenseLandmark.dir/clean:
	cd /workspace/arctern-base/build-trt/src/Algorithms/licenseLandmark && $(CMAKE_COMMAND) -P CMakeFiles/licenseLandmark.dir/cmake_clean.cmake
.PHONY : src/Algorithms/licenseLandmark/CMakeFiles/licenseLandmark.dir/clean

src/Algorithms/licenseLandmark/CMakeFiles/licenseLandmark.dir/depend:
	cd /workspace/arctern-base/build-trt && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /workspace/arctern-base /workspace/arctern-base/src/Algorithms/licenseLandmark /workspace/arctern-base/build-trt /workspace/arctern-base/build-trt/src/Algorithms/licenseLandmark /workspace/arctern-base/build-trt/src/Algorithms/licenseLandmark/CMakeFiles/licenseLandmark.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/Algorithms/licenseLandmark/CMakeFiles/licenseLandmark.dir/depend
