#include <map>
#include <mutex>
#include <QtSql/QSqlDatabase>

class DBManager {
public:
    ~DBManager();

    static QSqlDatabase &createConnection(const QString &dbName, const QString &connectionName);
    static QSqlDatabase &getConnection(const QString &connectionName);
    static bool isLastConnectionOpen();

private:
    static bool isConnectionCreated(const QString &connectionName);

private:
    static std::map<QString, QSqlDatabase> m_DatabaseConnections;
    static bool m_IsLastConnectionOpen;
    static std::mutex m_Mutex;
};
