#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "folderopener.hpp"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    FolderOpener folderOpener;
    engine.rootContext()->setContextProperty("folderOpener", &folderOpener);

engine.load(QUrl::fromLocalFile("main.qml"));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
