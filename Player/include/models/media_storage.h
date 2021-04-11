#ifndef MEDIASTORAGE_H
#define MEDIASTORAGE_H

#include <vector>
#include <mutex>
#include <QObject>

#include "include/composition.h"
#include "include/fileseeker_manager.h"

class MediaStorage : public QObject {    // create singltone ?
    Q_OBJECT

public:
    MediaStorage(const MediaStorage &other) = delete;

    MediaStorage &operator=(const MediaStorage &other) = delete;

    static MediaStorage *getInstanse();
    void setupMediaStorage();
    Composition getMediafileByIndex(int index) const;
    int size() const;

private:
    MediaStorage();

    void indexMediaStorage();
    bool isMediafileIndexValid(int index) const;

private:
    static MediaStorage *m_Instance;
    static std::mutex m_Mutex;
    std::vector<Composition> m_MediaFiles;
    std::vector<std::string> m_SupportedFilesExtensions;

signals:
    void beginInsertNewMediafiles(int indexBegin, int indexEnd);
    void endInsertNewMediafiles();
};

#endif
