file(GLOB_RECURSE srcs CONFIGURE_DEPENDS src/*.cpp include/*.h)
add_library(command_list STATIC ${srcs})

LINK_DIRECTORIES(D:\\projects\\vs\\mk\\sentencepiece\\lib)
target_link_libraries(command_list PUBLIC sentencepiece.lib )

target_link_libraries( command_list PUBLIC ThirdParty)
target_include_directories(command_list PUBLIC include)
target_link_libraries( command_list PUBLIC path)
target_link_libraries( command_list PUBLIC windows)