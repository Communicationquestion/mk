file(GLOB_RECURSE srcs CONFIGURE_DEPENDS src/*.cpp include/*.h)
add_library(designmode STATIC ${srcs})

target_include_directories(designmode PUBLIC include)
target_link_libraries(designmode PUBLIC ThirdParty)
target_link_libraries(designmode PUBLIC mk_command)
