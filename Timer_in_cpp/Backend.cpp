#include "Backend.h"
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>

Backend::Backend(QObject *parent)
    : QObject(parent)
{
    update_date();

    connect(&m_timer, &QTimer::timeout, this, &Backend::update_date);
    m_timer.start(1000); 
}

QString Backend::date() {
    return m_date;
}

void Backend::update_date() {
    auto now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);
    std::tm *parts = std::localtime(&now_c);

    std::ostringstream oss;
    oss << std::put_time(parts, "%Y-%m-%d %H:%M:%S");
    QString newDate = QString::fromStdString(oss.str());

    if (newDate != m_date) {
        m_date = newDate;
        emit date_changed();
    }
}
