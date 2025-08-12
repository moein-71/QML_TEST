import QtQuick 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 600
    height: 400
    title: "دو تا GridLayout"

    GridLayout {
        id: grid1
        columns: 2
        rowSpacing: 5
        columnSpacing: 5
        x: 20
        y: 20

        Rectangle { color: "red";    width: 50; height: 50 }
        Rectangle { color: "blue";   width: 50; height: 50 }
        Rectangle { color: "green";  width: 50; height: 50 }
        Rectangle { color: "yellow"; width: 50; height: 50 }
    }

    GridLayout {
        id: grid2
        columns: 3
        rowSpacing: 5
        columnSpacing: 5
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        anchors.margins: 20

        Rectangle { color: "pink";   width: 50; height: 50 }
        Rectangle { color: "orange"; width: 50; height: 50 }
        Rectangle { color: "purple"; width: 50; height: 50 }
        Rectangle { color: "cyan";   width: 50; height: 50 }
        Rectangle { color: "gray";   width: 50; height: 50 }
    }
}