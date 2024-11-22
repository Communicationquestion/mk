file(GLOB_RECURSE srcs CONFIGURE_DEPENDS src/*.cpp include/*.h)

enable_testing()
add_executable (test ${srcs})

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET mk PROPERTY CXX_STANDARD 17)
endif()



target_link_libraries( test PUBLIC GTest::gtest GTest::gtest_main)

target_link_libraries( test PUBLIC path)

target_link_libraries( test PUBLIC create_file)
target_link_libraries( test PUBLIC command_list)
target_link_libraries( test PUBLIC Strategy)
target_link_libraries( test PUBLIC ThirdParty)
target_link_libraries( test PUBLIC windows)

