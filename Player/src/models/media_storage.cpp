#include "include/models/media_storage.h"

#include <QMediaPlayer>

MediaStorage *MediaStorage::m_Instance = nullptr;
std::mutex MediaStorage::m_Mutex;

MediaStorage *MediaStorage::getInstanse()
{
    m_Mutex.lock();

    if (!m_Instance) {
        m_Instance = new MediaStorage();
    }

    m_Mutex.unlock();

    return m_Instance;
}

void MediaStorage::setupMediaStorage()
{
    indexMediaStorage();
}

Composition MediaStorage::getMediafileByIndex(int index) const
{
//    if (isMediafileIndexValid(index))
//    {
        return m_MediaFiles[index];
}

int MediaStorage::size() const
{
    return m_MediaFiles.size();
}

MediaStorage::MediaStorage()
    : m_SupportedFilesExtensions {"mp3"}
{
    setupMediaStorage();
}

void MediaStorage::indexMediaStorage()
{
    std::set<std::string> mediaFiles = FileseekerManager::retrieveFiles(m_SupportedFilesExtensions);

    m_MediaFiles.reserve(mediaFiles.size());

    QMediaPlayer metadataExtractor;

    for (auto &mediaFile : mediaFiles)
    {
        metadataExtractor.setMedia(QUrl::fromLocalFile(QString::fromStdString(mediaFile)));

        QString mediaTitle = metadataExtractor.metaData("AlbumTitle").toString();
        QString mediaGenre = metadataExtractor.metaData("Genre").toString();
        QDate mediaReleaseData = metadataExtractor.metaData("Date").toDate();

        int insertIndex = m_MediaFiles.size() - 1;
        emit beginInsertNewMediafiles(insertIndex, insertIndex);
        m_MediaFiles.emplace_back(
                    QString::fromStdString(mediaFile), mediaTitle, mediaGenre, mediaReleaseData);
        emit endInsertNewMediafiles();
    }

}

bool MediaStorage::isMediafileIndexValid(int index) const
{
    return (index >= 0 && index < static_cast<int>(m_MediaFiles.size()));
}
