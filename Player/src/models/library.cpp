#include "include/models/library.h"

#include "include/models/media_storage.h"

#include <QtMultimedia/QMediaPlayer>

Library::Library(MediaStorage *mediaStorage, QObject *parent)
    : MediaSourceListModel(parent)
    , m_MediaStorage {mediaStorage}
{
    connect(m_MediaStorage, &MediaStorage::beginInsertMedia, this, &Library::newMediaAboutToArrive);
    connect(m_MediaStorage, &MediaStorage::endInsertMedia, this, &Library::newMediaArrived);
    connect(m_MediaStorage, &MediaStorage::mediaLoaded, this, &Library::mediaLoaded);
}

bool Library::isMediafileIndexValid(int mediaFileIndex) const
{
    return (mediaFileIndex >= 0 && mediaFileIndex < static_cast<int>(size()));
}

bool Library::isEmpty() const
{
    return size() == 0;
}

int Library::size() const
{
    return m_MediaStorage->size();
}

int Library::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);

    return size();
}

void Library::newMediaAboutToArrive() {
    emit layoutAboutToBeChanged();
}

void Library::newMediaArrived() {
    emit layoutChanged();
}

QVariant Library::data(const QModelIndex &index, int role) const
{
    if (!isMediafileIndexValid(index.row()))
        return QVariant();

    QVariant value;

    Composition composition = m_MediaStorage->getMediafileByIndex(index.row());
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
