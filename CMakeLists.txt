# CMakeList.txt: 顶层 CMake 项目文件，在此处执行全局配置
# 并包含子项目。
#
cmake_minimum_required (VERSION 3.8)
add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(DCMAKE_TOOLCHAIN_FILE "D:/vcpkg/scripts/buildsystems/vcpkg.cmake")
set(CMAKE_PREFIX_PATH "C:\\tp\\CTranslate2\\lib\\cmake;C:\\Qt\\6.7.1\\msvc2019_64\\lib\\cmake")
set(DQT_QMAKE_EXECUTABLE "C:\\Qt\\6.7.1\\msvc2019_64\\bin\\qmake.exe")
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_AUTOUIC ON)       # UIC能被自动执行
set(CMAKE_AUTOMOC ON)       # MOC能被自动执行
set(CMAKE_AUTORCC ON)       # RCC能被自动执行

add_compile_options("/permissive-")
add_compile_options("/Zc:__cplusplus")



project ("mk")
INCLUDE_DIRECTORIES(D:\\code\\C++\\CppProgram\\mk\\sentencepiece\\include)
include_directories(D:\\code\\C++\\CppProgram\\mk\\sentencepiece\\include)
link_directories(D:\\code\\C++\\CppProgram\\mk\\sentencepiece\\lib)


find_package(Qt6 REQUIRED COMPONENTS Qml)
qt_standard_project_setup(REQUIRES 6.7)

# 包含子项目。

add_subdirectory ("mk")
add_subdirectory ("path")
add_subdirectory ("create_file")
add_subdirectory ("command_list")
add_subdirectory ("mk_command")
add_subdirectory ("Strategy")
add_subdirectory ("ThirdParty")
add_subdirectory ("windows")








