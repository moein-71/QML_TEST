#ifndef BACKEND_H
#define BACKEND_H

#include <QObject>
#include <QString>
#include <QTimer>

class Backend : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString rev READ mrev NOTIFY rev_changed)

public:
    explicit Backend(QObject *parent = nullptr);
    Q_INVOKABLE void make_reverse(QString salem);
    QString mrev() ;

signals:
    void rev_changed();


private:
    QString rev ;
    QString notrev;
};

#endif // BACKEND_H
