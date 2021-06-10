#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QVariant>

class PlaylistsSelector;
class PlaylistsManipulator;

class DBManager {
public:
    DBManager(const QString& dbPath);

    std::vector<QString> load(const PlaylistsSelector &selector, const QString &tableName); // this return dependency should be avoided -> create an. class ierh
    bool save(const PlaylistsManipulator &manipulator, const QString &tableName, const QString &data); // also useless data parameter
    bool isOpen() const;

    QStringList tables() const;

private:
    bool m_isOpen;
    QSqlDatabase m_Db;
    QSqlQuery m_QueryExecutor;
};
