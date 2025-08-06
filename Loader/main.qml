import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 400
    height: 300

    Column {
        anchors.centerIn: parent
        spacing: 10

        Button {
            text: "load"
            onClicked: loader.source = "MyComponent.qml"
        }

        Loader {
            id: loader
        }
    }
}
