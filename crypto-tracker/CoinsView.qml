import QtQuick 2.15

CoinsViewForm {
    model: cryptoModel

    Timer {
        id: updateInProgressTimer
        interval: 500
        repeat: false
        onRunningChanged: {
            if (running) {
                colorOverlay.visible = true
            } else {
                colorOverlay.visible = false
            }
        }
    }

    Connections {
        target: cryptoController
        function onUpdateStarted() {
            updateInProgressTimer.start()
        }
    }
}
