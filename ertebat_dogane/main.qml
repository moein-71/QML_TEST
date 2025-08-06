import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Window 2.15

Window {
    visible: true
    width: 400
    height: 250
    title: "ertebat"

    Column {
        anchors.centerIn: parent
        spacing: 20

        TextField {
            id: inputField
            width: 300
            placeholderText: "Enter your text : "
            onTextChanged: backend.updateText(text)
        }

        Text {
            text: "result : " + backend.outputText
            font.pixelSize: 20
        }
    }
}
