#ifndef FOLDEROPENER_H
#define FOLDEROPENER_H

#include <QObject>

class FolderOpener : public QObject
{
    Q_OBJECT
public:
    explicit FolderOpener(QObject *parent = nullptr);

    Q_INVOKABLE void openFolder(const QString &folderPath);
};

#endif // FOLDEROPENER_H
