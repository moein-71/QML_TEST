#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "TaskModel.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    TaskModel taskModel;
    engine.rootContext()->setContextProperty("taskModel", &taskModel);

    const QUrl url(u"main.qml"_qs);
    engine.load(url);

    return app.exec();
}
