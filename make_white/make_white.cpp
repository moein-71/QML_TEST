#include <QCoreApplication>
#include <QImage>
#include <QColor>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString inputPath = "minute.png";
    QString outputPath = "output.png";

    QImage image(inputPath);
    if (image.isNull()) {
        qWarning() << "dont uploaded";
        return -1;
    }

    if (image.format() != QImage::Format_ARGB32) {
        image = image.convertToFormat(QImage::Format_ARGB32); //being alpha
    }

    for (int y = 0; y < image.height(); ++y) {
        for (int x = 0; x < image.width(); ++x) {
            QColor color = image.pixelColor(x, y);
            // from now we know what is alpha
            if (color.red() == 0 && color.green() == 0 && color.blue() == 0 && color.alpha() > 0) {
                image.setPixelColor(x, y, QColor(255, 255, 255, color.alpha()));
            }
        }
    }

    if (image.save(outputPath)) {
        qDebug() << "pic saved" << outputPath;
    } else {
        qWarning() << "pic not saved";
    }

    return 0;
} 