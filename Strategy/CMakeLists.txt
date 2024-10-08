file(GLOB_RECURSE srcs CONFIGURE_DEPENDS src/*.cpp include/*.h)
add_library(Strategy STATIC ${srcs})




target_include_directories(Strategy PUBLIC include)

target_link_libraries( Strategy PUBLIC ThirdParty)
target_link_libraries(Strategy PUBLIC mk_command)