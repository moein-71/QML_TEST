import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 400
    height: 300

    Column {
        spacing: 10
        anchors.centerIn: parent

        Repeater {
            model: 5
            delegate: Rectangle {
                width: 100
                height: 30
                color: "lightblue"
                border.color: "black"

                Text {
                    anchors.centerIn: parent
                    text: "item " + index
                }
            }
        }
    }
}