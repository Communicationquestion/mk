file(GLOB_RECURSE srcs CONFIGURE_DEPENDS src/*.cpp include/*.h include/*.hpp)
add_library(tools STATIC ${srcs})
target_include_directories(tools PUBLIC include)
target_link_libraries(tools PUBLIC Boost::algorithm Boost::filesystem Boost::preprocessor Boost::locale Boost::process Boost::stacktrace)