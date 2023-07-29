file(GLOB_RECURSE srcs CONFIGURE_DEPENDS src/*.cpp include/*.h)
add_library(mk_command STATIC ${srcs})
target_include_directories(mk_command PUBLIC include)