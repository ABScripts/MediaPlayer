#ifndef MEDIASOURCE_H
#define MEDIASOURCE_H
#include <QAbstractListModel>

#include "include/models/media_player.h"

class MediaSourceListModel : public QAbstractListModel {
    Q_OBJECT

    Q_PROPERTY(int  currentSelectedIndex
               READ getCurrentSelectedIndex
               WRITE setCurrentSelectedIndex
               NOTIFY currentSelectedIndexChanged)
public:
    MediaSourceListModel(QObject *parent = nullptr);

public:
    virtual QString getNextMediaFile(int &index) const = 0;
    virtual QString getPreviousMediaFile(int &index) const = 0;
    virtual QString getMediaFileByIndex(int &index) const = 0;
    virtual QString getCurrentMediaFileTitle(void) const = 0;

private:
    int m_CurrentSelectedIndex = 0;

signals:
    void currentSelectedIndexChanged();

public slots:
    int getCurrentSelectedIndex() const;
    void setCurrentSelectedIndex(int index);

    friend MediaPlayer;
};

#endif
