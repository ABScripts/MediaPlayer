#ifndef MEDIAPLAYER
#define MEDIAPLAYER

#include <QMediaPlayer>

#include "include/video_surface.h"
#include "include/mediaplayer_enums.h"

class MediaSourceRouter;
class Library;

class MediaPlayer : public QMediaPlayer {
public:
    Q_OBJECT

    Q_PROPERTY(QString mediaFileTitle // currentMediaTitle
               MEMBER m_CurrentMediaTitle
               NOTIFY mediaTitleChanged)

    Q_PROPERTY(qreal position
               READ getPosition
               WRITE setPosition
               NOTIFY positionChanged)

    Q_PROPERTY(qreal duration
               READ getDuration
               NOTIFY durationChanged)

    Q_PROPERTY(QAbstractVideoSurface* videoSurface
               READ getVideoSurface
               WRITE setVideoSurface)

public:
    MediaPlayer(MediaSourceRouter &mediaSourceRouter, QObject *parent = nullptr);

    void setAutoMedia();
    void setNextMedia();
    void setPreviousMedia();
    void setMediaByIndex(int index);
    void setMode(PlayerMode mode);
    PlayerMode getMode() const;

    void seek(double position);

    Q_INVOKABLE void setVideoSurface(QAbstractVideoSurface *surface); // to emphasize that these methods are used by qml not slots but Q_INVOKABLE is specified
    Q_INVOKABLE QAbstractVideoSurface *getVideoSurface() const;

private:
    bool isSourceValid(const QString &source) const;
    bool isSourceNewcoming(const QString &source) const;
    bool isVideotype(const QString &extension) const;

    double getPosition() const;
    double getDuration() const;
    void setPosition(double position);
    void setMedia(const QString &source);

    void updateMediaSource(const QString &source);
    void notifyControllerAboutMediaType(const QString &mediafilePath) const;

private:
    static std::vector<QString> m_supportedVideotypes; // not const as it could be dynamically extended

    int m_CurrentMediaIndex;
    QString m_CurrentMediaTitle;
    QString m_CurrentMediaSource;
    PlayerMode m_PlayerMode;

    MediaSourceRouter &m_MediaSourceRouter;
    QAbstractVideoSurface* m_VideoOutputSurface;

private slots:
    void mediaStatusChangedSlot();

signals:
    void durationChanged() const;
    void positionChanged() const;
    void videoTypePlaying() const;
    void audioTypePlaying() const;
    void mediaTitleChanged() const;
    void mediaStartPlaying(PlayerStatus) const;
};

#endif

