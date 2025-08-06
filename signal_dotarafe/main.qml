import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Window 2.15

Window {
    visible: true
    width: 400
    height: 300
    title: "both connection"

    Column {
        anchors.centerIn: parent
        spacing: 20

        TextField {
            id: inputField
            placeholderText: "Enter your text :"
            width: 200
        }

        Button {
            text: "send to C++"
            onClicked: {
                backend.sendMessage(inputField.text)
            }
        }

        Text {
            id: resultText
            text: "result : "
            font.pixelSize: 20
        }
    }

    Component.onCompleted: {
        backend.messageProcessed.connect(function(res) {
            resultText.text =  "result : " + res
        })
    }
}
