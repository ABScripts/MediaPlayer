#ifndef MANIPULATOR_H
#define MANIPULATOR_H

#include <vector>
#include <QString>

class PlaylistsManipulator
{
public:
    QString playlistSourcesInsertQuery(const QString &tableName, const QString &source) const;
};

#endif // MANIPULATOR_H
