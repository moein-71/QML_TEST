#include "ImageProvider.h"

ImageProvider::ImageProvider() : QQuickImageProvider(QQuickImageProvider::Image) {
}

QImage ImageProvider::requestImage(const QString &id, QSize *size, const QSize &requestedSize) {
    QMutexLocker locker(&mutex);

    if (image.isNull())
        return QImage();

    if (size)
        *size = image.size();

    if (requestedSize.width() > 0 && requestedSize.height() > 0)
        return image.scaled(requestedSize);

    return image;
}

void ImageProvider::setImage(const QImage &img) {
    QMutexLocker locker(&mutex);
    image = img.copy();
    emit imageChanged();
}

