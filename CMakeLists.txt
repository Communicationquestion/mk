# CMakeList.txt: 顶层 CMake 项目文件，在此处执行全局配置
# 并包含子项目。
#
cmake_minimum_required (VERSION 3.8)
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
  
endif()
if(MSVC)
    add_compile_options(/utf-8)
endif()

set(GOOGLETEST_VERSION 1.11.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_AUTOUIC ON)       # UIC能被自动执行
set(CMAKE_AUTOMOC ON)       # MOC能被自动执行
set(CMAKE_AUTORCC ON)       # RCC能被自动执行

#add_compile_options("/permissive-")
#add_compile_options("/Zc:__cplusplus")
#set(DCMAKE_TOOLCHAIN_FILE: "C:\\vcpkg\\scripts\\buildsystems\\vcpkg.cmake")
#include(C:\\tp\\vcpkgs\\scripts\\buildsystems\\vcpkg.cmake)

#set(CMAKE_PREFIX_PATH "C:\\Qt\\6.7.2/\\msvc2019_64" "C:\\vcpkg\\scripts\\buildsystems\\vcpkg.cmake")
#  "C:\\tp\\vcpkgs\\installed\\x64-windows\\share\\cryptopp"
#  "C:\\tp\\vcpkgs\\installed\\x64-windows\\share\\opencv"
#  "C:\\tp\\vcpkgs\\installed\\x64-windows\\share\\protobuf")

#set(OpenCV_DIR "C:\\tp\\vcpkgs\\installed\\x64-windows\\share\\opencv")
#set(Protobuf_DIR "C:\\tp\\vcpkgs\\installed\\x64-windows\\share\\protobuf")

project ("mk")







include(FetchContent)

FetchContent_Declare(
  cryptopp-cmake
  GIT_REPOSITORY https://github.com/abdes/cryptopp-cmake.git
)
FetchContent_MakeAvailable(cryptopp-cmake)







INCLUDE_DIRECTORIES(.\\sentencepiece\\include)
include_directories(.\\sentencepiece\\include)
link_directories(.\\sentencepiece\\lib)

INCLUDE_DIRECTORIES(C:\\boost_1_86_0)
include_directories(C:\\boost_1_86_0)
link_directories(C:\\boost_1_86_0\\stage\\lib)

find_package(Qt6 REQUIRED COMPONENTS Core Quick Gui Widgets)
qt_standard_project_setup(REQUIRES 6.7)

add_subdirectory("ThirdParty/googletest")

# 包含子项目。

add_subdirectory ("mk")
add_subdirectory ("path")
add_subdirectory ("create_file")
add_subdirectory ("command_list")
add_subdirectory ("mk_command")
add_subdirectory ("Strategy")
add_subdirectory ("ThirdParty")
add_subdirectory ("windows")


# Prevent overriding the parent project's compiler/linker settings on Windows.
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
set(install_gtest OFF)
set(install_gmock OFF)
set(build_gmock ON)






