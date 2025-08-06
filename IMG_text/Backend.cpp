#include "Backend.h"
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>

Backend::Backend(QObject *parent)
    : QObject(parent)
{}

Q_INVOKABLE void Backend::set_new_img(QString img) {
    this->img = img ;
    emit this->img_changed() ;
}

QString Backend::get_img() {
    return this->img ;
}