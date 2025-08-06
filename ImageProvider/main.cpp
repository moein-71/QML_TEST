#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "ImageProvider.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    // پردازش تصویر
    QImage original("Start.jpg");
    QImage halfGray = original;

    for (int y = 0; y < halfGray.height(); ++y) {
        for (int x = 0; x < halfGray.width() / 2; ++x) {
            QColor color = halfGray.pixelColor(x, y);
            int gray = qGray(color.rgb());
            color.setRgb(gray, gray, gray);
            halfGray.setPixelColor(x, y, color);
        }
    }

    // تنظیم تصویر در ImageProvider
    auto *provider = new ImageProvider;
    provider->setImage(halfGray);
    engine.addImageProvider("custom", provider);

    engine.load(QUrl(QStringLiteral("main.qml")));

    return app.exec();
}
