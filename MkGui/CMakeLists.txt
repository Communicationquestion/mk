file(GLOB_RECURSE srcs CONFIGURE_DEPENDS src/*.cpp src/*.c include/*.h  include/*.cpp)
add_library(MkGui STATIC ${srcs})
find_package(glfw3 REQUIRED)
target_link_libraries(MkGui PUBLIC glfw)

find_package(Assimp REQUIRED)
target_link_libraries(MkGui PUBLIC assimp::assimp)


if(MSVC)
    target_include_directories(MkGui PUBLIC $ENV{VK_SDK_PATH}\\include)
    target_link_directories(MkGui PUBLIC $ENV{VK_SDK_PATH}\\lib)
    message("-- VK_SDK_PATH is $ENV{VK_SDK_PATH}")
else()
    message("-- VK_SDK_PATH is $ENV{VK_SDK_PATH}")
endif()


target_include_directories(MkGui PUBLIC
    ${PROJECT_SOURCE_DIR}/MkGui/include/imgui
    $ENV{VK_SDK_PATH}/include/Volk
)
target_include_directories(MkGui PUBLIC include)
target_link_libraries( MkGui PUBLIC tools)