#include <QGuiApplication>
#include <QQuickView>
#include <QQmlContext>

// Other classes
#include "include/mediaplayer_enums.h"
#include "include/media_source_router.h"
#include "include/playlist_element.h"

// Controllers
#include "include/controllers/mediaplayer_controller.h"
#include "include/controllers/media_section_controller.h"
#include "include/controllers/media_section_controller.h"
#include "include/controllers/library_controller.h"
#include "include/controllers/media_loader_controller.h"
#include "include/controllers/playlists_controller.h"

// Models
#include "include/models/library.h"
#include "include/models/media_player.h"
#include "include/models/playlists.h"
#include "include/models/playlist_media.h"
#include "include/models/media_storage.h"
#include "include/models/media_source.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    QQuickView *mainView = new QQuickView;

    QQmlContext *mainQmlContext = mainView->rootContext();


    // setting ins-app stuff
    MediaStorage *mediaStorage = MediaStorage::getInstanse();

    Library library(mediaStorage);
    PlaylistMedia playlistMedia(mediaStorage);

    using Section = MediaPlayerEnums::SectionTabs;
    std::map<Section, MediaSourceListModel*> mediaSources;
    mediaSources[Section::Library] = &library;
    mediaSources[Section::Playlists] = &playlistMedia;

    MediaSourceRouter mediaSourceRouter(mediaSources);

    Playlists playlistsModel(mediaStorage, &playlistMedia);
    MediaPlayer mediaPlayer(mediaSourceRouter);

    LibraryController libraryController(&library);
    MediaPlayerController mediaController(mediaPlayer);
    MediaSectionController mediaSectionController(mediaSourceRouter);
    MediaLoaderController mediaLoaderController(mediaStorage);
    PlaylistController playlistController(&playlistsModel);

    mainQmlContext->setContextProperty("LibraryModel", &library);
    mainQmlContext->setContextProperty("LibraryController", &libraryController);
    mainQmlContext->setContextProperty("MediaPlayerModel", &mediaPlayer);
    mainQmlContext->setContextProperty("MediaController", &mediaController);
    mainQmlContext->setContextProperty("PlaylistsModel", &playlistsModel);
    mainQmlContext->setContextProperty("PlaylistMediaModel", &playlistMedia);
    mainQmlContext->setContextProperty("MediaSectionController", &mediaSectionController);
    mainQmlContext->setContextProperty("MediaLoaderController", &mediaLoaderController);
    mainQmlContext->setContextProperty("PlaylistController", &playlistController);

    qmlRegisterUncreatableType<MediaPlayerEnums>("MediaPlayerEnums",1,0,"MediaEnums","");

    const QUrl mainWindowUrl(QStringLiteral("qrc:/qml/main.qml"));
    const QUrl playlistMediaListViewUrl(QStringLiteral("qrc:/qml/playlistMediaView.qml"));

    mainView->setSource(playlistMediaListViewUrl);
    mainView->setSource(mainWindowUrl);

    mainView->setResizeMode(QQuickView::SizeRootObjectToView);

    mainView->show();

    return app.exec();
}
