#ifndef MEDIAPLAYERENUMS_H
#define MEDIAPLAYERENUMS_H

#include <QObject>

class MediaPlayerEnums : public QObject {
    Q_OBJECT

public:
    enum PlayerStatus {
        None = 0,
        SwitchPlay, // special helper status to switch between Playing/Paused states
        Playing,
        Paused,
        Stopped
    };

    enum PlayerMode {
        SwitchMode = 0,
        Sequence,
        Repeat,
        Shuffle
    };

    enum SectionTabs {       // should be in a different class
        Library = 0,
        Playlists
    };

    Q_ENUM(PlayerStatus)
    Q_ENUM(PlayerMode)
    Q_ENUM(SectionTabs)
};

#endif
