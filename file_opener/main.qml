import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 400
    height: 300
    title: qsTr("باز کردن پوشه")

    Button {
        text: "باز کردن پوشه Documents"
        anchors.centerIn: parent
        onClicked: {
            folderOpener.openFolder("./record_vids")
        }
    }
}
