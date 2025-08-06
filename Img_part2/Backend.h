#ifndef BACKEND_H
#define BACKEND_H

#include <QObject>
#include <QStringList>

class Backend : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QStringList imageList READ imageList NOTIFY imageListChanged)
    Q_PROPERTY(int currentIndex READ currentIndex WRITE setCurrentIndex NOTIFY currentIndexChanged)
    Q_PROPERTY(QString currentImage READ currentImage NOTIFY currentImageChanged)

public:
    explicit Backend(QObject *parent = nullptr);

    QStringList imageList() const;
    int currentIndex() const;
    void setCurrentIndex(int idx);
    QString currentImage() const;

    Q_INVOKABLE void nextImage();
    Q_INVOKABLE void previousImage();

signals:
    void imageListChanged();
    void currentIndexChanged();
    void currentImageChanged();

private:
    QStringList m_imageList;
    int m_currentIndex;
};

#endif // BACKEND_H

