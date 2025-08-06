#include "PersonHandler.h"

PersonHandler::PersonHandler(QObject *parent) : QObject(parent) {}

QString PersonHandler::makeGreeting(const QString &name) {
    if (name.trimmed().isEmpty())
        return "Enter name : ";
    return "hi " + name ;
}
