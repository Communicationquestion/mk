cmake_minimum_required (VERSION 3.8)
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
  
endif()
if(MSVC)
    add_compile_options(/utf-8)
endif()
cmake_policy(SET CMP0071 NEW)
set(GOOGLETEST_VERSION 1.11.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_AUTOUIC ON)      
set(CMAKE_AUTOMOC ON)       
set(CMAKE_AUTORCC ON)      

#add_compile_options("/permissive-")
#add_compile_options("/Zc:__cplusplus")

project ("mk")

include(FetchContent)

FetchContent_Declare(
  cryptopp-cmake
  GIT_REPOSITORY https://github.com/abdes/cryptopp-cmake.git
)
FetchContent_MakeAvailable(cryptopp-cmake)

FetchContent_Declare(
  Boost
  URL https://github.com/boostorg/boost/releases/download/boost-1.84.0/boost-1.84.0.tar.xz
  URL_MD5 893b5203b862eb9bbd08553e24ff146a
  DOWNLOAD_EXTRACT_TIMESTAMP ON
)

FetchContent_MakeAvailable(Boost)

include_directories(.\\sentencepiece\\include)
link_directories(.\\sentencepiece\\lib)



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

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
set(install_gtest OFF)
set(install_gmock OFF)
set(build_gmock ON)