cmake_minimum_required(VERSION 3.0.0)
project(LeetCodeSolution VERSION 0.1.0)


set(CMAKE_GENERATOR "Unix Makefiles")
include(CTest)
enable_testing()

include(CheckCXXCompilerFlag) 
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11) 
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X) 
if(COMPILER_SUPPORTS_CXX11) 
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11") 
elseif(COMPILER_SUPPORTS_CXX0X) 
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x") 
else() 
    message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.") 
endif()


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)


add_subdirectory(SolutionSrc)
add_subdirectory(test)


# enable_testing()
# add_test(myTEST266 TEST415 1 2)

