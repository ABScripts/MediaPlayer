#include "include/playlist_loader.h"

#include <QSqlQuery>
#include <QVariant>

PlaylistLoader::PlaylistLoader(QSqlDatabase &connection)
    : m_Connection(connection)
{

}

std::vector<QString> PlaylistLoader::loadPlaylist(const QString &playlistName) const
{
    const QString loadAllPlaylistsQuery = "SELECT source FROM ";

    std::vector<QString> sources;

    QSqlQuery selectQuery(m_Connection);

    bool queryOk = selectQuery.exec(loadAllPlaylistsQuery + playlistName);

    if (queryOk)
    {
        while (selectQuery.next())
        {
            sources.emplace_back(selectQuery.value(0).toString());
        }
    }

    return sources;
}
