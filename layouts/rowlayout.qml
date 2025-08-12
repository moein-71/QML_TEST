import QtQuick 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 400
    height: 200

    RowLayout {
        anchors.fill: parent
        spacing: 10

        Rectangle {
            color: "red"
            Layout.fillWidth: true
            Layout.fillHeight: true
        }
        Rectangle {
            color: "blue"
            Layout.fillWidth: true
            Layout.fillHeight: true
        }
    }
}
