#ifndef PLAYLISTMANAGER_H
#define PLAYLISTMANAGER_H

#include "db_manager.h" // rename to db connection manager
#include "include/playlist_loader.h"
#include "include/playlist_saver.h"
#include "include/composition.h"

class MediaStorage;
class PlaylistElement;

class PlaylistManager {
public:
    PlaylistManager();
    std::vector<int> loadPlaylist(const QString &playlistName, const std::vector<Composition> &compositions) const;
    void savePlaylist(const QString &playlistName, const QString &source);
    void deleteMedia(const QString &playlistName, const QString &source);
    void deletePlaylist(const QString &name);
    std::vector<QString> getPlaylistNames() const;
    bool isDBAccessed() const;

private:
    const static QString playlistsDBPath;
    const static QString loaderConnectionName;
    const static QString saverConnectionName;

    PlaylistLoader m_PlaylistLoader;
    PlaylistSaver m_PlaylistSaver;
    MediaStorage *m_MediaStorage;
};

#endif
