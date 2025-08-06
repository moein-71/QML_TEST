import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Window 2.15

Window {
    visible: true
    width: 400
    height: 300
    title: "signals"

    Column {
        anchors.centerIn: parent
        spacing: 20

        Text {
            id: messageText
            text: "waiting..."
            font.pixelSize: 20
        }
    }

    Component.onCompleted: {
        backend.messageReceived.connect(function(msg) {
            messageText.text = msg
        })
    }
}
