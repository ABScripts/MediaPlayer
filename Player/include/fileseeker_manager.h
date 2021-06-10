#ifndef FILESEEKER_MANAGER_H
#define FILESEEKER_MANAGER_H

#include "include/fileseeker.h"

class FileseekerManager {
    
public:
    static QStringList retrieveFilesByExtension(const QStringList &fileExtensions);

private:
    static QString prettyFileExtension(const QString &fileExtensions);
    static QStringList createFileExtensionsPack(const QStringList &fileExtensions);
};

#endif
