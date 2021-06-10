#include "include/db_manager.h"
#include "manipulator.h"
#include "selector.h"
#include <QDebug>

DBManager::DBManager(const QString& dbPath)
{
    m_Db = QSqlDatabase::addDatabase("QSQLITE"); // check for driver availability first
    m_Db.setDatabaseName(dbPath);

    m_isOpen = m_Db.open();

    if (!m_isOpen)
    {
        qCritical() << "Failed to open db: " << dbPath;
    }
}

std::vector<QString> DBManager::load(const PlaylistsSelector &selector, const QString &tableName)
{
    m_QueryExecutor.exec(selector.playlistSourcesSelectQuery(tableName));

    std::vector<QString> sources;

    while (m_QueryExecutor.next())
    {
        sources.emplace_back(m_QueryExecutor.value(0).toString());
    }

    return sources;
}

bool DBManager::save(const PlaylistsManipulator &manipulator, const QString &tableName, const QString &data)
{
    QString createTableQuery = "CREATE TABLE IF NOT EXISTS " + tableName + " (source TEXT)";

    m_QueryExecutor.exec(createTableQuery);

    return m_QueryExecutor.exec(manipulator.playlistSourcesInsertQuery(tableName, data));
}

bool DBManager::isOpen() const
{
    return m_isOpen;
}

QStringList DBManager::tables() const
{
    return m_Db.tables();
}
