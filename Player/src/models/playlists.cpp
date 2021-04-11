#include "include/models/playlists.h"
#include "include/models/playlist_media.h"

#include <QObject>

Playlists::Playlists(PlaylistMedia *playlistMedia, QObject *parent)
    : QAbstractListModel(parent)
    , m_PlaylistMedia(playlistMedia)
{
    setMockData();

   // connect(m_PlaylistMedia, &PlaylistMedia::playlistEmpty, this, &Playlists::deletePlaylist);
}

int Playlists::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);

    return m_Playlists.size();
}

QVariant Playlists::data(const QModelIndex &index, int role) const
{
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
    if (!isNameTaken(name))
    {
        beginInsertRows(QModelIndex(), m_PlaylistsNames.size(), m_PlaylistsNames.size());
        m_PlaylistsNames.emplace_back(name);
        m_Playlists[name] = PlaylistElement(name);
        endInsertRows();

        emit mediafileAddedSuccesfully();
    }
    else
    {
        emit nameAlreadyTaken();
    }
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

    //m_PlaylistMedia->addMediaToPlaylist(mediafileIndex);
    m_Playlists[ playlistName ].addMediafile(mediafileIndex);
}

void Playlists::deleteMediaFromPLaylist(int mediafileIndex)
{
    m_PlaylistMedia->deleteMediaFromPlaylisit(mediafileIndex);
}

void Playlists::setPlaylistMedia(int index)
{
    QString playlistMediaName = m_PlaylistsNames[index];
    m_PlaylistMedia->setPlaylist( &m_Playlists [playlistMediaName] );
}

bool Playlists::isIndexValid(int index) const
{
    return (index >= 0 && index < static_cast<int>(m_Playlists.size()));
}

bool Playlists::isNameTaken(const QString &name) const
{
    return (m_Playlists.find(name) != m_Playlists.end());
}

void Playlists::setMockData()
{
//    add("Favourite");

//    addMediaToPlaylist(0, "Favourite");
//    addMediaToPlaylist(4, "Favourite");
//    addMediaToPlaylist(12, "Favourite");
//    addMediaToPlaylist(15, "Favourite");

    // m_PlaylistMedia->setPlaylist(&m_Playlists.at("Favourite"));
}

//void Playlists::deletePlaylist()
//{

//}

QHash<int, QByteArray> Playlists::roleNames() const
{
    QHash<int, QByteArray> roleNames;
    roleNames[Name] = "name";
    roleNames[MediaFilesCount] = "mediafilescount";

    return roleNames;
}
