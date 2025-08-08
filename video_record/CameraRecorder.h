#ifndef CAMERARECORDER_H
#define CAMERARECORDER_H

#include <QObject>
#include <QThread>
#include <QImage>
#include <opencv2/opencv.hpp>

class CameraRecorder : public QObject
{
    Q_OBJECT
public:
    explicit CameraRecorder(QObject *parent = nullptr);
    ~CameraRecorder();

    Q_INVOKABLE void startRecording(const QString &outputPath);
    Q_INVOKABLE void stopRecording();
    Q_INVOKABLE bool isRecording() const;

signals:
    void frameReady(const QImage &image);

private:
    void recordLoop();
    QThread m_thread;
    bool m_recording = false;
    QString m_outputPath;
};

#endif // CAMERARECORDER_H
~