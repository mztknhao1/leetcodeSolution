# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/mztkn/study/Leetcode/leetcodeSolution

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mztkn/study/Leetcode/leetcodeSolution/build

# Include any dependencies generated for this target.
include CMakeFiles/TEST442.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/TEST442.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TEST442.dir/flags.make

CMakeFiles/TEST442.dir/test442.cpp.o: CMakeFiles/TEST442.dir/flags.make
CMakeFiles/TEST442.dir/test442.cpp.o: ../test442.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mztkn/study/Leetcode/leetcodeSolution/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TEST442.dir/test442.cpp.o"
	/usr/bin/g++-5   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TEST442.dir/test442.cpp.o -c /home/mztkn/study/Leetcode/leetcodeSolution/test442.cpp

CMakeFiles/TEST442.dir/test442.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TEST442.dir/test442.cpp.i"
	/usr/bin/g++-5  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mztkn/study/Leetcode/leetcodeSolution/test442.cpp > CMakeFiles/TEST442.dir/test442.cpp.i

CMakeFiles/TEST442.dir/test442.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TEST442.dir/test442.cpp.s"
	/usr/bin/g++-5  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mztkn/study/Leetcode/leetcodeSolution/test442.cpp -o CMakeFiles/TEST442.dir/test442.cpp.s

CMakeFiles/TEST442.dir/test442.cpp.o.requires:

.PHONY : CMakeFiles/TEST442.dir/test442.cpp.o.requires

CMakeFiles/TEST442.dir/test442.cpp.o.provides: CMakeFiles/TEST442.dir/test442.cpp.o.requires
	$(MAKE) -f CMakeFiles/TEST442.dir/build.make CMakeFiles/TEST442.dir/test442.cpp.o.provides.build
.PHONY : CMakeFiles/TEST442.dir/test442.cpp.o.provides

CMakeFiles/TEST442.dir/test442.cpp.o.provides.build: CMakeFiles/TEST442.dir/test442.cpp.o


CMakeFiles/TEST442.dir/SolutionSrc/linkList.cpp.o: CMakeFiles/TEST442.dir/flags.make
CMakeFiles/TEST442.dir/SolutionSrc/linkList.cpp.o: ../SolutionSrc/linkList.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mztkn/study/Leetcode/leetcodeSolution/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/TEST442.dir/SolutionSrc/linkList.cpp.o"
	/usr/bin/g++-5   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TEST442.dir/SolutionSrc/linkList.cpp.o -c /home/mztkn/study/Leetcode/leetcodeSolution/SolutionSrc/linkList.cpp

CMakeFiles/TEST442.dir/SolutionSrc/linkList.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TEST442.dir/SolutionSrc/linkList.cpp.i"
	/usr/bin/g++-5  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mztkn/study/Leetcode/leetcodeSolution/SolutionSrc/linkList.cpp > CMakeFiles/TEST442.dir/SolutionSrc/linkList.cpp.i

CMakeFiles/TEST442.dir/SolutionSrc/linkList.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TEST442.dir/SolutionSrc/linkList.cpp.s"
	/usr/bin/g++-5  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mztkn/study/Leetcode/leetcodeSolution/SolutionSrc/linkList.cpp -o CMakeFiles/TEST442.dir/SolutionSrc/linkList.cpp.s

CMakeFiles/TEST442.dir/SolutionSrc/linkList.cpp.o.requires:

.PHONY : CMakeFiles/TEST442.dir/SolutionSrc/linkList.cpp.o.requires

CMakeFiles/TEST442.dir/SolutionSrc/linkList.cpp.o.provides: CMakeFiles/TEST442.dir/SolutionSrc/linkList.cpp.o.requires
	$(MAKE) -f CMakeFiles/TEST442.dir/build.make CMakeFiles/TEST442.dir/SolutionSrc/linkList.cpp.o.provides.build
.PHONY : CMakeFiles/TEST442.dir/SolutionSrc/linkList.cpp.o.provides

CMakeFiles/TEST442.dir/SolutionSrc/linkList.cpp.o.provides.build: CMakeFiles/TEST442.dir/SolutionSrc/linkList.cpp.o


CMakeFiles/TEST442.dir/SolutionSrc/array.cpp.o: CMakeFiles/TEST442.dir/flags.make
CMakeFiles/TEST442.dir/SolutionSrc/array.cpp.o: ../SolutionSrc/array.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mztkn/study/Leetcode/leetcodeSolution/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/TEST442.dir/SolutionSrc/array.cpp.o"
	/usr/bin/g++-5   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TEST442.dir/SolutionSrc/array.cpp.o -c /home/mztkn/study/Leetcode/leetcodeSolution/SolutionSrc/array.cpp

