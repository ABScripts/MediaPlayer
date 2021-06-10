import QtQuick 2.15
import QtQuick.Window 2.15

import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12
import QtQuick.Window 2.0
import QtMultimedia 5.0

import MediaPlayerEnums 1.0                 // Custom imports


ListView {
    id: _playlistMedia

    model:  PlaylistMediaModel

    delegate: Text {
        id: _mediaFileDelegate

        width: _playlistMedia.width
        height: _mediaFileInfo.implicitHeight

        Item {
            id: _compositionInfoWrap

            width: parent.width - _additionalCompositionRelatedControls.width
            height: parent.height

            RowLayout {
                anchors.fill: parent

                ColumnLayout {
                    id: _mediaFileInfo;

                    Layout.alignment: Qt.AlignLeft

                    Text {
                        font.pointSize: 18
                        text: model.title
                    }
                    Text {
                        font.pointSize: 14
                        text: model.genre
                    }
                }

                Text {
                    font.pointSize: 12
                    text: model.releaseDate

                    Layout.alignment: Qt.AlignRight
                }
            }

            MouseArea {
                anchors.fill: parent

                onClicked: {
                    _playlistMedia.model.currentSelectedIndex = model.index

                     MediaSectionController.changeSection(MediaEnums.Playlists)

                     MediaController.setAutoMedia()
                }
            }
        }

        Item {
            id: _additionalCompositionRelatedControls

            width: _deleteFromPlaylistButton.implicitWidth
            height: _deleteFromPlaylistButton.implicitHeight

            anchors.right: _mediaFileDelegate.right

            visible: false

            RoundButton {
                id: _deleteFromPlaylistButton

                icon.source: "qrc:/trash.png"
                icon.width: 32
                icon.height: 32

                MouseArea {

                anchors.fill: parent

                    onClicked: {
                        PlaylistsModel.deleteMediaFromPLaylist(model.index)
                    }
                }
            }
        }

        MouseArea {
            anchors.fill: parent
            hoverEnabled: true

            propagateComposedEvents: true

            onHoveredChanged: {
                _additionalCompositionRelatedControls.visible = this.containsMouse
            }
        }
    }
}
