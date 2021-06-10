#ifndef MEDIASOURCEROUTER_H
#define MEDIASOURCEROUTER_H
#include "include/controllers/media_section_controller.h"
#include "include/mediaplayer_enums.h"
#include "include/models/media_source.h"

class MediaSourceRouter {
    using MediaSource = MediaPlayerEnums::SectionTabs;

public:
    MediaSourceRouter(std::map<MediaSource, MediaSourceListModel *> mediaSources);

    QString getNextMediaFile(int &index) const;
    QString getPreviousMediaFile(int &index) const;
    QString getMediaFileByIndex(int &index) const;
    QString getCurrentMediaFileTitle(void) const;
    int getCurrentSelectedIndex() const;


    void changeMediaSource(MediaSource newMediaSource);

private:
    std::map<MediaSource, MediaSourceListModel *> m_MediaSource;
    MediaSource m_MediaSourceType;
};

#endif
