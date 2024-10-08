file(GLOB_RECURSE srcs CONFIGURE_DEPENDS src/*.cpp  include/*.h)

#add_library(windows STATIC ${srcs})

#target_include_directories(windows PUBLIC include)
add_library(windows STATIC ${srcs} )

target_include_directories(windows PUBLIC include)



file(GLOB_RECURSE QSOURCES CONFIGURE_DEPENDS ${CMAKE_SOURCE_DIR}/src/*.cpp)
file(GLOB_RECURSE HEADERS CONFIGURE_DEPENDS ${CMAKE_SOURCE_DIR}/include/*.h)
qt_add_qml_module(windows
    URI windows
    VERSION 1.0
    SOURCES
        ${QSOURCES}
        ${HEADERS}
       
    QML_FILES
         src/qmls/main.qml
         src/qmls/states_transitions.qml
         src/qmls/file.qml
         src/qmls/Interactive.qml
         src/qmls/txtfileitem.qml

    RESOURCES
    
)
target_link_libraries( windows PUBLIC ThirdParty)
target_link_libraries( windows PUBLIC create_file)
