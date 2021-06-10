#ifndef FILESEEKER_H
#define FILESEEKER_H

#include <QStringList>

class Fileseeker {

public:
    static QStringList getFilesByExtension(const QStringList &fileExtensions);
};

#endif
