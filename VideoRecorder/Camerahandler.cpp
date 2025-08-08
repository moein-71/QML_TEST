#include "Camerahandler.h"

Camerahandler::Camerahandler(QObject* parent) : QObject(parent) {}

Camerahandler::~Camerahandler() {
    stopRecording();
    Thread->quit();
    Thread->wait();
    // delete Thread ;
    // delete recorder ;
}

// void Camerahandler::stopshowing(const QString& path) {
//     stopRecording();
//     Thread->quit();
//     Thread->wait();
// }

void Camerahandler::startRecording(const QString& path) {
    recorder = new CameraRecorder();
    recorder->setImageProvider(this->imgProvider) ;
    Thread = new QThread(this);
    recorder->moveToThread(Thread);

    connect(Thread, &QThread::finished, recorder, &QObject::deleteLater);
    // connect(this, &Camerahandler::startRecording, recorder, &CameraRecorder::startRecording);
    // connect(this, &Camerahandler::stopRecording, recorder, &CameraRecorder::stopRecording);
    // connect(recorder, &CameraRecorder::framSet, this, &Camerahandler::);
    // connect(recorder, &CameraRecorder::finished, this, &CameraRecorder::handleFinished);

    Thread->start();

    QMetaObject::invokeMethod(recorder, "startRecording", Qt::QueuedConnection, Q_ARG(QString, path));
}

void Camerahandler::stopRecording() {

    QMetaObject::invokeMethod(recorder, "stopRecording", Qt::QueuedConnection);
}