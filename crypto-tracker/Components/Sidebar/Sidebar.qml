import QtQuick 2.15

SidebarForm {
    sortControl.onSortCoins: coinsView.model.sort(index)

    Connections {
        target: cryptoController
        function onErrorMessageReceived(errorCode, errorMessage) {
            networkErrorLabel.text = errorMessage
            networkErrorLabel.visible = errorCode !== 0
        }
    }

}
