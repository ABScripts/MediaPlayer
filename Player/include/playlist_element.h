#ifndef PLAYLISTSELEMENT_H
#define PLAYLISTSELEMENT_H
#include <QString>
#include <vector>

#include <include/composition.h>

class MediaStorage;

class PlaylistElement {
    //using MediaFile = std::vector<Composition>::iterator;

public:
    PlaylistElement(QString playlistName = "");

    void addMediafile(int storageMediafileIndex);
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
