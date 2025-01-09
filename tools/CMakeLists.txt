file(GLOB_RECURSE srcs CONFIGURE_DEPENDS src/*.cpp include/*.h include/*.hpp)
add_library(tools STATIC ${srcs})
target_include_directories(tools PUBLIC include)
if (MSVC)
   find_package(Boost 1.87.0 REQUIRED COMPONENTS  locale filesystem PATHS C:/Boost)
else()
	 find_package(Boost  REQUIRED COMPONENTS  locale filesystem )
endif()


target_link_libraries(tools PUBLIC Boost::locale Boost::filesystem Boost::boost )
#target_link_libraries(tools PUBLIC Boost::algorithm Boost::filesystem Boost::preprocessor Boost::locale Boost::process Boost::stacktrace)