#include <QObject>

class MediaStorage;

class MediaLoaderController : public QObject {
    Q_OBJECT

public:
    MediaLoaderController(MediaStorage *mediaStorage, QObject *parent = nullptr);

private:
    bool isMediaStorageValid() const;

private:
    MediaStorage *m_MediaStorage;

public slots:
    void onFileLoaded(const QString &source);

};
