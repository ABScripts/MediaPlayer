#include "selector.h"

QString PlaylistsSelector::playlistSourcesSelectQuery(const QString &tableName) const
{
    return "SELECT source, id from " + tableName;
}
