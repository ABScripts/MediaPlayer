#ifndef MEDIASECTIONCONTROLLER_H
#define MEDIASECTIONCONTROLLER_H

#include "include/mediaplayer_enums.h"

#include <QObject>

class MediaSourceRouter;

class MediaSectionController : public QObject {
    Q_OBJECT

public:
    MediaSectionController(MediaSourceRouter &mediaSourceRouter);

private:
    MediaSourceRouter &m_MediaSourceRouter;

public slots:
    void changeSection(int sectionTab); // change to QInvokable
};

#endif
