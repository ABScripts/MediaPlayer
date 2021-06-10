#ifndef PLAYLISTSELEMENT_H
#define PLAYLISTSELEMENT_H
#include <QString>

#include <include/composition.h>

class MediaStorage;

class PlaylistElement {
public:
    PlaylistElement(QString playlistName = "");

    bool addMediafile(int storageMediafileIndex);
    void deleteMediafile(int index);

    Composition getMediafile(int index) const;

    void setMediaStorage(MediaStorage *mediaStorage);

    int size() const;
    QString name() const;
    int isEmpty() const;
    bool isInPlaylist(int index) const;

private:
   bool isIndexValid(int index) const;

private:
    QString m_Name;
    std::vector<int> m_MediafileIndexes;
    MediaStorage *m_MediaStorage;
};

#endif
