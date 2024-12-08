file(GLOB_RECURSE srcs CONFIGURE_DEPENDS src/*.cpp include/*.h)
add_library(ThirdParty STATIC ${srcs})

find_package(ctranslate2 REQUIRED)
target_link_libraries(ThirdParty PUBLIC CTranslate2::ctranslate2)

find_package(cryptopp REQUIRED)
target_link_libraries(ThirdParty PUBLIC cryptopp::cryptopp)


find_package(OpenCV REQUIRED)
target_link_libraries(ThirdParty PUBLIC ${OpenCV_LIBS})


target_link_libraries(ThirdParty PUBLIC sentencepiece)
target_link_libraries(ThirdParty PUBLIC Boost::algorithm Boost::locale Boost::process)


target_include_directories(ThirdParty PUBLIC include )



