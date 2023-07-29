file(GLOB_RECURSE srcs CONFIGURE_DEPENDS src/*.cpp include/*.h)
add_library(module_path STATIC ${srcs})
target_include_directories(module_path PUBLIC include)

target_link_libraries(module_path PUBLIC abstraction_path)