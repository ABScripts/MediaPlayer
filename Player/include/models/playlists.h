#ifndef PLAYLISTS_h
#define PLAYLISTS_h
#include "QAbstractListModel"

#include <vector>
#include <thread>

#include "include/playlist_element.h"
#include "include/playlist_manager.h"

class PlaylistMedia;

class Playlists : public QAbstractListModel {
    Q_OBJECT

    Q_PROPERTY(int selectedLibraryIndex
               MEMBER  m_SelectedLibraryIndex
               WRITE setSelectedLibraryIndex)

    enum Roles {
        Name = Qt::UserRole + 1,
        MediaFilesCount
    };

public:
    Playlists(MediaStorage *mediaStorage, PlaylistMedia *playlistMedia, QObject *parent = nullptr);
    ~Playlists();

    // QAbstractItemModel interface
public:
    QHash<int, QByteArray> roleNames() const;
    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;

    Q_INVOKABLE void add(QString name);
    void remove(int index);

    Q_INVOKABLE void addMediaToPlaylist(int mediafileIndex, QString playlistName);
    Q_INVOKABLE void addMediaToPlaylist(QString playlistName);
    Q_INVOKABLE void deleteMediaFromPLaylist(int mediafileIndex);
    Q_INVOKABLE void setPlaylistMedia(int index);
    Q_INVOKABLE int size() const;

    void setSelectedLibraryIndex(int SelectedLibraryIndex);
    bool isNameTaken(const QString &name) const;
    bool isIndexValid(int index) const;

private:
    std::vector<QString> m_PlaylistsNames;
    std::map<QString, PlaylistElement> m_Playlists;
    PlaylistMedia *m_PlaylistMedia;
    PlaylistManager m_PlaylistManager;
    MediaStorage *m_MediaStorage;
    std::thread m_WorkingThread;
    int m_SelectedLibraryIndex;
    int m_SelectedPlaylistIndex;

private slots:
    void loadPlaylists();
    void loadPlaylistWorkThread();
    void deletePlaylist(QString name);

signals:
    void selectedLibraryIndexChanged();
    void nameAlreadyTaken();
    void playlistAddedSuccesfully();
    void playlistsLoaded();
};

#endif

