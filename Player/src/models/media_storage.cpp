#include "include/models/media_storage.h"

#include <thread>
#include <QMediaPlayer>
#include <QFileInfo>

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
    m_WorkingThread = new std::thread(&MediaStorage::indexMediaStorage, this);
}

Composition MediaStorage::getMediafileByIndex(int index) const
{
    return m_MediaFiles[index];
}

int MediaStorage::size() const
{
    return m_MediaFiles.size();
}

MediaStorage::~MediaStorage()
{
    m_WorkingThread->join();

    delete m_WorkingThread;
}

void MediaStorage::addMedia(const QString &mediaSource)
{
    QMediaPlayer metadataExtractor;

    metadataExtractor.setMedia(QUrl::fromLocalFile(mediaSource));

    QString mediaTitle = metadataExtractor.metaData("AlbumTitle").toString();
    QString mediaGenre = metadataExtractor.metaData("Genre").toString();
    QDate mediaReleaseData = metadataExtractor.metaData("Date").toDate();

    const std::lock_guard<std::mutex> lock(m_Mutex);

    emit beginInsertMedia();
    m_MediaFiles.emplace_back(mediaSource, mediaTitle, mediaGenre, mediaReleaseData);

    emit endInsertMedia();
}

MediaStorage::MediaStorage()
    : m_SupportedFilesExtensions {"mp3", "mp4"}
{
    setupMediaStorage();
}

void MediaStorage::indexMediaStorage()
{
    QStringList mediaFiles = FileseekerManager::retrieveFilesByExtension(m_SupportedFilesExtensions);

    m_MediaFiles.reserve(mediaFiles.size());

    for (auto &mediaFile : mediaFiles)
    {
        addMedia(mediaFile);
    }

    emit mediaLoaded();
}

bool MediaStorage::isMediafileIndexValid(int index) const
{
    return (index >= 0 && index < static_cast<int>(m_MediaFiles.size()));
}

const std::vector<Composition> &MediaStorage::getMediaFiles() const
{
    return m_MediaFiles;
}
