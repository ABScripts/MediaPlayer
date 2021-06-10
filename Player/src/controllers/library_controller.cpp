#include "include/controllers/library_controller.h"

#include "include/models/library.h"

LibraryController::LibraryController(Library *library, QObject *parent)
    : QObject(parent)
    , m_Library {library}
{
    connect(m_Library, &Library::mediaLoaded, this, &LibraryController::checkLibraryLoadForErrors);
}

void LibraryController::checkLibraryLoadForErrors()
{
    if (m_Library->isEmpty())
    {
        emit noMediaLoaded();
    } else
    {
        emit mediaLoadedSuccesfully();
    }
}
