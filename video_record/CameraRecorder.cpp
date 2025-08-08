#include "CameraRecorder.h"
#include <QDebug>
#include <QDateTime>
#include <QDir>

CameraRecorder::CameraRecorder(QObject *parent) : QObject(parent)
{
    moveToThread(&m_thread);
    m_thread.start();
}

CameraRecorder::~CameraRecorder()
{
    stopRecording();
    m_thread.quit();
    m_thread.wait();
}

void CameraRecorder::startRecording(const QString &outputPath)
{
    if (m_recording)
        return;

    m_recording = true;
    m_outputPath = outputPath;

    QtConcurrent::run([this]() { recordLoop(); });
}

void CameraRecorder::stopRecording()
{
    m_recording = false;
}

bool CameraRecorder::isRecording() const
{
    return m_recording;
}

void CameraRecorder::recordLoop()
{
    cv::VideoCapture cap(0);
    if (!cap.isOpened()) {
        qWarning() << "Failed to open camera.";
        return;
    }

    int width = static_cast<int>(cap.get(cv::CAP_PROP_FRAME_WIDTH));
    int height = static_cast<int>(cap.get(cv::CAP_PROP_FRAME_HEIGHT));
    int fps = 30;

    QString filename = m_outputPath + "/video_" +
        QDateTime::currentDateTime().toString("yyyyMMdd_hhmmss") + ".avi";

    cv::VideoWriter writer(filename.toStdString(), cv::VideoWriter::fourcc('M','J','P','G'), fps, cv::Size(width, height));

    while (m_recording) {
        cv::Mat frame;
        cap >> frame;
        if (frame.empty())
            continue;

        writer.write(frame);

        // Optional: Convert frame to QImage and send signal
        cv::Mat rgb;
        cv::cvtColor(frame, rgb, cv::COLOR_BGR2RGB);
        QImage img((uchar*)rgb.data, rgb.cols, rgb.rows, rgb.step, QImage::Format_RGB888);
        emit frameReady(img.copy());

        QThread::msleep(1000 / fps);
    }

    cap.release();
    writer.release();
}
