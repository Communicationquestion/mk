file(GLOB_RECURSE srcs CONFIGURE_DEPENDS src/*.cpp include/*.h)
add_library(ThirdParty STATIC ${srcs})

find_package(ctranslate2 REQUIRED)
find_package(Qt6 REQUIRED COMPONENTS Core Quick Gui )

qt_standard_project_setup()
target_link_libraries(ThirdParty PUBLIC Qt6::Core Qt6::Quick Qt6::Gui)
target_link_libraries(ThirdParty PUBLIC CTranslate2::ctranslate2)
target_include_directories(ThirdParty PUBLIC include)
