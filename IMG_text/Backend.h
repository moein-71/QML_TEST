#ifndef BACKEND_H
#define BACKEND_H

#include <QObject>
#include <QString>
#include <QTimer>

class Backend : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString img READ get_img WRITE set_new_img NOTIFY img_changed)

public:
    explicit Backend(QObject *parent = nullptr);
    Q_INVOKABLE void set_new_img(QString img);
    QString get_img() ;

signals:
    void img_changed();

private:
    QString img ;
};

#endif // BACKEND_H
