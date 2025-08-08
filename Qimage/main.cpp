#include <QApplication>
#include <QImage>
#include <QPixmap>
#include <QLabel>
#include <QColor>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // بارگذاری تصویر
    QImage img("clock-face.png");
    if (img.isNull()) {
        qWarning("pic dont load");
        return -1;
    }
    img = img.scaled(1920 , 1600 , Qt::KeepAspectRatio) ;
    int halfHeight = img.height();
    for (int y = 0; y < halfHeight; ++y) {
        for (int x = 0; x < img.width(); ++x) {
            QColor color = img.pixelColor(x, y);
            int gray = qGray(color.rgb()); 
            img.setPixelColor(x, y, QColor(gray, gray, gray));
        }
    }

    QLabel* label = new QLabel;
    label->setPixmap(QPixmap::fromImage(img));
    label->resize(img.size());
    label->show();

    return app.exec();
}
