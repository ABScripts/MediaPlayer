#include "include/models/playlists.h"
#include "include/models/playlist_media.h"

#include <QObject>

Playlists::Playlists(MediaStorage *mediaStorage, PlaylistMedia *playlistMedia, QObject *parent)
    : QAbstractListModel(parent)
    , m_PlaylistMedia(playlistMedia)
    , m_MediaStorage(mediaStorage)
{
    connect(m_MediaStorage, &MediaStorage::mediaLoaded, this, &Playlists::loadPlaylists);
    connect(m_PlaylistMedia, &PlaylistMedia::playlistEmpty, this, &Playlists::deletePlaylist);
}

Playlists::~Playlists()
{
    m_WorkingThread.join();
}

int Playlists::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);

    return m_Playlists.size();
}

QVariant Playlists::data(const QModelIndex &index, int role) const
{
    qDebug() << "data";
    if (!index.isValid() || index.row() >= static_cast<int>(m_Playlists.size()))
    {
        return {};
    }

    QVariant value;

    if (role == Roles::Name)
    {
        value = QVariant(m_PlaylistsNames[index.row()]);
    } else if (role == Roles::MediaFilesCount)
    {
        value = QVariant(m_Playlists.at(m_PlaylistsNames[index.row()]).size());
    }

    return value;
}

void Playlists::add(QString name)
{
    beginInsertRows(QModelIndex(), m_PlaylistsNames.size(), m_PlaylistsNames.size());

    m_PlaylistsNames.emplace_back(name);
    m_Playlists[name] = PlaylistElement(name);

    endInsertRows();
}

void Playlists::remove(int index)
{
    if (isIndexValid(index))
    {
        m_Playlists.erase( m_PlaylistsNames[index] );
        m_PlaylistsNames.erase(m_PlaylistsNames.begin() + index);
    }
}

void Playlists::addMediaToPlaylist(int mediafileIndex, QString playlistName)
{
    if (m_Playlists[ playlistName ].addMediafile(mediafileIndex))
    {
        m_PlaylistManager.savePlaylist(playlistName, m_MediaStorage->getMediafileByIndex(mediafileIndex).m_Source); // save to db
    }
}

void Playlists::addMediaToPlaylist(QString playlistName)
{
    addMediaToPlaylist(m_SelectedLibraryIndex, playlistName);
}

void Playlists::deleteMediaFromPLaylist(int mediafileIndex)
{
    QString playlistName = m_PlaylistsNames[m_SelectedPlaylistIndex];
    m_PlaylistManager.deleteMedia(playlistName, m_Playlists[playlistName].getMediafile(mediafileIndex).m_Source);

    m_PlaylistMedia->deleteMediaFromPlaylisit(mediafileIndex);
}

void Playlists::setPlaylistMedia(int index)
{
    m_SelectedPlaylistIndex = index;

    QString playlistMediaName = m_PlaylistsNames[index];
    m_PlaylistMedia->setPlaylist( &m_Playlists [playlistMediaName] );
}

int Playlists::size() const
{
    return m_Playlists.size();
}

bool Playlists::isIndexValid(int index) const
{
    return (index >= 0 && index < static_cast<int>(m_Playlists.size()));
}

bool Playlists::isNameTaken(const QString &name) const
{
    return (m_Playlists.find(name) != m_Playlists.end());
}

void Playlists::setSelectedLibraryIndex(int SelectedLibraryIndex)
{
    m_SelectedLibraryIndex = SelectedLibraryIndex;
}

void Playlists::loadPlaylists()
{
    m_WorkingThread = std::thread(&Playlists::loadPlaylistWorkThread, this);
}

void Playlists::loadPlaylistWorkThread()
{
    std::vector<QString> playlistNames = m_PlaylistManager.getPlaylistNames();

    for (auto &playlistName : playlistNames)
    {
        std::vector<int> playlist = m_PlaylistManager.loadPlaylist(playlistName, m_MediaStorage->getMediaFiles());

        add(playlistName);

        for (auto media : playlist)
        {
            m_Playlists[ playlistName ].addMediafile(media);
        }
    }

    emit playlistsLoaded();
}

void Playlists::deletePlaylist(QString name)
{
    m_PlaylistManager.deletePlaylist(name);
}

QHash<int, QByteArray> Playlists::roleNames() const
{
    QHash<int, QByteArray> roleNames;
    roleNames[Name] = "name";
    roleNames[MediaFilesCount] = "mediafilescount";

    return roleNames;
}
