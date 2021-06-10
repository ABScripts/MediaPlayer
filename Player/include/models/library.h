#ifndef LIBRARY_H
#define LIBRARY_H

#include "include/models/media_source.h"
#include "include/fileseeker_manager.h"
#include "include/composition.h"

class MediaPlayer;
class MediaStorage;

class Library : public MediaSourceListModel {
    Q_OBJECT

public:
    enum LibraryRoles {
        TitleRole = Qt::UserRole + 1,
        GenreRole,
        ReleaseDateRole
    };

    explicit Library(MediaStorage *mediaStorage, QObject *parent = nullptr);
    bool isMediafileIndexValid(int mediaFileIndex) const;
    bool isEmpty() const;
    int size() const;

public:         // QAbstractItemModel interface
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    void newMediaAboutToArrive();
    void newMediaArrived();

protected:
    QHash<int, QByteArray> roleNames() const override;

    // MediaSourceListModel interface
private:
    QString getNextMediaFile(int &mediFileIndex) const override;
    QString getPreviousMediaFile(int &mediaFileIndex) const override;
    QString getMediaFileByIndex(int &mediaFileIndex) const override;
    QString getCurrentMediaFileTitle(void) const override;

private:
    QString m_CurrentMediaFileTitle;
    Composition m_CurrentMediaFile;
    MediaStorage *m_MediaStorage;

signals:
    void mediaLoaded();
    void mediaArrived();

    friend MediaPlayer;
};

#endif