CMakeFiles/TEST442.dir/SolutionSrc/array.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TEST442.dir/SolutionSrc/array.cpp.i"
	/usr/bin/g++-5  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mztkn/study/Leetcode/leetcodeSolution/SolutionSrc/array.cpp > CMakeFiles/TEST442.dir/SolutionSrc/array.cpp.i

CMakeFiles/TEST442.dir/SolutionSrc/array.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TEST442.dir/SolutionSrc/array.cpp.s"
	/usr/bin/g++-5  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mztkn/study/Leetcode/leetcodeSolution/SolutionSrc/array.cpp -o CMakeFiles/TEST442.dir/SolutionSrc/array.cpp.s

CMakeFiles/TEST442.dir/SolutionSrc/array.cpp.o.requires:

.PHONY : CMakeFiles/TEST442.dir/SolutionSrc/array.cpp.o.requires

CMakeFiles/TEST442.dir/SolutionSrc/array.cpp.o.provides: CMakeFiles/TEST442.dir/SolutionSrc/array.cpp.o.requires
	$(MAKE) -f CMakeFiles/TEST442.dir/build.make CMakeFiles/TEST442.dir/SolutionSrc/array.cpp.o.provides.build
.PHONY : CMakeFiles/TEST442.dir/SolutionSrc/array.cpp.o.provides

CMakeFiles/TEST442.dir/SolutionSrc/array.cpp.o.provides.build: CMakeFiles/TEST442.dir/SolutionSrc/array.cpp.o


CMakeFiles/TEST442.dir/SolutionSrc/utils.cpp.o: CMakeFiles/TEST442.dir/flags.make
CMakeFiles/TEST442.dir/SolutionSrc/utils.cpp.o: ../SolutionSrc/utils.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mztkn/study/Leetcode/leetcodeSolution/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/TEST442.dir/SolutionSrc/utils.cpp.o"
	/usr/bin/g++-5   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TEST442.dir/SolutionSrc/utils.cpp.o -c /home/mztkn/study/Leetcode/leetcodeSolution/SolutionSrc/utils.cpp

CMakeFiles/TEST442.dir/SolutionSrc/utils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TEST442.dir/SolutionSrc/utils.cpp.i"
	/usr/bin/g++-5  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mztkn/study/Leetcode/leetcodeSolution/SolutionSrc/utils.cpp > CMakeFiles/TEST442.dir/SolutionSrc/utils.cpp.i

CMakeFiles/TEST442.dir/SolutionSrc/utils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TEST442.dir/SolutionSrc/utils.cpp.s"
	/usr/bin/g++-5  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mztkn/study/Leetcode/leetcodeSolution/SolutionSrc/utils.cpp -o CMakeFiles/TEST442.dir/SolutionSrc/utils.cpp.s

CMakeFiles/TEST442.dir/SolutionSrc/utils.cpp.o.requires:

.PHONY : CMakeFiles/TEST442.dir/SolutionSrc/utils.cpp.o.requires

CMakeFiles/TEST442.dir/SolutionSrc/utils.cpp.o.provides: CMakeFiles/TEST442.dir/SolutionSrc/utils.cpp.o.requires
	$(MAKE) -f CMakeFiles/TEST442.dir/build.make CMakeFiles/TEST442.dir/SolutionSrc/utils.cpp.o.provides.build
.PHONY : CMakeFiles/TEST442.dir/SolutionSrc/utils.cpp.o.provides

CMakeFiles/TEST442.dir/SolutionSrc/utils.cpp.o.provides.build: CMakeFiles/TEST442.dir/SolutionSrc/utils.cpp.o


CMakeFiles/TEST442.dir/SolutionSrc/queueS.cpp.o: CMakeFiles/TEST442.dir/flags.make
CMakeFiles/TEST442.dir/SolutionSrc/queueS.cpp.o: ../SolutionSrc/queueS.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mztkn/study/Leetcode/leetcodeSolution/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/TEST442.dir/SolutionSrc/queueS.cpp.o"
	/usr/bin/g++-5   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TEST442.dir/SolutionSrc/queueS.cpp.o -c /home/mztkn/study/Leetcode/leetcodeSolution/SolutionSrc/queueS.cpp

CMakeFiles/TEST442.dir/SolutionSrc/queueS.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TEST442.dir/SolutionSrc/queueS.cpp.i"
	/usr/bin/g++-5  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mztkn/study/Leetcode/leetcodeSolution/SolutionSrc/queueS.cpp > CMakeFiles/TEST442.dir/SolutionSrc/queueS.cpp.i

