import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 400
    height: 300
    title: "geting name"

    TextField {
        id: nameInput
        placeholderText: "Enter name : "
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin: 40
        width: 250
    }

    Button {
        text: "send : "
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: nameInput.bottom
        anchors.topMargin: 20

        onClicked: {
            resultText.text = personHandler.makeGreeting(nameInput.text)
        }
    }

    Text {
        id: resultText
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.verticalCenter
        font.pixelSize: 20
    }
}
