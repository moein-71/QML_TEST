#ifndef BACKEND_H
#define BACKEND_H

#include <QObject>
#include <QString>
#include <QTimer>

class Backend : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString date READ date NOTIFY date_changed)

public:
    explicit Backend(QObject *parent = nullptr);
    QString date();

signals:
    void date_changed();

private slots:
    void update_date();  

private:
    QString m_date;
    QTimer m_timer;  
};

#endif // BACKEND_H
