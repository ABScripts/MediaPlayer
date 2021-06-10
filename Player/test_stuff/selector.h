#ifndef SELECTOR_H
#define SELECTOR_H

#include <vector>
#include <QString>

class PlaylistsSelector
{
public:
    QString playlistSourcesSelectQuery(const QString &tableName) const;
};

#endif // SELECTOR_H
