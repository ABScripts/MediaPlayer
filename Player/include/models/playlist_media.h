#ifndef PLAYLISTMEDIA_H
#define PLAYLISTMEDIA_H
#include "include/models/media_source.h"
#include "include/models/media_storage.h"

class PlaylistElement;

class PlaylistMedia : public MediaSourceListModel {       // consider adapting that model to library
    Q_OBJECT

    enum LibraryRoles {
        TitleRole = Qt::UserRole + 1,
        GenreRole,
        ReleaseDateRole
    };

public:
    PlaylistMedia(MediaStorage *mediaStorage, QObject *parent = nullptr);

    void setPlaylist(PlaylistElement *playlistElement);

    void addMediaToPlaylist(int storageMediaIndex);
    void deleteMediaFromPlaylisit(int index);

    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QHash<int, QByteArray> roleNames() const;

private:
    void setMockData();

private:
    bool isPlaylistValid(PlaylistElement *playlistElement) const;
    bool isPlaylistMediafileIndexValid(int index) const;

    // MediaSourceListModel interface
private:
    void setPlaylistElement(PlaylistElement *playlistElement);

    QString getNextMediaFile(int &index) const;
    QString getPreviousMediaFile(int &index) const;
    QString getMediaFileByIndex(int &index) const;
    QString getCurrentMediaFileTitle() const;

private:
    PlaylistElement *m_Playlist;
    MediaStorage *m_MediaStorage;

signals:
    void playlistEmpty();
};

#endif
