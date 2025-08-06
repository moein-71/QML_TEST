#ifndef PERSONHANDLER_H
#define PERSONHANDLER_H

#include <QObject>
#include <QString>

class PersonHandler : public QObject
{
    Q_OBJECT
public:
    explicit PersonHandler(QObject *parent = nullptr);

    Q_INVOKABLE QString makeGreeting(const QString &name);
};

#endif // PERSONHANDLER_H
