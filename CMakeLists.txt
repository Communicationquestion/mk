# CMakeList.txt: 顶层 CMake 项目文件，在此处执行全局配置
# 并包含子项目。
#
cmake_minimum_required (VERSION 3.8)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project ("mk")

# 包含子项目。
add_subdirectory ("main")
add_subdirectory ("abstraction_path")
add_subdirectory ("project_path")
add_subdirectory ("module_path")
add_subdirectory ("create_file")
add_subdirectory ("command_list")
add_subdirectory ("mk_command")

