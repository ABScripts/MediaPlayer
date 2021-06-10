#include "include/controllers/media_loader_controller.h"
#include "include/models/media_storage.h"

#include <QDir>
#include <QString>

MediaLoaderController::MediaLoaderController(MediaStorage *mediaStorage, QObject *parent)
    : QObject(parent)
    , m_MediaStorage(mediaStorage)
{

}

bool MediaLoaderController::isMediaStorageValid() const
{
    return m_MediaStorage != nullptr;
}

void MediaLoaderController::onFileLoaded(const QString &source)
{
    if (isMediaStorageValid())
    {
        QString depricatedBeginPattern = "file://";
        QString depricatedEndPattern = "\r\n";

        QString prettierSource;
        const QString * finalSource = &source;

        if (!source.isEmpty())
        {
            if (source.size() >= std::min(depricatedBeginPattern.size(), depricatedEndPattern.size()))
            {
                finalSource = &(prettierSource = source);
                prettierSource.remove(depricatedBeginPattern);
                prettierSource.remove(depricatedEndPattern);
            }

            m_MediaStorage->addMedia(*finalSource);
        }
    }
}
