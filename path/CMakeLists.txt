file(GLOB_RECURSE srcs CONFIGURE_DEPENDS src/*.cpp include/*.h)
add_library(path STATIC ${srcs})

target_include_directories(path PUBLIC include)
