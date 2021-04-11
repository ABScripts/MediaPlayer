#ifndef PLAYLISTS_h
#define PLAYLISTS_h
#include "QAbstractListModel"

#include <vector>

#include "include/playlist_manager.h"
#include "include/playlist_element.h"

class PlaylistMedia;

class Playlists : public QAbstractListModel {
    Q_OBJECT

    Q_PROPERTY(int cirrentSelectedIndex
               MEMBER  m_CurrentSelectedIndex
               NOTIFY  currentSelectedIndexChanged)

    enum Roles {
        Name = Qt::UserRole + 1,
        MediaFilesCount
    };

public:
    Playlists(PlaylistMedia *playlistMedia, QObject *parent = nullptr);

    // QAbstractItemModel interface
public:
    QHash<int, QByteArray> roleNames() const;
    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;

    Q_INVOKABLE void add(QString name);
    void remove(int index);

    Q_INVOKABLE void addMediaToPlaylist(int mediafileIndex, QString playlistName);
    Q_INVOKABLE void deleteMediaFromPLaylist(int mediafileIndex);
    Q_INVOKABLE void setPlaylistMedia(int index);

private:
    bool isIndexValid(int index) const;
    bool isNameTaken(const QString &name) const;

    void setMockData();

private:
    PlaylistManager m_PlaylistManager;
    std::vector<QString> m_PlaylistsNames;
    std::map<QString, PlaylistElement> m_Playlists;
    PlaylistMedia *m_PlaylistMedia;


    // test area
    int m_CurrentSelectedIndex;

signals:
    void currentSelectedIndexChanged();
    void nameAlreadyTaken();
    void mediafileAddedSuccesfully();

//public slots:
//    void deletePlaylist();
};

#endif
