#ifndef MEDIAPLAYERCONTROLLER_H
#define MEDIAPLAYERCONTROLLER_H
#include <QObject>

#include "include/mediaplayer_enums.h"

class Library;
class MediaPlayer;

class MediaPlayerController : public QObject {
    Q_OBJECT

public:
    MediaPlayerController(MediaPlayer &mediaPlayer, QObject *parent = nullptr);

private:
    void manageMediaFileSetterSignal(const QString &mediaFileSource);

private:
    MediaPlayer &m_MediaPlayer;
    PlayerStatus m_PlayerStatus;
    bool m_IsSeeking;

public slots:
    void getNextMedia(void);
    void getPreviousMedia(void);
    void setAutoMedia(void);
    void changeStatus(int status);
    void changePlayerMode(int mode);
    void seek(double position);

signals:
    void paused(void);
    void playing(void);
    void stopped(void);
    void videoModeSet(void);
    void audioModeSet(void);
    void repeatModeSet(void);
    void sequenceModeSet(void);
    void durationChanged(void);
    void positionChanged(void);
};

#endif
