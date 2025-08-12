import QtQuick 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 400
    height: 200
    GridLayout {
        anchors.fill: parent
        columns: 3
        rowSpacing: 5
        columnSpacing: 5

        Rectangle { color: "red";    Layout.fillWidth: true; Layout.fillHeight: true }
        Rectangle { color: "green";  Layout.fillWidth: true; Layout.fillHeight: true }
        Rectangle { color: "blue";   Layout.fillWidth: true; Layout.fillHeight: true }
        Rectangle { color: "yellow"; Layout.fillWidth: true; Layout.fillHeight: true }
        Rectangle { color: "pink";   Layout.fillWidth: true; Layout.fillHeight: true }
    }
}
