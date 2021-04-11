#include "include/models/mediaplayer.h"
#include "include/models/library.h"

#include "include/media_source_router.h"

#include <QDebug>

MediaPlayer::MediaPlayer(MediaSourceRouter &mediaSourceRouter, QObject *parent)
    : QObject(parent)
    , m_Mode(PlayerMode::Sequence)
    , m_MediaSourceRouter {mediaSourceRouter}
    , m_CurrentMediaFileIndex {0}
    , m_IsRepeatOptionEnabled { false }
{
    connect(&m_MediaPlayer, &QMediaPlayer::mediaStatusChanged, this, &MediaPlayer::mediaStatusChangedSlot);
    connect(&m_MediaPlayer, &QMediaPlayer::positionChanged, this, &MediaPlayer::positionChanged);
    connect(&m_MediaPlayer, &QMediaPlayer::durationChanged, this, &MediaPlayer::durationChanged);
}

void MediaPlayer::setNextMediaFile()
{
    QString mediaFileSource = m_MediaSourceRouter.getNextMediaFile(m_CurrentMediaFileIndex);//m_MediaLibrary.getNextMediaFile(m_CurrentMediaFileIndex); // switch to mediaSourceManager

    updateCurrentMediaFileSource(mediaFileSource);
}

void MediaPlayer::setPreviousMediaFile()
{
    QString mediaFileSource = m_MediaSourceRouter.getPreviousMediaFile(m_CurrentMediaFileIndex);//m_MediaLibrary.getPreviousMediaFile(m_CurrentMediaFileIndex);

    updateCurrentMediaFileSource(mediaFileSource);
}

void MediaPlayer::setNewMediaFile()
{
    m_CurrentMediaFileIndex = m_MediaSourceRouter.getCurrentSelectedIndex();//m_MediaLibrary.getCurrentSelectedIndex();

    setNewMediaFileByIndex(m_CurrentMediaFileIndex);
}

void MediaPlayer::setNewMediaFileByIndex(int index)
{
    QString newMediaFileSource = m_MediaSourceRouter.getMediaFileByIndex(index);//m_MediaLibrary.getMediaFileByIndex(index);
    qDebug() << newMediaFileSource;
    updateCurrentMediaFileSource( newMediaFileSource );
}

void MediaPlayer::mediaStatusChangedSlot()
{
    if (m_MediaPlayer.mediaStatus() == QMediaPlayer::EndOfMedia)
    {
        if (m_Mode == PlayerMode::Repeat)
        {
            m_MediaPlayer.play();
        }
        else if (m_Mode == PlayerMode::Sequence)
        {
            setNextMediaFile();
        }
    }
}

void MediaPlayer::updateCurrentMediaFileSource(const QString &mediaFileSource)
{
    if (isMediaFileSourceValid(mediaFileSource) &&
            m_CurrentMediaFileIndex != mediaFileSource) {
        m_MediaPlayer.setMedia(QUrl::fromLocalFile( mediaFileSource ));

        //m_CurrentMediaFileTitle = m_MediaSourceRouter.getCurrentMediaFileTitle();//m_MediaLibrary.getCurrentMediaFileTitle();
       // emit currentMediaFileTitleChanged();
    }
    play();
}

void MediaPlayer::play()
{
    m_MediaPlayer.play();
}

void MediaPlayer::pause()
{
    m_MediaPlayer.pause();
}

void MediaPlayer::stop()
{
    m_MediaPlayer.stop();
}

void MediaPlayer::seek(double position)
{
    setPosition(position);
}

void MediaPlayer::setNewMode(MediaPlayer::PlayerMode mode)
{
    m_Mode = mode;
}

void MediaPlayer::setPosition(double position)
{
    if (m_MediaPlayer.isSeekable())
    {
        m_MediaPlayer.setPosition(position);
        emit positionChanged();
    }
}

double MediaPlayer::getPosition() const
{
    return static_cast<double>(m_MediaPlayer.position());
}

double MediaPlayer::getDuration() const
{
    return m_MediaPlayer.duration();
}

bool MediaPlayer::isMediaFileSourceValid(const QString &mediaFileSource) const
{
    return (mediaFileSource.size() != 0);
}

MediaPlayerEnums::PlayerMode MediaPlayer::getPlayerMode() const
{
    return m_Mode;
}
