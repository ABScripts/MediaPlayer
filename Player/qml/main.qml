import QtQuick 2.15
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.15 as NControls
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import QtQuick.Dialogs 1.2
import QtMultimedia 5.15

import MediaPlayerEnums 1.0                 // Custom imports

Rectangle {
    id: _mainWindow
    width: 1280
    height: 720
    color: "#dfe4ea"

    RowLayout {
        id: _playerRowLayout
        anchors.fill: parent

        Rectangle {
            id: _playArea
            color: "#dfe4ea"

            Layout.preferredWidth: _mainWindow.width - _mediaSourcesDrawer.width * _mediaSourcesDrawer.visible
            Layout.fillHeight: true

            ColumnLayout    {
                id: _playAreaColumnLayout

                spacing: 26
                anchors.fill: parent

                Item {
                    id: _mediaVisualisationArea

                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    Layout.rightMargin: 15
                    Layout.leftMargin: 15
                    Layout.topMargin: 15

                    Image {
                        id: _songCover

                        anchors.fill: _mediaVisualisationArea
                        fillMode: Image.PreserveAspectCrop
                        source: "qrc:/covers/httyd-soundtrack-cover.ipg"
                    }
                    VideoOutput {
                        id: _videoOutput

                        anchors.fill: _mediaVisualisationArea

                        source: MediaPlayerModel
                        flushMode: VideoOutput.LastFrame
                        visible: false
                    }
                }

                Item {
                    id: _mediaTitleArea
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
                            to:  _mediaTitleArea.width - _mediaFileTitle.implicitWidth
                            duration: _mediaTitleArea.width * 8
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
                            from: _mediaTitleArea.width - _mediaFileTitle.implicitWidth
                            to: 0
                            duration: _mediaTitleArea.width * 8
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
                        text: MediaPlayerModel.mediaFileTitle === null ? "" : MediaPlayerModel.mediaFileTitle
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
                    id: _playerControlsArea

                    Layout.alignment: Qt.AlignCenter
                    width: _playerControlsAreaLayout.implicitWidth
                    height: _playerControlsAreaLayout.implicitHeight

                    RowLayout {
                        id: _playerControlsAreaLayout

                        NControls.RoundButton {
                            id: _stopMediaButton

                            icon.source: "qrc:/stop.png"
                            icon.width: 32
                            icon.height: 32

                            onClicked: {
                                MediaController.changeStatus(MediaEnums.Stopped)
                            }
                        }

                        NControls.RoundButton {
                            id: previousMediaButton

                            icon.source: "qrc:/previous.png"
                            icon.width: 32
                            icon.height: 32

                            onClicked: {
                                MediaController.getPreviousMedia()
                            }

                        }

                        NControls.RoundButton {
                            id: _playMediaButton

                            icon.source: "qrc:/play.png"
                            icon.width: 32
                            icon.height: 32

                            onClicked: {
                                MediaController.changeStatus(MediaEnums.SwitchPlay)
                            }
                        }

                        NControls.RoundButton {
                            id: _nextMediaButton

                            icon.source: "qrc:/next.png"
                            icon.width: 32
                            icon.height: 32

                            onClicked: {
                                MediaController.getNextMedia()
                            }
                        }

                        NControls.RoundButton {
                            id: _repeatMediaButton

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
                    id: _playerSeekSlider

                    Layout.fillWidth: true

                    onPressedChanged: {
                        MediaController.seek(_playerSeekSlider.value)
                    }
                }
            }
        }                        // end of playable area

        NControls.Drawer {
            id: _mediaSourcesDrawer

            readonly property bool isInPortrait: _mainWindow.width <= _mainWindow.height
            readonly property real calculatedWidth: _mainWindow.width < 700 ? _mainWindow.width : _mainWindow.width * 0.45

            width: calculatedWidth
            height: _mainWindow.height

            edge: Qt.RightEdge

            modal: isInPortrait
            interactive: isInPortrait
            position: isInPortrait ? 0 : 1
            visible: !isInPortrait

            background: Rectangle {
                color: "#dfe4ea"
            }

            Item {
                id: _mediaSourcesArea

                anchors {
                    property real marginValue: parent.width * 0.03

                    fill: parent
                    margins: marginValue
                }

                    TabView {
                        id: _mediaSourceTabView

                         clip: true

                         anchors.fill: parent

                         Rectangle {
                             id: _playlistSectionBackground

                             anchors.fill: parent
                             color: "#dfe4ea"
                             z: -99
                         }

                        Tab {
                            id: _loadFromFileviewer
                            title: "Load"

                            anchors.fill: parent

                            Item {
                                anchors.fill: parent

                                DropArea {
                                       id: dropArea
                                       anchors.fill: parent

                                       Rectangle {
                                        anchors.fill: parent
                                        anchors.margins: Math.min(parent.height, parent.width) * 0.1
                                        color: "#dfe4ea"
                                        border.color: "black"
                                        radius: 10

                                        ColumnLayout {

                                            anchors.fill: parent
                                            Text {
                                                Layout.alignment: Qt.AlignCenter

                                                text: qsTr("Drag and drop your files")

                                                 font.pointSize: 18
                                            }

                                            Text {
                                                Layout.alignment: Qt.AlignCenter

                                                text: qsTr("OR")

                                                 font.pointSize: 22
                                            }

                                            Button {
                                                Layout.alignment: Qt.AlignCenter

                                                text: "Load from machine"

                                                onClicked: {
                                                    _fileDialog.open()
                                                }
                                            }
                                        }
                                       }

                                       FileDialog {
                                           id: _fileDialog
                                           title: "Please choose a file"
                                           folder: shortcuts.home

                                           onAccepted: {
                                               console.log("You chose: " + _fileDialog.fileUrls)
                                               MediaLoaderController.onFileLoaded(_fileDialog.fileUrl)
                                               Qt.quit()
                                           }
                                           onRejected: {
                                               console.log("Canceled")
                                               Qt.quit()
                                           }
                                       }

                                       keys: ["text/plain"]

                                       onDropped: if (drop.hasText) {
                                           if (drop.proposedAction == Qt.MoveAction || drop.proposedAction == Qt.CopyAction) {
                                               MediaLoaderController.onFileLoaded(drop.text)
                                               drop.acceptProposedAction()
                                           }
                                       }
                                   }
                            }
                        }

                        Tab {
                            id: _librarySectionTab
                            title: "Library"
                            anchors.fill: parent

                            active: true

                            Item {
                                id: _tabComponents

                                ListView {
                                    id: _mediaFilesLibraryListView

                                    model: LibraryModel
                                    anchors.fill: parent

                                    clip: true
                                    spacing: 5

                                    visible: false

                                    delegate: Item {
                                        id: _mediaLibraryFileDelegate

                                        width: _mediaFilesLibraryListView.width - _libraryScrollBar.width
                                        height: _mediaFileInfo.implicitHeight

                                        RowLayout {
                                            id: _mediaFileRowLayout

                                            anchors.fill: parent

                                            Item {
                                                id: _compositionInfoArea

                                                Layout.alignment: Qt.AlignLeft
                                                Layout.preferredWidth: _mediaFileRowLayout.width - _compositionControlsArea.width
                                                Layout.preferredHeight: _mediaLibraryFileDelegate.height

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
                                                    anchors.fill: _compositionInfoArea

                                                    onClicked: {
                                                        _mediaFilesLibraryListView.model.currentSelectedIndex = model.index

                                                        MediaSectionController.changeSection(MediaEnums.Library)

                                                        MediaController.setAutoMedia()
                                                    }
                                                }
                                            }

                                            Item {
                                                id: _compositionControlsArea

                                                Layout.alignment: Qt.AlignRight

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
                                                            PlaylistsModel.selectedLibraryIndex = model.index
                                                            _addToPlaylistPopup.open()

                                                          console.log(PlaylistsModel.selectedLibraryIndex)
                                                            console.log(model.index)
                                                        }
                                                    }
                                                }
                                            }

                                        }
                                        MouseArea {
                                            anchors.fill: parent
                                            hoverEnabled: true

                                            propagateComposedEvents: true

                                            onHoveredChanged: {
                                                _compositionControlsArea.visible = this.containsMouse
                                            }
                                        }
                                    }

                                    NControls.ScrollBar.vertical: NControls.ScrollBar {
                                        id: _libraryScrollBar

                                        parent: _librarySectionTab
                                        policy: NControls.ScrollBar.AlwaysOn

                                        visible: false

                                        anchors {
                                            top: parent.top
                                            right: parent.right
                                            bottom: parent.bottom
                                        }

                                        background: Rectangle {
                                            color: "#6b7b89"
                                            radius: 50
                                        }
                                    }
                                } // Library end view

                                Connections {
                                    target: LibraryController

                                    function onNoMediaLoaded() {
                                        _infoLoadingMediaText.text = "No media found :("
                                        _infoLoadingMediaIcon.source = "qrc:/status-icons/no-data.png"
                                    }

                                    function onMediaLoadedSuccesfully() {
                                        _infoLoadingMediaPlaceholder.visible = false
                                        _mediaFilesLibraryListView.visible = true
                                        _libraryScrollBar.visible = true
                                    }
                                }

                                Item {
                                    id: _infoLoadingMediaPlaceholder

                                    anchors.fill: parent

                                    ColumnLayout {
                                        anchors.centerIn: parent

                                        Text {
                                            id: _infoLoadingMediaText

                                            Layout.alignment: Qt.AlignHCenter

                                            text: "Loading media, please wait..."
                                        }

                                        AnimatedImage {
                                            id: _infoLoadingMediaIcon

                                            Layout.alignment: Qt.AlignHCenter

                                            source: "qrc:/status-icons/loading.gif"
                                        }
                                    }
                                }
                            }
                        } // end of Library tab

                        Tab {
                            id: _playlistsSectionTab
                            title: "Playlists"
                            anchors.fill: parent
                            active: true

                            Item {
                                anchors.fill: parent
                                anchors.topMargin: 25

                            ColumnLayout {
                                anchors.fill: parent

                                ColumnLayout {
                                    id: _infoLoadingPlaylistsPlaceholder

                                    Layout.alignment: Qt.AlignHCenter

                                    Text {
                                        id: _infoLoadingPlaylistsText

                                        Layout.alignment: Qt.AlignHCenter

                                        text: "Loading playliststs, please wait..."
                                    }

                                    AnimatedImage {
                                        id: _infoLoadingPlaylistsIcon

                                        Layout.alignment: Qt.AlignHCenter

                                        source: "qrc:/status-icons/loading.gif"
                                    }
                                }

                               RowLayout {
                                   NControls.RoundButton {
                                        id: _backToPlaylistsButton

                                        icon.source: "qrc:/back.png"
                                        icon.width: 32
                                        icon.height: 32

                                        onClicked: {
                                            _playlistsStackView.pop()
                                        }
                                    }
                                    Text {
                                        id: _playlistLabel

                                        text: qsTr("Playlists")
                                        font.pixelSize: Qt.application.font.pixelSize * 1.4
                                    }
                                }

                                StackView {
                                    id: _playlistsStackView
                                    Layout.fillWidth: true
                                    Layout.preferredHeight: parent.height -
                                                            _playlistControlsArea.height -
                                                            _infoLoadingPlaylistsPlaceholder.height * _infoLoadingPlaylistsPlaceholder.visible-
                                                            _playlistLabel.height - 25

                                    initialItem: Item {

                                        ListView {
                                            id: _playlistsListView

                                            clip: true
                                            anchors.fill: parent

                                            model: PlaylistsModel

                                            delegate: Text {
                                                text: name
                                                font.pixelSize: Qt.application.font.pixelSize * 1.4

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

                                Item {
                                    id: _playlistControlsArea

                                    width:  _addPlaylistButton.width
                                    height:  _addPlaylistButton.height
                                    Layout.alignment: Qt.AlignRight | Qt.AlignBottom

                                    NControls.RoundButton {
                                        id: _addPlaylistButton

                                        icon.source: "qrc:/add.png"
                                        icon.width: 32
                                        icon.height: 32

                                        onClicked: {
                                            _addPlaylistPopup.open()
                                        }
                                    }
                                }
                            }

                            Connections {
                                target: PlaylistController

                                function onPlaylistsLoadedSuccessfully() {
                                    _infoLoadingPlaylistsPlaceholder.visible = false
                                }

                                function onPlaylistEmpty() {
                                    _infoLoadingPlaylistsText.text = "No playlists yet :("
                                    _infoLoadingPlaylistsIcon.source = "qrc:/status-icons/no-data.png"
                                }

                                function onPlaylistNameConfirmed() {
                                    _infoLoadingPlaylistsPlaceholder.visible = false
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
                _playMediaButton.icon.source = "qrc:/play.png"
            }

            function onPlaying() {
                _playMediaButton.icon.source = "qrc:/pause.png"
            }

            function onStopped() {
                _playMediaButton.icon.source = "qrc:/play.png"
            }

            function onRepeatModeSet() {
                _repeatMediaButton.highlighted = true
            }

            function onSequenceModeSet() {
                _repeatMediaButton.highlighted = false
            }

            function onDurationChanged() {
                _playerSeekSlider.to = MediaPlayerModel.duration
            }

            function onPositionChanged() {
                _playerSeekSlider.value = MediaPlayerModel.position
            }

            function onVideoModeSet() {
                _videoOutput.visible = true
                _songCover.visible = false

            }

            function onAudioModeSet() {
                _videoOutput.visible = false
                _songCover.visible = true
            }
        }
    }

    NControls.Popup   {
        id: _addToPlaylistPopup

        anchors.centerIn: parent

        modal: true

        width: parent.width * 0.6
        height: parent.height * 0.4

        background: Rectangle {
            color: "#dfe4ea"
            radius: 10
        }

        onVisibleChanged: {
            var noPlaylists = (PlaylistsModel.size() === 0);

            _playlisFillForm.visible = !noPlaylists
            _noPlaylistsText.visible = noPlaylists
        }

        Text {
            id: _noPlaylistsText

            visible: false

            anchors.centerIn: parent

            text: "No playlists yet to add in :("
            font.pixelSize: Qt.application.font.pixelSize * 1.4
        }

        ColumnLayout {
            id: _playlisFillForm
            anchors.fill: parent

            Text {
                Layout.alignment: Qt.AlignHCenter

                text: "Choose a playlist to add:"
                font.pixelSize: Qt.application.font.pixelSize * 1.4
            }

            ListView {
                id: _playlistsListViewModal

                clip: true
                Layout.fillHeight: true
                Layout.fillWidth: true

                model: PlaylistsModel

                delegate: Item {
                    width: _playlistsListViewModal.width
                    height: _playlistName.height

                    Text {
                        id: _playlistName

                        anchors.centerIn: parent

                        text: name
                        font.pixelSize: Qt.application.font.pixelSize * 1.4

                        MouseArea {
                            anchors.fill:  parent

                            onClicked:  {
                                console.log(PlaylistsModel.selectedLibraryIndex)
                                console.log("TRTRTRTRTRTR")
                                PlaylistsModel.addMediaToPlaylist(name)
                                _addToPlaylistPopup.close()
                            }
                        }
                    }
                }
            }
        }

    }

    NControls.Popup {
        id: _addPlaylistPopup

        anchors.centerIn: parent

        modal: true
        focus: true

        background: Rectangle {
            color: "#dfe4ea"
            radius: 10
        }

        ColumnLayout {
            anchors.centerIn: parent
            width: childrenRect.width
            height: childrenRect.height

            Text {
                Layout.alignment: Qt.AlignHCenter

                text: "Adding playlist"
                font.pixelSize: Qt.application.font.pixelSize * 1.4
            }

            TextField {
                id: _playlistNameTextField
                Layout.alignment: Qt.AlignHCenter
                placeholderText: qsTr("Playlist name")
            }

            Text {
                id: _addingPlaylistInfo

                text: ""
            }

            NControls.RoundButton {
                id: _createPlaylistButton
                Layout.alignment: Qt.AlignHCenter
                width: 32
                height: 32

                text: "Create"

                onClicked: {
                    PlaylistController.addPlaylist(_playlistNameTextField.text)
                }

                Connections {
                    target: PlaylistController

                    function onPlaylistNameEmpty() {
                        _addingPlaylistInfo.text = "Invalid name!"
                    }

                    function onPlaylistNameTaken() {
                        _addingPlaylistInfo.text = "Name is already taken!"
                    }

                    function onPlaylistNameConfirmed() {
                         _addPlaylistPopup.close()
                    }
                }
            }
        }
    }
}
