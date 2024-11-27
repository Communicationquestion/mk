cmake_minimum_required (VERSION 3.8)
if (MSVC)
    add_compile_options(/Zc:preprocessor /utf-8 /DNOMINMAX /D_USE_MATH_DEFINES /EHsc /bigobj)
elseif()
    if (WIN32)
        add_compile_options(-finput-charset=utf-8 -fexec-charset=utf-8)
    endif()
    add_compile_options(-Wall -Wextra -Werror=return-type)
endif()

cmake_policy(SET CMP0071 NEW)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_AUTOUIC ON)      
set(CMAKE_AUTOMOC ON)       
set(CMAKE_AUTORCC ON)      

#add_compile_options("/permissive-")
#add_compile_options("/Zc:__cplusplus")


project ("mk")

include_directories(.\\sentencepiece\\include)
link_directories(.\\sentencepiece\\lib)


include_directories(D:\\Libs\\cmake\\boost)

link_directories(D:\\Libs\\cmake\\boost\\stage\\lib)





find_package(Qt6 REQUIRED COMPONENTS Core Quick Gui Widgets)
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
add_subdirectory ("test")

