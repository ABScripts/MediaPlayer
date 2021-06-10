#include "include/playlist_saver.h"

#include <QSqlQuery>

PlaylistSaver::PlaylistSaver(QSqlDatabase &connection)
    : m_DBConnection(connection)
{

}

void PlaylistSaver::savePlaylist(const QString &playlistName, const QString &source)
{  
    createTable(playlistName);

    const QString _insertQuery = "INSERT INTO " + playlistName +
            " (source) VALUES (\"" + source + "\")";

    QSqlQuery insertQuery(m_DBConnection);

    insertQuery.exec(_insertQuery);
}

void PlaylistSaver::createTable(const QString &tableName)
{
    QString _createTableQuery = "CREATE TABLE IF NOT EXISTS " + tableName + " (source TEXT)";

    QSqlQuery createTableQuery(m_DBConnection);

    createTableQuery.exec(_createTableQuery);
}
