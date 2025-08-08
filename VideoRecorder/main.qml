import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Window 2.15
import QtQuick.Layouts 1.15
import VideoRecorder 1.0

Window {
    visible: true
    width: 1280
    height: 720
    title: "test video recorder"
    ColumnLayout {
        anchors.centerIn: parent
        spacing: 20

        Image {
            id: cameraImage
            width: 1000
            height: 505
            fillMode: Image.PreserveAspectFit
            // source: "image://camera/live"
        }

       Connections {
            target: imageProvider
            function onImageChanged() {
                cameraImage.source = "image://camera/live?" + Math.random()
            }
       }
        
        RowLayout {
            spacing: 20

            Button {
                text: "شروع ضبط"
                onClicked: {
                    Camerahandler.startRecording("./recorded_videos")
                }
            }

            Button {
                text: "توقف ضبط"
                onClicked: Camerahandler.stopRecording()
            }

            Button {
                text: "باز کردن پوشه"
                onClicked: {
                    Camerahandler.openFolder("./recorded_videos")
                }
            }
        }
    }
}