#include "include/fileseeker_manager.h"

QString FileseekerManager::prettyFileExtension(const QString &fileExtension)
{
    QString extensionBeginSpec = "*.";

    if (fileExtension.size() >= extensionBeginSpec.size())
    {
        if (QStringRef(&fileExtension, 0, extensionBeginSpec.size()) == extensionBeginSpec)
        {
            return fileExtension;
        }
    }

    return (extensionBeginSpec + fileExtension);
}

QStringList FileseekerManager::createFileExtensionsPack(const QStringList &fileExtensions)
{
    QStringList fileExtensionsPack;

    for (auto &fileExtension : fileExtensions)
    {
        fileExtensionsPack.push_back( prettyFileExtension(fileExtension) );
    }

    return fileExtensionsPack;
}

QStringList FileseekerManager::retrieveFilesByExtension(const QStringList &fileExtensions)
{
    QStringList fileExtensionsPack = createFileExtensionsPack(fileExtensions);

    return Fileseeker::getFilesByExtension(fileExtensionsPack);
}
