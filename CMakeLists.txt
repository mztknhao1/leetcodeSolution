cmake_minimum_required(VERSION 3.0.0)
project(LeetCodeSolution VERSION 0.1.0)

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

include_directories(./ ./SolutionSrc ./SolutionTree)
add_subdirectory(SolutionSrc)
add_subdirectory(SolutionTree)

aux_source_directory(./SolutionSrc SOLUTIONSRC)
aux_source_directory(./SolutionTree SOLUTIONTREE)

add_executable(TEST456 test456.cpp ${SOLUTIONSRC})
add_executable(TEST442 test442.cpp ${SOLUTIONSRC})
add_executable(TEST650 test650.cpp ${SOLUTIONSRC})
add_executable(TEST542 test542.cpp ${SOLUTIONSRC})
add_executable(TEST21 test21.cpp ${SOLUTIONSRC})
add_executable(TEST3 test3.cpp ${SOLUTIONSRC})
add_executable(TEST15 test15.cpp ${SOLUTIONSRC})
add_executable(TEST415 test415.cpp ${SOLUTIONSRC})
add_executable(TEST721 test721.cpp ${SOLUTIONSRC})

