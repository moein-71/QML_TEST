import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Window 2.15

Rectangle {
    width: 300
    height: 300
    color: "lightblue"

    Rectangle {
        id: box
        width: 50
        height: 50
        color: "red"
        x: 0

        MouseArea {
            anchors.fill: parent
            onClicked: {
                anim.running = true
                anim2.running = true
            }
        }

        NumberAnimation {
            id: anim
            target: box
            property: "x"
            to: 250
            duration: 1000
        }
        NumberAnimation {
            id: anim2
            target: box
            property: "y"
            to : 250
            duration: 3000
        }
    }
}
