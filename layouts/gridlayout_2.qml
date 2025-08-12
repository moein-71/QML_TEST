import QtQuick 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 400
    height: 300

    GridLayout {
        anchors.fill: parent
        columns: 3
        rowSpacing: 5
        columnSpacing: 5

        Rectangle {
            color: "red"
            Layout.row: 0
            Layout.column: 0
            Layout.columnSpan: 2  
            Layout.fillWidth: true
            Layout.fillHeight: true
        }
        Rectangle {
            color: "blue"
            Layout.row: 0
            Layout.column: 2
            Layout.fillWidth: true
            Layout.fillHeight: true
        }
        Rectangle {
            color: "green"
            Layout.row: 1
            Layout.column: 0
            Layout.rowSpan: 2 
            Layout.fillWidth: true
            Layout.fillHeight: true
        }
        Rectangle {
            color: "yellow"
            Layout.row: 1
            Layout.column: 1
            Layout.fillWidth: true
            Layout.fillHeight: true
        }
        Rectangle {
            color: "pink"
            Layout.row: 1
            Layout.column: 2
            Layout.fillWidth: true
            Layout.fillHeight: true
        }
    }
}
