import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 400
    height: 400

    Column {
        spacing: 10
        anchors.centerIn: parent

        Repeater {
            id: repeater
            model: 5
            delegate: Rectangle {
                id: itemRect
                width: 200
                height: 40
                color: "lightgray"
                border.color: "black"

                Row {
                    anchors.fill: parent
                    spacing: 10

                    Text {
                        text: "item " + index
                        verticalAlignment: Text.AlignVCenter
                    }

                    Button {
                        text: "color change"
                        onClicked: {
                            itemRect.color = (itemRect.color === "lightgray") ? "lightgreen" : "lightgray"
                        }
                    }
                }
            }
        }

        Button {
            text: "change item 2 color"
            onClicked: {
                let item = repeater.itemAt(2);
                if (item) {
                    item.color = "yellow";
                }
            }
        }
    }
}