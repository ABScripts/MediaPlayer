#ifndef MEDIAPLAYERCONTROLLER_H
#define MEDIAPLAYERCONTROLLER_H
#include <QObject>
#include <vector>

#include "include/composition.h"
#include "include/mediaplayer_enums.h"

class Library;
class MediaPlayer;

class MediaPlayerController : public QObject {
    Q_OBJECT

    using PlayerStatus = MediaPlayerEnums::PlayerStatus;
    using PlayerMode = MediaPlayerEnums::PlayerMode;

public:
    MediaPlayerController(MediaPlayer &mediaPlayer, QObject *parent = nullptr);

private:
    void manageMediaFileSetterSignal(const QString &mediaFileSource);

private:
    MediaPlayer &m_MediaPlayer;
    PlayerStatus m_PlayerStatus = PlayerStatus::None;
    bool m_IsSeeking = false;

public slots:
    void getNextMediaFile(void);
    void getPreviousMediaFile(void);
    void setNewSong(void);
    void changeStatus(int status);
    void changePlayerMode(int mode);
    void seek(double position);

signals:
    void paused(void);
    void playing(void);
    void stopped(void);
    void repeatMode(void);
    void sequenceMode(void);
    void shuffleMode(void);
    void shuffleModeDisabled(void);
    void durationChanged(void);
    void positionChanged(void);
};

#endif
