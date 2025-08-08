#ifndef CAMERARECORDER_H
#define CAMERARECORDER_H

#include <QObject>
#include <QImage>
#include <QTimer>
#include <QDesktopServices>
#include <QUrl>
#include <QDir>
#include <QThread>
#include <opencv2/opencv.hpp>
#include "ImageProvider.h"

class CameraRecorder : public QObject
{
    Q_OBJECT
    // Q_PROPERTY(QImage frameImage READ frameImage NOTIFY frameImageChanged)
public: 
    explicit CameraRecorder(QObject *parent = nullptr);
    Q_INVOKABLE void startRecording(const QString &path);
    Q_INVOKABLE void stopRecording();
    // QImage frameImage() const;
    void setImageProvider(ImageProvider* provider);

signals:
    // void frameReady(const QImage &image);
    void frameImageChanged();

private slots:
    void captureFrame();

// private:
public:

    QTimer * frameTimer = nullptr ;
    QImage m_frameImage;
    cv::VideoCapture cap;
    cv::VideoWriter writer;
    bool isRecording = false ;
    bool showing = true ;
    ImageProvider * imgProvider = nullptr;

};

#endif // CAMERARECORDER_H