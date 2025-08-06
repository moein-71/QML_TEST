#include "Backend.hpp"

Backend::Backend(QObject *parent) : QObject(parent)
{
}

void Backend::sendMessage(const QString &msg)
{
    emit messageReceived(msg); // be in ehtiaj darom chon mire baraye qml
}
