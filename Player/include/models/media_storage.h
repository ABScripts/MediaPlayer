#ifndef MEDIASTORAGE_H
#define MEDIASTORAGE_H

#include <vector>
#include <mutex>
#include <QObject>
#include <QModelIndex>
#include <QDebug>

#include "include/composition.h"
#include "include/fileseeker_manager.h"

namespace std {
    class thread;
}

class MediaStorage : public QObject {    // create singltone ?
    Q_OBJECT

public:
    static MediaStorage *getInstanse();
    ~MediaStorage();

    void addMedia(const QString &mediaSource);
    Composition getMediafileByIndex(int index) const;
    int size() const;
    void setupMediaStorage();

    MediaStorage(const MediaStorage &other) = delete;
    MediaStorage &operator=(const MediaStorage &other) = delete;

    const std::vector<Composition> &getMediaFiles() const;

private:
    MediaStorage();

    void indexMediaStorage();
    bool isMediafileIndexValid(int index) const;

private:
    static MediaStorage *m_Instance;
    static std::mutex m_Mutex;
    std::vector<Composition> m_MediaFiles;
    QStringList m_SupportedFilesExtensions;
    std::thread *m_WorkingThread;

signals:
    void beginInsertMedia();
    void endInsertMedia();
    void mediaLoaded();
};

#endif
