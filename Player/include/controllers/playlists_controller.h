#ifndef PLAYLISTSCONTROLLER_H
#define PLAYLISTSCONTROLLER_H

#include <QObject>

class Playlists;

class PlaylistController : public QObject {
    Q_OBJECT

public:
    PlaylistController(Playlists *playlists);
    void checkLibraryLoadForErrors();

private:
    Playlists *m_Playlists;
    int m_PlaylistSelectedIndex;

signals:
    void playlistsLoadedSuccessfully();
    void playlistEmpty();

    void playlistNameEmpty();
    void playlistNameTaken();
    void playlistNameConfirmed();

public slots:
    void addPlaylist(const QString &name);
};

#endif
