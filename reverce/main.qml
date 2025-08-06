import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Window 2.15

Window {
    visible: true
    width: 400
    height: 300
    title: "Property and Signal"



        TextField {
                id: normaltext
                placeholderText: "Enter your text"
                anchors.horizontalCenter : parent.horizontalCenter
                anchors.top: parent.top
                anchors.topMargin : 30
                anchors.leftMargin : 30 
        }

        Button {
            text: "Enter to reverse"
            anchors.centerIn : parent
            onClicked: {
                backend.make_reverse(normaltext.text)
            }
        }

        Text {
            id: reverse
            text: backend.rev
            anchors.horizontalCenter : parent.horizontalCenter
            anchors.bottom : parent.bottom
            color: "black"
            font.pixelSize : 30
            // width: 250
              
        }
}
