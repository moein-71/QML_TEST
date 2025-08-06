#include "Backend.h"
#include <QDebug>

Backend::Backend(QObject *parent) : QObject(parent) {}

void Backend::sendMessage(const QString &msg)
{
    qDebug() << "get from QML:" << msg;

    QString processed = msg.toUpper(); 
    emit messageProcessed(processed);  
}
