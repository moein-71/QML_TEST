#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "CameraRecorder.h"
#include "Camerahandler.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    Camerahandler recorder;
    ImageProvider * imageProvider = new ImageProvider();
    recorder.imgProvider = imageProvider ;

    qmlRegisterSingletonInstance("VideoRecorder", 1, 0, "Camerahandler", &recorder);
    // engine.rootContext()->setContextProperty("Camerahandler", &recorder);
    engine.rootContext()->setContextProperty("imageProvider", imageProvider);
    engine.addImageProvider("camera", imageProvider);

    const QUrl url(u"qrc:/main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}