#include "manipulator.h"

QString PlaylistsManipulator::playlistSourcesInsertQuery(const QString &tableName, const QString &source) const
{
    QString insertQuery = "INSERT INTO" + tableName + " (source, id) VALUES";

    insertQuery += " (\"" + source + "\"),";

    insertQuery[insertQuery.size() - 1] = ';'; // change last comma to ';'

    return insertQuery;
}
