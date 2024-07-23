
file(GLOB_RECURSE srcs CONFIGURE_DEPENDS src/*.cpp include/*.h)
add_library(ThirdParty STATIC ${srcs})

find_package(ctranslate2 REQUIRED)
target_link_libraries(ThirdParty PUBLIC CTranslate2::ctranslate2)

find_package(Qt6 REQUIRED COMPONENTS Core Quick Gui Widgets)
target_link_libraries(ThirdParty PUBLIC Qt6::Core Qt6::Quick Qt6::Gui Qt6::Widgets)

find_package(cryptopp CONFIG REQUIRED)
target_link_libraries(ThirdParty PUBLIC cryptopp::cryptopp)

target_link_libraries(ThirdParty PUBLIC gtest)

target_include_directories(ThirdParty PUBLIC include)



