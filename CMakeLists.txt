cmake_minimum_required(VERSION 3.0.0)
project(LeetCodeSolution VERSION 0.1.0)

include(CTest)
enable_testing()

# add_library(LeetCodeSolution Solution.cpp)
#aux_source_directory(. DIR_ROOT_SRCS)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

add_executable(TEST456 test456.cpp Solution.cpp Solution.cpp)
add_executable(TEST442 test442.cpp Solution.cpp Solution.cpp)
