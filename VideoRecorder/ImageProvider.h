    #ifndef IMAGEPROVIDER_H
    #define IMAGEPROVIDER_H

    #include <QQuickImageProvider>
    #include <QImage>
    #include <QMutex>

    class ImageProvider : public QQuickImageProvider {
        Q_OBJECT
        public:
            ImageProvider();

            QImage requestImage(const QString &id, QSize *size, const QSize &requestedSize) override;
            
        public slots:
            void setImage(const QImage &img) ;

        signals:
            void imageChanged();

        private:
        QImage image;
        QMutex mutex;

    };

    #endif // IMAGEPROVIDER_H
