file(GLOB_RECURSE srcs CONFIGURE_DEPENDS src/*.cpp src/*.c include/*.h  include/*.cpp)
add_library(MkGui STATIC ${srcs})
find_package(glfw3 REQUIRED)
target_link_libraries(MkGui PUBLIC glfw)
target_include_directories(MkGui PUBLIC
    ${PROJECT_SOURCE_DIR}/MkGui/include/imgui/backends
     ${PROJECT_SOURCE_DIR}/MkGui/include/glad/include
)
target_include_directories(MkGui PUBLIC include)
