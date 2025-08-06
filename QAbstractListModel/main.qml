import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 400
    height: 600
    title: "to do list"

    ListView {
        anchors.fill: parent
        model: taskModel  

        delegate: Item {
            width: parent.width
            height: 50

            Row {
                spacing: 10
                Text {
                    text: name 
                    font.pixelSize: 20
                }
                Button {
                    text: "delete"
                    onClicked: taskModel.removeTask(index)
                }
            }
        }
    }
}
