import QtQuick 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 400
    height: 200
    ColumnLayout {
        anchors.fill: parent
        spacing: 5

        Rectangle {
            color: "green"
            Layout.fillWidth: true
            height: 50
        }
        Rectangle {
            color: "orange"
            Layout.fillWidth: true
            height: 50
        }
    }
}
