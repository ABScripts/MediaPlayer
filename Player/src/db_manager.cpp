#include "include/db_manager.h"

#include <QDebug>

std::mutex DBManager::m_Mutex;
bool DBManager::m_IsLastConnectionOpen = false;
std::map<QString, QSqlDatabase> DBManager::m_DatabaseConnections;

DBManager::~DBManager()
{
    for (auto &[_, dbConnection] : m_DatabaseConnections)
    {
        dbConnection.close();
    }
}

QSqlDatabase &DBManager::createConnection(const QString &dbName, const QString &connectionName)
{
    const std::lock_guard<std::mutex> lock(m_Mutex);

    if (!isConnectionCreated(connectionName))
    {
        QSqlDatabase connection = QSqlDatabase::addDatabase("QSQLITE", connectionName);

        connection.setDatabaseName(dbName);

        m_IsLastConnectionOpen = connection.open();

        if ( m_IsLastConnectionOpen )
        {
            m_DatabaseConnections[connectionName] = connection;
            return m_DatabaseConnections[connectionName];
        }
        else
        {
            qCritical() << "Failed to open connection for " << dbName;
        }
    }
}

QSqlDatabase &DBManager::getConnection(const QString &connectionName)
{
    return m_DatabaseConnections[connectionName];
}

bool DBManager::isLastConnectionOpen()
{
    return m_IsLastConnectionOpen;
}

bool DBManager::isConnectionCreated(const QString &connectionName)
{
    return m_DatabaseConnections.find(connectionName) != m_DatabaseConnections.end();
}
