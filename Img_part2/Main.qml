import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Window 2.15

Window {
    visible: true
    width: 400
    height: 400
    title: "more than one photo"
    Column {
        anchors.centerIn: parent
        spacing: 20

        Image {
            width: 300
            height: 300
            source: backend.currentImage
            fillMode: Image.PreserveAspectFit
        }

        Row {
            spacing: 20
            Button {
                text: "ghabli"
                onClicked: backend.previousImage()
            }
            Button {
                text: "badi"
                onClicked: backend.nextImage()
            }
        }
    }
}
