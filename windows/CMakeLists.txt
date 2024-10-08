#file(GLOB_RECURSE srcs CONFIGURE_DEPENDS src/*.cpp .qml include/*.h)

#add_library(windows STATIC ${srcs})

#target_include_directories(windows PUBLIC include)

file(GLOB_RECURSE srcs CONFIGURE_DEPENDS src/*.cpp include/*.h)
add_library(windows STATIC ${srcs} "include/imgtotxt/imgtotxt.h")
target_include_directories(windows PUBLIC include)

qt_add_qml_module(windows
    URI windows
    VERSION 1.0
    SOURCES

        include/basewindows/basewindows.h
        include/PasswordManagement/PasswordManagement.h
        src/PasswordManagement.cpp
        src/window.cpp

       
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
