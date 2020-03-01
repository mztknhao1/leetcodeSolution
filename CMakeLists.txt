cmake_minimum_required(VERSION 3.0.0)
project(LeetCodeSolution VERSION 0.1.0)


set(CMAKE_GENERATOR "Unix Makefiles")
include(CTest)
enable_testing()

include(CheckCXXCompilerFlag) 
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11) 
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X) 
if(COMPILER_SUPPORTS_CXX11) 
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g -Wall -Wno-unused-variable -pthread") 
elseif(COMPILER_SUPPORTS_CXX0X) 
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x") 
else() 
    message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.") 
endif()


# if( CMAKE_BUILD_TYPE STREQUAL "Debug" )
#     set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g -Wall -Wno-unused-variable -pthread")
# else( CMAKE_BUILD_TYPE STREQUAL "Debug" )
#         set(CMAKE_BUILD_TYPE "Release")
#     set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O2 -pthread -fopenmp")
# endif( CMAKE_BUILD_TYPE STREQUAL "Debug" )

# message("Build Type:"${CMAKE_BUILD_TYPE} ${CMAKE_CXX_FLAGS})


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)


add_subdirectory(SolutionSrc)
add_subdirectory(test)


# enable_testing()
# add_test(myTEST266 TEST415 1 2)

