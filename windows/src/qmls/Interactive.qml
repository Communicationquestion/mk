import QtQuick
import QtQuick.Controls 2.5

ApplicationWindow {
    visible: true
    width: Screen.width / 2
    height: Screen.height / 2

/*    Row{
        width: parent.width
        height: parent.height/20




    }*/
    menuBar: MenuBar {
        id : topmenuBar
        Menu {
            title: qsTr("&File")
            Action { text: qsTr("&New...")
                onTriggered: {
                    loader.source = "file.qml"

                }
            }
            Action { text: qsTr("&Open...") }
            Action { text: qsTr("&Save") }
            Action { text: qsTr("Save &As...") }
            MenuSeparator { }
            Action { text: qsTr("&Quit") }
        }
        Menu {
            title: qsTr("&Edit")
            Action { text: qsTr("Cu&t") }
            Action { text: qsTr("&Copy") }
            Action { text: qsTr("&Paste") }
        }
        Menu {
            title: qsTr("&Help")
            Action { text: qsTr("&About") }
        }
    }

    Loader {

        id: loader
        // 通过设置source属性来指定要加载的界面文件
        anchors.fill: parent
        anchors.topMargin: topmenuBar.height


    }




}