CMakeFiles/TEST442.dir/SolutionSrc/queueS.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TEST442.dir/SolutionSrc/queueS.cpp.s"
	/usr/bin/g++-5  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mztkn/study/Leetcode/leetcodeSolution/SolutionSrc/queueS.cpp -o CMakeFiles/TEST442.dir/SolutionSrc/queueS.cpp.s

CMakeFiles/TEST442.dir/SolutionSrc/queueS.cpp.o.requires:

.PHONY : CMakeFiles/TEST442.dir/SolutionSrc/queueS.cpp.o.requires

CMakeFiles/TEST442.dir/SolutionSrc/queueS.cpp.o.provides: CMakeFiles/TEST442.dir/SolutionSrc/queueS.cpp.o.requires
	$(MAKE) -f CMakeFiles/TEST442.dir/build.make CMakeFiles/TEST442.dir/SolutionSrc/queueS.cpp.o.provides.build
.PHONY : CMakeFiles/TEST442.dir/SolutionSrc/queueS.cpp.o.provides

CMakeFiles/TEST442.dir/SolutionSrc/queueS.cpp.o.provides.build: CMakeFiles/TEST442.dir/SolutionSrc/queueS.cpp.o


CMakeFiles/TEST442.dir/SolutionSrc/tree.cpp.o: CMakeFiles/TEST442.dir/flags.make
CMakeFiles/TEST442.dir/SolutionSrc/tree.cpp.o: ../SolutionSrc/tree.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mztkn/study/Leetcode/leetcodeSolution/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/TEST442.dir/SolutionSrc/tree.cpp.o"
	/usr/bin/g++-5   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TEST442.dir/SolutionSrc/tree.cpp.o -c /home/mztkn/study/Leetcode/leetcodeSolution/SolutionSrc/tree.cpp

CMakeFiles/TEST442.dir/SolutionSrc/tree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TEST442.dir/SolutionSrc/tree.cpp.i"
	/usr/bin/g++-5  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mztkn/study/Leetcode/leetcodeSolution/SolutionSrc/tree.cpp > CMakeFiles/TEST442.dir/SolutionSrc/tree.cpp.i

CMakeFiles/TEST442.dir/SolutionSrc/tree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TEST442.dir/SolutionSrc/tree.cpp.s"
	/usr/bin/g++-5  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mztkn/study/Leetcode/leetcodeSolution/SolutionSrc/tree.cpp -o CMakeFiles/TEST442.dir/SolutionSrc/tree.cpp.s

CMakeFiles/TEST442.dir/SolutionSrc/tree.cpp.o.requires:

.PHONY : CMakeFiles/TEST442.dir/SolutionSrc/tree.cpp.o.requires

CMakeFiles/TEST442.dir/SolutionSrc/tree.cpp.o.provides: CMakeFiles/TEST442.dir/SolutionSrc/tree.cpp.o.requires
	$(MAKE) -f CMakeFiles/TEST442.dir/build.make CMakeFiles/TEST442.dir/SolutionSrc/tree.cpp.o.provides.build
.PHONY : CMakeFiles/TEST442.dir/SolutionSrc/tree.cpp.o.provides

CMakeFiles/TEST442.dir/SolutionSrc/tree.cpp.o.provides.build: CMakeFiles/TEST442.dir/SolutionSrc/tree.cpp.o


CMakeFiles/TEST442.dir/SolutionSrc/DP.cpp.o: CMakeFiles/TEST442.dir/flags.make
CMakeFiles/TEST442.dir/SolutionSrc/DP.cpp.o: ../SolutionSrc/DP.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mztkn/study/Leetcode/leetcodeSolution/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/TEST442.dir/SolutionSrc/DP.cpp.o"
	/usr/bin/g++-5   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TEST442.dir/SolutionSrc/DP.cpp.o -c /home/mztkn/study/Leetcode/leetcodeSolution/SolutionSrc/DP.cpp

CMakeFiles/TEST442.dir/SolutionSrc/DP.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TEST442.dir/SolutionSrc/DP.cpp.i"
	/usr/bin/g++-5  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mztkn/study/Leetcode/leetcodeSolution/SolutionSrc/DP.cpp > CMakeFiles/TEST442.dir/SolutionSrc/DP.cpp.i

CMakeFiles/TEST442.dir/SolutionSrc/DP.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TEST442.dir/SolutionSrc/DP.cpp.s"
	/usr/bin/g++-5  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mztkn/study/Leetcode/leetcodeSolution/SolutionSrc/DP.cpp -o CMakeFiles/TEST442.dir/SolutionSrc/DP.cpp.s

