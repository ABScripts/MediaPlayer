#ifndef MEDIAPLAYER
#define MEDIAPLAYER
#include <QObject>
#include <QDebug>
#include <QMediaPlayer>

#include "include/mediaplayer_enums.h"

class MediaSourceRouter;
class Library;

class MediaPlayer : public QObject {
public:
    Q_OBJECT

    Q_PROPERTY(QString currentMediaFileTitle
               MEMBER m_CurrentMediaFileTitle
               NOTIFY currentMediaFileTitleChanged)

    Q_PROPERTY(qreal position
               READ getPosition
               WRITE setPosition
               NOTIFY positionChanged)

    Q_PROPERTY(qreal duration
               READ getDuration
               NOTIFY durationChanged)

    using PlayerMode = MediaPlayerEnums::PlayerMode;

public:
    MediaPlayer(MediaSourceRouter &mediaSourceRouter, QObject *parent = nullptr);

    void setNewMediaFile();
    void setNewMediaFileByIndex(int index);
    void setNextMediaFile();
    void setPreviousMediaFile();
    void setNewMode(PlayerMode mode);
    PlayerMode getPlayerMode() const;

    void play();
    void pause();
    void stop();
    void seek(double position);

private:
    bool isMediaFileSourceValid(const QString &mediaFileSource) const;
    void updateCurrentMediaFileSource(const QString &mediaFileSource);

    double getPosition() const;
    double getDuration() const;

    void setPosition(double position);

private:
    PlayerMode m_Mode;
    MediaSourceRouter &m_MediaSourceRouter;
    //Library &m_MediaLibrary;
    QMediaPlayer m_MediaPlayer;
    int m_CurrentMediaFileIndex;
    bool m_IsRepeatOptionEnabled;
    QString m_CurrentMediaFileTitle;

private slots:
    void mediaStatusChangedSlot();

signals:
    void durationChanged();
    void positionChanged();
    void currentMediaFileTitleChanged();
};

#endif

