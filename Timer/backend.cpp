#include "Backend.h"
#include <QDateTime>

Backend::Backend(QObject *parent)
    : QObject{parent}
{}

QString Backend::get_time() {
    return QDateTime::currentDateTime().toString("hh:mm:ss");
}


