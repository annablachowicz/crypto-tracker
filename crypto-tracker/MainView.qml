import QtQuick 2.15
import "Components/CryptoLabel"
import "Components/Sidebar"
import "Components"

Item {
    Sidebar {
        id: sidebar
        anchors.left: parent.left
        anchors.top: parent.top
        height: parent.height
    }

    CoinsView {
        id: coinsView
        anchors.left: sidebar.right
        anchors.top: parent.top
        anchors.right: parent.right
        anchors.bottom: parent.bottom
    }
}
