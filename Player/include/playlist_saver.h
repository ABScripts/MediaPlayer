#include <QSqlDatabase>

class PlaylistSaver {
public:
    PlaylistSaver(QSqlDatabase &connection);
    void savePlaylist(const QString &playlistName, const QString &source);

private:
    void createTable(const QString &tableName);

private:
    QSqlDatabase m_DBConnection;
};
