#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "CameraRecorder.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    CameraRecorder recorder;
    engine.rootContext()->setContextProperty("cameraRecorder", &recorder);

    const QUrl url(u"qrc:/main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    engine.load(url);
    return app.exec();
}
