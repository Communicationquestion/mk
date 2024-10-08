import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import Qt.labs.qmlmodels
import MyModel 1.0

Rectangle {
	anchors.fill: parent
	height: parent.height
	visible: true
	width: parent.width

	Component.onCompleted: {
		MyListModel.init_data();
	}

	Rectangle {
		anchors.fill: parent
		height: parent.height
		width: parent.width

		ListView {
			id: listView

			anchors.fill: parent
			height: parent.height
			model: MyListModel
			width: parent.width

			delegate: Item {
				height: 80
				width: listView.width

				RowLayout {
					anchors.fill: parent
					height: parent.height
					width: parent.width

					Rectangle {
						id: itemRect

						border.color: "#cccccc"
						border.width: 1
						color: "#ffffff"
						height: parent.height
						radius: 8
						width: parent.width / 3

						gradient: Gradient {
							GradientStop {
								color: "#f0f0f0"
								position: 0.0
							}
							GradientStop {
								color: "#ffffff"
								position: 1.0
							}
						}
						Behavior on opacity {
							NumberAnimation {
								duration: 250
								easing.type: Easing.InOutQuad
							}
						}

						MouseArea {
							anchors.fill: parent

							onClicked: {}
							onPressed: {
								itemRect.scale = 0.95;
							}
							onReleased: {
								itemRect.scale = 1;
							}
						}
						Column {
							anchors.fill: parent
							padding: 10
							spacing: 5

							Text {
								font.bold: true
								font.pointSize: 10
								text: name
							}
							Text {
								font.bold: true
								font.pointSize: 10
								text: user
							}
							Text {
								font.bold: true
								font.pointSize: 10
								text: passwd
							}
						}
					}
				}
			}
		}
	}
}
