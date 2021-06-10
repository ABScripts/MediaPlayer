#include "include/playlist_manager.h"

#include <QSqlQuery>

const QString PlaylistManager::playlistsDBPath = "Playlists";
const QString PlaylistManager::loaderConnectionName = "loaderConnection";
const QString PlaylistManager::saverConnectionName = "saverConnection";

PlaylistManager::PlaylistManager()
    : m_PlaylistLoader(DBManager::createConnection(playlistsDBPath, loaderConnectionName))
    , m_PlaylistSaver(DBManager::createConnection(playlistsDBPath, saverConnectionName))
{

}

std::vector<int> PlaylistManager::loadPlaylist(const QString &playlistName, const std::vector<Composition> &compositions) const
{
    std::vector<QString> sources = m_PlaylistLoader.loadPlaylist(playlistName);

    std::vector<int> playlistMediaMap;
    playlistMediaMap.reserve(sources.size());

    for (int i = 0; i < static_cast<int>(sources.size()); ++i)
    {
        for (int j = 0; j < static_cast<int>(compositions.size()); ++j)
        {
            if (sources[i] == compositions[j].m_Source) {
                playlistMediaMap.push_back(j);
            }
        }
    }

    return playlistMediaMap;
}

void PlaylistManager::savePlaylist(const QString &playlistName, const QString &source)
{
    m_PlaylistSaver.savePlaylist(playlistName, source);
}

// Actually i was not sure how to deal with these operations `couse I feel like creating additional class for that is an overhelm.
void PlaylistManager::deleteMedia(const QString &playlistName, const QString &source)
{
    QString _deleteQuery = "DELETE FROM " + playlistName +  " WHERE source=\"" + source + "\"";

    QSqlQuery deleteQuery(DBManager::getConnection(loaderConnectionName));

    deleteQuery.exec(_deleteQuery);
}

void PlaylistManager::deletePlaylist(const QString &name)
{
    QString _deleteTableQuery = "DROP TABLE " + name;

    QSqlQuery deleteTableQuery(DBManager::getConnection(loaderConnectionName));

    deleteTableQuery.exec(_deleteTableQuery);
}

std::vector<QString> PlaylistManager::getPlaylistNames() const
{
    QStringList names = DBManager::getConnection(loaderConnectionName).tables();

    std::vector<QString> playlistNames;

    std::copy(names.begin(), names.end(), std::back_inserter(playlistNames));

    return playlistNames;
}

bool PlaylistManager::isDBAccessed() const
{
    return DBManager::getConnection(loaderConnectionName).isValid() &&
           DBManager::getConnection(saverConnectionName).isValid();
}
