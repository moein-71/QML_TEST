#ifndef BACKEND_H
#define BACKEND_H

#include <QObject>

class Backend : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString outputText READ outputText NOTIFY outputTextChanged)

public:
    explicit Backend(QObject *parent = nullptr);

    Q_INVOKABLE void updateText(const QString &input);

    QString outputText() const;

signals:
    void outputTextChanged();

private:
    QString m_outputText;
};

#endif // BACKEND_H
    