#include "Backend.h"

Backend::Backend(QObject *parent)
    : QObject(parent), m_currentIndex(0)
{
    m_imageList << "qrc:/images/img1.png"
                << "qrc:/images/img2.png"
                << "qrc:/images/img3.png";

    emit imageListChanged();
    emit currentImageChanged();
}

QStringList Backend::imageList() const {
    return m_imageList;
}

int Backend::currentIndex() const {
    return m_currentIndex;
}

void Backend::setCurrentIndex(int idx) {
    if (idx >= 0 && idx < m_imageList.size()) {
        m_currentIndex = idx;
        emit currentIndexChanged();
        emit currentImageChanged();
    }
}

QString Backend::currentImage() const {
    if (m_currentIndex >= 0 && m_currentIndex < m_imageList.size())
        return m_imageList[m_currentIndex];
    return "";
}

void Backend::nextImage() {
    if (m_currentIndex + 1 < m_imageList.size()) {
        m_currentIndex++;
        emit currentIndexChanged();
        emit currentImageChanged();
    }
}

void Backend::previousImage() {
    if (m_currentIndex - 1 >= 0) {
        m_currentIndex--;
        emit currentIndexChanged();
        emit currentImageChanged();
    }
}
