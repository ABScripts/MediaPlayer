#include <QObject>

class Library;

class LibraryController : public QObject {
    Q_OBJECT

public:
    LibraryController(Library *library, QObject *parent = nullptr);

private:
    Library *m_Library;

    void checkLibraryLoadForErrors();

signals:
    void noMediaLoaded();
    void mediaLoadedSuccesfully();
};
