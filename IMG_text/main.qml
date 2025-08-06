import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Window 2.15

Window {
    visible: true
    width: 1000
    height: 1000
    title: "image"
    color : "blue"

    Text {
        anchors.top : parent.top
        anchors.horizontalCenter : parent.horizontalCenter
        anchors.topMargin : 100
        font.pixelSize : 50
        text: "Click on buttons to see imgs"
    }

    Button {
        id: map_button
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter:parent.horizontalCenter
        width: 200
        height: 100
        text: "Click for Save menu"
        font.pixelSize:20
        onClicked: {
            backend.set_new_img("Save.jpg")
        }
    }

    Button {
        id: dracula_botton
        anchors.right : map_button.left
        anchors.verticalCenter: parent.verticalCenter
        anchors.rightMargin : 50
        width: 200
        height: 100
        text: "Click for menu"
        font.pixelSize:20
        onClicked: {
            backend.set_new_img("Menu.jpg")
        }
    }

    Button {
        id: invisible_man_botton
        anchors.left : map_button.right
        anchors.verticalCenter: parent.verticalCenter
        anchors.leftMargin : 50
        width: 200
        height: 100
        text: "Click for start"
        font.pixelSize:20
        onClicked: {
            backend.set_new_img("Start.jpg")
        }
    }

    Image {
        id: img
        width: 525
        height: 290
        source: backend.img
        anchors.horizontalCenter : parent.horizontalCenter
        anchors.bottom : parent.bottom
        anchors.bottomMargin: 30
    }
}
