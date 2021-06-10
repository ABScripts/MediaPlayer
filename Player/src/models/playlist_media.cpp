#include "include/models/playlist_media.h"
#include "include/playlist_element.h"

#include <QDebug>

PlaylistMedia::PlaylistMedia(MediaStorage *mediaStorage, QObject *parent)
    : MediaSourceListModel(parent)
    , m_Playlist     { nullptr }
    , m_MediaStorage {mediaStorage}
{

}

void PlaylistMedia::setPlaylist(PlaylistElement *playlistElement)
{
    if (isPlaylistValid(playlistElement))
    {
        m_Playlist = playlistElement;
        m_Playlist->setMediaStorage(m_MediaStorage);
    }
}

void PlaylistMedia::addMediaToPlaylist(int storageMediaIndex)
{
    beginInsertRows(QModelIndex(), m_Playlist->size(), m_Playlist->size());
    m_Playlist->addMediafile(storageMediaIndex);
    endInsertRows();
}

void PlaylistMedia::deleteMediaFromPlaylisit(int index)
{
    beginRemoveRows(QModelIndex(), index, index);
    m_Playlist->deleteMediafile(index);

    if (m_Playlist->isEmpty()) {
        emit playlistEmpty(m_Playlist->name());
    }
    endRemoveRows();
}

int PlaylistMedia::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);

    if (!m_Playlist)
    {
        return {};
    }

    return m_Playlist->size();
}

QVariant PlaylistMedia::data(const QModelIndex &index, int role) const
{
    if (!m_Playlist)
    {
        return {};
    }

    if (!index.isValid() || index.row() >= m_Playlist->size())
    {
        return {};
    }

    QVariant value;

    Composition composition = m_Playlist->getMediafile(index.row());
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

QHash<int, QByteArray> PlaylistMedia::roleNames() const
{
    QHash<int, QByteArray> roleNames;
    roleNames[TitleRole] = "title";
    roleNames[GenreRole] = "genre";
    roleNames[ReleaseDateRole] = "releaseDate";

    return roleNames;
}

bool PlaylistMedia::isPlaylistValid(PlaylistElement *playlistElement) const
{
    return (playlistElement != nullptr);
}

bool PlaylistMedia::isPlaylistMediafileIndexValid(int index) const
{
    return (index >= 0 && index < m_Playlist->size());
}

void PlaylistMedia::setPlaylistElement(PlaylistElement *playlistElement)
{
    m_Playlist = playlistElement;
    m_Playlist->setMediaStorage(m_MediaStorage);
}

QString PlaylistMedia::getNextMediaFile(int &index) const
{
    ++index;

    if (index == m_Playlist->size()) {
        index = 0;
    }

    return m_Playlist->getMediafile(index).m_Source;
}

QString PlaylistMedia::getPreviousMediaFile(int &index) const
{
    --index;

    if (index < 0) {
        index = m_Playlist->size();
    }

    return m_Playlist->getMediafile(index).m_Source;
}

QString PlaylistMedia::getMediaFileByIndex(int &index) const
{
    if (isPlaylistMediafileIndexValid(index)) {
            return m_Playlist->getMediafile(index).m_Source;
    }
    return {};
}

QString PlaylistMedia::getCurrentMediaFileTitle() const
{
}
