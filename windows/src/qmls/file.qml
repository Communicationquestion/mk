import QtQuick 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15

Rectangle {
    width: parent.width
    height: parent.height
        Column {
            anchors.centerIn: parent
            width: parent.width
            height: parent.height
            Rectangle {
                width: parent.width
                height: parent.height * 2 / 3
                color: "red"
                ColumnLayout {
                    anchors.centerIn: parent
                    spacing: 10
                    Rectangle {

                        width: 400
                        height: 30
                        Text {
                            anchors.fill: parent
                            text: "名称"
                            font.pointSize: 15
                        }
                    }
                    Rectangle {
                        width: 400
                        height: 30
                        border.color: "grey"
                        TextInput {
                            anchors.fill: parent
                            font.pointSize: 15
                            focus: true
                        }
                    }
                    Rectangle {
                        width: 400
                        height: 30
                        Text {
                            anchors.fill: parent
                            text: "账号"
                            font.pointSize: 15
                        }
                    }
                    Rectangle {
                        width: 400
                        height: 30
                        border.color: "grey"
                        TextInput {
                            anchors.fill: parent
                            font.pointSize: 15
                            focus: true
                        }
                    }
                    Rectangle {
                        width: 400
                        height: 30
                        Text {
                            anchors.fill: parent
                            text: "password"
                            font.pointSize: 15
                        }
                    }
                    Rectangle {
                        width: 400
                        height: 30
                        border.color: "grey"
                        TextInput {
                            anchors.fill: parent
                            font.pointSize: 15
                            focus: true
                        }
                    }
                }
            }
            Rectangle {
                width: parent.width
                height: parent.height * 1 / 3
                color: "blue"
                Row {
                    anchors.centerIn: parent
                    width: parent.width
                    height: parent.height
                    Rectangle {
                        color: "yellow"
                        width: parent.width / 2
                        height: parent.height
                        Button {
                            width: parent.width / 2
                            height: parent.height / 2
                            anchors.centerIn: parent
                            text: "Save"
                        }
                    }
                    Rectangle {
                        color: "aqua"
                        width: parent.width / 2
                        height: parent.height
                        Button {
                            width: parent.width / 2
                            height: parent.height / 2
                            anchors.centerIn: parent
                            text: "Clear"
                        }
                    }
                }
            }
        }
}
