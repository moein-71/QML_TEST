#ifndef BACKEND_H
#define BACKEND_H

#include <QObject>
#include <QString>

class Backend : public QObject
{
    Q_OBJECT
public:
    explicit Backend(QObject *parent = nullptr);

    Q_INVOKABLE void sendMessage(const QString &msg);

signals:
    void messageProcessed(const QString &result);
};

#endif // BACKEND_H
