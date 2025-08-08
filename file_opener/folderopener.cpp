#include "folderopener.hpp"
#include <QDesktopServices>
#include <QUrl>
#include <QDir>

FolderOpener::FolderOpener(QObject *parent)
    : QObject(parent)
{
}

void FolderOpener::openFolder(const QString &folderPath)
{
    QUrl folderUrl = QUrl::fromLocalFile(QDir(folderPath).absolutePath());
    QDesktopServices::openUrl(folderUrl);
}
