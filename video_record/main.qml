    import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: "ضبط ویدیو با دوربین"

    Column {
        spacing: 20
        anchors.centerIn: parent

        Button {
            text: "شروع ضبط"
            onClicked: {
                cameraRecorder.startRecording("/home/moein/Videos")
            }
        }

        Button {
            text: "توقف ضبط"
            onClicked: {
                cameraRecorder.stopRecording()
            }
        }

        Text {
            text: cameraRecorder.isRecording() ? "در حال ضبط..." : "متوقف شده"
            color: "white"
        }
    }
}
