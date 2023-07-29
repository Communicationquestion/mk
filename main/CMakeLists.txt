# CMakeList.txt: main 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#

# 将源代码添加到此项目的可执行文件。
add_executable (main "main.cpp" "main.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET main PROPERTY CXX_STANDARD 20)
endif()

target_link_libraries( main PUBLIC project_path)
target_link_libraries( main PUBLIC module_path)
target_link_libraries( main PUBLIC create_file)
target_link_libraries( main PUBLIC command_list)
# TODO: 如有需要，请添加测试并安装目标。


