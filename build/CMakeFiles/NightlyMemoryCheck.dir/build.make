# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = D:\software\CMake\bin\cmake.exe

# The command to remove a file.
RM = D:\software\CMake\bin\cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = E:\Master\LeetCode_mztkn\leetcodeSolution

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\Master\LeetCode_mztkn\leetcodeSolution\build

# Utility rule file for NightlyMemoryCheck.

# Include the progress variables for this target.
include CMakeFiles/NightlyMemoryCheck.dir/progress.make

CMakeFiles/NightlyMemoryCheck:
	D:\software\CMake\bin\ctest.exe -D NightlyMemoryCheck

NightlyMemoryCheck: CMakeFiles/NightlyMemoryCheck
NightlyMemoryCheck: CMakeFiles/NightlyMemoryCheck.dir/build.make

.PHONY : NightlyMemoryCheck

# Rule to build all files generated by this target.
CMakeFiles/NightlyMemoryCheck.dir/build: NightlyMemoryCheck

.PHONY : CMakeFiles/NightlyMemoryCheck.dir/build

CMakeFiles/NightlyMemoryCheck.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\NightlyMemoryCheck.dir\cmake_clean.cmake
.PHONY : CMakeFiles/NightlyMemoryCheck.dir/clean

CMakeFiles/NightlyMemoryCheck.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\Master\LeetCode_mztkn\leetcodeSolution E:\Master\LeetCode_mztkn\leetcodeSolution E:\Master\LeetCode_mztkn\leetcodeSolution\build E:\Master\LeetCode_mztkn\leetcodeSolution\build E:\Master\LeetCode_mztkn\leetcodeSolution\build\CMakeFiles\NightlyMemoryCheck.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/NightlyMemoryCheck.dir/depend

