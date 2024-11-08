file(GLOB_RECURSE srcs CONFIGURE_DEPENDS src/*.cpp include/*.h)
add_library(ThirdParty STATIC ${srcs})

find_package(ctranslate2 REQUIRED)
target_link_libraries(ThirdParty PUBLIC CTranslate2::ctranslate2)

set(CMAKE_AUTOUIC ON)      
set(CMAKE_AUTOMOC ON)       
set(CMAKE_AUTORCC ON)  

find_package(Qt6 REQUIRED COMPONENTS Core Quick Gui Widgets)
target_link_libraries(ThirdParty PUBLIC Qt6::Core Qt6::Quick Qt6::Gui Qt6::Widgets)

target_link_libraries(ThirdParty PUBLIC Boost::algorithm Boost::locale Boost::process)
target_link_libraries(ThirdParty PUBLIC sentencepiece)
target_link_libraries(ThirdParty PUBLIC cryptopp)

target_include_directories(ThirdParty PUBLIC include )



