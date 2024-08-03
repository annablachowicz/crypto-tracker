import QtQuick 2.15

CoinsViewForm {
    model: cryptoModel

    Connections {
        target: cryptoModel
        function onItemDataUpdateStarted(index) {
            if (listView.itemAtIndex(index) !== null)
                listView.itemAtIndex(index).animation.start();
        }
    }

    function getFirstVisibleIndex() {
        var currentY = scrollBar.position / 1.0 * listView.contentHeight
        return listView.indexAt(200, currentY)
    }
    function getLastVisibleIndex() {
        var currentY = (scrollBar.position + scrollBar.size) / 1.0 * listView.contentHeight - 1
        return listView.indexAt(200, currentY)
    }
}
