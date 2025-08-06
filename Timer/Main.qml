import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Window 2.15

Window {
    visible: true
    width: 400
    height: 200
    title: "Timer"
    Column {
        anchors.centerIn: parent
        spacing: 20

        Text {
            id: clockText
            text: "uploading..."
            font.pixelSize: 20
        }

        Timer {
            interval: 1000  
            running: true
            repeat: true
            onTriggered: {
                clockText.text = backend.get_time()
            }
        }
    }
}
