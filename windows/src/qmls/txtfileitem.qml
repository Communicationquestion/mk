import QtQuick 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15
import txtTable 1.0

Rectangle {
    width: parent.width
    height: parent.height
    color: "red"
    TxtTable {
        id: txtTable
    }
    Rectangle {
        width: parent.width / 2
        height: parent.height / 10
        anchors.centerIn: parent
        color: "blue"
        Rectangle {
            width: parent.width / 8
            height: parent.height
            anchors.right: parent
            color: "green"
            Button {
                width: parent.width/2
                height: parent.height/2
                anchors.centerIn: parent
            }
        }

    }
}
