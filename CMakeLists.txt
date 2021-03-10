cmake_minimum_required(VERSION 3.18)
set(projectName "fractalkor")
project(${projectName})
add_subdirectory(../varkor varkor)

# Adding the WIN32 option makes WinMain the entry symbol instead of main. This
# will make the output executable into a gui program rather than a console
# program.
add_executable(${projectName} WIN32)
add_subdirectory(src)
target_link_libraries(${projectName} varkor)
set_property(TARGET ${projectName} PROPERTY RUNTIME_OUTPUT_DIRECTORY
  "${CMAKE_SOURCE_DIR}/working")
