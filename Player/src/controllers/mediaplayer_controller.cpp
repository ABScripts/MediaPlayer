#include "include/controllers/mediaplayer_controller.h"
#include "include/models/mediaplayer.h"

#include <QDebug>

MediaPlayerController::MediaPlayerController(MediaPlayer &mediaPlayer, QObject *parent)
    : QObject {parent}
    , m_MediaPlayer {mediaPlayer}
{
    connect(&m_MediaPlayer, &MediaPlayer::durationChanged, this, &MediaPlayerController::durationChanged);
    connect(&m_MediaPlayer, &MediaPlayer::positionChanged, this, &MediaPlayerController::positionChanged);
}

void MediaPlayerController::getNextMediaFile()
{
    m_MediaPlayer.setNextMediaFile();
}

void MediaPlayerController::getPreviousMediaFile()
{
    m_MediaPlayer.setPreviousMediaFile();
}

void MediaPlayerController::setNewSong(void)
{
    m_MediaPlayer.setNewMediaFile();
}

void MediaPlayerController::changeStatus(int status)
{
    if (status == PlayerStatus::SwitchPlay)
    {
        switch (m_PlayerStatus) {
            case PlayerStatus::Playing:
                status = PlayerStatus::Paused;
                break;

            case PlayerStatus::Stopped:
            case PlayerStatus::Paused:
            case PlayerStatus::None:
                status = PlayerStatus::Playing;
                break;
        }
    }

    switch (status) {
        case PlayerStatus::Playing:
            m_MediaPlayer.play();
            emit playing();
            break;

        case PlayerStatus::Paused:
            m_MediaPlayer.pause();
            emit paused();
            break;

        case PlayerStatus::Stopped:
            m_MediaPlayer.stop();
            emit stopped();
            break;

        default:
            break;
    }

    m_PlayerStatus = static_cast<PlayerStatus>(status);
}

void MediaPlayerController::changePlayerMode(int mode)
{
    PlayerMode playerMode = m_MediaPlayer.getPlayerMode();

    switch (playerMode) {
        case PlayerMode::Repeat:
            mode = PlayerMode::Sequence;
            emit sequenceMode();
            break;

        case PlayerMode::Sequence:
            mode = PlayerMode::Repeat;
            emit repeatMode();
            break;

        default:
            break;
    }

    m_MediaPlayer.setNewMode(static_cast<PlayerMode>(mode));
}

void MediaPlayerController::seek(double position)
{
    m_IsSeeking = !m_IsSeeking;

    if (!m_IsSeeking)
    {
        m_MediaPlayer.seek(position);
        m_MediaPlayer.play();
    }
    else
    {
        m_MediaPlayer.stop();
    }
}
