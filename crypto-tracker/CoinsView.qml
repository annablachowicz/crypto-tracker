import QtQuick 2.15

CoinsViewForm {
    model: cryptoModel

    Connections {
        target: cryptoModel
        function onItemDataUpdateStarted(index) {
            repeater.itemAt(index).animation.start();
        }
    }
}
