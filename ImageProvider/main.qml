import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    visible: true
    width: 640
    height: 480
    title: "see pic with imageprovider"

    Image {
        anchors.centerIn: parent
        width: 400
        height: 300
        source: "image://custom/anything"
        fillMode: Image.PreserveAspectFit
    }
}
