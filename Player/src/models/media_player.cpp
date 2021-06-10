#include "include/models/media_player.h"
#include "include/models/library.h"

#include "include/media_source_router.h"

#include <QFileInfo>

std::vector<QString> MediaPlayer::m_supportedVideotypes = {"avi", "mp4"};

MediaPlayer::MediaPlayer(MediaSourceRouter &mediaSourceRouter, QObject *parent)
    : QMediaPlayer(parent)
    , m_CurrentMediaIndex {0}
    , m_PlayerMode        { PlayerMode::Sequence }
    , m_MediaSourceRouter {mediaSourceRouter}
{
    connect(this, &QMediaPlayer::mediaStatusChanged, this, &MediaPlayer::mediaStatusChangedSlot);
    connect(this, &QMediaPlayer::positionChanged, this, &MediaPlayer::positionChanged);
    connect(this, &QMediaPlayer::durationChanged, this, &MediaPlayer::durationChanged);

    setVideoSurface(new class VideoSurface);
}

void MediaPlayer::setNextMedia()
{
    QString mediaSource = m_MediaSourceRouter.getNextMediaFile(m_CurrentMediaIndex);

    updateMediaSource(mediaSource);
}

void MediaPlayer::setPreviousMedia()
{
    QString mediaSource = m_MediaSourceRouter.getPreviousMediaFile(m_CurrentMediaIndex);

    updateMediaSource(mediaSource);
}

void MediaPlayer::setAutoMedia()
{
    m_CurrentMediaIndex = m_MediaSourceRouter.getCurrentSelectedIndex();

    setMediaByIndex(m_CurrentMediaIndex);
}

void MediaPlayer::setMediaByIndex(int index)
{
    QString mediaSource = m_MediaSourceRouter.getMediaFileByIndex(index);

    updateMediaSource(mediaSource );
}

void MediaPlayer::mediaStatusChangedSlot()
{
    if (mediaStatus() == QMediaPlayer::EndOfMedia)
    {
        if (m_PlayerMode == PlayerMode::Repeat)
        {
            emit mediaStartPlaying(PlayerStatus::Playing);
        }
        else if (m_PlayerMode == PlayerMode::Sequence)
        {
            setNextMedia();
        }
    }
}

void MediaPlayer::updateMediaSource(const QString &source)
{
    if (isSourceValid(source) && isSourceNewcoming(source))
    {
        setMedia(source);

        emit mediaStartPlaying(MediaPlayerEnums::PlayerStatus::Playing);
    }
}

void MediaPlayer::notifyControllerAboutMediaType(const QString &mediafilePath) const
{
    QString fileExtension = QFileInfo(mediafilePath).suffix();

    emit (isVideotype(fileExtension) ? videoTypePlaying() : audioTypePlaying());
}

void MediaPlayer::setMedia(const QString &source)
{
    m_CurrentMediaSource = source;
    QMediaPlayer::setMedia(QUrl::fromLocalFile( source ));

    notifyControllerAboutMediaType(source);
}

void MediaPlayer::seek(double position)
{
    setPosition(position);
}

bool MediaPlayer::isVideotype(const QString &extension) const
{
    auto begin = m_supportedVideotypes.begin(),
         end  = m_supportedVideotypes.end();

    return std::find(begin, end, extension) != end;
}

bool MediaPlayer::isSourceValid(const QString &mediaFileSource) const
{
    return (mediaFileSource.size() != 0);
}

bool MediaPlayer::isSourceNewcoming(const QString &source) const
{
    return m_CurrentMediaSource != source;
}

double MediaPlayer::getDuration() const
{
    return duration();
}

double MediaPlayer::getPosition() const
{
    return static_cast<double>(position());
}

void MediaPlayer::setPosition(double position)
{
    if (isSeekable())
    {
        QMediaPlayer::setPosition(position);
        emit positionChanged();
    }
}

QAbstractVideoSurface *MediaPlayer::getVideoSurface() const
{
    return m_VideoOutputSurface;
}

void MediaPlayer::setVideoSurface(QAbstractVideoSurface *surface)
{
    m_VideoOutputSurface = surface;
    setVideoOutput(m_VideoOutputSurface);
}

MediaPlayerEnums::PlayerMode MediaPlayer::getMode() const
{
    return m_PlayerMode;
}

void MediaPlayer::setMode(PlayerMode mode)
{
    m_PlayerMode = mode;
}
