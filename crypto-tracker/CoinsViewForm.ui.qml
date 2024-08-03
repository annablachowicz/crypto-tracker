import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.3
import CustomColors 1.0
import "Components/CryptoLabel"

Rectangle {
    id: root

    property alias model: listView.model
    property alias listView: listView
    property alias scrollBar: scrollBar

    color: Colors.darkBackground

    ListView {
        id: listView

        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        width: 350

        boundsBehavior: Flickable.StopAtBounds
        ScrollBar.vertical: ScrollBar {
            id: scrollBar
            policy: ScrollBar.AlwaysOff
            active: ScrollBar.AlwaysOn
        }

        delegate: CryptoLabel {
            cryptoLogo: model.image
            cryptoName: model.name
            ticker: model.ticker
            price: model.price
            change1h: model.priceChange1h
            change24h: model.priceChange24h
            rank: model.rank
            lastUpdate: model.lastUpdate
        }
    }
}
