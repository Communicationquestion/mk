file(GLOB_RECURSE srcs CONFIGURE_DEPENDS src/*.cpp include/*.h)
add_library(project_path STATIC ${srcs})
target_include_directories(project_path PUBLIC include)

target_link_libraries(project_path PUBLIC abstraction_path)