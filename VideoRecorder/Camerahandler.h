#ifndef CAMERAHANDLER_H
#define CAMERAHANDLER_H

#include <QObject>
#include <QImage>
#include <QTimer>
#include <QDesktopServices>
#include <QUrl>
#include <QDir>
// #include <opencv2/opencv.hpp>
#include "ImageProvider.h"
#include "CameraRecorder.h"

class Camerahandler : public QObject {
    Q_OBJECT
    public:
        explicit Camerahandler(QObject* parent = nullptr);
        ~Camerahandler();

        // Q_INVOKABLE void startshowing(const QString& path);
        // Q_INVOKABLE void stopshowing(const QString& path);

        Q_INVOKABLE void startRecording(const QString& path);
        Q_INVOKABLE void stopRecording();


    // private:
    public:
        CameraRecorder * recorder = nullptr;
        QThread* Thread = nullptr;
        ImageProvider * imgProvider = nullptr;
};


#endif //CAMERAHANDLER_H