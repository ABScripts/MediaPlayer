import QtQuick 2.15
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.15 as NControls
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4

import MediaPlayerEnums 1.0                 // Custom imports

Rectangle {
    id: _mainWindow
    width: 1280
    height: 720
    color: "#dfe4ea"

    RowLayout {
        anchors.fill: parent

        anchors {
            property real margin: Math.min(parent.height, parent.width) * 0.03
            margins: margin
        }

        Rectangle {
            id: _playableArea
            color: "#dfe4ea"

            width: parent.width - _mediaFilesDrawer.width * _mediaFilesDrawer.position
            Layout.fillHeight: true

            ColumnLayout    {
                spacing: 26
                anchors.fill: parent

                Item {
                    Layout.fillWidth: true
                    Layout.fillHeight: true

                    Image {
                        id: _mediaFileCover
                        anchors.fill: parent
                        fillMode: Image.PreserveAspectCrop
                        source: "qrc:/covers/httyd-soundtrack-cover.ipg"
                    }

                    //                  Video {
                    //                      id: video
                    //                      anchors.fill: parent
                    //                      source: "file:///home/sviatoslav/Downloads/sample.mp4"
                    //                      autoPlay: true
                    //                  }
                }

                Item {
                    id: _mediaFileTitleWrapper
                    clip: true

                    Layout.fillWidth: true
                    height:  _mediaFileTitle.implicitHeight

                    SequentialAnimation {
                        running: true
                        onStopped: start()

                        XAnimator {
                            easing.type: Easing.InOutQuad
                            target: _mediaFileTitle
                            from: 0
                            to:  _mediaFileTitleWrapper.width - _mediaFileTitle.implicitWidth
                            duration: _mediaFileTitleWrapper.width * 8
                        }

                        ParallelAnimation {
                            OpacityAnimator {
                                target: _rightMediaFileTitleGradient
                                from: 1
                                to: 0
                            }

                            PauseAnimation {
                                duration: 1500
                            }
                        }

                        OpacityAnimator {
                            target: _rightMediaFileTitleGradient
                            from: 0
                            to: 1
                        }

                        XAnimator {
                            easing.type: Easing.InOutQuad
                            target: _mediaFileTitle
                            from: _mediaFileTitleWrapper.width - _mediaFileTitle.implicitWidth
                            to: 0
                            duration: _mediaFileTitleWrapper.width * 8
                        }

                        ParallelAnimation {
                            OpacityAnimator {
                                target: _leftMediaFileTitleGradient
                                from: 1
                                to: 0
                            }

                            PauseAnimation {
                                duration: 1500
                            }
                        }

                        OpacityAnimator {
                            target: _leftMediaFileTitleGradient
                            from: 0
                            to: 1
                        }
                    }

                    Label {
                        id: _mediaFileTitle
                        text: MediaPlayerModel.currentMediaFileTitle === null ? "" : MediaPlayerModel.currentMediaFileTitle
                        font.pixelSize: Qt.application.font.pixelSize * 1.4
                    }

                    Rectangle {
                        id: _rightMediaFileTitleGradient

                        width: height
                        height: parent.height
                        anchors.right: parent.right
                        rotation: -90

                        gradient: Gradient {
                            GradientStop {
                                position: 0
                                color: "#00dfe4ea"
                            }
                            GradientStop {
                                position: 1
                                color: "#dfe4ea"
                            }
                        }
                    }

                    Rectangle {
                        id: _leftMediaFileTitleGradient

                        width: height
                        height: parent.height
                        anchors.left: parent.left
                        rotation: 90

                        gradient: Gradient {
                            GradientStop {
                                position: 0
                                color: "#00dfe4ea"
                            }
                            GradientStop {
                                position: 1
                                color: "#dfe4ea"
                            }
                        }
                    }
                }

                Item {
                    id: _mediaPlayerControlsPanel

                    Layout.alignment: Qt.AlignCenter

                    width: _mediaPlayerControlsPanelLayout.implicitWidth
                    height: _mediaPlayerControlsPanelLayout.implicitHeight

                    RowLayout {
                        id: _mediaPlayerControlsPanelLayout

                        NControls.RoundButton {
                            icon.source: "qrc:/stop.png"
                            icon.width: 32
                            icon.height: 32

                            onClicked: {
                                MediaController.changeStatus(MediaEnums.Stopped)
                            }
                        }

                        NControls.RoundButton {
                            icon.source: "qrc:/previous.png"
                            icon.width: 32
                            icon.height: 32

                            onClicked: {
                                MediaController.getPreviousMediaFile()
                            }

                        }

                        NControls.RoundButton {
                            id: _playButton
                            icon.source: "qrc:/play.png"
                            icon.width: 32
                            icon.height: 32

                            onClicked: {
                                MediaController.changeStatus(MediaEnums.SwitchPlay)
                            }
                        }

                        NControls.RoundButton {
                            icon.source: "qrc:/next.png"
                            icon.width: 32
                            icon.height: 32

                            onClicked: {
                                MediaController.getNextMediaFile()
                            }
                        }

                        NControls.RoundButton {
                            id: _repeatButton

                            icon.source: "qrc:/repeat"
                            icon.width: 32
                            icon.height: 32

                            onClicked: {
                                MediaController.changePlayerMode(MediaEnums.SwitchMode)
                            }
                        }
                    }
                }

                NControls.Slider {
                    id: _mediaPlayerSeekSlider

                    Layout.fillWidth: true

                    onPressedChanged: {
                        MediaController.seek(_mediaPlayerSeekSlider.value)
                    }
                }
            }
        }                        // end of playable area

        NControls.Drawer {
            id: _mediaFilesDrawer

            readonly property bool inPortrait: _mainWindow.width <= _mainWindow.height
            readonly property real calculated_mediaFilesDrawerWidth: _mainWindow.width < 700 ? _mainWindow.width : _mainWindow.width * 0.45

            width: calculated_mediaFilesDrawerWidth
            height: parent.height
            edge: Qt.RightEdge

            modal: inPortrait
            interactive: inPortrait
            position: inPortrait ? 0 : 1
            visible: !inPortrait

            background: Rectangle {
                color: "#dfe4ea"
            }

            Rectangle {
                id: _mediaFilesSources
                color: "#dfe4ea"

                anchors {
                    property real marginValue: parent.width * 0.03

                    fill: parent
                    margins: marginValue
                }

                ColumnLayout {
                    id: test
                    anchors.fill: parent

                    TabView {
                        id: _mediaFilesContainer

                        clip: true

                        Layout.fillWidth: true
                        Layout.fillHeight: true

                        Tab {
                            id: _librarySectionTab
                            title: "Library"

                            onVisibleChanged: {
                                if (_librarySectionTab.visible)
                                {
                                    MediaSectionController.changeSection(MediaEnums.Library)
                                }
                            }

                            Rectangle {
                                id: _librarySectionTabBackground
                                color: "#dfe4ea"

                                ListView {
                                    id: _mediaFilesListView
                                    clip: true
                                    anchors.fill: parent
                                    model: LibraryModel
                                    spacing: 10

                                    delegate: Rectangle {
                                        property int currentSelectedIndex: null

                                        id: _mediaFileDelegate

                                        width: _mediaFilesListView.width
                                        height: _mediaFileInfo.implicitHeight

                                        color: "#dfe4ea"

                                        RowLayout {
                                            anchors.fill: parent

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

                                                        //anchors.right: parent.right
                                                        Layout.alignment: Qt.AlignRight
                                                    }
                                                }

                                                MouseArea {
                                                    anchors.fill: _compositionInfoWrap

                                                    onClicked: {
                                                        _mediaFilesListView.model.currentSelectedIndex = model.index

                                                        MediaController.setNewSong()
                                                    }
                                                }
                                            }

                                            Item {
                                                id: _additionalCompositionRelatedControls

                                                width: _addToPlaylistButton.implicitWidth
                                                height: _addToPlaylistButton.implicitHeight

                                                visible: false

                                                NControls.RoundButton {
                                                    id: _addToPlaylistButton

                                                    icon.source: "qrc:/add.png"
                                                    icon.width: 32
                                                    icon.height: 32

                                                    MouseArea {
                                                        anchors.fill: parent

                                                        onClicked: {
                                                            _addToPlaylistPopup.open()
                                                            currentSelectedIndex = model.index

                                                        }
                                                    }
                                                }
                                            }

                                        }   // main row layout end

                                        MouseArea {
                                            anchors.fill: parent
                                            hoverEnabled: true

                                            propagateComposedEvents: true

                                            onHoveredChanged: {
                                                _additionalCompositionRelatedControls.visible = this.containsMouse
                                            }
                                        }


                                        NControls.Popup   {
                                            id: _addToPlaylistPopup

                                            modal: true

                                            width: 300
                                            height: 300

                                            ListView {
                                                id: _playlistsListViewModal

                                                clip: true
                                                anchors.fill: parent

                                                model: PlaylistsModel

                                                delegate: Text {
                                                    text: name

                                                    MouseArea {
                                                        anchors.fill:  parent

                                                        onClicked:  {
                                                            console.log("sdfsdfsdfsdfs" + currentSelectedIndex)
                                                            PlaylistsModel.addMediaToPlaylist(currentSelectedIndex, name)
                                                            _addToPlaylistPopup.close()
                                                        }
                                                    }
                                                }
                                            }
                                            onClosed: {
                                                console.log(PlaylistsModel)
                                            }
                                        }

                                    }

                                    NControls.ScrollBar.vertical: NControls.ScrollBar {
                                        parent: _mediaFilesContainer
                                        policy: NControls.ScrollBar.AlwaysOn

                                        anchors {
                                            top: parent.top
                                            right: parent.right
                                            bottom: parent.bottom
                                            margins: 1
                                        }

                                        background: Rectangle {
                                            color: "#6b7b89"
                                            radius: 50
                                        }
                                    }
                                } // Library end view
                            }
                        }

                        Tab {
                            id: _playlistsSectionTab
                            title: "Playlists"

                            onVisibleChanged: {
                                if (_playlistsSectionTab.visible)
                                {
                                    MediaSectionController.changeSection(MediaEnums.Playlists)
                                }
                            }

                            Rectangle {
                                id: _playlistsSectionTabBackground
                                color: "#dfe4ea"

                                StackView {
                                    id: _playlistsStackView
                                    anchors.fill: parent

                                    initialItem: Item {

                                        ListView {
                                            id: _playlistsListView

                                            clip: true
                                            anchors.fill: parent

                                            model: PlaylistsModel

                                            delegate: Text {
                                                text: name

                                                MouseArea {
                                                    anchors.fill:  parent

                                                    onClicked:  {
                                                        PlaylistsModel.setPlaylistMedia(model.index)

                                                        _playlistsStackView.push("qrc:/qml/playlistMediaView.qml")
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }       // end Stack playlists view
                                RowLayout {
                                    NControls.RoundButton {

                                        icon.source: "qrc:/back.png"
                                        icon.width: 32
                                        icon.height: 32

                                        onClicked: {
                                            _playlistsStackView.pop()
                                        }
                                    }
                                    NControls.RoundButton {

                                        icon.source: "qrc:/add.png"
                                        icon.width: 32
                                        icon.height: 32

                                        onClicked: {
                                            _popup.open()
                                            //PlaylistsModel.add("New")
                                        }
                                    }

                                    NControls.Popup {
                                            id: _popup
                                            x: 100
                                            y: 100
                                            width: 200
                                            height: 300
                                            modal: true
                                            focus: true
                                            //closePolicy: NControls.Popup.CloseOnEscape | NControls.Popup.CloseOnPressOutsideParent

                                            TextField {
                                                id: _playlistNameTextField
                                                placeholderText: qsTr("Playlist name")
                                            }

                                            NControls.RoundButton {
                                                width: 32
                                                height: 32

                                                onClicked: {
                                                    PlaylistsModel.add(_playlistNameTextField.text)
                                                }

                                                Connections {
                                                    target: PlaylistsModel

                                                    function onNameAlreadyTaken() {
                                                        _playlistNameTextField.text = "Name is already taken!"
                                                    }

                                                   function onMediafileAddedSuccesfully() {
                                                        _popup.close()
                                                    }
                                                }
                                            }
                                        }
                                }
                            }
                        }
                    }
                }
            }
        }

        Connections {
            target: MediaController

            function onPaused() {
                _playButton.icon.source = "qrc:/play.png"
            }

            function onPlaying() {
                _playButton.icon.source = "qrc:/pause.png"
            }

            function onStopped() {
                _playButton.icon.source = "qrc:/play.png"
            }

            function onRepeatMode() {
                _repeatButton.highlighted = true
            }

            function onSequenceMode() {
                _repeatButton.highlighted = false
            }

            function onDurationChanged() {
                _mediaPlayerSeekSlider.to = MediaPlayerModel.duration
            }

            function onPositionChanged() {
                _mediaPlayerSeekSlider.value = MediaPlayerModel.position
            }
        }
    }
}
