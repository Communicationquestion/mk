file(GLOB_RECURSE srcs CONFIGURE_DEPENDS src/*.cpp include/*.h)
add_library(create_file STATIC ${srcs})
target_include_directories(create_file PUBLIC include)

target_link_libraries(create_file PUBLIC path)

