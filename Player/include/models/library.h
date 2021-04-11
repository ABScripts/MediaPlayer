#ifndef LIBRARY_H
#define LIBRARY_H

#include "include/models/media_source.h"
#include "include/fileseeker_manager.h"
#include "include/composition.h"

#include <thread>

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
    //void addComposition(QString source, QString title, QString genre, QDate releaseDate);
    bool isMediafileIndexValid(int mediaFileIndex) const;
    //void indexMediaFiles();
    int size() const;
    //std::thread indexMedia();

public:         // QAbstractItemModel interface
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

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
    //std::vector<Composition> m_MediaFiles;
    //std::vector<std::string> m_SupportedFileExtensions;
    Composition m_CurrentMediaFile;

    MediaStorage *m_MediaStorage;

    friend MediaPlayer;
};

#endif
