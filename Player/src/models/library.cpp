#include "include/models/library.h"

#include "include/models/media_storage.h"

#include <QtMultimedia/QMediaPlayer>
#include <QDebug>

Library::Library(MediaStorage *mediaStorage, QObject *parent)
    : MediaSourceListModel(parent)
    , m_MediaStorage {mediaStorage}
//    , m_SupportedFileExtensions {"mp3"}
{
//   indexMediaFiles();

    //    m_CurrentMediaFile = m_MediaFiles.begin();
}

bool Library::isMediafileIndexValid(int mediaFileIndex) const
{
    return (mediaFileIndex >= 0 && mediaFileIndex < static_cast<int>(size()));
}

//void Library::indexMediaFiles()
//{
//    std::set<std::string> mediaFiles = FileseekerManager::retrieveFiles(m_SupportedFileExtensions);

//    m_MediaFiles.reserve(mediaFiles.size());

//    QMediaPlayer metadataExtractor;

//    for (auto &mediaFile : mediaFiles)
//    {
//        metadataExtractor.setMedia(QUrl::fromLocalFile(QString::fromStdString(mediaFile)));

//        QString mediaTitle = metadataExtractor.metaData("AlbumTitle").toString();
//        QString mediaGenre = metadataExtractor.metaData("Genre").toString();
//        QDate mediaReleaseData = metadataExtractor.metaData("Date").toDate();

//        beginInsertRows(QModelIndex(), rowCount(), rowCount());
//        m_MediaFiles.emplace_back(
//                    QString::fromStdString(mediaFile), mediaTitle, mediaGenre, mediaReleaseData);
//        endInsertRows();
//    }
//}

int Library::size() const
{
    return m_MediaStorage->size();
    //return m_MediaFiles.size();
}

//std::thread Library::indexMedia()
//{
//    return std::thread( [this] {this->indexMedia();} );
//}

//void Library::addComposition(QString source, QString title, QString genre, QDate releaseDate)
//{
//    beginInsertRows(QModelIndex(), rowCount(), rowCount());
//    //m_MediaFiles.emplace_back(source, title, genre, releaseDate);
//    endInsertRows();
//}

//bool Library::mediaFileIndexIsValid(int mediaFileIndex) const
//{
//    return (mediaFileIndex >= 0 && mediaFileIndex < static_cast<int>(m_MediaFiles.size()));
//}

int Library::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);

    qDebug() << size();
    return size();
}

QVariant Library::data(const QModelIndex &index, int role) const
{
//    if (!index.isValid() || index.row() >= static_cast<int>(m_MediaFiles.size()))
    if (!isMediafileIndexValid(index.row()))
        return QVariant();

    QVariant value;

    Composition composition = m_MediaStorage->getMediafileByIndex(index.row());//m_MediaFiles[index.row()];
    if (role == TitleRole) {
        value = QVariant(composition.m_Title);
    } else if (role == GenreRole)
    {
        value = QVariant(composition.m_Genre);
    } else if (role == ReleaseDateRole)
    {
        value = QVariant(composition.m_ReleaseDate.currentDate().toString("dd.MM.yyyy"));
    }

    return value;
}

QHash<int, QByteArray> Library::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[TitleRole] = "title";
    roles[GenreRole] = "genre";
    roles[ReleaseDateRole] = "releaseDate";
    return roles;
}

QString Library::getNextMediaFile(int &mediaFileIndex) const
{
    if (!isMediafileIndexValid(mediaFileIndex))
    {
        return {};
    }

    ++mediaFileIndex;

    if (mediaFileIndex == static_cast<int>(size()))
    {
        mediaFileIndex = 0;
    }

    return m_MediaStorage->getMediafileByIndex(mediaFileIndex).m_Source;
}

QString Library::getPreviousMediaFile(int &mediaFileIndex) const
{
    if (!isMediafileIndexValid(mediaFileIndex))
    {
        return {};
    }

    --mediaFileIndex;

    if (mediaFileIndex < 0)
    {
        mediaFileIndex = static_cast<int>(size() - 1);
    }

    return m_MediaStorage->getMediafileByIndex(mediaFileIndex).m_Source;
}

QString Library::getMediaFileByIndex(int &mediaFileIndex) const
{
    if (isMediafileIndexValid(mediaFileIndex))
    {
        return m_MediaStorage->getMediafileByIndex(mediaFileIndex).m_Source;
    }

    return {};
}

QString Library::getCurrentMediaFileTitle() const
{
    return m_CurrentMediaFile.m_Title;
}
