# 设置 CMake 的最低版本要求
cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

# 设定项目
project(URTR VERSION 0.0.10)
message(STATUS "[Project] ${PROJECT_NAME}")

include(FetchContent)

message(STATUS "find package: UCMake 0.5.0")
find_package(UCMake 0.5.0 QUIET)
if(NOT UCMake_FOUND)
  message(STATUS "UCMake 0.5.0 not found")
  message(STATUS "fetch: ${_address} 0.5.0")
  set(_address "https://github.com/Ubpa/UCMake")
  FetchContent_Declare(
    UCMake
    GIT_REPOSITORY ${_address}
    GIT_TAG "0.5.0"
  )
  FetchContent_MakeAvailable(UCMake)
  message(STATUS "UCMake 0.5.0 build done")
endif()

if(Ubpa_BuildURTRTest)
  find_package(glfw3 REQUIRED)
endif()

Ubpa_AddDep(UGL 0.2.4)
Ubpa_AddDep(UScene 0.5.5)

Ubpa_AddSubDirsRec(src)

Ubpa_Export(DIRECTORIES "include")
