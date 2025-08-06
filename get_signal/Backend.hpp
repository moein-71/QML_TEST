#ifndef BACKEND_H
#define BACKEND_H

#include <QObject>
#include <QString>

class Backend : public QObject
{
    Q_OBJECT
public:
    explicit Backend(QObject *parent = nullptr);

    void sendMessage(const QString &msg);

signals:
    void messageReceived(const QString &msg);
};

#endif // BACKEND_H
