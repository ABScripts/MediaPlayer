QT += quick multimedia sql
CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/controllers/library_controller.cpp \
    src/controllers/media_loader_controller.cpp \
    src/db_manager.cpp \
    src/main.cpp \
    src/composition.cpp \                                       # Other classes
    src/fileseeker.cpp \
    src/fileseeker_manager.cpp \
    src/media_source_router.cpp \
    src/mediaplayer_enums.cpp \
    src/models/media_player.cpp \
    src/models/media_source.cpp \
    src/models/media_storage.cpp \
    src/playlist_element.cpp \
    src/controllers/media_section_controller.cpp \              # Controllers
    src/controllers/mediaplayer_controller.cpp \
    src/controllers/playlist_media_controller.cpp \
    src/controllers/playlists_controller.cpp \
    src/models/library.cpp \                                    # Models
    src/models/playlist_media.cpp \
    src/models/playlists.cpp \
    src/playlist_loader.cpp \
    src/playlist_manager.cpp \
    src/playlist_saver.cpp \
    src/video_surface.cpp


RESOURCES += \
        qml/icons.qrc \
        qml/main.qml \
        qml/playlistMediaView.qml


# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    include/composition.h \                                     # Other classes
    include/controllers/library_controller.h \
    include/controllers/media_loader_controller.h \
    include/db_manager.h \
    include/fileseeker.h \
    include/fileseeker_manager.h \
    include/media_source_router.h \
    include/mediaplayer_enums.h \
    include/models/media_player.h \
    include/models/media_source.h \
    include/models/media_storage.h \
    include/playlist_element.h \
    include/controllers/media_section_controller.h \            # Controllers
    include/controllers/mediaplayer_controller.h \
    include/controllers/playlist_media_controller.h \
    include/controllers/playlists_controller.h \
    include/models/library.h \                                  # Models
    include/models/playlist_media.h \
    include/models/playlists.h \
    include/playlist_loader.h \
    include/playlist_manager.h \
    include/playlist_saver.h \
    include/video_surface.h


DISTFILES +=
