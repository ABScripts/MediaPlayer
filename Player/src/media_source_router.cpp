#include "include/media_source_router.h"

MediaSourceRouter::MediaSourceRouter(std::map<MediaSourceRouter::MediaSource, MediaSourceListModel *> mediaSources)
    : m_MediaSource(mediaSources)
    , m_MediaSourceType { MediaPlayerEnums::Library }
{

}

QString MediaSourceRouter::getNextMediaFile(int &index) const
{
    return m_MediaSource.at(m_MediaSourceType)->getNextMediaFile(index);
}

QString MediaSourceRouter::getPreviousMediaFile(int &index) const
{
    return m_MediaSource.at(m_MediaSourceType)->getPreviousMediaFile(index);
}

QString MediaSourceRouter::getMediaFileByIndex(int &index) const
{
    return m_MediaSource.at(m_MediaSourceType)->getMediaFileByIndex(index);
}

QString MediaSourceRouter::getCurrentMediaFileTitle() const
{
    return m_MediaSource.at(m_MediaSourceType)->getCurrentMediaFileTitle();
}

int MediaSourceRouter::getCurrentSelectedIndex() const
{
    return m_MediaSource.at(m_MediaSourceType)->getCurrentSelectedIndex();
}

void MediaSourceRouter::changeMediaSource(MediaSourceRouter::MediaSource newMediaSource)
{
    m_MediaSourceType = newMediaSource;
}
