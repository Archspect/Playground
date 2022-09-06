cmake_minimum_required(VERSION 3.0.0)
project(Playground VERSION 0.1.0)

include(CTest)
enable_testing()

FILE(GLOB_RECURSE src src/*.cpp src/*.h)

add_executable(Playground ${src})
target_link_libraries(Playground raylib)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
