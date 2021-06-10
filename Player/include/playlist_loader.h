#include <vector>

#include <QSqlDatabase>

class PlaylistLoader {
public:
    PlaylistLoader(QSqlDatabase &connection);

    std::vector<QString> loadPlaylist(const QString &playlistName) const;

private:
    QSqlDatabase m_Connection;
};
