file(GLOB_RECURSE srcs CONFIGURE_DEPENDS src/*.cpp include/*.h)
add_library(ThirdParty STATIC ${srcs})

find_package(ctranslate2 REQUIRED)
target_link_libraries(ThirdParty PUBLIC CTranslate2::ctranslate2)

find_package(cryptopp REQUIRED)
target_link_libraries(ThirdParty PUBLIC cryptopp::cryptopp)


find_package(OpenCV REQUIRED)
target_link_libraries(ThirdParty PUBLIC ${OpenCV_LIBS})


target_link_libraries(ThirdParty PUBLIC sentencepiece)
# Copyright 2019, 2023 Peter Dimov
# Distributed under the Boost Software License, Version 1.0.
# (See accompanying file LICENSE_1_0.txt or copy at http://boost.org/LICENSE_1_0.txt)

# This CMake configuration file provides support for find_package(Boost).

target_link_libraries(ThirdParty PUBLIC Boost::algorithm Boost::filesystem Boost::preprocessor Boost::locale Boost::process Boost::stacktrace)

target_include_directories(ThirdParty PUBLIC include )



