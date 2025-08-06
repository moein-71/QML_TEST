#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "PersonHandler.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    PersonHandler handler;
    engine.rootContext()->setContextProperty("personHandler", &handler);

    const QUrl url(u"main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
