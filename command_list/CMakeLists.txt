file(GLOB_RECURSE srcs CONFIGURE_DEPENDS src/*.cpp include/*.h)
add_library(command_list STATIC ${srcs})
target_include_directories(command_list PUBLIC include)