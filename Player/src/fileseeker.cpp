#include "include/fileseeker.h"

#include <QDirIterator>

QStringList Fileseeker::getFilesByExtension(const QStringList &fileExtensions)
{
    QFileInfoList drives = QDir::drives();

    QStringList filesFound;

    for (auto &drive : drives)
    {
            QDirIterator fileIterator(drive.path(),  fileExtensions, QDir::Files, QDirIterator::Subdirectories);
            while (fileIterator.hasNext()) {
                filesFound.push_back(fileIterator.next());
            }
    }

    return filesFound;
}

