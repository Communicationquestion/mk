file(GLOB_RECURSE srcs CONFIGURE_DEPENDS src/*.cpp include/*.h)
add_library(abstraction_path STATIC ${srcs})
target_include_directories(abstraction_path PUBLIC include)