CMakeFiles/TEST442.dir/SolutionSrc/DP.cpp.o.requires:

.PHONY : CMakeFiles/TEST442.dir/SolutionSrc/DP.cpp.o.requires

CMakeFiles/TEST442.dir/SolutionSrc/DP.cpp.o.provides: CMakeFiles/TEST442.dir/SolutionSrc/DP.cpp.o.requires
	$(MAKE) -f CMakeFiles/TEST442.dir/build.make CMakeFiles/TEST442.dir/SolutionSrc/DP.cpp.o.provides.build
.PHONY : CMakeFiles/TEST442.dir/SolutionSrc/DP.cpp.o.provides

CMakeFiles/TEST442.dir/SolutionSrc/DP.cpp.o.provides.build: CMakeFiles/TEST442.dir/SolutionSrc/DP.cpp.o


CMakeFiles/TEST442.dir/SolutionSrc/Solution.cpp.o: CMakeFiles/TEST442.dir/flags.make
CMakeFiles/TEST442.dir/SolutionSrc/Solution.cpp.o: ../SolutionSrc/Solution.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mztkn/study/Leetcode/leetcodeSolution/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/TEST442.dir/SolutionSrc/Solution.cpp.o"
	/usr/bin/g++-5   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TEST442.dir/SolutionSrc/Solution.cpp.o -c /home/mztkn/study/Leetcode/leetcodeSolution/SolutionSrc/Solution.cpp

CMakeFiles/TEST442.dir/SolutionSrc/Solution.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TEST442.dir/SolutionSrc/Solution.cpp.i"
	/usr/bin/g++-5  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mztkn/study/Leetcode/leetcodeSolution/SolutionSrc/Solution.cpp > CMakeFiles/TEST442.dir/SolutionSrc/Solution.cpp.i

CMakeFiles/TEST442.dir/SolutionSrc/Solution.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TEST442.dir/SolutionSrc/Solution.cpp.s"
	/usr/bin/g++-5  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mztkn/study/Leetcode/leetcodeSolution/SolutionSrc/Solution.cpp -o CMakeFiles/TEST442.dir/SolutionSrc/Solution.cpp.s

CMakeFiles/TEST442.dir/SolutionSrc/Solution.cpp.o.requires:

.PHONY : CMakeFiles/TEST442.dir/SolutionSrc/Solution.cpp.o.requires

CMakeFiles/TEST442.dir/SolutionSrc/Solution.cpp.o.provides: CMakeFiles/TEST442.dir/SolutionSrc/Solution.cpp.o.requires
	$(MAKE) -f CMakeFiles/TEST442.dir/build.make CMakeFiles/TEST442.dir/SolutionSrc/Solution.cpp.o.provides.build
.PHONY : CMakeFiles/TEST442.dir/SolutionSrc/Solution.cpp.o.provides

CMakeFiles/TEST442.dir/SolutionSrc/Solution.cpp.o.provides.build: CMakeFiles/TEST442.dir/SolutionSrc/Solution.cpp.o


CMakeFiles/TEST442.dir/SolutionSrc/my_sort.cpp.o: CMakeFiles/TEST442.dir/flags.make
CMakeFiles/TEST442.dir/SolutionSrc/my_sort.cpp.o: ../SolutionSrc/my_sort.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mztkn/study/Leetcode/leetcodeSolution/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/TEST442.dir/SolutionSrc/my_sort.cpp.o"
	/usr/bin/g++-5   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TEST442.dir/SolutionSrc/my_sort.cpp.o -c /home/mztkn/study/Leetcode/leetcodeSolution/SolutionSrc/my_sort.cpp

CMakeFiles/TEST442.dir/SolutionSrc/my_sort.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TEST442.dir/SolutionSrc/my_sort.cpp.i"
	/usr/bin/g++-5  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mztkn/study/Leetcode/leetcodeSolution/SolutionSrc/my_sort.cpp > CMakeFiles/TEST442.dir/SolutionSrc/my_sort.cpp.i

CMakeFiles/TEST442.dir/SolutionSrc/my_sort.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TEST442.dir/SolutionSrc/my_sort.cpp.s"
	/usr/bin/g++-5  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mztkn/study/Leetcode/leetcodeSolution/SolutionSrc/my_sort.cpp -o CMakeFiles/TEST442.dir/SolutionSrc/my_sort.cpp.s

CMakeFiles/TEST442.dir/SolutionSrc/my_sort.cpp.o.requires:

.PHONY : CMakeFiles/TEST442.dir/SolutionSrc/my_sort.cpp.o.requires

