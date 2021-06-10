#include "include/playlist_element.h"

#include "include/models/media_storage.h"

PlaylistElement::PlaylistElement(QString playlistName)
    : m_Name(playlistName)
{

}

bool PlaylistElement::addMediafile(int storageMediafileIndex)
{
    if (!isInPlaylist(storageMediafileIndex))
    {
        m_MediafileIndexes.push_back(storageMediafileIndex);
        return true;
    }
    return false;
}

void PlaylistElement::deleteMediafile(int index)
{
    if (isIndexValid(index))
    {
        m_MediafileIndexes.erase(m_MediafileIndexes.begin() + index);
    }
}

Composition PlaylistElement::getMediafile(int index) const
{
    if (isIndexValid(index))
    {
        return m_MediaStorage->getMediafileByIndex( m_MediafileIndexes[index] );
    }
    return {};
}

void PlaylistElement::setMediaStorage(MediaStorage *mediaStorage)
{
    m_MediaStorage = mediaStorage;
}

int PlaylistElement::size() const
{
    return m_MediafileIndexes.size();
}

QString PlaylistElement::name() const
{
    return m_Name;
}

int PlaylistElement::isEmpty() const
{
    return (size() == 0);
}

bool PlaylistElement::isInPlaylist(int index) const
{
    return (std::find(m_MediafileIndexes.begin(), m_MediafileIndexes.end(), index) !=
                m_MediafileIndexes.end());
}

bool PlaylistElement::isIndexValid(int index) const
{
   return (index >= 0 && index < static_cast<int>(size()));
}
