cmake_minimum_required(VERSION 3.18)
set(projectName "fractalkor")
project(${projectName})
add_subdirectory(../varkor varkor)

add_executable(${projectName})
add_subdirectory(src)
target_link_libraries(${projectName} varkor)
set_property(TARGET ${projectName} PROPERTY RUNTIME_OUTPUT_DIRECTORY
  "${CMAKE_SOURCE_DIR}/working")
