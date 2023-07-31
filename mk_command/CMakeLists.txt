file(GLOB_RECURSE srcs CONFIGURE_DEPENDS src/*.cpp include/*.h)
add_library(mk_command STATIC ${srcs})
target_include_directories(mk_command PUBLIC include)

target_link_libraries(mk_command PUBLIC command_list)