import QtQuick
import QtQuick.Controls
import Qt.labs.qmlmodels
Rectangle {
	color: "lightblue"
	height: Screen.height / 2
	visible: true
	width: Screen.width / 2

	Rectangle {
       
        width: parent.width/10
        anchors.fill: parent
		TableView {
    anchors.fill: parent
    columnSpacing: 1
    rowSpacing: 1
    clip: true

    model: TableModel {
        TableModelColumn { display: "name" }
        TableModelColumn { display: "color" }

        rows: [
            {
                "name": "cat",
                "color": "black"
            },
            {
                "name": "dog",
                "color": "brown"
            },
            {
                "name": "bird",
                "color": "white"
            }
        ]
    }

    delegate: Rectangle {
        implicitWidth: 100
        implicitHeight: 50
        border.width: 1

        Text {
            text: display
            anchors.centerIn: parent
        }
    }
}
	}
}
