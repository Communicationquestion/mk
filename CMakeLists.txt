cmake_minimum_required (VERSION 3.8)

if (MSVC)
    add_compile_options(/Zc:preprocessor /utf-8 /DNOMINMAX /D_USE_MATH_DEFINES /EHsc /bigobj)
    add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/source-charset:utf-8>")
    add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/execution-charset:utf-8>")
elseif()
    if (WIN32)
        
    endif()
    add_compile_options(-Wall -Wextra -Werror=return-type)
endif()

if(POLICY CMP0135)
  cmake_policy(SET CMP0135 NEW)
endif()
set(FETCHCONTENT_UPDATES_DISCONNECTED ON CACHE BOOL "Disable FetchContent updates for faster builds")
set(FETCHCONTENT_QUIET OFF CACHE BOOL "Enable verbose output from FetchContent")

# Set the DOWNLOAD_EXTRACT_TIMESTAMP option to TRUE
set(FETCHCONTENT_DOWNLOAD_EXTRACT_TIMESTAMP TRUE)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


project ("mk")

include(FetchContent)

FetchContent_Declare(
  Boost
  URL https://github.com/boostorg/boost/releases/download/boost-1.86.0/boost-1.86.0-cmake.tar.xz
  
#  DOWNLOAD_EXTRACT_TIMESTAMP ON
)
#set(BOOST_INCLUDE_LIBRARIES algorithm locale process stacktrace )
FetchContent_MakeAvailable(Boost)

FetchContent_Declare(
  sentencepiece
  GIT_REPOSITORY https://github.com/google/sentencepiece.git
)

FetchContent_MakeAvailable(sentencepiece)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)



# 包含子项目。

add_subdirectory ("mk")
add_subdirectory ("path")
add_subdirectory ("command_list")
add_subdirectory ("mk_command")
add_subdirectory ("Strategy")
add_subdirectory ("ThirdParty")
add_subdirectory ("test")
add_subdirectory ("MkGui")
add_subdirectory ("tools")