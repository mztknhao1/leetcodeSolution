cmake_minimum_required(VERSION 3.0.0)
project(LeetCodeSolution VERSION 0.1.0)

include(CTest)
enable_testing()

# add_library(LeetCodeSolution Solution.cpp)
#aux_source_directory(. DIR_ROOT_SRCS)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

add_executable(TEST456 test456.cpp Solution.cpp)
add_executable(TEST442 test442.cpp Solution.cpp)
add_executable(TEST650 test650.cpp Solution.cpp)
add_executable(TEST542 test542.cpp Solution.cpp)
add_executable(TEST21 test21.cpp Solution.cpp utils.cpp)
add_executable(TEST3 test3.cpp Solution.cpp utils.cpp)
add_executable(TEST15 test15.cpp Solution.cpp utils.cpp)

