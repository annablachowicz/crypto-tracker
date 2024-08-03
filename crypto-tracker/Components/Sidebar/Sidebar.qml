import QtQuick 2.15

SidebarForm {
    sortControl.onSortCoins: coinsView.model.sort(index, order)
    staleDataIndicator.visible: cryptoController.isStaleData

    randomChangesButton.onCheckedChanged: {
        if (randomChangesButton.checked) {
            var firstIndex = coinsView.getFirstVisibleIndex()
            var lastIndex = coinsView.getLastVisibleIndex()
            if (firstIndex !== -1 && lastIndex !== -1) {
                cryptoController.enableRandomChange(firstIndex, lastIndex)
            }
        } else {
            cryptoController.disableRandomChange()
        }
    }

    Connections {
        target: cryptoController
        function onErrorMessageReceived(errorCode, errorMessage) {
            networkErrorLabel.text = errorMessage
            networkErrorLabel.visible = errorCode !== 0
        }
        function onUpdateStarted() {
            loadingImage.visible = true
            loadingAnimation.start()
        }
        function onUpdateFinished() {
            loadingImage.visible = false
            loadingAnimation.stop()
        }
    }

    NumberAnimation on loadingImage.rotation {
        id: loadingAnimation
        from: 0
        to: -360
    }

}
