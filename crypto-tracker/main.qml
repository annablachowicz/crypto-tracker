import QtQuick 2.15
import QtQuick.Window 2.15
import CustomColors 1.0
import "Components/CryptoLabel"
import "Components/Sidebar"

Window {
    width: 880
    height: 960
    visible: true
    title: qsTr("Hello World")
    color: Colors.almostWhite

    Sidebar {
        id: sidebar
        anchors.left: parent.left
        anchors.top: parent.top
        onSortCoins: {
            coinsView.model.sort(index)
        }
    }

    CoinsView {
        id: coinsView
        anchors.left: sidebar.right
        anchors.top: parent.top
        anchors.right: parent.right
        anchors.bottom: parent.bottom
    }

}