CMakeFiles/TEST442.dir/SolutionSrc/my_sort.cpp.o.provides: CMakeFiles/TEST442.dir/SolutionSrc/my_sort.cpp.o.requires
	$(MAKE) -f CMakeFiles/TEST442.dir/build.make CMakeFiles/TEST442.dir/SolutionSrc/my_sort.cpp.o.provides.build
.PHONY : CMakeFiles/TEST442.dir/SolutionSrc/my_sort.cpp.o.provides

CMakeFiles/TEST442.dir/SolutionSrc/my_sort.cpp.o.provides.build: CMakeFiles/TEST442.dir/SolutionSrc/my_sort.cpp.o


# Object files for target TEST442
TEST442_OBJECTS = \
"CMakeFiles/TEST442.dir/test442.cpp.o" \
"CMakeFiles/TEST442.dir/SolutionSrc/linkList.cpp.o" \
"CMakeFiles/TEST442.dir/SolutionSrc/array.cpp.o" \
"CMakeFiles/TEST442.dir/SolutionSrc/utils.cpp.o" \
"CMakeFiles/TEST442.dir/SolutionSrc/queueS.cpp.o" \
"CMakeFiles/TEST442.dir/SolutionSrc/tree.cpp.o" \
"CMakeFiles/TEST442.dir/SolutionSrc/DP.cpp.o" \
"CMakeFiles/TEST442.dir/SolutionSrc/Solution.cpp.o" \
"CMakeFiles/TEST442.dir/SolutionSrc/my_sort.cpp.o"

# External object files for target TEST442
TEST442_EXTERNAL_OBJECTS =

TEST442: CMakeFiles/TEST442.dir/test442.cpp.o
TEST442: CMakeFiles/TEST442.dir/SolutionSrc/linkList.cpp.o
TEST442: CMakeFiles/TEST442.dir/SolutionSrc/array.cpp.o
TEST442: CMakeFiles/TEST442.dir/SolutionSrc/utils.cpp.o
TEST442: CMakeFiles/TEST442.dir/SolutionSrc/queueS.cpp.o
TEST442: CMakeFiles/TEST442.dir/SolutionSrc/tree.cpp.o
TEST442: CMakeFiles/TEST442.dir/SolutionSrc/DP.cpp.o
TEST442: CMakeFiles/TEST442.dir/SolutionSrc/Solution.cpp.o
TEST442: CMakeFiles/TEST442.dir/SolutionSrc/my_sort.cpp.o
TEST442: CMakeFiles/TEST442.dir/build.make
TEST442: CMakeFiles/TEST442.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mztkn/study/Leetcode/leetcodeSolution/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable TEST442"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TEST442.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TEST442.dir/build: TEST442

.PHONY : CMakeFiles/TEST442.dir/build

CMakeFiles/TEST442.dir/requires: CMakeFiles/TEST442.dir/test442.cpp.o.requires
CMakeFiles/TEST442.dir/requires: CMakeFiles/TEST442.dir/SolutionSrc/linkList.cpp.o.requires
CMakeFiles/TEST442.dir/requires: CMakeFiles/TEST442.dir/SolutionSrc/array.cpp.o.requires
CMakeFiles/TEST442.dir/requires: CMakeFiles/TEST442.dir/SolutionSrc/utils.cpp.o.requires
CMakeFiles/TEST442.dir/requires: CMakeFiles/TEST442.dir/SolutionSrc/queueS.cpp.o.requires
CMakeFiles/TEST442.dir/requires: CMakeFiles/TEST442.dir/SolutionSrc/tree.cpp.o.requires
CMakeFiles/TEST442.dir/requires: CMakeFiles/TEST442.dir/SolutionSrc/DP.cpp.o.requires
CMakeFiles/TEST442.dir/requires: CMakeFiles/TEST442.dir/SolutionSrc/Solution.cpp.o.requires
CMakeFiles/TEST442.dir/requires: CMakeFiles/TEST442.dir/SolutionSrc/my_sort.cpp.o.requires

.PHONY : CMakeFiles/TEST442.dir/requires

CMakeFiles/TEST442.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TEST442.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TEST442.dir/clean

CMakeFiles/TEST442.dir/depend:
	cd /home/mztkn/study/Leetcode/leetcodeSolution/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mztkn/study/Leetcode/leetcodeSolution /home/mztkn/study/Leetcode/leetcodeSolution /home/mztkn/study/Leetcode/leetcodeSolution/build /home/mztkn/study/Leetcode/leetcodeSolution/build /home/mztkn/study/Leetcode/leetcodeSolution/build/CMakeFiles/TEST442.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TEST442.dir/depend

