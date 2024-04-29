import QtQuick
import QtQuick.Controls

Window {
    visible: true
    width: Screen.width / 2
    height: Screen.height / 2
    color : "lightblue"
    Row{
        width: parent.width
        height: parent.height
        Rectangle {
            width: parent.width /2
            height: parent.height
            color: "red"
        }
        Column{
            width: parent.width /2
            height: parent.height
            Rectangle {
                width: parent.width
                height: parent.height / 3
                color: "blue"
                Rectangle{
                    width: parent.width /2
                    height: parent.height / 2
                    color: "lightblue"
                    anchors.left: parent.left
                }
            }
            Rectangle {
                width: parent.width
                height: parent.height / 3
                color: "green"
            }
            Rectangle {
                width: parent.width
                height: parent.height / 3
                color: "yellow"
            }
        }

    }

}
