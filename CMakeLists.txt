cmake_minimum_required(VERSION 3.0)
project(
  ModooCode
  VERSION 0.1
  DESCRIPTION "예제 프로젝트"
  LANGUAGES CXX)
message("project name: ${CMAKE_PROJECT_NAME}")
message("install dir: ${CMAKE_INSTALL_PREFIX}")

set(MEMORY_SOURCE ./memory/memory.cpp)
set(CPU_SRC ./cpu/state.cpp ./cpu/cpu.cpp ./cpu/main.cpp)
set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_BUILD_TYPE Debug)
set(SOURCE_FILES ${MEMORY_SOURCE} ${CPU_SRC})
set(CMAKE_PREFIX_PATH /usr/lib /usr/local/lib )
message("set vars: ${CMAKE_BUILD_TYPE}, ${SOURCE_FILES}")
add_executable(main ${SOURCE_FILES})
target_compile_options(main PUBLIC -Wall -O0 -g)