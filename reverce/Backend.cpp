#include "Backend.h"
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>

Backend::Backend(QObject *parent)
    : QObject(parent)
{}

void Backend::make_reverse(QString salem) {
    this -> notrev = salem ;
    std::string a = salem.toStdString() ;
    std::reverse(a.begin(), a.end());
    this -> rev = QString::fromStdString(a) ;
    emit rev_changed() ;
}

QString Backend::mrev() {
    return rev ;
}