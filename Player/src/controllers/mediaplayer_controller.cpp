#include "include/controllers/mediaplayer_controller.h"
#include "include/models/media_player.h"

MediaPlayerController::MediaPlayerController(MediaPlayer &mediaPlayer, QObject *parent)
    : QObject {parent}
    , m_MediaPlayer  {mediaPlayer}
    , m_PlayerStatus {PlayerStatus::None}
    , m_IsSeeking    {false}
{
    connect(&m_MediaPlayer, &MediaPlayer::durationChanged, this, &MediaPlayerController::durationChanged);
    connect(&m_MediaPlayer, &MediaPlayer::positionChanged, this, &MediaPlayerController::positionChanged);
    connect(&m_MediaPlayer, &MediaPlayer::mediaStartPlaying, this, &MediaPlayerController::changeStatus);
    connect(&m_MediaPlayer, &MediaPlayer::videoTypePlaying, this, &MediaPlayerController::videoModeSet);
    connect(&m_MediaPlayer, &MediaPlayer::audioTypePlaying, this, &MediaPlayerController::audioModeSet);
}

void MediaPlayerController::getNextMedia()
{
    m_MediaPlayer.setNextMedia();
}

void MediaPlayerController::getPreviousMedia()
{
    m_MediaPlayer.setPreviousMedia();
}

void MediaPlayerController::setAutoMedia(void)
{
    m_MediaPlayer.setAutoMedia();
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
    PlayerMode playerMode = m_MediaPlayer.getMode();

    switch (playerMode) {
        case PlayerMode::Repeat:
            mode = PlayerMode::Sequence;
            emit sequenceModeSet();
            break;

        case PlayerMode::Sequence:
            mode = PlayerMode::Repeat;
            emit repeatModeSet();
            break;

        default:
            break;
    }

    m_MediaPlayer.setMode(static_cast<PlayerMode>(mode));
}

void MediaPlayerController::seek(double position)
{
    m_IsSeeking = !m_IsSeeking;

    if (!m_IsSeeking)
    {
        m_MediaPlayer.seek(position);

        if (m_PlayerStatus == PlayerStatus::Playing)
        {
            m_MediaPlayer.play();
        }
    }
    else
    {
        m_MediaPlayer.stop();
    }
}
