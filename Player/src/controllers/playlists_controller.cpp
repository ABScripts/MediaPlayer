#include "include/controllers/playlists_controller.h"

#include "include/models/playlists.h"

PlaylistController::PlaylistController(Playlists *playlists)
    : m_Playlists(playlists)
{
    connect(m_Playlists, &Playlists::playlistsLoaded, this, &PlaylistController::checkLibraryLoadForErrors);
}

void PlaylistController::checkLibraryLoadForErrors()
{
    if (m_Playlists->size() == 0)
    {
        emit playlistEmpty();
    } else
    {
        emit playlistsLoadedSuccessfully();
    }
}

void PlaylistController::addPlaylist(const QString &name)
{
    if (name.isEmpty())
    {
        emit playlistNameEmpty();
    } else if (m_Playlists->isNameTaken(name))
    {
        emit playlistNameTaken();
    } else
    {
        m_Playlists->add(name);
        emit playlistNameConfirmed();
    }
}
