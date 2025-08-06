import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Window 2.15

Window {
    visible: true
    width: 400
    height: 300
    title: "timer in cpp"

    Column {
        anchors.centerIn: parent
        spacing: 20

        Text {
                text: "date is : " + backend.date
                font.pixelSize: 40
        }

    }
}
