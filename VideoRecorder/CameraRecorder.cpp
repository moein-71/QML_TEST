#include "CameraRecorder.h"
#include <QDateTime>
#include <QDebug>
#include <QDesktopServices>
#include <QUrl>
#include <QDir>

CameraRecorder::CameraRecorder(QObject *parent) : QObject(parent) {
    
}

void CameraRecorder::startRecording(const QString &path) {

    frameTimer = new QTimer();
    connect(frameTimer, &QTimer::timeout, this, &CameraRecorder::captureFrame);

    if (isRecording) return;

    QDir dir(path);
    if (!dir.exists())
        dir.mkpath(".");

    cap.open(0, cv::CAP_V4L2);
    if (!cap.isOpened()) {
        qDebug() << "Camera not accessible!";
        return;
    }

    double fps = cap.get(cv::CAP_PROP_FPS);
    // if (fps <= 0) {
    //     fps = 30.0;
    // }

    fps = 15 ;

    // int timer_with_fps = static_cast<int>(1000.0 / fps);

    QString filename = path + "/recorded_" + QDateTime::currentDateTime().toString("yyyyMMdd_HHmmss") + ".avi";
    writer.open(filename.toStdString(), cv::VideoWriter::fourcc('M','J','P','G'),
                fps, cv::Size((int)cap.get(cv::CAP_PROP_FRAME_WIDTH), (int)cap.get(cv::CAP_PROP_FRAME_HEIGHT)));

    if (!writer.isOpened()) {
        qDebug() << "Failed to open video file for writing!";
        return;
    }

    isRecording = true;
    frameTimer->start(fps);

}

void CameraRecorder::stopRecording() {
    isRecording = false;
    if (frameTimer) frameTimer->stop();
    writer.release();
    cap.release();                  
}

void CameraRecorder::captureFrame() {

    if (!isRecording) return;

    cv::Mat frame;
    if (!cap.read(frame)) return;

    if (isRecording) {
        writer.write(frame);
    }   

    cv::cvtColor(frame, frame, cv::COLOR_BGR2RGB);
    QImage img((uchar*)frame.data, frame.cols, frame.rows, frame.step, QImage::Format_RGB888);

    if (imgProvider) {
        imgProvider->setImage(img);
    }
    m_frameImage = img;
    emit frameImageChanged();
}


// QImage CameraRecorder::frameImage() const {
//     return m_frameImage;
// }

void CameraRecorder::setImageProvider(ImageProvider* provider) {
    imgProvider = provider;
}