cmake_minimum_required(VERSION 3.0.0)
project(tiny-renderer VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(tiny-renderer main.cpp source/tgaimage.cpp source/model.cpp)
include_directories(include/)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
