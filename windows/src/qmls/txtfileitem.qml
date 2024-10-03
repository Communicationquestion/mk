import QtQuick 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15
import txtTable 1.0
import Qt.labs.platform 

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
            anchors.right: parent.right
            color: "green"
            Button {
                width: parent.width/2
                height: parent.height/2
                anchors.centerIn: parent
                onClicked:fileDialog.open();
            }
        }

    }
    FileDialog {
        id: fileDialog
        selectedNameFilter.index: 1
        nameFilters: [ "HTML files (*.html *.htm)","Text files (*.txt)"]
        onAccepted: {
            console.log("选中的文件有:")
                console.log(file)
            txtTable.getfilepath(file)
            txtTable.ensrctxt()

            loader.source = "main.qml"
        }

    }
    Loader {

        id: loader
        // 通过设置source属性来指定要加载的界面文件
        anchors.fill: parent
        anchors.topMargin: topmenuBar.height
    }
   
}
